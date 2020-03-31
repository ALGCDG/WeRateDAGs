#include "ASTProc.hpp"
#include <exception>
#include <cassert>
#include "ast_TypeInfo.hpp"
//void visit(Node*); //If nothing defined for this type of node
void ASTProcVis::visit(ArraySubscript* _subcr){
    // std::cout << "visit " << "arraysubsr" << std::endl;
    _subcr->Subscript->accept(this);
    _subcr->LHS->accept(this);
}
void ASTProcVis::visit(FuncCall* _funccall){
    
    if(_funccall->Args!=NULL){ _funccall->Args->accept(this); }
    _funccall->LHS->accept(this);
}
void ASTProcVis::visit(MemberAccess* _memberaccess){
    std::cerr << "visit " << "MemberAccess" << std::endl;
    //cant link easily to their meaning, don't know their namespace
    //_memberaccess->ID->accept(this);
    _memberaccess->LHS->accept(this);
    TypeGetter* getter = new TypeGetter;
    TypeInfo* struct_info = _memberaccess->LHS->acceptTypeGetter(getter);
    assert(struct_info->Options==TypeInfo::STRUCT);
    assert(struct_info->isStruct!=NULL);
    Record* member_record = struct_info->isStruct->SearchForMember(_memberaccess->ID->Name);
    _memberaccess->ID->ContextRecord = dynamic_cast<NamedRecord*>(member_record);
    delete getter;
    delete struct_info;
}
void ASTProcVis::visit(DerefMemberAccess* _derefmemberacc){
    //_derefmemberacc->ID->accept(this);
    _derefmemberacc->LHS->accept(this);
    TypeGetter* getter = new TypeGetter;
    TypeInfo* struct_pt_info = _derefmemberacc->LHS->acceptTypeGetter(getter);
    if(struct_pt_info->Options==TypeInfo::POINTER)
    {
        assert(struct_pt_info->isPt!=NULL);
        assert(struct_pt_info->isPt->ptToStruct!=NULL);
        Record* member_record = struct_pt_info->isPt->ptToStruct->SearchForMember(_derefmemberacc->ID->Name);
        _derefmemberacc->ID->ContextRecord = dynamic_cast<NamedRecord*>(member_record);
    }
    else if(struct_pt_info->Options==TypeInfo::ARR)
    {
        assert(struct_pt_info->isArr!=NULL);
        assert(struct_pt_info->isArr->structElementType!=NULL);
        Record* member_record = struct_pt_info->isArr->structElementType->SearchForMember(_derefmemberacc->ID->Name);
        _derefmemberacc->ID->ContextRecord = dynamic_cast<NamedRecord*>(member_record);
    }
    delete getter;
    delete struct_pt_info;
}
void ASTProcVis::visit(ArgExprList* _argexprlist){
    for(auto i : _argexprlist->Args){
        i->accept(this);
    }
}
void ASTProcVis::visit(SizeofExpr* _sizeofexpr){
    _sizeofexpr->RHS->accept(this);
}
void ASTProcVis::visit(SizeofType* _sizeoftype){
    TableInstance->StartNewDeclaration();
    TableInstance->awaitDecSpecs();
    TableInstance->AddIDtoCurrRecord("");
    _sizeoftype->typ_nam->accept(this);
    VariableDeclaration* info;
    TableInstance->AppendCachedDecSpecs();
    TableInstance->clearDecSpecs();
    TableInstance->EndDeclaration(info);
    _sizeoftype->typeInfo=info;
    /*
    TableInstance->StartNewDeclaration();
    TableInstance->awaitDecSpecs();
    TableInstance->AddIDtoCurrRecord("");
    _castexpr->typ->accept(this);
    VariableDeclaration* info;
    TableInstance->AppendCachedDecSpecs();
    TableInstance->clearDecSpecs();
    TableInstance->EndDeclaration(info);
    _castexpr->castInfo = info;
    _castexpr->RHS->accept(this);
    */
}
void ASTProcVis::visit(UnaryAddressOperator* _addrOp){
    _addrOp->RHS->accept(this);
}
void ASTProcVis::visit(UnaryDerefOperator* derefOp){
    derefOp->RHS->accept(this);
    //todo
}
void ASTProcVis::visit(PostInc* _postinc){
    _postinc->LHS->accept(this);
}
void ASTProcVis::visit(PostDec* _postdec){
    _postdec->LHS->accept(this);
}
void ASTProcVis::visit(CastExpr* _castexpr){
    std::cerr << "visiting cast expr" << std::endl;
    TableInstance->StartNewDeclaration();
    TableInstance->awaitDecSpecs();
    TableInstance->AddIDtoCurrRecord("");
    _castexpr->typ->accept(this);
    VariableDeclaration* info;
    TableInstance->AppendCachedDecSpecs();
    TableInstance->clearDecSpecs();
    TableInstance->EndDeclaration(info);
    _castexpr->castInfo = info;
    _castexpr->RHS->accept(this);
    //todo
}
void ASTProcVis::visit(AssignmentExpression* _assignexpr){
    _assignexpr->RHS->accept(this);
    _assignexpr->LHS->accept(this);
    //todo
}

void ASTProcVis::visit(Constant* _constant){}
void ASTProcVis::visit(constant_int* _constantint){
}
void ASTProcVis::visit(UnaryPlusOperator* _unaryplus){
    _unaryplus->RHS->accept(this);
}
void ASTProcVis::visit(UnaryNegOperator* _unaryneg){
    _unaryneg->RHS->accept(this);
}
void ASTProcVis::visit(UnaryBitwiseNotOperator* _unaryBitNot){
    _unaryBitNot->RHS->accept(this);
    //todo
}
void ASTProcVis::visit(UnaryLogicalNotOperator* _unaryLogNot){
    _unaryLogNot->RHS->accept(this);
    //todo
}
void ASTProcVis::visit(PreInc* _preinc){
    _preinc->RHS->accept(this);

}
void ASTProcVis::visit(PreDec* _predec){
    _predec->RHS->accept(this);

}
void ASTProcVis::visit(Multiply* _mul){
    _mul->RHS->accept(this);
    _mul->LHS->accept(this);
}
void ASTProcVis::visit(Divide* _div){
    _div->RHS->accept(this);
    _div->LHS->accept(this);
}
void ASTProcVis::visit(Modulo* _mod){
    _mod->RHS->accept(this);
    _mod->LHS->accept(this);
}
void ASTProcVis::visit(Add* _add){
    _add->RHS->accept(this);
    _add->LHS->accept(this);
}
void ASTProcVis::visit(Sub* _sub){
    _sub->RHS->accept(this);
    _sub->LHS->accept(this);
}
void ASTProcVis::visit(ShiftLeft* _shl){
    _shl->RHS->accept(this);
    _shl->LHS->accept(this);
}
void ASTProcVis::visit(ShiftRight* _shr){
    _shr->RHS->accept(this);
    _shr->LHS->accept(this);
}
void ASTProcVis::visit(LessThan* _lt){
    _lt->RHS->accept(this);
    _lt->LHS->accept(this);
}
void ASTProcVis::visit(GreaterThan* _gt){
    _gt->RHS->accept(this);
    _gt->LHS->accept(this);
}
void ASTProcVis::visit(LessThanOrEqual* _lte){
    _lte->RHS->accept(this);
    _lte->LHS->accept(this);
}
void ASTProcVis::visit(GreaterThanOrEqual* _gte){
    _gte->RHS->accept(this);
    _gte->LHS->accept(this);
}
void ASTProcVis::visit(EqualTo* _eq){
    _eq->RHS->accept(this);
    _eq->LHS->accept(this);
}
void ASTProcVis::visit(NotEqualTo* _ne){
    _ne->RHS->accept(this);
    _ne->LHS->accept(this);
}
void ASTProcVis::visit(LogicalAND* _logand){
    _logand->RHS->accept(this);
    _logand->LHS->accept(this);
}
void ASTProcVis::visit(LogicalOR* _logor){
    _logor->RHS->accept(this);
    _logor->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseAND* _bitand){
    _bitand->RHS->accept(this);
    _bitand->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseOR* _bitor){
    _bitor->RHS->accept(this);
    _bitor->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseXOR* _bitxor){
    _bitxor->RHS->accept(this);
    _bitxor->LHS->accept(this);
}
void ASTProcVis::visit(TernaryOpExpression* _tern){
    _tern->Condition->accept(this);
    _tern->IfFalse->accept(this);
    _tern->IfTrue->accept(this);
}
void ASTProcVis::visit(MulAssignment* _mulass){
    _mulass->RHS->accept(this);
    _mulass->LHS->accept(this);
}
void ASTProcVis::visit(DivAssignment* _divass){
    _divass->RHS->accept(this);
    _divass->LHS->accept(this);
}
void ASTProcVis::visit(ModAssignment* _modass){
    _modass->RHS->accept(this);
    _modass->LHS->accept(this);
}
void ASTProcVis::visit(AddAssignment* _addass){
    _addass->RHS->accept(this);
    _addass->LHS->accept(this);
}
void ASTProcVis::visit(SubAssignment* _subass){
    _subass->RHS->accept(this);
    _subass->LHS->accept(this);
}
void ASTProcVis::visit(ShiftLeftAssignment* _shlass){
    _shlass->RHS->accept(this);
    _shlass->LHS->accept(this);
}
void ASTProcVis::visit(ShiftRightAssignment* _shrass){
    _shrass->RHS->accept(this);
    _shrass->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseANDAssignment* _bANDass){
    _bANDass->RHS->accept(this);
    _bANDass->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseXORAssignment* _xorass){
    _xorass->RHS->accept(this);
    _xorass->LHS->accept(this);
}
void ASTProcVis::visit(BitwiseORAssignment* _bORass){
    _bORass->RHS->accept(this);
    _bORass->LHS->accept(this);
}
void ASTProcVis::visit(ConstantExpression* _constexpr){
    _constexpr->ConstantSubtree->accept(this);
}
void ASTProcVis::visit(CommaSepExpression* _comsep){
    throw("comma sep expr not to be used");
}

//Declarations
void ASTProcVis::visit(declaration* _dectn){
    TableInstance->awaitDecSpecs();//new vector on top
    _dectn->specifier->accept(this);
    std::cerr << "visited declaration specifier" << std::endl;
    // TableInstance->stopAwaitDecSpecs();
    if(_dectn->list!=NULL)
        _dectn->list->accept(this);
    TableInstance->clearDecSpecs();
    std::cerr << "visited declaration" << std::endl;
}
void ASTProcVis::visit(declaration_specifiers* _decspec){
    //TODO if not a canonical type, link in the record somehow
    if(_decspec->type_spec!=NULL){
        _decspec->type_spec->accept(this);
    }
    else if(_decspec->storage_class_specifier!=NULL){
        _decspec->storage_class_specifier->accept(this);
    }
    if(_decspec->specifier!=NULL){
        
        _decspec->specifier->accept(this);
    }
}
void ASTProcVis::visit(TypedefNode* _typedef){
    TableInstance->PushDecSpec("typedef");
    // TableInstance->AssertTypedef();//TODO add base class visitor for typedef node
}

void ASTProcVis::visit(type_name* typ){
    std::cerr << "visiting type_name" << std::endl;
    if(typ->abs_dec!=NULL){ typ->abs_dec->accept(this);std::cerr << "visited type_name absdec" << std::endl;}
    if(typ->spec_list!=NULL){ typ->spec_list->accept(this); std::cerr << "visited type_name speclist" << std::endl; }
}

void ASTProcVis::visit(init_declarator_list* _indeclis){
    
    if(_indeclis->init_dec_list!=NULL) _indeclis->init_dec_list->accept(this);
    TableInstance->StartNewDeclaration();
    _indeclis->init_dec->accept(this);
    TableInstance->AppendCachedDecSpecs();//adds dec specs to vec
    TableInstance->EndDeclaration();//combines dec specs right to left
}
void ASTProcVis::visit(init_declarator* _indec){
    if(_indec->init!=NULL) _indec->init->accept(this);
    _indec->dec->accept(this);
}
void ASTProcVis::visit(type_specifier* _typespec){
    std::cerr << "visiting type_specifier" << std::endl;
    std::cerr << "pushing dec spec" << std::endl;
    TableInstance->PushDecSpec(_typespec->type);
    std::cerr << "pushed dec spec" << std::endl;
}
void ASTProcVis::visit(specifier_list* _speclist){
    std::cerr << "visiting spec list" << std::endl;
    _speclist->type_spec->accept(this);
    std::cerr << "... visited a spec" << std::endl;
    if(_speclist->spec_list!=NULL){ _speclist->spec_list->accept(this); }
}
void ASTProcVis::visit(pointer* _pt){
    
    TableInstance->AddPtrToCurrRecord();
    if (_pt->p!=NULL){_pt->p->accept(this); }
}
void ASTProcVis::visit(base_declarator* _basedec){}
void ASTProcVis::visit(abstract_declarator* _absdec){
    std::cerr << "visiting abstract declarator" << std::endl;
    if(_absdec->p!=NULL){
        if(_absdec->dabs_dec!=NULL){
            _absdec->dabs_dec->accept(this);
        }
        _absdec->p->accept(this);
    }
    else{
        _absdec->dabs_dec->accept(this);
    }
}
void ASTProcVis::visit(direct_abstract_declarator* _absdec){
    
    if(_absdec->abs_dec!=NULL){ _absdec->abs_dec->accept(this); }
    else{
        if(_absdec->dabs_dec!=NULL){ 
            _absdec->dabs_dec->accept(this); 
        }
        if(_absdec->const_expr!=NULL){
            int size = EvalConstantExpression(_absdec->const_expr);
            TableInstance->AddArrayToCurrRecord(size);
        }
        else if(_absdec->para_list!=NULL){
            TableInstance->AddFuncToCurrRecord();
            _absdec->para_list->accept(this);
            TableInstance->EndFuncParams();
        }
    }
}
void ASTProcVis::visit(declarator* _declr){
    
    _declr->dir_dec->accept(this);
    
    if(_declr->p!=NULL) _declr->p->accept(this);
}
void ASTProcVis::visit(direct_declarator* _dirdec){
    
    if(_dirdec->ID != NULL){
        TableInstance->AddIDtoCurrRecord(_dirdec->ID->Name);  
        _dirdec->ID->ContextRecord = TableInstance->GetActiveRecord();
    }
    else if(_dirdec->dec != NULL){
        _dirdec->dec->accept(this);
    }
    else if(_dirdec->dir_dec != NULL){
        _dirdec->dir_dec->accept(this);
        if(_dirdec->const_expr != NULL){
            std::cerr<<"before eval" << std::endl;
            int size = EvalConstantExpression(_dirdec->const_expr);
            std::cerr<<"after eval" << std::endl;
            TableInstance->AddArrayToCurrRecord(size);
        }
        else if(_dirdec->para_list!=NULL){
            
            TableInstance->AddFuncToCurrRecord();
            _dirdec->para_list->accept(this);
            TableInstance->EndFuncParams();
        }
    }
}
void ASTProcVis::visit(parameter_list* _paramlist){
    
    if(_paramlist->para_list!=NULL){ _paramlist->para_list->accept(this); }
    TableInstance->StartParamDeclaration();
    _paramlist->para_dec->accept(this);
    
    TableInstance->EndParamDeclaration();
    
}
void ASTProcVis::visit(parameter_declaration* _pardec){
    
    TableInstance->awaitDecSpecs();
    _pardec->dec_spec->accept(this);
    if(_pardec->dec!=NULL){
        _pardec->dec->accept(this);
    }
    //TODO is unnamed seperate to abstract?
    else if(_pardec->abs_dec!=NULL){
        TableInstance->AddUnnamedtoCurrRecord();
        _pardec->abs_dec->accept(this);
    }
    else{
        //todo ie here
        TableInstance->AddUnnamedtoCurrRecord();
    }
    TableInstance->AppendCachedDecSpecs();

    //!added this, not sure
    TableInstance->clearDecSpecs();
}
//Statements
void ASTProcVis::visit(EmptyStatement* _emptmnt){}//do nothing
void ASTProcVis::visit(Continue* _cont){}//do nothing
void ASTProcVis::visit(Break* _brk){}//do nothing
void ASTProcVis::visit(Return* _ret){
    if(_ret->ReturnExpression!=NULL){
        _ret->ReturnExpression->accept(this);
    }
}
void ASTProcVis::visit(ExpressionStatement* _exprstmnt){
    _exprstmnt->Expr->accept(this);
}
void ASTProcVis::visit(StatementList* _stmntlist){
    if(_stmntlist->RestOfStatements!=NULL){_stmntlist->RestOfStatements->accept(this);}
    _stmntlist->statement->accept(this);
}
void ASTProcVis::visit(CompoundStatement* _compstat){
    TableInstance->NewScope();
    if(_compstat->Decls!=NULL){ _compstat->Decls->accept(this); }
    if(_compstat->Statements!=NULL){ _compstat->Statements->accept(this); }
    TableInstance->PopScope();
}

//scope changing
void ASTProcVis::visit(While* _whi){
    _whi->ControlExpression->accept(this);
    TableInstance->NewScope();
    _whi->Body->accept(this);
    TableInstance->PopScope();
}
void ASTProcVis::visit(DoWhile* _dowhi){
    TableInstance->NewScope();
    _dowhi->Body->accept(this);
    TableInstance->PopScope();
    //control expression is in scope above the body
    _dowhi->ControlExpression->accept(this);
}
void ASTProcVis::visit(For* _for){
    _for->Init->accept(this);
    _for->Control->accept(this);
    _for->Next->accept(this);
    TableInstance->NewScope();
    _for->Body->accept(this);
    TableInstance->PopScope();
}
void ASTProcVis::visit(If* _if){
    _if->ControlExpression->accept(this);
    TableInstance->NewScope();
    _if->IfTrue->accept(this);
    TableInstance->PopScope();
}
void ASTProcVis::visit(IfElse* _ifelse){
    _ifelse->ControlExpression->accept(this);
    TableInstance->NewScope();
    _ifelse->IfTrue->accept(this);
    TableInstance->PopScope();
    TableInstance->NewScope();
    _ifelse->IfFalse->accept(this);
    TableInstance->PopScope();
}
void ASTProcVis::visit(Switch* _swi){
    _swi->ControlExpression->accept(this);
    TableInstance->NewScope();
    _swi->Body->accept(this);
    TableInstance->PopScope();
}
void ASTProcVis::visit(CaseOrDefault* _caseordef){
    TableInstance->NewScope();
    _caseordef->Body->accept(this);
    TableInstance->PopScope();
}

//External definitions
void ASTProcVis::visit(TranslationUnit* _trans){
    
    for (auto el : _trans->decls){
        el->accept(this);
    }
}
void ASTProcVis::visit(FunctionDefinition* _funcdef){
    
    TableInstance->StartNewFuncDef();
    TableInstance->awaitDecSpecs();
    _funcdef->specs->accept(this);
    
    _funcdef->decl->accept(this);
    
    TableInstance->AppendCachedDecSpecs();
    
    TableInstance->clearDecSpecs();
    
    TableInstance->EndFuncDfDeclaration();
    TableInstance->AddFuncRecordBody();
    
    _funcdef->Body->accept(this);
    TableInstance->EndFuncDef();
    // TableInstance->PopScope();
}
void ASTProcVis::visit(ExternalDeclaration* _extdec){
    

    //hop straight down to the declaration
    _extdec->decl->accept(this);
    std::cerr << "visited declaration" << std::endl;
}

void ASTProcVis::visit(IdentifierNode* _idnode){
    _idnode->ContextRecord = TableInstance->GetIDRecord((_idnode->Name));
}

void ASTProcVis::visit(DeclarationList* decllis){
    if(decllis->left_list!=NULL){ decllis->left_list->accept(this);}
    decllis->this_decl->accept(this);
}

void ASTProcVis::visit(initializer * _init){
    if(_init->ass_expr!=NULL){ _init->ass_expr->accept(this); }
    else if(_init->init_list!=NULL){ _init->init_list->accept(this); }
    else { throw("uh oh"); }
}
void ASTProcVis::visit(initializer_list * _init_list){
    if(_init_list->init_list!=NULL){_init_list->init_list->accept(this);}
    _init_list->init->accept(this);
}

void ASTProcVis::visit(struct_specifier* _strspec){
    std::string name = "struct";
    if(_strspec->tag!=NULL){ name += " " + _strspec->tag->Name; } //"struct <tag>"
    if(_strspec->list!=NULL){
        TableInstance->StartNewStructDeclaration();
        TableInstance->AddIDtoCurrRecord(name);
        _strspec->list->accept(this);
        TableInstance->EndStructDeclaration();
    }
    TableInstance->PushDecSpec(name);
    std::cerr << "visited struct specifier" << std::endl;
}
void ASTProcVis::visit(struct_declaration_list* _strdectionlist){
    for(auto declaration : _strdectionlist->decs){
        declaration->accept(this);
    }
}
void ASTProcVis::visit(struct_declaration* _strdection){
    TableInstance->awaitDecSpecs();
    _strdection->specs->accept(this);
    _strdection->decls->accept(this);
    TableInstance->clearDecSpecs();
}
void ASTProcVis::visit(struct_declarator_list* _strdeclist){
    for(auto dec : _strdeclist->decls){
        TableInstance->StartNewDeclaration();
        dec->accept(this);
        TableInstance->AppendCachedDecSpecs();
        TableInstance->EndDeclaration();
    }
}

void ASTProcVis::visit(EnumSpecifier* _enum){
    std::cerr << "visiting enum spec" << std::endl;
    std::string name = "enum";
    if(_enum->tag!=NULL){ name += " " + _enum->tag->Name; }
    if(_enum->options!=NULL){
        TableInstance->StartNewEnumDeclaration(name);
        std::cerr << "started enum dec" << std::endl;
        // TableInstance->AddIDtoCurrRecord(name);
        // std::cerr << "add id: enum spec" << std::endl;
        _enum->options->accept(this);
        std::cerr << "visited options" << std::endl;
        TableInstance->EndEnumDeclaration();
    }
    TableInstance->PushDecSpec(name);
    std::cerr << "pushed " << name << std::endl;
}

void ASTProcVis::visit(EnumeratorList* _enumlist){
    for(auto enumerator : _enumlist->List){
        enumerator->accept(this);
    }
}

void ASTProcVis::visit(Enumerator* _enumer){
    std::cerr << "visiting enumerator" << std::endl;
    if(_enumer->OptionalValue!=NULL){
        std::cerr << "enumerator: value given" << std::endl;
        int value = EvalConstantExpression(_enumer->OptionalValue);
        std::cerr << "visited enumerator, calculated value as " << value << std::endl;
        TableInstance->AddEnumerator(_enumer->ConstID->Name, value);
    }
    else{
        std::cerr << "enumerator: no value given" << std::endl;
        TableInstance->AddEnumerator(_enumer->ConstID->Name);
    }
}

int ASTProcVis::EvalConstantExpression(ConstantExpression* _const_expr){
    return _const_expr->constEval();
}

// unsigned int ASTProcVis::EvalConstantExpression(constant_int* _const){
//     std::cerr << "eval const int" << std::endl;
//     return _const->constEval();
// }

int ASTProcVis::EvalConstantExpression(Expression* expr){
    std::cerr << "eval expr" << std::endl;
    return expr->constEval();
    //throw("No eval for class: expression");
    //as it is a placeholder class!
}

// unsigned int ASTProcVis::EvalConstantExpression(unspecified_array_length* _unspec){
//     std::cerr << "eval unspec expr" << std::endl;
//     return _unspec->constEval();
//     //ansi c forbids explicit array size declaration of size 0
//     //so this is safe

//     //!Size 0 -> unspecified
// }

