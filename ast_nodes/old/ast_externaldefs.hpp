#ifndef AST_EXTERNS
#define AST_EXTERNS

#include "ast_node.hpp"
#include "altdec.hpp"
#include <vector>

class TranslationUnit : public Node
{
private:
    std::vector<GenericExternalDeclaration*> Units;
public:
    TranslationUnit(GenericExternalDeclaration* _externaldef) : Units{_externaldef} {}
};

class GenericExternalDeclaration : public Node{};

class FunctionDefinition : public GenericExternalDeclaration{
public:
    declaration_specifiers* specs;
    declarator* decl;
    declaration_list* decl_list;
    CompoundStatement* Body;
};

class ExternalDeclaration : public GenericExternalDeclaration{
public:
    declaration* decl;
};

#endif