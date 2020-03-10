#include "ast_allnodes.hpp"
#include <iostream>
// #include "visitors.hpp"

// ArgExprList::ArgExprList(Expression* Arg){
//     Args.push_back(Arg);
// }

// void ArgExprList::AppendArgExpression(Expression* ArgExpr){
//     Args.push_back(ArgExpr);
// }

// void TranslationUnit::AppendDeclaration(GenericExternalDeclaration* _decl){
//     decls.push_back(_decl);
// }

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
    std::cerr << "decoding assignment" << std::endl;
    std::string op = *yytext;
    if(op == "="){
        std::cerr << "new = sign" << std::endl;
        return new AssignmentExpression(LHS,RHS);
    }
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

// void Node::accept(Visitor *AVisitor)
// {
//     AVisitor->visit(this);
// }

// void While::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void If::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void IfElse::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void Return::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void CompoundStatement::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void StatementList::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void declaration::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void init_declarator_list::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void init_declarator::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// //Expressions
// void Multiply::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void Add::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void Sub::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void LogicalAND::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void LogicalOR::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void LessThan::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void EqualTo::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void FuncCall::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void ArgExprList::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void IdentifierNode::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void AssignmentExpression::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

// void TranslationUnit::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }
// void ExternalDeclaration::accept(Visitor * AVisitor) 
// {
//     AVisitor->visit(this);
// }

