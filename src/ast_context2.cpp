#include "ast_context2.hpp"
#include <numeric> //accumulate
#include <iostream>
#include <algorithm>//copy_if
#include <regex>

unsigned int UniqueCtr(){
    static unsigned int a = 0;
    return a++;
}

//For pretty printing-----------
namespace prPr{
    int tabs = 0;
}
std::string prPr::genTabs(){
    std::string tabstr;
    for(int i = prPr::tabs; i!=0; i--){
        tabstr += "\t";
    }
    return tabstr;
}
void prPr::Tabsminus(){
    tabs--;
}
void prPr::Tabsplus(){
    tabs++;
}
void Table::PrettyPrint(){
    for (auto rec : subRecords){
        rec->PrettyPrint();
    }
}
void ParameterTable::PrettyPrint(){
    std::cout << prPr::genTabs() << "(" << std::endl;
    prPr::Tabsplus();
    for(auto param : subRecords){
        param->PrettyPrint();
    }
    prPr::Tabsminus();
    std::cout << prPr::genTabs() << ")" << std::endl;
}
void VariableDeclaration::PrettyPrint(){
    std::cout << prPr::genTabs() << id << /*" of depth " << GetDepth() <<*/ " is ";
    if(primaryPt!=NULL){
        primaryPt->Show();
    }
    else if(primaryArr!=NULL){
        primaryArr->Show();
    }
    else if(primaryFunc!=NULL){
        primaryFunc->Show();
    }
    else if(primaryTypespec!=NULL){
        primaryTypespec->Show();
    }
    else if(primaryStruct!=NULL){
        primaryStruct->Show();
    }
    else if(primaryEnum!=NULL){
        primaryEnum->Show();
    }
    else{
        std::cout << "error -> no type";
    }
    std::cout << std::endl;
}
void FunctionDefinitionRec::PrettyPrint(){
    std::cout << prPr::genTabs() << id << " is ";
    funcInfo->Show();
    std::cout << std::endl <<prPr::genTabs() << "{" << std::endl;
    prPr::Tabsplus();
    body->PrettyPrint();
    prPr::Tabsminus();
    std::cout << prPr::genTabs() << "}" << std::endl << std::endl;
}
void StructTypeDeclarationRec::PrettyPrint(){
    // std::cout << prPr::genTabs() << id << " is struct type definition with namespace:" << std::endl;
    // prPr::Tabsplus();
    // structDef->members->PrettyPrint();
    // prPr::Tabsminus();
}
// void EnumTypeDeclarationRec::PrettyPrint(){
//     std::cout << "With name " << id << ", ";
//     enumDef->Show();
// }
// void EnumConstDeclarationRec::PrettyPrint(){
//     data->Show();
// }

void functionType::Show(){
    std::cout << "function " << std::endl;
    arguments->PrettyPrint();
    std::cout << prPr::genTabs() << "that returns ";
    if(basetypeReturnType!=NULL){ basetypeReturnType->Show(); }
    else if(pointerReturnType!=NULL){ pointerReturnType->Show(); }
}
void arrayType::Show(){
    std::cout << "array (" << size << ")" << "of ";
    if(nextArray!=NULL){ nextArray->Show();}
    else if(pointerElementType!=NULL){ pointerElementType->Show(); }
    else if(basetypeElementType!=NULL){ basetypeElementType-> Show(); }
    else { std::cout << " error -> no base type"; }
}
void pointerType::Show(){
    std::cout << "pointer to ";
    if(ptToPointer!=NULL){ ptToPointer->Show(); }
    else if(ptToArray!=NULL){ ptToArray->Show(); }
    else if(ptToBasetype!=NULL){ ptToBasetype->Show(); }
    else if(ptToFunc!=NULL){ ptToFunc->Show(); }
    else if(ptToStruct!=NULL){ ptToStruct->Show(); }
    else{ std::cout << "error, pointer to nothing"; }
}
void typeSpecifiers::Show(){
    for(auto i : specs){
        std::cout << i << " ";
    }
}
void structType::Show(){
    std::cout << "struct with members" << std::endl;
    prPr::Tabsplus();
    members->PrettyPrint();
    prPr::Tabsminus();
}
void enumType::Show(){
    std::cout << "enum with options";
    for (auto option : options){
        option->Show();
        std::cout << " ";
    }
    std::cout << std::endl;
}
void enumConstType::Show(){
    std::cout << "(" << name << "," << value << ")";
}


//For adding types to chain

void functionType::AddNextType(typeSpecifiers* specs){
    basetypeReturnType = specs;
    pointerReturnType = NULL;
}void functionType::AddNextType(pointerType* point){
    basetypeReturnType = NULL;
    pointerReturnType = point;
}

void arrayType::AddNextType(arrayType* arr){
    nextArray = arr;
    pointerElementType = NULL;
    basetypeElementType = NULL;
    structElementType = NULL;
}void arrayType::AddNextType(pointerType* pnt){
    nextArray = NULL;
    pointerElementType = pnt;
    basetypeElementType = NULL;
    structElementType = NULL;
}void arrayType::AddNextType(typeSpecifiers* typ){
    nextArray = NULL;
    pointerElementType = NULL;
    basetypeElementType = typ;
    structElementType = NULL;
}void arrayType::AddNextType(structType* str){
    nextArray = NULL;
    pointerElementType = NULL;
    basetypeElementType = NULL;
    structElementType = str;
}

void pointerType::AddNextType(arrayType* arr){
    ptToPointer = NULL;
    ptToArray = arr;
    ptToBasetype = NULL;
    ptToFunc = NULL;
    ptToStruct = NULL;
    ptToEnum = NULL;
}void pointerType::AddNextType(pointerType* pnt){
    ptToPointer = pnt;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = NULL;
    ptToStruct = NULL;
    ptToEnum = NULL;
}void pointerType::AddNextType(typeSpecifiers* typ){
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = typ;
    ptToFunc = NULL;
    ptToStruct = NULL;
    ptToEnum = NULL;
}void pointerType::AddNextType(functionType* func){
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = func;
    ptToStruct = NULL;
    ptToEnum = NULL;
}void pointerType::AddNextType(structType* str){
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = NULL;
    ptToStruct = str;
    ptToEnum = NULL;
}void pointerType::AddNextType(enumType* en){
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = NULL;
    ptToStruct = NULL;
    ptToEnum = en;
}

void typeSpecifiers::AddNextType(std::string spec){
    specs.push_back(spec);
}

void functionType::BeAppended(genericConstituentType* other){ other->AddNextType(this); }
void functionType::BeAppended(VariableDeclaration* vardec){ vardec->AddPrimary(this);}
void functionType::BeAppended(FunctionDefinitionRec* funcdec){ funcdec->AddPrimary(this); }

void arrayType::BeAppended(genericConstituentType* other){ other->AddNextType(this); }
void arrayType::BeAppended(VariableDeclaration* vardec){ vardec->AddPrimary(this); }
void arrayType::BeAppended(FunctionDefinitionRec* funcdec){ funcdec->AddPrimary(this); }

void pointerType::BeAppended(genericConstituentType* other){ other->AddNextType(this); }
void pointerType::BeAppended(VariableDeclaration* vardec){ vardec->AddPrimary(this); }
void pointerType::BeAppended(FunctionDefinitionRec* funcdec){ funcdec->AddPrimary(this); }

void typeSpecifiers::BeAppended(genericConstituentType* other){ other->AddNextType(this); }
void typeSpecifiers::BeAppended(VariableDeclaration* vardec){ vardec->AddPrimary(this); }
void typeSpecifiers::BeAppended(FunctionDefinitionRec* funcdec){ funcdec->AddPrimary(this); }

void structType::BeAppended(genericConstituentType* other){other->AddNextType(this);}
void structType::BeAppended(pointerType* ptr){ptr->AddNextType(this);}
void structType::BeAppended(VariableDeclaration* vardec){ vardec->AddPrimary(this); }
void structType::BeAppended(StructTypeDeclarationRec* structDec){ structDec->AddPrimary(this);}
void structType::BeAppended(TypedefTypeDeclarationRec* typedefDec){ typedefDec->AddPrimary(this); }

void enumType::BeAppended(genericConstituentType* other){other->AddNextType(this);}
void enumType::BeAppended(pointerType* ptr){ ptr->AddNextType(this);}
void enumType::BeAppended(VariableDeclaration* vardec){vardec->AddPrimary(this);}
void enumType::BeAppended(TypedefTypeDeclarationRec* typedefDec){typedefDec->AddPrimary(this);}

std::vector<Record*>& functionType::ArgVec(){
    return arguments->subRecords;
}

unsigned int pointerType::ByteSize(){
    return 4;
}

unsigned int typeSpecifiers::ByteSize(){
    unsigned int size_count = 0;
    //float
    //char
    //signed
    //double
    //int
    for(auto spec : specs){
        if(spec == "int" | spec == "float") size_count += 4;
        else if(spec == "char") size_count += 1;
        else if(spec == "double") size_count += 8;
    }
    return size_count;
}

unsigned int arrayType::ByteSize(){
    if(nextArray!=NULL) return size*nextArray->ByteSize();
    else if(pointerElementType!=NULL) return size*pointerElementType->ByteSize();
    else if(basetypeElementType!=NULL) return size*basetypeElementType->ByteSize();
    else if(structElementType!=NULL) return size*structElementType->ByteSize();
}

unsigned int functionType::ByteSize(){
    unsigned int size_count = 0;
    for(auto arg : ArgVec()){
        size_count += arg->DeclarationSize();
    }
    return size_count;
}

unsigned int structType::ByteSize(){
    unsigned int sum = 0;
    for(auto rec : members->subRecords){
        sum += rec->DeclarationSize();
    }
}

unsigned int enumType::ByteSize(){
    return 4;
}
unsigned int enumConstType::ByteSize(){
    return 4;
}
//--------------------
void VariableDeclaration::AddPrimary(pointerType* _primaryPt){
    primaryPt = _primaryPt;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = NULL;
    primaryStruct = NULL;
    primaryEnum = NULL;
}
void VariableDeclaration::AddPrimary(arrayType* _primaryArr){
    primaryPt = NULL;
    primaryArr = _primaryArr;
    primaryFunc = NULL;
    primaryTypespec = NULL;
    primaryStruct = NULL;
    primaryEnum = NULL;
}
void VariableDeclaration::AddPrimary(functionType* _primaryFunc){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = _primaryFunc;
    primaryTypespec = NULL;
    primaryStruct = NULL;
    primaryEnum = NULL;
}
void VariableDeclaration::AddPrimary(typeSpecifiers* _primaryTypespec){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = _primaryTypespec;
    primaryStruct = NULL;
    primaryEnum = NULL;
}
void VariableDeclaration::AddPrimary(structType* _primarystruct){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = NULL;
    primaryStruct = _primarystruct;
    primaryEnum = NULL;
}
void VariableDeclaration::AddPrimary(enumType* _primaryenum){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = NULL;
    primaryStruct = NULL;
    primaryEnum = _primaryenum;
}

void TypedefTypeDeclarationRec::AddPrimary(pointerType* _PtrDef){
    pointerType* PtrDef = _PtrDef;
    arrayType* ArrDef = NULL;
    functionType* FuncDef = NULL;
    structType* StructDef = NULL;
    typeSpecifiers* BasetypeDef = NULL;
    enumDef = NULL;
}
void TypedefTypeDeclarationRec::AddPrimary(arrayType* _ArrDef){
    pointerType* PtrDef = NULL;
    arrayType* ArrDef = _ArrDef;
    functionType* FuncDef = NULL;
    structType* StructDef = NULL;
    typeSpecifiers* BasetypeDef = NULL;
    enumDef = NULL;
}
void TypedefTypeDeclarationRec::AddPrimary(functionType* _FuncDef){
    pointerType* PtrDef = NULL;
    arrayType* ArrDef = NULL;
    functionType* FuncDef = _FuncDef;
    structType* StructDef = NULL;
    typeSpecifiers* BasetypeDef = NULL;
    enumDef = NULL;
}
void TypedefTypeDeclarationRec::AddPrimary(structType* _StructDef){
    pointerType* PtrDef = NULL;
    arrayType* ArrDef = NULL;
    functionType* FuncDef = NULL;
    structType* StructDef = _StructDef;
    typeSpecifiers* BasetypeDef = NULL;
    enumDef = NULL;
}
void TypedefTypeDeclarationRec::AddPrimary(typeSpecifiers* _BasetypeDef){
    pointerType* PtrDef = NULL;
    arrayType* ArrDef = NULL;
    functionType* FuncDef = NULL;
    structType* StructDef = NULL;
    typeSpecifiers* BasetypeDef = _BasetypeDef;
    enumDef = NULL;
}
void TypedefTypeDeclarationRec::AddPrimary(enumType* enType){
    pointerType* PtrDef = NULL;
    arrayType* ArrDef = NULL;
    functionType* FuncDef = NULL;
    structType* StructDef = NULL;
    typeSpecifiers* BasetypeDef = NULL;;
    enumDef = enType;
}

void FunctionDefinitionRec::AddPrimary(functionType* _Func){
    funcInfo = _Func;
}

genericConstituentType* VariableDeclaration::GetPrimary(){
    if(primaryPt!=NULL) return primaryPt;
    else if(primaryArr!=NULL) return primaryArr;
    else if(primaryFunc!=NULL) return primaryFunc;
    else if(primaryTypespec!=NULL) return primaryTypespec;
    else throw("variable record has no info!");
}

unsigned int VariableDeclaration::GetDepth(){
    Record* traverser = parentTable;
    unsigned int depth = 0;
    while(traverser!=NULL){
        depth++;
        traverser = traverser->parentTable;
    }
    return depth - 1;
}

bool VariableDeclaration::IsGlobal(){
    return GetDepth() == 0;
}
genericConstituentType* FunctionDefinitionRec::GetPrimary(){
    if(funcInfo!=NULL) return funcInfo;
    else throw("func record has no info!");
}

std::vector<Record*>::iterator FunctionDefinitionRec::ArgsBegin(){
    return funcInfo->ArgVec().begin();
}
std::vector<Record*>::iterator FunctionDefinitionRec::ArgsEnd(){
    return funcInfo->ArgVec().end();
}
unsigned int FunctionDefinitionRec::NumArgs(){
    return funcInfo->ArgVec().size();
}

genericConstituentType* StructTypeDeclarationRec::GetPrimary(){
    return structDef;
}

genericConstituentType* EnumTypeDeclarationRec::GetPrimary(){
    return enumDef;
}

genericConstituentType* EnumConstDeclarationRec::GetPrimary(){
    return data;
}


//---------------------


SymbolTable::SymbolTable(){
    trans_unit = new Table(NULL);
    ActiveScopePtr = trans_unit;

    declarationStack.push(NULL);//so never empty completely
    ActiveRecordPtr = declarationStack.top();

    ActiveFuncDefPtr = NULL;
}

void SymbolTable::NewDeclParts(){
    declPartsStack.push(std::vector<genericConstituentType*>());
}
void SymbolTable::PopDeclParts(){
    declPartsStack.pop();
}

void SymbolTable::NewScope(){
    Table* newScope = new Table(ActiveScopePtr);
    ActiveScopePtr->subRecords.push_back(newScope);
    ActiveScopePtr = newScope;
}

void SymbolTable::PopScope(){
    ActiveScopePtr = ActiveScopePtr->parentTable;
}

void SymbolTable::StartNewDeclaration(){
    NewDeclParts();
    VariableDeclaration* dec = new VariableDeclaration(ActiveScopePtr);
    ActiveRecordPtr = dec;
    declarationStack.push(dec);
}

void SymbolTable::awaitDecSpecs(){
    decspecStack.push(std::vector<std::string>());
}

void SymbolTable::clearDecSpecs(){
    decspecStack.pop();
}

void SymbolTable::PushDecSpec(std::string _specid){
    decspecStack.top().push_back(_specid);
}

void SymbolTable::EndDeclaration(){
    //declarationStack.top()->AddPrimary(AccumulateDeclParts());
    AccumulateDeclParts();
    ActiveScopePtr->subRecords.push_back(declarationStack.top());
    
    declarationStack.pop();
    ActiveRecordPtr = declarationStack.top();
    PopDeclParts();
}

void SymbolTable::AddArrayToCurrRecord(int size){
    declPartsStack.top().push_back(new arrayType(size));
}

void SymbolTable::AddIDtoCurrRecord(std::string _id){
    if(FuncDefIsFocus){
        ActiveFuncDefPtr->SetName(_id);
        DefocusFunc();
    }
    else{
        ActiveRecordPtr->SetName(_id);
    }
}

void SymbolTable::AddUnnamedtoCurrRecord(){
    AddIDtoCurrRecord("");
}

void SymbolTable::AssertTypedef(){
    ActiveRecordPtr->isTypedef=true;
}

bool SymbolTable::IsCanonicalTypespec(const std::string& spec){
    static const std::string match = "void|char|short|int|long|float|double|signed|unsigned";
    static const std::regex reg(match);
    return std::regex_match(spec, reg);
}

void SymbolTable::AppendCachedDecSpecs(){
    typeSpecifiers* specs = new typeSpecifiers;
    //deep copy
    std::vector<std::string> filteredspecs;
    for(auto spec : decspecStack.top()){
        if(spec == "typedef") AssertTypedef();
        else{
            if(!IsCanonicalTypespec(spec)){
                //this should work for structs too?
                genericConstituentType* dec = GetIDRecord(spec)->GetPrimary();
                declPartsStack.top().push_back(dec);
                //TODO The above currently shallow copies the linked list
                //!Two owners to the linked list!
            }
            else{
                filteredspecs.push_back(spec);
            }
        }
    }
    // if(filteredspecs.size() != decspecStack.top().size()){ AssertTypedef(); }
    specs->specs = filteredspecs;
    declPartsStack.top().push_back(specs);
}

void SymbolTable::AddPtrToCurrRecord(){
    declPartsStack.top().push_back(new pointerType);
}

//adds functiontype part to declparts
//creates new param table
//switches current scope to param table

//!MUST BE FOLLOWED BY END PARAMS()
void SymbolTable::AddFuncToCurrRecord(){
    functionType* newFunc = new functionType;
    
    declPartsStack.top().push_back(newFunc);
    
    ParameterTable* params = new ParameterTable(ActiveScopePtr);
    newFunc->arguments = params;
    ActiveScopePtr = params;
}

void SymbolTable::StartParamDeclaration(){
    StartNewDeclaration();
}
void SymbolTable::EndParamDeclaration(){
    EndDeclaration();
    
}
void SymbolTable::EndFuncParams(){
    ActiveScopePtr = ActiveScopePtr->parentTable;
    
}

void SymbolTable::StartNewFuncDef(){
    NewDeclParts();
    FunctionDefinitionRec* def = new FunctionDefinitionRec;
    ActiveFuncDefPtr = def;
    FocusFunc();
    //no nested function definitions in c90 so this is ok
    //no need to push to a stack
}

void SymbolTable::AddFuncRecordBody(){
    if(ActiveFuncDefPtr==NULL){ throw "uh oh, 2"; }
    else{
        ActiveFuncDefPtr->body = new Table(ActiveFuncDefPtr->funcInfo->arguments);
        ActiveScopePtr = ActiveFuncDefPtr->body;
    }
}

void SymbolTable::EndFuncDfDeclaration(){
    // 
    // genericConstituentType* parts = AccumulateDeclParts();
    // 
    // ActiveFuncDefPtr->AddPrimary(parts);
    // 
    FocusFunc();
    
    AccumulateDeclParts();
    
    PopDeclParts();
    DefocusFunc();
}

void SymbolTable::EndFuncDef(){
    // go up through the parameter table
    ActiveScopePtr = ActiveScopePtr->parentTable->parentTable;
    ActiveScopePtr->subRecords.push_back(ActiveFuncDefPtr);
    ActiveFuncDefPtr = NULL;
}

NamedRecord* SymbolTable::GetActiveRecord(){
    if(FuncDefIsFocus){
        return ActiveFuncDefPtr;
    }
    else{
        return ActiveRecordPtr;
    }
}

void SymbolTable::StartNewStructDeclaration(){
    //new struct record
    StructTypeDeclarationRec* rec = new StructTypeDeclarationRec(ActiveScopePtr);
    //add to struct stack
    structDecStack.push(rec);
    //set it to be the active record
    ActiveRecordPtr = rec;
    //add the type part that describes it
    rec->structDef = new structType;
    //add the table that holds the member decs
    rec->structDef->members = new nsTable(ActiveScopePtr);
    //switch scope to this table
    ActiveScopePtr = rec->structDef->members;
}
void SymbolTable::EndStructDeclaration(){
    ActiveScopePtr = ActiveScopePtr->parentTable;
    ActiveScopePtr->GetScope()->subRecords.push_back(structDecStack.top());
    structDecStack.pop();
    if(structDecStack.size() > 0) ActiveRecordPtr = structDecStack.top();
    else ActiveRecordPtr = declarationStack.top();

}

void SymbolTable::StartNewEnumDeclaration(const std::string& name){
    EnumTypeDeclarationRec* rec = new EnumTypeDeclarationRec(ActiveScopePtr);
    ActiveEnumPtr = rec;
    rec->SetName(name);
    ActiveScopePtr->GetScope()->subRecords.push_back(rec);
}

void SymbolTable::AddEnumerator(const std::string& name, int value){
    EnumConstDeclarationRec* constrec = new EnumConstDeclarationRec(ActiveScopePtr->GetScope(),ActiveEnumPtr,value);
    constrec->SetName(name);
    ActiveEnumPtr->enumDef->options.push_back(constrec->data);
    ActiveScopePtr->GetScope()->subRecords.push_back(constrec);
}

void SymbolTable::AddEnumerator(const std::string& name){
    int last_val;
    if(ActiveEnumPtr->enumDef->options.size()!=0)
    {
        last_val = ActiveEnumPtr->enumDef->options.back()->value;
    }
    else{
        last_val = -1;
    }
    AddEnumerator(name,last_val+1);
}

void SymbolTable::EndEnumDeclaration(){
    ActiveEnumPtr = NULL;
}
// void SymbolTable::AddStructRecToCurrRecord(const std::string& tag){
//     NamedRecord* structResult = GetIDRecord("struct " + tag);
//     //declPartsStack.top().push_back(structResult->GetPrimary());
//     // change decspec stack to have a vector of a container struct
//     // that can contain either a string, struct spec or enum spec
// }
//-----------------------------------
void SymbolTable::AccumulateDeclParts(){
    // if (declPartsStack.top().size() == 1){
    //     return declPartsStack.top()[0];
    // }
    // else{
        // genericConstituentType* tmp = NULL;//workaround for accumulate
        std::vector<genericConstituentType*> decls = declPartsStack.top();
        
        // genericConstituentType* top = std::accumulate(decls.rbegin(),decls.rend(), tmp,
        //     [](genericConstituentType* left, genericConstituentType* right){
        //         std::cout << "accumulating" << std::endl;
        //         left->AddNextType(right);
        //         return left;
        //     }
        // );
        genericConstituentType* acc = NULL;
        // for(auto i = decls.rbegin(); i < decls.rend(); i++){
        //             //     (*i)->AddNextType(acc);
        //     acc = *i;
            
        // }
        for(int i = decls.size() - 1; i > 0; i--){
            decls[i]->BeAppended(decls[i-1]);
        }
    
    // }
    if(FuncDefIsFocus){
        decls[0]->BeAppended(ActiveFuncDefPtr);
    }
    else{
        
        decls[0]->BeAppended(declarationStack.top());
        
        // declarationStack.top()->AddPrimary(decls[0]);
    }
    

}

NamedRecord* SymbolTable::GetIDRecord(const std::string& _ID){
    return SearchUp(_ID, ActiveScopePtr);
}

NamedRecord* SymbolTable::SearchUp(const std::string& _ID, Table* scope){
    for(auto i = scope->subRecords.rbegin(); i < scope->subRecords.rend(); i++){
        if((*i)->hasID(_ID)) return static_cast<NamedRecord*>(*i); //only named records have names -> less overhead than dynamic cast
    }
    if(scope->parentTable!=NULL){
        return SearchUp(_ID, scope->parentTable);
    }
    else{
        return NULL;//not found :(
    }
}