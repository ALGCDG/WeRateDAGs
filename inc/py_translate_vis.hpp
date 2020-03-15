#ifndef PYTRVISIT_HPP
#define PYTRVISIT_HPP

#include <string>
#include <unordered_set>
#include <iostream>
#include <typeinfo>
// #include "visitors.hpp"
#include "ast_allnodes.hpp"

//? WHY ARE THE DEFINITIONS IN THE HPP?

class python_Visitor: public Visitor
{
public:
    python_Visitor():indentation(0){}
    int indentation;
    // an unordered set used to store the global names
    std::unordered_set<std::string> global; 
    std::string gentabs()
    {
        std::cerr << "generating tabs" << std::endl;
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
        if (r->ReturnExpression != NULL)
        {
            r->ReturnExpression->accept(this);
        }
        // std::cout << std::endl;
    }
    void visit(CompoundStatement* cs)
    {
        std::cerr << "compound satement" << std::endl;
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
        std::cerr << "statement list: " << sl->RestOfStatements << std::endl;
        if (sl->RestOfStatements != NULL)
        {
            std::cerr << "going to other statement" << std::endl;
            sl->RestOfStatements->accept(this);
        }
        sl->statement->accept(this);
        std::cout << std::endl;
    }
    void visit(DeclarationList *dl)
    {
        std::cerr << "declaration list: " << dl->left_list << std::endl;
        if (dl->left_list!=NULL)
        {
            dl->left_list->accept(this);
        }
        dl->this_decl->accept(this);

    }
    void visit(ExpressionStatement * es)
    {
        std::cout << gentabs();
        es->Expr->accept(this);
    }
    /*
    Declarations
    */
    void visit(declaration* dec)
    {
        std::cerr << "declaration" << std::endl;
        std::cout << gentabs();
        // we can assume it is a function or an int
        if (dec->list != NULL)
        {
            dec->list->accept(this);
        }
        std::cout << std::endl;
    }
    void visit(init_declarator_list * il)
    {
        std::cerr << "init declarator list" << std::endl;
        il->init_dec->accept(this);
        if(il->init_dec_list != NULL)
        {
            il->init_dec_list->accept(this);
        }
    }
    void visit(init_declarator * id)
    {
        std::cerr << "init declarator";
        // getting variable name
        auto name = (id->dec->dir_dec->ID->Name);
        std::cerr << " name is: " << name << std::endl;
        if (global.find(name) !=  global.end())
        {
            // variable is referenced in global scope
            std::cout << "global ";
        }
        std::cerr << "checked global" << std::endl;
        std::cout << name;
        // id->dec->dir_dec->ID->accept(this);
        if (indentation == 0)
        {
            // if we are in the global scope, we add it to the set
            global.insert((id->dec->dir_dec->ID->Name));
            std::cerr << "added to global" << std::endl;
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
            std::cerr << "going to assignment expression: " << typeid(*(id->init->ass_expr)).name() << std::endl;
            id->init->ass_expr->accept(this);
            std::cerr << "done" << std::endl;
        }
    }
    void visit(parameter_list * pl)
    {
        std::cerr << "parameter list" << std::endl;
        if (pl->para_list != NULL)
        {
            pl->para_list->accept(this);
            std::cout << ", ";
        }
        pl->para_dec->accept(this);
    }
    void visit(parameter_declaration * pd)
    {
        std::cerr << "parameter declaration" << std::endl;
        std::cerr<< "parameter declaration" << std::endl;
        if (pd->dec != NULL)
        {
            std::cout << (pd->dec->dir_dec->ID->Name);
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
        std::cerr << "function call" << std::endl;
        call->LHS->accept(this);
        std::cout << "(";
        if (call->Args!=NULL)
        {
            call->Args->accept(this);
        }
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
    void visit(AssignmentExpression* expr){
        std::cerr << "assignment expression: " << typeid(*(expr->LHS)).name() << std::endl;
        expr->LHS->accept(this);
        std::cout << "=";
        expr->RHS->accept(this);
    }
    void visit(Expression *expr)
    {
        std::cerr << "expression" << std::endl;
    }
    void visit(constant_int *ci)
    {
        std::cerr << "constant int value" << std::endl;
        std::cout << ci->value;
    }
    void visit(IdentifierNode * in)
    {
        std::cerr << "identifier" << std::endl;
        std::cout << (in->Name);
    }


    /*
		External Definitions
	*/

    //TODO 
    void visit(TranslationUnit* unit)
	{
        std::cerr << "top of tree" << std::endl;
        for (std::vector<GenericExternalDeclaration*>::iterator it = unit->decls.begin(); it < unit->decls.end(); it++)
        {
            (*it)->accept(this);
        }
        // inserting boilerplate main thread handling stuff
        std::cout << "if __name__ == \"__main__\":" << std::endl;
        std::cout << "\timport sys" << std::endl;
        std::cout << "\tret=main()" << std::endl;
        std::cout << "\tsys.exit(ret)" << std::endl;
    }
    void visit(FunctionDefinition* fd)
	{
        // // getting function name
        std::cerr << "function definition" << std::endl;
        // std::cout << *(fd->decl->dir_dec->ID->Name);
        // std::cout << '(';
        // // fd->decl->dir_dec->para_list->accept(this);
        // std::cerr << *(fd->decl->dir_dec) << std::endl;
        std::cout << "def ";
        fd->decl->dir_dec->accept(this);
        std::cerr << (fd->decl->dir_dec->para_list == NULL) << std::endl;
        // std::cout << "):" << std::endl;
        indentation++;
        // doing global
        for (std::unordered_set<std::string>::iterator it = global.begin(); it != global.end(); it++)
        {
            std::cout << gentabs() << "global " << *it << std::endl; 
        }
        fd->Body->accept(this);
        indentation--;
    }
    void visit(ExternalDeclaration * ed)
	{
        std::cerr << "ex dec" << std::endl;
        ed->decl->accept(this);
    
    }
    // void visit(Node * n)
    // {
    //     std::cerr << "visiting node, not supported: " << typeid(*n).name() << std::endl;
    // }
    void visit(direct_declarator * dd)
    {
        std::cerr << "direct declarator" << std::endl;
        if (dd->ID != NULL)
        {
            std::cout << (dd->ID->Name);
        }
        else{
            if (dd->dir_dec != NULL)
            {
                dd->dir_dec->accept(this);
                std::cout << '(';
                if (dd->para_list != NULL)
                {
                    std::cerr << "going to visit parameters: " << dd->para_list << std::endl;
                    dd->para_list->accept(this);
                }
                std::cout << "):" << std::endl;
            }
        }
    }
    void visit(empty_parameter_list * epl)
    {

    }
};

#endif