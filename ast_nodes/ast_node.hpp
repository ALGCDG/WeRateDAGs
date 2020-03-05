#ifndef AST_NODE
#define AST_NODE

#include "visitors.hpp"

class Node{
public:
    void accept(Visitor* AVisitor);
private:
    
};

#endif