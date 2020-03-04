#include "ast_context.hpp"

ContextTable* ContextTable::Instance(){
    //only one instance of context table
    if(!table_instance){ table_instance = new ContextTable; }
    return table_instance;
}

void ContextTable::NewScope(){
    table_data.push_front(std::unordered_map<std::string, Node*>());
}

void ContextTable::PopScope(){
    table_data.pop_front();
}

void ContextTable::AddDeclarationNode(std::string _ID, Node* _node){
    table_data[0][_ID] = (_node);
}

Node* ContextTable::GetObjectDeclaration(std::string _ID){
    for(std::deque<LocalTable>::iterator it = table_data.begin(); it < table_data.end(); it++){
        LocalTable::iterator find_it = it->find(_ID);
        if(find_it != it->end()) return find_it->second;
    }
}