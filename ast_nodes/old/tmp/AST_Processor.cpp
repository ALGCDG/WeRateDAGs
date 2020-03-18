#include "AST_Processor.hpp"

//remember:
//linked list of type parts, head and tail
//typedef std::tuple<Context::typePart*, Context::typePart*> decTypeInfo; 

//getting information out of declarator for use in records
ContextData::baseSpecPart* ASTProcVis::descendDecSpecs(declaration_specifiers* _decl_spec){
    ContextData::baseSpecPart* otherSpecs = NULL;
    if(_decl_spec->specifier!=NULL){ otherSpecs = descendDecSpecs(_decl_spec->specifier); }
    if(_decl_spec->storage_class_specifier!=NULL){ return new ContextData::typedefSpecPart(otherSpecs); }
    else if(_decl_spec->type_spec != NULL){ return TableInstance->TypeIsUserOrCanon(_decl_spec->type_spec->type, otherSpecs); }
}

//get decType info from each of the items in the list
std::vector<decTypeInfo>& ASTProcVis::descendInitDecList(init_declarator_list* _list){
    std::vector<decTypeInfo> listDecInfo;
    init_declarator_list* traversePtr = _list;
    do{
        listDecInfo.push_back(descendInitDec(traversePtr->init_dec));
        traversePtr = traversePtr->init_dec_list;
    }while(traversePtr != NULL);
    return listDecInfo;
}

//get the info from the declaration
decTypeInfo ASTProcVis::descendInitDec(init_declarator* _init_dec){
    return descendDeclarator(_init_dec->dec);
}


decTypeInfo ASTProcVis::descendDeclarator(pointer* _ptr)
{
    if(_ptr->p == NULL){
        //create pointer part, as both the head and tail of the linked list
        ContextData::pointerPart* bottomPointer = new ContextData::pointerPart(NULL);
        return decTypeInfo(bottomPointer, bottomPointer);
    }
    else{
        decTypeInfo below = descendDeclarator(_ptr->p);
        //construct new pointer part with the previous head as its child
        ContextData::pointerPart* thisPointer = new ContextData::pointerPart(below.first);
        below.first = thisPointer;
        return below;
    }
}
decTypeInfo ASTProcVis::descendDeclarator(declarator* _decl)
{
    //declarator has member data:
        // pointer (optional)
        // direct declarator
    decTypeInfo dir_dec_info = descendDeclarator(_decl->dir_dec);

    if(_decl->p!=NULL){
        decTypeInfo pointer_info = descendDeclarator(_decl->p); 
        dir_dec_info.second->AddChild(pointer_info.first);
        //dir dec returns type pointer to something
        dir_dec_info.second = pointer_info.second;   
        //make tail of pointer chain tail of total list
    }
    
    return dir_dec_info;

    
}
decTypeInfo ASTProcVis::descendDeclarator(direct_declarator* _this_dir_dec)
{
    //TODO empty parameter list added to grammar
    /** Member data:
     * idenfifier node
     * declarator
     * direct declarator [ unspecified array length]
     * direct declarator [ constant expression ]
     * direct declarator ( parameter list )
     * direct declarator ( empty parameter list )
     */
    if(_this_dir_dec->ID != NULL) { return descendDeclarator(_this_dir_dec->ID); }
    else if(_this_dir_dec->dec != NULL) { return descendDeclarator(_this_dir_dec->dec); }
    else if(_this_dir_dec->dir_dec != NULL){
        decTypeInfo below = descendDeclarator(_this_dir_dec->dir_dec);
        if(_this_dir_dec->const_expr != NULL){
            unsigned int size = ASTProcVis::EvalConstantExpression(_this_dir_dec->const_expr);
            ContextData::arrayPart* this_array = new ContextData::arrayPart(size, NULL);
            below.second->AddChild(this_array); //add array to linked list
            below.second = this_array; //make bottom of list this array
            return below;
        }
        else if(_this_dir_dec->para_list!=NULL){
            ContextData::argsPart* args = descendDeclarator(_this_dir_dec->para_list);
            ContextData::funcPart* this_func = new ContextData::funcPart(args, NULL);
            below.second->AddChild(this_func);
            below.second = this_func;
            return below;
        }
    }
}

decTypeInfo ASTProcVis::descendDeclarator(IdentifierNode* _id)
{
    ContextData::IDPart* head = new ContextData::IDPart(_id, NULL);
    return decTypeInfo(head,head);
}

ContextData::argsPart* ASTProcVis::descendDeclarator(parameter_list* _par_list)
{   
    //TODO empty params?
    ContextData::argsPart* args = new ContextData::argsPart();
    parameter_list* list_traverser = _par_list;
    do{
        ContextData::argPart* argInfo = descendDeclarator(list_traverser->para_dec);
        args->argTypes.push_back(argInfo);//add head to params
        list_traverser = list_traverser->para_list;
    }while(list_traverser!=NULL);
    //reverse, params accessed from right to left
    std::reverse(args->argTypes.begin(),args->argTypes.end());
    return args;
}

ContextData::argPart* ASTProcVis::descendDeclarator(parameter_declaration* _par_dec)
{
    //param decl contains:
    // dec specs
    // dec specs, abstract decl
    // dec specs, declarator
    ContextData::baseSpecPart* decspecs = descendDecSpecs(_par_dec->dec_spec);
    decTypeInfo argInfo = decTypeInfo(NULL,NULL); //init as empty
    if(_par_dec->dec!=NULL){
        argInfo = descendDeclarator(_par_dec->dec);
        //TODO remember abstracc params
        argInfo.second->AddChild(decspecs);
    }
    else{
        argInfo.first = decspecs;
    }
    return new ContextData::argPart(argInfo.first);
}
decTypeInfo ASTProcVis::descendDeclarator(base_declarator * _decl){
    throw("base declarator encountered instead of specic abstract or direct:(");
}
decTypeInfo ASTProcVis::descendDeclarator(abstract_declarator* _decl ){
    throw("abstract processor not yet implemented");
}
decTypeInfo ASTProcVis::descendDeclarator(direct_abstract_declarator* _dir_abs_dec){
    throw("direct abstract proessor not yet implemented");

}

//void visit(Node*); //If nothing defined for this type of node
//might require special handling 
    void ASTProcVis::visit(ArraySubscript* _subcr){}
    void ASTProcVis::visit(FuncCall* _funccall){}
    void ASTProcVis::visit(MemberAccess* _memberaccess){}
    void ASTProcVis::visit(DerefMemberAccess* _derefmemberacc){}
    void ASTProcVis::visit(ArgExprList* _argexprlist){}
    void ASTProcVis::visit(SizeofExpr* _sizeofexpr){}
    void ASTProcVis::visit(SizeofType* _sizeoftype){}
    void ASTProcVis::visit(UnaryAddressOperator* _addrOp){}
    void ASTProcVis::visit(UnaryDerefOperator* derefOp){}
    void ASTProcVis::visit(PostInc* _postinc){}
    void ASTProcVis::visit(PostDec* _postdec){}
    void ASTProcVis::visit(CastExpr* _castexpr){}
    void ASTProcVis::visit(AssignmentExpression* _assignexpr){}

    //might not need to handle with this visitor
    void ASTProcVis::visit(Constant* _constant){}
    void ASTProcVis::visit(UnaryPlusOperator* _unaryplus){}
    void ASTProcVis::visit(UnaryNegOperator* _unaryneg){}
    void ASTProcVis::visit(UnaryBitwiseNotOperator* _unaryBitNot){}
    void ASTProcVis::visit(UnaryLogicalNotOperator* _unaryLogNot){}
    void ASTProcVis::visit(PreInc* _preinc){}
    void ASTProcVis::visit(PreDec* _predec){}
    void ASTProcVis::visit(Multiply* _mul){}
    void ASTProcVis::visit(Divide* _div){}
    void ASTProcVis::visit(Modulo* _mod){}
    void ASTProcVis::visit(Add* _add){}
    void ASTProcVis::visit(Sub* _sub){}
    void ASTProcVis::visit(ShiftLeft* _shl){}
    void ASTProcVis::visit(ShiftRight* _shr){}
    void ASTProcVis::visit(LessThan* _lt){}
    void ASTProcVis::visit(GreaterThan* _gt){}
    void ASTProcVis::visit(LessThanOrEqual* _lte){}
    void ASTProcVis::visit(GreaterThanOrEqual* _gte){}
    void ASTProcVis::visit(EqualTo* _eq){}
    void ASTProcVis::visit(NotEqualTo* _ne){}
    void ASTProcVis::visit(LogicalAND* _logand){}
    void ASTProcVis::visit(LogicalOR* _logor){}
    void ASTProcVis::visit(BitwiseAND* _bitand){}
    void ASTProcVis::visit(BitwiseOR* _bitor){}
    void ASTProcVis::visit(BitwiseXOR* _bitxor){}
    void ASTProcVis::visit(TernaryOpExpression* _tern){}
    void ASTProcVis::visit(MulAssignment* _mulass){}
    void ASTProcVis::visit(DivAssignment* _divass){}
    void ASTProcVis::visit(ModAssignment* _modass){}
    void ASTProcVis::visit(AddAssignment* _addass){}
    void ASTProcVis::visit(SubAssignment* _subass){}
    void ASTProcVis::visit(ShiftLeftAssignment* _shlass){}
    void ASTProcVis::visit(ShiftRightAssignment* _shrass){}
    void ASTProcVis::visit(BitwiseANDAssignment* _bANDass){}
    void ASTProcVis::visit(BitwiseXORAssignment* _xorass){}
    void ASTProcVis::visit(BitwiseORAssignment* _bORass){}
    void ASTProcVis::visit(ConstantExpression* _constexpr){}
    void ASTProcVis::visit(CommaSepExpression* _comsep){}

    //Declarations
    void ASTProcVis::visit(declaration* _dectn){
        //TODO
        if(_dectn->list!=NULL){
            ContextData::baseSpecPart* specs = descendDecSpecs(_dectn->specifier);
            std::vector<decTypeInfo> initList_info = descendInitDecList(_dectn->list);
            for(auto info : initList_info){
                //deep copy the dec specs, so that seperate decls in the list aren't connected
                ContextData::baseSpecPart* specCpy = ContextData::baseSpecPart::CopySpecList(specs);
                info.second->AddChild(specCpy);
                ContextData::IDPart* id = static_cast<ContextData::IDPart*>(info.first);
                std::string name = std::string(*(id->ast_node->Name));
                TableInstance->ProcessIDDecl(name, info.first->GetChild());
            }
            delete specs;
        }
        //do nothing otherwise
    }
    void ASTProcVis::visit(declaration_specifiers* _decspec){
        //TODO possibly will never visit (access through descender)
        throw("should not be visiting dec specs with processor");
    }
    void ASTProcVis::visit(init_declarator_list* _indeclis){
        throw("should not be visiting init dec list");
    }
    void ASTProcVis::visit(init_declarator* _indec){
        throw("should not be visiting int dec");
    }
    void ASTProcVis::visit(type_specifier* _typespec){
        throw("");
    }
    void ASTProcVis::visit(specifier_list* _speclist){}
    void ASTProcVis::visit(pointer* _pt){}
    void ASTProcVis::visit(base_declarator* _basedec){}
    void ASTProcVis::visit(abstract_declarator* _absdec){}
    void ASTProcVis::visit(declarator* _declr){}

    //Statements
    void ASTProcVis::visit(EmptyStatement* _emptmnt){}
    void ASTProcVis::visit(Continue* _cont){}
    void ASTProcVis::visit(Break* _brk){}
    void ASTProcVis::visit(Return* _ret){}
    void ASTProcVis::visit(ExpressionStatement* _exprstmnt){}
    void ASTProcVis::visit(StatementList* _stmntlist){}
    void ASTProcVis::visit(CompoundStatement* _compstat){}

    //scope changing
    void ASTProcVis::visit(While* _whi){
        _whi->ControlExpression->accept(this);
        TableInstance->NewScope();
        _whi->Body->accept(this);
        TableInstance->PopScope();
    }
    void ASTProcVis::visit(DoWhile* _dowhi){
        TableInstance->NewScope();
        _dowhi->Body->accept(this);
        TableInstance->PopScope();
        //control expression is in scope above the body
        _dowhi->ControlExpression->accept(this);
    }
    void ASTProcVis::visit(For* _for){

    }
    void ASTProcVis::visit(If* _if){}
    void ASTProcVis::visit(IfElse* _ifelse){}
    void ASTProcVis::visit(Switch* _swi){}
    void ASTProcVis::visit(CaseOrDefault* _caseordef){}

    //External definitions
    void ASTProcVis::visit(TranslationUnit* _trans){
        for (auto el : _trans->decls){
            el->accept(this);
        }
    }
    void ASTProcVis::visit(FunctionDefinitionRec* _funcdef){
        // //TODO consider declaratinos preceding definitions
        // ContextData::baseSpecPart* spec_info;
        // if(_funcdef->specs != NULL){
        //     spec_info = descendDecSpecs(_funcdef->specs);
        // }
        // else{
        //     //presume integer
        //     spec_info = new ContextData::canonSpecPart(new std::string("int"),NULL);
        // }
        // decTypeInfo decl_info = descendDeclarator(_funcdef->decl);
        // decl_info.second->AddChild(spec_info);
        // decl_info.second = spec_info;
        // //head of list is deffo identifier, so can do this
        // ContextData::IDPart* id = static_cast<ContextData::IDPart*>(decl_info.first);
        // ContextData::FunctionDef* funcdefrecord = new ContextData::FunctionDef(id->ast_node->Name, decl_info.first);
        
        // // TableInstance->AddObjectRecord(funcdefrecord);
        // id->ast_node->ContextRecord = funcdefrecord; //link id node in ast to def in table
        // auto scopeRecord = new ContextData::FunctionScopeRecord();
        // // //link together dec and def
        // // scopeRecord->SetDeclarationPtr(funcdefrecord);
        // // funcdefrecord->SetDefRecordPtr(scopeRecord);
        // // TableInstance->SetActiveScope(scopeRecord);
        // // _funcdef->Body->accept(this);
        // // TableInstance->SetActiveScope()

        // TableInstance->AddFunctionDecAndBody(funcdefrecord, scopeRecord);
        // _funcdef->Body->accept(this);
        // //leave function scope
        // TableInstance->PopScope();
        ContextData::baseSpecPart* spec_info;
        if(_funcdef->specs != NULL){
            spec_info = descendDecSpecs(_funcdef->specs);
        }
        else{
            //presume integer
            spec_info = new ContextData::canonSpecPart(new std::string("int"),NULL);
        }
        decTypeInfo declInf = descendDeclarator(_funcdef->decl);
        declInf.second->AddChild(spec_info);
        declInf.second = spec_info;
        //head is always id for func defs
        std::string funcName = *static_cast<ContextData::IDPart*>(declInf.first)->ast_node->Name;
        TableInstance->ProcessIDDecl(funcName, declInf.first->GetChild());
        TableInstance->PrepareForFuncDef(funcName);
        _funcdef->Body->accept(this);
        TableInstance->PopScope();
    }
    void ASTProcVis::visit(ExternalDeclaration* _extdec){
        //hop straight down to the declaration
        _extdec->decl->accept(this);
    }
