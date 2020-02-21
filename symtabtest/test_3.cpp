#include "test_3.hpp"
#include <iostream>

void test_lookup(std::string in){
    try{
        data_t out = lookup(in);
        std::cout << "Element found with value " << out << std::endl;
    }
    catch(std::out_of_range e){
        std::cout << "Element not found" << std::endl;
    }
}