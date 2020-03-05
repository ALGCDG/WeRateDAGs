// Want to contain the whole tree in table, not just activated scopes
// Possibly could be integrated with symbol table being used for lexer hack?
// Creates lots of global accesses, possibly neater to contain this in one translation unit scope
// 
// Can build this table after the file has parsed, and thereby convert the AST into a DAG after file analysis
// Or link while running, maintain and build table of declarations etc 
#ifndef AST_CONTEXT
#define AST_CONTEXT

#include "ast_node.hpp"
#include "visitors.hpp"
#include "ast_expressions.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>

class ConstantExpression;
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
namespace Context
{
    class Record{

};


class typePart{
    //function: return, args with type
    //pointer to primitive type
    //array of size, of type
    //canonical type or type name
};

class pointerPart : public Context::typePart{
public:
    Context::typePart* pointerTo;
};

class argPart : public Context::typePart{
public:
    std::vector<Context::typePart*> argTypes;
};

class funcPart : public Context::typePart{
public:
    Context::typePart* returns;
    Context::argPart* args;
};

class arrayPart : public Context::typePart{
public:
    ConstantExpression* size;
    Context::typePart* ofType;
};

}



typedef std::unordered_map<std::string, Context::Record*> LocalTable;

//maps name directly to node
class ContextTable{
public:
    ContextTable() : table_data(){}
    Context::Record* GetObjectRecord(std::string _ID); //definition?
    void AddObjectRecord(std::string _ID, Context::Record* _node); //and definition? for functions?
    void NewScope();
    void PopScope();
    bool IdentifierIsGlobal(std::string _ID); // not defined yet
    static ContextTable* Instance();
private:
    std::deque<LocalTable> table_data;
    static ContextTable* table_instance;
};


#endif