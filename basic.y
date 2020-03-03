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
%token Keyword Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return Keyword_enum Keyword_struct Keyword_typedef
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

primary_EXPR: Identifier { std::cerr << "IDENTIFIER" << std::endl; // $$ = new identifier($1); }
                 | Constant { std::cerr << "CONSTANT" << std::endl; // $$ = new constant($1);  }
                  | String { std::cerr << "STRING" << std::endl; // $$ = new string($1);  }
              | Punctuator_par_open EXPR Punctuator_par_close { std::cout << "(x)" << std::endl; }


Constant: Constant_int {}  
		| Constant_char {}
		| Constant_double {}
		| Constant_float {}
		| Constant_long_double {}


postfix_EXPR: primary_EXPR { $$ = $1; } /*Pass through*/
                  | postfix_EXPR Punctuator_squ_open EXPR Punctuator_squ_close { $$ = new ArraySubscript($1, $3); }
                  | postfix_EXPR Punctuator_par_open  Punctuator_par_close  { $$ = new FuncCall($1); }
                  | postfix_EXPR Punctuator_par_open argument_EXPR_list Punctuator_par_close  { $$ = new FuncCall($1, $3); }
                  | postfix_EXPR Operator_access Identifier   { $$ = new MemberAccess($1, $3); }
                  | postfix_EXPR Operator_deref_access Identifier   { $$ = new DerefMemberAccess($1, $3); }
                  | postfix_EXPR Operator_addadd  { $$ = new PostInc($1); }
                  | postfix_EXPR Operator_subsub  { $$ = new PostDec($1); }


argument_EXPR_list: assignment_EXPR { $$ = new ArgExprList($1); }
                  | argument_EXPR_list Operator_comma assignment_EXPR { ($1)->AppendArgExpression($3); }

unary_EXPR: postfix_EXPR { $$=$1; }
		  | Operator_addadd unary_EXPR { $$ = new PreInc($2); }
		  | Operator_subsub unary_EXPR { $$ = new PreDec($2); }
      | unary_operator cast_EXPR { $$ = new CastExpr($2); }
      | Operator_sizeof unary_EXPR { $$ = new SizeofExpr($2); }
      | Operator_sizeof Punctuator_par_open type_name Punctuator_par_close  { $$ = new SizeofType($3); } 

unary_operator: Operator_bit_and | Operator_mul | Operator_add | Operator_sub | Operator_bit_not | Operator_not

cast_EXPR: unary_EXPR { $$ = $1; }
               | Punctuator_par_open type_name Punctuator_par_close cast_EXPR { $$ = new CastExpr($2, $4); }

multiplicative_EXPR: cast_EXPR { $$ = $1; }
                         | multiplicative_EXPR Operator_mul cast_EXPR { $$ = new Multiply($1, $3); }
                         | multiplicative_EXPR Operator_div cast_EXPR { $$ = new Divide($1, $3); }  
						             | multiplicative_EXPR Operator_mod cast_EXPR { $$ = new Modulo($1, $3); }


additive_EXPR: multiplicative_EXPR { $$ = $1;}
                   | additive_EXPR Operator_add multiplicative_EXPR { $$ = new Add($1, $3); }
                   | additive_EXPR Operator_sub multiplicative_EXPR { $$ = new Sub($1, $3); }

shift_EXPR: additive_EXPR { $$ = $1; }
          | shift_EXPR Operator_sl additive_EXPR { $$ = new ShiftLeft($1, $3); }
          | shift_EXPR Operator_sr additive_EXPR { $$ = new ShiftRight($1, $3); }

relational_EXPR: shift_EXPR
               | relational_EXPR Operator_less shift_EXPR { $$ = new LessThan($1, $3); }
               | relational_EXPR Operator_greater shift_EXPR { $$ = new GreaterThan($1, $3); }
               | relational_EXPR Operator_less_equal shift_EXPR { $$ = new LessThanOrEqual($1, $3); }
               | relational_EXPR Operator_greater_equal shift_EXPR { $$ = new GreaterThanOrEqual($1, $3); }

equality_EXPR: relational_EXPR { $$ = $1; }
             | equality_EXPR Operator_equal relational_EXPR { $$ = new EqualTo($1, $3); }
             | equality_EXPR Operator_not_equal relational_EXPR { $$ = new NotEqualTo($1, $3); }



BIT_AND_EXPR: equality_EXPR { $$ = $1; }
        | BIT_AND_EXPR Operator_bit_and equality_EXPR { $$ = new BitwiseAND($1, $3); }

BIT_XBIT_OR_EXPR: BIT_AND_EXPR { $$ = $1; }
        | BIT_XBIT_OR_EXPR Operator_bit_xor BIT_AND_EXPR{ $$ = new BitwiseXOR($1, $3); }

BIT_OR_EXPR: BIT_XBIT_OR_EXPR { $$ = $1; }
       | BIT_OR_EXPR Operator_bit_or BIT_XBIT_OR_EXPR{ $$ = new BitwiseOR($1, $3); }

LOGIC_AND_EXPR: BIT_OR_EXPR { $$ = $1; }
              | LOGIC_AND_EXPR Operator_and BIT_OR_EXPR{ $$ = new LogicAND($1, $3); }

LOGIC_OR_EXPR: LOGIC_AND_EXPR { $$ = $1; }
             | LOGIC_OR_EXPR Operator_or LOGIC_AND_EXPR{ $$ = new LogicOR($1, $3); }

conditional_EXPR: LOGIC_OR_EXPR { $$ = $1; }
                | LOGIC_OR_EXPR Operator_trinary_question EXPR Operator_trinary_choice conditional_EXPR { $$ = new TernaryOpExpression($1, $3, $5); }

assignment_EXPR: conditional_EXPR { $$ = $1; }
               | unary_EXPR assignment assignment_EXPR { $$ = GenericAssignExpr::DecodeAssignOp($1, $2, $3); }
               
assignment: Operator_assign | Operator_mul_assign | Operator_div_assign | Operator_mod_assign | Operator_add_assign | Operator_sub_assign | Operator_sl_assign | Operator_sr_assign | Operator_and_assign | Operator_xor_assign | Operator_or_assign
               

EXPR: assignment_EXPR { $$ = $1; }
    | EXPR Operator_comma assignment_EXPR { $$ = new CommaSepExpression($1, $3); }

constant_EXPR: conditional_EXPR { ConstantExpression($1); }

/*
DECLARATIONS
*/


declaration: declaration_specifiers init_declarator_list Punctuator_eol { std::cerr << "decspec list ;" << std::endl; }
           | declaration_specifiers Punctuator_eol { std::cerr << "decspec ;" << std::endl; }

declaration_specifiers: storage_class_specifier { std::cerr << "stor" << std::endl; }
                      | storage_class_specifier declaration_specifiers { std::cerr << "stor decspec" << std::endl; }
                      | type_specifier  { std::cerr << "typspec list" << std::endl; }
                      | type_specifier declaration_specifiers  { std::cerr << "typspec decspec" << std::endl; }

storage_class_specifier: Keyword_typedef { std::cerr << "typedef" << std::endl; }

init_declarator_list: init_declarator  { std::cerr << "initdec" << std::endl; }
                    | init_declarator_list Operator_comma init_declarator { std::cerr << "initdeclist , initdec " << std::endl; }

init_declarator: declarator { std::cerr << "dec" << std::endl; }
               | declarator Operator_assign initializer { std::cerr << "dec = init" << std::endl; }

type_specifier: Keyword_void | Keyword_char | Keyword_short | Keyword_int | Keyword_long | Keyword_float | Keyword_double | Keyword_signed | Keyword_unsigned
/*              | struct_specifier { std::cerr << "struct" << std::endl; }
              | enum_specifier { std::cerr << "enum" << std::endl; }
              | typedef_name { std::cerr << "typedef type" << std::endl; }

struct_specifier: Keyword_struct Identifier Punctuator_cur_open struct_declaration_list Punctuator_cur_close { std::cerr << "struct x {...}" << std::endl; }
				| Keyword_struct Punctuator_cur_open struct_declaration_list Punctuator_cur_close { std::cerr << "struct {...}" << std::endl; }
				| Keyword_struct Identifier { std::cerr << "struct x" << std::endl; }



struct_declaration_list: struct_declaration
					   | struct_declaration_list struct_declaration

struct_declaration: specifier_list struct_declarator_list
*/
specifier_list: type_specifier  { std::cerr << "tysp" << std::endl; }
						| type_specifier specifier_list { std::cerr << "tysp spli" << std::endl; }
/*
struct_declarator_list: struct_declarator
					  | struct_declarator_list Operator_comma struct_declarator

struct_declarator: declarator
                 | declarator Operator_trinary_choice struct_declarator
                 | Operator_trinary_choice struct_declarator


enum_specifier: Keyword_enum Identifier
			  | Keyword_enum Identifier Punctuator_cur_open enum_list Punctuator_cur_close
			  | Keyword_enum Punctuator_cur_open enum_list Punctuator_cur_close

enum_list: enumerator
		 | enum_list Operator_comma enumerator

enumerator: ENUM_CONST
		  | ENUM_CONST Operator_assign constant_EXPR

ENUM_CONST: Identifier
*/
declarator: direct_declarator { std::cerr << "direct dec" << std::endl; }
		  | pointer direct_declarator { std::cerr << "point direct dec" << std::endl; }


direct_declarator: Identifier
				 | Punctuator_par_open declarator Punctuator_par_close
				 | direct_declarator Punctuator_squ_open Punctuator_squ_close
				 | direct_declarator Punctuator_squ_open constant_EXPR Punctuator_squ_close
				 | direct_declarator Punctuator_par_open parameter_type_list  Punctuator_par_close
				 | direct_declarator Punctuator_par_open identifier_list Punctuator_par_close
				 | direct_declarator Punctuator_par_open Punctuator_par_close

pointer: Operator_mul { std::cerr << "dumb pointer" << std::endl; }
	   | Operator_mul pointer { std::cerr << "pointer" << std::endl; }

parameter_type_list: parameter_list

parameter_list: parameter_declaration { std::cerr << "a parameter" << std::endl; }
		 	  | parameter_list Operator_comma parameter_declaration { std::cerr << "multiple parameters" << std::endl; }

parameter_declaration: declaration_specifiers declarator { std::cerr << "param dec" << std::endl; }
					 | declaration_specifiers  { std::cerr << "no param name" << std::endl; }
					 | declaration_specifiers abstract_declarator { std::cerr << "pass by reference" << std::endl; }

identifier_list: Identifier
			   | identifier_list Operator_comma Identifier

type_name: specifier_list
		 | specifier_list abstract_declarator

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

/*
typedef_name: Identifier  { std::cerr << "typedef" << std::endl; }
*/
initializer: assignment_EXPR { std::cerr << "assigning an initialiser" << std::endl; }
		   | Punctuator_cur_open initializer_list Punctuator_cur_close  { std::cerr << "{init}" << std::endl; }
		   | Punctuator_cur_open initializer_list Operator_comma Punctuator_cur_close { std::cerr << "{init,}" << std::endl; }

initializer_list: initializer  { std::cerr << "iniz" << std::endl; }
				| initializer_list Operator_comma initializer { std::cerr << "iniz, iniz" << std::endl; }



/*
ROOT: EXPR { std::cerr << "exp" << std::endl; }
	| declaration { std::cerr << "Its a declaration" << std::endl; }
*/


/*
Statements
*/

statement: selection_statement { $$ = $1; }
         | labeled_statement { $$ = $1; }
         | compound_statement { $$ = $1; }
         | EXPR_statement { $$ = $1; }
         | iteration_statement { $$ = $1; }
         | jump_statement { $$ = $1; }

labeled_statement: Keyword_case constant_EXPR Operator_trinary_choice statement { $$ = new CaseOrDefault($2, $4); }
                 | Keyword_default Operator_trinary_choice statement { $$ = new CaseOrDefault($3); }

compound_statement: Punctuator_cur_open declaration_list statement_list Punctuator_cur_close { $$ = new CompoundStatement($2, $3); }
                  | Punctuator_cur_open declaration_list Punctuator_cur_close { $$ = new CompoundStatement($2);}
                  | Punctuator_cur_open statement_list Punctuator_cur_close { $$ = new CompoundStatement($2); /*Will need to use arg overloaded constructor to differentiate between the above*/}
                  | Punctuator_cur_open Punctuator_cur_close

declaration_list: declaration
                | declaration_list declaration

statement_list: statement { $$ = new StatementList($1); }
              | statement_list statement { $$ = new StatementList($1, $2); }

EXPR_statement: EXPR Punctuator_eol { $$ = new ExpressionStatement($1); }
                    | Punctuator_eol { $$ = new EmptyStatement(); }

selection_statement: Keyword_if Punctuator_par_open EXPR Punctuator_par_close statement Keyword_else statement { $$ = new IfElse($3, $5, $7); }
                   | Keyword_if Punctuator_par_open EXPR Punctuator_par_close statement { $$ = new If($3, $5); }
                   | Keyword_switch Punctuator_par_open EXPR Punctuator_par_close statement { $$ = new Switch($3, $5); }

/*
my attempt to fix dangling else, still causing issue
selection_statement: M
                   | U

M: Keyword_if Punctuator_par_open EXPR Punctuator_par_close M Keyword_else M
 | NON_IF

U: Keyword_if Punctuator_par_open EXPR Punctuator_par_close selection_statement
 | Keyword_if Punctuator_par_open EXPR Punctuator_par_close M Keyword_else U
*/
iteration_statement: Keyword_while Punctuator_par_open EXPR Punctuator_par_close statement { $$ = new While($3, $5); }
                   | Keyword_do statement Keyword_while Punctuator_par_open EXPR Punctuator_par_close Punctuator_eol { $$ = new DoWhile($2, $5); }
                   | Keyword_for Punctuator_par_open EXPR_statement EXPR_statement EXPR Punctuator_par_close statement { $$ = new For($3,$4,$5,$7);}
                   | Keyword_for Punctuator_par_open EXPR_statement EXPR_statement Punctuator_par_close statement { $$ = new For($3,$4,$6);}

jump_statement: Keyword_continue Punctuator_eol { $$ = new Continue(); }
              | Keyword_break Punctuator_eol{ $$ = new Break(); }
              | Keyword_return Punctuator_eol{ $$ = new Return(); }
              | Keyword_return EXPR Punctuator_eol{ $$ = new Return($2); }
/*
ROOT: statement { std::cerr << "Its a valid program" << std::endl; }
*/

/*
External definitions
*/
translation_unit: external_declaration
                | translation_unit external_declaration

external_declaration: function_definition
                    | declaration

function_definition: declarator compound_statement
                   | declarator declaration_list compound_statement
                   | declaration_specifiers declarator compound_statement
                   | declaration_specifiers declaration declaration_list compound_statement


ROOT: translation_unit { std::cerr << "Its a valid program" << std::endl; }

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
