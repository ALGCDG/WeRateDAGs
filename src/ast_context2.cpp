#include "ast_context2.hpp"
#include <numeric> //accumulate
#include <iostream>
#include <algorithm>//copy_if

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
    std::cout << prPr::genTabs() << id << " is ";
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
    std::cout << prPr::genTabs() << "}" << std::endl << std::endl;;
}
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
    else{ std::cout << "error, pointer to nothing"; }
}
void typeSpecifiers::Show(){
    for(auto i : specs){
        std::cout << i << " ";
    }
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
}void arrayType::AddNextType(pointerType* pnt){
    
    nextArray = NULL;
    pointerElementType = pnt;
    basetypeElementType = NULL;
}void arrayType::AddNextType(typeSpecifiers* typ){
    
    nextArray = NULL;
    pointerElementType = NULL;
    basetypeElementType = typ;
}

void pointerType::AddNextType(arrayType* arr){
    
    ptToPointer = NULL;
    ptToArray = arr;
    ptToBasetype = NULL;
    ptToFunc = NULL;
}void pointerType::AddNextType(pointerType* pnt){
    
    ptToPointer = pnt;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = NULL;
}void pointerType::AddNextType(typeSpecifiers* typ){
    
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = typ;
    ptToFunc = NULL;
}void pointerType::AddNextType(functionType* func){
    
    ptToPointer = NULL;
    ptToArray = NULL;
    ptToBasetype = NULL;
    ptToFunc = func;
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

//--------------------
void VariableDeclaration::AddPrimary(pointerType* _primaryPt){
    primaryPt = _primaryPt;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = NULL;
}
void VariableDeclaration::AddPrimary(arrayType* _primaryArr){
    primaryPt = NULL;
    primaryArr = _primaryArr;
    primaryFunc = NULL;
    primaryTypespec = NULL;
}
void VariableDeclaration::AddPrimary(functionType* _primaryFunc){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = _primaryFunc;
    primaryTypespec = NULL;
}
void VariableDeclaration::AddPrimary(typeSpecifiers* _primaryTypespec){
    primaryPt = NULL;
    primaryArr = NULL;
    primaryFunc = NULL;
    primaryTypespec = _primaryTypespec;
}
void FunctionDefinitionRec::AddPrimary(functionType* _Func){
    funcInfo = _Func;
}
//---------------------


SymbolTable::SymbolTable(){
    trans_unit = new Table(ActiveScopePtr);
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
    VariableDeclaration* dec = new VariableDeclaration();
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

}

void SymbolTable::AppendCachedDecSpecs(){
    typeSpecifiers* specs = new typeSpecifiers;
    //deep copy
    std::vector<std::string> filteredspecs;
    for(auto spec : decspecStack.top()){
        if(spec == "typedef") AssertTypedef();
        else{
            // if(!IsCanonicalTypespec(spec)){
            //     VariableDeclaration* dec = static_cast<VariableDeclaration*>(GetIDRecord(spec));
                
            // }
            filteredspecs.push_back(spec);
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