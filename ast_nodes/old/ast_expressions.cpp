#include "ast_expressions.hpp"

void ArgExprList::AppendArgExpression(Expression* ArgExpr){
    Args.push_back(ArgExpr);
}

/*static*/
PrefixExpr* PrefixExpr::DecodeUnaryOp(std::string* yytext, Expression* _RHS){
    std::string op = *yytext;
    if(op == "*") return new UnaryDerefOperator(_RHS);
    else if(op == "&") return new UnaryAddressOperator(_RHS);
    else if(op == "+") return new UnaryPlusOperator(_RHS);  
    else if(op == "-") return new UnaryNegOperator(_RHS);
    else if(op == "~") return new UnaryBitwiseNotOperator(_RHS);
    else if(op == "!") return new UnaryLogicalNotOperator(_RHS);
    else return NULL;
    
}/*static*/
GenericAssignExpr* GenericAssignExpr::DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS)
{
    std::string op = *yytext;
    if(op == "=") return new AssignmentExpression(LHS,RHS);
    else if(op == "*=") return new MulAssignment(LHS, RHS);
    else if(op == "/=") return new DivAssignment(LHS,RHS);
    else if(op == "%=") return new ModAssignment(LHS,RHS);
    else if(op == "+=") return new AddAssignment(LHS,RHS);
    else if(op == "-=") return new SubAssignment(LHS,RHS);
    else if(op == "<<=") return new ShiftLeftAssignment(LHS,RHS);
    else if(op == ">>=") return new ShiftRightAssignment(LHS,RHS);
    else if(op == "&=") return new BitwiseANDAssignment(LHS,RHS);
    else if(op == "^=") return new BitwiseXORAssignment(LHS,RHS);
    else if(op == "|=") return new BitwiseORAssignment(LHS,RHS);
    else return NULL;
}

