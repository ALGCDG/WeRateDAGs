#include "feSymtabDec.hpp"//declaration is here
#include "feSymtab.hpp" //function declarations

//define global variable
std::vector<std::vector<std::pair<std::string, bool> > > tieinSymtab = std::vector<std::vector<std::pair<std::string, bool> > >();

bool isTypeName(const std::string& name){
    for(auto scope = tieinSymtab.rbegin(); scope < tieinSymtab.rend(); scope++){
        for(auto entry = scope->rbegin(); entry < scope->rend(); entry++){
            //searching backwards
            if(entry->first==name){ return entry->second; }
        }
    }
    //always presume var name
    return false;
}
void insertTypeName(const std::string& name){
    tieinSymtab.back().push_back(std::make_pair(name,true));
}
void insertOtherName(const std::string& name){
    tieinSymtab.back().push_back(std::make_pair(name,false));
}
void PopScope(){
    tieinSymtab.pop_back();
}
void NewScope(){
    tieinSymtab.push_back(std::vector<std::pair<std::string,bool> >());
}