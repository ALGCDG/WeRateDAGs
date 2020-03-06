#ifndef ALLNODES_HPP
#define ALLNODES_HPP

#include <string>
#include <vector>
#include "ast_basenode.hpp"

// #include "visitors.hpp"
// //FORWARD DECLARE VISITOR
// class Visitor;

#include "ast_context.hpp"
//CONTEXT DOES NOT NEED TO KNOW THESE NODES, HANDLED BY VISITOR
//NO FORWARD DECLARATION NEEDED


// class Node{
// public:
//     void accept(Visitor* AVisitor);
// private:
    
// };

/*
EXPRESSIONS
*/

class Expression : public Node{
public:
    //Type* EvalsToType;
    //TODO types!
};

//primary expr
class IdentifierNode : public Expression{
public:
    IdentifierNode(std::string _name) : Name(_name){}
    std::string Name;
    Context::Record* ContextRecord;
};

class Constant : public Expression{
public:
    Constant();//TODO
    union { 
        int int_t; 
        char char_t;
        double dbl_t;
        float flt_t;    
        long long_t;
    };
};


class StringLiteral : public Expression{
public:
    StringLiteral(std::string _str, bool L = false) : wide(L), str(_str){}
    bool wide;
    std::string str;
};
//---------------------------------------------------------
class PostfixExpr : public Expression{
public:
    PostfixExpr(Expression* _LHS) : LHS(_LHS){}
    Expression* LHS;
};

class ArraySubscript : public PostfixExpr{
public:
    ArraySubscript(Expression* _LHS, Expression* _Subscript) : PostfixExpr(_LHS), Subscript(_Subscript){}
private:
    Expression* Subscript;
};

class FuncCall : public PostfixExpr{
public:
    FuncCall(Expression* _LHS) : PostfixExpr(_LHS) {}
    FuncCall(Expression* _LHS, ArgExprList* RHS) : PostfixExpr(_LHS), Args(RHS){}
    ArgExprList* Args;

};

class MemberAccess : public PostfixExpr{
public:
    MemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}
private:
    IdentifierNode* ID;
};

class DerefMemberAccess : public PostfixExpr{
public:
    DerefMemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}
private:
    IdentifierNode* ID;
};

class PostInc : public PostfixExpr{
public:
    using PostfixExpr::PostfixExpr;
};

class PostDec : public PostfixExpr{
public:
    using PostfixExpr::PostfixExpr;
};

//---------------------------------------------------------

class ArgExprList : public Node{
public:
    ArgExprList(Expression* Arg) : Args{Arg}{}
    void AppendArgExpression(Expression* ArgExpr);
    //in the grammar, expression* can be assignment expression
    std::vector<Expression*> Args;
};

//---------------------------------------------------------

class PrefixExpr : public Expression{
public:
    PrefixExpr(Expression* _RHS) : RHS(_RHS){}
    //returns correct unary operator node, described below
    static PrefixExpr* DecodeUnaryOp(std::string* yytext, Expression* _RHS);
private:
    Expression* RHS;
};

class UnaryAddressOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryDerefOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryPlusOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryNegOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryBitwiseNotOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class UnaryLogicalNotOperator : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

//The rest of the prefix types:
class PreInc : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class PreDec : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class SizeofExpr : public PrefixExpr{
public:
    using PrefixExpr::PrefixExpr;
};

class SizeofType : public Expression{
public:
    SizeofType(type_name* _typ_nam) : typ_nam(_typ_nam){}
    type_name* typ_nam;
};

class CastExpr : public PrefixExpr{
public:
    CastExpr(type_name* _typ , Expression* _ExprToBeCast) : typ(_typ), PrefixExpr(_ExprToBeCast) {}
    type_name* typ;
//TODO -> Needs type system
};

//---------------------------------------------------------

class BinaryOpExpression : public Expression{
public:
    BinaryOpExpression(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    Expression *LHS, *RHS;  
};

class Multiply : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Divide : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Modulo : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Add : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class Sub : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class ShiftLeft : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class ShiftRight : public BinaryOpExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

//------------
class LogicalBinaryExpression : public BinaryOpExpression{
public:
    LogicalBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS)/*, EvalsToType() TODO set to int */ {}
//Always evaluates to int
};

class LessThan : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class GreaterThan : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LessThanOrEqual : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class GreaterThanOrEqual : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class EqualTo : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class NotEqualTo : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LogicalAND : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

class LogicalOR : public LogicalBinaryExpression{
public:
    using LogicalBinaryExpression::LogicalBinaryExpression;
};

//------------
class BitwiseBinaryExpression : public BinaryOpExpression{
//type depends on input
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseAND : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseOR : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};

class BitwiseXOR : public BitwiseBinaryExpression{
public:
    using BinaryOpExpression::BinaryOpExpression;
};
//---------------------------------------------------------

class TernaryOpExpression : public Expression{
private:
    Expression* Condition, IfTrue, IfFalse;
};

//---------------------------------------------------------

class GenericAssignExpr : public Expression{
public:
    GenericAssignExpr(Expression* _LHS, Expression* _RHS) : LHS(_LHS), RHS(_RHS){}
    static GenericAssignExpr* DecodeAssignOp(Expression* LHS, std::string* yytext, Expression* RHS);

//Not to be used, dummy stand in, supplies decoder
//Value and type of assignment expression is that of the right side argument
    //possibly move this out of this class
    Expression* LHS, *RHS;
};

class AssignmentExpression : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class MulAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class DivAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ModAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class AddAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class SubAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ShiftLeftAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class ShiftRightAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseANDAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseXORAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

class BitwiseORAssignment : public GenericAssignExpr{
public:
    using GenericAssignExpr::GenericAssignExpr;
};

//---------------------------------------------------------

class ConstantExpression : public Expression{
public:
    ConstantExpression(Expression* Expr);
private:
    Expression* ConstantSubtree;
};

//TODO Comma seperated expression? Grammar from annex:
// expression ::= assignment-expression | expression "," assignment-expression

class CommaSepExpression : public Expression{
public:
    CommaSepExpression(Expression* _LHS, Expression* _RHS) : RHS(_RHS), LHS(_LHS){}
private:
    Expression* LHS, *RHS;
};

//---------------------------------------------------------


/*
Statements
*/

class Statement : public Node{

};

class EmptyStatement : public Statement{};

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
    ExpressionStatement* Init, *Control;
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
    StatementList(Statement* TerminalStatement) : statement(TerminalStatement), RestOfStatements(NULL){}
    StatementList(StatementList* OtherStatements, Statement* ThisStatement) : statement(ThisStatement), RestOfStatements(RestOfStatements){}
    bool isTerminalStatement() const;
private:
    Statement* statement;
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

class DeclarationList : public Node{
public:
    DeclarationList(declaration* _this_decl): this_decl(_this_decl), left_list(NULL){}
    DeclarationList(DeclarationList* list, declaration* _this_decl): this_decl(_this_decl), left_list(list){}
    declaration* this_decl;
    DeclarationList* left_list;
};

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
};


class declaration_specifiers : public Node
{
public:
    // storage information about decleration
    // type, storage ( ie int) (ie long)
    // again cascades
    type_specifier * type_spec;
    declaration_specifiers * specifier; // may be null if there is none
    declaration_specifiers(type_specifier * _type_spec, declaration_specifiers * _specifier = NULL) : type_spec(_type_spec), specifier(_specifier) {}
};

class init_declarator_list : public Node
{
public:
    // multiple declarations in one line
    // cascades
    init_declarator * init_dec;
    init_declarator_list * init_dec_list;// may point to null if there are no more
    init_declarator_list(init_declarator* _init_dec, init_declarator_list * _init_dec_list = NULL) : init_dec(_init_dec), init_dec_list(_init_dec_list) {}
};

class init_declarator : public Node
{
    // a single atomic declaration
    declarator * dec; // points to declaration, ie a name or identifier
    initializer * init; // points to expression being assigned to identifier, may be NULL if none is
    init_declarator(declarator * _dec, initializer * _init = NULL) : dec(_dec), init(_init) {}
};

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
};
*/

class type_specifier : public Node
{

    /*
    enum C_types basic_type;
    */
    std::string type;
    type_specifier(const std::string &Keyword = "") : type(Keyword) {}
};

class specifier_list : public Node
{
    type_specifier * type_spec;
    specifier_list * spec_list; // cascades, may be null
    specifier_list(type_specifier * _type_spec, specifier_list * _spec_list = NULL) : type_spec(_type_spec), spec_list(_spec_list) {}
};


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
};

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
};


class abstract_declarator : public base_declarator
{
public:
    // unlinked operand
    /* pointer* p */
    direct_abstract_declarator * dabs_dec;
    abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, pointer * point = NULL) : base_declarator(point), dabs_dec(_dabs_dec) {}
};



class declarator : public base_declarator
{
    // asserts link between symbol and operand
    /* pointer* p*/
    direct_declarator * dir_dec;
    declarator(direct_declarator * _dir_dec, pointer * point = NULL) : base_declarator(point), dir_dec(_dir_dec) {}
};

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
};

// a class used to signify that an array declaration does not specify array length
class unspecified_array_length : public ConstantExpression {};
// a class used to signify that a parameter list is empty
class empty_parameter_list : public parameter_list {};

class direct_abstract_declarator : public base_direct_declarator
{
public:
    direct_abstract_declarator * dabs_dec; // may be null
    abstract_declarator * abs_dec;
    direct_abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, abstract_declarator * _abs_dec = NULL, ConstantExpression * _const_expr = NULL, parameter_list * _para_list = NULL) 
        : base_direct_declarator(_const_expr, _para_list), dabs_dec(_dabs_dec), abs_dec(_abs_dec) {}
};

class direct_declarator : public base_direct_declarator
{
public:
    IdentifierNode * ID;
    direct_declarator * dir_dec; // may be null
    declarator * dec;                                                                                                                                                                     //TODO doesnt match
    direct_declarator(IdentifierNode * _ID = NULL, direct_declarator * _dir_dec = NULL, ConstantExpression * _const_expr = NULL, parameter_list * _para_list = NULL, declarator * _dec = NULL) 
        : base_direct_declarator(_const_expr, _para_list), ID(_ID), dir_dec(_dir_dec), dec(_dec) {}
};

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
};

class parameter_declaration : public Node
{
public:
    declaration_specifiers * dec_spec;
    declarator * dec;
    parameter_declaration(declaration_specifiers * _dec_spec, declarator * _dec = NULL) : dec_spec(_dec_spec), dec(_dec) {}
};

class type_name : public Node
{
public:
    specifier_list * spec_list;
    abstract_declarator * abs_dec;
    type_name(specifier_list * _spec_list, abstract_declarator * _abs_dec = NULL) : spec_list(_spec_list), abs_dec(_abs_dec) {}
};


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
};

class initializer_list : public Node
{
public:
    initializer * init;
    initializer_list * init_list; // cascades may be null
    initializer_list(initializer * _init, initializer_list * _init_list = NULL) : init(_init), init_list(_init_list) {}
};


class TranslationUnit : public Node
{
private:
    std::vector<GenericExternalDeclaration*> Units;
public:
    TranslationUnit(GenericExternalDeclaration* _externaldef) : Units(_externaldef) {}
};

class GenericExternalDeclaration : public Node{};

class FunctionDefinition : public GenericExternalDeclaration{
public:
    declaration_specifiers* specs;
    declarator* decl;
    declaration_list* decl_list;
    CompoundStatement* Body;
};

class ExternalDeclaration : public GenericExternalDeclaration{
public:
    declaration* decl;
};

#endif