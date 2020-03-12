#include <vector>
#include <string>
#include <stack>

struct genericConstituentType{
    virtual void AddNextType(genericConstituentType* nexttype){}
    virtual void AddNextType(typeSpecifiers* specs){}
    virtual void AddNextType(typeSpecifiers* typ){}
    virtual void AddNextType(functionType* func){}
    virtual void AddNextType(arrayType* arr){}
    virtual void AddNextType(pointerType* point){}
};
struct ParameterTable;
struct functionType : public genericConstituentType{
    void AddNextType(typeSpecifiers* specs) override;
    void AddNextType(pointerType* point) override;
    typeSpecifiers* basetypeReturnType;
    pointerType* pointerReturnType;
    ParameterTable* arguments;
};

struct arrayType : public genericConstituentType{
    arrayType(int _size) : size(_size){}
    int size;
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;

    arrayType* nextArray;
    pointerType* pointerElementType;
    typeSpecifiers* basetypeElementType;
};

struct pointerType : public genericConstituentType{
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;
    pointerType* ptToPointer;
    arrayType* ptToArray;
    typeSpecifiers* ptToBasetype;
    functionType* ptToFunc;
};

struct typeSpecifiers : public genericConstituentType{
    std::vector<std::string> specs;
    void AddNextType(std::string spec);
};

// struct funcArgs{
//     //abstract represented with empty string
//     std::vector<std::pair<std::string, genericConstituentType*> > args;
// };




struct Record{
    virtual bool hasID(const std::string& _id){ return false; }
    virtual void SetName(const std::string& _id){}
    bool isTypedef = false;
};

struct Table : public Record{
    Table(Table* _parentTable) : parentTable(_parentTable){}
    std::vector<Record*> subRecords;
    Table* parentTable;
};

struct ParameterTable : public Table{
    ParameterTable(Table* _parentTable) : Table(_parentTable){}
};


struct NamedRecord : public Record{
    bool hasID(const std::string& _id) override;
    std::string id;
};

struct VariableDeclaration : public NamedRecord{
    //sets all others to null explicitly
    void AddPrimary(genericConstituentType* _generic){ throw "uh oh?"; }
    void AddPrimary(pointerType* _primaryPt);
    void AddPrimary(arrayType* _primaryArr);
    void AddPrimary(functionType* _primaryFunc);
    void AddPrimary(typeSpecifiers* _primaryTypespec);
    
    //can be only one of the below
    pointerType* primaryPt;
    arrayType* primaryArr;
    functionType* primaryFunc;
    typeSpecifiers* primaryTypespec;

};


struct FunctionDefinition : public NamedRecord{
    functionType* funcInfo;
    Table* body;
    void AddPrimary(genericConstituentType* _generic){ throw "uh oh?3"; }
    void AddPrimary(pointerType* _primaryPt);
    // void AddPrimary(arrayType* _primaryArr);
    // void AddPrimary(functionType* _primaryFunc);
    void AddPrimary(typeSpecifiers* _primaryTypespec);
    pointerType* primaryPt;
    typeSpecifiers* primaryTypespec;
};

class SymbolTable{
public:
    SymbolTable();
    void awaitDecSpecs();//done
    // void stopAwaitDecSpecs();//
    void AssertTypedef();//done
    // void awaitDeclarator();
    // void endAwaitDeclarator();
    void AppendCachedDecSpecs();//done
    void clearDecSpecs();//done
    void PushDecSpec(std::string _specid);//done
    void AddPtrToCurrRecord();//done
    void AddArrayToCurrRecord(int _size);//done
    void AddFuncToCurrRecord();//done
    // void AwaitFuncParams();
    void StartParamDeclaration();//done
    void EndParamDeclaration();//done
    void EndFuncParams();//done
    void AddFuncRecordBody();
    void AddIDtoCurrRecord(std::string _id);//done
    // void awaitParamDec();
    // void endAwaitParamDec();
    void AddUnnamedtoCurrRecord();
    void StartNewFuncDef();
    void EndFuncDef();
    void StartNewDeclaration();//done
    void EndDeclaration();//done
    void NewScope();//done
    void PopScope();//done
private:
    // std::stack<funcArgs*> funcargsStack;
    std::stack<std::vector<genericConstituentType*> > declPartsStack;
    genericConstituentType* AccumulateDeclParts();
    std::stack<VariableDeclaration*> declarationStack;
    std::stack<std::vector<std::string> >decspecStack;
    Table* trans_unit;
    Table* ActiveScope;
    FunctionDefinition* ActiveFuncDef;
    NamedRecord* ActiveRecord;
    // funcArgs* ActiveFuncArgs;
};


    