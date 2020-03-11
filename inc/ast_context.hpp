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
        //all records have parents
        void SetScopeParent(ContextData::ScopeRecord* _parent); //non virtual
        ScopeRecord* GetParent(); //non virtual
        virtual std::string* Name(){ return NULL; }
        virtual std::string What(){ return "generic record"; }
    protected:
        ScopeRecord* parent;
    };

    //contains sub scope record
    class ScopeRecord : public Record{
    public:
        ScopeRecord() : Record(){} //set parent to null
        void AddRecord(Record* _rec); //wrapper for push_back
        virtual std::vector<Record*>& GetSubTable();
        std::string What() override{ return "scope"; }
    protected:
        std::vector<Record*> SubTable;
    };

    class FunctionDef;
    class FunctionScopeRecord : public ScopeRecord{
    public:
        FunctionScopeRecord() : ScopeRecord(){}
        //need to make function params decl available as declaration to
        //subscope 
        std::vector<Record*>& GetSubTable() override; 
        void SetDeclarationPtr(FunctionDef* def);
        std::string What() override{ return "funcscope"; }
        FunctionDef* declaration;
    };
    //===========================
    class NamedRecord : public Record{
    public:
        NamedRecord(std::string* _name): Record(), name(_name){}
        std::string* name;
        std::string* Name(){ return name; }
        std::string What() override{ return "named"; }
    };

    /*==============================
    Sub classes for named records
    */
    class typePart;
    class VariableDeclarationRec : public NamedRecord{
    public:
        VariableDeclarationRec(std::string* _name, typePart* _type):NamedRecord(_name), type(_type){} 
        typePart* type;
        std::string What() override { return "variabledec"; }
    };
    class FunctionDef : public NamedRecord{
    public:
        FunctionDef(std::string* _name, typePart* _info): NamedRecord(_name),info(_info){}
        typePart* info;
        FunctionScopeRecord* definition;
        void SetDefRecordPtr(FunctionScopeRecord* scopeptr);
        std::vector<Record*> exposeNamedParams();
        std::string What() override { return "funcdefordec"; }
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
        virtual std::string WhatPart(){ return "genericpart"; }
    };
    class IDPart : public typePart{
    public:
        IDPart(IdentifierNode* _ID, typePart* _child) : ast_node(_ID), definedToBe(_child){}
        IdentifierNode* ast_node;
        typePart* definedToBe;
        void AddChild(typePart* _child);
        std::string WhatPart(){ return "IDpart"; }
    };
    class pointerPart : public typePart{
    public:
        pointerPart(typePart* _pointerto) : pointerTo(_pointerto){}
        typePart* pointerTo;
        void AddChild(typePart* _child);//define
        std::string WhatPart() override { return "ptrpart"; }
    };

    class argPart : public typePart{
    public:
        argPart(typePart* _info) : argInfo(_info){}
        typePart* argInfo;
        std::string WhatPart() override { return "argpart"; }
    };
    class argsPart : public typePart{
    public:
        std::vector<argPart*> argTypes;
        std::string WhatPart() override { return "argspart"; }

    };

    class funcPart : public typePart{
    public:
        funcPart(argsPart* _args, typePart* _returns) : returns(_returns), args(_args){}
        typePart* returns;
        argsPart* args;
        void AddChild(typePart* _child);
        std::string WhatPart() override { return "funcpart"; }

    };

    class arrayPart : public typePart{
    public:
        arrayPart(int _size, typePart* _type) : size(_size), ofType(_type){}
        int size;
        typePart* ofType;
        void AddChild(typePart* _child);
        std::string WhatPart() override { return "arrpart"; }

    };

    class baseSpecPart : public typePart{
    //parent class for both canonical and user typedef'd type specifiers, and typedef node
    public:
        baseSpecPart* otherSpecs;
        baseSpecPart(baseSpecPart* _other) : otherSpecs(_other){}
        void AddChild(baseSpecPart* _child);
        static ContextData::baseSpecPart* CopySpecList(baseSpecPart* head);
        std::string WhatPart() override { return "basespecpart"; }

    };

    class canonSpecPart : public baseSpecPart{
    //for canonical type specs
    public:
        std::string* specKeyword;
        //void AddChild(baseSpecPart* _child); use basespecpart child adder
        canonSpecPart(std::string* _key, baseSpecPart* _other) : baseSpecPart(_other), specKeyword(_key){}
        std::string WhatPart() override { return "canonspecpart"; }

    };

    class userSpecPart : public baseSpecPart{
    //for user typedef'd specs
    public:
        std::string* specKeyword;
        typePart* definition; // get from context table
        //void AddChild(baseSpecPart* _child);

        userSpecPart(std::string* spec, baseSpecPart* otherspecs ,typePart* def) : baseSpecPart(otherspecs), specKeyword(spec), definition(def){} //links to context table
        std::string WhatPart() override { return "userspecpart"; }

    };

    class typedefSpecPart : public baseSpecPart{
    public:
        typedefSpecPart(baseSpecPart* otherspecs) : baseSpecPart(otherspecs){}
        std::string WhatPart() override { return "typedefspecpart"; }

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
    void AddObjectRecord(ContextData::NamedRecord* _node); //and definition? for functions?
    bool IdentifierIsGlobal(std::string _ID); // not defined yet
    //searches symbol table for appearance and returns constructed userSpec or canon spec with pointer to definition if user
    ContextData::baseSpecPart* TypeIsUserOrCanon(std::string* keyword, ContextData::baseSpecPart* otherSpecs);
    
    //link together and set scope ptr correctly
    void AddFunctionDecAndBody(ContextData::FunctionDef* def, ContextData::FunctionScopeRecord* body);
private:
    std::vector<ContextData::Record*> table_data;
    ContextData::ScopeRecord* currScopePtr;//NULL if at global scope
    void AddToActiveTable(ContextData::Record* _rec);
    std::vector<ContextData::Record*>& GetActiveTable();
    ContextData::Record* FindNameInActiveTable(const std::string& _name);
};

#endif