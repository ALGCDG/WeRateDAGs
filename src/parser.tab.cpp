/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "src/parser.y" /* yacc.c:355  */


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

  


#line 116 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 21 "src/parser.y" /* yacc.c:355  */

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

#line 265 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 282 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  217
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  359

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   180,   180,   181,   182,   183,   185,   186,   187,   189,
     190,   191,   192,   193,   195,   196,   197,   198,   199,   200,
     201,   202,   204,   205,   207,   208,   209,   210,   211,   212,
     214,   215,   216,   217,   218,   219,   221,   222,   224,   225,
     226,   227,   230,   231,   232,   234,   235,   236,   238,   239,
     240,   241,   242,   244,   245,   246,   250,   251,   253,   254,
     256,   257,   259,   260,   262,   263,   265,   266,   268,   269,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   285,   286,   288,   295,   296,   297,   299,   300,   302,
     303,   304,   305,   308,   310,   312,   314,   316,   317,   319,
     320,   322,   323,   325,   326,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   342,   344,   346,
     350,   351,   353,   355,   356,   358,   359,   368,   369,   370,
     372,   373,   375,   376,   378,   380,   381,   384,   385,   386,
     387,   388,   390,   392,   394,   395,   396,   398,   399,   401,
     402,   404,   406,   407,   409,   410,   411,   418,   419,   421,
     422,   423,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   438,   439,   440,   442,   443,   457,   458,   459,   460,
     461,   462,   464,   465,   467,   468,   469,   470,   472,   473,
     474,   475,   477,   479,   482,   483,   485,   486,   488,   489,
     491,   492,   493,   506,   507,   508,   509,   511,   512,   513,
     514,   522,   523,   525,   526,   528,   529,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Constant_int", "Constant_char",
  "Constant_double", "Constant_float", "Constant_long_double", "String",
  "Identifier", "varIdentifier", "typedefIdentifier", "Operator",
  "Operator_add", "Operator_sub", "Operator_addadd", "Operator_subsub",
  "Operator_mul", "Operator_div", "Operator_mod", "Operator_and",
  "Operator_or", "Operator_not", "Operator_assign", "Operator_equal",
  "Operator_not_equal", "Operator_greater", "Operator_less",
  "Operator_greater_equal", "Operator_less_equal", "Operator_bit_and",
  "Operator_bit_or", "Operator_bit_not", "Operator_bit_xor", "Operator_sl",
  "Operator_sr", "Operator_add_assign", "Operator_sub_assign",
  "Operator_mul_assign", "Operator_div_assign", "Operator_mod_assign",
  "Operator_and_assign", "Operator_or_assign", "Operator_xor_assign",
  "Operator_sr_assign", "Operator_sl_assign", "Operator_ref",
  "Operator_deref", "Operator_access", "Operator_deref_access",
  "Operator_sizeof", "Operator_trinary_question",
  "Operator_trinary_choice", "Operator_comma", "Keyword", "Keyword_void",
  "Keyword_char", "Keyword_short", "Keyword_int", "Keyword_long",
  "Keyword_float", "Keyword_double", "Keyword_signed", "Keyword_unsigned",
  "Keyword_case", "Keyword_default", "Keyword_if", "Keyword_else",
  "Keyword_switch", "Keyword_while", "Keyword_do", "Keyword_for",
  "Keyword_continue", "Keyword_break", "Keyword_return", "Keyword_enum",
  "Keyword_struct", "Keyword_typedef", "Punctuator", "Punctuator_eol",
  "Punctuator_par_open", "Punctuator_par_close", "Punctuator_squ_open",
  "Punctuator_squ_close", "Punctuator_cur_open", "Punctuator_cur_close",
  "$accept", "primary_EXPR", "varIdent", "generalIdent", "Constant",
  "postfix_EXPR", "argument_EXPR_list", "unary_EXPR", "unary_operator",
  "cast_EXPR", "multiplicative_EXPR", "additive_EXPR", "shift_EXPR",
  "relational_EXPR", "equality_EXPR", "BIT_AND_EXPR", "BIT_XBIT_OR_EXPR",
  "BIT_OR_EXPR", "LOGIC_AND_EXPR", "LOGIC_OR_EXPR", "conditional_EXPR",
  "assignment_EXPR", "assignment", "EXPR", "constant_EXPR", "declaration",
  "declaration_specifiers", "declaration_specifiers_type",
  "storage_class_specifier", "declaratorVar", "declaratorVarFunc",
  "declaratorType", "init_declarator_list", "init_declarator_list_type",
  "init_declarator", "init_declarator_type", "type_specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "specifier_list", "struct_declarator_list", "enum_specifier",
  "enum_list", "enumerator", "ENUM_CONST", "declarator",
  "direct_declarator", "func_declarator", "direct_func_declarator",
  "paren_start_func_scope", "paren_end_func_scope", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "compound_statement_func", "newscope_paren",
  "endscope_paren", "declaration_list", "statement_list", "EXPR_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "ROOT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

#define YYPACT_NINF -218

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-218)))

#define YYTABLE_NINF -149

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1137,  -218,   146,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,    22,    26,  -218,   169,   -39,  -218,   182,   169,
    1231,   -34,  1231,  -218,  -218,   -17,  -218,  -218,  1137,  -218,
    -218,    82,  -218,   202,    41,   275,    45,   116,  -218,     5,
      -8,    17,  -218,   115,   -34,   128,  -218,  -218,   -17,   119,
     130,  -218,  -218,  -218,  -218,  1231,  -218,  -218,   467,  -218,
    -218,  1165,   683,  1194,  -218,  -218,  -218,   -24,  -218,   122,
     202,   275,  1036,  -218,   169,   275,  -218,  -218,  1165,    -8,
     662,  -218,   169,  -218,   662,   169,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,   996,   996,  -218,  -218,
    -218,  -218,  1027,  1058,    97,    72,    94,   117,   549,   152,
      98,   129,   916,  -218,   895,   783,  -218,  -218,  -218,   186,
     464,  1058,  -218,   201,   223,   229,   216,   251,   209,   214,
     221,   237,    27,  -218,  -218,   138,  -218,   182,  -218,  -218,
    -218,  -218,   297,   467,   580,  -218,  -218,  -218,  -218,  -218,
     124,   275,   206,   239,  -218,  -218,  -218,  -218,   184,  -218,
     212,   202,  -218,  1058,   -15,  -218,  -218,  -218,   142,  -218,
    1067,   662,  -218,  -218,  -218,  -218,  -218,  1058,  -218,  -218,
     895,  -218,   242,   549,  1058,  1058,  1058,   226,   975,  -218,
    -218,  -218,   143,   -27,    29,   215,  -218,  -218,   202,   202,
     803,  1058,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  1058,  -218,  1058,  1058,  1058,  1058,  1058,
    1058,  1058,  1058,  1058,  1058,  1058,  1058,  1058,  1058,  1058,
    1058,  1058,  1058,  1058,  1058,  -218,  -218,  -218,   297,   380,
    -218,  -218,   580,  -218,  -218,  1099,   715,  -218,    42,  -218,
     123,  -218,   275,  -218,  -218,  -218,  -218,  -218,   169,  -218,
    -218,  -218,   -14,   217,   549,  -218,    -4,    13,    14,   219,
     975,  -218,  -218,  1128,   149,  -218,  1058,  -218,  -218,  -218,
      34,  -218,    -2,  -218,  -218,  -218,  -218,   201,   201,   223,
     223,   229,   229,   229,   229,   216,   216,   251,   209,   214,
     221,   237,   225,  -218,  -218,   380,  -218,  -218,  -218,   228,
     234,  -218,   235,   123,  1204,   754,  -218,  -218,   411,  -218,
    -218,  -218,   549,   549,   549,  1058,   863,  -218,  1058,  -218,
    -218,  1058,  -218,  -218,  -218,  -218,  -218,   240,  -218,   241,
    -218,  -218,   230,  -218,  -218,    63,   549,    95,  -218,  -218,
    -218,  -218,   549,   243,  -218,   549,  -218,  -218,  -218
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,   115,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,    93,     0,   137,   214,     0,     0,
      89,     0,    87,   116,   114,     0,    95,   143,   217,   211,
     213,     0,     8,     0,   127,     0,   119,   149,   137,     0,
     135,     0,    86,   101,     0,     0,    97,    94,   135,   103,
       0,    99,    96,   115,    90,    91,   192,   215,     0,    88,
      92,     0,     0,     0,   212,     1,   134,     0,   130,   132,
       0,   123,     0,   120,     0,     0,   150,   138,     0,   136,
       0,   216,     0,    84,     0,     0,    85,     9,    10,    11,
      12,    13,     4,     6,    32,    33,     0,     0,    31,    35,
      30,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,   192,    14,     2,     3,    24,
      36,     0,    38,    42,    45,    48,    53,    56,    58,    60,
      62,    64,    66,    68,    81,     0,   194,     0,   191,   196,
     177,   178,     0,     0,     0,   179,   176,   180,   181,   142,
     155,    87,     0,   151,   152,   139,    36,    83,     0,   146,
       0,     0,   129,     0,     0,   124,   118,   121,     0,   125,
       0,     0,   171,   102,    98,   104,   100,     0,    25,    26,
       0,    28,     0,     0,     0,     0,     0,     0,     0,   207,
     208,   209,     0,     0,   157,     0,    20,    21,     0,     0,
       0,     0,    70,    74,    75,    71,    72,    73,    78,    80,
      79,    77,    76,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,   193,   187,     0,     0,
     195,   189,     0,   190,   197,     0,     0,   154,   159,   156,
     161,   141,     0,   140,   145,   131,   133,   128,     0,   122,
     117,   174,     0,     0,     0,   183,     0,     0,     0,     0,
       0,   210,     5,     0,   159,   158,     0,    18,    19,    16,
       0,    22,     0,    69,    39,    40,    41,    43,    44,    46,
      47,    50,    49,    52,    51,    54,    55,    57,    59,    61,
      63,    65,     0,    82,   185,     0,   186,   188,   170,     0,
       0,   166,     0,   160,     0,     0,   153,   126,     0,   172,
      29,   182,     0,     0,     0,     0,     0,    37,     0,    17,
      15,     0,   184,   168,   162,   164,   169,     0,   165,     0,
     173,   175,   201,   202,   203,     0,     0,     0,    23,    67,
     167,   163,     0,     0,   206,     0,   200,   204,   205
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,   118,  -218,  -218,  -218,   -62,  -218,  -103,
      62,    69,    49,    57,    92,    96,    93,   108,   109,  -218,
     -61,   -63,  -218,  -101,   -99,   -44,    47,    36,  -218,   176,
     310,  -218,  -218,  -218,   258,   257,    68,  -218,   268,   -53,
     -59,  -218,  -218,   274,   185,  -218,   -12,     2,  -218,  -218,
    -218,  -135,   -22,   -58,  -218,   112,   165,  -134,  -217,   -78,
    -218,   -64,  -218,  -218,   304,    83,  -216,   207,  -118,  -178,
    -218,  -218,  -218,  -218,   347,  -218,  -218
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   116,   117,    38,   118,   119,   280,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   213,   135,   158,    17,   150,    19,    20,    43,
      21,    49,    45,    50,    46,    51,   151,    23,    72,    73,
      74,   168,    24,    67,    68,    69,    47,    40,    26,    27,
      63,   138,    41,   152,   153,   154,   195,   310,   250,   173,
     262,   139,   140,   141,    57,   142,   237,   143,   144,   145,
     146,   147,   148,    28,    29,    30,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     156,   157,    25,    39,   182,   160,   175,    52,   241,   243,
     270,   192,   165,   193,   136,    76,   249,   172,   214,   167,
      48,   172,   304,   306,   239,   242,   234,     1,    32,   161,
      25,   313,     1,    32,   178,   179,     1,    32,   161,   318,
     181,   156,   157,    79,   187,  -144,    37,    18,   232,   234,
      56,   234,     1,    32,   272,   194,    54,   313,    60,   156,
     275,   162,   169,    61,   256,    62,   234,   234,    22,    59,
     257,   319,    78,    52,    62,    18,   193,   322,   233,   193,
     244,   330,    65,   266,   267,   268,    77,   328,    55,   332,
      22,    60,   326,   261,   323,   324,    22,    15,   136,   240,
     282,   156,   157,    71,    58,   137,    33,   307,   172,   273,
      35,   246,   284,   285,   286,   329,   234,   167,    16,   265,
     305,   194,   245,    55,   246,    70,    22,    58,   248,    75,
      34,    36,   302,    37,     1,    32,    16,   281,    80,    71,
      71,    37,    84,    71,   353,   163,    16,   312,   234,   183,
     283,    66,   184,   156,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     156,   303,   274,   327,   185,   244,   355,   189,   244,     1,
      32,    82,    71,    85,   156,   157,    37,   309,    66,   137,
     137,   234,     1,    32,   240,   258,   234,   186,    59,    37,
     321,   196,   197,   314,   245,   315,   246,    83,   190,    86,
      22,    22,     1,    32,   156,   309,   339,   235,   215,   216,
     217,   259,   271,   248,   345,   347,    -8,    -8,    -8,   273,
      -8,   246,   188,    39,   198,   199,   218,   219,    71,   228,
     341,   244,   222,   223,   224,   225,   317,   229,    71,    15,
      79,   274,   230,   156,   157,   172,   337,   231,   342,   343,
     344,    42,    15,   220,   221,   348,   200,   253,   201,   156,
     349,   291,   292,   293,   294,   226,   227,   331,   234,    66,
     287,   288,   354,   295,   296,   137,    53,   251,   356,   289,
     290,   358,   252,   254,   264,   269,   276,   352,   320,   325,
      87,    88,    89,    90,    91,    92,    22,    93,    53,   333,
      94,    95,    96,    97,    98,   334,   277,   278,   335,    99,
     297,   350,   357,   299,   351,   298,   247,   100,    44,   101,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   300,
     174,   301,   176,   170,   164,   263,   255,   102,    81,   238,
      12,    13,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   103,   104,   105,   316,   106,   107,   108,   109,   110,
     111,   112,    12,    13,    14,    64,   113,   114,     0,     0,
       0,    56,   236,    87,    88,    89,    90,    91,    92,     0,
      93,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
     100,     0,   101,     0,    87,    88,    89,    90,    91,    92,
       0,    93,     0,     0,    94,    95,    96,    97,    98,     0,
     102,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,   100,     0,   101,   103,   104,   105,     0,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,   102,     0,     0,    56,   236,     0,     0,     0,     0,
      87,    88,    89,    90,    91,    92,     0,    93,    53,     0,
      94,    95,    96,    97,    98,     0,     0,   202,     0,    99,
       0,   114,     0,     0,     0,   171,   340,   100,     0,   101,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   103,   104,   105,     0,   106,   107,   108,   109,   110,
     111,   112,    12,    13,    14,     0,   113,   114,     0,     0,
       0,   115,    87,    88,    89,    90,    91,    92,     0,    93,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,   100,
       0,   101,     0,    87,    88,    89,    90,    91,    92,     0,
      93,     0,     0,    94,    95,    96,    97,    98,     0,   102,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
     100,     0,   101,   103,   104,   105,     0,   106,   107,   108,
     109,   110,   111,   112,     0,     0,     0,     0,   113,   114,
     102,     0,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   106,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,   113,
     114,     0,     0,     0,   115,    87,    88,    89,    90,    91,
      92,     0,    93,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,    99,     0,    87,    88,    89,    90,
      91,    92,   100,    93,   101,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,   102,   100,     0,   101,     0,     0,    87,    88,
      89,    90,    91,    92,     0,    93,     0,     0,    94,    95,
      96,    97,    98,   102,     0,     0,     0,    99,     0,     0,
       0,     0,   114,     0,     0,   100,   171,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,    88,    89,
      90,    91,    92,   114,    93,   102,   155,    94,    95,    96,
      97,    98,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,  -148,   100,     0,   101,     0,     0,     0,
       0,     0,     0,  -148,  -148,   114,     0,     0,   311,     0,
       0,     0,     0,     0,   102,     0,    87,    88,    89,    90,
      91,    92,     0,    93,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,   100,   114,   101,     0,   338,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,     0,     0,     0,
       0,     0,     0,   102,     0,     0,     0,     0,  -148,  -148,
    -148,     0,     0,  -148,     0,     0,    87,    88,    89,    90,
      91,    92,     0,    93,     0,     0,    94,    95,    96,    97,
      98,     0,     0,   114,   279,    99,     0,     0,     0,     0,
       0,     0,     0,   100,     0,   101,     0,     0,    87,    88,
      89,    90,    91,    92,     0,    93,    53,     0,    94,    95,
      96,    97,    98,   102,     0,     0,     0,    99,     0,    87,
      88,    89,    90,    91,    92,   100,    93,   101,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,    99,     0,
       0,     0,     0,   114,   346,   102,   100,     0,   101,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,   102,     0,     0,     0,
      12,    13,     0,     0,     0,   114,     0,     0,    87,    88,
      89,    90,    91,    92,     0,    93,     0,     0,    94,    95,
      96,    97,    98,     0,     0,   191,   114,    99,     0,    87,
      88,    89,    90,    91,    92,   100,    93,   101,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,   102,   100,     0,   101,     0,
      87,    88,    89,    90,    91,    92,     0,    93,     0,     0,
      94,    95,    96,    97,    98,     0,   102,    53,     0,    99,
       0,     0,     0,     0,   113,   114,     0,   100,     0,   101,
       0,    87,    88,    89,    90,    91,    92,     0,    93,     0,
       0,    94,    95,    96,    97,    98,   177,   102,    53,     0,
      99,     0,     0,     0,     0,     0,     0,     0,   100,     0,
     101,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,   180,   102,     1,
       2,    12,    13,     0,     0,     0,    37,     0,     0,     0,
       0,   166,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,   114,    53,
       0,     0,    12,    13,     0,    37,     0,     1,     2,     0,
       0,     0,   260,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,    53,     0,     0,   245,
     308,   246,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,    12,    13,    53,     0,     0,   273,   308,
     246,     0,    12,    13,    14,    53,     0,    15,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,    53,     0,     0,     0,   149,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
      13,     0,     0,     0,     0,   159,     0,     0,     0,    12,
      13,     0,     0,     0,     0,   336,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,    14
};

static const yytype_int16 yycheck[] =
{
      62,    62,     0,    15,   103,    63,    84,    19,   143,   144,
     188,   112,    71,   114,    58,    37,   150,    80,   121,    72,
      18,    84,   238,   239,   142,   143,    53,    10,    11,    53,
      28,   248,    10,    11,    96,    97,    10,    11,    53,    53,
     102,   103,   103,    41,   108,    84,    17,     0,    21,    53,
      84,    53,    10,    11,    81,   114,    20,   274,    22,   121,
     194,    85,    74,    80,   163,    82,    53,    53,     0,    22,
      85,    85,    80,    85,    82,    28,   177,    81,    51,   180,
     144,    83,     0,   184,   185,   186,    81,    53,    20,   305,
      22,    55,   270,   171,    81,    81,    28,    80,   142,   143,
     201,   163,   163,    35,    21,    58,    84,   242,   171,    80,
      84,    82,   215,   216,   217,    81,    53,   170,     0,   183,
     238,   180,    80,    55,    82,    84,    58,    44,   150,    84,
      12,    13,   233,    17,    10,    11,    18,   200,    23,    71,
      72,    17,    23,    75,    81,    23,    28,   246,    53,    52,
     213,    33,    80,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   234,   194,   276,    80,   239,    81,    79,   242,    10,
      11,    53,   114,    53,   246,   246,    17,   245,    70,   142,
     143,    53,    10,    11,   238,    53,    53,    80,   151,    17,
     264,    15,    16,    80,    80,    82,    82,    79,    79,    79,
     142,   143,    10,    11,   276,   273,   315,    79,    17,    18,
      19,    79,    79,   245,   325,   326,    80,    81,    82,    80,
      84,    82,    80,   245,    48,    49,    13,    14,   170,    30,
     318,   305,    26,    27,    28,    29,   258,    33,   180,    80,
     248,   273,    31,   315,   315,   318,   314,    20,   322,   323,
     324,    79,    80,    34,    35,   328,    80,    83,    82,   331,
     331,   222,   223,   224,   225,    24,    25,    52,    53,   161,
     218,   219,   346,   226,   227,   238,    11,    81,   352,   220,
     221,   355,    53,    81,    52,    69,    81,    67,    81,    80,
       3,     4,     5,     6,     7,     8,   238,    10,    11,    81,
      13,    14,    15,    16,    17,    81,   198,   199,    83,    22,
     228,    81,    79,   230,    83,   229,   150,    30,    18,    32,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   231,
      82,   232,    85,    75,    70,   180,   161,    50,    44,   142,
      75,    76,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   252,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    28,    79,    80,    -1,    -1,
      -1,    84,    85,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    -1,    13,    14,    15,    16,    17,    -1,
      50,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,
      80,    50,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    14,    15,    16,    17,    -1,    -1,    23,    -1,    22,
      -1,    80,    -1,    -1,    -1,    84,    85,    30,    -1,    32,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    79,    80,    -1,    -1,
      -1,    84,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,    -1,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    32,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    -1,    -1,    13,    14,    15,    16,    17,    -1,    50,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    32,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,    80,
      50,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    79,
      80,    -1,    -1,    -1,    84,     3,     4,     5,     6,     7,
       8,    -1,    10,    -1,    -1,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,     3,     4,     5,     6,
       7,     8,    30,    10,    32,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    30,    -1,    32,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    13,    14,
      15,    16,    17,    50,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    30,    84,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    80,    10,    50,    83,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    30,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    11,    80,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    50,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    80,    32,    -1,    83,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    75,    76,
      77,    -1,    -1,    80,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    -1,    -1,    13,    14,    15,    16,
      17,    -1,    -1,    80,    81,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      15,    16,    17,    50,    -1,    -1,    -1,    22,    -1,     3,
       4,     5,     6,     7,     8,    30,    10,    32,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    80,    81,    50,    30,    -1,    32,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      75,    76,    -1,    -1,    -1,    80,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    79,    80,    22,    -1,     3,
       4,     5,     6,     7,     8,    30,    10,    32,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    30,    -1,    32,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      13,    14,    15,    16,    17,    -1,    50,    11,    -1,    22,
      -1,    -1,    -1,    -1,    79,    80,    -1,    30,    -1,    32,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    -1,
      -1,    13,    14,    15,    16,    17,    80,    50,    11,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,
      32,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    50,    10,
      11,    75,    76,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    85,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    11,
      -1,    -1,    75,    76,    -1,    17,    -1,    10,    11,    -1,
      -1,    -1,    85,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    11,    -1,    -1,    80,
      81,    82,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    75,    76,    11,    -1,    -1,    80,    81,
      82,    -1,    75,    76,    77,    11,    -1,    80,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    11,    -1,    -1,    -1,    81,    -1,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    75,    76,    77,    80,    89,   111,   112,   113,
     114,   116,   122,   123,   128,   133,   134,   135,   159,   160,
     161,   162,    11,    84,    89,    84,    89,    17,    89,   132,
     133,   138,    79,   115,   116,   118,   120,   132,   133,   117,
     119,   121,   132,    11,   113,   122,    84,   150,   151,   112,
     113,    80,    82,   136,   160,     0,    89,   129,   130,   131,
      84,   122,   124,   125,   126,    84,   138,    81,    80,   133,
      23,   150,    53,    79,    23,    53,    79,     3,     4,     5,
       6,     7,     8,    10,    13,    14,    15,    16,    17,    22,
      30,    32,    50,    64,    65,    66,    68,    69,    70,    71,
      72,    73,    74,    79,    80,    84,    87,    88,    90,    91,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   109,   111,   112,   137,   147,
     148,   149,   151,   153,   154,   155,   156,   157,   158,    81,
     112,   122,   139,   140,   141,    83,    93,   106,   110,    81,
     139,    53,    85,    23,   129,   126,    85,   125,   127,   132,
     124,    84,   107,   145,   120,   145,   121,    80,    93,    93,
      80,    93,   110,    52,    80,    80,    80,   147,    80,    79,
      79,    79,   109,   109,   126,   142,    15,    16,    48,    49,
      80,    82,    23,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   108,    95,    17,    18,    19,    13,    14,
      34,    35,    26,    27,    28,    29,    24,    25,    30,    33,
      31,    20,    21,    51,    53,    79,    85,   152,   153,   154,
     111,   137,   154,   137,   147,    80,    82,   115,   138,   143,
     144,    81,    53,    83,    81,   130,   110,    85,    53,    79,
      85,   145,   146,   142,    52,   147,   109,   109,   109,    69,
     155,    79,    81,    80,   138,   143,    81,    89,    89,    81,
      92,   107,   109,   107,    95,    95,    95,    96,    96,    97,
      97,    98,    98,    98,    98,    99,    99,   100,   101,   102,
     103,   104,   109,   107,   152,   154,   152,   137,    81,   139,
     143,    83,   110,   144,    80,    82,   141,   132,    53,    85,
      81,   147,    81,    81,    81,    80,   155,    95,    53,    81,
      83,    52,   152,    81,    81,    83,    81,   139,    83,   110,
      85,   145,   147,   147,   147,   109,    81,   109,   107,   106,
      81,    83,    67,    81,   147,    81,   147,    79,   147
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    87,    87,    88,    89,    89,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    96,    96,
      96,    96,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   111,   111,   111,   112,   112,   113,
     113,   113,   113,   114,   115,   116,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   123,
     124,   124,   125,   126,   126,   127,   127,   128,   128,   128,
     129,   129,   130,   130,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   134,   135,   135,   135,   136,   137,   138,
     138,   139,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   143,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   145,   146,   146,   147,   147,   147,   147,
     147,   147,   148,   148,   149,   149,   149,   149,   150,   150,
     150,   150,   151,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   156,   157,   157,   157,   157,   158,   158,   158,
     158,   159,   159,   160,   160,   161,   161,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     4,     3,     3,
       2,     2,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     2,
       1,     2,     3,     1,     2,     1,     3,     2,     5,     4,
       1,     3,     1,     3,     1,     1,     2,     1,     3,     3,
       4,     4,     3,     1,     1,     4,     3,     1,     1,     1,
       2,     1,     1,     3,     2,     1,     2,     1,     2,     1,
       2,     1,     3,     4,     3,     3,     2,     4,     3,     3,
       2,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     4,     3,
       3,     2,     1,     1,     1,     2,     1,     2,     2,     1,
       7,     5,     5,     5,     7,     7,     6,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].identnode); }
#line 1851 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1857 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "new string literal" << std::endl;(yyval.expression) = new StringLiteral(*(yyvsp[0].text)); }
#line 1863 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1869 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = new IdentifierNode(*((yyvsp[0].text))); }
#line 1875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = new IdentifierNode(*((yyvsp[0].text))); }
#line 1881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = new IdentifierNode(*((yyvsp[0].text))); }
#line 1887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_int((yyvsp[0].ivalue)); }
#line 1893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_char(*(yyvsp[0].text)); }
#line 1899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArraySubscript((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-2].expression)); }
#line 1935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-3].expression), (yyvsp[-1].argexprlist)); }
#line 1941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new MemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new DerefMemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostInc((yyvsp[-1].expression)); }
#line 1959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostDec((yyvsp[-1].expression)); }
#line 1965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argexprlist) = new ArgExprList((yyvsp[0].expression)); }
#line 1971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].argexprlist))->AppendArgExpression((yyvsp[0].expression)); }
#line 1977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[0].expression); }
#line 1983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreInc((yyvsp[0].expression)); }
#line 1989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreDec((yyvsp[0].expression)); }
#line 1995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = PrefixExpr::DecodeUnaryOp((yyvsp[-1].text),(yyvsp[0].expression)); }
#line 2001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofExpr((yyvsp[0].expression)); }
#line 2007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofType((yyvsp[-1].t_type_name)); }
#line 2013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&");}
#line 2019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*");}
#line 2025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+");}
#line 2031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-");}
#line 2037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("~");}
#line 2043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("!");}
#line 2049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CastExpr((yyvsp[-2].t_type_name), (yyvsp[0].expression)); }
#line 2061 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2067 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Multiply((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2073 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2079 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Modulo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2085 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 230 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 2091 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 231 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Add((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2097 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2103 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2109 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftLeft((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2115 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 236 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftRight((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2121 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2127 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2133 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2139 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2145 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2151 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2157 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new EqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2163 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new NotEqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2169 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2175 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2181 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2187 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseXOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2193 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2199 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2205 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2211 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2217 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2223 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2229 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2235 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new TernaryOpExpression((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2241 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2247 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 269 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = GenericAssignExpr::DecodeAssignOp((yyvsp[-2].expression), (yyvsp[-1].text), (yyvsp[0].expression)); }
#line 2253 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("=");}
#line 2259 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*=");}
#line 2265 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("/=");}
#line 2271 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("%=");}
#line 2277 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 276 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+=");}
#line 2283 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-=");}
#line 2289 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("<<=");}
#line 2295 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string(">>=");}
#line 2301 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&=");}
#line 2307 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("^=");}
#line 2313 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("|=");}
#line 2319 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2325 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CommaSepExpression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2331 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.constexp) = new ConstantExpression((yyvsp[0].expression)); std::cerr << "new constant expression" << std::endl;}
#line 2337 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_init_declarator_list)); }
#line 2343 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 296 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_init_declarator_list)); }
#line 2349 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-1].t_declaration_specifiers)); }
#line 2355 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[0].t_type_specifier));}
#line 2361 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[-1].t_type_specifier), (yyvsp[0].t_declaration_specifiers)); }
#line 2367 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,NULL,(yyvsp[0].t_storage_class_specifier)); std::cerr << "New typedef" << std::endl;}
#line 2373 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,(yyvsp[0].t_declaration_specifiers),(yyvsp[-1].t_storage_class_specifier)); }
#line 2379 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[0].t_type_specifier)); }
#line 2385 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[-1].t_type_specifier), (yyvsp[0].t_declaration_specifiers)); }
#line 2391 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_storage_class_specifier) = new TypedefNode; }
#line 2397 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { insertOtherName(GetIdentName((yyvsp[0].t_declarator))); }
#line 2403 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { insertOtherName(GetIdentName((yyvsp[0].t_declarator)));}
#line 2409 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { insertTypeName(GetIdentName((yyvsp[0].t_declarator))); }
#line 2415 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 316 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator)); }
#line 2421 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator), (yyvsp[-2].t_init_declarator_list)); }
#line 2427 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 319 "src/parser.y" /* yacc.c:1646  */
    {}
#line 2433 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 320 "src/parser.y" /* yacc.c:1646  */
    {}
#line 2439 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 322 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[0].t_declarator)); }
#line 2445 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[-2].t_declarator), (yyvsp[0].t_initializer)); }
#line 2451 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 325 "src/parser.y" /* yacc.c:1646  */
    {}
#line 2457 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 326 "src/parser.y" /* yacc.c:1646  */
    {}
#line 2463 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("void"); }
#line 2469 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("char"); }
#line 2475 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 330 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("short"); }
#line 2481 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("int"); }
#line 2487 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("long"); }
#line 2493 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("float"); }
#line 2499 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 334 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("double"); }
#line 2505 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 335 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("signed"); }
#line 2511 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("unsigned"); }
#line 2517 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = (yyvsp[0].t_type_specifier); }
#line 2523 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier(*(yyvsp[0].text)); }
#line 2529 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 339 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = (yyvsp[0].t_type_specifier); }
#line 2535 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier((yyvsp[-3].identnode), (yyvsp[-1].struct_dection_list)); }
#line 2541 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier(NULL, (yyvsp[-1].struct_dection_list)); }
#line 2547 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier((yyvsp[0].identnode)); }
#line 2553 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection_list) = new struct_declaration_list((yyvsp[0].struct_dection)); }
#line 2559 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 351 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].struct_dection_list)->AppendDeclaration((yyvsp[0].struct_dection)); }
#line 2565 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection) = new struct_declaration((yyvsp[-2].t_specifier_list), (yyvsp[-1].struct_dec_list)); }
#line 2571 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[0].t_type_specifier)); }
#line 2577 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 356 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[-1].t_type_specifier), (yyvsp[0].t_specifier_list)); }
#line 2583 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 358 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dec_list) = new struct_declarator_list((yyvsp[0].t_declarator)); }
#line 2589 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 359 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].struct_dec_list)->AppendDeclarator((yyvsp[0].t_declarator)); }
#line 2595 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[0].identnode)); }
#line 2601 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[-3].identnode), (yyvsp[-1].t_enumlist)); }
#line 2607 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[-1].t_enumlist)); }
#line 2613 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumlist) = new EnumeratorList((yyvsp[0].t_enumerator)); }
#line 2619 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].t_enumlist))->AppendEnumerator((yyvsp[0].t_enumerator));}
#line 2625 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 375 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumerator) = new Enumerator((yyvsp[0].identnode));}
#line 2631 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumerator) = new Enumerator((yyvsp[-2].identnode), (yyvsp[0].constexp));}
#line 2637 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 378 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = (yyvsp[0].identnode); }
#line 2643 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 380 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator)); }
#line 2649 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 381 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator), (yyvsp[-1].t_pointer)); }
#line 2655 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 384 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator((yyvsp[0].identnode));}
#line 2661 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, NULL, NULL,NULL, (yyvsp[-1].t_declarator)); }
#line 2667 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 386 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), new unspecified_array_length()); }
#line 2673 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 387 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), (yyvsp[-1].constexp)); }
#line 2679 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), NULL, (yyvsp[-1].t_parameter_list)); }
#line 2685 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 390 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), NULL, new empty_parameter_list()); }
#line 2691 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 392 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator)); }
#line 2697 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 394 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator((yyvsp[0].identnode));}
#line 2703 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 395 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), NULL, (yyvsp[-1].t_parameter_list)); }
#line 2709 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 396 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), NULL, new empty_parameter_list()); }
#line 2715 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 398 "src/parser.y" /* yacc.c:1646  */
    { NewScope(); }
#line 2721 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 399 "src/parser.y" /* yacc.c:1646  */
    { PopScope(); PopScope(); }
#line 2727 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 401 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer(); }
#line 2733 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer((yyvsp[0].t_pointer)); }
#line 2739 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 404 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = (yyvsp[0].t_parameter_list); }
#line 2745 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 406 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration)); }
#line 2751 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 407 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration), (yyvsp[-2].t_parameter_list)); }
#line 2757 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 409 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), (yyvsp[0].t_declarator)); }
#line 2763 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 410 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[0].t_declaration_specifiers)); }
#line 2769 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 411 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), NULL, (yyvsp[0].t_abstract_declarator)); }
#line 2775 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 418 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[0].t_specifier_list)); }
#line 2781 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 419 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[-1].t_specifier_list), (yyvsp[0].t_abstract_declarator)); }
#line 2787 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 421 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator(NULL, (yyvsp[0].t_pointer)); }
#line 2793 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 422 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator), (yyvsp[-1].t_pointer)); }
#line 2799 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 423 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator)); }
#line 2805 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 425 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, (yyvsp[-1].t_abstract_declarator)); }
#line 2811 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 426 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, (yyvsp[-1].constexp)); }
#line 2817 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 427 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, (yyvsp[-1].constexp)); }
#line 2823 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 428 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, new unspecified_array_length()); }
#line 2829 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 429 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, new unspecified_array_length()); }
#line 2835 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 430 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2841 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 431 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2847 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 432 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, NULL, new empty_parameter_list()); }
#line 2853 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 433 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, new empty_parameter_list()); }
#line 2859 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 438 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer((yyvsp[0].expression)); }
#line 2865 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 439 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-1].t_initializer_list)); }
#line 2871 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 440 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-2].t_initializer_list)); }
#line 2877 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 442 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer)); }
#line 2883 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 443 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer), (yyvsp[-2].t_initializer_list)); }
#line 2889 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 457 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2895 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 458 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2901 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 459 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].cmpstmt); }
#line 2907 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 460 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].exprstmt); }
#line 2913 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 461 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2919 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 462 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2925 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 464 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[-2].constexp), (yyvsp[0].stmt)); }
#line 2931 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 465 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[0].stmt)); }
#line 2937 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 467 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-2].t_declist), (yyvsp[-1].stmtlist)); }
#line 2943 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 468 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].t_declist));}
#line 2949 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 469 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].stmtlist)); /*Will need to use arg overloaded constructor to differentiate between the above*/}
#line 2955 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 470 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement(); }
#line 2961 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 472 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-2].t_declist), (yyvsp[-1].stmtlist)); }
#line 2967 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 473 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].t_declist));}
#line 2973 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 474 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].stmtlist)); /*Will need to use arg overloaded constructor to differentiate between the above*/}
#line 2979 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 475 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement(); }
#line 2985 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 477 "src/parser.y" /* yacc.c:1646  */
    { NewScope(); }
#line 2991 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 479 "src/parser.y" /* yacc.c:1646  */
    { PopScope(); }
#line 2997 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 482 "src/parser.y" /* yacc.c:1646  */
    {(yyval.t_declist) = new DeclarationList((yyvsp[0].t_declaration)); }
#line 3003 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 483 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declist) = new DeclarationList((yyvsp[-1].t_declist), (yyvsp[0].t_declaration)); }
#line 3009 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 485 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StatementList((yyvsp[0].stmt)); }
#line 3015 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 486 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StatementList((yyvsp[-1].stmtlist), (yyvsp[0].stmt)); }
#line 3021 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 488 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new ExpressionStatement((yyvsp[-1].expression)); }
#line 3027 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 489 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new EmptyStatement(); }
#line 3033 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 491 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfElse((yyvsp[-4].expression), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 3039 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 492 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new If((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 3045 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 493 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Switch((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 3051 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 506 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new While((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 3057 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 507 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DoWhile((yyvsp[-5].stmt), (yyvsp[-2].expression)); }
#line 3063 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 508 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-4].exprstmt),(yyvsp[-3].exprstmt),(yyvsp[-2].expression),(yyvsp[0].stmt));}
#line 3069 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 509 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-3].exprstmt),(yyvsp[-2].exprstmt),(yyvsp[0].stmt));}
#line 3075 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 511 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Continue(); }
#line 3081 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 512 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Break(); }
#line 3087 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 513 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return(); }
#line 3093 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 514 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return((yyvsp[-1].expression)); }
#line 3099 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 211:
#line 522 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_translation_unit) = new TranslationUnit((yyvsp[0].t_external_declaration)); }
#line 3105 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 212:
#line 523 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-1].t_translation_unit))->AppendDeclaration((yyvsp[0].t_external_declaration)); }
#line 3111 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 213:
#line 525 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = (yyvsp[0].t_function_definition); }
#line 3117 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 214:
#line 526 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = new ExternalDeclaration((yyvsp[0].t_declaration)); }
#line 3123 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 215:
#line 528 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 3129 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 216:
#line 529 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 3135 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 217:
#line 532 "src/parser.y" /* yacc.c:1646  */
    {g_root = (yyvsp[0].t_translation_unit); }
#line 3141 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 3145 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 534 "src/parser.y" /* yacc.c:1906  */


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

