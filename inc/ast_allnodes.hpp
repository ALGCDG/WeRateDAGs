#ifndef ALLNODES_HPP
#define ALLNODES_HPP

#include <string>
#include <vector>
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

class Node{
public:
    void accept(Visitor* AVisitor);
};

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
    IdentifierNode(std::string* _name) : Name(_name){}
    std::string* Name;
    ContextData::Record* ContextRecord;
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

class TypedefNode : public Node{

};
//---------------------------------------------------------
class PostfixExpr : public Expression{
public:
    PostfixExpr(Expression* _LHS) : LHS(_LHS){}
    Expression* LHS;
};
//---------------------------------------------------------

class ArgExprList : public Node{
public:
    ArgExprList(Expression* Arg){ Args.push_back(Arg);}
    void AppendArgExpression(Expression* ArgExpr){ Args.push_back(ArgExpr); }
    //in the grammar, expression* can be assignment expression
    std::vector<Expression*> Args;
};

//------------------------------------------------------
class ArraySubscript : public PostfixExpr{
public:
    ArraySubscript(Expression* _LHS, Expression* _Subscript) : PostfixExpr(_LHS), Subscript(_Subscript){}

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

    IdentifierNode* ID;
};

class DerefMemberAccess : public PostfixExpr{
public:
    DerefMemberAccess(Expression* _LHS, IdentifierNode* _ID) : PostfixExpr(_LHS), ID(_ID){}

    IdentifierNode* ID;
};

class PostInc : public PostfixExpr{
public:
    PostInc(Expression* _LHS) : PostfixExpr(_LHS){}
};

class PostDec : public PostfixExpr{
public:
    PostDec(Expression* _LHS) : PostfixExpr(_LHS){}
};


//---------------------------------------------------------

class PrefixExpr : public Expression{
public:
    PrefixExpr(Expression* _RHS) : RHS(_RHS){}
    //returns correct unary operator node, described below
    static PrefixExpr* DecodeUnaryOp(std::string* yytext, Expression* _RHS);

    Expression* RHS;
};

class UnaryAddressOperator : public PrefixExpr{
public:
    UnaryAddressOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

class UnaryDerefOperator : public PrefixExpr{
public:
    UnaryDerefOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

class UnaryPlusOperator : public PrefixExpr{
public:
    UnaryPlusOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

class UnaryNegOperator : public PrefixExpr{
public:
    UnaryNegOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

class UnaryBitwiseNotOperator : public PrefixExpr{
public:
    UnaryBitwiseNotOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

class UnaryLogicalNotOperator : public PrefixExpr{
public:
    UnaryLogicalNotOperator(Expression* _RHS) : PrefixExpr(_RHS){}
};

//The rest of the prefix types:
class PreInc : public PrefixExpr{
public:
    PreInc(Expression* _RHS) : PrefixExpr(_RHS){}
};

class PreDec : public PrefixExpr{
public:
    PreDec(Expression* _RHS) : PrefixExpr(_RHS){}
};

class SizeofExpr : public PrefixExpr{
public:
    SizeofExpr(Expression* _RHS) : PrefixExpr(_RHS){}
};

class SizeofType : public Expression{
public:
    SizeofType(type_name* _typ_nam) : typ_nam(_typ_nam){}
    type_name* typ_nam;
};

class CastExpr : public PrefixExpr{
public:
    CastExpr(type_name* _typ , Expression* _ExprToBeCast) : PrefixExpr(_ExprToBeCast), typ(_typ) {}
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
    Multiply(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class Divide : public BinaryOpExpression{
public:
    Divide(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class Modulo : public BinaryOpExpression{
public:
    Modulo(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class Add : public BinaryOpExpression{
public:
    Add(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class Sub : public BinaryOpExpression{
public:
    Sub(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class ShiftLeft : public BinaryOpExpression{
public:
    ShiftLeft(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class ShiftRight : public BinaryOpExpression{
public:
    ShiftRight(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

//------------
class LogicalBinaryExpression : public BinaryOpExpression{
public:
    LogicalBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS)/*, EvalsToType() TODO set to int */ {}
//Always evaluates to int
};

class LessThan : public LogicalBinaryExpression{
public:
    LessThan(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class GreaterThan : public LogicalBinaryExpression{
public:
    GreaterThan(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class LessThanOrEqual : public LogicalBinaryExpression{
public:
    LessThanOrEqual(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class GreaterThanOrEqual : public LogicalBinaryExpression{
public:
    GreaterThanOrEqual(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class EqualTo : public LogicalBinaryExpression{
public:
    EqualTo(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class NotEqualTo : public LogicalBinaryExpression{
public:
    NotEqualTo(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class LogicalAND : public LogicalBinaryExpression{
public:
    LogicalAND(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

class LogicalOR : public LogicalBinaryExpression{
public:
    LogicalOR(Expression* _LHS, Expression* _RHS) : LogicalBinaryExpression(_LHS, _RHS){}
};

//------------
class BitwiseBinaryExpression : public BinaryOpExpression{
//type depends on input
public:
    BitwiseBinaryExpression(Expression* _LHS, Expression* _RHS) : BinaryOpExpression(_LHS, _RHS){}
};

class BitwiseAND : public BitwiseBinaryExpression{
public:
    BitwiseAND(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
};

class BitwiseOR : public BitwiseBinaryExpression{
public:
    BitwiseOR(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
};

class BitwiseXOR : public BitwiseBinaryExpression{
public:
    BitwiseXOR(Expression* _LHS, Expression* _RHS) : BitwiseBinaryExpression(_LHS, _RHS){}
};
//---------------------------------------------------------

class TernaryOpExpression : public Expression{
public:
    TernaryOpExpression(Expression* cond, Expression* _true, Expression* _false) : Condition(cond), IfTrue(_true), IfFalse(_false){}
    Expression* Condition, *IfTrue, *IfFalse;
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
    AssignmentExpression(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class MulAssignment : public GenericAssignExpr{
public:
    MulAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class DivAssignment : public GenericAssignExpr{
public:
    DivAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class ModAssignment : public GenericAssignExpr{
public:
    ModAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class AddAssignment : public GenericAssignExpr{
public:
    AddAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class SubAssignment : public GenericAssignExpr{
public:
    SubAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class ShiftLeftAssignment : public GenericAssignExpr{
public:
    ShiftLeftAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class ShiftRightAssignment : public GenericAssignExpr{
public:
    ShiftRightAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class BitwiseANDAssignment : public GenericAssignExpr{
public:
    BitwiseANDAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class BitwiseXORAssignment : public GenericAssignExpr{
public:
    BitwiseXORAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

class BitwiseORAssignment : public GenericAssignExpr{
public:
    BitwiseORAssignment(Expression* _LHS, Expression* _RHS) : GenericAssignExpr(_LHS, _RHS){}
};

//---------------------------------------------------------

class ConstantExpression : public Expression{
public:
    ConstantExpression(){}
    ConstantExpression(Expression* Expr): ConstantSubtree(Expr){}

    Expression* ConstantSubtree;
};

//TODO Comma seperated expression? Grammar from annex:
// expression ::= assignment-expression | expression "," assignment-expression

class CommaSepExpression : public Expression{
public:
    CommaSepExpression(Expression* _LHS, Expression* _RHS) : RHS(_RHS), LHS(_LHS){}

    Expression* RHS, *LHS;
};

//---------------------------------------------------------


/*
Statements
*/

class Statement : public Node{

};


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
    Expression* ControlExpression;
    Statement* Body;
};

class DoWhile : public Statement{
public:
    DoWhile(Statement* _Body, Expression* _Control) : Body(_Body), ControlExpression(_Control){}

    Statement* Body;
    Expression* ControlExpression;
};

class For : public Statement{
public:
    For(ExpressionStatement* _init, ExpressionStatement* _control, Statement* _body) 
            : Init(_init), Control(_control), Next(NULL), Body(_body){}
    For(ExpressionStatement* _init, ExpressionStatement* _control, Expression* _next, Statement* _body) 
            : Init(_init), Control(_control), Next(_next), Body(_body){}

    ExpressionStatement* Init, *Control;
    Expression* Next;
    Statement* Body;
};

//------------------------------

class SelectionStatement : public Statement{
public:
    SelectionStatement(Expression* _control) : ControlExpression(_control){}

    Expression* ControlExpression;
};

class If : public SelectionStatement{
public:
    If(Expression* _control, Statement* _iftrue) : SelectionStatement(_control), IfTrue(_iftrue){}

    Statement* IfTrue;
};

class IfElse : public SelectionStatement{
public:
    IfElse(Expression* _control, Statement* _iftrue, Statement* _iffalse) 
            : SelectionStatement(_control), IfTrue(_iftrue), IfFalse(_iffalse){}

    Statement* IfTrue;
    Statement* IfFalse;
};

class Switch : public SelectionStatement{
public:
    Switch(Expression* _control, Statement* _body) : SelectionStatement(_control), Body(_body){}

    Statement* Body;
};

//------------------------------

class ExpressionStatement : public Statement{
public:
    ExpressionStatement(Expression* _expr) : Expr(_expr){}
    Expression* Expr;
};

class EmptyStatement : public ExpressionStatement{
public:
    EmptyStatement(): ExpressionStatement(NULL){}
};
//------------------------------

class StatementList : public Node{
public:
    StatementList(Statement* TerminalStatement) : statement(TerminalStatement), RestOfStatements(NULL){}
    StatementList(StatementList* OtherStatements, Statement* ThisStatement) : statement(ThisStatement), RestOfStatements(RestOfStatements){}
    bool isTerminalStatement() const;

    Statement* statement;
    StatementList* RestOfStatements;
};

//-------------------------------

class CompoundStatement : public Statement{
public:
    CompoundStatement(DeclarationList* _decls, StatementList* _stmnts) : Decls(_decls), Statements(_stmnts){}
    CompoundStatement(DeclarationList* _decls) : Decls(_decls), Statements(NULL){}
    CompoundStatement(StatementList* _stmnts) : Decls(NULL), Statements(_stmnts){}
    CompoundStatement() : Decls(NULL), Statements(NULL) {}
    DeclarationList* Decls;
    StatementList* Statements;
};

//-------------------------------

class CaseOrDefault : public Statement{
public:
    CaseOrDefault(Expression* _eval, Statement* _body) : Eval(_eval), Body(_body){}
    CaseOrDefault(Statement* _body) : Eval(NULL), Body(_body){}
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
    TypedefNode * storage_class_specifier;
    declaration_specifiers(type_specifier * _type_spec, declaration_specifiers * _specifier = NULL, TypedefNode* stor_spec=NULL) : type_spec(_type_spec), specifier(_specifier), storage_class_specifier(stor_spec)  {}
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
public:
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
public:
    /*
    enum C_types basic_type;
    */
    std::string* type;
    type_specifier( std::string* Keyword) : type(Keyword) {}
};

class specifier_list : public Node
{
public:
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
public:
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
class unspecified_array_length : public ConstantExpression {
public:
    
};

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
    parameter_list():para_list(NULL), para_dec(NULL), abs_dec(NULL){}
};
// a class used to signify that a parameter list is empty
class empty_parameter_list : public parameter_list {
public:
    empty_parameter_list() {}
};

class parameter_declaration : public Node
{
public:
    declaration_specifiers * dec_spec;
    base_declarator * dec;
    parameter_declaration(declaration_specifiers * _dec_spec, base_declarator * _dec = NULL) : dec_spec(_dec_spec), dec(_dec) {}
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

class GenericExternalDeclaration : public Node{};

class TranslationUnit : public Node
{
public:
    std::vector<GenericExternalDeclaration*> decls;
    TranslationUnit(GenericExternalDeclaration* _externaldef){ decls.push_back(_externaldef); }
    void AppendDeclaration(GenericExternalDeclaration* _decl){ decls.push_back(_decl);}
};


class FunctionDefinition : public GenericExternalDeclaration{
public:
    FunctionDefinition(declaration_specifiers* _specs, declarator* _decl, CompoundStatement* _stmt) : specs(_specs), decl(_decl), Body(_stmt){}
    FunctionDefinition(declarator* _decl, CompoundStatement* _stmt) : FunctionDefinition(NULL, _decl, _stmt){}
    declaration_specifiers* specs;
    declarator* decl;
    //DeclarationList* decl_list; only needed for k&r
    CompoundStatement* Body;
};

class ExternalDeclaration : public GenericExternalDeclaration{
public:
    ExternalDeclaration(declaration* _decl) : decl(_decl){}
    declaration* decl;
};

#endif
