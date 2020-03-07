#ifndef BASENODE_HPP
#define BASENODE_HPP

#include "visitors.hpp"
class Visitor;

class Node{
public:
    void accept(Visitor* AVisitor);
private:
    
};

#endif