#ifndef TOKENS_HPP
#define TOKENS_HPP

#include<string>

// these are the tokens as specified in the 1990 ansi
// excluding preprocessing tokens
enum TokenType
{
    None,
    Operator,
    Operator_add,
    Operator_sub,
    Operator_addadd,
    Operator_subsub,
    Operator_mul,
    Operator_div,
    Operator_mod,
    Operator_and,
    Operator_or,
    Operator_not,
    Operator_assign,
    Operator_equal,
    Operator_not_equal,
    Operator_greater,
    Operator_less,
    Operator_greater_equal,
    Operator_less_equal,
    Operator_bit_and,
    Operator_bit_or,
    Operator_bit_not,
    Operator_bit_xor,
    Operator_sl,
    Operator_sr,
    Operator_add_assign,
    Operator_sub_assign,
    Operator_mul_assign,
    Operator_div_assign,
    Operator_mod_assign,
    Operator_and_assign,
    Operator_or_assign,
    Operator_xor_assign,
    Operator_sr_assign,
    Operator_sl_assign,
    Operator_ref,
    Operator_deref,
    Operator_access,
    Operator_deref_access,
    Operator_sizeof,
    Operator_trinary_question,
    Operator_trinary_choice,
    Operator_comma,
    Constant,
    Constant_int,
    Constant_char,
    Constant_double,
    Constant_float,
    Constant_long_double,
    Identifier,
    Keyword, 
    Keyword_void,
    Keyword_char,
    Keyword_short,
    Keyword_int,
    Keyword_long,
    Keyword_float,
    Keyword_double,
    Keyword_signed,
    Keyword_unsigned,
    Keyword_case,
    Keyword_default,
    Keyword_if,
    Keyword_else,
    Keyword_switch,
    Keyword_while,
    Keyword_do,
    Keyword_for,
    Keyword_continue,
    Keyword_break,
    Keyword_return
    String,
    Punctuator,
    Punctuator_eol,
    Punctuator_par_open,
    Punctuator_par_close,
    Punctuator_squ_open,
    Punctuator_squ_close,
    Punctuator_cur_open,
    Punctuator_cur_close
};

union TokenValue
{
    std::string *text;
    int ivalue;
    char cvalue;
    double dvalue;
};

extern TokenValue yylval; // function for handing the value to yacc

extern int yylex(); // lexer function generated by flex, returns token type

#endif
