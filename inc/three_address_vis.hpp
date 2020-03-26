#ifndef THRADDR_HPP
#define THRADDR_HPP

#include <string>
#include <unordered_set>
#include <iostream>
#include <typeinfo>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
// #include "visitors.hpp"
#include "ast_allnodes.hpp"

class vm
{
    /*
    A class for tracking the position of variables on the stack
    */
    public:
    int stack_size;
    std::unordered_map<std::string, int> m;
    public:
    vm():stack_size(0){}
    void update(int offset, bool in_stack = true)
    {
        std::cerr << "UPDATE" << std::endl;
        if (in_stack) stack_size+=offset;
        for(auto & p : m)
        {
            p.second += offset;
        }
    }
    int lookup(std::string s)
    {
        return m[s];
    }
    void register_variable(std::string s, int x)
    {
        m[s] = x;
    }
    bool contains(std::string s)
    {
        return m.find(s) != m.end() && !m.empty();
    }
    void clear()
    {
        m.clear();
    }
    int get_stack_size()
    {
        return stack_size;
    }
};



class three_address_Visitor : public Visitor
{
    public:
    three_address_Visitor(): counter(0), return_register(), continue_to(), break_to(), cases(), global(true), global_labels(), intermediate_values(), temporary_registers(), saved_registers(), variable_map(), writing(false), parameter_flag(false), func_call_flag(false), array_flag(false), initlist_count(0)
    {
        for (int i = 9; i >= 0; i--)
            temporary_registers.push("$t"+std::to_string(i));
        for (int i = 7; i >= 0; i--)
            saved_registers.push("$s"+std::to_string(i));
    }
    int counter;
    std::stack<std::string> return_register; // a stack which tracks which of the two return registers to use
    std::stack<std::string> continue_to; // stores where a continue should jump to
    std::stack<std::string> break_to; // stores where a break should jump to 
    // std::stack<std::string> temporary_words; 
    bool global; // a flag for tracking if declaration is global or is in a scope.
    std::unordered_set<std::string> global_labels;
    std::stack<std::pair<std::string,Expression*>> cases; // a stack sructure used when generating switch case code
    std::string default_label; // used as a seperate place to store a default label for switch cases
    std::stack<std::string> intermediate_values; // a stack for counting the intermediate values of a function
    std::stack<std::string> temporary_registers;
    std::stack<std::string> saved_registers;
    bool writing;
    bool parameter_flag;
    bool func_call_flag;
    bool array_flag;
    int local_words, arg_words;
    int stacksize;
    int parameter_size;
    std::string function_end;
    vm variable_map; // a map of variable name to stack offset and what register it might be stored in
    std::string array_name;
    int initlist_count;
    std::unordered_map<std::string, int> enum_symbol_map;
    int enum_counter;
    std::string get_temp_register(const std::string &inter)
    {
        if (!saved_registers.empty())
        {
            auto r = saved_registers.top();
            saved_registers.pop();
            return r;
        }
        else
        {
            std::cout << "ERROR too many intermediate values" << std::endl;
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
        std::cerr << "ID" << std::endl;
        if (array_flag) array_name = in->ContextRecord->unique_id;
        if (parameter_flag)
        {
            std::cerr << "parameter flag" << std::endl;
            variable_map.update(4, false);
            variable_map.register_variable(in->ContextRecord->unique_id, 4);
        }
        else if (func_call_flag)
        {
            std::cerr << "func call flag" << std::endl;
            std::cout << (in->Name);
        }
        else if (!writing)
        {
            std::cerr << "reading" << std::endl;
            if (return_register.empty())
            {
                //function definition
                std::cout << (in->Name);
                if (global)
                {
                    global_labels.insert(in->Name);
                }
            }
            else
            {
                // std::cout << *(in->Name);
                // expression terminal
                // auto return_reg = return_register.top();
                // return_register.pop();
                // if (variable_map[*(in->Name)].second == "spill")
                // {
                //     std::cout << "lw " << saved_registers.top() << ", " << variable_map[*(in->Name)].first << "($fp)" << std::endl;
                //     std::cout << "move " << return_reg << ", " << saved_registers.top() << std::endl;
                //     variable_map[*(in->Name)].second = saved_registers.top();
                //     saved_registers.pop();

                // }
                // else
                // {
                //     std::cout << "move " << return_reg << ", " << variable_map[*(in->Name)].second << std::endl;
                // }
                auto return_reg = return_register.top();
                return_register.pop();
                if (enum_symbol_map.find(in->Name) == enum_symbol_map.end())
                {
                    // std::cout << "move " << return_reg << ", " << (in->Name) << std::endl;
                    std::cout << "# reading variable " << in->ContextRecord->unique_id << std::endl;
                    std::cout << "lw " << return_reg << ", " << variable_map.lookup(in->ContextRecord->unique_id) << "($fp) " << std::endl; // still need to add frame offset TODO
                    std::cout << "nop" << std::endl;
                }
                else
                {
                    std::cout << "li " << return_reg << ", " << enum_symbol_map[in->Name] << std::endl;
                }
            }
        }
        else
        {
            std::cerr << "writing: " << in->Name << std::endl;
            std::cerr << (in->ContextRecord == NULL) << std::endl;
            if (!global)
            {
                if (!variable_map.contains(in->ContextRecord->unique_id))
                {
                    std::cerr << "new" << std::endl;
                    stacksize+=4;
                    variable_map.update(4);
                    std::cout << "# allocating space for " << in->ContextRecord->unique_id << std::endl;
                    std::cout << "addiu $sp, $sp, -4" << std::endl;
                    std::cout << "move $fp, $sp" << std::endl;
                    std::cout << "sw $v0, 4($fp)" << std::endl; // still need to add frame offset TODO
                    std::cout << "nop" << std::endl;
                    variable_map.register_variable(in->ContextRecord->unique_id, 4);
                }
                else
                {
                    std::cerr << "old" << std::endl;
                    std::cout << "# writing to variable " << in->ContextRecord->unique_id << std::endl;
                    std::cout << "sw $v0, " << variable_map.lookup(in->ContextRecord->unique_id) << "($fp)" << std::endl; // still need to add frame offset TODO
                    std::cout << "nop" << std::endl;
                }
            }
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
            std::cout << "li " << return_reg << ", " << ci->value << std::endl;
        }
    }
    void visit(ArraySubscript * as)
    {
        std::cerr << "subscript!!!" << std::endl;
        // get subscript expression
        return_register.push("$t0");
        as->Subscript->accept(this);
        // assume it is int, multiply by 4
        std::cout << "sll $t0, $t0, 2" << std::endl;
        // getting array name, stored in array_name string
        // array_flag = true;
        // as->LHS->accept(this);
        // array_flag = false;
        if (global)
        {
            std::cout << "# accessing global array " << array_name << std::endl;
            // if array is global
            // get array address
            std::cout << "la $t1, " << array_name << std::endl;
            // add subscript and 
            std::cout << "addu $t0 $t0 $t1";
            if (!writing)
            {
                // reading from array
                // get return register
                auto return_reg = return_register.top();
                // load relevant word
                std::cout << "lw " << return_reg << " $t0" << std::endl;
                std::cout << "nop" << std::endl;
                return_register.pop();
            }
            // else
            // {
            //     std::cout << "lw " << return_reg << " $v0" << std::endl;
            //     std::cout << "nop" << std::endl;

            // }
            global = false;
        }
        else
        {
            std::cout << "# accessing local array " << array_name << std::endl;
            // getting array offset
            auto tmp_write = writing;
            writing = false;
            return_register.push("$t1");
            as->LHS->accept(this);
            writing = tmp_write;
            // add subscript and frame pointer
            std::cout << "addu $t0, $t0, $t1" << std::endl;
            if (!writing)
            {
                // reading from array
                // get return register
                auto return_reg = return_register.top();
                // load relevant word
                std::cout << "lw " << return_reg << ", 0($t0)" << std::endl;
                std::cout << "nop" << std::endl;
                return_register.pop();
            }
            else
            {
                std::cout << "sw $v0, 0($t0)" << std::endl;
                std::cout << "nop" << std::endl;
                
            }
            
        }
    }
    void visit(FuncCall * fc)
    {
        int no_args = 0;
        // REMEMBER, PUSH TO STACK ENOUGH SPACE FOR ALL WORDS USED BY FUNCTION ARGUMENT
        if (fc->Args != NULL)
        {
            no_args = fc->Args->Args.size();
            no_args = std::max(no_args,4);
            std::cout << "# making room on the stack for arguments" << std::endl;
            std::cout << "addiu $sp, $sp, " << -no_args*4 << std::endl;
            std::cout << "move $fp, $sp " << std::endl;
            variable_map.update(no_args*4);
            // insert arguments
            fc->Args->accept(this);
        }
        // jump and link
        std::cout << "jal ";
        func_call_flag = true;
        fc->LHS->accept(this);
        func_call_flag = false;
        std::cout << std::endl;
        std::cout << "nop" << std::endl; // moving returned value to specified register
        std::cout << "move " << return_register.top() << ", $v0" << std::endl; // moving returned value to specified register
        return_register.pop();
        if (fc->Args != NULL)
        {
            std::cout << "# freeing function call arguments from stack" << std::endl;
            std::cout << "addiu $sp, $sp, " << no_args*4 << std::endl;
            std::cout << "move $fp, $sp " << std::endl;
            variable_map.update(-no_args*4);
        }
    }
    void visit(MemberAccess *) {}
    void visit(DerefMemberAccess *) {}
    void visit(PostInc * pi)
    {
        std::cerr << "PI" << std::endl;
        return_register.push(return_register.top());
        pi->LHS->accept(this);
        std::cout << "addiu $v0, " << return_register.top() << ", 1" << std::endl;
        return_register.pop();
        writing = true;
        pi->LHS->accept(this);
        writing = false;
    }
    void visit(PostDec * pd)
    {
        std::cerr << "PD" << std::endl;
        return_register.push(return_register.top());
        pd->LHS->accept(this);
        std::cout << "addiu $v0, " << return_register.top() << ", -1" << std::endl;
        return_register.pop();
        writing = true;
        pd->LHS->accept(this);
        writing = false;
    }
    void visit(ArgExprList * ael)
    {
        for (int i = ael->Args.size() - 1 ; i >= 0; i--)
        {
            // evaluating arguments
            auto r = (i < 4) ? "$a" + std::to_string(i) : "$v0";
            return_register.push(r);
            ael->Args[i]->accept(this);
            // // store all arguments on stack
            std::cout << "sw " << r << ", " << (i+1)*4 << "($fp)" << std::endl;
            std::cout << "nop" << std::endl;
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
    void visit(UnaryLogicalNotOperator * ulno)
    {
        auto return_reg = return_register.top();
        return_register.pop();
        return_register.push(return_reg);
        ulno->RHS->accept(this);
        std::cout << "sne " << return_reg << return_reg << " $zero" << std::endl;
    }
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
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(Divide *d)
    {
        auto intermediates = descend(d);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "divu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo " << return_reg << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(Modulo * m)
    {
        auto intermediates = descend(m);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "divu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mfhi " << return_reg << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(Add * a)
    {
        auto intermediates = descend(a);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "addu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(Sub * s)
    {
        auto intermediates = descend(s);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "subu " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ShiftLeft * sl)
    {
        auto intermediates = descend(sl);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "sllv " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ShiftRight * sr)
    {
        auto intermediates = descend(sr);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "srlv " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(LessThan * lt)
    {
        auto intermediates = descend(lt);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "slt " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(GreaterThan * gt)
    {
        auto intermediates = descend(gt);
        // std::cout << "sub $v0 $zero $v0" << std::endl;
        // std::cout << "sub $v1 $zero $v1" << std::endl;
        // std::cout << "slt " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "sgt " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        return_register.pop();
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(LessThanOrEqual * ltoe)
    {
        auto intermediates = descend(ltoe);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "sle " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(GreaterThanOrEqual * gtoe)
    {
        auto intermediates = descend(gtoe);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "sge " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(EqualTo * et)
    {
        auto intermediates = descend(et);
        // std::cout << "xor $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        // std::cout << "li $v1, 0xffffffff" << std::endl;
        // std::cout << "xor $v0, $v0, $v1" << std::endl;
        // std::cout << "li $v1, 0xfffffffe" << std::endl;
        // std::cout << "sltu " << return_register.top() << ", $v0, $v1" << std::endl;
        std::cout << "seq $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        return_register.pop();
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(NotEqualTo * net)
    {
        auto intermediates = descend(net);
        // std::cout << "xor " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "sne " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        return_register.pop();
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(LogicalAND * la)
    {
        auto intermediates = descend(la);
        std::cout << "sne " << intermediates.first << ", " << intermediates.first << ", $zero" << std::endl;
        std::cout << "sne " << intermediates.second << ", " << intermediates.second << ", $zero" << std::endl;
        std::cout << "and " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "sne " << return_register.top() << ", " << return_register.top() << ", $zero" << std::endl;
        return_register.pop();
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(LogicalOR * lo)
    {
        auto intermediates = descend(lo);
        std::cout << "or " << return_register.top() << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "sne " << return_register.top() << ", " << return_register.top() << ", $zero" << std::endl;
        return_register.pop();
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseAND * ba)
    {
        auto intermediates = descend(ba);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "and " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseOR * bo)
    {
        auto intermediates = descend(bo);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "or " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseXOR * bx)
    {
        auto intermediates = descend(bx);
        auto return_reg = return_register.top();
        return_register.pop();
        std::cout << "xor " << return_reg << ", " << intermediates.first << ", " << intermediates.second << std::endl;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
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
        std::cout << "beq $v0, $zero, " << f << std::endl;
        std::cout << "nop" << std::endl;
        return_register.push(return_register.top());
        // doing true expression
        std::cout << gen_name("ternary_true") << ':' << std::endl;
        return_register.push(return_register.top());
        toe->IfTrue->accept(this);
        // branch to end
        std::cout << "b " << end << std::endl;
        std::cout << "nop" << std::endl;
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
        // std::cout << "move ";
        writing = true;
        ae->LHS->accept(this);
        writing = false;
        // std::cout << " $v0" << std::endl;
    }
    std::pair<std::string,std::string> descend(GenericAssignExpr *gae)
    {
        auto ret_A = get_temp_register(gen_name("ret_A_"));
        auto ret_B = get_temp_register(gen_name("ret_B_"));
        return_register.push(ret_A);
        gae->LHS->accept(this);
        return_register.push(ret_B);
        gae->RHS->accept(this);
        return make_pair(ret_A, ret_B);
    }
    void visit(MulAssignment * ma)
    {
        auto intermediates = descend(ma);
        std::cout << "mult " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo $v0" << std::endl;
        writing = true;
        ma->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(DivAssignment * da)
    {
        auto intermediates = descend(da);
        std::cout << "div " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mfhi $v0" << std::endl;
        writing = true;
        da->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ModAssignment * ma)
    {
        auto intermediates = descend(ma);
        std::cout << "div, " << intermediates.first << ", " << intermediates.second << std::endl;
        std::cout << "mflo $v0" << std::endl;
        writing = true;
        ma->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(AddAssignment * aa)
    {
        auto intermediates = descend(aa);
        std::cout << "addu $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        aa->LHS->accept(this);
        writing = false;  
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(SubAssignment * sa)
    {
        auto intermediates = descend(sa);
        std::cout << "subu $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        sa->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ShiftLeftAssignment * sla)
    {
        auto intermediates = descend(sla);
        std::cout << "sllv $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        sla->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ShiftRightAssignment * sra)
    {
        auto intermediates = descend(sra);
        std::cout << "srlv $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        sra->LHS->accept(this);
        writing = false;  
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseANDAssignment * baa)
    {
        auto intermediates = descend(baa);
        std::cout << "and $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        baa->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseXORAssignment * bxa)
    {
        auto intermediates = descend(bxa);
        std::cout << "xor $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        bxa->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(BitwiseORAssignment * boa)
    {
        auto intermediates = descend(boa);
        std::cout << "or $v0, " << intermediates.first << ", " << intermediates.second << std::endl;
        writing = true;
        boa->LHS->accept(this);
        writing = false;
        saved_registers.push(intermediates.first);
        saved_registers.push(intermediates.second);
    }
    void visit(ConstantExpression *) {}
    void visit(CommaSepExpression *) {}

    //Declarations

    void visit(declaration * dec)
    {
        dec->specifier->accept(this);
        if (dec->list != NULL)
        {
            writing = true;
            dec->list->accept(this);
            writing = false;
        }
    }
    void visit(declaration_specifiers * ds)
    {
        if (ds->type_spec != NULL) ds->type_spec->accept(this);
        else if (ds->storage_class_specifier != NULL) ds->storage_class_specifier->accept(this);
        if (ds->specifier != NULL) ds->specifier->accept(this);
    }
    void visit(init_declarator_list * il)
    {
        if (il->init_dec_list != NULL)
        {
            il->init_dec_list->accept(this);
        }
        il->init_dec->accept(this);
    }
    void visit(init_declarator *id)
    {
        std::cerr << "init D" << std::endl;
        if (global)
        {
            id->dec->accept(this);
            // std::cout << ": ";
            if (id->init != NULL) id->init->accept(this);
        }
        else
        {
            writing = true;
            id->dec->accept(this);
            if (id->init!=NULL)
            {
                if (id->init->ass_expr!=NULL)
                {
                    return_register.push("$v0");
                    id->init->ass_expr->accept(this);
                    while (!intermediate_values.empty()) intermediate_values.pop();
                    // std::cout << "move ";
                    writing = true;
                    id->dec->accept(this);
                    writing = false;
                    // std::cout << ", $v0" << std::endl;
                }
            }
            writing = false;
        }
    }
    void visit(initializer * i)
    {
        std::cerr << "init" << std::endl;
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
        else
        {
            if (i->ass_expr != NULL)
            {
                return_register.push("$v0");
                i->ass_expr->accept(this);
                std::cout << "sw $v0, " << std::endl;
                std::cout << "nop" << std::endl;
            }
            else if (i->init_list != NULL)
            {
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
        std::cerr << "DD" << std::endl;
        if (dd->ID != NULL)
        {
            dd->ID->accept(this);
        }
        else if (dd->dec!=NULL)
        {
            dd->dec->accept(this);
        }
        else
        {
            if (dd->dir_dec != NULL)
            {
                if (dd->const_expr != NULL) array_flag = true;
                dd->dir_dec->accept(this);
                if (dd->para_list != NULL)
                {
                    dd->para_list->accept(this);
                }
                else if (dd->const_expr != NULL)
                {
                    // assume const expression is a number (not a variable or expression)
                    int no_elements = dd->const_expr->ConstantSubtree->constEval();
                    if (!global)
                    {
                        if (no_elements == 0)
                        {
                            // array size has not been specified
                            // TODO DO SOMETHING
                        }
                        else
                        {
                            //assuming type is int
                            std::cout << "# allocating " << no_elements*4 << " bytes for array " << array_name << " on function stack" << std::endl;
                            std::cerr << -no_elements*4 << std::endl;
                            std::cout << "addiu $sp, $sp, " << -no_elements*4 << std::endl;
                            std::cout << "move $fp, $sp" << std::endl;
                            for (int i = no_elements-1; i >= 0 ; i--)
                            {
                                variable_map.update(4);
                                variable_map.register_variable(array_name+'['+std::to_string(i)+']', 4);
                                // std::cout << "sw $zero, 4($fp)" << std::endl;
                                // std::cout << "nop" << std::endl;
                            }
                        }
                        // std::cout << "# creating " << array_name << " as a pointer to the base of the array" << std::endl;
                        // std::cout << "addiu $v0, $sp, 4" << std::endl;
                        // std::cout << "sw $v0, 0($sp)" << std::endl;
                        std::cout << "addiu $v0, $fp, " << variable_map.lookup(array_name+"[0]") << std::endl;
                        std::cout << "sw $v0, " << variable_map.lookup(array_name) << "($fp)" << std::endl;
                        std::cout << "nop" << std::endl;
                    }
                    else
                    {
                        std::cout << array_name << ':' << " .space " <<  no_elements*4 << std::endl;
                    }
                    
                    array_flag = false;
                }
            }
        }
    }
    void visit(abstract_declarator *) {}
    void visit(declarator * d)
    {
        std::cerr << "D" << std::endl;
        d->dir_dec->accept(this);
    }
    void visit(parameter_list * pl)
    {
        pl->para_dec->accept(this);
        if (pl->para_list != NULL)
        {
            pl->para_list->accept(this);
        }
    }
    void visit(empty_parameter_list *) {}
    void visit(parameter_declaration * pd)
    {
        parameter_size++;
        parameter_flag=true;
        pd->dec->accept(this);
        parameter_flag=false;
    }
    void visit(Enumerator* _enum)
    {
        if (_enum->OptionalValue != NULL)
        {
            auto val = _enum->OptionalValue->constEval();
            enum_symbol_map[_enum->ConstID->Name] = val;
            enum_counter = ++val;
        }
        else
        {
            enum_symbol_map[_enum->ConstID->Name] = enum_counter++;
        }
    }
    void visit(EnumeratorList* _enumlist)
    {
        enum_counter=0;
        for (const auto &e : _enumlist->List) e->accept(this);
    }
    void visit(EnumSpecifier* _enumspec)
    {
        if (_enumspec->options!=NULL) _enumspec->options->accept(this);
    }

    //Statements
    void visit(EmptyStatement *) {}
    void visit(Continue *)
    {
        std::cout << "b " << continue_to.top() << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(Break *)
    {
        std::cout << "b " << break_to.top() << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(Return * r)
    {
        if (r->ReturnExpression != NULL)
        {
            return_register.push("$v0");
            r->ReturnExpression->accept(this);
        }
        std::cout << "b " << function_end << std::endl;
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
        return_register.push("$v0");
        w->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq $v0, $zero, " << end << std::endl;
        std::cout << "nop" << std::endl;
        // do body
        w->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // branch to beginning
        std::cout << "b "<< beginning << std::endl;
        std::cout << "nop" << std::endl;
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
        return_register.push("$v0");
        dw->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq $v0, $zero, " << end << std::endl;
        std::cout << "nop" << std::endl;
        // do body
        dw->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // branch to beginning
        std::cout << "b " << beginning << std::endl;
        std::cout << "nop" << std::endl;
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
        std::cout << "beq $v0, $zero, " << end << std::endl;
        std::cout << "nop" << std::endl;
        // executing body
        f->Body->accept(this);
        // do iteration statement
        if (f->Next != NULL)
        {
            f->Next->accept(this);
        }
        // jump to beginning
        std::cout << "beq $v0, $zero, " << beginning << std::endl;
        std::cout << "nop" << std::endl;
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
        return_register.push("$v0");
        i->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch to end if false
        std::cout << "beq $v0, $zero, " << end_label << std::endl;
        std::cout << "nop" << std::endl;
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
        return_register.push("$v0");
        ie->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch between true or false case
        std::cout << "beq $v0, $zero, " << false_case_label << std::endl;
        std::cout << "nop" << std::endl;
        // do true
        std::cout << true_case_label << ':' << std::endl;
        ie->IfTrue->accept(this);
        std::cout << "b " << end_label << std::endl;
        std::cout << "nop" << std::endl;
        // do false
        std::cout << false_case_label << ':' << std::endl;
        ie->IfFalse->accept(this);
        // end
        std::cout << end_label << ':' << std::endl;
    }
    void visit(ExpressionStatement * es)
    {
        es->Expr->accept(this);
        while (!intermediate_values.empty()) intermediate_values.pop();
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
        std::cout << "nop" << std::endl;
        // making case
        s->Body->accept(this);
        break_to.pop();
        std::cout << "b " << end << std::endl;
        std::cout << "nop" << std::endl;
        //evaluate switch expression
        std::cout << decision << ':' << std::endl;
        return_register.push("$v0"); // stores evaluation in t9 to avoid conflict with expression temps
        s->ControlExpression->accept(this);
        // checking and branching to each case
        while (!cases.empty())
        {
            // std::cerr << "loop" << std::endl;
            auto c = cases.top();
            return_register.push("$v1");
            // std::cerr << "push" << std::endl;
            c.second->accept(this);
            std::cout << "beq $v0, $v1, " << c.first << std::endl;
            std::cout << "nop" << std::endl;
            cases.pop();
        }
        // or going to default
        std::cout << "b " << default_label << std::endl;
        std::cout << "nop" << std::endl;
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
        // while (!global_labels.empty())
        // {
        //     std::cout << ".global " << global_labels.top() << std::endl;
        //     global_labels.pop();
        // }
        for (const std::string & s : global_labels) std::cout << ".global " << s << std::endl;
    }
    void visit(FunctionDefinition * fd)
    {
        // create function label and parameters
        parameter_size = 0; // also count number of words used by argument
        variable_map = vm();
        fd->decl->accept(this);
        std::cout << ':' << std::endl;

        // generating stack handler label
        auto stack_handler = gen_name("PUSH");
        // jumping to stack handler
        // creatinge end label
        auto end = gen_name("POP");
        function_end = end;
        // SETUP STACK
        std::cout << stack_handler << ':' << std::endl;
        // store first four parameters IF they are provided
        for (int i = 0; i < parameter_size; i++)
        {
            if  (i < 4)
            {
                std::cout << "sw $a" << i << ", " << (i+1)*4 << "($sp)" << std::endl;
                std::cout << "nop" << std::endl;
            }
        }
        // make space for local variables
        stacksize = 8 + 8*4; // by default we assign space for return address, old stack pointer, and saved registers
        variable_map.update(stacksize);
        std::cout << "addiu $sp, $sp, " << -stacksize << std::endl;
        // store return address
        std::cout << "sw $ra, " << stacksize << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        // store previous stack pointer
        std::cout << "sw $fp, " << stacksize - 4 << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        // move fp to sp
        // make space for saved registers (always going to be)
        for (int i = 0; i < 8; i++)
        {
            std::cout << "sw $s" << i << ", " << (i+1)*4 << "($sp)" << std::endl;
            std::cout << "nop" << std::endl;
        }
        std::cout << "move $fp, $sp" << std::endl;
        // processing body
        auto body = gen_name("body");
        std::cout << body << ':' << std::endl;

        global = false;
        fd->Body->accept(this);
        global = true;
        // FREE STACK
        stacksize = variable_map.get_stack_size();
        std::cout << end << ':' << std::endl;
        // restore saved registers
        for (int i = 0; i < 8; i++)
        {
            std::cout << "lw $s" << i << ", " << stacksize - (9-i) * 4 << "($sp)" << std::endl;
            std::cout << "nop" << std::endl;
        }
        // restore return address
        std::cout << "lw $ra, " << stacksize << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        // restore stack pointer
        std::cout << "lw $fp, " << stacksize -4 << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        std::cout << "move $sp, $fp" << std::endl;
        // jump to original
        std::cout << "jr $ra" << std::endl;
        std::cout << "nop" << std::endl;
        std::cout << std::endl << std::endl;
    }
    void visit(ExternalDeclaration * ed)
    {
        std::cerr << "ex dec" << std::endl;
        ed->decl->accept(this);
        std::cout << std::endl << std::endl;
    }
};



#endif