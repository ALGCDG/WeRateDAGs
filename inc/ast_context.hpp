// Want to contain the whole tree in table, not just activated scopes
// Possibly could be integrated with symbol table being used for lexer hack?
// Creates lots of global accesses, possibly neater to contain this in one translation unit scope
// 
// Can build this table after the file has parsed, and thereby convert the AST into a DAG after file analysis
// Or link while running, maintain and build table of declarations etc 
#ifndef AST_CONTEXT
#define AST_CONTEXT

#include "ast_allnodes.hpp"
#include "visitors.hpp"
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
    /*==============================
    Records for the context table
    */
    class Record{
    public:
        Record() : parent(ContextTable::Instance().GetCurrParentScopePtr()){}
        ScopeRecord* parent;
    //needs to store some stuff
    };

    class ScopeRecord : public Record{
    //just a wrapper for the vector
    public:
        ScopeRecord() : Record(){}
        std::vector<Record*> SubTable;
    };

    class NamedRecord : public Record{
    public:
        NamedRecord(std::string* _name): Record(), name(_name){}
        std::string* name;
    };


    /*==============================
    Sub classes for named records
    */
    class VariableDeclaration : public NamedRecord{
    public:
        VariableDeclaration(std::string* _name, typePart* _type):NamedRecord(_name), type(_type){} 
        typePart* type;
    };


    /*==============================
    Type parts for the context table
    */
    class typePart{
        //function: return, args with type
        //pointer to primitive type
        //array of size, of type
        //canonical type or type name
        public:
            virtual void AddChild(typePart* _child);
    };
    class IDPart : public typePart{
    public:
        IDPart(IdentifierNode* _ID, typePart* _child) : ID(_ID), definedToBe(_child){}
        IdentifierNode* ID;
        typePart* definedToBe;
        void AddChild(typePart* _child);
    };
    class pointerPart : public Context::typePart{
    public:
        pointerPart(Context::typePart* _pointerto) : pointerTo(_pointerto){}
        Context::typePart* pointerTo;
        void AddChild(typePart* _child){;}//define
    };

    class argPart : public Context::typePart{
    public:
        std::vector<Context::typePart*> argTypes;
    };

    class funcPart : public Context::typePart{
    public:
        funcPart(Context::argPart* _args, Context::typePart* _returns) : returns(_returns), args(_args){}
        Context::typePart* returns;
        Context::argPart* args;
        void AddChild(typePart* _child);
    };

    class arrayPart : public Context::typePart{
    public:
        arrayPart(int _size, Context::typePart* _type) : size(_size), ofType(_type){}
        int size;
        Context::typePart* ofType;
        void AddChild(typePart* _child);
    };

    class baseSpecPart : public Context::typePart{
    //parent class for both canonical and user typedef'd type specifiers, and typedef node
    public:
        baseSpecPart* otherSpecs;
        baseSpecPart(baseSpecPart* _other) : otherSpecs(_other){}
    };

    class canonSpecPart : public baseSpecPart{
    //for canonical type specs
    public:
        std::string* specKeyword;
        void AddChild(baseSpecPart* _child);
        canonSpecPart(std::string* _key, baseSpecPart* _other) : baseSpecPart(_other), specKeyword(_key){}
    };

    class userSpecPart : public baseSpecPart{
    //for user typedef'd specs
    public:
        std::string* specKeyword;
        typePart* definition; // get from context table
        void AddChild(baseSpecPart* _child);

        userSpecPart(std::string* spec, baseSpecPart* otherspecs ,typePart* def) : baseSpecPart(otherspecs), specKeyword(spec), definition(def){} //links to context table
    };

    class typedefSpecPart : public baseSpecPart{
    public:
        typedefSpecPart(baseSpecPart* otherspecs) : baseSpecPart(otherspecs){}
    };

}


// typedef std::unordered_map<std::string, Context::Record*> LocalTable;

//maps name directly to node
class ContextTable{
public:
    Context::Record* GetObjectRecord(std::string _ID); //definition?
    void AddObjectRecord(std::string _ID, Context::Record* _node); //and definition? for functions?
    void NewScope();
    void PopScope();
    bool IdentifierIsGlobal(std::string _ID); // not defined yet

    //searches symbol table for appearance and returns constructed userSpec or canon spec with pointer to definition if user
    Context::baseSpecPart* TypeIsUserOrCanon(std::string* keyword, Context::baseSpecPart* otherSpecs);
    static ContextTable& Instance();
    Context::ScopeRecord* GetCurrParentScopePtr();
private:
    //private constructor for singleton pattern
    ContextTable() : table_data(), currParentScopePtr(NULL){}
    std::vector<Context::Record*> table_data;
    Context::ScopeRecord* currParentScopePtr;//NULL if at global scope
    static ContextTable table_instance;
    void AddToActiveTable(Context::Record* _rec);
};


#endif
