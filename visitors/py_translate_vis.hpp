#ifndef PYTRVISIT_HPP
#define PYTRVISIT_HPP

#include <string>

#include "visitors.hpp"
#include "ast_expressions.hpp"
#include "ast_statements.hpp"

class python_Visitor: public Visitor
{
    int indentation;
    std::string gentabs()
    {
        std::string indent = "";
        for (int i = 0; i < indentation; i++)
        {
            indent += "\t";
        }
        return indent;
    }

    void visit(While* w)
    {
        std::cout << gentabs() << "while ";
        w->Body->accept(this);
        std::cout << " :" << std::endl;
        indentation++;
        w->Body->accept(this);
        indentation--;
    }

    void visit(If* i)
    {
    }

    //Expressions
    void visit(Multiply* binaryOp){
        binaryOp->LHS->accept(this);
        std::cout << " * ";
        binaryOp->RHS->accept(this);
    }
    void visit(Add* binaryOp){
        (binaryOp -> LHS) -> accept(this);
        std::cout << " + ";
        (binaryOp -> RHS) -> accept(this);
    }
    void visit(Sub* binaryOp){
        binaryOp -> LHS -> accept(this);
        std::cout << " - ";
        binaryOp -> RHS -> accept(this);
    }
    
    void visit(LogicalAND* binaryOp){
        binaryOp -> LHS -> accept(this);
        std::cout << " and ";
        binaryOp -> RHS -> accept(this);
    }
    void visit(LogicalOR* binaryOp){
        binaryOp -> LHS -> accept(this);
        std::cout << " or ";
        binaryOp -> RHS -> accept(this);
    }
    void visit(LessThan* binaryOp){
        binaryOp -> LHS -> accept(this);
        std::cout << " < ";
        binaryOp -> RHS -> accept(this);
    }
    void visit(EqualTo* binaryOp){
        binaryOp -> LHS -> accept(this);
        std::cout << " == ";
        binaryOp -> RHS -> accept(this);
    }
    
    void visit(FuncCall* call){
        call->LHS->accept(this);
        std::cout << "(";
        call->Args->accept(this);
        std::cout << ")";
    }
    //argexprlist
    void visit(ArgExprList* args){
        // std::cout << gentabs();
        for(std::vector<Expression*>::iterator it = args->Args.begin(); it != args->Args.end(); it++){
            if(it != args->Args.begin()){ std::cout << ", "; }
            (*it)->accept(this);
        }
    }
    void visit(Identifier* ID){
        std::cout << ID->Name;
    }

    void visit(AssignmentExpression* expr){
        expr->LHS->accept(this);
        std::cout << "=";
        expr->RHS->accept(this);
    }

    
public:
    python_Visitor()
    {
        indentation = 0;
    }
};

#endif

