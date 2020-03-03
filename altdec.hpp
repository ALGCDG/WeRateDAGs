#ifndef AST_DECLS
#define AST_DECLS

class declaration
{
    *declartaion_specifier specifier // specifies type of declaration
    *init_declaration_list list // list of variables being declared as this type, may be null
    declaration(declartaion_specifier * _specifier ,init_declaration_list * _list = NULL) : specifier(_specifier), list(_list) {}
};


class declartaion_specifiers
{
    // storage information about decleration
    // type, storage ( ie int) (ie long)
    // again cascades
    type_specifier * type_spec;
    declartaion_specifiers * specifier; // may be null if there is none
    declaration_specifiers(type_specifier _type_spec, declaration_specifiers * _specifier = NULL) type_spec(_type_spec), specifier(_specifier)
    {
        switch(Keyword)
        {
            case "int": specified_type = t_int;
        }
    }
};

class init_declaration_list
{
    // multiple declarations in one line
    // cascades
    init_declaration * init_dec;
    init_declaration_list * init_dec_list;// may point to null if there are no more
    initializer_list(init_declaration * _init_dec, init_declaration_list * _init_dec_list = NULL) init_dec(_init_dec), init_dec_list(_init_dec_list) {}
};

class init_declaration
{
    // a single atomic declaration
    declarator * dec; // points to declaration, ie a name or identifier
    initializer * init; // points to expression being assigned to identifier, may be NULL if none is
    init_declaration(declarator * _dec, initializer * _init = NULL) dec(_dec), init(_init) {}
};

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

class type_specifier
{

    enum C_types basic_type;
    type_specifier(const std::string &Keyword = '')
    {
        switch (Keyword)
        {
            default: basic_type = none;
        }
    }
};

class specifier_list
{
    type_specifier * type_spec;
    specifier_list * spec_list; // cascades, may be null
    specifier_list(type_specifier * _type_spec, specifier_list * _spec_list) type_spec(_type_spec), spec_list(_spec_list) {}
};

/*
enum declaration_mode
{
    variable,
    array,
    function
};

union declaration_details
{
    int array_length,
    std::map<std::string, type> function_parameters
};
*/

class pointer
{
    // pointers are constructed and counted
    pointer* p
    static int count(int i)
    {
        // we count the number of pointers and delete in one thing
        int no_children = p->count(i);
        delete p;
        return no_children + 1
    }
};


class absract_declarator
{
    // asserts link between symbol and operand
    int pointer; // stores how many pointers, zero means its a simple variable
    abstract_declarator(, pointer * point, )
    {
        mode = m;
        // counting layer of pointers
        if ( point != NULL )
        {
            pointer = point->count("0");
            delete point;
        }
    }
}

class direct_abstract_declarator
{
    
};

class declarator
{
    // asserts link between symbol and operand
    int pointer; // stores how many pointers, zero means its a simple variable
    enum declaration_mode mode; // stores what type of declaration this is
    union declaration_details;
    declarator(, pointer * point, )
    {
        mode = m;
        // counting layer of pointers
        if ( point != NULL )
        {
            pointer = point->count("0");
            delete point;
        }
    }
};



class direct_declarator
{
    Identifier * ID;
    direct_declarator * dir_dec; // may be null
    constant_expression * const_expr; // nonnull if it is an array, zero if empty
    parameter_list * para_list; // nonnull if it is a function
};

// parameters

class parameter_list
{
    *parameter_list para_list;// cascades, may be null
    *parameter_declaration para_dec;
};

class parameter_declaration
{
    *declaration_specifiers dec_spec;
    *declarator dec;
};

class type_name
{
    specifier_list * spec_list;
    abstract_declarator * abs_dec;
};



class initializer
{
    assignment_expression * ass_expr;
}

class initializer_list
{
    initializer * init;
    initializer_list * init_list; // cascades may be null
};

#endif
