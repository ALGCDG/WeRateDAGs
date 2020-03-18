#ifndef AST_CONT2_HPP
#define AST_CONT2_HPP

#include <vector>
#include <string>
#include <stack>
#include <iostream>

struct typeSpecifiers;
struct ParameterTable;
struct arrayType;
struct pointerType;
struct functionType;
struct VariableDeclaration;
struct FunctionDefinitionRec;
namespace prPr{
    extern int tabs;
    void Tabsplus();
    void Tabsminus();
    std::string genTabs();
}

struct genericConstituentType{
    virtual void BeAppended(genericConstituentType* other) = 0;
    virtual void BeAppended(VariableDeclaration* vardec) = 0;
    virtual void BeAppended(FunctionDefinitionRec* funcdec) = 0;
    virtual void AddNextType(typeSpecifiers* specs){}
    virtual void AddNextType(functionType* func){}
    virtual void AddNextType(arrayType* arr){}
    virtual void AddNextType(pointerType* point){}
    virtual void Show(){}
};
struct functionType : public genericConstituentType{
    void BeAppended(genericConstituentType* other);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(FunctionDefinitionRec* funcdec);
    void AddNextType(typeSpecifiers* specs) override;
    void AddNextType(pointerType* point) override;
    typeSpecifiers* basetypeReturnType;
    pointerType* pointerReturnType;
    ParameterTable* arguments;
    void Show();
};

struct arrayType : public genericConstituentType{
    void BeAppended(genericConstituentType* other);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(FunctionDefinitionRec* funcdec);
    arrayType(int _size) : size(_size){}
    int size;
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;

    arrayType* nextArray;
    pointerType* pointerElementType;
    typeSpecifiers* basetypeElementType;
    void Show();
};

struct pointerType : public genericConstituentType{
    void BeAppended(genericConstituentType* other);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(FunctionDefinitionRec* funcdec);
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;
    void AddNextType(functionType* func) override;
    pointerType* ptToPointer;
    arrayType* ptToArray;
    typeSpecifiers* ptToBasetype;
    functionType* ptToFunc;
    void Show();
};

struct typeSpecifiers : public genericConstituentType{
    void BeAppended(genericConstituentType* other);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(FunctionDefinitionRec* funcdec);
    std::vector<std::string> specs;
    void AddNextType(std::string spec);
    void Show();
};

// struct funcArgs{
//     //abstract represented with empty string
//     std::vector<std::pair<std::string, genericConstituentType*> > args;
// };



struct Table;
struct Record{
    Record(){}
    Record(Table* _parentTable) : parentTable(_parentTable){}
    virtual bool hasID(const std::string& _id){ return false; }
    virtual void SetName(const std::string& _id){}
    bool isTypedef = false;
    virtual void PrettyPrint(){}
    Table* parentTable;
};

struct Table : public Record{
    Table(Table* _parentTable) : Record(_parentTable){}
    std::vector<Record*> subRecords;
    void PrettyPrint() override;
};

struct ParameterTable : public Table{
    ParameterTable(Table* _parentTable) : Table(_parentTable){}
    void PrettyPrint() override;
};


struct NamedRecord : public Record{
    NamedRecord(){}
    NamedRecord(Table* _parent) : Record(_parent){}
    bool hasID(const std::string& _id) override { return _id == id; }
    //use this to check on receipt of named record which type it is
    virtual bool isFunctionDefinition(){return false; }
    void SetName(const std::string& _id){ id = _id; }
    std::string id;
    virtual genericConstituentType* GetPrimary() = 0;

};

struct VariableDeclaration : public NamedRecord{
    VariableDeclaration(Table* _parent) : NamedRecord(_parent){}
    bool isFunctionDefinition(){ return false; }
    //sets all others to null explicitly
    void AddPrimary(genericConstituentType* _generic){ std::cout << "lol"; }
    void AddPrimary(pointerType* _primaryPt);
    void AddPrimary(arrayType* _primaryArr);
    void AddPrimary(functionType* _primaryFunc);
    void AddPrimary(typeSpecifiers* _primaryTypespec);
    
    //can be only one of the below
    pointerType* primaryPt;
    arrayType* primaryArr;
    functionType* primaryFunc;
    typeSpecifiers* primaryTypespec;
    bool IsGlobal();
    unsigned int GetDepth();
    genericConstituentType* GetPrimary() override;
    void PrettyPrint() override;
};


struct FunctionDefinitionRec : public NamedRecord{
    FunctionDefinitionRec(){}
    bool isFunctionDefinition(){ return true; }
    functionType* funcInfo;
    Table* body;
    void AddPrimary(genericConstituentType* _generic){ std::cout << "hmm";}
    void AddPrimary(typeSpecifiers* _typ){ std::cout << "hmm2"; }
    // void AddPrimary(pointerType* _primaryPt);
    // void AddPrimary(arrayType* _primaryArr);
    void AddPrimary(functionType* _Func);
    // void AddPrimary(typeSpecifiers* _primaryTypespec);
    // pointerType* primaryPt;
    // typeSpecifiers* primaryTypespec;
    void PrettyPrint() override;
    genericConstituentType* GetPrimary() override;
};

class SymbolTable{
public:
    SymbolTable();
    void PrettyPrint() { trans_unit->PrettyPrint(); }
    void awaitDecSpecs();//done
    void AssertTypedef();//done
    void AppendCachedDecSpecs();//done
    void clearDecSpecs();//done
    void PushDecSpec(std::string _specid);//done
    void AddPtrToCurrRecord();//done
    void AddArrayToCurrRecord(int _size);//done
    void AddFuncToCurrRecord();//done
    void StartParamDeclaration();//done
    void EndParamDeclaration();//done
    void EndFuncParams();//done
    void AddFuncRecordBody();
    void AddIDtoCurrRecord(std::string _id);//done
    void AddUnnamedtoCurrRecord();
    void StartNewFuncDef();//done
    void EndFuncDfDeclaration();
    void EndFuncDef();//done
    void StartNewDeclaration();//done
    void EndDeclaration();//done
    void NewScope();//done
    void PopScope();//done
    void NewDeclParts();
    void PopDeclParts();
    NamedRecord* GetIDRecord(const std::string& _ID);
    NamedRecord* GetActiveRecord();
    void DefocusFunc() { FuncDefIsFocus = false; }
    void FocusFunc() { FuncDefIsFocus = true; }
    bool IsCanonicalTypespec(const std::string& spec);
private:
    NamedRecord* SearchUp(const std::string& _ID, Table* scope);
    // std::stack<funcArgs*> funcargsStack;
    std::stack<std::vector<genericConstituentType*> > declPartsStack;
    void AccumulateDeclParts();
    std::stack<VariableDeclaration*> declarationStack;
    std::stack<std::vector<std::string> >decspecStack;
    Table* trans_unit;
    Table* ActiveScopePtr;
    FunctionDefinitionRec* ActiveFuncDefPtr;
    bool FuncDefIsFocus;
    NamedRecord* ActiveRecordPtr;
};

#endif