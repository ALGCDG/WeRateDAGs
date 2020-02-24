#include "symtab.hpp"
typedef bool data_t;
std::stack<std::unordered_map<std::string, ident_data>> SymbolTable = std::stack<std::unordered_map<std::string, ident_data>>();

// data_t lookup(std::string token_value){
//     data_t out = SymbolTable.at(token_value);
// }

// void insert(std::string in, data_t data){
//     SymbolTable[in] = data;
// }
