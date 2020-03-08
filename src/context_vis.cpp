#include "context_vis.hpp"

//remember:
//linked list of type parts, head and tail
//typedef std::tuple<Context::typePart*, Context::typePart*> decTypeInfo; 

//getting information out of declarator for use in records
decTypeInfo* ContextVisitor::descendDeclarator(declarator* _decl)
{
    //declarator has member data:
        // pointer (optional)
        // direct declarator

    
}
decTypeInfo* ContextVisitor::descendDeclarator(pointer* _ptr)
{
    if(_ptr->p == NULL){
        //create pointer part, as both the head and tail of the linked list
        ContextData::pointerPart* bottomPointer = new ContextData::pointerPart(NULL);
        return new decTypeInfo(bottomPointer, bottomPointer);
    }
    else{
        decTypeInfo* below = descendDeclarator(_ptr->p);
        //construct new pointer part with the previous head as its child
        ContextData::pointerPart* thisPointer = new ContextData::pointerPart(below->first);
        below->first = thisPointer;
        return below;
    }
}
decTypeInfo* ContextVisitor::descendDeclarator(direct_declarator* _this_dir_dec)
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
        decTypeInfo* below = descendDeclarator(_this_dir_dec->dir_dec);
        if(_this_dir_dec->const_expr != NULL){
            int size = EvalConstantExpression(_this_dir_dec->const_expr);
            ContextData::arrayPart* this_array = new ContextData::arrayPart(size, NULL);
            below->second->AddChild(this_array); //add array to linked list
            below->second = this_array; //make bottom of list this array
            return below;
        }
        else if(_this_dir_dec->para_list!=NULL){
            ContextData::argPart* args = descendDeclarator(_this_dir_dec->para_list);
            ContextData::funcPart* this_func = new ContextData::funcPart(args, NULL);
            below->second->AddChild(this_func);
            below->second = this_func;
            return below;
        }
    }

}
decTypeInfo* ContextVisitor::descendDeclarator(IdentifierNode* _id)
{
    ContextData::IDPart* head = new ContextData::IDPart(_id, NULL);
    return new decTypeInfo(head,head);
}

ContextData::argPart* ContextVisitor::descendDeclarator(parameter_list* _par_list)
{

}
decTypeInfo* ContextVisitor::descendDeclarator(parameter_declaration* _par_dec)
{

}
ContextData::baseSpecPart* ContextVisitor::descendDeclarator(declaration_specifiers* _decl_spec){
    ContextData::baseSpecPart* otherSpecs = NULL;
    if(_decl_spec->specifier!=NULL){ otherSpecs = descendDeclarator(_decl_spec->specifier); }
    if(_decl_spec->storage_class_specifier!=NULL){ return new ContextData::typedefSpecPart(otherSpecs); }
    else if(_decl_spec->type_spec != NULL){ return TableInstance->TypeIsUserOrCanon(_decl_spec->type_spec->type, otherSpecs); }
}
decTypeInfo* ContextVisitor::descendDeclarator(abstract_declarator* _decl ){}
decTypeInfo* ContextVisitor::descendDeclarator(direct_abstract_declarator* _dir_abs_dec){}

//void visit(Node*); //If nothing defined for this type of node
//might require special handling 
    void visit(ArraySubscript*);
    void visit(FuncCall*);
    void visit(MemberAccess*);
    void visit(DerefMemberAccess*);
    void visit(ArgExprList*);
    void visit(SizeofExpr*);
    void visit(SizeofType*);
    void visit(UnaryAddressOperator*);
    void visit(UnaryDerefOperator*);
    void visit(PostInc*);
    void visit(PostDec*);
    void visit(CastExpr*);
    void visit(AssignmentExpression*);

    //might not need to handle with this visitor
    void visit(Constant*);
    void visit(UnaryPlusOperator*);
    void visit(UnaryNegOperator*);
    void visit(UnaryBitwiseNotOperator*);
    void visit(UnaryLogicalNotOperator*);
    void visit(PreInc*);
    void visit(PreDec*);
    void visit(Multiply*);
    void visit(Divide*);
    void visit(Modulo*);
    void visit(Add*);
    void visit(Sub*);
    void visit(ShiftLeft*);
    void visit(ShiftRight*);
    void visit(LessThan*);
    void visit(GreaterThan*);
    void visit(LessThanOrEqual*);
    void visit(GreaterThanOrEqual*);
    void visit(EqualTo*);
    void visit(NotEqualTo*);
    void visit(LogicalAND*);
    void visit(LogicalOR*);
    void visit(BitwiseAND*);
    void visit(BitwiseOR*);
    void visit(BitwiseXOR*);
    void visit(TernaryOpExpression*);
    void visit(MulAssignment*);
    void visit(DivAssignment*);
    void visit(ModAssignment*);
    void visit(AddAssignment*);
    void visit(SubAssignment*);
    void visit(ShiftLeftAssignment*);
    void visit(ShiftRightAssignment*);
    void visit(BitwiseANDAssignment*);
    void visit(BitwiseXORAssignment*);
    void visit(BitwiseORAssignment*);
    void visit(ConstantExpression*);
    void visit(CommaSepExpression*);

    //Declarations
    void visit(declaration*);
    void visit(declaration_specifiers*);
    void visit(init_declarator_list*);
    void visit(init_declarator*);
    void visit(type_specifier*);
    void visit(specifier_list*);
    void visit(pointer*);
    void visit(base_declarator*);
    void visit(abstract_declarator*);
    void visit(declarator*);

    //Statements
    void visit(EmptyStatement*);
    void visit(Continue*);
    void visit(Break*);
    void visit(Return*);
    void visit(ExpressionStatement*);
    void visit(StatementList*);
    void visit(CompoundStatement*);

    //scope changing
    void visit(While*);
    void visit(DoWhile*);
    void visit(For*);
    void visit(If*);
    void visit(IfElse*);
    void visit(Switch*);
    void visit(CaseOrDefault*);

    //External definitions
    void visit(TranslationUnit*);
    void visit(FunctionDefinition*);
    void visit(ExternalDeclaration*);