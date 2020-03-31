/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:1909  */


  #include<iostream>
  #include<string>
  #include "ast_allnodes.hpp"
  #include "feSymtab.hpp"
  #include "feSymtabDec.hpp"

  extern TranslationUnit *g_root; // A way of getting the AST out
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

  


#line 63 "src/parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Constant_int = 258,
    Constant_char = 259,
    Constant_double = 260,
    Constant_float = 261,
    Constant_long_double = 262,
    String = 263,
    Identifier = 264,
    varIdentifier = 265,
    typedefIdentifier = 266,
    Operator = 267,
    Operator_add = 268,
    Operator_sub = 269,
    Operator_addadd = 270,
    Operator_subsub = 271,
    Operator_mul = 272,
    Operator_div = 273,
    Operator_mod = 274,
    Operator_and = 275,
    Operator_or = 276,
    Operator_not = 277,
    Operator_assign = 278,
    Operator_equal = 279,
    Operator_not_equal = 280,
    Operator_greater = 281,
    Operator_less = 282,
    Operator_greater_equal = 283,
    Operator_less_equal = 284,
    Operator_bit_and = 285,
    Operator_bit_or = 286,
    Operator_bit_not = 287,
    Operator_bit_xor = 288,
    Operator_sl = 289,
    Operator_sr = 290,
    Operator_add_assign = 291,
    Operator_sub_assign = 292,
    Operator_mul_assign = 293,
    Operator_div_assign = 294,
    Operator_mod_assign = 295,
    Operator_and_assign = 296,
    Operator_or_assign = 297,
    Operator_xor_assign = 298,
    Operator_sr_assign = 299,
    Operator_sl_assign = 300,
    Operator_ref = 301,
    Operator_deref = 302,
    Operator_access = 303,
    Operator_deref_access = 304,
    Operator_sizeof = 305,
    Operator_trinary_question = 306,
    Operator_trinary_choice = 307,
    Operator_comma = 308,
    Keyword = 309,
    Keyword_void = 310,
    Keyword_char = 311,
    Keyword_short = 312,
    Keyword_int = 313,
    Keyword_long = 314,
    Keyword_float = 315,
    Keyword_double = 316,
    Keyword_signed = 317,
    Keyword_unsigned = 318,
    Keyword_case = 319,
    Keyword_default = 320,
    Keyword_if = 321,
    Keyword_else = 322,
    Keyword_switch = 323,
    Keyword_while = 324,
    Keyword_do = 325,
    Keyword_for = 326,
    Keyword_continue = 327,
    Keyword_break = 328,
    Keyword_return = 329,
    Keyword_enum = 330,
    Keyword_struct = 331,
    Keyword_typedef = 332,
    Punctuator = 333,
    Punctuator_eol = 334,
    Punctuator_par_open = 335,
    Punctuator_par_close = 336,
    Punctuator_squ_open = 337,
    Punctuator_squ_close = 338,
    Punctuator_cur_open = 339,
    Punctuator_cur_close = 340
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "src/parser.y" /* yacc.c:1909  */

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

#line 212 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
