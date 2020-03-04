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
    Return() : ReturnType(NULL), ReturnExpression(NULL) {}
    Return(Expression* ToReturn) : ReturnType(NULL), ReturnExpression(ToReturn){}
    Type* ReturnType;
    Expression* ReturnExpression;
};

//------------------------------

class While : public Statement{
public:
    While(Expression*  _Control, Statement* _Body) : ControlExpression(_Control), Body(_Body){} 
private:
    Expression* ControlExpression;
    Statement* Body;
};

class DoWhile : public Statement{
public:
    DoWhile(Statement* _Body, Expression* _Control) : Body(_Body), ControlExpression(_Control){}
private:
    Expression* ControlExpression;
    Statement* Body;
};

class For : public Statement{
public:
    For(ExpressionStatement* _init, ExpressionStatement* _control, Statement* _body) 
            : Init(_init), Control(_control), Next(NULL), Body(_body){}
    For(ExpressionStatement* _init, ExpressionStatement* _control, Expression* _next, Statement* _body) 
            : Init(_init), Control(_control), Next(_next), Body(_body){}
private:
    ExpressionStatement* Init, Control;
    Expression* Next;
    Statement* Body;
};

//------------------------------

class SelectionStatement : public Statement{
public:
    SelectionStatement(Expression* _control) : ControlExpression(_control){}
protected:
    Expression* ControlExpression;
};

class If : public SelectionStatement{
public:
    If(Expression* _control, Statement* _iftrue) : SelectionStatement(_control), IfTrue(_iftrue){}
private:
    Statement* IfTrue;
};

class IfElse : public SelectionStatement{
public:
    IfElse(Expression* _control, Statement* _iftrue, Statement* _iffalse) 
            : SelectionStatement(_control), IfTrue(_iftrue), IfFalse(_iffalse){}
private:
    Statement* IfTrue;
    Statement* IfFalse;
};

class Switch : public SelectionStatement{
public:
    Switch(Expression* _control, Statement* _body) : SelectionStatement(_control), Body(_body){}
private:
    Statement* Body;
};

//------------------------------

class ExpressionStatement : public Statement{
public:
    ExpressionStatement(Expression* _expr) : Expr(_expr){}
private:
    Expression* Expr;
};

//------------------------------

class StatementList : public Node{
public:
    StatementList(Statement* TerminalStatement) : Statement(TerminalStatement), RestOfStatements(NULL){}
    StatementList(StatementList* OtherStatements, Statement* ThisStatement) : Statement(ThisStatement), RestOfStatements(RestOfStatements){}
    bool isTerminalStatement() const;
private:
    Statement* Statement;
    StatementList* RestOfStatements;
};

//-------------------------------

class CompoundStatement : public Statement{
public:
    CompoundStatement(DeclarationList* _decls, StatementList* _stmnts) : Decls(_decls), Statements(_stmnts){}
    CompoundStatement(DeclarationList* _decls) : Decls(_decls), Statements(NULL){}
    CompoundStatement(StatementList* _stmnts) : Decls(NULL), Statements(_stmnts){}
private:
    DeclarationList* Decls;
    StatementList* Statements;
};

//-------------------------------

class CaseOrDefault : public Statement{
public:
    CaseOrDefault(Expression* _eval, Statement* _body) : Eval(_eval), Body(_body){}
    CaseOrDefault(Statement* _body) : Eval(NULL), Body(_body){}

    bool isDefault() const;
private:
    Expression* Eval;
    Statement* Body;
};

#endif