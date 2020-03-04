#ifndef AST_DECLS
#define AST_DECLS

#include "ast_node.hpp"
#include <string>

class declaration : public Node
{
public:
    declaration_specifiers* specifier; // specifies type of declaration
    init_declaration_list* list; // list of variables being declared as this type, may be null
    declaration(declaration_specifiers * _specifier ,init_declaration_list * _list = NULL) : specifier(_specifier), list(_list) {}
};


class declaration_specifiers : public Node
{
public:
    // storage information about decleration
    // type, storage ( ie int) (ie long)
    // again cascades
    type_specifier * type_spec;
    declaration_specifiers * specifier; // may be null if there is none
    declaration_specifiers(type_specifier _type_spec, declaration_specifiers * _specifier = NULL) type_spec(_type_spec), specifier(_specifier) {}
};

class init_declaration_list : public Node
{
public:
    // multiple declarations in one line
    // cascades
    init_declaration * init_dec;
    init_declaration_list * init_dec_list;// may point to null if there are no more
    init_declaration_list(init_declaration* _init_dec, init_declaration_list * _init_dec_list = NULL) init_dec(_init_dec), init_dec_list(_init_dec_list) {}
};

class init_declaration : public Node
{
    // a single atomic declaration
    declarator * dec; // points to declaration, ie a name or identifier
    initializer * init; // points to expression being assigned to identifier, may be NULL if none is
    init_declaration(declarator * _dec, initializer * _init = NULL) dec(_dec), init(_init) {}
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
    specifier_list(type_specifier * _type_spec, specifier_list * _spec_list = NULL) type_spec(_type_spec), spec_list(_spec_list) {}
};


class pointer : public Node
{
public:
    // pointers are constructed and counted
    pointer* p;
    static int count(const int &i)
    {
        // we count the number of pointers and delete in one thing
        if (p != NULL)
        {
            int no_children = p->count(i);
            delete p;
            return no_children + 1;
        }
    }
    pointer(pointer * _p = NULL) : p(_p) {}
};

/*
Declarators
*/

class base_declarator : public Node
{
public:
    int point_cnt;
    base_declarator(pointer* point = NULL)
    {
        // counting layer of pointers
        if ( point != NULL )
        {
            point_cnt = point->count(0);
            delete point;
        }
    }
};


class abstract_declarator : public base_declarator
{
public:
    // unlinked operand
    direct_abstract_declarator * dabs_dec;
    abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, pointer * point = NULL) : base_declarator(point), dabs_dec(_dabs_dec) {}
};



class declarator : public base_declarator
{
    // asserts link between symbol and operand
    direct_declarator * dir_dec;
    declarator(direct_declarator * dir_dec, pointer * point = NULL) : base_declarator(point), dir_dec(_dir_dec) {}
};

/*
Direct Declartions
*/

class base_direct_declarator : public Node
{
    // direct_abstract_declarator and direct_declarator share a lot in common
    // it is the better part of wisdom to make them children of a common node
    constant_expression * const_expr; // nonnull if it is an array, zero if empty
    parameter_list * para_list; // nonnull if it is a functio
    base_direct_declarator(abstract_declarator * _abs_dec, constant_expression * _const_expr = NULL, parameter_list * _para_list = NULL) : abs_dec(_abs_dec), const_expr (_const_expr), para_list(_para_list) {}
};

// a class used to signify that an array declaration does not specify array length
class unspecified_array_length : public constant_expression {};
// a class used to signify that a parameter list is empty
class empty_parameter_list : public parameter_list {};

class direct_abstract_declarator : public base_direct_declarator
{
    direct_abstract_declarator * dabs_dec; // may be null
    abstract_declarator * abs_dec;
    direct_abstract_declarator(direct_abstract_declarator * _dabs_dec = NULL, abstract_declarator * _abs_dec = NULL, constant_expression * _const_expr = NULL, parameter_list * _para_list = NULL) : base_direct_declarator(_const_expr, _para_list), dabs_dec(_dabs_dec), abs_dec(_abs_dec) {}
};

class direct_declarator : public base_direct_declarator
{
    Identifier * ID;
    direct_declarator * dir_dec; // may be null
    declarator * dec;
    direct_declarator(Identifier * _ID = NULL, direct_declarator * _dir_dec = NULL, constant_expression * _const_expr = NULL, parameter_list * _para_list = NULL, declarator * _dec) : base_direct_declarator(_const_expr, _para_list), ID(_ID), dir_dec(_dir_dec), dec(_dec) {}
};

/*
Parameters
*/

class parameter_list : public Node
{
    parameter_list * para_list;// cascades, may be null
    parameter_declaration * para_dec;
    abstract_declarator * abs_dec;
    parameter_list(parameter_declaration * _para_dec, parameter_list * _para_list = NULL, abstract_declarator * _abs_dec = NULL) : para_list(_para_list), para_dec(_para_dec), abs_dec(_abs_dec) {}
};

class parameter_declaration : public Node
{
    declaration_specifiers * dec_spec;
    declarator * dec;
    parameter_declaration(declaration_specifiers * _dec_spec, declarator * _dec = NULL) : dec_spec(_dec_spec), dec(_dec) {}
};

class type_name : public Node
{
    specifier_list * spec_list;
    abstract_declarator * abs_dec;
    type_name(specifier_list * _spec_list, abstract_declarator * _abs_dec = NULL) : spec_list(_spec_list), abs_dec(_abs_dec) {}
};


/*
Initializers
*/

class initializer : public Node
{
    assignment_expression * ass_expr;
    // OR
    initializer_list * init_list;
    initializer(assignment_expression * _ass_expr, initializer_list * _init_list = NULL) : ass_expr(_ass_expr), init_list(_init_list) {}
};

class initializer_list : public Node
{
    initializer * init;
    initializer_list * init_list; // cascades may be null
    initializer_list(initializer * _init, initializer_list * _init_list = NULL) : init(_init), init_list(_init_list) {}
};

#endif
