#ifndef ALLNODES_HPP
#define ALLNODES_HPP

#include <string>
#include <vector>
#include <iostream>
// #include "ast_basenode.hpp"

// //FORWARD DECLARE VISITOR
// class Visitor;

// #include "ast_context.hpp"
//CONTEXT DOES NOT NEED TO KNOW THESE NODES, HANDLED BY VISITOR
//NO FORWARD DECLARATION NEEDED
namespace ContextData{
    class Record;
}
class Visitor;

class Node;
class Expression;
class IdentifierNode;
class Constant;
class constant_int;
class StringLiteral;
class PostfixExpr;
class ArgExprList;
class ArraySubscript;
class FuncCall;
class MemberAccess;
class DerefMemberAccess;
class PostInc;
class PostDec;
class PrefixExpr;
class UnaryAddressOperator;
class UnaryDerefOperator;
class UnaryPlusOperator;
class UnaryNegOperator;
class UnaryBitwiseNotOperator;
class UnaryLogicalNotOperator;
class PreInc;
class PreDec;
class SizeofExpr;
class SizeofType;
class CastExpr;
class BinaryOpExpression;
class direct_declarator;

class Multiply;
class Divide;
class Modulo;
class Add;
class Sub;
class ShiftLeft;
class ShiftRight;
class LogicalBinaryExpression;
class LessThan;
class GreaterThan;
class LessThanOrEqual;
class GreaterThanOrEqual;
class EqualTo;
class NotEqualTo;
class LogicalAND;
class LogicalOR;
class BitwiseBinaryExpression;
class BitwiseAND;
class BitwiseOR;
class BitwiseXOR;
class TernaryOpExpression;
class GenericAssignExpr;
class AssignmentExpression;
class MulAssignment;
class DivAssignment;
class ModAssignment;
class AddAssignment;
class SubAssignment;
class ShiftLeftAssignment;
class ShiftRightAssignment;
class BitwiseANDAssignment;
class BitwiseXORAssignment;
class BitwiseORAssignment;
class ConstantExpression;
class CommaSepExpression;
class Statement;
class EmptyStatement;
class Continue;
class Break;
class Return;
class While;
class DoWhile;
class For;
class SelectionStatement;
class If;
class IfElse;
class Switch;
class ExpressionStatement;
class StatementList;
class CompoundStatement;
class CaseOrDefault;
class DeclarationList;
class declaration;
class declaration_specifiers;
class init_declarator_list;
class init_declarator;
class type_specifier;
class specifier_list;
class pointer;
class base_declarator;
class abstract_declarator;
class declarator;
class base_direct_declarator;
class unspecified_array_length;
class empty_parameter_list_list;
class direct_abstract_declarator;
class direct_declarator;
class direct_declarator_direct_declarator;
class parameter_list;
class parameter_declaration;
class type_name;
class initializer;
class initializer_list;
class GenericExternalDeclaration;
class TranslationUnit;
class FunctionDefinition;
class ExternalDeclaration;

class Visitor
{
public:
    //they don't all want to be pure virtual
    //only stuff that must be implemented in all visitors should be

    //potential to combine some of the visits into the same overload?
    //Expressions
    virtual void visit(Node *) {} //If nothing defined for this type of node
    virtual void visit(Constant *) {}
    virtual void visit(constant_int *) {}
    virtual void visit(ArraySubscript *) {}
    virtual void visit(FuncCall *) {}
    virtual void visit(MemberAccess *) {}
    virtual void visit(DerefMemberAccess *) {}
    virtual void visit(PostInc *) {}
    virtual void visit(PostDec *) {}
    virtual void visit(ArgExprList *) {}
    virtual void visit(UnaryAddressOperator *) {}
    virtual void visit(UnaryDerefOperator *) {}
    virtual void visit(UnaryPlusOperator *) {}
    virtual void visit(UnaryNegOperator *) {}
    virtual void visit(UnaryBitwiseNotOperator *) {}
    virtual void visit(UnaryLogicalNotOperator *) {}
    virtual void visit(PreInc *) {}
    virtual void visit(PreDec *) {}
    virtual void visit(SizeofExpr *) {}
    virtual void visit(SizeofType *) {}
    virtual void visit(CastExpr *) {}
    virtual void visit(Multiply *) {}
    virtual void visit(Divide *) {}
    virtual void visit(Modulo *) {}
    virtual void visit(Add *) {}
    virtual void visit(Sub *) {}
    virtual void visit(ShiftLeft *) {}
    virtual void visit(ShiftRight *) {}
    virtual void visit(LessThan *) {}
    virtual void visit(GreaterThan *) {}
    virtual void visit(LessThanOrEqual *) {}
    virtual void visit(GreaterThanOrEqual *) {}
    virtual void visit(EqualTo *) {}
    virtual void visit(NotEqualTo *) {}
    virtual void visit(LogicalAND *) {}
    virtual void visit(LogicalOR *) {}
    virtual void visit(BitwiseAND *) {}
    virtual void visit(BitwiseOR *) {}
    virtual void visit(BitwiseXOR *) {}
    virtual void visit(TernaryOpExpression *) {}
    virtual void visit(AssignmentExpression *) {}
    virtual void visit(MulAssignment *) {}
    virtual void visit(DivAssignment *) {}
    virtual void visit(ModAssignment *) {}
    virtual void visit(AddAssignment *) {}
    virtual void visit(SubAssignment *) {}
    virtual void visit(ShiftLeftAssignment *) {}
    virtual void visit(ShiftRightAssignment *) {}
    virtual void visit(BitwiseANDAssignment *) {}
    virtual void visit(BitwiseXORAssignment *) {}
    virtual void visit(BitwiseORAssignment *) {}
    virtual void visit(ConstantExpression *) {}
    virtual void visit(CommaSepExpression *) {}

    //Declarations

    virtual void visit(declaration *) {}
    virtual void visit(declaration_specifiers *) {}
    virtual void visit(init_declarator_list *) {}
    virtual void visit(init_declarator *) {}
    virtual void visit(type_specifier *) {}
    virtual void visit(specifier_list *) {}
    virtual void visit(pointer *) {}
    virtual void visit(base_declarator *) {}
    virtual void visit(abstract_declarator *) {}
    virtual void visit(declarator *) {}

    //Statements
    virtual void visit(EmptyStatement *) {}
    virtual void visit(Continue *) {}
    virtual void visit(Break *) {}
    virtual void visit(Return *) {}
    virtual void visit(While *) {}
    virtual void visit(DoWhile *) {}
    virtual void visit(For *) {}
    virtual void visit(If *) {}
    virtual void visit(IfElse *) {}
    virtual void visit(Switch *) {}
    virtual void visit(ExpressionStatement *) {}
    virtual void visit(StatementList *) {}
    virtual void visit(CompoundStatement *) {}
    virtual void visit(CaseOrDefault *) {}

    //External definitions
    virtual void visit(TranslationUnit *) {}
    virtual void visit(FunctionDefinition *) {}
    virtual void visit(ExternalDeclaration *) {}

    //Declarations
};

class Node{
public:
    virtual void accept(Visitor *AVisitor) { AVisitor->visit(this); }
};

/*
EXPRESSIONS
*/

class Expression : public Node{
public:
    //Type* EvalsToType;
    //TODO types!
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//primary expr
class IdentifierNode : public Expression{
public:
    IdentifierNode(std::string* _name) : Name(_name){}
    std::string* Name;
    ContextData::Record* ContextRecord;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


class Constant : public Expression{
public:
    Constant() {}
    // union { 
    //     int int_t; 
    //     char char_t;
    //     double dbl_t;
    //     float flt_t;    
    //     long long_t;
    // };
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class constant_int : public Constant {
    public:
    int value;
    constant_int(int v): value(v) {std::cerr << "creating int: " << v << std::endl;}

public:
    void accept(Visitor *AVisitor) override { AVisitor->visit(this); }
};
class StringLiteral : public Expression
{
public:
    StringLiteral(std::string _str, bool L = false) : wide(L), str(_str){}
    bool wide;
    std::string str;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class TypedefNode : public Node{

public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
//---------------------------------------------------------
class PostfixExpr : public Expression{
public:
    PostfixExpr(Expression* _LHS) : LHS(_LHS){}
    Expression* LHS;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
//---------------------------------------------------------

class ArgExprList : public Node{
public:
    ArgExprList(Expression* Arg){ Args.push_back(Arg);}
    void AppendArgExpression(Expression* ArgExpr){ Args.push_back(ArgExpr); }
    //in the grammar, expression* can be assignment expression
    std::vector<Expression*> Args;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------------------------------------------------
class ArraySubscript : public PostfixExpr{
public:
    ArraySubscript(Expression* _LHS, Expression* _Subscript) : PostfixExpr(_LHS), Subscript(_Subscript){}

    Expression* Subscript;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class FuncCall : public PostfixExpr{
public:
    FuncCall(Expression* _LHS) : PostfixExpr(_LHS) {}
    FuncCall(Expression* _LHS, ArgExprList* RHS) : PostfixExpr(_LHS), Args(RHS){}
    ArgExprList* Args;

public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class MemberAccess : public PostfixExpr{
public:
    MemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}

    IdentifierNode* ID;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class DerefMemberAccess : public PostfixExpr{
public:
    DerefMemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}

    IdentifierNode* ID;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class PostInc : public PostfixExpr{
public:
    PostInc(Expression* _LHS) : PostfixExpr(_LHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class PostDec : public PostfixExpr{
public:
    PostDec(Expression* _LHS) : PostfixExpr(_LHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


//---------------------------------------------------------

class PrefixExpr : public Expression{
public:
    PrefixExpr(Expression* _RHS) : RHS(_RHS){}
    //returns correct unary operator node, described below
    static PrefixExpr* DecodeUnaryOp(std::string* yytext, Expression* _RHS);

    Expression* RHS;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryAddressOperator : public PrefixExpr{
public:
    UnaryAddressOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryDerefOperator : public PrefixExpr{
public:
    UnaryDerefOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryPlusOperator : public PrefixExpr{
public:
    UnaryPlusOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryNegOperator : public PrefixExpr{
public:
    UnaryNegOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryBitwiseNotOperator : public PrefixExpr{
public:
    UnaryBitwiseNotOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class UnaryLogicalNotOperator : public PrefixExpr{
public:
    UnaryLogicalNotOperator(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//The rest of the prefix types:
class PreInc : public PrefixExpr{
public:
    PreInc(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class PreDec : public PrefixExpr{
public:
    PreDec(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class SizeofExpr : public PrefixExpr{
public:
    SizeofExpr(Expression* _RHS) : PrefixExpr(_RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class SizeofType : public Expression{
public:
    SizeofType(type_name* _typ_nam) : typ_nam(_typ_nam){}
    type_name* typ_nam;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class CastExpr : public PrefixExpr{
public:
    CastExpr(type_name* _typ , Expression* _ExprToBeCast) : PrefixExpr(_ExprToBeCast), typ(_typ) {}
    type_name* typ;
//TODO -> Needs type system
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//---------------------------------------------------------

class BinaryOpExpression : public Expression{
public:
    BinaryOpExpression(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    Expression *LHS, *RHS;  
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Multiply : public BinaryOpExpression{
public:
    Multiply(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Divide : public BinaryOpExpression{
public:
    Divide(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Modulo : public BinaryOpExpression{
public:
    Modulo(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Add : public BinaryOpExpression{
public:
    Add(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Sub : public BinaryOpExpression{
public:
    Sub(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ShiftLeft : public BinaryOpExpression{
public:
    ShiftLeft(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ShiftRight : public BinaryOpExpression{
public:
    ShiftRight(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------
class LogicalBinaryExpression : public BinaryOpExpression{
public:
    LogicalBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS)/*, EvalsToType() TODO set to int */ {}
//Always evaluates to int
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class LessThan : public LogicalBinaryExpression{
public:
    LessThan(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class GreaterThan : public LogicalBinaryExpression{
public:
    GreaterThan(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class LessThanOrEqual : public LogicalBinaryExpression{
public:
    LessThanOrEqual(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class GreaterThanOrEqual : public LogicalBinaryExpression{
public:
    GreaterThanOrEqual(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class EqualTo : public LogicalBinaryExpression{
public:
    EqualTo(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class NotEqualTo : public LogicalBinaryExpression{
public:
    NotEqualTo(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class LogicalAND : public LogicalBinaryExpression{
public:
    LogicalAND(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class LogicalOR : public LogicalBinaryExpression{
public:
    LogicalOR(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------
class BitwiseBinaryExpression : public BinaryOpExpression{
//type depends on input
public:
    BitwiseBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseAND : public BitwiseBinaryExpression{
public:
    BitwiseAND(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseOR : public BitwiseBinaryExpression{
public:
    BitwiseOR(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseXOR : public BitwiseBinaryExpression{
public:
    BitwiseXOR(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
//---------------------------------------------------------

class TernaryOpExpression : public Expression{
public:
    TernaryOpExpression(Expression* cond, Expression* _true, Expression* _false) : Condition(cond), IfTrue(_true), IfFalse(_false){}
    Expression* Condition, *IfTrue, *IfFalse;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//---------------------------------------------------------

class GenericAssignExpr : public Expression{
public:
    GenericAssignExpr(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    static GenericAssignExpr* DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS);

//Not to be used, dummy stand in, supplies decoder
//Value and type of assignment expression is that of the right side argument
    //possibly move this out of this class
    Expression* LHS, *RHS;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class AssignmentExpression : public GenericAssignExpr{
public:
    AssignmentExpression(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class MulAssignment : public GenericAssignExpr{
public:
    MulAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class DivAssignment : public GenericAssignExpr{
public:
    DivAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ModAssignment : public GenericAssignExpr{
public:
    ModAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class AddAssignment : public GenericAssignExpr{
public:
    AddAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class SubAssignment : public GenericAssignExpr{
public:
    SubAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ShiftLeftAssignment : public GenericAssignExpr{
public:
    ShiftLeftAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ShiftRightAssignment : public GenericAssignExpr{
public:
    ShiftRightAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseANDAssignment : public GenericAssignExpr{
public:
    BitwiseANDAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseXORAssignment : public GenericAssignExpr{
public:
    BitwiseXORAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class BitwiseORAssignment : public GenericAssignExpr{
public:
    BitwiseORAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//---------------------------------------------------------

class ConstantExpression : public Expression{
public:
    ConstantExpression(){}
    ConstantExpression(Expression* Expr): ConstantSubtree(Expr){}

    Expression* ConstantSubtree;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//TODO Comma seperated expression? Grammar from annex:
// expression ::= assignment-expression | expression "," assignment-expression

class CommaSepExpression : public Expression{
public:
    CommaSepExpression(Expression* _LHS, Expression* _RHS) : RHS(_RHS), LHS(_LHS){}

    Expression* RHS, *LHS;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//---------------------------------------------------------


/*
Statements
*/

class Statement : public Node{

public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


//----------------------------

class Continue : public Statement{};

class Break : public Statement{};

class Return : public Statement{
public:
    Return() : /*ReturnType(NULL),*/ ReturnExpression(NULL) {}
    Return(Expression* ToReturn) : /*ReturnType(NULL),*/ ReturnExpression(ToReturn){}
    //Type* ReturnType;
    Expression* ReturnExpression;
    //TODO types!
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------------------------

class While : public Statement{
public:
    While(Expression*  _Control, Statement* _Body) : ControlExpression(_Control), Body(_Body){} 
    Expression* ControlExpression;
    Statement* Body;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class DoWhile : public Statement{
public:
    DoWhile(Statement* _Body, Expression* _Control) : Body(_Body), ControlExpression(_Control){}

    Statement* Body;
    Expression* ControlExpression;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class For : public Statement{
public:
    For(ExpressionStatement* _init, ExpressionStatement* _control, Statement* _body) 
            : Init(_init), Control(_control), Next(NULL), Body(_body){}
    For(ExpressionStatement* _init, ExpressionStatement* _control, Expression* _next, Statement* _body) 
            : Init(_init), Control(_control), Next(_next), Body(_body){}

    ExpressionStatement* Init, *Control;
    Expression* Next;
    Statement* Body;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------------------------

class SelectionStatement : public Statement{
public:
    SelectionStatement(Expression* _control) : ControlExpression(_control){}

    Expression* ControlExpression;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class If : public SelectionStatement{
public:
    If(Expression* _control, Statement* _iftrue) : SelectionStatement(_control), IfTrue(_iftrue){}

    Statement* IfTrue;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class IfElse : public SelectionStatement{
public:
    IfElse(Expression* _control, Statement* _iftrue, Statement* _iffalse) 
            : SelectionStatement(_control), IfTrue(_iftrue), IfFalse(_iffalse){}

    Statement* IfTrue;
    Statement* IfFalse;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class Switch : public SelectionStatement{
public:
    Switch(Expression* _control, Statement* _body) : SelectionStatement(_control), Body(_body){}

    Statement* Body;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//------------------------------

class ExpressionStatement : public Statement{
public:
    ExpressionStatement(Expression* _expr) : Expr(_expr){}
    Expression* Expr;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class EmptyStatement : public ExpressionStatement{
public:
    EmptyStatement(): ExpressionStatement(NULL){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
//------------------------------

class StatementList : public Node{
public:
    StatementList(Statement* TerminalStatement) : statement(TerminalStatement), RestOfStatements(NULL){}
    StatementList(StatementList* OtherStatements, Statement* ThisStatement) : statement(ThisStatement), RestOfStatements(RestOfStatements){}
    bool isTerminalStatement() const;

    Statement* statement;
    StatementList* RestOfStatements;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//-------------------------------

class CompoundStatement : public Statement{
public:
    CompoundStatement(DeclarationList* _decls, StatementList* _stmnts) : Decls(_decls), Statements(_stmnts){}
    CompoundStatement(DeclarationList* _decls) : Decls(_decls), Statements(NULL){}
    CompoundStatement(StatementList* _stmnts) : Decls(NULL), Statements(_stmnts){}
    CompoundStatement() : Decls(NULL), Statements(NULL) {}
    DeclarationList* Decls;
    StatementList* Statements;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//-------------------------------

class CaseOrDefault : public Statement{
public:
    CaseOrDefault(Expression* _eval, Statement* _body) : Eval(_eval), Body(_body){}
    CaseOrDefault(Statement* _body) : Eval(NULL), Body(_body){}
    Expression* Eval;
    Statement* Body;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class DeclarationList : public Node{
public:
    DeclarationList(declaration* _this_decl): this_decl(_this_decl), left_list(NULL){}
    DeclarationList(DeclarationList* list, declaration* _this_decl): this_decl(_this_decl), left_list(list){}
    declaration* this_decl;
    DeclarationList* left_list;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

//-------------------------------------------

/*
Declarations and types
*/

class declaration : public Node
{
public:
    declaration_specifiers* specifier; // specifies type of declaration
    init_declarator_list* list; // list of variables being declared as this type, may be null
    declaration(declaration_specifiers * _specifier ,init_declarator_list * _list = NULL) : specifier(_specifier), list(_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


class declaration_specifiers : public Node
{
public:
    // storage information about decleration
    // type, storage ( ie int) (ie long)
    // again cascades
    type_specifier * type_spec;
    declaration_specifiers * specifier; // may be null if there is none
    TypedefNode * storage_class_specifier;
    declaration_specifiers(type_specifier * _type_spec, declaration_specifiers * _specifier = NULL, TypedefNode* stor_spec=NULL) : type_spec(_type_spec), specifier(_specifier), storage_class_specifier(stor_spec)  {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class init_declarator_list : public Node
{
public:
    // multiple declarations in one line
    // cascades
    init_declarator * init_dec;
    init_declarator_list * init_dec_list;// may point to null if there are no more
    init_declarator_list(init_declarator* _init_dec, init_declarator_list * _init_dec_list = NULL) : init_dec(_init_dec), init_dec_list(_init_dec_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class init_declarator : public Node
{
public:
    // a single atomic declaration
    declarator * dec; // points to declaration, ie a name or identifier
    initializer * init; // points to expression being assigned to identifier, may be NULL if none is
    init_declarator(declarator * _dec, initializer * _init = NULL) : dec(_dec), init(_init) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

/*
enum C_types
{
    none,
    t_void,
    t_int,
    t_char,
    t_short,
    t_long,
    t_float,
    t_double,
    t_signed,
    t_unsigned
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
*/

class type_specifier : public Node
{
public:
    /*
    enum C_types basic_type;
    */
    std::string* type;
    type_specifier( std::string* Keyword) : type(Keyword) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class specifier_list : public Node
{
public:
    type_specifier * type_spec;
    specifier_list * spec_list; // cascades, may be null
    specifier_list(type_specifier * _type_spec, specifier_list * _spec_list = NULL) : type_spec(_type_spec), spec_list(_spec_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


class pointer : public Node
{
public:
    // pointers are constructed and counted
    pointer* p;
    // static int count(const int &i)
    // {
    //     // we count the number of pointers and delete in one thing
    //     if (p != NULL)
    //     {
    //         int no_children = p->count(i);
    //         delete p;
    //         return no_children + 1;
    //     }
    // }
    pointer(pointer * _p = NULL) : p(_p) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

/*
Declarators
*/

class base_declarator : public Node
{
public:
    // int point_cnt;
    pointer* p;
    base_declarator(pointer* point = NULL) : p(point){}
    // {
    //     // counting layer of pointers
    //     if ( point != NULL )
    //     {
    //         point_cnt = point->count(0);
    //         delete point;
    //     }
    // }
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


class abstract_declarator : public base_declarator
{
public:
    // unlinked operand
    /* pointer* p */
    direct_abstract_declarator * dabs_dec;
    abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, pointer * point = NULL) : base_declarator(point), dabs_dec(_dabs_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};



class declarator : public base_declarator
{
public:
    // asserts link between symbol and operand
    /* pointer* p*/
    direct_declarator * dir_dec;
    declarator(direct_declarator * _dir_dec, pointer * point = NULL) : base_declarator(point), dir_dec(_dir_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

/*
Direct Declartions
*/

class base_direct_declarator : public Node
{
public:
    // direct_abstract_declarator and direct_declarator share a lot in common
    // it is the better part of wisdom to make them children of a common node -> archie being pretentious
    ConstantExpression * const_expr; // nonnull if it is an array, zero if empty
    parameter_list * para_list; // nonnull if it is a functio
    base_direct_declarator(ConstantExpression * _const_expr = NULL, parameter_list * _para_list = NULL) : const_expr (_const_expr), para_list(_para_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

// a class used to signify that an array declaration does not specify array length
class unspecified_array_length : public ConstantExpression {
public:
    
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class direct_abstract_declarator : public base_direct_declarator
{
public:
    direct_abstract_declarator * dabs_dec; // may be null
    abstract_declarator * abs_dec;
    direct_abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, abstract_declarator * _abs_dec = NULL, ConstantExpression * _const_expr = NULL, parameter_list * _para_list = NULL) 
        : base_direct_declarator(_const_expr, _para_list), dabs_dec(_dabs_dec), abs_dec(_abs_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class direct_declarator : public base_direct_declarator
{
public:
    IdentifierNode * ID;
    direct_declarator * dir_dec; // may be null
    declarator * dec;                                                                                                                                                                     //TODO doesnt match
    direct_declarator(IdentifierNode * _ID = NULL, direct_declarator * _dir_dec = NULL, ConstantExpression * _const_expr = NULL, parameter_list * _para_list = NULL, declarator * _dec = NULL) 
        : base_direct_declarator(_const_expr, _para_list), ID(_ID), dir_dec(_dir_dec), dec(_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

/*
Parameters
*/

class parameter_list : public Node
{
public:
    parameter_list * para_list;// cascades, may be null
    parameter_declaration * para_dec;
    abstract_declarator * abs_dec;
    parameter_list(parameter_declaration * _para_dec, parameter_list * _para_list = NULL, abstract_declarator * _abs_dec = NULL) : para_list(_para_list), para_dec(_para_dec), abs_dec(_abs_dec) {}
    parameter_list():para_list(NULL), para_dec(NULL), abs_dec(NULL){}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};
// a class used to signify that a parameter list is empty
class empty_parameter_list : public parameter_list {
public:
    empty_parameter_list() {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class parameter_declaration : public Node
{
public:
    declaration_specifiers * dec_spec;
    declarator * dec;
    abstract_declarator * abs_dec;
    parameter_declaration(declaration_specifiers * _dec_spec, declarator * _dec = NULL, abstract_declarator * _abs_dec = NULL) : dec_spec(_dec_spec), dec(_dec), abs_dec(_abs_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class type_name : public Node
{
public:
    specifier_list * spec_list;
    abstract_declarator * abs_dec;
    type_name(specifier_list * _spec_list, abstract_declarator * _abs_dec = NULL) : spec_list(_spec_list), abs_dec(_abs_dec) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


/*
Initializers
*/

class initializer : public Node
{
public:
    Expression* ass_expr;
    // OR
    initializer_list * init_list;
    initializer(Expression* _ass_expr, initializer_list * _init_list = NULL) : ass_expr(_ass_expr), init_list(_init_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class initializer_list : public Node
{
public:
    initializer * init;
    initializer_list * init_list; // cascades may be null
    initializer_list(initializer * _init, initializer_list * _init_list = NULL) : init(_init), init_list(_init_list) {}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class GenericExternalDeclaration : public Node{
public:
    virtual void accept(Visitor *AVisitor) = 0;
};

class TranslationUnit : public Node
{
public:
    std::vector<GenericExternalDeclaration*> decls;
    TranslationUnit(GenericExternalDeclaration* _externaldef){ decls.push_back(_externaldef); }
    void AppendDeclaration(GenericExternalDeclaration* _decl){ decls.push_back(_decl);}
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};


class FunctionDefinition : public GenericExternalDeclaration{
public:
    FunctionDefinition(declaration_specifiers* _specs, declarator* _decl, CompoundStatement* _stmt) : specs(_specs), decl(_decl), Body(_stmt){}
    FunctionDefinition(declarator* _decl, CompoundStatement* _stmt) : FunctionDefinition(NULL, _decl, _stmt){}
    declaration_specifiers* specs;
    declarator* decl;
    //DeclarationList* decl_list; only needed for k&r
    CompoundStatement* Body;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

class ExternalDeclaration : public GenericExternalDeclaration{
public:
    ExternalDeclaration(declaration* _decl) : decl(_decl){}
    declaration* decl;
public: void accept(Visitor * AVisitor) override { AVisitor->visit(this); }};

#endif
