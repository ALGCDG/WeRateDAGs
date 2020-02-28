%code requires{

  #include<iostream>
  #include<string>
 /* extern const Expression *g_root; // A way of getting the AST out
*/
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union
{
    std::string *text;
    int ivalue;
    char cvalue;
    double dvalue;
	float fvalue;
	long double ldvalue;
}

%token Constant_int Constant_char Constant_double Constant_float Constant_long_double
%token String
%token Identifier
%token Operator Operator_add  Operator_sub  Operator_addadd  Operator_subsub  Operator_mul  Operator_div  Operator_mod  Operator_and  Operator_or  Operator_not  Operator_assign  Operator_equal  Operator_not_equal  Operator_greater  Operator_less  Operator_greater_equal  Operator_less_equal  Operator_bit_and  Operator_bit_or  Operator_bit_not  Operator_bit_xor  Operator_sl  Operator_sr  Operator_add_assign  Operator_sub_assign  Operator_mul_assign  Operator_div_assign  Operator_mod_assign  Operator_and_assign  Operator_or_assign  Operator_xor_assign  Operator_sr_assign  Operator_sl_assign  Operator_ref  Operator_deref  Operator_access  Operator_deref_access  Operator_sizeof  Operator_trinary_question  Operator_trinary_choice  Operator_comma 
%token Keyword Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return Keyword_enum Keyword_struct
%token Punctuator Punctuator_eol Punctuator_par_open Punctuator_par_close Punctuator_squ_open Punctuator_squ_close Punctuator_cur_open Punctuator_cur_close



%type <ivalue> Constant Constant_int
%type <cvalue> Constant_char
%type <dvalue> Constant_double
%type <fvalue> Constant_float
%type <ldvalue> Constant_long_double
%start ROOT

%%

/*
EXPRESSIONS
*/

primary_EXPR: Identifier { std::cerr << "IDENTIFIER" << std::endl; // $$ = new identifier($1); 
}
                 | Constant { std::cerr << "CONSTANT" << std::endl; // $$ = new constant($1); 
				 }
                  | String { std::cerr << "STRING" << std::endl; // $$ = new string($1); 
				  }
              | Punctuator_par_open EXPR Punctuator_par_close { std::cout << "(x)" << std::endl; }


Constant: Constant_int {}  
		| Constant_char {}
		| Constant_double {}
		| Constant_float {}
		| Constant_long_double {}


postfix_EXPR: primary_EXPR { std::cerr << "prim" << std::endl; }
                  | postfix_EXPR Punctuator_squ_open EXPR Punctuator_squ_close { std::cerr << "x[y]" << std::endl; }
                  | postfix_EXPR Punctuator_par_open  Punctuator_par_close  { std::cerr << "x(y)" << std::endl; }
                  | postfix_EXPR Punctuator_par_open argument_EXPR_list Punctuator_par_close  { std::cerr << "x(y,z)" << std::endl; }
                  | postfix_EXPR Operator_access Identifier   { std::cerr << "x.y" << std::endl; }
                  | postfix_EXPR Operator_deref_access Identifier   { std::cerr << "x->y" << std::endl; }
                  | postfix_EXPR Operator_addadd  { std::cerr << "x++" << std::endl; }
                  | postfix_EXPR Operator_subsub  { std::cerr << "x--" << std::endl; }


argument_EXPR_list: assignment_EXPR
                  | argument_EXPR_list Operator_comma assignment_EXPR { std::cerr << "argument list" << std::endl; }

unary_EXPR: postfix_EXPR { std::cerr << "as;dklfj" << std::endl; }
		  | Operator_addadd unary_EXPR { std::cerr << "++x" << std::endl; }
		  | Operator_subsub unary_EXPR { std::cerr << "--x" << std::endl; }
		| unary_operator cast_EXPR { std::cerr << "unary op" << std::endl; }
		| Operator_sizeof unary_EXPR { std::cerr << "size of" << std::endl; }
		| Operator_sizeof Punctuator_par_open type_name Punctuator_par_close  { std::cerr << "size of" << std::endl; } 

unary_operator: Operator_bit_and | Operator_mul | Operator_add | Operator_sub | Operator_bit_not | Operator_not

type_name: Keyword_void | Keyword_char | Keyword_short | Keyword_int | Keyword_long | Keyword_float | Keyword_double

cast_EXPR: unary_EXPR
               | Punctuator_par_open type_name Punctuator_par_close cast_EXPR { std::cerr << "(cast) x" << std::endl; }

multiplicative_EXPR: cast_EXPR
                         | multiplicative_EXPR Operator_mul cast_EXPR { std::cerr << "x * cast" << std::endl; }
                         | multiplicative_EXPR Operator_div cast_EXPR { std::cerr << "x / cast" << std::endl; }  
						 | multiplicative_EXPR Operator_mod cast_EXPR { std::cerr << "x % cast" << std::endl; }


additive_EXPR: multiplicative_EXPR
                   | additive_EXPR Operator_add multiplicative_EXPR { std::cerr << "x + y" << std::endl; }
                   | additive_EXPR Operator_sub multiplicative_EXPR { std::cerr << "x - y" << std::endl; }

shift_EXPR: additive_EXPR
          | shift_EXPR Operator_sl additive_EXPR { std::cerr << "x << y" << std::endl; }
          | shift_EXPR Operator_sr additive_EXPR { std::cerr << "x >> y" << std::endl; }

relational_EXPR: shift_EXPR
               | relational_EXPR Operator_less shift_EXPR { std::cerr << "x < y" << std::endl; }
               | relational_EXPR Operator_greater shift_EXPR { std::cerr << "x > y" << std::endl; }
               | relational_EXPR Operator_less_equal shift_EXPR { std::cerr << "x <= y" << std::endl; }
               | relational_EXPR Operator_greater_equal shift_EXPR { std::cerr << "x >= y" << std::endl; }

equality_EXPR: relational_EXPR
             | equality_EXPR Operator_equal relational_EXPR { std::cerr << "x == y" << std::endl; }
             | equality_EXPR Operator_not_equal relational_EXPR { std::cerr << "x != y" << std::endl; }



BIT_AND_EXPR: equality_EXPR
        | BIT_AND_EXPR Operator_bit_and equality_EXPR { std::cerr << "x & y" << std::endl; }

BIT_XBIT_OR_EXPR: BIT_AND_EXPR
        | BIT_XBIT_OR_EXPR Operator_bit_xor BIT_AND_EXPR{ std::cerr << "x ^ y" << std::endl; }

BIT_OR_EXPR: BIT_XBIT_OR_EXPR
       | BIT_OR_EXPR Operator_bit_or BIT_XBIT_OR_EXPR{ std::cerr << "x | y" << std::endl; }

LOGIC_AND_EXPR: BIT_OR_EXPR
              | LOGIC_AND_EXPR Operator_and BIT_OR_EXPR{ std::cerr << "x || y" << std::endl; }

LOGIC_OR_EXPR: LOGIC_AND_EXPR
             | LOGIC_OR_EXPR Operator_or LOGIC_AND_EXPR{ std::cerr << "x && y" << std::endl; }

conditional_EXPR: LOGIC_OR_EXPR
                | LOGIC_OR_EXPR Operator_trinary_question EXPR Operator_trinary_choice conditional_EXPR { std::cerr << "x?y:z" << std::endl; }

assignment_EXPR: conditional_EXPR
               | unary_EXPR assignment assignment_EXPR { std::cerr << "assignment" << std::endl; }
               
assignment: Operator_assign | Operator_mul_assign | Operator_div_assign | Operator_mod_assign | Operator_add_assign | Operator_sub_assign | Operator_sl_assign | Operator_sr_assign | Operator_and_assign | Operator_xor_assign | Operator_or_assign
               

EXPR: assignment_EXPR
    | EXPR Operator_comma assignment_EXPR { std::cerr << "x, y" << std::endl; }

constant_EXPR: conditional_EXPR { std::cerr << "cond expr" << std::endl; }

/*
DECLARATIONS
*/


declaration: declaration_specifiers init_declarator_list Punctuator_eol { std::cerr << "decspec list ;" << std::endl; }
           | declaration_specifiers Punctuator_eol { std::cerr << "decspec ;" << std::endl; }

declaration_specifiers: type_specifier  { std::cerr << "typspec list" << std::endl; }
                      | type_specifier declaration_specifiers  { std::cerr << "typspec decspec" << std::endl; }
/*
					  | type_qualifier { std::cerr << "typqual" << std::endl; }
                      | type_qualifier declaration_specifiers { std::cerr << "typqual decspec" << std::endl; }
*/

init_declarator_list: init_declarator  { std::cerr << "initdec" << std::endl; }
                    | init_declarator_list Operator_comma init_declarator { std::cerr << "initdeclist , initdec " << std::endl; }

init_declarator: declarator { std::cerr << "dec" << std::endl; }
               | declarator Operator_assign initializer { std::cerr << "dec = init" << std::endl; }

type_specifier: Keyword_void | Keyword_char | Keyword_short | Keyword_int | Keyword_long | Keyword_float | Keyword_double | Keyword_signed | Keyword_unsigned
              | struct_specifier { std::cerr << "struct" << std::endl; }
              | enum_specifier { std::cerr << "enum" << std::endl; }
              | typedef_name { std::cerr << "typedef type" << std::endl; }

struct_specifier: Keyword_struct Identifier Punctuator_cur_open struct_declaration_list Punctuator_cur_close { std::cerr << "struct x {...}" << std::endl; }
				| Keyword_struct Punctuator_cur_open struct_declaration_list Punctuator_cur_close { std::cerr << "struct {...}" << std::endl; }
				| Keyword_struct Identifier { std::cerr << "struct x" << std::endl; }



struct_declaration_list: struct_declaration
					   | struct_declaration_list struct_declaration

struct_declaration: specifier_qualifier_list struct_declaration_list

specifier_qualifier_list: type_specifier
						| type_specifier specifier_qualifier_list
/*
						| type_qualifier
						| type_qualifier specifier_qualifier_list
*/
struct_declarator_list: struct_declarator
					  | struct_declarator_list Operator_comma struct_declarator

struct_declarator: declarator

enum_specifier: Keyword_enum Identifier
			  | Keyword_enum Identifier Punctuator_cur_open enum_list Punctuator_cur_close
			  | Keyword_enum Punctuator_cur_open enum_list Punctuator_cur_close

enum_list: enumerator
		 | enum_list Operator_comma enumerator

enumerator: ENUM_CONST
		  | ENUM_CONST Operator_assign constant_EXPR

ENUM_CONST: Identifier

declarator: direct_declarator
		  | pointer direct_declarator

direct_declarator: Identifier
				 | Punctuator_par_open declarator Punctuator_par_close
				 | direct_declarator Punctuator_squ_open Punctuator_squ_close
				 | direct_declarator Punctuator_squ_open constant_EXPR Punctuator_squ_close
				 | direct_declarator Punctuator_par_open parameter_type_list  Punctuator_par_close
				 | direct_declarator Punctuator_par_open identifier_list Punctuator_par_close
				 | direct_declarator Punctuator_par_open Punctuator_par_close

pointer: Operator_mul
	   | Operator_mul pointer

/*
type_qualifier_list: type_qualifier
				   | type_qualifier_list type_qualifier
*/
parameter_type_list: parameter_list

parameter_list: parameter_declaration
		 	  | parameter_list Operator_comma parameter_declaration

parameter_declaration: declaration_specifiers declarator
					 | declaration_specifiers
					 | declaration_specifiers abstract_declarator

identifier_list: Identifier
			   | identifier_list Operator_comma Identifier

type_name: specifier_qualifier_list
		 | specifier_qualifier_list abstract_declarator

abstract_declarator: pointer
					| pointer direct_abstract_declarator
					| direct_abstract_declarator

direct_abstract_declarator: Punctuator_par_open abstract_declarator Punctuator_par_close
						  | direct_abstract_declarator Punctuator_squ_open constant_EXPR Punctuator_squ_close
						  | Punctuator_squ_open constant_EXPR Punctuator_squ_close
						  | direct_abstract_declarator Punctuator_squ_open Punctuator_squ_close
						  | Punctuator_squ_open Punctuator_squ_close
						  | direct_abstract_declarator Punctuator_par_open parameter_type_list Punctuator_par_close
						  | Punctuator_par_open parameter_type_list Punctuator_par_close
						  | direct_abstract_declarator Punctuator_par_open Punctuator_par_close
						  | Punctuator_par_open Punctuator_par_close


typedef_name: Identifier

initializer: assignment_EXPR
		   | Punctuator_cur_open initializer_list Punctuator_cur_close
		   | Punctuator_cur_open initializer_list Operator_comma Punctuator_cur_close

initializer_list: initializer
				| initializer_list Operator_comma initializer

ROOT: EXPR { std::cerr << "exp" << std::endl; }
	| declaration { std::cerr << "Its a declaration" << std::endl; }
%%
/*
const Expression *g_root; // Definition of variable (to match declaration earlier)
*/

void parseAST()
{
  std::cerr << "parsing" << std::endl;
  for(;;)
  {
  	yyparse();
  }
  return;
}

main()
{
	std::cerr << "starting parser" << std::endl;
	for(;;)
	{
		parseAST();
	}
}
