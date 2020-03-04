#ifndef AST_EXTERNS
#define AST_EXTERNS

#include "ast_node.hpp"
#include "ast_declarations.hpp"
#include <vector>

class TranslationUnit : public Node
{
private:
    std::vector<ExternalDef*> Units;
public:
    TranslationUnit(ExternalDef* _externaldef) : Units{_externaldef} {}
    
};

class ExternalDef : public Node
{
private:
public:
};

class ExternalFuncDef : public ExternalDef
{
private:
    
public:
    ExternalFuncDef(/* args */) {}
};

class ExternalDeclaration : public ExternalDef
{
private:
    Declaration* ExtDecl;
};


#endif