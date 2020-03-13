#include "ast_context2.hpp"
#include <numeric> //accumulate

SymbolTable::SymbolTable(){
    trans_unit = new Table(ActiveScopePtr);
    ActiveScopePtr = trans_unit;

    declarationStack.push(NULL);//so never empty completely
    ActiveRecordPtr = declarationStack.top();
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
    declarationStack.top()->AddPrimary(AccumulateDeclParts());
    ActiveScopePtr->subRecords.push_back(declarationStack.top());
    declarationStack.pop();
    ActiveRecordPtr = declarationStack.top();
}

void SymbolTable::AddArrayToCurrRecord(int size){
    declPartsStack.top().push_back(new arrayType(size));
}

void SymbolTable::AddIDtoCurrRecord(std::string _id){
    ActiveRecordPtr->SetName(_id);
}

void SymbolTable::AssertTypedef(){
    ActiveRecordPtr->isTypedef=true;
}

void SymbolTable::AppendCachedDecSpecs(){
    typeSpecifiers* specs = new typeSpecifiers;
    //deep copy
    specs->specs = std::vector<std::string>(decspecStack.top());
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
    FunctionDefinition* def = new FunctionDefinition;
    ActiveFuncDefPtr = def;
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

void SymbolTable::EndFuncDef(){
    // go up through the parameter table
    ActiveScopePtr = ActiveScopePtr->parentTable->parentTable;
    ActiveFuncDefPtr->AddPrimary(AccumulateDeclParts());
    ActiveScopePtr->subRecords.push_back(ActiveFuncDefPtr);
    ActiveFuncDefPtr = NULL;
}

genericConstituentType* SymbolTable::AccumulateDeclParts(){
    if (declPartsStack.top().size() == 1){
        return declPartsStack.top()[0];
    }
    else{
        genericConstituentType* tmp = NULL;//workaround for accumulate
        std::vector<genericConstituentType*> decls = declPartsStack.top();
        genericConstituentType* top = std::accumulate(decls.begin(),decls.end(), tmp,
            [](auto left, auto right){
                left->AddNextType(right);
                return left;
            }
        );
        return decls[0];
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

