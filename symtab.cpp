#include "symtab.hpp"
SymbolTable _table = SymbolTable();

bool IsNamePresent(std::string ID){
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        if(it->find(ID) != it->end()) return true;
    }
    return false;
}

char isSymbolAType(std::string ID){
    //searches up through deque, doesn't discern between what was typedef'd first or whatever inside the same scope
    for(SymbolTable::iterator it = _table.begin(); it < _table.end(); it++){
        ScopedSymbolTable::iterator find_it = it->find(ID);
        if(find_it != it->end()) return find_it->second.TypeOrNot;
    }
    return -1;
}

void addSymbol(std::string ID, bool isType){
    _table.front()[ID] = {0, (char) isType}; //possibly don't need 0, just for insert order
};
void new_scope(){ _table.push_front(ScopedSymbolTable()); }
void pop_scope(){ _table.pop_front(); }