#ifndef VISITORS_HPP
#define VISITORS_HPP

#include "ast_expressions.hpp"
#include "ast_statements.hpp"
#include "ast_externaldefs.hpp"

class Visitor{
public:
    //they don't all want to be pure virtual
    //only stuff that must be implemented in all visitors should be
    
    //potential to combine some of the visits into the same overload?
    //Expressions
    virtual void visit(Node*); //If nothing defined for this type of node
    virtual void visit(ArraySubscript*) = 0;
    virtual void visit(FuncCall*) = 0;
    virtual void visit(MemberAccess*) = 0;
    virtual void visit(DerefMemberAccess*) = 0;
    virtual void visit(PostInc*) = 0;
    virtual void visit(PostDec*) = 0;
    virtual void visit(ArgExprList*) = 0;
    virtual void visit(UnaryAddressOperator*) = 0;
    virtual void visit(UnaryDerefOperator*) = 0;
    virtual void visit(UnaryPlusOperator*) = 0;
    virtual void visit(UnaryNegOperator*) = 0;
    virtual void visit(UnaryBitwiseNotOperator) = 0;
    virtual void visit(UnaryLogicalNotOperator) = 0;
    virtual void visit(PreInc*) = 0;
    virtual void visit(PreDec*) = 0;
    virtual void visit(SizeofExpr*) = 0;
    virtual void visit(SizeofType*) = 0;
    virtual void visit(CastExpr*) = 0;
    virtual void visit(Multiply*) = 0;
    virtual void visit(Divide*) = 0;
    virtual void visit(Modulo*) = 0;
    virtual void visit(Add*) = 0;
    virtual void visit(Sub*) = 0;
    virtual void visit(ShiftLeft*) = 0;
    virtual void visit(ShiftRight*) = 0;
    virtual void visit(LessThan*) = 0;
    virtual void visit(GreaterThan*) = 0;
    virtual void visit(LessThanOrEqual*) = 0;
    virtual void visit(GreaterThanOrEqual*) = 0;
    virtual void visit(EqualTo*) = 0;
    virtual void visit(NotEqualTo*) = 0;
    virtual void visit(LogicalAND*) = 0;
    virtual void visit(LogicalOR*) = 0;
    virtual void visit(BitwiseAND*) = 0;
    virtual void visit(BitwiseOR*) = 0;
    virtual void visit(BitwiseXOR*) = 0;
    virtual void visit(TernaryOpExpression*) = 0;
    virtual void visit(AssignmentExpression*) = 0;
    virtual void visit(MulAssignment*) = 0;
    virtual void visit(DivAssignment*) = 0;
    virtual void visit(ModAssignment*) = 0;
    virtual void visit(AddAssignment*) = 0;
    virtual void visit(SubAssignment*) = 0;
    virtual void visit(ShiftLeftAssignment*) = 0;
    virtual void visit(ShiftRightAssignment*) = 0;
    virtual void visit(BitwiseANDAssignment*) = 0;
    virtual void visit(BitwiseXORAssignment*) = 0;
    virtual void visit(BitwiseORAssignment*) = 0;
    virtual void visit(ConstantExpression*) = 0;
    virtual void visit(CommaSepExpression*) = 0;

    //Statements
    virtual void visit(EmptyStatement*) = 0;
    virtual void visit(Continue*) = 0;
    virtual void visit(Break*) = 0;
    virtual void visit(Return*) = 0;
    virtual void visit(While*) = 0;
    virtual void visit(DoWhile*) = 0;
    virtual void visit(For*) = 0;
    virtual void visit(If*) = 0;
    virtual void visit(IfElse*) = 0;
    virtual void visit(Switch*) = 0;
    virtual void visit(ExpressionStatement*) = 0;
    virtual void visit(StatementList*) = 0;
    virtual void visit(CompoundStatement*) = 0;
    virtual void visit(CaseOrDefault*) = 0;

    //External definitions
    virtual void visit(TranslationUnit*) = 0;
    virtual void visit(ExternalFuncDef*) = 0;
    virtual void visit(ExternalDeclaration*) = 0;
    
    //Declarations

}

#endif