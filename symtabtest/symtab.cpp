#include "symtab.hpp"
typedef bool data_t;
std::unordered_map<std::string, data_t> SymbolTable = std::unordered_map<std::string, data_t>();

data_t lookup(std::string token_value){
    data_t out = SymbolTable.at(token_value);
}

void insert(std::string in, data_t data){
    SymbolTable[in] = data;
}
