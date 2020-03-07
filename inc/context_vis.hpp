#ifndef CONTEXTVIS_HPP
#define CONTEXTVIS_HPP

#include "ast_context.hpp"
#include "visitors.hpp"
#include "ast_allnodes.hpp"

#include <tuple>

class ContextVisitor : public Visitor{
public:
/*  Needs to link all identifiers in the ast with info in the table
    Needs to intereact with table for scope changes, add records, change records?
    Also needs to provide algorithms for getting:
        ID from declaration
        Type as type parts from declaration

        Stack frame / pointer locations

*/
private:
    Context::Record* GetRecord(const std::string &_id);
    Context::Record* CreateRecord(declaration* _dect); //calls descendDeclarator
    
    //<ID at bottom, top type part in hierarchy, pointer to next type part that needs to be filled in> 
    typedef std::tuple<std::string,Context::typePart*, Context::typePart*> decTypeInfo;  
    decTypeInfo* descendDeclarator(direct_abstract_declarator* _dir_abs_dec);
    decTypeInfo* descendDeclarator(direct_declarator* _dir_dec);
    decTypeInfo* descendDeclarator(declarator* _decl);
    decTypeInfo* descendDeclarator(init_declarator* _in_decl);
    decTypeInfo* descendDeclarator(init_declarator_list* _dir_abs_dec);




    //evaluates constant expression
    void SimplifyConstantExpression(ConstantExpression* _const_expr);
};

#endif