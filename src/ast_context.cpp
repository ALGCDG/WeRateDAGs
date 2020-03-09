#include "ast_context.hpp"

namespace ContextData
{
    void Record::SetParent(ScopeRecord* _parent){
        parent = _parent;
    }

    ScopeRecord* Record::GetParent(){
        return parent;
    }

    //adds record to scope record type only, not global :(
    void ScopeRecord::AddRecord(Record* _rec){
        SubTable.push_back(_rec);
    }

    void IDPart::AddChild(typePart* _child){
        definedToBe = _child;
    }

    void pointerPart::AddChild(typePart* _child){
        pointerTo = _child;
    }

    //argpart

    void funcPart::AddChild(typePart* _child){
        returns = _child;
    }

    void arrayPart::AddChild(typePart* _child){
        ofType = _child;
    }

    void baseSpecPart::AddChild(baseSpecPart* _child){
        otherSpecs = _child;
    }

}



void ContextTable::NewScope(){
    ContextData::ScopeRecord* newScopeTable = new ContextData::ScopeRecord();
    newScopeTable->SetParent(currParentScopePtr);
    AddToActiveTable(newScopeTable);
    currParentScopePtr = newScopeTable;
}

void ContextTable::PopScope(){
    currParentScopePtr=currParentScopePtr->GetParent();//step up one level
}

void ContextTable::AddObjectRecord(ContextData::NamedRecord* _rec){
    AddToActiveTable(_rec);
}

void ContextTable::AddToActiveTable(ContextData::Record* _rec){
    if(currParentScopePtr == NULL) table_data.push_back(_rec);
    else{ currParentScopePtr->AddRecord(_rec); }
}

std::vector<ContextData::Record*>& ContextTable::GetActiveTable(){
    if(currParentScopePtr == NULL) return table_data;
    else{ return currParentScopePtr->SubTable; }
}

ContextData::Record* ContextTable::FindNameInActiveTable(const std::string& _name){
    std::vector<ContextData::Record*> currTable = GetActiveTable();
    auto result = std::find_if(currTable.rbegin(), currTable.rend(), [&_name](ContextData::Record* entry)
        { 
            return *(entry->Name()) == _name;
        }
    );
    if (result != currTable.rend()){ return (*result); }
    else { return NULL; }
}

ContextData::Record* ContextTable::GetObjectRecord(const std::string& _ID){
    ContextData::ScopeRecord* backupPtr = currParentScopePtr;
    bool end = false;
    while(!end){
        end = (currParentScopePtr==NULL);
        auto result = FindNameInActiveTable(_ID);
        if (result != NULL){ 
            currParentScopePtr=backupPtr;
            return result; 
        }
        else{
            currParentScopePtr=currParentScopePtr->GetParent();
        }
    }
    currParentScopePtr=backupPtr;
    return NULL;
}
