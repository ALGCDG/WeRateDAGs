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
  #include "./ast_allnodes.hpp"

  extern TranslationUnit *g_root; // A way of getting the AST out
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 58 "src/parser.tab.hpp" /* yacc.c:1909  */

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
    Operator = 265,
    Operator_add = 266,
    Operator_sub = 267,
    Operator_addadd = 268,
    Operator_subsub = 269,
    Operator_mul = 270,
    Operator_div = 271,
    Operator_mod = 272,
    Operator_and = 273,
    Operator_or = 274,
    Operator_not = 275,
    Operator_assign = 276,
    Operator_equal = 277,
    Operator_not_equal = 278,
    Operator_greater = 279,
    Operator_less = 280,
    Operator_greater_equal = 281,
    Operator_less_equal = 282,
    Operator_bit_and = 283,
    Operator_bit_or = 284,
    Operator_bit_not = 285,
    Operator_bit_xor = 286,
    Operator_sl = 287,
    Operator_sr = 288,
    Operator_add_assign = 289,
    Operator_sub_assign = 290,
    Operator_mul_assign = 291,
    Operator_div_assign = 292,
    Operator_mod_assign = 293,
    Operator_and_assign = 294,
    Operator_or_assign = 295,
    Operator_xor_assign = 296,
    Operator_sr_assign = 297,
    Operator_sl_assign = 298,
    Operator_ref = 299,
    Operator_deref = 300,
    Operator_access = 301,
    Operator_deref_access = 302,
    Operator_sizeof = 303,
    Operator_trinary_question = 304,
    Operator_trinary_choice = 305,
    Operator_comma = 306,
    Keyword = 307,
    Keyword_void = 308,
    Keyword_char = 309,
    Keyword_short = 310,
    Keyword_int = 311,
    Keyword_long = 312,
    Keyword_float = 313,
    Keyword_double = 314,
    Keyword_signed = 315,
    Keyword_unsigned = 316,
    Keyword_case = 317,
    Keyword_default = 318,
    Keyword_if = 319,
    Keyword_else = 320,
    Keyword_switch = 321,
    Keyword_while = 322,
    Keyword_do = 323,
    Keyword_for = 324,
    Keyword_continue = 325,
    Keyword_break = 326,
    Keyword_return = 327,
    Keyword_enum = 328,
    Keyword_struct = 329,
    Keyword_typedef = 330,
    Punctuator = 331,
    Punctuator_eol = 332,
    Punctuator_par_open = 333,
    Punctuator_par_close = 334,
    Punctuator_squ_open = 335,
    Punctuator_squ_close = 336,
    Punctuator_cur_open = 337,
    Punctuator_cur_close = 338
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "src/parser.y" /* yacc.c:1909  */

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

#line 201 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
