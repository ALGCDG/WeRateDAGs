#include "ast_context.hpp"

namespace ContextData
{
    void Record::SetScopeParent(ScopeRecord* _parent){
        parent = _parent;
    }

    ScopeRecord* Record::GetParent(){
        return parent;
    }

    //adds record to scope record type only, not global :(
    void ScopeRecord::AddRecord(Record* _rec){
        SubTable.push_back(_rec);
    }
    std::vector<Record*>& ScopeRecord::GetSubTable(){
        return SubTable;
    }

    std::vector<Record*>& FunctionScopeRecord::GetSubTable(){
        //gets parameters and creates a new vector
        //with those parameters at the start of the decls
        std::vector<Record*> paramDecls = declaration->exposeNamedParams();
        paramDecls.insert(paramDecls.end(), SubTable.begin(), SubTable.end());
        return paramDecls;
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
    newScopeTable->SetScopeParent(currScopePtr);
    AddToActiveTable(newScopeTable);
    currScopePtr = newScopeTable;
}

void ContextTable::PopScope(){
    currScopePtr=currScopePtr->GetParent();//step up one level
}

void ContextTable::AddObjectRecord(ContextData::NamedRecord* _rec){
    AddToActiveTable(_rec);
}

void ContextTable::AddToActiveTable(ContextData::Record* _rec){
    if(currScopePtr == NULL) table_data.push_back(_rec);
    else{ currScopePtr->AddRecord(_rec); }
}

std::vector<ContextData::Record*>& ContextTable::GetActiveTable(){
    if(currScopePtr == NULL) return table_data;
    else{ return currScopePtr->GetSubTable(); }
}

ContextData::Record* ContextTable::FindNameInActiveTable(const std::string& _name){
    std::vector<ContextData::Record*> currTable = GetActiveTable();
    //find most recent addition (reverse search, as push_back to add new entries)
    auto result = std::find_if(currTable.rbegin(), currTable.rend(), [&_name](ContextData::Record* entry)
        { 
            return *(entry->Name()) == _name;
        }
    );
    if (result != currTable.rend()){ return (*result); }
    else { return NULL; }
}

ContextData::Record* ContextTable::GetObjectRecord(const std::string& _ID){
    ContextData::ScopeRecord* backupPtr = currScopePtr;
    bool end = false;
    while(!end){
        end = (currScopePtr==NULL);
        auto result = FindNameInActiveTable(_ID);
        if (result != NULL){ 
            currScopePtr=backupPtr;
            return result; 
        }
        else{
            currScopePtr=currScopePtr->GetParent();
        }
    }
    currScopePtr=backupPtr;
    return NULL;
}

void ContextTable::AddFunctionDecAndBody(ContextData::FunctionDefOrDec* def, ContextData::FunctionScopeRecord* body){
    def->SetScopeParent(currScopePtr);//belongs to this parent scope
    body->SetScopeParent(currScopePtr);//body also is in this scope
    body->SetDeclarationPtr(def);//but is linked to the def/dec for its param decls
    //sort of like a 'virtual' scope
    AddObjectRecord(def);
    currScopePtr = body;
}
