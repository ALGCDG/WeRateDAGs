#ifndef PYTRVISIT_HPP
#define PYTRVISIT_HPP

#include "visitors.hpp"
#include "ast_expressions.hpp"

class python_Visitor: public Visitor
{
    int indentation;
    std::string gentabs()
    {
        std::string indent = ""
        for (int i = 0; i < intentation; i++)
        {
            indent += "\t";
        }
        return indent;
    }
    void visit(While* w)
    {
        std::cout << gentabs() << "while ";
        w->Body->accept(this);
        std::cout << " :" << std::endl;
        indentation++;
        w->Body->accept(this);
        indentation--;
    }
    void visit(If* i)
    {
    }
    public:
    python_Visitor()
    {
        indentation = 0;
    }
};

#endif
