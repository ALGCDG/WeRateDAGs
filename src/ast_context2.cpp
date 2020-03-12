#include "ast_context2.hpp"
#include <numeric> //accumulate

SymbolTable::SymbolTable(){
    Data = new Table(ActiveScope);
    ActiveScope = Data;

    declarationStack.push(NULL);//so never empty completely
    ActiveRecord = declarationStack.top();
}

void SymbolTable::NewScope(){
    Table* newScope = new Table(ActiveScope);
    ActiveScope->subRecords.push_back(newScope);
    ActiveScope = newScope;
}

void SymbolTable::PopScope(){
    ActiveScope = ActiveScope->parentTable;
}

void SymbolTable::StartNewDeclaration(){
    VariableDeclaration* dec = new VariableDeclaration();
    ActiveRecord = dec;
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
    ActiveScope->subRecords.push_back(declarationStack.top());
    declarationStack.pop();
    ActiveRecord = declarationStack.top();
}

void SymbolTable::AddArrayToCurrRecord(int size){
    declPartsStack.top().push_back(new arrayType(size));
}

void SymbolTable::AddIDtoCurrRecord(std::string _id){
    ActiveRecord->SetName(_id);
}

void SymbolTable::AssertTypedef(){
    ActiveRecord->isTypedef=true;
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
    ParameterTable* params = new ParameterTable(ActiveScope);
    ActiveScope = params;
}

void SymbolTable::StartParamDeclaration(){
    StartNewDeclaration();
}
void SymbolTable::EndParamDeclaration(){
    EndDeclaration();
}
void SymbolTable::EndFuncParams(){
    ActiveScope = ActiveScope->parentTable;
}

void SymbolTable::StartNewFuncDef(){
    FunctionDefinition* def = new FunctionDefinition;
    ActiveFuncDef = def;
    //no nested function definitions in c90 so this is ok
    //no need to push to a stack
}

void SymbolTable::AddFuncRecordBody(){
    if(ActiveFuncDef==NULL){ throw "uh oh, 2"; }
    else{
        ActiveFuncDef->body = new Table(ActiveFuncDef->funcInfo->arguments);
        ActiveScope = ActiveFuncDef->body;
    }
}

void SymbolTable::EndFuncDef(){
    // go up through the parameter table
    ActiveScope = ActiveScope->parentTable->parentTable;
    ActiveFuncDef->AddPrimary(AccumulateDeclParts());
    ActiveScope->subRecords.push_back(ActiveFuncDef);
    ActiveFuncDef = NULL;
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

