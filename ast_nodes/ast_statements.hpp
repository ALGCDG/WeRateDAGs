#ifndef AST_STATS
#define AST_STATS

#include "ast_expressions.hpp"
#include "ast_declarations.hpp"
#include "ast_node.hpp"
#include "ast_types.hpp"

class Statement : public Node{

};

//----------------------------

class Continue : public Statement{};

class Break : public Statement{};

class Return : public Statement{
private:
    Type* ReturnType;
    Expression* ReturnExpression;
};

//------------------------------

class While : public Statement{
private:
    Expression* ControlExpression;
    Statement* Body;
};

class DoWhile : public Statement{
private:
    Expression* ControlExpression;
    Statement* Body;
};

class ForWhile : public Statement{
private:
    ExpressionStatement* Init, Control;
    Expression* Next;
};

//------------------------------

class SelectionStatement : public Statement{
protected:
    Expression* ControlExpression;
};

class If : public SelectionStatement{
private:
    Statement* IfTrue;
};

class IfElse : public SelectionStatement{
private:
    Statement* IfTrue, IfFalse;
};

class Switch : public SelectionStatement{
private:
    Statement* Body;
};

//------------------------------

class ExpressionStatement : public Statement{
private:
    Expression* Expr;
};

//------------------------------

class StatementList : public Node{
    void AppendStatement(Statement* Statement);
private:
    std::vector<Statement*> Statements;
};

//-------------------------------

class CompoundStatement : public Statement{
private:
    DeclarationList* Decls;
    StatementList* Statements;
};

//-------------------------------

class CaseOrDefault : public Statement{
private:
    Expression* Eval;
    Statement* Body;
};

#endif