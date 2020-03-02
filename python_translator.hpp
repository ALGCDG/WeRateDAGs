#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

class translator: public Visitor
{
    public:
    visit(FUNC_NODE)
    visit(RETURN)
    visit(IF)
    visit(IF_ELSE)
    visit(WHILE)
    visit(SEQ)
    visit(func_call)
    visit(CONST_INT)
    visit(VARIABLE)
    visit(*+-,&&,||,<,==)
};


#endif
