#ifndef FE_SYMTAB_HPP
#define FE_SYMTAB_HPP

#include <string>

//function declarations to be used

bool isTypeName(const std::string& name);
void insertTypeName(const std::string& name);
void insertOtherName(const std::string& name);
void PopScope();
void NewScope();

#endif