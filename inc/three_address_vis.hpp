#ifndef THRADDR_HPP
#define THRADDR_HPP

#include <string>
#include <unordered_set>
#include <iostream>
#include <typeinfo>
#include <stack>
#include <utility>

#include <string>
// #include "visitors.hpp"
#include "ast_allnodes.hpp"

class three_address_Visitor : public Visitor
{
    public:
    three_address_Visitor(): counter(0), return_register(), continue_to(), break_to(), cases(), global(true), global_labels(), intermediate_values() {}
    int counter;
    std::stack<std::string> return_register; // a stack which tracks which of the two return registers to use
    std::stack<std::string> continue_to; // stores where a continue should jump to
    std::stack<std::string> break_to; // stores where a break should jump to 
    // std::stack<std::string> temporary_words; 
    bool global; // a flag for tracking if declaration is global or is in a scope.
    std::stack<std::string> global_labels;
    std::stack<std::pair<std::string,Expression*>> cases; // a stack sructure used when generating switch case code
    std::string default_label; // used as a seperate place to store a default label for switch cases
    std::stack<std::string> intermediate_values; // a stack for counting the intermediate values of a function
    std::string get_temp_register(const std::string &inter)
    {
        if (intermediate_values.size() < 8)
        {
            auto reg = "$t" + std::to_string(intermediate_values.size());
            intermediate_values.push(inter);
            return reg;
        }
        else
        {
            return inter;
        }
    }
    std::string gen_name(const std::string &prefix)
    {
        return prefix + std::to_string(counter++);
    }
    void visit(Node * n)
    {
        std::cerr << "visting undefined Node" << std::endl;
    }
    void visit(IdentifierNode * in)
    {
        if (return_register.empty())
        {
            //function definition
            std::cout << *(in->Name);
            if (global)
            {
                global_labels.push(*(in->Name));
            }
        }
        else
        {
            // expression terminal
            auto return_reg = return_register.top();
            return_register.pop();
            std::cout << "move " << return_reg << ", " << *(in->Name) << std::endl;
        }
    }
    void visit(Constant *) {}
    void visit(constant_int * ci)
    {
        if (return_register.empty())
        {
            std::cout << ci->value;
        }
        else
        {
            auto return_reg = return_register.top();
            return_register.pop();
            std::cout << "li " << return_reg << ' ' << ci->value << std::endl;
        }
    }
    void visit(ArraySubscript * as)
    {
        // reading from array
        // get return register
        auto return_reg = return_register.top();
        // get subscript expression
        return_register.push("$v0");
        as->Subscript->accept(this);
        // if array is global
            // get array address
            std::cout << "la $v1 ";
            as->LHS->accept(this);
            std::cout << std::endl;
            // add subscript and 
            std::cout << "addu $v0 $v0 $v1";
            // load relevant word
            std::cout << "lw " << return_reg << " $v0" << std::endl;
        // if array is local
        // ???
        return_register.pop();
    }
    void visit(FuncCall * fc)
    {
        // insert arguments
        fc->Args->accept(this);
        // jump and link
        std::cout << "jal ";
        fc->LHS->accept(this);
        std::cout << std::endl;
    }
    void visit(MemberAccess *) {}
    void visit(DerefMemberAccess *) {}
    void visit(PostInc * pi)
    {
        // // expression of postinc must be a variable
        // std::cout << "move $v0" << *(pi->LHS->Name) << std::endl;
        // std::cout << "addui " << *(pi->LHS->Name) << " $v0 1"<< std::endl;
    }
    void visit(PostDec * pd)
    {
        // // expression of postinc must be a variable
        // std::cout << "move $v0" << *(pd->LHS->Name) << std::endl;
        // std::cout << "addui " << *(pd->LHS->Name) << " $v0 -1"<< std::endl;
    }
    void visit(ArgExprList * ael)
    {
        int words = 0;
        for (std::vector<Expression *>::iterator it = ael->Args.begin(); it != ael->Args.end(); it++)
        {
            if (words < 4)
            {
                // move first 4 args into relevant registers
                std::cout << "move $a" << words << " " << std::endl;
            }
            else
            {
                // move other args into stack
            }
            words++;
        }
    }
    void visit(UnaryAddressOperator *) {}
    void visit(UnaryDerefOperator *) {}
    void visit(UnaryPlusOperator * upo)
    {
        // does nothing, equivalent
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        upo->RHS->accept(this);
    }
    void visit(UnaryNegOperator * uno)
    {
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        uno->RHS->accept(this);
        std::cout << "subu " << return_reg << " $zero " << return_reg << std::endl;
    }
    void visit(UnaryBitwiseNotOperator * ubno)
    {
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        ubno->RHS->accept(this);
        std::cout << "xori " << return_reg << return_reg << " 1" << std::endl;
    }
    void visit(UnaryLogicalNotOperator *) {}
    void visit(PreInc * pi)
    {
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        pi->RHS->accept(this);
        std::cout << "addiu " << return_reg << return_reg << " 1" << std::endl;
    }
    void visit(PreDec * pd)
    {
        // TODO find suitable replacement for subiu
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        pd->RHS->accept(this);
        std::cout << "subiu " << return_reg << return_reg << " 1" << std::endl;
    }
    void visit(SizeofExpr *) {}
    void visit(SizeofType *) {}
    void visit(CastExpr *) {}
    std::pair<std::string, std::string> descend(BinaryOpExpression * bop)
    {
        auto ret_A = get_temp_register(gen_name("ret_A_"));
        auto ret_B = get_temp_register(gen_name("ret_B_"));
        return_register.push(ret_A);
        bop->LHS->accept(this);
        return_register.push(ret_B);
        bop->RHS->accept(this);
        return make_pair(ret_A, ret_B);
    }
    void visit(Multiply *m)
    {
        auto intermediates = descend(m);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "multu " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo " << return_reg << std::endl;
    }
    void visit(Divide *d)
    {
        auto intermediates = descend(d);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "divu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mfhi " << return_reg << std::endl;
    }
    void visit(Modulo * m)
    {
        auto intermediates = descend(m);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "divu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo " << return_reg << std::endl;
    }
    void visit(Add * a)
    {
        auto intermediates = descend(a);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "addu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(Sub * s)
    {
        auto intermediates = descend(s);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "subu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(ShiftLeft * sl)
    {
        auto intermediates = descend(sl);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "sllv " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(ShiftRight * sr)
    {
        auto intermediates = descend(sr);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "srlv " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(LessThan * lt)
    {
        auto intermediates = descend(lt);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "slt " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(GreaterThan * gt)
    {
        auto intermediates = descend(gt);
        std::cout << "sub $v0 $zero $v0" << std::endl;
        std::cout << "sub $v1 $zero $v1" << std::endl;
        std::cout << "slt " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        return_register.pop();
    }
    void visit(LessThanOrEqual *) {}
    void visit(GreaterThanOrEqual *) {}
    void visit(EqualTo * et)
    {
        auto intermediates = descend(et);
        std::cout << "xor $v0 " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "li $v1 0xffffffff" << std::endl;
        std::cout << "xor $v0 $v0 $v1" << std::endl;
        std::cout << "li $v1 0xfffffffe" << std::endl;
        std::cout << "sltu " << return_register.top() << " $v0 $v1" << std::endl;
        return_register.pop();
    }
    void visit(NotEqualTo * net)
    {
        auto intermediates = descend(net);
        std::cout << "xor " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        return_register.pop();
    }
    void visit(LogicalAND * la)
    {
        // auto intermediates = descend(la);
        // std::cout << "and " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        // return_register.pop();
    }
    void visit(LogicalOR *) {}
    void visit(BitwiseAND * ba)
    {
        auto intermediates = descend(ba);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "and " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(BitwiseOR * bo)
    {
        auto intermediates = descend(bo);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "or " << return_reg << " " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(BitwiseXOR * bx)
    {
        auto intermediates = descend(bx);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "xor " << return_reg << " " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(TernaryOpExpression * toe)
    {
        // generating branch labels
        auto f = gen_name("ternary_false");
        auto end = gen_name("ternary_end");
        // generating condition expression to store in $v0
        return_register.push("$v0");
        toe->Condition->accept(this);
        // if false go to false label
        std::cout << "beq $v0 $zero " << f << std::endl;
        return_register.push(return_register.top());
        // doing true expression
        std::cout << gen_name("ternary_true") << ':' << std::endl;
        return_register.push(return_register.top());
        toe->IfTrue->accept(this);
        // branch to end
        std::cout << "b " << end << std::endl;
        // do false expression
        std::cout << f << ':' << std::endl;
        return_register.push(return_register.top());
        toe->IfFalse->accept(this);
        // end
        std::cout << end << ':' << std::endl;
        return_register.pop();
    }
    void visit(AssignmentExpression *ae)
    {
        return_register.push("$v0");
        ae->RHS->accept(this);
        std::cout << "move ";
        ae->LHS->accept(this);
        std::cout << " $v0" << std::endl;
    }
    std::pair<std::string,std::string> descend(GenericAssignExpr *gae)
    {
        auto ret_A = gen_name("ret_A_");
        auto ret_B = gen_name("ret_B_");
        return_register.push(ret_A);
        gae->LHS->accept(this);
        return_register.push(ret_B);
        gae->RHS->accept(this);
        return make_pair(ret_A, ret_B);
    }
    void visit(MulAssignment * ma)
    {
        auto intermediates = descend(ma);
        std::cout << "mult, " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo ";
        ma->LHS->accept(this);
        std::cout << std::endl; 
    }
    void visit(DivAssignment * da)
    {
        auto intermediates = descend(da);
        std::cout << "div, " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mfhi ";
        da->LHS->accept(this);
        std::cout << std::endl; 
    }
    void visit(ModAssignment * ma)
    {
        auto intermediates = descend(ma);
        std::cout << "div, " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo ";
        ma->LHS->accept(this);
        std::cout << std::endl; 
    }
    void visit(AddAssignment * aa)
    {
        auto intermediates = descend(aa);
        std::cout << "addu ";
        aa->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(SubAssignment * sa)
    {
        auto intermediates = descend(sa);
        std::cout << "subu ";
        sa->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(ShiftLeftAssignment * sla)
    {
        auto intermediates = descend(sla);
        std::cout << "sllv ";
        sla->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(ShiftRightAssignment * sra)
    {
        auto intermediates = descend(sra);
        std::cout << "srlv ";
        sra->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(BitwiseANDAssignment * baa)
    {
        auto intermediates = descend(baa);
        std::cout << "and ";
        baa->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(BitwiseXORAssignment * bxa)
    {
        auto intermediates = descend(bxa);
        std::cout << "xor ";
        bxa->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(BitwiseORAssignment * boa)
    {
        auto intermediates = descend(boa);
        std::cout << "or ";
        boa->LHS->accept(this);
        std::cout << ", " << intermediates.first << ", " << intermediates.second << std::endl;
    }
    void visit(ConstantExpression *) {}
    void visit(CommaSepExpression *) {}

    //Declarations

    void visit(declaration * dec)
    {
        if (dec->list != NULL)
        {
            dec->list->accept(this);
        }
    }
    void visit(declaration_specifiers *) {}
    void visit(init_declarator_list * il)
    {
        il->init_dec->accept(this);
        if (il->init_dec_list != NULL)
        {
            il->init_dec_list->accept(this);
        }
    }
    void visit(init_declarator *id)
    {
        if (global)
        {
            id->dec->accept(this);
            std::cout << ": ";
            id->init->accept(this);
        }
        else
        {
            if (id->init!=NULL)
            {
                if (id->init->ass_expr!=NULL)
                {
                    return_register.push("$v0");
                    id->init->ass_expr->accept(this);
                    std::cout << "move ";
                    id->dec->accept(this);
                    std::cout << ", $v0" << std::endl;
                }
            }
        }
    }
    void visit(initializer * i)
    {
        if(global)
        {

            if (i->ass_expr != NULL)
            {
                std::cout << ".word ";
                i->ass_expr->accept(this);
                std::cout << std::endl;
            }
            else if (i->init_list != NULL)
            {
                std::cout << std::endl;
                i->init_list->accept(this);

            }
        }
    }
    void visit(initializer_list * il)
    {
        if (il->init_list != NULL)
        {
            il->init_list->accept(this);
        }
        il->init->accept(this);
    }

    void visit(type_specifier *) {}
    void visit(specifier_list *) {}
    void visit(pointer *) {}
    void visit(base_declarator *) {}
    void visit(direct_declarator * dd)
    {
        if (dd->ID != NULL)
        {
            dd->ID->accept(this);
            // std::cout << *(dd->ID->Name);
        }
        else if (dd->dec!=NULL)
        {
            dd->dec->accept(this);
        }
        else
        {
            if (dd->dir_dec != NULL)
            {
                dd->dir_dec->accept(this);
                // std::cout << '(';
                // if (dd->para_list != NULL)
                // {
                //     std::cerr << "going to visit parameters: " << dd->para_list << std::endl;
                //     dd->para_list->accept(this);
                // }
                // std::cout << "):" << std::endl;
            }
        }
    }
    void visit(abstract_declarator *) {}
    void visit(declarator * d)
    {
        d->dir_dec->accept(this);
    }
    void visit(parameter_list *) {}
    void visit(empty_parameter_list *) {}
    void visit(parameter_declaration *) {}

    //Statements
    void visit(EmptyStatement *) {}
    void visit(Continue *)
    {
        std::cout << "b " << continue_to.top() << std::endl;
    }
    void visit(Break *)
    {
        std::cout << "b " << break_to.top() << std::endl;
    }
    void visit(Return * r)
    {
        if (r->ReturnExpression != NULL)
        {
            return_register.push("$v0");
            r->ReturnExpression->accept(this);
        }
        std::cout << "jr $ra" << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(While * w) 
    {
        // creating entry label
        auto beginning = gen_name("while_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("while_end");
        // adding beginning and end as pair to boundry stacks
        continue_to.push(beginning);
        break_to.push(end);
        // evaluate condition
        auto condition = gen_name("while_condition");
        w->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq " << "$v0" << ' ' << "$zero" << ' ' << end << std::endl;
        // do body
        w->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // branch to beginning
        std::cout << "b "<< beginning << std::endl;
        //end
        std::cout << end << ':' << std::endl;
        // std::cout << "const " << destReg << " 0" << std::endl; // we need to return 0
    }
    void visit(DoWhile *dw)
    {
        // creating entry label
        auto beginning = gen_name("while_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("while_end");
        // adding beginning and end as pair to boundry stacks
        continue_to.push(beginning);
        break_to.push(end);
        // evaluate condition
        auto condition = gen_name("while_condition");
        dw->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq " << "$v0" << ' ' << "$zero" << ' ' << end << std::endl;
        // do body
        dw->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // branch to beginning
        std::cout << "b " << beginning << std::endl;
        //end
        std::cout << end << ':' << std::endl;
        // std::cout << "const " << destReg << " 0" << std::endl; // we need to return 0
    }
    void visit(For * f)
    {
        // doing inital statement
        if (f->Init != NULL)
        {
            f->Init->accept(this);
        }
        // creating entry label
        auto beginning = gen_name("for_begin");
        // creating loop exit
        auto end = gen_name("for_end");
        // adding beginning and end as pair to boundry stacks
        continue_to.push(beginning);
        break_to.push(end);
        // writing start
        std::cout << beginning << ':' << std::endl;
        // doing control statement
        if (f->Control != NULL)
        {
            return_register.push("$v0");
            f->Control->accept(this);
        }
        // jump to end if control fails
        std::cout << "beq $v0 $zero " << end << std::endl;
        // executing body
        f->Body->accept(this);
        // do iteration statement
        if (f->Next != NULL)
        {
            f->Next->accept(this);
        }
        // jump to beginning
        std::cout << "beq $v0 $zero " << beginning << std::endl;
        // writing end
        std::cout << end << ':' << std::endl;
        // clearing continue and break
        continue_to.pop();
        break_to.pop();
    }
    void visit(If * i)
    {
        // creating labels
        auto true_case_label = gen_name("if_true");
        auto end_label = gen_name("if_end");
        // evaluating expression
        i->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch to end if false
        std::cout << "beq " << " $v0" << ' ' << " $zero" << ' ' << end_label << std::endl;
        // do true
        std::cout << true_case_label << ':' << std::endl;
        i->IfTrue->accept(this);
        // end
        std::cout << end_label << ':' << std::endl;
    }
    void visit(IfElse *ie)
    {
        // creating labels
        auto true_case_label = gen_name("if_true");
        auto false_case_label = gen_name("if_false");
        auto end_label = gen_name("if_end");
        // evaluating expression
        ie->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch between true or false case
        std::cout << "beq " << " $v0" << ' ' << " $zero" << ' ' << false_case_label << std::endl;
        // do true
        std::cout << true_case_label << ':' << std::endl;
        ie->IfTrue->accept(this);
        std::cout << "b " << end_label << std::endl;
        // do false
        std::cout << false_case_label << ':' << std::endl;
        ie->IfFalse->accept(this);
        // end
        std::cout << end_label << ':' << std::endl;
    }
    void visit(ExpressionStatement * es)
    {
        es->Expr->accept(this);
    }
    void visit(StatementList * sl)
    {
        if (sl->RestOfStatements != NULL)
        {
            sl->RestOfStatements->accept(this);
        }
        sl->statement->accept(this);
    }
    void visit(DeclarationList * dl)
    {
        if (dl->left_list != NULL)
        {
            dl->left_list->accept(this);
        }
        dl->this_decl->accept(this);
    }
    void visit(CompoundStatement * cs)
    {
        if (cs->Decls!=NULL)
        {
            cs->Decls->accept(this);
        }
        if (cs->Statements != NULL)
        {
            cs->Statements->accept(this);
        }
    }
    void visit(Switch * s)
    {
        // creating entry label
        auto beginning = gen_name("switch_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("switch_end");
        auto decision = gen_name("switch_decision");
        // adding beginning and end as pair to boundry stacks
        break_to.push(end);
        // jumping to decision
        std::cout << "b " << decision << std::endl;
        // making case
        s->Body->accept(this);
        break_to.pop();
        std::cout << "b " << end << std::endl;
        //evaluate switch expression
        std::cout << decision << ':' << std::endl;
        return_register.push("$t9"); // stores evaluation in t9 to avoid conflict with expression temps
        s->ControlExpression->accept(this);
        // checking and branching to each case
        while (!cases.empty())
        {
            // std::cerr << "loop" << std::endl;
            auto c = cases.top();
            return_register.push("$v0");
            // std::cerr << "push" << std::endl;
            c.second->accept(this);
            std::cout << "beq $t9 $v0 " << c.first << std::endl;
            cases.pop();
        }
        // or going to default
        std::cout << "b " << default_label << std::endl;
        std::cout << end << ':' << std::endl;
    }
    void visit(CaseOrDefault * cod)
    {
        if (cod->Eval != NULL)
        {
            auto case_label = gen_name("case");
            cases.push(make_pair(case_label, cod->Eval));
            std::cout << case_label << ':' << std::endl;
        }
        else
        {
            default_label = gen_name("default");
            std::cout << default_label << ':' << std::endl;
        }
        cod->Body->accept(this);
    }

    //External definitions
    void visit(TranslationUnit * tu)
    {
        std::cerr << "top of tree" << std::endl;
        for (std::vector<GenericExternalDeclaration *>::iterator it = tu->decls.begin(); it < tu->decls.end(); it++)
        {
            (*it)->accept(this);
        }
        while (!global_labels.empty())
        {
            std::cout << ".global " << global_labels.top() << std::endl;
            global_labels.pop();
        }
    }
    void visit(FunctionDefinition * fd)
    {
        // create function label and parameters
        fd->decl->accept(this);
        std::cout << ':' << std::endl;
        // std::cout << "addiu $sp $sp -8" << std::endl; // moving the stack pointer down by two
        // std::cout << "sw $fp 4($sp)" << std::endl; //storing the previous stack pointer in the second/first word of the new stack
        // std::cout << "move $fp $sp" << std::endl; 
        // return value using return regesters
        global = false;
        fd->Body->accept(this);
        global = true;
        // if no return statement is used must still jump back
        std::cout << "jr $ra" << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(ExternalDeclaration * ed)
    {
        std::cerr << "ex dec" << std::endl;
        ed->decl->accept(this);
    }
};

#endif