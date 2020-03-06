#ifndef VISITORS_HPP
#define VISITORS_HPP

#include "ast_allnodes.hpp"

class Visitor{
public:
    //they don't all want to be pure virtual
    //only stuff that must be implemented in all visitors should be
    
    //potential to combine some of the visits into the same overload?
    //Expressions
    virtual void visit(Node*); //If nothing defined for this type of node
    virtual void visit(Constant*);
    virtual void visit(ArraySubscript*);
    virtual void visit(FuncCall*);
    virtual void visit(MemberAccess*);
    virtual void visit(DerefMemberAccess*);
    virtual void visit(PostInc*);
    virtual void visit(PostDec*);
    virtual void visit(ArgExprList*);
    virtual void visit(UnaryAddressOperator*);
    virtual void visit(UnaryDerefOperator*);
    virtual void visit(UnaryPlusOperator*);
    virtual void visit(UnaryNegOperator*);
    virtual void visit(UnaryBitwiseNotOperator*);
    virtual void visit(UnaryLogicalNotOperator*);
    virtual void visit(PreInc*);
    virtual void visit(PreDec*);
    virtual void visit(SizeofExpr*);
    virtual void visit(SizeofType*);
    virtual void visit(CastExpr*);
    virtual void visit(Multiply*);
    virtual void visit(Divide*);
    virtual void visit(Modulo*);
    virtual void visit(Add*);
    virtual void visit(Sub*);
    virtual void visit(ShiftLeft*);
    virtual void visit(ShiftRight*);
    virtual void visit(LessThan*);
    virtual void visit(GreaterThan*);
    virtual void visit(LessThanOrEqual*);
    virtual void visit(GreaterThanOrEqual*);
    virtual void visit(EqualTo*);
    virtual void visit(NotEqualTo*);
    virtual void visit(LogicalAND*);
    virtual void visit(LogicalOR*);
    virtual void visit(BitwiseAND*);
    virtual void visit(BitwiseOR*);
    virtual void visit(BitwiseXOR*);
    virtual void visit(TernaryOpExpression*);
    virtual void visit(AssignmentExpression*);
    virtual void visit(MulAssignment*);
    virtual void visit(DivAssignment*);
    virtual void visit(ModAssignment*);
    virtual void visit(AddAssignment*);
    virtual void visit(SubAssignment*);
    virtual void visit(ShiftLeftAssignment*);
    virtual void visit(ShiftRightAssignment*);
    virtual void visit(BitwiseANDAssignment*);
    virtual void visit(BitwiseXORAssignment*);
    virtual void visit(BitwiseORAssignment*);
    virtual void visit(ConstantExpression*);
    virtual void visit(CommaSepExpression*);

    //Statements
    virtual void visit(EmptyStatement*);
    virtual void visit(Continue*);
    virtual void visit(Break*);
    virtual void visit(Return*);
    virtual void visit(While*);
    virtual void visit(DoWhile*);
    virtual void visit(For*);
    virtual void visit(If*);
    virtual void visit(IfElse*);
    virtual void visit(Switch*);
    virtual void visit(ExpressionStatement*);
    virtual void visit(StatementList*);
    virtual void visit(CompoundStatement*);
    virtual void visit(CaseOrDefault*);

    //External definitions
    virtual void visit(TranslationUnit*);
    virtual void visit(FunctionDefinition*);
    virtual void visit(ExternalDeclaration*);
    
    //Declarations

};

#endif
