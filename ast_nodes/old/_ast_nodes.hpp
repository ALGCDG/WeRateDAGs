#ifndef AST_NODE
#define AST_NODE

#include "_ast_op_types.hpp"
#include <vector>
#include <string>

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
    //std::vector<CaseOrDefault*> Cases; 
    ExpressionList* Body;
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


class Expression : public Statement{
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

class FuncCall : public Expression{
public:
private:
    Expression* Designator;
    std::vector<Expression*> Args;
};

class IdentifierNode: public Expression{
private:
    std::string name;
};

class MemberExpression : public Expression{
private:
    Expression* ObjectDesignator;
    Expression* AttributeDesignator;
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


class Declaration{
//initial class layout done, perhaps change the structure
};

/*Possibility that there are other top level declaration classes so leave NamedDeclaration as a child for now*/
class NamedDeclaration : public Declaration{
private:
    IdentifierNode* ID;
    //Specifiers
};

class TypeDeclaration : public NamedDeclaration{
// needs to hold a type?
// possibly refactor into better structure
};

class TypedefNameDeclaration : public TypeDeclaration{
// declares a typedef
// need type and name i think
};

class TagDeclaration : public TypeDeclaration{
//not a type declaration, structs and enums must be prefixed by struct/enum TAG when used as a type specifier
//this is called an "elaborated type specifier"
};

class EnumDeclaration : public TagDeclaration{
//holds specific info for enums
};

class StructDeclaration : public TagDeclaration{
//declaration of struct tag
//holds specific info for structs
};

class ValueDeclaration : public NamedDeclaration {
//super class of the below, holds name and type
};

class EnumConstantDeclaration : public ValueDeclaration {
//must be type int in C, holds name and value
};

class FunctionDeclaration : public ValueDeclaration{
//holds declaration /and possibly definition
};

class StructFieldDeclaration : public ValueDeclaration{
//holds information connected to a particular struct
};

class VariableDeclaration : public ValueDeclaration{
//general variable declaration, holds name and type
};

class ParamDeclaration : public VariableDeclaration{
//held inside function definition, relevent only within function
};

/**
 * Declaration
 *  Empty Decl
 *  Named Decl
 *      Type Decl
 *          Tag Decl //struct, enum tags
 *              enum decl
 *              record decl
 *          typedef name decl 
 *      Value Decl //variable, function or enum constant
 *          enum constant decl
 *          function decl
 *          field decl //member of struct
 *          variable declaration
 *              param declaration
 */

#endif