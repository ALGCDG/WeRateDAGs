// Want to contain the whole tree in table, not just activated scopes
// Possibly could be integrated with symbol table being used for lexer hack?
// Creates lots of global accesses, possibly neater to contain this in one translation unit scope
// 
// Can build this table after the file has parsed, and thereby convert the AST into a DAG after file analysis
// Or link while running, maintain and build table of declarations etc 
#ifndef AST_CONTEXT
#define AST_CONTEXT

#include "ast_node.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>

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
//is this needed? perhaps only noderecord needed
};
}

// class ScopeTableRecord : public Record{
// public:
//     ScopeTableRecord(_Table* SubTable);
// private:
//     _Table* ScopedTablePtr;
// };

//possibly specialised records for func def, array def?
// class NodeRecord : public Record{
// public:
//     // NodeRecord(Node* ASTNode);
//     NodeRecord(Node* _node) : ASTNode(_node){}
//     Node* GetNode(std::string _ID);
// private:
//     Node* ASTNode;
// };

typedef std::unordered_map<std::string, Record*> LocalTable;

//maps name directly to node
class ContextTable{
public:
    ContextTable() : table_data(){}
    Node* GetObjectDeclaration(std::string _ID); //definition?
    void AddDeclarationNode(std::string _ID, Node* _node); //and definition? for functions?
    void NewScope();
    void PopScope();
    bool IdentifierIsGlobal(std::string _ID); // not defined yet
    static ContextTable* Instance();
private:
    std::deque<LocalTable> table_data;
    static ContextTable* table_instance;
};


#endif