#include "symtab.hpp"
SymbolTable _table = SymbolTable();

std::string VarEntry::RecordType(){ return "Variable"; }
std::string ArrEntry::RecordType(){ return "Array"; }
std::string FuncEntry::RecordType(){ return "Function"; }
std::string TypeEntry::RecordType(){ return "Type"; }

bool IsNamePresent(std::string name){
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        if(it->find(name) != it->end()) return true;
    }
    return false;
}

void new_scope(){
    _table.push_front(ScopedSymbolTable());
}

//TODO Error check for scope decrease too much ( eg too many '}' )
void end_scope(){
    _table.pop_front();
}

void InsertNameData(std::string name, RecordEntry * entry){
    //TODO Check if present -> appropriate error handling
    _table[0][name] = entry;
}

void EditNameData(std::string name, RecordEntry * entry){
    //TODO Error handling, different than inserting
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        ScopedSymbolTable::iterator search_it = it->find(name);
        if(search_it != it->end()){
            delete search_it->second;
            search_it->second = entry;
            return;
        }
    }
}

/** @param name symbol name
 *  @return pointer to most local matching name
 *      or NULL if not found
 */
RecordEntry* GetTokenData(std::string name){
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        ScopedSymbolTable::iterator search_it = it->find(name);
        if(search_it != it->end()) return search_it->second;
    }
    return NULL;
}

