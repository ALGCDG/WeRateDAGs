#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <deque>

/*
Goal:
    Make lexer hack symbol table as simple as possible
How:
    Only store the identifiers
    Only differentiate between type names, and other objects' names
*/


struct RecordEntry{
    /**
     * Do we need to distinguish between typedef and variable in the same scope?
     * Can add static, monotonicly increasing counter
     * Or is it invalid C to have a typedef and variable use...
     *      in the same scope?
     * eg:
     * typedef int a
     * a a;
     * Some compilers don't compile this, but do compile:
     * typedef int a
     * {
     *  a a;
     * }
     */
    unsigned int insert_order;//possibly?
    char TypeOrNot;
};

typedef std::unordered_map<std::string, RecordEntry> ScopedSymbolTable;
typedef std::deque<ScopedSymbolTable> SymbolTable;
extern SymbolTable _table;

namespace symbTab{
    bool isSymbolPresent(std::string ID);

    //-1 if not found, 0 if other object, 1 if type
    char isSymbolAType(std::string ID);

    void addSymbol(std::string ID, bool isType /*or other object as false*/);
    void new_scope();
    void pop_scope();
}


#endif

