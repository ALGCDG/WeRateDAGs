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

struct functionType : public genericConstituentType{
    void AddNextType(typeSpecifiers* specs) override;
    void AddNextType(pointerType* point) override;
    typeSpecifiers* basetypeReturnType;
    pointerType* pointerReturnType;
    funcArgs* arguments;
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

struct funcArgs{
    //abstract represented with empty string
    std::vector<std::pair<std::string, genericConstituentType*> > args;
};




struct Record{
    virtual bool hasID(const std::string& _id){ return false; }
    virtual void SetName(const std::string& _id){}
};

struct Table : public Record{
    std::vector<Record*> subRecords;
    Table* parentTable;
};

struct VariableDeclaration : public Record{
    bool hasID(const std::string& _id) override;
    std::string id;
    //sets all others to null explicitly
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

struct FunctionDefinition : public Record{
    bool hasID(const std::string& _io) override;
    std::string id;
     
};

class SymbolTable{
public:
    void awaitDecSpecs();
    void stopAwaitDecSpecs();
    void AssertTypedef();
    void awaitDeclarator();
    void endAwaitDeclarator();
    void AppendCachedDecSpecs();
    void clearDecSpecs();
    void PushDecSpec(const std::string& _id);
    void AddPtrToCurrRecord();
    void AddArrayToCurrRecord(int _size);
    void AddFuncToCurrRecord();
    void AwaitFuncParams();
    void EndAwaitFuncParams();
    void AddIDtoCurrRecord();
    void awaitParamDec();
    void endAwaitParamDec();
    void AddUnnamedParam();
    void NewScope();
    void PopScope();
private:
    std::stack<funcArgs*> funcargsStack;
    std::stack<std::vector<genericConstituentType*> > declPartsStack;
    genericConstituentType* AccumulateDeclParts();
    
    std::stack<std::vector<std::string> >decspecStack;
    Table* Data;
};


    