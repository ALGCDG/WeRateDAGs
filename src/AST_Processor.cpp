#include "AST_Processor.hpp"

//remember:
//linked list of type parts, head and tail
//typedef std::tuple<Context::typePart*, Context::typePart*> decTypeInfo; 

//getting information out of declarator for use in records
ContextData::baseSpecPart* ASTProcessorVis::descendDecSpecs(declaration_specifiers* _decl_spec){
    ContextData::baseSpecPart* otherSpecs = NULL;
    if(_decl_spec->specifier!=NULL){ otherSpecs = descendDecSpecs(_decl_spec->specifier); }
    if(_decl_spec->storage_class_specifier!=NULL){ return new ContextData::typedefSpecPart(otherSpecs); }
    else if(_decl_spec->type_spec != NULL){ return TableInstance->TypeIsUserOrCanon(_decl_spec->type_spec->type, otherSpecs); }
}

//get decType info from each of the items in the list
std::vector<decTypeInfo>& ASTProcessorVis::descendInitDecList(init_declarator_list* _list){
    std::vector<decTypeInfo> listDecInfo;
    init_declarator_list* traversePtr = _list;
    do{
        listDecInfo.push_back(descendInitDec(traversePtr->init_dec));
        traversePtr = traversePtr->init_dec_list;
    }while(traversePtr != NULL);
    return listDecInfo;
}

//get the info from the declaration
decTypeInfo ASTProcessorVis::descendInitDec(init_declarator* _init_dec){
    return descendDeclarator(_init_dec->dec);
}


decTypeInfo ASTProcessorVis::descendDeclarator(pointer* _ptr)
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
decTypeInfo ASTProcessorVis::descendDeclarator(declarator* _decl)
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
decTypeInfo ASTProcessorVis::descendDeclarator(direct_declarator* _this_dir_dec)
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
            int size = EvalConstantExpression(_this_dir_dec->const_expr);
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

decTypeInfo ASTProcessorVis::descendDeclarator(IdentifierNode* _id)
{
    ContextData::IDPart* head = new ContextData::IDPart(_id, NULL);
    return decTypeInfo(head,head);
}

ContextData::argsPart* ASTProcessorVis::descendDeclarator(parameter_list* _par_list)
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

ContextData::argPart* ASTProcessorVis::descendDeclarator(parameter_declaration* _par_dec)
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
decTypeInfo ASTProcessorVis::descendDeclarator(base_declarator * _decl){
    throw("base declarator encountered instead of specic abstract or direct:(");
}
decTypeInfo ASTProcessorVis::descendDeclarator(abstract_declarator* _decl ){
    throw("abstract processor not yet implemented");
}
decTypeInfo ASTProcessorVis::descendDeclarator(direct_abstract_declarator* _dir_abs_dec){
    throw("direct abstract proessor not yet implemented");

}

//void visit(Node*); //If nothing defined for this type of node
//might require special handling 
    void ASTProcessorVis::visit(ArraySubscript* _subcr){}
    void ASTProcessorVis::visit(FuncCall* _funccall){}
    void ASTProcessorVis::visit(MemberAccess* _memberaccess){}
    void ASTProcessorVis::visit(DerefMemberAccess* _derefmemberacc){}
    void ASTProcessorVis::visit(ArgExprList* _argexprlist){}
    void ASTProcessorVis::visit(SizeofExpr* _sizeofexpr){}
    void ASTProcessorVis::visit(SizeofType* _sizeoftype){}
    void ASTProcessorVis::visit(UnaryAddressOperator* _addrOp){}
    void ASTProcessorVis::visit(UnaryDerefOperator* derefOp){}
    void ASTProcessorVis::visit(PostInc* _postinc){}
    void ASTProcessorVis::visit(PostDec* _postdec){}
    void ASTProcessorVis::visit(CastExpr* _castexpr){}
    void ASTProcessorVis::visit(AssignmentExpression* _assignexpr){}

    //might not need to handle with this visitor
    void ASTProcessorVis::visit(Constant* _constant){}
    void ASTProcessorVis::visit(UnaryPlusOperator* _unaryplus){}
    void ASTProcessorVis::visit(UnaryNegOperator* _unaryneg){}
    void ASTProcessorVis::visit(UnaryBitwiseNotOperator* _unaryBitNot){}
    void ASTProcessorVis::visit(UnaryLogicalNotOperator* _unaryLogNot){}
    void ASTProcessorVis::visit(PreInc* _preinc){}
    void ASTProcessorVis::visit(PreDec* _predec){}
    void ASTProcessorVis::visit(Multiply* _mul){}
    void ASTProcessorVis::visit(Divide* _div){}
    void ASTProcessorVis::visit(Modulo* _mod){}
    void ASTProcessorVis::visit(Add* _add){}
    void ASTProcessorVis::visit(Sub* _sub){}
    void ASTProcessorVis::visit(ShiftLeft* _shl){}
    void ASTProcessorVis::visit(ShiftRight* _shr){}
    void ASTProcessorVis::visit(LessThan* _lt){}
    void ASTProcessorVis::visit(GreaterThan* _gt){}
    void ASTProcessorVis::visit(LessThanOrEqual* _lte){}
    void ASTProcessorVis::visit(GreaterThanOrEqual* _gte){}
    void ASTProcessorVis::visit(EqualTo* _eq){}
    void ASTProcessorVis::visit(NotEqualTo* _ne){}
    void ASTProcessorVis::visit(LogicalAND* _logand){}
    void ASTProcessorVis::visit(LogicalOR* _logor){}
    void ASTProcessorVis::visit(BitwiseAND* _bitand){}
    void ASTProcessorVis::visit(BitwiseOR* _bitor){}
    void ASTProcessorVis::visit(BitwiseXOR* _bitxor){}
    void ASTProcessorVis::visit(TernaryOpExpression* _tern){}
    void ASTProcessorVis::visit(MulAssignment* _mulass){}
    void ASTProcessorVis::visit(DivAssignment* _divass){}
    void ASTProcessorVis::visit(ModAssignment* _modass){}
    void ASTProcessorVis::visit(AddAssignment* _addass){}
    void ASTProcessorVis::visit(SubAssignment* _subass){}
    void ASTProcessorVis::visit(ShiftLeftAssignment* _shlass){}
    void ASTProcessorVis::visit(ShiftRightAssignment* _shrass){}
    void ASTProcessorVis::visit(BitwiseANDAssignment* _bANDass){}
    void ASTProcessorVis::visit(BitwiseXORAssignment* _xorass){}
    void ASTProcessorVis::visit(BitwiseORAssignment* _bORass){}
    void ASTProcessorVis::visit(ConstantExpression* _constexpr){}
    void ASTProcessorVis::visit(CommaSepExpression* _comsep){}

    //Declarations
    void ASTProcessorVis::visit(declaration* _dectn){
        //TODO
        if(_dectn->list!=NULL){
            ContextData::baseSpecPart* specs = descendDecSpecs(_dectn->specifier);
            std::vector<decTypeInfo> initList_info = descendInitDecList(_dectn->list);
            for(auto info : initList_info){
                //deep copy the dec specs, so that seperate decls in the list aren't connected
                ContextData::baseSpecPart* specCpy = ContextData::baseSpecPart::CopySpecList(specs);
                info.second->AddChild(specCpy);
                ContextData::IDPart* id = static_cast<ContextData::IDPart*>(info.first);
                std::string* name = new std::string(*(id->ast_node->Name));
                ContextData::VariableDeclarationRec* rec = new ContextData::VariableDeclarationRec(name, info.first);
                TableInstance->AddObjectRecord(rec);
            }
            delete specs;
        }
        //do nothing otherwise
    }
    void ASTProcessorVis::visit(declaration_specifiers* _decspec){
        //TODO possibly will never visit (access through descender)
        throw("should not be visiting dec specs with processor");
    }
    void ASTProcessorVis::visit(init_declarator_list* _indeclis){
        throw("should not be visiting init dec list");
    }
    void ASTProcessorVis::visit(init_declarator* _indec){
        throw("should not be visiting int dec");
    }
    void ASTProcessorVis::visit(type_specifier* _typespec){
        throw("");
    }
    void ASTProcessorVis::visit(specifier_list* _speclist){}
    void ASTProcessorVis::visit(pointer* _pt){}
    void ASTProcessorVis::visit(base_declarator* _basedec){}
    void ASTProcessorVis::visit(abstract_declarator* _absdec){}
    void ASTProcessorVis::visit(declarator* _declr){}

    //Statements
    void ASTProcessorVis::visit(EmptyStatement* _emptmnt){}
    void ASTProcessorVis::visit(Continue* _cont){}
    void ASTProcessorVis::visit(Break* _brk){}
    void ASTProcessorVis::visit(Return* _ret){}
    void ASTProcessorVis::visit(ExpressionStatement* _exprstmnt){}
    void ASTProcessorVis::visit(StatementList* _stmntlist){}
    void ASTProcessorVis::visit(CompoundStatement* _compstat){}

    //scope changing
    void ASTProcessorVis::visit(While* _whi){
        _whi->ControlExpression->accept(this);
        TableInstance->NewScope();
        _whi->Body->accept(this);
        TableInstance->PopScope();
    }
    void ASTProcessorVis::visit(DoWhile* _dowhi){
        TableInstance->NewScope();
        _dowhi->Body->accept(this);
        TableInstance->PopScope();
        //control expression is in scope above the body
        _dowhi->ControlExpression->accept(this);
    }
    void ASTProcessorVis::visit(For* _for){

    }
    void ASTProcessorVis::visit(If* _if){}
    void ASTProcessorVis::visit(IfElse* _ifelse){}
    void ASTProcessorVis::visit(Switch* _swi){}
    void ASTProcessorVis::visit(CaseOrDefault* _caseordef){}

    //External definitions
    void ASTProcessorVis::visit(TranslationUnit* _trans){
        for (auto el : _trans->decls){
            el->accept(this);
        }
    }
    void ASTProcessorVis::visit(FunctionDefinition* _funcdef){
        //TODO consider declaratinos preceding definitions
        ContextData::baseSpecPart* spec_info;
        if(_funcdef->specs != NULL){
            spec_info = descendDecSpecs(_funcdef->specs);
        }
        else{
            //presume integer
            spec_info = new ContextData::canonSpecPart(new std::string("int"),NULL);
        }
        decTypeInfo decl_info = descendDeclarator(_funcdef->decl);
        decl_info.second->AddChild(spec_info);
        decl_info.second = spec_info;
        //head of list is deffo identifier, so can do this
        ContextData::IDPart* id = static_cast<ContextData::IDPart*>(decl_info.first);
        ContextData::FunctionDef* funcdefrecord = new ContextData::FunctionDef(id->ast_node->Name, decl_info.first);
        
        // TableInstance->AddObjectRecord(funcdefrecord);
        id->ast_node->ContextRecord = funcdefrecord; //link id node in ast to def in table
        auto scopeRecord = new ContextData::FunctionScopeRecord();
        // //link together dec and def
        // scopeRecord->SetDeclarationPtr(funcdefrecord);
        // funcdefrecord->SetDefRecordPtr(scopeRecord);
        // TableInstance->SetActiveScope(scopeRecord);
        // _funcdef->Body->accept(this);
        // TableInstance->SetActiveScope()

        TableInstance->AddFunctionDecAndBody(funcdefrecord, scopeRecord);
        _funcdef->Body->accept(this);
        //leave function scope
        TableInstance->PopScope();
    }
    void ASTProcessorVis::visit(ExternalDeclaration* _extdec){
        //hop straight down to the declaration
        _extdec->decl->accept(this);
    }
