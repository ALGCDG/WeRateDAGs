#include "test_2.hpp"
#include "test_3.hpp"

int main(){
    std::string test = "lol";
    test_lookup(test);
    test_insert(test, true);
    test_lookup(test);
    test_lookup("lmao");
    test_insert("lmao", false);
    test_lookup("lmao");

}