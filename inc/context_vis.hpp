#ifndef CONTEXTVIS_HPP
#define CONTEXTVIS_HPP

#include "ast_context.hpp"
#include "visitors.hpp"
#include "ast_allnodes.hpp"
#include <cassert>

#include <utility> //std::pair

class ContextVisitor : public Visitor{
public:
/*  Needs to link all identifiers in the ast with info in the table
    Needs to intereact with table for scope changes, add records, change records?
    Also needs to provide algorithms for getting:
        ID from declaration
        Type as type parts from declaration

        Stack frame / pointer locations

*/
    ContextVisitor(ContextTable* _table) : TableInstance(_table){
        //make sure to construct visitor with instance of table
        assert(_table);
    }
private:
    ContextData::Record* GetRecord(const std::string &_id);
    ContextData::Record* CreateRecord(declaration* _dect); //calls descendDeclarator
    
    //<ID at bottom, top type part in hierarchy, pointer to next type part that needs to be filled in> 
    decTypeInfo* descendDeclarator(declarator* _decl);
    decTypeInfo* descendDeclarator(pointer* _ptr);

    decTypeInfo* descendDeclarator(direct_declarator* _dir_dec);
    decTypeInfo* descendDeclarator(IdentifierNode* _id);
    ContextData::argPart* descendDeclarator(parameter_list* _par_list);
        decTypeInfo* descendDeclarator(parameter_declaration* _par_dec);
            ContextData::baseSpecPart* descendDeclarator(declaration_specifiers* _decl_spec);
            decTypeInfo* descendDeclarator(abstract_declarator* _decl);
                decTypeInfo* descendDeclarator(direct_abstract_declarator* _dir_abs_dec);

    //evaluates constant expression, (returns -1 if unspecified size)
    int EvalConstantExpression(ConstantExpression* _const_expr);
    ContextTable* TableInstance;
};

namespace{
    //linked list of type parts, head and tail
    typedef std::pair<ContextData::typePart*, ContextData::typePart*> decTypeInfo;  
}

#endif