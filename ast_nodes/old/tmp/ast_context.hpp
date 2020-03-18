// Want to contain the whole tree in table, not just activated scopes
// Possibly could be integrated with symbol table being used for lexer hack?
// Creates lots of global accesses, possibly neater to contain this in one translation unit scope
// 
// Can build this table after the file has parsed, and thereby convert the AST into a DAG after file analysis
// Or link while running, maintain and build table of declarations etc 
#ifndef AST_CONTEXT
#define AST_CONTEXT

#include "ast_allnodes.hpp"
// #include "visitors.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>
#include <algorithm>

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

//Not to be accessed outside of the table
namespace ContextData
{
    /*==============================
    Records for the context table
    */
    class ScopeRecord;
    class Record{
    public:
        Record() : parent(NULL){}
        void SetScopeParent(ScopeRecord* _parent);
        ScopeRecord* GetParent();
        virtual std::string GetName(){ return ""; }
    protected:
        ScopeRecord* parent;
    };

    class ScopeRecord : public Record{
    public:
        ScopeRecord() : Record(){}
        void AddRecord(Record* _rec);
        virtual std::vector<Record*>& GetSubTable();
    protected:
        std::vector<Record*> SubTable;
    };

    class FunctionRec : public ScopeRecord{
    public:
        FunctionRec() : ScopeRecord(){}
        std::vector<Record*>& GetSubTable() override;
        std::string Name;
        ScopeRecord* DefinitionBody;
        argsPart* args;
        typePart* Returns;
        //subtable in this case refers to the parameters
        std::string GetName(){ return Name; }
    };
    //===========================
    class NamedRecord : public Record{
    public:
        NamedRecord(std::string* _name): Record(), name(_name){}
        std::string* name;
        std::string* Name(){ return name; }
    };

    /*==============================
    Sub classes for named records
    */
    class VariableDeclarationRec : public Record{
    public:
        VariableDeclarationRec() : Record(){}
        std::string Name;
        std::string GetName(){ return Name; }
        typePart* DefinedToBe;
    };


    /*==============================
    Type parts for the context table
    */
    //function: return, args with type
    //pointer to primitive type
    //array of size, of type
    //canonical type or type name
    class typePart{
    public:
        virtual void AddChild(typePart* _child);
        virtual typePart* GetChild(){}
    };
    class IDPart : public typePart{
    public:
        IDPart(IdentifierNode* _ID, typePart* _child) : ast_node(_ID), definedToBe(_child){}
        IdentifierNode* ast_node;
        typePart* definedToBe;
        void AddChild(typePart* _child);
    };
    class pointerPart : public typePart{
    public:
        pointerPart(typePart* _pointerto) : pointerTo(_pointerto){}
        typePart* pointerTo;
        void AddChild(typePart* _child);//define
    };

    class argPart : public typePart{
    public:
        argPart(typePart* _info) : argInfo(_info){}
        typePart* argInfo;
    };
    class argsPart : public typePart{
    public:
        std::vector<argPart*> argTypes;

    };

    class funcPart : public typePart{
    public:
        funcPart(argsPart* _args, typePart* _returns) : returns(_returns), args(_args){}
        typePart* returns;
        argsPart* args;
        void AddChild(typePart* _child);

    };

    class arrayPart : public typePart{
    public:
        arrayPart(int _size, typePart* _type) : size(_size), ofType(_type){}
        int size;
        typePart* ofType;
        void AddChild(typePart* _child);

    };

    class baseSpecPart : public typePart{
    //parent class for both canonical and user typedef'd type specifiers, and typedef node
    public:
        baseSpecPart* otherSpecs;
        baseSpecPart() : otherSpecs(NULL){}
        void AddChild(baseSpecPart* _child);
        static ContextData::baseSpecPart* CopySpecList(baseSpecPart* head);
        ~baseSpecPart(){
            if (otherSpecs!=NULL){ delete otherSpecs; }
        }
    };

    class canonSpecPart : public baseSpecPart{
    //for canonical type specs
    public:
        std::string* specKeyword;
        canonSpecPart(std::string* _key) : baseSpecPart(), specKeyword(_key){}
    };

    class userSpecPart : public baseSpecPart{
    //for user typedef'd specs
    public:
        std::string* specKeyword;
        typePart* definition; // get from context table
        userSpecPart(std::string* spec) : baseSpecPart(), specKeyword(spec){} //links to context table

    };

    class typedefSpecPart : public baseSpecPart{
    public:
        typedefSpecPart() : baseSpecPart(){}
    };

}


// typedef std::unordered_map<std::string, Context::Record*> LocalTable;

//maps name directly to node
class ContextTable{
public:
    ContextTable() : table_data(), currScopePtr(NULL){}

    void NewScope();
    void PopScope();
    ContextData::Record* GetObjectRecord(const std::string& _ID); //definition?

    bool IdentifierIsGlobal(std::string _ID); // not defined yet
    //searches symbol table for appearance and returns constructed userSpec or canon spec with pointer to definition if user
    ContextData::baseSpecPart* TypeIsUserOrCanon(std::string* keyword, ContextData::baseSpecPart* otherSpecs);
    
    void ProcessIDDecl(const std::string& name, ContextData::typePart* generic);
    void ProcessIDDecl(const std::string& name, ContextData::funcPart* func);
    void ProcessIDDecl(const std::string& name, ContextData::arrayPart* arr);
    
    void AddFuncDef(const std::string& name, ContextData::funcPart* default_so_error);
    void AddFuncDef(const std::string& name, ContextData::funcPart* func);
private:
    std::vector<ContextData::Record*> table_data;
    ContextData::ScopeRecord* currScopePtr;//NULL if at global scope
    void AddToActiveTable(ContextData::Record* _rec);
    std::vector<ContextData::Record*>& GetActiveTable();
    ContextData::Record* FindNameInActiveTable(const std::string& _name);
};

#endif