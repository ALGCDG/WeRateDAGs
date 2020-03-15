#include "ASTProc.hpp"


    //void visit(Node*); //If nothing defined for this type of node
    void ASTProcVis::visit(ArraySubscript* _subcr){
        std::cout << "visit " << "arraysubsr" << std::endl;
        _subcr->Subscript->accept(this);
        _subcr->LHS->accept(this);
    }
    void ASTProcVis::visit(FuncCall* _funccall){
        std::cerr << "visiting func call" << std::endl;
        if(_funccall->Args!=NULL){ _funccall->Args->accept(this); }
        _funccall->LHS->accept(this);
    }
    void ASTProcVis::visit(MemberAccess* _memberaccess){
        std::cout << "visit " << "MemberAccess" << std::endl;
        _memberaccess->ID->accept(this);
        _memberaccess->LHS->accept(this);
    }
    void ASTProcVis::visit(DerefMemberAccess* _derefmemberacc){
        _derefmemberacc->ID->accept(this);
        _derefmemberacc->LHS->accept(this);
    }
    void ASTProcVis::visit(ArgExprList* _argexprlist){
        std::cerr << "visiting arg expr list" << std::endl;
        for(auto i : _argexprlist->Args){
            i->accept(this);
        }
    }
    void ASTProcVis::visit(SizeofExpr* _sizeofexpr){
        _sizeofexpr->RHS->accept(this);
    }
    void ASTProcVis::visit(SizeofType* _sizeoftype){
        _sizeoftype->typ_nam->accept(this);//TODO more of
    }
    void ASTProcVis::visit(UnaryAddressOperator* _addrOp){
        _addrOp->RHS->accept(this);
    }
    void ASTProcVis::visit(UnaryDerefOperator* derefOp){
        derefOp->RHS->accept(this);
    }
    void ASTProcVis::visit(PostInc* _postinc){
        _postinc->LHS->accept(this);
    }
    void ASTProcVis::visit(PostDec* _postdec){
        _postdec->LHS->accept(this);
    }
    void ASTProcVis::visit(CastExpr* _castexpr){
        _castexpr->typ->accept(this);
        _castexpr->RHS->accept(this);
    }
    void ASTProcVis::visit(AssignmentExpression* _assignexpr){
        _assignexpr->RHS->accept(this);
        _assignexpr->LHS->accept(this);
    }

    void ASTProcVis::visit(Constant* _constant){}
    void ASTProcVis::visit(UnaryPlusOperator* _unaryplus){
        _unaryplus->RHS->accept(this);
    }
    void ASTProcVis::visit(UnaryNegOperator* _unaryneg){
        _unaryneg->RHS->accept(this);
    }
    void ASTProcVis::visit(UnaryBitwiseNotOperator* _unaryBitNot){
        _unaryBitNot->RHS->accept(this);
    }
    void ASTProcVis::visit(UnaryLogicalNotOperator* _unaryLogNot){
        _unaryLogNot->RHS->accept(this);
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
        std::cerr << "visiting declaration" << std::endl;
        TableInstance->awaitDecSpecs();//new vector on top
        _dectn->specifier->accept(this);
        // TableInstance->stopAwaitDecSpecs();
        _dectn->list->accept(this);
        TableInstance->clearDecSpecs();
    }
    void ASTProcVis::visit(declaration_specifiers* _decspec){
        std::cerr << "visiting dec specs" << std::endl;
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
        std::cerr << "visiting typedef node" << std::endl;
        TableInstance->AssertTypedef();//TODO add base class visitor for typedef node
    }
    void ASTProcVis::visit(init_declarator_list* _indeclis){
        std::cerr << "visiting init dec list" << std::endl;
        if(_indeclis->init_dec_list!=NULL) _indeclis->init_dec_list->accept(this);
        TableInstance->StartNewDeclaration();
        _indeclis->init_dec->accept(this);
        TableInstance->AppendCachedDecSpecs();//adds dec specs to vec
        TableInstance->EndDeclaration();//combines dec specs right to left
    }
    void ASTProcVis::visit(init_declarator* _indec){
        std::cerr << "visiting init declarator" << std::endl;
        if(_indec->init!=NULL) _indec->init->accept(this);
        _indec->dec->accept(this);
    }
    void ASTProcVis::visit(type_specifier* _typespec){
        std::cerr << "visiting type spec" << std::endl;
        TableInstance->PushDecSpec((_typespec->type));
        

    }
    void ASTProcVis::visit(specifier_list* _speclist){
        std::cerr << "visiting specifier list" << std::endl;
        _speclist->type_spec->accept(this);
        if(_speclist->spec_list!=NULL){ _speclist->spec_list->accept(this); }
    }
    void ASTProcVis::visit(pointer* _pt){
        std::cerr << "visiting pointer" << std::endl;
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
        std::cerr << "visiting direct abstract decl" << std::endl;
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
        std::cerr << "visiting declarator" << std::endl;
        _declr->dir_dec->accept(this);
        std::cerr << "visited dir dec" << std::endl;
        if(_declr->p!=NULL) _declr->p->accept(this);
    }
    void ASTProcVis::visit(direct_declarator* _dirdec){
        std::cerr << "visiting direct dec" << std::endl;
        if(_dirdec->ID != NULL){
            TableInstance->AddIDtoCurrRecord(_dirdec->ID->Name);
            
        }
        else if(_dirdec->dec != NULL){
            _dirdec->dec->accept(this);
        }
        else if(_dirdec->dir_dec != NULL){
            _dirdec->dir_dec->accept(this);
            if(_dirdec->const_expr != NULL){
                int size = EvalConstantExpression(_dirdec->const_expr);
                TableInstance->AddArrayToCurrRecord(size);
            }
            else if(_dirdec->para_list!=NULL){
                std::cerr << "adding func to curr record" << std::endl;
                TableInstance->AddFuncToCurrRecord();
                _dirdec->para_list->accept(this);
                TableInstance->EndFuncParams();
            }
        }
    }
    void ASTProcVis::visit(parameter_list* _paramlist){
        std::cerr << "visiting param list" << std::endl;
        if(_paramlist->para_list!=NULL){ _paramlist->para_list->accept(this); }
        TableInstance->StartParamDeclaration();
        _paramlist->para_dec->accept(this);
        std::cerr << "ending param declaration" << std::endl;
        TableInstance->EndParamDeclaration();
        std::cerr << "stopped visiting param list" << std::endl;
    }
    void ASTProcVis::visit(parameter_declaration* _pardec){
        std::cerr << "visiting param declaration" << std::endl;
        TableInstance->awaitDecSpecs();
        _pardec->dec_spec->accept(this);
        if(_pardec->dec!=NULL){
            _pardec->dec->accept(this);
        }
        else if(_pardec->abs_dec!=NULL){
            TableInstance->AddUnnamedtoCurrRecord();
            _pardec->abs_dec->accept(this);
        }
        else{
            TableInstance->AddUnnamedtoCurrRecord();
        }
        TableInstance->AppendCachedDecSpecs();
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
        std::cerr << "visiting statement list" << std::endl;
        if(_stmntlist->RestOfStatements!=NULL){_stmntlist->RestOfStatements->accept(this);}
        _stmntlist->statement->accept(this);
    }
    void ASTProcVis::visit(CompoundStatement* _compstat){
        std::cerr << "visiting compound statement" << std::endl;
        if(_compstat->Decls!=NULL){ _compstat->Decls->accept(this); }
        if(_compstat->Statements!=NULL){ _compstat->Statements->accept(this); }
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
        std::cerr << "visiting transl unit" << std::endl;
        for (auto el : _trans->decls){
            el->accept(this);
        }
    }
    void ASTProcVis::visit(FunctionDefinition* _funcdef){
                std::cerr << "visiting func def" << std::endl;

        TableInstance->StartNewFuncDef();
        TableInstance->awaitDecSpecs();
        _funcdef->specs->accept(this);
        std::cerr << " visiting declarator" << std::endl;
        _funcdef->decl->accept(this);
        std::cerr << "appending cahced specs" << std::endl;
        TableInstance->AppendCachedDecSpecs();
        std::cerr << "appended cached specs" << std::endl;
        TableInstance->clearDecSpecs();
        std::cerr << "cleared dec specs" << std::endl;
        TableInstance->EndFuncDfDeclaration();
        TableInstance->AddFuncRecordBody();
        
        _funcdef->Body->accept(this);
        TableInstance->EndFuncDef();
        // TableInstance->PopScope();
    }
    void ASTProcVis::visit(ExternalDeclaration* _extdec){
        std::cerr << "visiting extern dec" << std::endl;

        //hop straight down to the declaration
        _extdec->decl->accept(this);
    }

    void ASTProcVis::visit(IdentifierNode* _idnode){
        std::cerr << "visiting idnode" << std::endl;
        _idnode->ContextRecord = TableInstance->GetIDRecord((_idnode->Name));
    }
