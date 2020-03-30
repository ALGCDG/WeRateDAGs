#include "feSymtabDec.hpp"//declaration is here
#include "feSymtab.hpp" //function declarations

//define global variable
std::stack<std::vector<std::pair<std::string, bool> > > tieinSymtab = std::stack<std::vector<std::pair<std::string, bool> >();

bool isTypeName(const std::string& name){
    for(auto& pair : tieinSymtab.top()){}
}
void insertTypeName(const std::string& name){
    tieinSymtab.top().push_back(std::make_pair(name,true));
}
void insertOtherName(const std::string& name){
    tieinSymtab.top().push_back(std::make_pair(name,false));
}
void PopScope(){
    tieinSymtab.pop();
}
void NewScope(){
    tieinSymtab.push(std::vector<std::pair<std::string,bool> >());
}