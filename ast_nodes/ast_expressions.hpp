#ifndef AST_EXPR
#define AST_EXPR

#include "ast_node.hpp"
#include "ast_types.hpp"
#include <vector>
#include <string>
//TODO:
//!Change relevent private members to protected
// Identifier  (and constant, string-literal etc)
// "Type name" as an expression


//?
// Should the decode functions be in the class?

class Expression : public Node{
public:
    Type* EvalsToType;
private:
};

//primary expr
class Identifier : public Expression{
public:
    Type* GetType();
private:
    std::string* Name;
};

class StringLiteral : public ???HALP{};//TODO
//---------------------------------------------------------
class PostfixExpr : public Expression{
public:
    PostfixExpr(Expression* LHS);
protected:
    Expression* LHS;
};

class ArraySubscript : public PostfixExpr{
public:
    ArraySubscript(Expression* LHS, Expression* Subscript);
private:
    Expression* Subscript;
};

class FuncCall : public PostfixExpr{
    FuncCall(Expression* LHS);
    FuncCall(Expression* LHS, ArgExprList* RHS);
private:
    ArgExprList* Args;
};

class MemberAccess : public PostfixExpr{
private:
    std::string* ID;
};

class DerefMemberAccess : public PostfixExpr{
private:
    std::string* ID;
};

class PostInc : public PostfixExpr{

};

class PostDec : public PostfixExpr{

};

//---------------------------------------------------------

class ArgExprList : public Node{
public:
    ArgExprList(Expression* Arg);
    void AppendArgExpression(Expression* ArgExpr);
private:
    std::vector<Expression*> Args;
};

//---------------------------------------------------------

class PrefixExpr : public Expression{
    //returns correct unary operator node, described below
    static PrefixExpr* DecodeUnaryOperator(std::string* yytext);
private:
    Expression* RHS;
};

class UnaryAddressOperator : public PrefixExpr{

};

class UnaryDerefOperator : public PrefixExpr{

};

class UnaryPlusOperator : public PrefixExpr{

};

class UnaryNegOperator : public PrefixExpr{

};

class UnaryBitwiseNotOperator : public PrefixExpr{

};

class UnaryLogicalNotOperator : public PrefixExpr{

};

//The rest of the prefix types:
class PreInc : public PrefixExpr{

};

class PreDec : public PrefixExpr{

};

class SizeofExpr : public PrefixExpr{

};

class SizeofType : public PrefixExpr{
//need type system
};

class CastExpr : public PrefixExpr{
public:
    CastExpr(Type? , Expression* ExprToBeCast);
//need type system
};

//---------------------------------------------------------

class BinaryOpExpression : public Expression{
private:
    Expression* LHS, RHS;  
};

class Multiply : public BinaryOpExpression{

};

class Divide : public BinaryOpExpression{

};

class Modulo : public BinaryOpExpression{

};

class Add : public BinaryOpExpression{

};

class Sub : public BinaryOpExpression{

};

class ShiftLeft : public BinaryOpExpression{

};

class ShiftRight : public BinaryOpExpression{

};

//------------
class LogicalBinaryExpression : public BinaryOpExpression{
//Always evaluates to int
};

class LessThan : public LogicalBinaryExpression{

};

class GreaterThan : public LogicalBinaryExpression{

};

class LessThanOrEqual : public LogicalBinaryExpression{

};

class GreaterThanOrEqual : public LogicalBinaryExpression{

};

class EqualTo : public LogicalBinaryExpression{

};

class NotEqualTo : public LogicalBinaryExpression{

};

class LogicalAND : public LogicalBinaryExpression{

};

class LogicalOR : public LogicalBinaryExpression{

};

//------------
class BitwiseBinaryExpression : public BinaryOpExpression{
//type depends on input
};

class BitwiseAND : public BitwiseBinaryExpression{

};

class BitwiseOR : public BitwiseBinaryExpression{

};

class BitwiseXOR : public BitwiseBinaryExpression{

};
//---------------------------------------------------------

class TernaryOpExpression : public Expression{
private:
    Expression* Condition, IfTrue, IfFalse;
};

//---------------------------------------------------------

class GenericAssignExpr : public Expression{
    static GenericAssignExpr* DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS);

//Not to be used, dummy stand in, supplies decoder
//Value and type of assignment expression is that of the right side argument
public:
    //possibly move this out of this class
private:
    Expression* LHS, RHS;
};

class AssignmentExpression : public GenericAssignExpr{

};

class MulAssignment : public GenericAssignExpr{

};

class DivAssignment : public GenericAssignExpr{

};

class ModAssignment : public GenericAssignExpr{

};

class AddAssignment : public GenericAssignExpr{

};

class SubAssignment : public GenericAssignExpr{

};

class ShiftLeftAssignment : public GenericAssignExpr{

};

class ShiftRightAssignment : public GenericAssignExpr{

};

class BitwiseANDAssignment : public GenericAssignExpr{

};

class BitwiseNOTAssignment : public GenericAssignExpr{

};

class BitwiseORAssignment : public GenericAssignExpr{

};

//---------------------------------------------------------

class ConstantExpression : public Expression{
public:
    ConstantExpression(Expression* Expr);
private:
    Expression* ConstantSubtree;
};

//TODO Comma seperated expression? Grammar from annex:
// expression ::= assignment-expression | expression "," assignment-expression

class CommaSepExpression : public Expression{
public:
    CommaSepExpression(Expression* LHS, Expression* RHS);
private:
    Expression* LHS, RHS;
};

//---------------------------------------------------------

#endif