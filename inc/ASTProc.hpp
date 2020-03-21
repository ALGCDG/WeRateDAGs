#ifndef ASTPROC_HPP
#define ASTPROC_HPP

#include "ast_context2.hpp"
#include "ast_allnodes.hpp"
#include <cassert>

class ASTProcVis : public Visitor{
public:
    ASTProcVis(SymbolTable* _table) : TableInstance(_table){
        //make sure to construct visitor with instance of table
        assert(_table);
    }
    void ProcessAST(TranslationUnit* root){ root->accept(this); }

    void visit(ArraySubscript* _subcr);
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

    //Dec
    void visit(declaration* _dectn);
    void visit(declaration_specifiers* _decspec);
    void visit(init_declarator_list* _indeclis);
    void visit(init_declarator* _indec);
    void visit(type_specifier* _typespec);
    void visit(specifier_list* _speclist);
    void visit(pointer* _pt);
    void visit(base_declarator* _basedec);
    void visit(abstract_declarator* _absdec);
    void visit(direct_abstract_declarator* _absdec);
    void visit(declarator* _declr);
    void visit(direct_declarator* _dirdec);
    void visit(parameter_list* _paramlist);
    void visit(parameter_declaration* _pardec);
    //Sta
    void visit(EmptyStatement* _emptmnt);//do nothing
    void visit(Continue* _cont);//do nothing
    void visit(Break* _brk);//do nothing
    void visit(Return* _ret);
    void visit(ExpressionStatement* _exprstmnt);
    void visit(StatementList* _stmntlist);
    void visit(CompoundStatement* _compstat);

    //sco
    void visit(While* _whi);
    void visit(DoWhile* _dowhi);
    void visit(For* _for);
    void visit(If* _if);
    void visit(IfElse* _ifelse);
    void visit(Switch* _swi);

    void visit(CaseOrDefault* _caseordef);

    //Ext
    void visit(TranslationUnit* _trans);
    void visit(FunctionDefinition* _funcdef);
    void visit(ExternalDeclaration* _extdec);
    void visit(IdentifierNode* _idnode);
    void visit(TypedefNode* _typedef);
    void visit(DeclarationList* decllis);

    void visit(struct_specifier* _strspec);
    void visit(struct_declaration_list* _strdectionlist);
    void visit(struct_declaration* _strdection);
    void visit(struct_declarator_list* _strdeclist);

    unsigned int EvalConstantExpression(ConstantExpression* _const_expr);
    unsigned int EvalConstantExpression(Expression* expr);
    unsigned int EvalConstantExpression(constant_int* _const);
    unsigned int EvalConstantExpression(unspecified_array_length* _unspec);
private:
    SymbolTable* TableInstance;
    std::stack<IdentifierNode*> IDstack;
};

#endif