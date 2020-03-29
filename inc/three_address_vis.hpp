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
#include <vector>
// #include "visitors.hpp"
#include "ast_allnodes.hpp"
#include "ast_TypeInfo.hpp"

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
    three_address_Visitor(): counter(0), return_register(), continue_to(), break_to(), cases(), global(true), global_labels(), intermediate_values(), temporary_registers(), saved_registers(), variable_map(), writing(false), parameter_flag(false), func_flag(false), array_flag(false), initlist_count(0), address_flag(false), struct_flag(false), struct_fetch_record(false), sizeof_flag(false), string_literal_flag(false)
    {
        for (int i = 9; i >= 0; i--)
            temporary_registers.push("$t"+std::to_string(i));
        for (int i = 7; i >= 0; i--)
            saved_registers.push("$s"+std::to_string(i));
    }
    int counter;
    std::stack<std::string> return_register; // a stack which tracks which of the two return registers to use
    std::stack<std::pair<std::string, int>> continue_to; // stores where a continue should jump to, and the stack size it should return to
    std::stack<std::pair<std::string, int>> break_to; // stores where a break should jump to, and the stack size it should return to
    // std::stack<std::string> temporary_words; 
    bool global; // a flag for tracking if declaration is global or is in a scope.
    std::unordered_set<std::string> global_labels;
    std::stack<std::pair<std::string,int>> cases; // a stack sructure used when generating switch case code
    std::string default_label; // used as a seperate place to store a default label for switch cases
    std::stack<std::string> intermediate_values; // a stack for counting the intermediate values of a function
    std::stack<std::string> temporary_registers;
    std::stack<std::string> saved_registers;
    bool writing;
    bool parameter_flag;
    bool func_flag;
    bool array_flag;
    int local_words, arg_words;
    int stacksize;
    int parameter_size;
    std::string function_end;
    vm variable_map; // a map of variable name to stack offset and what register it might be stored in
    std::string array_name;
    int initlist_count;
    bool address_flag;
    std::string address_name;
    std::unordered_map<std::string, int> enum_symbol_map;
    int enum_counter;
    bool struct_flag;
    bool struct_fetch_record;
    bool string_literal_flag;
    std::vector<Record*> struct_record;
    std::unordered_map<std::string, int> sizeof_variables;
    bool sizeof_flag;
    void pop(std::string reg, int stack_offset = 0) { std::cout << "lw " << reg << ", " << stack_offset << "($sp)" << std::endl << "nop" << std::endl;}
    void push(std::string reg, int stack_offset = 0) { std::cout << "sw " << reg << ", " << stack_offset << "($sp)" << std::endl << "nop" << std::endl;}
    void move(std::string dest, std::string src) { std::cout << "move " << dest << ", " << src << std::endl; }
    void li(int val, std::string dest = "$v0") {std::cout << "li " << dest << ", " << val << std::endl;}
    void mt_c(std::string dest, std::string src) { std::cout << "mtc1 " << src << ", " << dest << std::endl; }
    void mf_c(std::string dest, std::string src) { std::cout << "mfc1 " << dest << ", " << src << std::endl; }
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
        // if (true)
        // {
        //     if (writing)
        //     {
        //         int size = in->ContextRecord->GetPrimary()->members->subRecords.size()*4;
        //         std::cout << "addiu $sp, $sp, " << -size << std::endl;
        //         move("$fp", "$sp");
        //         for (const auto & r : in->ContextRecord->GetPrimary()->members->subRecords)
        //         {


        //         }
        //     }
        // }
        if (struct_fetch_record) struct_record = in->ContextRecord->GetPrimary()->get_table()->subRecords;
        if (parameter_flag)
        {
            std::cerr << "parameter flag" << std::endl;
            variable_map.update(4, false);
            variable_map.register_variable(in->ContextRecord->unique_id, 0);
        }
        else if (sizeof_flag) li(sizeof_variables[in->ContextRecord->get_unique_id()]);
        else if (func_flag)
        {
            std::cerr << "func flag" << std::endl;
            std::cout << (in->Name);
            if (global)
            {
                global_labels.insert(in->Name);
            }
        }
        else if (address_flag) address_name = in->ContextRecord->unique_id;
        else if (!writing)
        {
            std::cerr << "reading" << std::endl;
            if (enum_symbol_map.find(in->Name) == enum_symbol_map.end())
            {
                std::cout << "# reading variable " << in->ContextRecord->unique_id << std::endl;
                std::cout << "lw $v0, " << variable_map.lookup(in->ContextRecord->unique_id) << "($fp) " << std::endl; // still need to add frame offset TODO
                std::cout << "nop" << std::endl;
            }
            else
            {
                std::cout << "li $v0, " << enum_symbol_map[in->Name] << std::endl;
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
                    // stacksize+=4;
                    variable_map.update(4);
                    std::cout << "# allocating space for " << in->ContextRecord->unique_id << std::endl;
                    std::cout << "addiu $sp, $sp, -4" << std::endl;
                    std::cout << "move $fp, $sp" << std::endl;
                    std::cout << "sw $v0, 4($fp)" << std::endl; // still need to add frame offset TODO
                    std::cout << "nop" << std::endl;
                    variable_map.register_variable(in->ContextRecord->unique_id, 4);
                    sizeof_variables[in->ContextRecord->unique_id] = 4;
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
        if (struct_flag) 
        {
            std::cerr << "allocating struct space" << std::endl;
            int no_elements = 0;
            no_elements = in->ContextRecord->GetPrimary()->get_table()->subRecords.size();
            std::cerr << "here" << std::endl;
            std::string struct_name = in->ContextRecord->unique_id;
            if (!global)
            {
                //assuming type is int
                std::cout << "# allocating " << no_elements*4 << " bytes for structure " << struct_name << " on function stack" << std::endl;
                std::cerr << -no_elements*4 << std::endl;
                std::cout << "addiu $sp, $sp, " << -no_elements*4 << std::endl;
                std::cout << "move $fp, $sp" << std::endl;
                std::string last;
                for (auto & r : in->ContextRecord->GetPrimary()->get_table()->subRecords)
                {
                    variable_map.update(4);
                    variable_map.register_variable(struct_name+'.'+r->get_unique_id(), 4);
                    last = r->get_unique_id();
                }
                std::cout << "addiu $v0, $fp, " << variable_map.lookup(struct_name+"."+last) << std::endl;
                std::cout << "sw $v0, " << variable_map.lookup(struct_name) << "($fp)" << std::endl;
                std::cout << "nop" << std::endl;
            }
            sizeof_variables[struct_name]=no_elements*4;
            struct_flag = false;
        }
    }
    void visit(Constant *) {}
    void visit(constant_int * ci)
    {
        // if (return_register.empty())
        // {
        //     std::cout << ci->value;
        // }
        // else
        // {
        std::cout << "li $v0, " << ci->value << std::endl;
        // }
    }
    virtual void visit(constant_char * cc)
    {
        std::cerr << "character string " << cc->constant << std::endl;
        std::cout << "li $v0, " << (int)cc->constant[0] << std::endl;
    }
    void visit(StringLiteral * sl)
    {
        std::cerr << "string literal: " << sl->str << std::endl;
        int size = sl->str.length()+1;
        size = size + (4-size%4);
        std::cout << "# allocating " << size << " bytes for string " << sl->str << std::endl;
        std::cout << "addiu $sp, $sp, " << -size-4 << std::endl;
        move("$fp", "$sp");
        for (int i = 0; i < sl->str.length(); i++) 
        {
            li((int)sl->str[i]);
            std::cout << "sb $v0, " << i+4 << "($sp)" << std::endl;
        }
        li((int)'\0');
        std::cout << "sb $v0, " << sl->str.length() << "($sp)" << std::endl;
        // storing pointer to string beginning in $v0
        std::cout << "addiu $v0, $sp, 4" << std::endl;
        variable_map.update(size+4);

    }
    void visit(ArraySubscript * as)
    {
        std::cerr << "subscript!!!" << std::endl;
        move("$t2","$v0");
        // get subscript expression
        as->Subscript->accept(this);
        move("$t0", "$v0");
        // assume it is int, multiply by 4
        TypeGetter * t = new TypeGetter();
        auto info = as->acceptTypeGetter(t);
        delete t;
        std::cerr << "type info options " << info->Options << std::endl;
        switch(info->Options)
        {
            case(TypeInfo::CHAR): break;
            default:
                std::cout << "sll $t0, $t0, 2" << std::endl;
        }
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
                // load relevant word
                std::cout << "lw $v0, 0($t0)" << std::endl;
                std::cout << "nop" << std::endl;
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
            as->LHS->accept(this);
            move("$t1","$v0");
            writing = tmp_write;
            // add subscript and frame pointer
            std::cout << "addu $t0, $t0, $t1" << std::endl;
            if (!writing)
            {
                // reading from array
                // get return register
                // load relevant word
                // std::cout << "lw $v0, 0($t0)" << std::endl;
                switch(info->Options)
                {
                    case(TypeInfo::CHAR): 
                        std::cout << "lb $v0, 0($t0)" << std::endl;
                        break;
                    default:
                        std::cout << "lw $v0, 0($t0)" << std::endl;
                }
                std::cout << "nop" << std::endl;
            }
            else
            {
                move("$v0","$t2");
                switch(info->Options)
                {
                    case(TypeInfo::CHAR): 
                        std::cout << "sb $v0, 0($t0)" << std::endl;
                        break;
                    default:
                        std::cout << "sw $v0, 0($t0)" << std::endl;
                }
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
        func_flag = true;
        fc->LHS->accept(this);
        func_flag = false;
        std::cout << std::endl;
        std::cout << "nop" << std::endl; // moving returned value to specified register
        if (fc->Args != NULL)
        {
            std::cout << "# freeing function call arguments from stack" << std::endl;
            std::cout << "addiu $sp, $sp, " << no_args*4 << std::endl;
            std::cout << "move $fp, $sp " << std::endl;
            variable_map.update(-no_args*4);
        }
    }
    void visit(MemberAccess * ma)
    {
        // get pointer to structure (also requried record)
        if (writing) move("$v1", "$v0");
        struct_fetch_record = true;
        auto tmp = writing;
        writing = false;
        ma->LHS->accept(this);
        writing = tmp;
        struct_fetch_record = false;
        int offset = 0;
        for (auto & r : struct_record) if (r->get_id()==ma->ID->Name) break; else offset+=4;
        if (!writing)
        {
            std::cout << "lw $v0, " << offset << "($v0)" << std::endl;
        }
        else
        {
            std::cout << "sw $v1, " << offset << "($v0)" << std::endl;
        }
        std::cout << "nop" << std::endl;
    }
    void visit(DerefMemberAccess * dma)
    {
        // // get pointer to structure (also requried record)
        // if (writing) move("$v1", "$v0");
        // struct_fetch_record = true;
        // auto tmp = writing;
        // writing = false;
        // ma->LHS->accept(this);
        // writing = tmp;
        // struct_fetch_record = false;
        // int offset = 0;
        // for (auto & r : struct_record) if (r->get_id()==ma->ID->Name) break; else offset+=4;
        // if (!writing)
        // {
        //     std::cout << "lw $v0, " << offset << "($v0)" << std::endl;
        // }
        // else
        // {
        //     std::cout << "sw $v1, " << offset << "($v0)" << std::endl;
        // }
        // std::cout << "nop" << std::endl;
    }
    void visit(PostInc * pi)
    {
        std::cerr << "PI" << std::endl;
        pi->LHS->accept(this);
        move("$v1", "$v0");
        std::cout << "addiu $v0, $v0, 1" << std::endl;
        writing = true;
        pi->LHS->accept(this);
        writing = false;
        move("$v0", "$v1");
    }
    void visit(PostDec * pd)
    {
        std::cerr << "PD" << std::endl;
        pd->LHS->accept(this);
        move("$v1", "$v0");
        std::cout << "addiu $v0, $v0, -1" << std::endl;
        writing = true;
        pd->LHS->accept(this);
        writing = false;
        move("$v0", "$v1");
    }
    void visit(ArgExprList * ael)
    {
        for (int i = ael->Args.size() - 1 ; i >= 0; i--)
        {
            // evaluating arguments
            auto r = (i < 4) ? "$a" + std::to_string(i) : "$v0";
            ael->Args[i]->accept(this);
            move(r, "$v0");
            // // store all arguments on stack
            std::cout << "sw " << r << ", " << (i)*4 << "($fp)" << std::endl;
            std::cout << "nop" << std::endl;
        }
    }
    void visit(UnaryAddressOperator * uao)
    {
        address_flag = true;
        uao->RHS->accept(this);
        address_flag = false;
        std::cout << "# getting address of " << address_name << std::endl;
        std::cout << "addiu $v0, $sp, " << variable_map.lookup(address_name) << std::endl;
    }
    void visit(UnaryDerefOperator * udo)
    {
        if (!writing)
        {
            udo->RHS->accept(this);
            std::cout << "lw $v0, 0($v0)" << std::endl;
        }
        else
        {
            move("$v1", "$v0");
            writing = false;
            udo->RHS->accept(this);
            writing = true;
            std::cout << "sw $v1, 0($v0)" << std::endl;
        }
    }
    void visit(UnaryPlusOperator * upo)
    {
        // does nothing, equivalent
        upo->RHS->accept(this);
    }
    void visit(UnaryNegOperator * uno)
    {
        uno->RHS->accept(this);
        std::cout << "subu $v0, $zero, $v0" << std::endl;
    }
    void visit(UnaryBitwiseNotOperator * ubno)
    {
        ubno->RHS->accept(this);
        std::cout << "li $v1, 0xffffffff" << std::endl;
        std::cout << "xori $v0, $v0, $v1" << std::endl;
    }
    void visit(UnaryLogicalNotOperator * ulno)
    {
        ulno->RHS->accept(this);
        std::cout << "sne $v0, $v0, $zero" << std::endl;
    }
    void visit(PreInc * pi)
    {
        pi->RHS->accept(this);
        std::cout << "addiu $v0, $v0, 1" << std::endl;
        writing = true;
        pi->RHS->accept(this);
        writing = false;
    }
    void visit(PreDec * pd)
    {
        pd->RHS->accept(this);
        std::cout << "addiu $v0, $v0, -1" << std::endl;
        writing = true;
        pd->RHS->accept(this);
        writing = false;
    }
    void visit(SizeofExpr * soe)
    {
        sizeof_flag = true;
        soe->RHS->accept(this);
        sizeof_flag = false;
    }
    void visit(SizeofType * sot)
    {
        if(sot->typ_nam != NULL){
        if(sot->typ_nam->spec_list != NULL){
        if(sot->typ_nam->spec_list->type_spec != NULL){
        auto type = sot->typ_nam->spec_list->type_spec->type;
        if (type == "void") li(1);
        else if (type == "char") li(1);
        else if (type == "int") li(4);
        else if (type == "float") li(4);
        else if (type == "double") li(8);
        else if (type == "long") li(8);
        else if (type == "short") li(2);
        }}}
    }
    void visit(CastExpr *) {}
    // std::pair<std::string, std::string> descend(BinaryOpExpression * bop)
    // {
    //     auto ret_A = get_temp_register(gen_name("ret_A_"));
    //     auto ret_B = get_temp_register(gen_name("ret_B_"));
    //     return_register.push(ret_A);
    //     bop->LHS->accept(this);
    //     return_register.push(ret_B);
    //     bop->RHS->accept(this);
    //     return make_pair(ret_A, ret_B);
    // }
    void descend(BinaryOpExpression * bop)
    {
        std::cerr << "descend" << std::endl;
        std::cout << "addiu $sp, $sp, -4" << std::endl;
        std::cout << "move $fp, $sp" << std::endl;
        variable_map.update(4);
        bop->LHS->accept(this);
        push("$v0");
        // std::cout << "addiu $sp, $sp, -4" << std::endl;
        // std::cout << "move $fp, $sp" << std::endl;
        // variable_map.update(4);
        bop->RHS->accept(this);
        // push("$v0");
        // pop("$v1");
        // pop("$v0",4);  
        move("$v1", "$v0");
        pop("$v0");  
        // std::cout << "addiu $sp, $sp, 8" << std::endl;
        std::cout << "addiu $sp, $sp, 4" << std::endl;
        std::cout << "move $fp, $sp" << std::endl;
        // variable_map.update(-8);
        variable_map.update(-4);
    }
    void visit(Multiply *m)
    {
        descend(m);
        std::cout << "multu $v0, $v1" << std::endl;
        std::cout << "mflo $v0" << std::endl;
        // { mt_c("$f0","$v0"); mt_c("$f2","$v1"); std::cout << "mul.s $f0, $f0, $f2" << std::endl; mf_c("$v0","$f0"); }
    }
    void visit(Divide *d)
    {
        descend(d);
        std::cout << "div $v0, $v1" << std::endl;
        std::cout << "mflo $v0" << std::endl;
        // { mt_c("$f0","$v0"); mt_c("$f2","$v1"); std::cout << "div.s $f0, $f0, $f2" << std::endl; mf_c("$v0","$f0"); }
    }
    void visit(Modulo * m)
    {
        descend(m);
        std::cout << "divu $v0, $v1" << std::endl;
        std::cout << "mfhi $v0" << std::endl;
    }
    void visit(Add * a)
    {
        descend(a);
        std::cout << "addu $v0, $v0, $v1" << std::endl;
        // { mt_c("$f0","$v0"); mt_c("$f2","$v1"); std::cout << "add.s $f0, $f0, $f2" << std::endl; mf_c("$v0","$f0"); }
    }
    void visit(Sub * s)
    {
        descend(s);
        std::cout << "subu $v0, $v0, $v1" << std::endl;
        // { mt_c("$f0","$v0"); mt_c("$f2","$v1"); std::cout << "sub.s $f0, $f0, $f2" << std::endl; mf_c("$v0","$f0"); }
    }
    void visit(ShiftLeft * sl)
    {
        descend(sl);
        std::cout << "sllv $v0, $v0, $v1" << std::endl;
    }
    void visit(ShiftRight * sr)
    {
        descend(sr);
        std::cout << "srlv $v0, $v0, $v1" << std::endl;
    }
    void visit(LessThan * lt)
    {
        std::cerr << "MAN" << std::endl;
        descend(lt);
        std::cout << "slt $v0, $v0, $v1" << std::endl;
        std::cerr << "VAN" << std::endl;
        // { mt_c("$f0","$v0"); mt_c("$f2","$v1"); std::cout << "c.lt.s $f0, $f0, $f2" << std::endl; mf_c("$v0","$f0"); }
    }
    void visit(GreaterThan * gt)
    {
        descend(gt);
        std::cout << "sgt $v0, $v0, $v1" << std::endl;
    }
    void visit(LessThanOrEqual * ltoe)
    {
        descend(ltoe);
        std::cout << "sle $v0, $v0, $v1" << std::endl;
    }
    void visit(GreaterThanOrEqual * gtoe)
    {
        descend(gtoe);
        std::cout << "sge $v0, $v0, $v1" << std::endl;
    }
    void visit(EqualTo * et)
    {
        descend(et);
        std::cout << "seq $v0, $v0, $v1" << std::endl;
    }
    void visit(NotEqualTo * net)
    {
        descend(net);
        std::cout << "sne $v0, $v0, $v1" << std::endl;
    }
    void visit(LogicalAND * la)
    {
        descend(la);
        std::cout << "sne $v0, $v0, $zero" << std::endl;
        std::cout << "sne $v1, $v1, $zero" << std::endl;
        std::cout << "and $v0, $v0, $v1" << std::endl;
        std::cout << "sne $v0, $v0, $zero" << std::endl;
    }
    void visit(LogicalOR * lo)
    {
        descend(lo);
        std::cout << "or $v0, $v0, $v1" << std::endl;
        std::cout << "sne $v0, $v0, $zero" << std::endl;
    }
    void visit(BitwiseAND * ba)
    {
        descend(ba);
        std::cout << "and $v0, $v0, $v1" << std::endl;
    }
    void visit(BitwiseOR * bo)
    {
        descend(bo);
        std::cout << "or $v0, $v0, $v1" << std::endl;
    }
    void visit(BitwiseXOR * bx)
    {
        descend(bx);
        std::cout << "xor $v0, $v0, $v1" << std::endl;
    }
    void visit(TernaryOpExpression * toe)
    {
        // generating branch labels
        auto f = gen_name("ternary_false");
        auto end = gen_name("ternary_end");
        // generating condition expression to store in $v0
        toe->Condition->accept(this);
        // if false go to false label
        std::cout << "beq $v0, $zero, " << f << std::endl;
        std::cout << "nop" << std::endl;
        // doing true expression
        std::cout << gen_name("ternary_true") << ':' << std::endl;
        toe->IfTrue->accept(this);
        // branch to end
        std::cout << "b " << end << std::endl;
        std::cout << "nop" << std::endl;
        // do false expression
        std::cout << f << ':' << std::endl;
        toe->IfFalse->accept(this);
        // end
        std::cout << end << ':' << std::endl;
    }
    void visit(AssignmentExpression *ae)
    {
        ae->RHS->accept(this);
        writing = true;
        ae->LHS->accept(this);
        writing = false;
    }
    // std::pair<std::string,std::string> descend(GenericAssignExpr *gae)
    // {
    //     auto ret_A = get_temp_register(gen_name("ret_A_"));
    //     auto ret_B = get_temp_register(gen_name("ret_B_"));
    //     return_register.push(ret_A);
    //     gae->LHS->accept(this);
    //     return_register.push(ret_B);
    //     gae->RHS->accept(this);
    //     return make_pair(ret_A, ret_B);
    // }
    void descend(GenericAssignExpr *gae)
    {
        std::cout << "addiu $sp, $sp, -4" << std::endl;
        std::cout << "move $fp, $sp" << std::endl;
        variable_map.update(4);
        gae->LHS->accept(this);
        push("$v0");
        // std::cout << "addiu $sp, $sp, -4" << std::endl;
        // std::cout << "move $fp, $sp" << std::endl;
        // variable_map.update(4);
        gae->RHS->accept(this);
        // push("$v0");
        // pop("$v1");
        // pop("$v0",4);  
        move("$v1", "$v0");
        pop("$v0");
        // std::cout << "addiu $sp, $sp, 8" << std::endl;
        std::cout << "addiu $sp, $sp, 4" << std::endl;
        std::cout << "move $fp, $sp" << std::endl;
        // variable_map.update(-8);
        variable_map.update(-4);
    }

    void visit(MulAssignment * ma)
    {
        descend(ma);
        std::cout << "mult $v0, $v1" << std::endl;
        std::cout << "mflo $v0" << std::endl;
        writing = true;
        ma->LHS->accept(this);
        writing = false;
    }
    void visit(DivAssignment * da)
    {
        descend(da);
        std::cout << "div  $v0, $v1" << std::endl;
        std::cout << "mfhi $v0" << std::endl;
        writing = true;
        da->LHS->accept(this);
        writing = false;
    }
    void visit(ModAssignment * ma)
    {
        descend(ma);
        std::cout << "div  $v0, $v1" << std::endl;
        std::cout << "mflo $v0" << std::endl;
        writing = true;
        ma->LHS->accept(this);
        writing = false;
    }
    void visit(AddAssignment * aa)
    {
        descend(aa);
        std::cout << "addu $v0, $v0, $v1" << std::endl;
        writing = true;
        aa->LHS->accept(this);
        writing = false;  
    }
    void visit(SubAssignment * sa)
    {
        descend(sa);
        std::cout << "subu $v0, $v0, $v1" << std::endl;
        writing = true;
        sa->LHS->accept(this);
        writing = false;
    }
    void visit(ShiftLeftAssignment * sla)
    {
        descend(sla);
        std::cout << "sllv $v0, $v0, $v1" << std::endl;
        writing = true;
        sla->LHS->accept(this);
        writing = false;
    }
    void visit(ShiftRightAssignment * sra)
    {
        descend(sra);
        std::cout << "srlv $v0, $v0, $v1" << std::endl;
        writing = true;
        sra->LHS->accept(this);
        writing = false;  
    }
    void visit(BitwiseANDAssignment * baa)
    {
        descend(baa);
        std::cout << "and $v0, $v0, $v1" << std::endl;
        writing = true;
        baa->LHS->accept(this);
        writing = false;
    }
    void visit(BitwiseXORAssignment * bxa)
    {
        descend(bxa);
        std::cout << "xor $v0, $v0, $v1" << std::endl;
        writing = true;
        bxa->LHS->accept(this);
        writing = false;
    }
    void visit(BitwiseORAssignment * boa)
    {
        descend(boa);
        std::cout << "or $v0, $v0, $v1" << std::endl;
        writing = true;
        boa->LHS->accept(this);
        writing = false;
    }
    void visit(ConstantExpression *) {}
    void visit(CommaSepExpression *) {}

    //Declarations

    void visit(declaration * dec)
    {
        std::cerr << "declon" << std::endl;
        dec->specifier->accept(this);
        if (dec->list != NULL)
        {
            // writing = true;
            dec->list->accept(this);
            // writing = false;
        }
        struct_flag = false;
    }
    void visit(declaration_specifiers * ds)
    {
        std::cerr << "decspec" << std::endl;
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
            writing = true;
            id->dec->accept(this);
            if (id->init != NULL) id->init->accept(this);
            writing = false;
        }
        else
        {

            if (id->init!=NULL)
            {
                if (id->init->ass_expr!=NULL)
                {
                    id->init->ass_expr->accept(this);
                    writing = true;
                    id->dec->accept(this);
                    writing = false;
                }
            }
            else 
            {
                writing = true;
                id->dec->accept(this);
                writing = false;
            }
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
                i->ass_expr->accept(this);
                // std::cout << "addiu $sp, $sp, 4" << std::endl; move("$fp", "$sp");
                // std::cout << "sw $v0, 0($sp)" << std::endl;
                // std::cout << "nop" << std::endl;
                // variable_map.update(4);
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

    void visit(type_specifier * ts)
    {
        std::cerr << "type specifier" << std::endl;
    }
    void visit(struct_specifier* _strspec)
    { 
        std::cerr << "struct specifier" << std::endl;
        struct_flag = true;
    }
    void visit(struct_declaration_list* _strdectionlist){}
    void visit(struct_declaration* _strdection){}
    void visit(struct_declarator_list* _strdeclist){}

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
                            sizeof_variables[array_name]=no_elements*4;
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
        // clearing local variables
        if (variable_map.stack_size !=  continue_to.top().second)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - continue_to.top().second << std::endl;
            move("$fp", "$sp");
            variable_map.update(continue_to.top().second - variable_map.stack_size);
        }
        std::cout << "b " << continue_to.top().first << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(Break *)
    {
        // clearing local variables
        if (variable_map.stack_size !=  break_to.top().second)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - break_to.top().second << std::endl;
            move("$fp", "$sp");
            variable_map.update(break_to.top().second - variable_map.stack_size);
        }
        std::cout << "b " << break_to.top().first << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(Return * r)
    {
        if (r->ReturnExpression != NULL)
        {
            r->ReturnExpression->accept(this);
        }
        // FREE STACK
        std::cout << "addiu $sp, $sp, " << variable_map.get_stack_size() - stacksize << std::endl;
        move("$fp", "$sp");
        std::cout << "b " << function_end << std::endl;
        std::cout << "nop" << std::endl;
    }
    void visit(While * w) 
    {
        int base_stack_size = variable_map.stack_size;
        // creating entry label
        auto beginning = gen_name("while_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("while_end");
        // adding beginning and end as pair to boundry stacks
        continue_to.push(std::make_pair(beginning, base_stack_size));
        break_to.push(std::make_pair(end, base_stack_size));
        // evaluate condition
        auto condition = gen_name("while_condition");
        w->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq $v0, $zero, " << end << std::endl;
        std::cout << "nop" << std::endl;
        // do body
        w->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        // branch to beginning
        std::cout << "b "<< beginning << std::endl;
        std::cout << "nop" << std::endl;
        //end
        std::cout << end << ':' << std::endl;
        // std::cout << "const " << destReg << " 0" << std::endl; // we need to return 0
    }
    void visit(DoWhile *dw)
    {
        int base_stack_size = variable_map.stack_size;
        // creating entry label
        auto beginning = gen_name("while_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("while_end");
        // adding beginning and end as pair to boundry stacks
        continue_to.push(std::make_pair(beginning, base_stack_size));
        break_to.push(std::make_pair(end, base_stack_size));
        // evaluate condition
        auto condition = gen_name("while_condition");
        dw->ControlExpression->accept(this);
        // branch to end if condition not met
        std::cout << "beq $v0, $zero, " << end << std::endl;
        std::cout << "nop" << std::endl;
        // do body
        dw->Body->accept(this);
        continue_to.pop();
        break_to.pop();
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        // branch to beginning
        std::cout << "b " << beginning << std::endl;
        std::cout << "nop" << std::endl;
        //end
        std::cout << end << ':' << std::endl;
        // std::cout << "const " << destReg << " 0" << std::endl; // we need to return 0
    }
    void visit(For * f)
    {
        int base_stack_size = variable_map.stack_size;
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
        continue_to.push(std::make_pair(beginning, base_stack_size));
        break_to.push(std::make_pair(end, base_stack_size));
        // writing start
        std::cout << beginning << ':' << std::endl;
        // doing control statement
        std::cerr << "CONTROL" << std::endl;
        if (f->Control != NULL)
        {
            f->Control->accept(this);
        }
        std::cerr << "CONTROL END" << std::endl;
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
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        // jump to beginning
        std::cout << "b " << beginning << std::endl;
        std::cout << "nop" << std::endl;
        // writing end
        std::cout << end << ':' << std::endl;
        // clearing continue and break
        continue_to.pop();
        break_to.pop();
    }
    void visit(If * i)
    {
        int base_stack_size = variable_map.stack_size;
        // creating labels
        auto true_case_label = gen_name("if_true");
        auto end_label = gen_name("if_end");
        // evaluating expression
        i->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch to end if false
        std::cout << "beq $v0, $zero, " << end_label << std::endl;
        std::cout << "nop" << std::endl;
        // do true
        std::cout << true_case_label << ':' << std::endl;
        i->IfTrue->accept(this);
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        // end
        std::cout << end_label << ':' << std::endl;
    }
    void visit(IfElse *ie)
    {
        int base_stack_size = variable_map.stack_size;
        // creating labels
        auto true_case_label = gen_name("if_true");
        auto false_case_label = gen_name("if_false");
        auto end_label = gen_name("if_end");
        // evaluating expression
        ie->ControlExpression->accept(this);
        // result of controlexpression should be stored in $v0
        // branch between true or false case
        std::cout << "beq $v0, $zero, " << false_case_label << std::endl;
        std::cout << "nop" << std::endl;
        // do true
        std::cout << true_case_label << ':' << std::endl;
        ie->IfTrue->accept(this);
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        std::cout << "b " << end_label << std::endl;
        std::cout << "nop" << std::endl;
        // do false
        std::cout << false_case_label << ':' << std::endl;
        ie->IfFalse->accept(this);
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
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
        int base_stack_size = variable_map.stack_size;
        // creating entry label
        auto beginning = gen_name("switch_begin");
        std::cout << beginning << ':' << std::endl;
        // creating loop exit
        auto end = gen_name("switch_end");
        auto decision = gen_name("switch_decision");
        // default label
        default_label = "";
        // adding beginning and end as pair to boundry stacks
        break_to.push(std::make_pair(end, base_stack_size));
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
        s->ControlExpression->accept(this);
        // checking and branching to each case
        while (!cases.empty())
        {
            // std::cerr << "loop" << std::endl;
            auto c = cases.top();
            std::cout << "li $v1, " << c.second << std::endl;
            std::cout << "beq $v0, $v1, " << c.first << std::endl;
            std::cout << "nop" << std::endl;
            cases.pop();
        }
        // or going to default
        if (default_label != "")
        {
            std::cout << "b " << default_label << std::endl;
            std::cout << "nop" << std::endl;
        }
        // clearing local variables
        if (variable_map.stack_size !=  base_stack_size)
        {
            std::cout << "addiu $sp, $sp, " << variable_map.stack_size - base_stack_size << std::endl;
            move("$fp", "$sp");
            variable_map.update(base_stack_size - variable_map.stack_size);
        }
        std::cout << end << ':' << std::endl;
    }
    void visit(CaseOrDefault * cod)
    {
        if (cod->Eval != NULL)
        {
            auto case_label = gen_name("case");
            cases.push(make_pair(case_label, cod->Eval->constEval()));
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
        std::cerr << "Func Def" << std::endl;
        // create function label and parameters
        parameter_size = 0; // also count number of words used by argument
        variable_map = vm();
        func_flag = true;
        fd->decl->accept(this);
        func_flag = false;
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
                std::cout << "sw $a" << i << ", " << (i)*4 << "($sp)" << std::endl;
                std::cout << "nop" << std::endl;
            }
        }
        // make space for local variables
        stacksize = 8 + 8*4 + 4; // by default we assign space for return address, old stack pointer, and saved registers
        variable_map.update(stacksize);
        std::cout << "addiu $sp, $sp, " << -stacksize << std::endl;
        // store return address
        std::cout << "sw $ra, " << stacksize - 4 << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        // store previous stack pointer
        std::cout << "sw $fp, " << stacksize - 8 << "($sp)" << std::endl;
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
        std::cout << "addiu $sp, $sp, " << variable_map.get_stack_size() - stacksize << std::endl;
        move("$fp", "$sp");
        // stacksize = variable_map.get_stack_size();
        std::cout << end << ':' << std::endl;
        // restore saved registers
        for (int i = 0; i < 8; i++)
        {
            std::cout << "lw $s" << i << ", " << stacksize - (10-i) * 4 << "($sp)" << std::endl;
            std::cout << "nop" << std::endl;
        }
        // restore return address
        std::cout << "lw $ra, " << stacksize-4 << "($sp)" << std::endl;
        std::cout << "nop" << std::endl;
        // restore stack pointer
        std::cout << "lw $fp, " << stacksize -8 << "($sp)" << std::endl;
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