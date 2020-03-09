#ifndef CONTEXTVIS_HPP
#define CONTEXTVIS_HPP

#include "ast_context.hpp"
#include "visitors.hpp"
#include "ast_allnodes.hpp"
#include <cassert>

#include <utility> //std::pair

class ASTProcessorVis : public Visitor{
public:
/*  Needs to link all identifiers in the ast with info in the table
    Needs to intereact with table for scope changes, add records, change records?
    Also needs to provide algorithms for getting:
        ID from declaration
        Type as type parts from declaration

        Stack frame / pointer locations

*/
    ASTProcessorVis(ContextTable* _table) : TableInstance(_table){
        //make sure to construct visitor with instance of table
        assert(_table);
    }
    void ProcessAST(Node* root);
private:
    ContextData::Record* GetRecord(const std::string &_id);
    //ContextData::Record* CreateRecord(declaration* _dect);
    
    //<ID at bottom, top type part in hierarchy, pointer to next type part that needs to be filled in> 

    //will return a linked list something like unsigned -> long -> int
    ContextData::baseSpecPart* descendDecSpecs(declaration_specifiers* _decl_spec);

    std::vector<decTypeInfo*>& descendInitDecList(init_declarator_list* _list);
    decTypeInfo descendInitDec(init_declarator* _init_dec); //basically just ignore init part, not relevant for table
    decTypeInfo descendDeclarator(pointer* _ptr);
    decTypeInfo descendDeclarator(declarator* _decl);

    decTypeInfo descendDeclarator(direct_declarator* _dir_dec);
    decTypeInfo descendDeclarator(IdentifierNode* _id);
    ContextData::argPart* descendDeclarator(parameter_list* _par_list);
    decTypeInfo descendDeclarator(parameter_declaration* _par_dec);
    decTypeInfo descendDeclarator(abstract_declarator* _decl);
    decTypeInfo descendDeclarator(direct_abstract_declarator* _dir_abs_dec);

    //evaluates constant expression, (returns -1 if unspecified size)
    int EvalConstantExpression(ConstantExpression* _const_expr);
    ContextTable* TableInstance;
    void visit(ArraySubscript* _subcr){}
    void visit(FuncCall* _funccall);
    void visit(MemberAccess* _memberaccess);
    void visit(DerefMemberAccess* _derefmemberacc);
    void visit(ArgExprList* _argexprlist);
    void visit(SizeofExpr* _sizeofexpr);
    void visit(SizeofType* _sizeoftype);
    void visit(UnaryAddressOperator* _addrOp);
    void visit(UnaryDerefOperator* derefOp);
    void visit(PostInc* _postinc);
    void visit(PostDec* _postdec);
    void visit(CastExpr* _castexpr);
    void visit(AssignmentExpression* _assignexpr);

    //might not need to handle with this visitor
    void visit(Constant* _constant);
    void visit(UnaryPlusOperator* _unaryplus);
    void visit(UnaryNegOperator* _unaryneg);
    void visit(UnaryBitwiseNotOperator* _unaryBitNot);
    void visit(UnaryLogicalNotOperator* _unaryLogNot);
    void visit(PreInc* _preinc);
    void visit(PreDec* _predec);
    void visit(Multiply* _mul);
    void visit(Divide* _div);
    void visit(Modulo* _mod);
    void visit(Add* _add);
    void visit(Sub* _sub);
    void visit(ShiftLeft* _shl);
    void visit(ShiftRight* _shr);
    void visit(LessThan* _lt);
    void visit(GreaterThan* _gt);
    void visit(LessThanOrEqual* _lte);
    void visit(GreaterThanOrEqual* _gte);
    void visit(EqualTo* _eq);
    void visit(NotEqualTo* _ne);
    void visit(LogicalAND* _logand);
    void visit(LogicalOR* _logor);
    void visit(BitwiseAND* _bitand);
    void visit(BitwiseOR* _bitor);
    void visit(BitwiseXOR* _bitxor);
    void visit(TernaryOpExpression* _tern);
    void visit(MulAssignment* _mulass);
    void visit(DivAssignment* _divass);
    void visit(ModAssignment* _modass);
    void visit(AddAssignment* _addass);
    void visit(SubAssignment* _subass);
    void visit(ShiftLeftAssignment* _shlass);
    void visit(ShiftRightAssignment* _shrass);
    void visit(BitwiseANDAssignment* _bANDass);
    void visit(BitwiseXORAssignment* _xorass);
    void visit(BitwiseORAssignment* _bORass);
    void visit(ConstantExpression* _constexpr);
    void visit(CommaSepExpression* _comsep);

    //Declarations
    void visit(declaration* _dectn);
    void visit(declaration_specifiers* _decspec);
    void visit(init_declarator_list* _indeclis);
    void visit(init_declarator* _indec);
    void visit(type_specifier* _typespec);
    void visit(specifier_list* _speclist);
    void visit(pointer* _pt);
    void visit(base_declarator* _basedec);
    void visit(abstract_declarator* _absdec);
    void visit(declarator* _declr);

    //Statements
    void visit(EmptyStatement* _emptmnt);
    void visit(Continue* _cont);
    void visit(Break* _brk);
    void visit(Return* _ret);
    void visit(ExpressionStatement* _exprstmnt);
    void visit(StatementList* _stmntlist);
    void visit(CompoundStatement* _compstat);

    //scope changing
    void visit(While* _whi){}
    void visit(DoWhile* _dowhi);
    void visit(For* _for);
    void visit(If* _if);
    void visit(IfElse* _ifelse);
    void visit(Switch* _swi);
    void visit(CaseOrDefault* _caseordef);

    //External definitions
    void visit(TranslationUnit* _trans);
    void visit(FunctionDefinition* _funcdef);
    void visit(ExternalDeclaration* _extdec);
    
};

namespace{
    //linked list of type parts, head and tail
    typedef std::pair<ContextData::typePart*, ContextData::typePart*> decTypeInfo;  
}

#endif