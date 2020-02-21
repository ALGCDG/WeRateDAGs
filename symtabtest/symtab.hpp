#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

/*
Need to store:
    Simple variables:
        name, type, scope?
    Arrays:
        name, type, size
    Procedures
        name, number args, return type, arg types
    Typedefs
        name, type
*/

typedef bool data_t;


struct var_or_type_ident_info{
    //string representing symbol's name
    std::string name;
    //int, flex/bisons representation of identifiers
    int type;
};

struct arr_ident_info{
    std::string name;
    int type;
    //size of array, unitialised will have size 0
    int size;
};

struct fun_ident_info{
    std::string name;
    int ret_type;
    int num_args;
    std::vector<int> arg_types;
    /**
     * ? Record default args?
     */
};

//equivalent structure to var_ident_info -> needed at all?
// struct type_ident_info{
//     std::string name;
//     int type;
// };

union ident_info{
    var_or_type_ident_info var;
    arr_ident_info arr;
    fun_ident_info fun;
};

//? think of a better naming scheme?
typedef enum {VAR, TYP, ARR, FUN} which_symbol;
//TODO Rename / restructure, a bit messy :(

struct ident_data{
    ident_info info;
    which_symbol which;
};


extern std::stack<std::unordered_map<std::string, ident_data>> _table;
// struct function_type_entry{
//     _ return_type;
//     int num_args;
//     std::vector< _ > arg_types;
// };

// struct ident_type_entry{
//     _ ident_type;
// };

//extern std::stack<std::unordered_map<std::string, data_t>> SymbolTable;

bool IsNamePresent(std::string token_value);

void InsertNameData(std::string name,  ident_data data);
void EditNameData(std::string name, ident_data data);

ident_data GetTokenData(std::string name);
//TODO differentiate between function lookup and variable lookup?
//answer: doesn't matter, uses most local scope as type
// ie function named in global scope, variable with same name in local scope
// -> assumes identifier refers to variable
// -> if used as a function f(), throw error!

void new_scope();
void end_scope();


#endif