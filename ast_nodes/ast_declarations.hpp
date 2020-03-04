#ifndef AST_DECLS
#define AST_DECLS

#include "ast_expressions.hpp"
#include <vector>
//vargs?
//asbtract declarators?
//decl list (in statements grammar)
//!Change type to type specifier
// !Identifier is not a type

class TypedefSpecifier : public Node{

};

//-----------------------
class StructSpecifier : public Type{
//stand in for polymorphism
};
class NoTagStructSpec : public StructSpecifier{
//no tag given:
//"struct { fields }"
};
class FullStructSpec : public StructSpecifier{
//tag and declaration list given
// "struct Tag { fields }"
};
class WithoutDeclsStructSpec : public StructSpecifier{
//Struct has probably been defined before
//This is then used to later declare an instance of this class:
/*
First define struct:
> struct A { fields };

Then use "WithoutDeclsStructSpec" like so
> struct A myStruct;
to create an instance of struct A
*/
};

//--------------------------

class StructDeclList : public Node{
public:
    void AppendDeclaration(StructDeclaration* Declaration);
private:
    std::vector<StructDeclaration*> List;
};

class StructDeclaration : public Node{
private:
    TypeSpecifier* DeclaratorListType;
    StructDeclaratorList* DeclaratorList; 
};

class StructDeclaratorList : public Node{
    void AppendDeclarator(Declarator* Decl);
private:
    std::vector<Declarator*> List;
};

class Declarator : public Node{
private:
    PointerList* PointerSpecifier;
    DirectDeclarator* DirDeclarator;
};

class DirectDeclarator : public Node{

};

class IdentDirectDeclarator : public DirectDeclarator{
private:
    Identifier ID;
};

class BracketedDirectDeclarator : public DirectDeclarator{
private:
    Declarator* Decl;
};

class ArrayDirectDeclarator : public DirectDeclarator{
private:
    DirectDeclarator* LeftDecl;
    ConstantExpression* Size;
};

class IncompleteArrayDirectDeclarator : public DirectDeclarator{
private:
    DirectDeclarator* LeftDecl;
};

class FunctionDirectDeclarator : public DirectDeclarator{
private:
    //null if no args
    ParameterList* Params;
};

//-----------------------------

class PointerList : public Node{
    void IncreasePointerDepth();
private:
    int PointerDepth /* = 1 -> on init*/;
};

class ParameterList : public Node{
    void AppendDeclaration(ParamDeclaration* Decl);
private:
    std::vector<ParamDeclaration*> List;
};

class ParamDeclaration : public Node{

};

class NamedParameterDeclaration : public ParamDeclaration{
private:
    DeclarationSpecifiers* Specs;
    Declarator* Decl;
};

class UnnamedParameterDeclaration : public ParamDeclaration{
private:
    DeclarationSpecifiers* Specs; //eg int

    //optional
    PointerAbstractDeclarator* Decl; //eg *
    //combined: could be:
    // int
    // int *
    //inside a function: int f(int *); <- which is unnamed int* param 
};

class PointerAbstractDeclarator : public Node{
    //for just a pointer
protected:
    PointerList* Pointer;
};

class FullAbstractDeclarator : public PointerAbstractDeclarator{
    //for pointer (opt) and direct abstract declarator
private:
    DirectAbstractDeclarator* Decl;
};

class DirectAbstractDeclarator : public Node{};

class BracketedDirAbsDeclarator : public DirectAbstractDeclarator{
private:
    PointerAbstractDeclarator* Decl;
};

class ArrayDirAbsDeclarator : public DirectAbstractDeclarator{
public:
    bool IsIncomplete();
private:
    DirectAbstractDeclarator* DADecl;
    ConstantExpression* Expr;
};

class FunctionDirAbsDeclarator : public DirectAbstractDeclarator{
public:
private:
    DirectAbstractDeclarator* DADecl;
    ParameterList* List;
};

class Initialiser : public Declarator{

};

class InitialiserAssignment : public Initialiser{
private:
    GenericAssignExpr* AssExpr;
};

class BracketedInitialiseList : public Initialiser{
private:
    InitialiserList* List;
};

class InitialiserList : public Node{
public:
    void AppenedInitialiser(Initialiser* Init);
private:
    std::vector<Initialiser*> List;
};
//bottom of 6.5.5 in grammars
#endif


