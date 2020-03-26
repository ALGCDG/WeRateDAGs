%code requires{

  #include<iostream>
  #include<string>
  #include "./ast_allnodes.hpp"

  extern TranslationUnit *g_root; // A way of getting the AST out
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
    Node* node;
    Expression* expression;
    ArgExprList* argexprlist;
    IdentifierNode* identnode;
    type_name* _typename;
    ConstantExpression* constexp;
    Statement* stmt;
    StatementList* stmtlist;
    ExpressionStatement* exprstmt;
    DeclarationList*  t_declist;
    declaration       *    t_declaration;
    declaration_specifiers * t_declaration_specifiers;
    TypedefNode * t_storage_class_specifier;
    init_declarator_list  * t_init_declarator_list;
    init_declarator       * t_init_declarator;
    type_specifier        * t_type_specifier;

    specifier_list        * t_specifier_list;
    declarator            * t_declarator;
    direct_declarator     * t_direct_declarator;
    pointer               * t_pointer;
    /*parameter_type_list  *  t_parameter_type_list;*/
    parameter_list       *  t_parameter_list;
    parameter_declaration * t_parameter_declaration;
    type_name            *  t_type_name;
    abstract_declarator *   t_abstract_declarator;
    direct_abstract_declarator * t_direct_abstract_declarator;
    initializer * t_initializer;
    initializer_list * t_initializer_list;
    CompoundStatement * cmpstmt;

    TranslationUnit * t_translation_unit;
    GenericExternalDeclaration * t_external_declaration;
    FunctionDefinition * t_function_definition;

    struct_specifier* struct_spec;
    struct_declaration* struct_dection;
    struct_declaration_list* struct_dection_list;
    struct_declarator_list* struct_dec_list;

    Enumerator* t_enumerator;
    EnumeratorList* t_enumlist;
};

%token Constant_int Constant_char Constant_double Constant_float Constant_long_double
%token String /*What is this for*/
%token Identifier
%token Operator Operator_add  Operator_sub  Operator_addadd  Operator_subsub  Operator_mul  Operator_div  Operator_mod  Operator_and  Operator_or  Operator_not  Operator_assign  Operator_equal  Operator_not_equal  Operator_greater  Operator_less  Operator_greater_equal  Operator_less_equal  Operator_bit_and  Operator_bit_or  Operator_bit_not  Operator_bit_xor  Operator_sl  Operator_sr  Operator_add_assign  Operator_sub_assign  Operator_mul_assign  Operator_div_assign  Operator_mod_assign  Operator_and_assign  Operator_or_assign  Operator_xor_assign  Operator_sr_assign  Operator_sl_assign  Operator_ref  Operator_deref  Operator_access  Operator_deref_access  Operator_sizeof  Operator_trinary_question  Operator_trinary_choice  Operator_comma 
%token Keyword Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return Keyword_enum Keyword_struct Keyword_typedef
%token Punctuator Punctuator_eol Punctuator_par_open Punctuator_par_close Punctuator_squ_open Punctuator_squ_close Punctuator_cur_open Punctuator_cur_close

%type <t_type_specifier> struct_specifier
%type <struct_dection> struct_declaration
%type <struct_dection_list> struct_declaration_list
%type <struct_dec_list> struct_declarator_list

%type <ivalue> Constant_int
%type <cvalue> Constant_char
%type <dvalue> Constant_double
%type <fvalue> Constant_float
%type <ldvalue> Constant_long_double
%type <text> Identifier
%type <text> Keyword Keyword_void Keyword_char Keyword_short Keyword_int Keyword_long Keyword_float Keyword_double Keyword_signed Keyword_unsigned Keyword_case Keyword_default Keyword_if Keyword_else Keyword_switch Keyword_while Keyword_do Keyword_for Keyword_continue Keyword_break Keyword_return Keyword_enum Keyword_struct Keyword_typedef


%type <expression> primary_EXPR
%type <identnode> Ident
%type <expression> Constant
%type <expression> postfix_EXPR
%type <argexprlist> argument_EXPR_list
%type <expression> unary_EXPR
%type <text> unary_operator
%type <expression> cast_EXPR
%type <expression> multiplicative_EXPR
%type <expression> additive_EXPR
%type <expression> shift_EXPR
%type <expression> relational_EXPR
%type <expression> equality_EXPR
%type <expression> BIT_AND_EXPR
%type <expression> BIT_XBIT_OR_EXPR
%type <expression> BIT_OR_EXPR
%type <expression> LOGIC_AND_EXPR
%type <expression> LOGIC_OR_EXPR
%type <expression> conditional_EXPR
%type <expression> assignment_EXPR
%type <text> assignment
%type <expression> EXPR
%type <constexp> constant_EXPR

%type <t_declaration> declaration
%type <t_declaration_specifiers> declaration_specifiers
%type <t_storage_class_specifier> storage_class_specifier
%type <t_init_declarator_list> init_declarator_list
%type <t_init_declarator> init_declarator
%type <t_type_specifier> type_specifier
%type <t_specifier_list> specifier_list
%type <t_declarator> declarator
%type <t_direct_declarator> direct_declarator
%type <t_pointer> pointer
%type <t_parameter_list> parameter_type_list
%type <t_parameter_list> parameter_list
%type <t_parameter_declaration> parameter_declaration
%type <t_type_name> type_name
%type <t_abstract_declarator> abstract_declarator
%type <t_direct_abstract_declarator> direct_abstract_declarator
%type <t_initializer> initializer
%type <t_initializer_list> initializer_list

%type <stmt> statement
%type <stmt> labeled_statement
%type <cmpstmt> compound_statement
%type <t_declist> declaration_list
%type <stmtlist> statement_list
%type <exprstmt> EXPR_statement
%type <stmt> selection_statement
%type <stmt> iteration_statement
%type <stmt> jump_statement 

%type <t_translation_unit> translation_unit
%type <t_external_declaration> external_declaration
%type <t_function_definition> function_definition

%type <t_type_specifier> enum_specifier
%type <t_enumerator> enumerator
%type <t_enumlist> enum_list
%type <identnode> ENUM_CONST

%start ROOT


%%

/*
EXPRESSIONS
*/

primary_EXPR: Ident { $$ = $1; }
                  | Constant { $$ = $1; }
                  | String { std::cerr << "STRING" << std::endl; }
                  | Punctuator_par_open EXPR Punctuator_par_close { $$ = $2; }

Ident: Identifier { $$ = new IdentifierNode(*($1)); } 

Constant: Constant_int { $$ = new constant_int($1); }  
		| Constant_char  { $$ = new Constant(); }  
		| Constant_double { $$ = new Constant(); }  
		| Constant_float { $$ = new Constant(); }  
		| Constant_long_double { $$ = new Constant(); }  

postfix_EXPR: primary_EXPR { $$ = $1; } /*Pass through*/
                  | postfix_EXPR Punctuator_squ_open EXPR Punctuator_squ_close { $$ = new ArraySubscript($1, $3); }
                  | postfix_EXPR Punctuator_par_open  Punctuator_par_close  { $$ = new FuncCall($1); }
                  | postfix_EXPR Punctuator_par_open argument_EXPR_list Punctuator_par_close  { $$ = new FuncCall($1, $3); }
                  | postfix_EXPR Operator_access Ident   { $$ = new MemberAccess($1, $3); }
                  | postfix_EXPR Operator_deref_access Ident   { $$ = new DerefMemberAccess($1, $3); }
                  | postfix_EXPR Operator_addadd  { $$ = new PostInc($1); }
                  | postfix_EXPR Operator_subsub  { $$ = new PostDec($1); }


argument_EXPR_list: assignment_EXPR { $$ = new ArgExprList($1); }
                  | argument_EXPR_list Operator_comma assignment_EXPR { ($1)->AppendArgExpression($3); }

unary_EXPR: postfix_EXPR { $$=$1; }
		  | Operator_addadd unary_EXPR { $$ = new PreInc($2); }
		  | Operator_subsub unary_EXPR { $$ = new PreDec($2); }
      | unary_operator cast_EXPR { $$ = PrefixExpr::DecodeUnaryOp($1,$2); }
      | Operator_sizeof unary_EXPR { $$ = new SizeofExpr($2); }
      | Operator_sizeof Punctuator_par_open type_name Punctuator_par_close  { $$ = new SizeofType($3); } 

unary_operator: Operator_bit_and { $$ = new std::string("&");} 
              | Operator_mul { $$ = new std::string("*");}
              | Operator_add { $$ = new std::string("+");}
              | Operator_sub { $$ = new std::string("-");}
              | Operator_bit_not { $$ = new std::string("~");}
              | Operator_not { $$ = new std::string("!");}

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

relational_EXPR: shift_EXPR { $$ = $1; }
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
              | LOGIC_AND_EXPR Operator_and BIT_OR_EXPR{ $$ = new LogicalAND($1, $3); }

LOGIC_OR_EXPR: LOGIC_AND_EXPR { $$ = $1; }
             | LOGIC_OR_EXPR Operator_or LOGIC_AND_EXPR{ $$ = new LogicalOR($1, $3); }

conditional_EXPR: LOGIC_OR_EXPR { $$ = $1; }
                | LOGIC_OR_EXPR Operator_trinary_question EXPR Operator_trinary_choice conditional_EXPR { $$ = new TernaryOpExpression($1, $3, $5); }

assignment_EXPR: conditional_EXPR { $$ = $1; }
               | unary_EXPR assignment assignment_EXPR { $$ = GenericAssignExpr::DecodeAssignOp($1, $2, $3); }
               

assignment: Operator_assign { $$ = new std::string("=");} 
          | Operator_mul_assign { $$ = new std::string("*=");}
          | Operator_div_assign { $$ = new std::string("/=");}
          | Operator_mod_assign { $$ = new std::string("%=");}
          | Operator_add_assign { $$ = new std::string("+=");}
          | Operator_sub_assign { $$ = new std::string("-=");}
          | Operator_sl_assign { $$ = new std::string("<<=");}
          | Operator_sr_assign { $$ = new std::string(">>=");}
          | Operator_and_assign { $$ = new std::string("&=");}
          | Operator_xor_assign { $$ = new std::string("^=");}
          | Operator_or_assign{ $$ = new std::string("|=");}
               

EXPR: assignment_EXPR { $$ = $1; }
    | EXPR Operator_comma assignment_EXPR { $$ = new CommaSepExpression($1, $3); }

constant_EXPR: conditional_EXPR { $$ = new ConstantExpression($1); std::cerr << "new constant expression" << std::endl;}

/*
DECLARATIONS
*/


declaration: declaration_specifiers init_declarator_list Punctuator_eol { $$ = new declaration($1, $2); }
           | declaration_specifiers Punctuator_eol { $$ = new declaration($1); }

declaration_specifiers: storage_class_specifier { $$ = new declaration_specifiers(NULL,NULL,$1); }
                      | storage_class_specifier declaration_specifiers { $$ = new declaration_specifiers(NULL,$2,$1); }
                      | type_specifier { $$ = new declaration_specifiers($1); }
                      | type_specifier declaration_specifiers { $$ = new declaration_specifiers($1, $2); }

storage_class_specifier: Keyword_typedef { $$ = new TypedefNode; }

init_declarator_list: init_declarator { $$ = new init_declarator_list($1); }
                    | init_declarator_list Operator_comma init_declarator { $$ = new init_declarator_list($3, $1); }

init_declarator: declarator { $$ = new init_declarator($1); }
               | declarator Operator_assign initializer { $$ = new init_declarator($1, $3); }

type_specifier: Keyword_void { $$ = new type_specifier("void"); }
              | Keyword_char { $$ = new type_specifier("char"); }
              | Keyword_short { $$ = new type_specifier("short"); }
              | Keyword_int { $$ = new type_specifier("int"); }
              | Keyword_long { $$ = new type_specifier("long"); }
              | Keyword_float { $$ = new type_specifier("float"); }
              | Keyword_double { $$ = new type_specifier("double"); }
              | Keyword_signed { $$ = new type_specifier("signed"); }
              | Keyword_unsigned{ $$ = new type_specifier("unsigned"); }
              | enum_specifier { $$ = $1; }
/*              | typedef_name { std::cerr << "typedef type" << std::endl; }*/
              | struct_specifier{ $$ = $1; }

struct_specifier: Keyword_struct Ident Punctuator_cur_open struct_declaration_list Punctuator_cur_close 
        { $$ = new struct_specifier($2, $4); }
				| Keyword_struct Punctuator_cur_open struct_declaration_list Punctuator_cur_close 
        { $$ = new struct_specifier(NULL, $3); }
				| Keyword_struct Ident { $$ = new struct_specifier($2); }

struct_declaration_list: struct_declaration { $$ = new struct_declaration_list($1); }
					   | struct_declaration_list struct_declaration { $1->AppendDeclaration($2); }

struct_declaration: specifier_list struct_declarator_list Punctuator_eol { $$ = new struct_declaration($1, $2); }

specifier_list: type_specifier  { $$ = new specifier_list($1); } /*TODO!*/
						| type_specifier specifier_list { $$ = new specifier_list($1, $2); }

struct_declarator_list: declarator { $$ = new struct_declarator_list($1); }
					  | struct_declarator_list Operator_comma declarator { $1->AppendDeclarator($3); }

/*This includes bitfields which are not required -> struct declarator === declarator
struct_declarator: declarator
                 | declarator Operator_trinary_choice struct_declarator
                 | Operator_trinary_choice struct_declarator
*/


enum_specifier: Keyword_enum Ident { $$ = new EnumSpecifier($2); }
			  | Keyword_enum Ident Punctuator_cur_open enum_list Punctuator_cur_close { $$ = new EnumSpecifier($2, $4); }
			  | Keyword_enum Punctuator_cur_open enum_list Punctuator_cur_close { $$ = new EnumSpecifier($3); }

enum_list: enumerator { $$ = new EnumeratorList($1); }
		 | enum_list Operator_comma enumerator { ($1)->AppendEnumerator($3);}

enumerator: ENUM_CONST { $$ = new Enumerator($1);}
		  | ENUM_CONST Operator_assign constant_EXPR { $$ = new Enumerator($1, $3);}

ENUM_CONST: Ident { $$ = $1; }

declarator: direct_declarator { $$ = new declarator($1); }
		  | pointer direct_declarator { $$ = new declarator($2, $1); }


direct_declarator: Ident { $$ = new direct_declarator($1); }
				 | Punctuator_par_open declarator Punctuator_par_close  { $$ = new direct_declarator(NULL, NULL, NULL,NULL, $2); }
				 | direct_declarator Punctuator_squ_open Punctuator_squ_close  { $$ = new direct_declarator(NULL, $1, new unspecified_array_length()); }
				 | direct_declarator Punctuator_squ_open constant_EXPR Punctuator_squ_close  { $$ = new direct_declarator(NULL, $1, $3); }
				 | direct_declarator Punctuator_par_open parameter_type_list  Punctuator_par_close  { $$ = new direct_declarator(NULL, $1, NULL, $3); }
				 /*| direct_declarator Punctuator_par_open identifier_list Punctuator_par_close { std::cerr << "still not sure what this does" << std::endl; } k&r style, not needed*/
				 | direct_declarator Punctuator_par_open Punctuator_par_close { $$ = new direct_declarator(NULL, $1, NULL, new empty_parameter_list()); }

pointer: Operator_mul { $$ = new pointer(); }
	   | Operator_mul pointer { $$ = new pointer($2); }

parameter_type_list: parameter_list { $$ = $1; }

parameter_list: parameter_declaration { $$ = new parameter_list($1); }
		 	  | parameter_list Operator_comma parameter_declaration { $$ = new parameter_list($3, $1); }

parameter_declaration: declaration_specifiers declarator { $$ = new parameter_declaration($1, $2); }
					 | declaration_specifiers  { $$ = new parameter_declaration($1); }
					 | declaration_specifiers abstract_declarator { $$ = new parameter_declaration($1, NULL, $2); }

/*identifier_list: Ident
			   | identifier_list Operator_comma Ident
K&R -> don't need
*/

type_name: specifier_list { $$ = new type_name($1); }
		 | specifier_list abstract_declarator { $$ = new type_name($1, $2); }

abstract_declarator: pointer { $$ = new abstract_declarator(NULL, $1); }
					| pointer direct_abstract_declarator { $$ = new abstract_declarator($2, $1); }
					| direct_abstract_declarator { $$ = new abstract_declarator($1); }

direct_abstract_declarator: Punctuator_par_open abstract_declarator Punctuator_par_close { $$ = new direct_abstract_declarator(NULL, $2); }
						  | direct_abstract_declarator Punctuator_squ_open constant_EXPR Punctuator_squ_close { $$ = new direct_abstract_declarator($1, NULL, $3); }
						  | Punctuator_squ_open constant_EXPR Punctuator_squ_close { $$ = new direct_abstract_declarator(NULL, NULL, $2); }
						  | direct_abstract_declarator Punctuator_squ_open Punctuator_squ_close { $$ = new direct_abstract_declarator($1, NULL, new unspecified_array_length()); }
						  | Punctuator_squ_open Punctuator_squ_close { $$ = new direct_abstract_declarator(NULL, NULL, new unspecified_array_length()); }
						  | direct_abstract_declarator Punctuator_par_open parameter_type_list Punctuator_par_close { $$ = new direct_abstract_declarator($1, NULL, NULL, $3); }
						  | Punctuator_par_open parameter_type_list Punctuator_par_close { $$ = new direct_abstract_declarator(NULL, NULL, NULL, $2); }
						  | direct_abstract_declarator Punctuator_par_open Punctuator_par_close { $$ = new direct_abstract_declarator($1, NULL, NULL, new empty_parameter_list()); }
						  | Punctuator_par_open Punctuator_par_close { $$ = new direct_abstract_declarator(NULL, NULL, NULL, new empty_parameter_list()); }

/*
typedef_name: Ident  { std::cerr << "typedef" << std::endl; }
*/
initializer: assignment_EXPR { $$ = new initializer($1); }
		   | Punctuator_cur_open initializer_list Punctuator_cur_close  { $$ = new initializer(NULL, $2); }
		   | Punctuator_cur_open initializer_list Operator_comma Punctuator_cur_close { $$ = new initializer(NULL, $2); }

initializer_list: initializer  { $$ = new initializer_list($1); }
				| initializer_list Operator_comma initializer { $$ = new initializer_list($3, $1); }



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
                  | Punctuator_cur_open Punctuator_cur_close { $$ = new CompoundStatement(); }

declaration_list: declaration {$$ = new DeclarationList($1); }
                | declaration_list declaration { $$ = new DeclarationList($1, $2); }

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
translation_unit: external_declaration { $$ = new TranslationUnit($1); }
                | translation_unit external_declaration { ($1)->AppendDeclaration($2); }

external_declaration: function_definition { $$ = $1; }
                    | declaration { $$ = new ExternalDeclaration($1); }

function_definition: declarator compound_statement { $$ = new FunctionDefinition($1, $2); }
                   | declaration_specifiers declarator compound_statement { $$ = new FunctionDefinition($1, $2, $3); }
                   /*| declaration_specifiers declaration declaration_list compound_statement -> only for K&R*/


ROOT: translation_unit {g_root = $1; }

%%

TranslationUnit *g_root; // Definition of variable (to match declaration earlier)

TranslationUnit * parseAST()
{
  std::cerr << "parsing" << std::endl;
  g_root = 0;
  yyparse();
  return g_root;
}
/*
main()
{
	std::cerr << "starting parser" << std::endl;
	for(;;)
	{
		parseAST();
	}
}
*/
