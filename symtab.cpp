#include "symtab.hpp"
SymbolTable _table = SymbolTable();

bool IsNamePresent(std::string ID){
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        if(it->find(ID) != it->end()) return true;
    }
    return false;
}

char isSymbolAType(std::string ID){
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        
        if(it->find(ID) != it->end()) return true;
    }
    return false;
}


void new_scope(){ _table.push_front(ScopedSymbolTable()); }
void pop_scope(){ _table.pop_front(); }