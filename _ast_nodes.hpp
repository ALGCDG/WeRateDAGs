#ifndef AST_NODE
#define AST_NODE

#include "_ast_op_types.hpp"
#include <vector>

/** TODO:
 * Constructors
 * Getters / useful functions
 */


class ASTVisitor{
public:
    //TODO add visits for each node type
    virtual void visit(Node& ) = 0;
};


class Node{
public:
    void accept(ASTVisitor &);

};

class Statement : public Node{
public:
    //virtual void accept(ASTVisitor &) = 0;
};

class StatementList : public Node{
public:
    // void accept(ASTVisitor &) override;
private:
    std::vector<Statement*> Statements;
};

class If : public Statement{
public:
    // void accept(ASTVisitor &) override;
private:
    Expression* Condition;
    StatementList* IfTrue;
};

class IfThenElse : public Statement{
public:
    // void accept(ASTVisitor &) override;
private:
    Expression* Condition;
    StatementList* IfTrue;
    StatementList* IFFalse;
};

class Expression : public Node{
public:
    // void accept(ASTVisitor &) override;
private:
};

class For : public Statement{
public:
    // void accept(ASTVisitor &) override;
private:
    Expression* Init;
    Expression* Condition;
    Expression* Next;
    StatementList* Body;
};

class DoWhile : public Statement{
public:
    // void accept(ASTVisitor)
private:
    StatementList* Body;
    Expression* Condition;
};

class While : public Statement{
public:
private:
    StatementList* Body;
    Expression* Condition;
};

class Switch : public Statement{
private:
    Expression* Evaluate;
    std::vector<CaseOrDefault*> Cases; 
};

class CaseOrDefault : public Statement{
private:
    //!Initialise to null
    //Null -> default
    Expression* CaseExpr;

    StatementList* Body;
};

class JumpStatement : public Statement{

};

class Continue : public JumpStatement{

};

class Break : public JumpStatement{

};

class Return : public JumpStatement{

};

class ID : public Node{
public:
private:
    std::string Name;
};

class Expression : public Node{
public:
private:
    Type* EvalsToType;
};

class ExpressionList : public Node{
private:
    std::vector<Expression*> Expressions;
};

class Constant : public Expression{

};

class BinaryOperator : public Expression{
public:
    typedef WRDAGS::BinaryOpType OPtype;
private:
    OPtype OPCode;
    Expression* Left;
    Expression* Right;
};

/** Thinking about struct access:
 * Struct access is an expression
 * Has labelled ret type
 * Possible ret type is function
 * function has compound type
 * ie (a b) -> c
 * Implement compound type?
 * Restructure?
 */



class Type{
public:
    void accept(ASTVisitor&);
    virtual int getByteSize();
private:
};

class Integral : public Type{
/** Superset of:
 * char
 * ints
 * enumerated types
 * 
 */
};






#endif