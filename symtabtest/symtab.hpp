#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <unordered_map>
#include <vector>

/*
Need to store:
    Data type + name
    Procedure names
        Number of args and types for function
*/

typedef bool data_t;



// struct function_type_entry{
//     _ return_type;
//     int num_args;
//     std::vector< _ > arg_types;
// };

// struct ident_type_entry{
//     _ ident_type;
// };

extern std::unordered_map<std::string, data_t> SymbolTable;

data_t lookup(std::string token_value);

void insert(std::string in, data_t val);


#endif