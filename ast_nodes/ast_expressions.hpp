#ifndef AST_EXPR
#define AST_EXPR

#include <vector>
#include <string>
//TODO:
// Identifier  (and constant, string-literal etc)
// "Type name" as an expression

//?
// Should the decode functions be in the class?

class Expression{
private:
    Type EvalsToType;
};

//primary expr

//---------------------------------------------------------
class PostfixExpr : public Expression{
private:
    Expression* LHS;
};

class ArraySubscript : public PostfixExpr{
private:
    Expression* Subscript;
};

class FuncCall : public PostfixExpr{
private:
    ArgExprList* Args;
};

class MemberAccess : public PostfixExpr{
private:
    Identifier ID;
};

class DerefMemberAccess : public PostfixExpr{
private:
    Identifier ID;
};

class PostInc : public PostfixExpr{

};

class PostDec : public PostfixExpr{

};

//---------------------------------------------------------

class ArgExprList{
public:
    void AppendArgExpression(Expression* ArgExpr);
private:
    std::vector<Expression*> Args;
};

//---------------------------------------------------------

class PrefixExpr : public Expression{
    //returns correct unary operator node, described below
    PrefixExpr* DecodeUnaryOperator(std::string* yytext);
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
class GenericAssignmentExpression : public Expression{
//Not to be used, dummy stand in, supplies decoder
//Value and type of assignment expression is that of the right side argument
public:
    //possibly move this out of this class
    GenericAssignmentExpression* DecodeAssignmentOperator(std::string* yytext);
private:
    Expression* LHS, RHS;
};

class AssignmentExpression : public GenericAssignmentExpression{

};

class MulAssignment : public GenericAssignmentExpression{

};

class DivAssignment : public GenericAssignmentExpression{

};

class ModAssignment : public GenericAssignmentExpression{

};

class AddAssignment : public GenericAssignmentExpression{

};

class SubAssignment : public GenericAssignmentExpression{

};

class ShiftLeftAssignment : public GenericAssignmentExpression{

};

class ShiftRightAssignment : public GenericAssignmentExpression{

};

class BitwiseANDAssignment : public GenericAssignmentExpression{

};

class BitwiseNOTAssignment : public GenericAssignmentExpression{

};

class BitwiseORAssignment : public GenericAssignmentExpression{

};

//---------------------------------------------------------

class ConstantExpression : public Expression{
private:
    Expression* ConstantSubtree;
};

//TODO Comma seperated expression? Grammar from annex:
// expression ::= assignment-expression | expression "," assignment-expression

class CommaSepExpression : public Expression{
private:
    Expression* LHS, RHS;
};

//---------------------------------------------------------

#endif