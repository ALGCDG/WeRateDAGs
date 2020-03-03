#ifndef AST_STATS
#define AST_STATS

#include "ast_expressions.hpp"
#include "ast_declarations.hpp"
#include "ast_node.hpp"
#include "ast_types.hpp"

class Statement : public Node{

};

class EmptyStatement : public Statement{};

//----------------------------

class Continue : public Statement{};

class Break : public Statement{};

class Return : public Statement{
public:
    Return();
    Return(Expression* ToReturn);
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
public:
    DoWhile(Statement* Body, Expression* Control);
private:
    Expression* ControlExpression;
    Statement* Body;
};

class For : public Statement{
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
public:
    StatementList(Statement* TerminalStatement);
    StatementList(StatementList* OtherStatements, Statement* ThisStatement);
private:
    Statement* Statement;
    StatementList* RestOfStatements;
};

//-------------------------------

class CompoundStatement : public Statement{
public:
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