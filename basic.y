%code requires{

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%token Constant
%token String
%token Identifier
%token Operator_access Operator_deref_access Operator_addadd Operator_subsub Operator_sizeof Operator_mul Operator_div Operator_mod Operator_add Operator_sub Operator_sl Operator_sr Operator_less Operator_greater Operator_less_equal Operator_greater_equal Operator_equal Operator_not_equal Operator_bit_and Operator_bit_xor Operator_bit_or Operator_bit_not Operator_and Operator_or Operator_trinary_question Operator_trinary_choice Operator_comma Operator_assign
%token Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return
%token Punctuator_eol Punctuator_par_open Punctuator_par_close Punctuator_squ_open Punctuator_squ_close Punctuator_cur_open Punctuator_cur_close

%start ROOT

%%

primary_EXPR: Identifier { $$ = new identifier($1) }
                  | Constant { $$ = new constant($1); }
                  | String { $$ = new string($1); }
/*                  | Punctuator_par_open EXPR Punctuator_par_close { $$ = expression($2); }
*/

ROOT: primary_EXPR { std::cerr << "This is route" << std::endl;}

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
