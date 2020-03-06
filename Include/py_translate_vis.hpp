#ifndef PYTRVISIT_HPP
#define PYTRVISIT_HPP

#include <string>
#include <unordered_set>

#include "visitors.hpp"
#include "ast_allnodes.hpp"

//? WHY ARE THE DEFINITIONS IN THE HPP?

class python_Visitor: public Visitor
{
    int indentation;
    // an unordered set used to store the global names
    std::unordered_set<std::string> global; 
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
        w->ControlExpression->accept(this);
        std::cout << " :" << std::endl;
        indentation++;
        w->Body->accept(this);
        indentation--;
    }

    void visit(If* i)
    {
        std::cout << gentabs() << "if ";
        i->ControlExpression->accept(this);
        std::cout << " :" << std::endl;
        indentation++;
        i->IfTrue->accept(this);
        indentation--;
    }
    void visit(IfElse* ie)
    {
        std::cout << gentabs() << "if ";
        ie->ControlExpression->accept(this);
        std::cout << " :" << std::endl;
        indentation++;
        ie->IfTrue->accept(this);
        indentation--;
        std::cout << gentabs() << "else: " << std::endl;
        indentation++;
        ie->IfFalse->accept(this);
        indentation--;   
    }
    void visit(Return* r)
    {
        std::cout << gentabs() << "return ";
        if (r->ReturnType != NULL)
        {
            r->ReturnExpression->accept(this);
        }
        std::cout << std::endl;
    }
    void visit(CompoundStatement* cs)
    {
        // handling sequences
        if (cs->Decls != NULL)
        {
            cs->Decls->accept(this);
        }
        if (cs->Statements != NULL)
        {
            cs->Statements->accept(this);
        }   
    }
    void visit(StatementList* sl)
    {
        sl->statement->visit(this);
        if (cs->RestOfStatements != NULL)
        {
            cs->RestOfStatements->accept(this);
        }
    }
    /*
    Declarations
    */
    void visit(declaration* dec)
    {
        std::cout << gentab();
        // we can assume it is a function or an int
        if (dec->list != NULL)
        {
            dec->list->accept(this);
        }
        std::cout << std::endl;
    }
    void visit(init_declarator_list * il)
    {
        il->init_dec->accept(this);
        if(il->init_dec_list != NULL)
        {
            il->init_dec_list->accept(this);
        }
    }
    void visit(init_declarator * id)
    {
        // getting variable name
        auto name = id->dec->dir_dec->ID->Name;
        if (global.find(name) !=  global.end())
        {
            // variable is referenced in global scope
            std::cout << "global "
        }
        id->dec->dir_dec->ID->accept(this);
        if (indentation == 0)
        {
            // if we are in the global scope, we add it to the set
            global.insert(id->dec->dir_dec->ID->Name);
        }
        std::cout << "=";
        if (id->init == NULL)
        {
            // uninitialised values default to zero
            std::cout << "0";
        }
        else if (id->init->ass_expr != NULL)
        {
            // assigning int value
            id->init->ass_expr->accept(this);
        }
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
    void visit(IdentifierNode* ID){
        std::cout << ID->Name;
    }

    void visit(AssignmentExpression* expr){
        expr->LHS->accept(this);
        std::cout << "=";
        expr->RHS->accept(this);
    }
	
	/*
		External Definitions
	*/
    void visit(TranslationUnit*)
	{}
    void visit(FunctionDefinition*)
	{}
    void visit(ExternalDeclaration*)
	{}

    
public:
    python_Visitor()
    {
        indentation = 0;
    }
};

#endif

