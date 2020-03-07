#include "context_vis.hpp"

//remember:
//linked list of type parts, head and tail
//typedef std::tuple<Context::typePart*, Context::typePart*> decTypeInfo; 

//getting information out of declarator for use in records
decTypeInfo* descendDeclarator(declarator* _decl)
{
    //declarator has member data:
        // pointer (optional)
        // direct declarator

    
}
decTypeInfo* ContextVisitor::descendDeclarator(pointer* _ptr)
{
    if(_ptr->p == NULL){
        //create pointer part, as both the head and tail of the linked list
        Context::pointerPart* bottomPointer = new Context::pointerPart(NULL);
        return new decTypeInfo(bottomPointer, bottomPointer);
    }
    else{
        decTypeInfo* below = descendDeclarator(_ptr->p);
        //construct new pointer part with the previous head as its child
        Context::pointerPart* thisPointer = new Context::pointerPart(below->first);
        below->first = thisPointer;
        return below;
    }
}
decTypeInfo* ContextVisitor::descendDeclarator(direct_declarator* _this_dir_dec)
{
    //TODO empty parameter list added to grammar
    /** Member data:
     * idenfifier node
     * declarator
     * direct declarator [ unspecified array length]
     * direct declarator [ constant expression ]
     * direct declarator ( parameter list )
     * direct declarator ( empty parameter list )
     */
    if(_this_dir_dec->ID != NULL) { return descendDeclarator(_this_dir_dec->ID); }
    else if(_this_dir_dec->dec != NULL) { return descendDeclarator(_this_dir_dec->dec); }
    else if(_this_dir_dec->dir_dec != NULL){
        decTypeInfo* below = descendDeclarator(_this_dir_dec->dir_dec);
        if(_this_dir_dec->const_expr != NULL){
            int size = EvalConstantExpression(_this_dir_dec->const_expr);
            Context::arrayPart* this_array = new Context::arrayPart(size, NULL);
            below->second->AddChild(this_array); //add array to linked list
            below->second = this_array; //make bottom of list this array
            return below;
        }
        else if(_this_dir_dec->para_list!=NULL){
            Context::argPart* args = descendDeclarator(_this_dir_dec->para_list);
            Context::funcPart* this_func = new Context::funcPart(args, NULL);
            below->second->AddChild(this_func);
            below->second = this_func;
            return below;
        }
    }

}
decTypeInfo* descendDeclarator(IdentifierNode* _id)
{
    Context::IDPart* head = new Context::IDPart(_id, NULL);
    return new decTypeInfo(head,head);
}

Context::argPart* descendDeclarator(parameter_list* _par_list)
{

}
decTypeInfo* descendDeclarator(parameter_declaration* _par_dec)
{

}
Context::baseSpecPart* descendDeclarator(declaration_specifiers* _decl_spec){
    Context::baseSpecPart* otherSpecs = NULL;
    if(_decl_spec->specifier!=NULL){ otherSpecs = descendDeclarator(_decl_spec->specifier); }
    if(_decl_spec->storage_class_specifier!=NULL){ return new Context::typedefSpecPart(otherSpecs); }
    else if(_decl_spec->type_spec != NULL){ return ContextTable::Instance()->TypeIsUserOrCanon(_decl_spec->type_spec->type, otherSpecs); }
}
decTypeInfo* descendDeclarator(abstract_declarator* _decl );
decTypeInfo* descendDeclarator(direct_abstract_declarator* _dir_abs_dec);