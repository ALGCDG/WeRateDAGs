#include "ast_context.hpp"

ContextTable* ContextTable::Instance(){
    //only one instance of context table
    static 
    return table_instance;
}


//TODO redo for new vector based context table
void ContextTable::NewScope(){
    
    Context::ScopeRecord* newScopeTable = new Context::ScopeRecord(currParentScopePtr);
    if(currParentScopePtr==NULL){
        table_data.push_back(newScopeTable);
    }
    else{
        currParentScopePtr->SubTable.push_back(newScopeTable);
    }
    currParentScopePtr = newScopeTable;
    
}

void ContextTable::PopScope(){
    currParentScopePtr=currParentScopePtr->parent;
}

void ContextTable::AddNamedRecord(Context::NamedRecord* _rec){
    
}


void ContextTable::AddToActiveTable(Context::Record* _rec){
    if(currParentScopePtr == NULL) table_data.push_back(_rec);
    else{ currParentScopePtr->SubTable.push_back(_rec); }
}

Context::ScopeRecord* ContextTable::GetCurrParentScopePtr(){
    return currParentScopePtr;
}