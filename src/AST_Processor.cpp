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
std::vector<decTypeInfo>& descendInitDecList(init_declarator_list* _list){
    std::vector<decTypeInfo> listDecInfo;
    init_declarator_list* traversePtr = _list;
    do{
        listDecInfo.push_back(descendInitDec(traversePtr->init_dec));
        traversePtr = traversePtr->init_dec_list;
    }while(traversePtr != NULL);
    return listDecInfo;
}

//get the info from the declaration
decTypeInfo descendInitDec(init_declarator* _init_dec);{
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
            ContextData::argPart* args = descendDeclarator(_this_dir_dec->para_list);
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

ContextData::argPart* ASTProcessorVis::descendDeclarator(parameter_list* _par_list)
{
    //TODO
}
decTypeInfo ASTProcessorVis::descendDeclarator(parameter_declaration* _par_dec)
{
    //TODO
}
decTypeInfo ASTProcessorVis::descendDeclarator(abstract_declarator* _decl ){
    //TODO
}
decTypeInfo ASTProcessorVis::descendDeclarator(direct_abstract_declarator* _dir_abs_dec){
    //TODO
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
    void ASTProcessorVis::visit(declaration* _dectn){}
    void ASTProcessorVis::visit(declaration_specifiers* _decspec){}
    void ASTProcessorVis::visit(init_declarator_list* _indeclis){}
    void ASTProcessorVis::visit(init_declarator* _indec){}
    void ASTProcessorVis::visit(type_specifier* _typespec){}
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
    void ASTProcessorVis::visit(While* _whi){}
    void ASTProcessorVis::visit(DoWhile* _dowhi){}
    void ASTProcessorVis::visit(For* _for){}
    void ASTProcessorVis::visit(If* _if){}
    void ASTProcessorVis::visit(IfElse* _ifelse){}
    void ASTProcessorVis::visit(Switch* _swi){}
    void ASTProcessorVis::visit(CaseOrDefault* _caseordef){}

    //External definitions
    void ASTProcessorVis::visit(TranslationUnit* _trans){
        
    }
    void ASTProcessorVis::visit(FunctionDefinition* _funcdef){}
    void ASTProcessorVis::visit(ExternalDeclaration* _extdec){}