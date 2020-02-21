#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <deque>

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


struct RecordEntry{
    std::string name;
    virtual std::string RecordType() = 0;
};

struct VarEntry : RecordEntry{
    std::string RecordType();
    int type;
};

struct ArrEntry : RecordEntry{
    std::string RecordType();
    int type;
    int size;
};

struct FuncEntry : RecordEntry{
    std::string RecordType();
    int retType;
    int numArgs;
    std::vector<int> argTypes;
};

struct TypeEntry : RecordEntry{
    std::string RecordType();
    int type;
};

typedef std::unordered_map<std::string, RecordEntry*> ScopedSymbolTable;
typedef std::deque<ScopedSymbolTable> SymbolTable;
extern SymbolTable _table;


//extern std::stack<std::unordered_map<std::string, data_t>> SymbolTable;
bool IsNamePresent(std::string name);

void InsertNameData(std::string name,  RecordEntry * entry);
void EditNameData(std::string name, RecordEntry * entry);

RecordEntry* GetTokenData(std::string name);
//TODO differentiate between function lookup and variable lookup?
    //answer: doesn't matter, uses most local scope as type
    // ie function named in global scope, variable with same name in local scope
    // -> assumes identifier refers to variable
    // -> if used as a function f(), throw error!

void new_scope();
void end_scope();



#endif