#ifndef AST_CONT2_HPP
#define AST_CONT2_HPP

#include <vector>
#include <string>
#include <stack>
#include <iostream>

struct typeSpecifiers;
struct ParameterTable;
struct Table;
struct arrayType;
struct pointerType;
struct functionType;
struct VariableDeclaration;
struct FunctionDefinitionRec;
struct StructTypeDeclarationRec;
struct TypedefTypeDeclarationRec;
struct structType;
struct enumType;
namespace prPr{
    extern int tabs;
    void Tabsplus();
    void Tabsminus();
    std::string genTabs();
}

struct genericConstituentType{
    virtual void BeAppended(genericConstituentType* other){}
    virtual void BeAppended(VariableDeclaration* vardec){}
    virtual void BeAppended(FunctionDefinitionRec* funcdec){}
    virtual void AddNextType(typeSpecifiers* specs){}
    virtual void AddNextType(functionType* func){}
    virtual void AddNextType(arrayType* arr){}
    virtual void AddNextType(pointerType* point){}
    virtual void AddNextType(structType* str){}
    virtual void AddNextType(enumType* en){}
    virtual void Show(){}
    virtual unsigned int ByteSize() = 0;
};
struct Record;
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
    std::vector<Record*>& ArgVec();
    unsigned int ByteSize() override;
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
    void AddNextType(structType* str) override;

    arrayType* nextArray;
    pointerType* pointerElementType;
    typeSpecifiers* basetypeElementType;
    structType* structElementType;//TODO fix append to make this null when appropriate
    void Show();
    unsigned int ByteSize() override;
};

struct pointerType : public genericConstituentType{
    void BeAppended(genericConstituentType* other) override;
    void BeAppended(VariableDeclaration* vardec) override;
    void BeAppended(FunctionDefinitionRec* funcdec) override;
    void AddNextType(arrayType* arr) override;
    void AddNextType(pointerType* pnt) override;
    void AddNextType(typeSpecifiers* typ) override;
    void AddNextType(functionType* func) override;
    void AddNextType(structType* str) override;
    void AddNextType(enumType* en) override;
    pointerType* ptToPointer;
    arrayType* ptToArray;
    typeSpecifiers* ptToBasetype;
    functionType* ptToFunc;
    structType* ptToStruct;
    enumType* ptToEnum;
    void Show();
    unsigned int ByteSize() override;
};

struct typeSpecifiers : public genericConstituentType{
    void BeAppended(genericConstituentType* other);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(FunctionDefinitionRec* funcdec);
    std::vector<std::string> specs;
    void AddNextType(std::string spec);
    void Show();
    unsigned int ByteSize() override;
};

struct nsTable;
struct structType : public genericConstituentType{
    nsTable* members;
    void BeAppended(genericConstituentType* other);
    void BeAppended(pointerType* ptr);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(StructTypeDeclarationRec* structDec);
    void BeAppended(TypedefTypeDeclarationRec* typedefDec);
    unsigned int ByteSize() override;
    void Show();
};

struct enumConstType : public genericConstituentType{
    enumConstType(int val):value(val){}
    int value;
    std::string name;
    unsigned int ByteSize() override;
    void Show();
};
struct enumType : public genericConstituentType{
    enumType(){}
    std::vector<enumConstType*> options;
    void BeAppended(genericConstituentType* other);
    void BeAppended(pointerType* ptr);
    void BeAppended(VariableDeclaration* vardec);
    void BeAppended(TypedefTypeDeclarationRec* typedefDec);
    unsigned int ByteSize();
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
    virtual void PrettyPrint(){}
    virtual unsigned int DeclarationSize(){ return 0; }
    bool isTypedef = false;
    Table* parentTable;
};

struct Table : public Record{
    Table(Table* _parentTable) : Record(_parentTable){}
    std::vector<Record*> subRecords;
    void PrettyPrint() override;
    virtual Table* GetScope(){ return this;}
};

//mainly for structs?
struct nsTable : public Table{
    nsTable(Table* _parent) : Table(_parent){}
    //void PrettyPrint() override;
    //struct namespaces don't introduce new scopes 
    // whenever a new type is introduced insif 
    Table* GetScope() override { return parentTable; }
};

struct ParameterTable : public Table{
    ParameterTable(Table* _parentTable) : Table(_parentTable){}
    void PrettyPrint() override;
};

unsigned int UniqueCtr();

struct NamedRecord : public Record{
    NamedRecord(){}
    NamedRecord(Table* _parent) : Record(_parent){}
    bool hasID(const std::string& _id) override { return _id == id; }
    //use this to check on receipt of named record which type it is
    // virtual bool isFunctionDefinition(){ return false; }
    virtual void SetName(const std::string& _id){ id = _id; unique_id = _id + std::to_string(UniqueCtr()); }
    std::string id;
    std::string unique_id;
    virtual genericConstituentType* GetPrimary() = 0;
    virtual unsigned int GetSize() = 0; //TODO
};

struct VariableDeclaration : public NamedRecord{
    VariableDeclaration(Table* _parent) : NamedRecord(_parent){ }
    // bool isFunctionDefinition(){ return false; }
    //sets all others to null explicitly
    void AddPrimary(genericConstituentType* _generic){}
    void AddPrimary(pointerType* _primaryPt);
    void AddPrimary(arrayType* _primaryArr);
    void AddPrimary(functionType* _primaryFunc);
    void AddPrimary(typeSpecifiers* _primaryTypespec);
    void AddPrimary(structType* _primarystruct);
    void AddPrimary(enumType* _primaryenum);
    //can be only one of the below
    pointerType* primaryPt;
    arrayType* primaryArr;
    functionType* primaryFunc;
    typeSpecifiers* primaryTypespec;
    structType* primaryStruct;
    enumType* primaryEnum;
    bool IsGlobal();
    unsigned int GetDepth();
    genericConstituentType* GetPrimary() override;
    void PrettyPrint() override;
    unsigned int DeclarationSize(){ GetPrimary()->ByteSize(); }
};


struct FunctionDefinitionRec : public NamedRecord{
    FunctionDefinitionRec(){}
    // bool isFunctionDefinition(){ return true; }
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
    std::vector<Record*>::iterator ArgsBegin();
    std::vector<Record*>::iterator ArgsEnd();
    unsigned int NumArgs();
};


struct TypeDeclarationRec : public NamedRecord{
    TypeDeclarationRec(){}
    TypeDeclarationRec(Table* parent) : NamedRecord(parent){}
};
struct StructTypeDeclarationRec : public TypeDeclarationRec{
    StructTypeDeclarationRec(Table* parent) : TypeDeclarationRec(parent){}
    structType* structDef;
    void AddPrimary(structType* _strdef){ structDef = _strdef; }
    genericConstituentType* GetPrimary() override;
    void PrettyPrint() override;
};
struct EnumTypeDeclarationRec : public TypeDeclarationRec{
    EnumTypeDeclarationRec(Table* parent) : TypeDeclarationRec(parent){
        enumDef = new enumType;
    }
    enumType* enumDef;
    genericConstituentType* GetPrimary() override;
    // void PrettyPrint() override;
};
struct EnumConstDeclarationRec : public NamedRecord{
    EnumConstDeclarationRec(Table* parent, EnumTypeDeclarationRec* _parentenum, int value) : NamedRecord(parent), parentEnum(_parentenum){
        data = new enumConstType(value);
    }
    void SetParentEnum(EnumTypeDeclarationRec* rec){ parentEnum = rec; }
    bool hasID(const std::string& _id) override { return data->name == _id; }
    void SetName(const std::string& name) override {data->name = name; NamedRecord::SetName(name); }
    EnumTypeDeclarationRec* parentEnum;
    enumConstType* data;
    genericConstituentType* GetPrimary() override;
    //void PrettyPrint() override;
};
struct TypedefTypeDeclarationRec : public TypeDeclarationRec{
    TypedefTypeDeclarationRec(Table* parent) : TypeDeclarationRec(parent){}
    //type parts pointers here
    pointerType* PtrDef;
    arrayType* ArrDef;
    functionType* FuncDef;
    structType* StructDef;
    typeSpecifiers* BasetypeDef;
    enumType* enumDef;
    void AddPrimary(pointerType* PtrDef);
    void AddPrimary(arrayType* ArrDef);
    void AddPrimary(functionType* FuncDef);
    void AddPrimary(structType* StructDef);
    void AddPrimary(typeSpecifiers* BasetypeDef);
    void AddPrimary(enumType* enType);
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
    void NewDeclParts();//done
    void PopDeclParts();//done

    void StartNewStructDeclaration();//done
    void EndStructDeclaration();//done
    // void AddStructRecToCurrRecord(const std::string& tag);    

    void AddEnumerator(const std::string& name, int value);
    void AddEnumerator(const std::string& name);
    void StartNewEnumDeclaration(const std::string& name);
    void EndEnumDeclaration();
    

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
    std::stack<StructTypeDeclarationRec*> structDecStack;
    std::stack<std::vector<std::string> >decspecStack;
    Table* trans_unit;
    Table* ActiveScopePtr;
    FunctionDefinitionRec* ActiveFuncDefPtr;
    bool FuncDefIsFocus;
    NamedRecord* ActiveRecordPtr;
    EnumTypeDeclarationRec* ActiveEnumPtr;
};

#endif