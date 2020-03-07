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
    /** Member data:
     * idenfifier node
     * declarator
     * direct declarator [ unspecified array length]
     * direct declarator [ constant expression ]
     * direct declarator ( parameter list )
     * direct declarator ()
     */
    if(_this_dir_dec->ID != NULL) { return descendDeclarator(_this_dir_dec->ID); }
    else if(_this_dir_dec->dec != NULL) { return descendDeclarator(_this_dir_dec->dec); }
    else if(_this_dir_dec->dir_dec != NULL){
        if(_this_dir_dec->const_expr != NULL){
            int size = EvalConstantExpression(_this_dir_dec->const_expr);
            decTypeInfo* below = descendDeclarator(_this_dir_dec->dir_dec);
            Context::arrayPart* this_array = new Context::arrayPart(size, NULL);
            below->second->AddChild(this_array); //add array to linked list
            below->second = this_array; //make bottom of list this array
            return below;
        }
        else if(_this_dir_dec->para_list!=NULL){

            Context::funcPart* this_func = new Context::funcPart()
        }
    }

}
decTypeInfo* descendDeclarator(IdentifierNode* _id)
{
    Context::IDPart* head = new Context::IDPart(_id, NULL);
    return new decTypeInfo(head,head);
}

decTypeInfo* descendDeclarator(parameter_list* _par_list)
{
}
decTypeInfo* descendDeclarator(parameter_declaration* _par_dec)
{

}
decTypeInfo* descendDeclarator(declaration_specifiers* _decl_spec);
decTypeInfo* descendDeclarator(abstract_declarator* _decl);
decTypeInfo* descendDeclarator(direct_abstract_declarator* _dir_abs_dec);