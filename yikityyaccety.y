%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token Constant
%token String
%token Identifier
%token Operator_access Operator_deref_access Operator_addadd Operator_subsub Operator_sizeof Operator_mul Operator_div Operator_mod Operator_add Operator_sub Operator_sl Operator_sr Operator_less Operator_greater Operator_less_equal Operator_greater_equal Operator_equal Operator_not_equal Operator_bit_and Operator_bit_xor Operator_bit_or Operator_bit_not Operator_and Operator_or Operator_trinary_question Operator_trinary_choice Operator_comma Operator_assign
%token Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return
%token Punctuator_eol Punctuator_par_open Punctuator_par_close Punctuator_squ_open Punctuator_squ_close Punctuator_cur_open Punctuator_cur_close

%type <expr> EXPR TERM UNARY FACTOR
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

primary_EXPR: identifier      
                  | Constant
                  | String
                  | ( EXPR )

postfix_EXPR: primary_EXPR
                  | postfix_EXPR [ EXPR ]
                  | postfix_EXPR (  )
                  | postfix_EXPR ( argument_EXPR_list )
                  | postfix_EXPR Operator_access identifier
                  | postfix_EXPR Operator_deref_access identifier
                  | postfix_EXPR Operator_addadd
                  | postfix_EXPR Operator_subsub

argument_EXPR_list: assignment_EXPR
                        | assignment_EXPR_list, assignment_EXPR

unary_EXPR: postfix_EXPR
                | Operator_addadd unary_EXPR
                | Operator_subsub unary_EXPR
                | unary_operator cast_EXPR
                | Operator_sizeof unary_EXPR
                | Operator_sizeof ( type_name )

unary_operator: Operator_and | Operator_mul | Operator_plus | Operator_sub | Operator_bit_not | Operator_not

cast_EXPR: unary_EXPR
               | ( type_name ) cast_EXPR

multiplicative_EXPR: cast_EXPR
                         | multiplicative_EXPR Operator_mul cast_EXPR
                         | multiplicative_EXPR Operator_div cast_EXPR
                         | multiplicative_EXPR Operator_mod cast_EXPR

additive_EXPR: multiplicative_EXPR
                   | additive_EXPR Operator_add multiplicative_EXPR
                   | additive_EXPR Operator_sub multiplicative_EXPR

shift_EXPR: additive_EXPR
          | shift_EXPR Operator_sl additive_EXPR
          | shift_EXPR Operator_sr additive_EXPR

relational_EXPR: shift_EXPR
               | relational_EXPR Operator_less shift_EXPR
               | relational_EXPR Operator_greater shift_EXPR
               | relational_EXPR Operator_less_equal shift_EXPR
               | relational_EXPR Operator_greater_equal shift_EXPR

equality_EXPR: relational_EXPR
             | equality_EXPR Operator_equal relational_EXPR
             | equality_EXPR Operator_not_equal relational_EXPR

// I"M NOT SO SURE ABOUT THESE LOGIC AND BIT GRAMMARS, CHECK!!!

BIT_AND_EXPR: equality_EXPR
        | BIT_AND_EXPR Operator_bit_and equality_EXPR

BIT_XBIT_OR_EXPR: BIT_AND_EXPR
        | BIT_XBIT_OR_EXPR Operator_bit_xor BIT_AND_EXPR

BIT_OR_EXPR: BIT_XBIT_OR_EXPR
       | BIT_OR_EXPR Operator_bit_or BIT_XBIT_OR_EXPR

LOGIC_AND_EXPR: BIT_OR_EXPR
              | LOGIC_AND_EXPR Operator_and BIT_OR_EXPR

LOGIC_OR_EXPR: LOGIC_AND_EXPR
             | LOGIC_OR_EXPR Operator_or LOGIC_AND_EXPR

conditional_EXPR: LOGIC_OR_EXPR
                | LOGIC_OR_EXPR Operator_trinary_question EXPR Operator_trinary_choice conditional_EXPR

assignment_EXPR: conditional_EXPR
               | unary_EXPR assignment assignment_EXPR // assignments are = *= /= %= += -= <<= >>= &= ^= |=

assignment: Operator_assign | Operator_mul_assign | Operator_div_assign | Operator_mod_assign | Operator_add_assign | Operator_sub_assign | Operator_sl_assign | Operator_sr_assign | Operator_and_assign | Operator_xor_assign | Operator_or_assign

EXPR: assignment_EXPR
    | EXPR Operator_comma assignment_EXPR

constant_EXPR: conditional_EXPR // DONT THINK WE NEED THIS, WE DON'T USE CONST

declaration: declaration_specifiers init_declarator_list Punctuator_eol
           | declaration_specifiers Punctuator_eol

declaration_specifiers: storage_class_specifier
                      | storage_class_specifier declaration_specifiers
                      | type_spcifier
                      | type_spcifier declaration_specifiers
                      | type_qualifier declaration_specifiers

init_declarator_list: init_declarator
                    | init_declarator_list Operator_comma init_declarator

init_declarator: declarator
               | declarator Operator_assign initializer

storage_class_specifier: /* I don't believe we need this either */

type_specifier: Keyword_void | Keyword_char | Keyword_short | Keyword_int | Keyword_long | Keyword_float | Keyword_double | Keyword_signed | Keyword_unsigned
              | struct_or_union_specifier
              | enum_specifier
              | typedef_name


STRUCT STUFF /* cant do it see page 69 of ref */

ENUM STUFF /* enum sutff on page 71 */

type_qualifier /* I believe these are not needed */



statement: labeled_statement
         | compound_statement
         | EXPR_statement
         | select_statement
         | ITER_statement
         | jump-statement

labeled_statement: identifier Operator_trinary_choice statement
                 | Keyword_case constant_EXPR Operator_trinary_choice statement
                 | Keyword_default Operator_trinary_choice statement

compound_statement: Punctuator_cur_open declartio???????Punctuator_cur_close /* TODO */

declaration_list: declaration
                | declaration_list declaration

statement_list: statement
              | statement_list statement

EXPR_statement: EXPR
              |  /*how to express null?*/

selection_statement: Keyword_if ( EXPR ) statement
                   | Keyword_if ( EXPR ) statement Keyword_else statement
                   | Keyword_switch ( EXPR ) statement

ITER_statement: Keyword_while ( EXPR ) statement
              | Keyword_do statement Keyword_while ( EXPR ) Punctuator_eol
              | Keyword_for ( EXPR Punctuator_eol EXPR Punctuator_eol EXPR ) statement /* NB EXPRs are optional, we have to write one for each case */

jump_statement: Keyword_continue Punctuator_eol
              | Keyword_break Punctuator_eol
              | Keyword_return EXPR Punctuator_eol
              | Keyword_return Punctuator_eol /* evaluation of void return is undefined behaviour */

/* not sure if we need the next two */
translation_unit
External_declaration 



FUNC_DEF: declaration_specifiers declarator declaration_list compound_statement
        | declaration_specifiers declarator compound_statement Punctuator_cur_open /* function with no arguments */ Punctuator_cur_close
        | declarator declaration_list compound_statement
        | declarator compound_statement


%%
