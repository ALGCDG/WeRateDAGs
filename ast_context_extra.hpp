#include <string>
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
    FunctionDefinition() : ScopeRecord(){}
    std::vector<Record*>& GetSubTable() override;
    std::string Name;
    ScopeRecord* DefinitionBody;
    argsPart* args;
    typePart* Returns;
    //subtable in this case refers to the parameters
    std::string GetName(){ return Name; }
};

class VariableDeclarationRec : public Record{
public:
    VariableDeclaration() : Record(){}
    std::string Name;
    std::string GetName(){ return Name; }
    typePart* DefinedToBe;
};

