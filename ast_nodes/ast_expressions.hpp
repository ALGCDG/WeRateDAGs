#ifndef AST_EXPR
#define AST_EXPR

#include "ast_node.hpp"
#include "ast_types.hpp"
#include "ast_context.hpp"
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
class IdentifierNode : public Expression{
public:
    std::string Name;
    Context::Record* ContextRecord;
};

class Constant : public Expression{
public:
    union { 
        int int_t; 
        char char_t;
        double dbl_t;
        float flt_t;    
        long long_t;
    };
};

class StringLiteral : public ???HALP{};//TODO
//---------------------------------------------------------
class PostfixExpr : public Expression{
public:
    PostfixExpr(Expression* _LHS) : LHS(_LHS){}
    Expression* LHS;
};

class ArraySubscript : public PostfixExpr{
public:
    ArraySubscript(Expression* _LHS, Expression* _Subscript) : PostfixExpr(_LHS), Subscript(_Subscript){}
private:
    Expression* Subscript;
};

class FuncCall : public PostfixExpr{
public:
    FuncCall(Expression* _LHS) : PostfixExpr(_LHS) {}
    FuncCall(Expression* _LHS, ArgExprList* RHS) : PostfixExpr(_LHS), Args(RHS){}
    ArgExprList* Args;

};

class MemberAccess : public PostfixExpr{
public:
    MemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}
private:
    IdentifierNode* ID;
};

class DerefMemberAccess : public PostfixExpr{
public:
    DerefMemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}
private:
    IdentifierNode* ID;
};

class PostInc : public PostfixExpr{
public:
    using PostfixExpr::PostfixExpr;
};

class PostDec : public PostfixExpr{
public:
    using PostfixExpr::PostfixExpr;
};

//---------------------------------------------------------

class ArgExprList : public Node{
public:
    ArgExprList(Expression* Arg) : Args{Arg}{}
    void AppendArgExpression(Expression* ArgExpr);
    //in the grammar, expression* can be assignment expression
    std::vector<Expression*> Args;
};

//---------------------------------------------------------

class PrefixExpr : public Expression{
public:
    PrefixExpr(Expression* _RHS) : RHS(_RHS){}
    //returns correct unary operator node, described below
    static PrefixExpr* DecodeUnaryOp(std::string* yytext, Expression* _RHS);
private:
    Expression* RHS;
};

class UnaryAddressOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryDerefOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryPlusOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryNegOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryBitwiseNotOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryLogicalNotOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

//The rest of the prefix types:
class PreInc : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class PreDec : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class SizeofExpr : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class SizeofType : public PrefixExpr{
//TODO -> Needs type system
};

class CastExpr : public PrefixExpr{
public:
    CastExpr(type_name* _typ , Expression* _ExprToBeCast) : typ(_typ), ExprToBeCast(_ExprToBeCast){}
    type_name* typ;
    Expression* ExprToBeCast;
//TODO -> Needs type system
};

//---------------------------------------------------------

class BinaryOpExpression : public Expression{
public:
    BinaryOpExpression(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    Expression *LHS, *RHS;  
};

class Multiply : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Divide : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Modulo : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Add : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Sub : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class ShiftLeft : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class ShiftRight : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

//------------
class LogicalBinaryExpression : public BinaryOpExpression{
public:
    LogicalBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS), EvalsToType() /*TODO set to int */ {}
//Always evaluates to int
};

class LessThan : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class GreaterThan : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LessThanOrEqual : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class GreaterThanOrEqual : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class EqualTo : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class NotEqualTo : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LogicalAND : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LogicalOR : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

//------------
class BitwiseBinaryExpression : public BinaryOpExpression{
//type depends on input
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseAND : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseOR : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseXOR : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};
//---------------------------------------------------------

class TernaryOpExpression : public Expression{
private:
    Expression* Condition, IfTrue, IfFalse;
};

//---------------------------------------------------------

class GenericAssignExpr : public Expression{
public:
    GenericAssignExpr(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    static GenericAssignExpr* DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS);

//Not to be used, dummy stand in, supplies decoder
//Value and type of assignment expression is that of the right side argument
    //possibly move this out of this class
    Expression* LHS, *RHS;
};

class AssignmentExpression : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class MulAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class DivAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ModAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class AddAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class SubAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ShiftLeftAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ShiftRightAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseANDAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseXORAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseORAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
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
    CommaSepExpression(Expression* _LHS, Expression* _RHS) : RHS(_RHS), LHS(_LHS){}
private:
    Expression* LHS, *RHS;
};

//---------------------------------------------------------

#endif