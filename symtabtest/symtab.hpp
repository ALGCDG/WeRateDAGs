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
*/

typedef bool data_t;


struct var_ident_info{
    std::string name;
    int type;
};

struct arr_ident_info : var_ident_info{
    int size;
};

struct fun_ident_info : var_ident_info{
    int num_args;
    std::vector<int> arg_types;
    /**
     * ? Record default args?
     */
};

union ident_info{
    var_ident_info var;
    arr_ident_info arr;
    fun_ident_info fun;
};

typedef enum {VAR, ARR, FUN} which_symbol;
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

bool IsTokenPresent(std::string token_value);

void InsertToken(std::string name, ident_data ident);

ident_data GetTokenData(std::string name);
//TODO differentiate between function lookup and variable lookup?
//answer: doesn't matter, uses most local scope as type
// ie function named in global scope, variable with same name in local scope
// -> assumes identifier refers to variable
// -> if used as a function f(), throw error!

void new_scope();

void end_scope();
#endif