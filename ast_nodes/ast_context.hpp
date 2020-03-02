// Want to contain the whole tree in table, not just activated scopes
// Possibly could be integrated with symbol table being used for lexer hack?
// Creates lots of global accesses, possibly neater to contain this in one translation unit scope
// 
// Can build this table after the file has parsed, and thereby convert the AST into a DAG after file analysis
// Or link while running, maintain and build table of declarations etc 
#ifndef AST_CONTEXT
#define AST_CONTEXT

#include "_ast_types.hpp"

/*  Don't need as much of a robust class hierarchy
    Need to contain:
    - Type definitions / declarations
    - Function declarations / definitions
    - Variable declarations / definitions

    Need to store scope:
    - Messy data structure for containing vector of vector of ... 
    - Instead, use a number to count the scope depth
    With each scope increase, increase the number
    Each scope decrease, decrease the number
    - OR symbol tables, as linked data structures using pointers

*/

class Record{
public:
    Identifier ID;
};

class ScopeTableRecord : public Record{
private:
    _Table* ScopedTablePtr;
};

class FunctionDeclarationRecord : public Record{
private:
    ParameterList* Params;
};

class FunctionDefinitionRecord : public Record{

};

class VariableDeclarationRecord : public Record{

};

class TypeDeclarationRecord : public Record{

};

class _Table{
    //provide functions for accessing the table
private:
    std::vector<Record*> Entries;
};

class Context{
    //provide functions for using accessed data
private:
    _Table ContextTable;
}




#endif