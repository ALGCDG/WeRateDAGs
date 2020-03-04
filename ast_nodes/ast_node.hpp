#ifndef AST_NODE
#define AST_NODE

class Node{
public:
    void accept(Visitor* AVisitor);
private:
    
};

#endif