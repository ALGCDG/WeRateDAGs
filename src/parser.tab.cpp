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
  #include "ast_node.hpp"
  #include "ast_expressions.hpp"
  #include "ast_statements.hpp"
  #include "ast_types.hpp"
  #include "ast_node.hpp"

  #include "altdec.hpp"
 /* extern const Expression *g_root; // A way of getting the AST out
*/
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 117 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 22 "src/parser.y" /* yacc.c:355  */

    std::string *text;
    int ivalue;
    char cvalue;
    double dvalue;
	  float fvalue;
	  long double ldvalue;
    Node* node;
    Expression* expression;
    IdentiferNode* identnode;
    ConstantExpression* constexpr;

#line 226 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   121,   122,   124,   126,   127,   128,
     129,   130,   133,   134,   135,   136,   137,   138,   139,   140,
     143,   144,   146,   147,   148,   149,   150,   151,   153,   154,
     155,   156,   157,   158,   160,   161,   163,   164,   165,   166,
     169,   170,   171,   173,   174,   175,   177,   178,   179,   180,
     181,   183,   184,   185,   189,   190,   192,   193,   195,   196,
     198,   199,   201,   202,   204,   205,   207,   208,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   224,
     225,   227,   234,   235,   237,   238,   239,   240,   242,   244,
     245,   247,   248,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   274,   275,   297,   298,   301,   302,   303,   304,
     305,   306,   307,   309,   310,   312,   314,   315,   317,   318,
     319,   321,   322,   324,   325,   327,   328,   329,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   344,   345,   346,
     348,   349,   363,   364,   365,   366,   367,   368,   370,   371,
     373,   374,   375,   376,   378,   379,   381,   382,   384,   385,
     387,   388,   389,   402,   403,   404,   405,   407,   408,   409,
     410,   418,   419,   421,   422,   424,   425,   426,   427,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Constant_int", "Constant_char",
  "Constant_double", "Constant_float", "Constant_long_double", "String",
  "Identifier", "Operator", "Operator_add", "Operator_sub",
  "Operator_addadd", "Operator_subsub", "Operator_mul", "Operator_div",
  "Operator_mod", "Operator_and", "Operator_or", "Operator_not",
  "Operator_assign", "Operator_equal", "Operator_not_equal",
  "Operator_greater", "Operator_less", "Operator_greater_equal",
  "Operator_less_equal", "Operator_bit_and", "Operator_bit_or",
  "Operator_bit_not", "Operator_bit_xor", "Operator_sl", "Operator_sr",
  "Operator_add_assign", "Operator_sub_assign", "Operator_mul_assign",
  "Operator_div_assign", "Operator_mod_assign", "Operator_and_assign",
  "Operator_or_assign", "Operator_xor_assign", "Operator_sr_assign",
  "Operator_sl_assign", "Operator_ref", "Operator_deref",
  "Operator_access", "Operator_deref_access", "Operator_sizeof",
  "Operator_trinary_question", "Operator_trinary_choice", "Operator_comma",
  "Keyword", "Keyword_void", "Keyword_char", "Keyword_short",
  "Keyword_int", "Keyword_long", "Keyword_float", "Keyword_double",
  "Keyword_signed", "Keyword_unsigned", "Keyword_case", "Keyword_default",
  "Keyword_if", "Keyword_else", "Keyword_switch", "Keyword_while",
  "Keyword_do", "Keyword_for", "Keyword_continue", "Keyword_break",
  "Keyword_return", "Keyword_enum", "Keyword_struct", "Keyword_typedef",
  "Punctuator", "Punctuator_eol", "Punctuator_par_open",
  "Punctuator_par_close", "Punctuator_squ_open", "Punctuator_squ_close",
  "Punctuator_cur_open", "Punctuator_cur_close", "$accept", "primary_EXPR",
  "Ident", "Constant", "postfix_EXPR", "argument_EXPR_list", "unary_EXPR",
  "unary_operator", "cast_EXPR", "multiplicative_EXPR", "additive_EXPR",
  "shift_EXPR", "relational_EXPR", "equality_EXPR", "BIT_AND_EXPR",
  "BIT_XBIT_OR_EXPR", "BIT_OR_EXPR", "LOGIC_AND_EXPR", "LOGIC_OR_EXPR",
  "conditional_EXPR", "assignment_EXPR", "assignment", "EXPR",
  "constant_EXPR", "declaration", "declaration_specifiers",
  "storage_class_specifier", "init_declarator_list", "init_declarator",
  "type_specifier", "specifier_list", "declarator", "direct_declarator",
  "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "EXPR_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "ROOT", YY_NULLPTR
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
     335,   336,   337,   338
};
# endif

#define YYPACT_NINF -133

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-133)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1017,  -133,    39,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    37,  -133,  -133,   989,   857,   857,   149,
      28,     2,  1017,  -133,  -133,    48,  -133,   -22,  -133,   857,
      27,   108,  -133,     4,  -133,  -133,   251,  -133,  -133,   149,
     113,   634,    28,  -133,  -133,  -133,   149,    38,    37,  -133,
     585,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
     922,   922,  -133,  -133,  -133,  -133,   953,   982,    18,    19,
      35,    47,   554,    72,     1,   104,   845,  -133,   786,  -133,
    -133,  -133,  -133,    77,   248,   982,  -133,   148,   105,   190,
     169,   204,    82,   159,   170,   194,    12,  -133,  -133,   109,
    -133,  -133,  -133,   332,   413,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,    23,   150,   187,  -133,   -28,  -133,  -133,
    -133,   162,  -133,  -133,   585,  -133,  -133,   982,  -133,  -133,
     786,  -133,   195,   554,   982,   982,   982,   183,   876,  -133,
    -133,  -133,   136,   -21,   310,    20,   173,  -133,  -133,   261,
     261,   725,   982,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,  -133,   982,  -133,   982,   982,   982,   982,
     982,   982,   982,   982,   982,   982,   982,   982,   982,   982,
     982,   982,   982,   982,   982,   982,  -133,  -133,   444,  -133,
    -133,   960,   665,  -133,     7,  -133,   161,  -133,   857,   261,
    -133,  -133,  -133,   -42,   198,   554,  -133,   -12,    -2,    30,
     200,   876,  -133,  -133,  -133,  1026,   164,  -133,   982,  -133,
    -133,  -133,    32,  -133,    -8,  -133,  -133,  -133,  -133,   148,
     148,   105,   105,   190,   190,   190,   190,   169,   169,   204,
      82,   159,   170,   194,   197,  -133,  -133,  -133,   201,   213,
    -133,   212,   161,  1054,   694,  -133,  -133,   525,  -133,  -133,
    -133,   554,   554,   554,   982,   754,  -133,   982,  -133,  -133,
     982,  -133,  -133,  -133,  -133,   215,  -133,   214,  -133,  -133,
     211,  -133,  -133,    33,   554,    42,  -133,  -133,  -133,  -133,
     554,   219,  -133,   554,  -133,  -133,  -133
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   113,    93,    94,    95,    96,    97,    98,    99,
     100,   101,    88,     0,   106,   174,     0,    84,    86,     0,
     104,     0,   179,   171,   173,     0,   114,     0,    83,     0,
       0,     0,    89,    91,    85,    87,     0,   154,   175,     0,
       0,     0,   105,   172,     1,   107,     0,    91,     0,    82,
       0,   177,     7,     8,     9,    10,    11,     4,    30,    31,
       0,     0,    29,    33,    28,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,     0,   153,
      12,     2,     3,    22,    34,     0,    36,    40,    43,    46,
      51,    54,    56,    58,    60,    62,    64,    66,    79,     0,
     156,   143,   144,     0,     0,   145,   142,   146,   147,   155,
     176,   112,   121,   119,     0,   115,   116,     0,   108,    34,
      81,     0,   178,    90,     0,   137,    92,     0,    23,    24,
       0,    26,     0,     0,     0,     0,     0,     0,     0,   167,
     168,   169,     0,     0,   102,   123,     0,    18,    19,     0,
       0,     0,     0,    68,    72,    73,    69,    70,    71,    76,
      78,    77,    75,    74,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   158,   151,     0,   152,
     157,     0,     0,   118,   125,   120,   127,   110,     0,     0,
     111,   109,   140,     0,     0,     0,   149,     0,     0,     0,
       0,     0,   170,     5,   103,     0,   125,   124,     0,    16,
      17,    14,     0,    20,     0,    67,    37,    38,    39,    41,
      42,    44,    45,    48,    47,    50,    49,    52,    53,    55,
      57,    59,    61,    63,     0,    80,   150,   136,     0,     0,
     132,     0,   126,     0,     0,   117,   122,     0,   138,    27,
     148,     0,     0,     0,     0,     0,    35,     0,    15,    13,
       0,   134,   128,   130,   135,     0,   131,     0,   139,   141,
     161,   162,   163,     0,     0,     0,    21,    65,   133,   129,
       0,     0,   166,     0,   160,   164,   165
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,    34,  -133,  -133,  -133,   -40,  -133,   -72,    98,
     101,    61,    97,   118,   120,   117,   119,   133,  -133,   -38,
      -6,  -133,   -64,   -43,    53,     0,  -133,  -133,   254,   -68,
     180,   -11,   -17,     6,   -33,  -133,   127,  -133,   202,   -80,
     -41,  -109,  -133,   -44,  -133,   143,    78,   224,  -132,  -133,
    -133,  -133,  -133,   281,  -133,  -133
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    81,    82,    83,   222,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,   164,    99,   121,    37,    30,    17,    31,    32,    18,
     145,    19,    20,    21,   248,   115,   116,   117,   146,   249,
     196,   126,   203,   100,   101,   102,    39,   104,   105,   106,
     107,   108,    22,    23,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      16,   119,    27,   120,    42,    33,   211,   114,    26,   257,
     144,     1,   142,   165,   143,   202,     1,    34,    35,    47,
     128,   129,    16,   199,   132,    50,   131,   119,   137,   120,
     185,   183,     1,   195,    14,     2,     1,    47,     2,   185,
     113,   258,     2,   185,   125,   119,     1,    14,    44,   185,
      14,   200,     2,    15,     2,    14,    14,    45,   213,    50,
     190,   184,   144,   143,    14,   217,   143,   261,   133,    29,
     207,   208,   209,   269,   112,    15,   144,   262,   139,   265,
      13,   185,    14,   267,   185,   191,    36,   192,   224,   206,
     147,   148,   109,   185,   226,   227,   228,   134,   215,   109,
     192,   191,   193,   192,    28,    13,    40,    46,    41,   263,
     179,   268,   291,   135,   103,    13,   169,   170,   125,   194,
     244,   293,     1,   149,   150,   136,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   190,   223,   266,    14,   279,   251,
     138,   216,   119,   252,   120,   151,   109,   152,   225,    48,
     185,   260,    38,   166,   167,   168,     3,     4,     5,     6,
       7,     8,     9,    10,    11,   252,    51,    42,   119,   245,
      27,   140,   110,   219,   220,    49,   186,   185,    12,   122,
     180,   113,   111,   173,   174,   175,   176,   194,   113,   181,
     283,   285,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   277,   182,   212,   119,   113,   120,   280,   281,   282,
     275,   216,   171,   172,    12,    14,   177,   178,    14,   197,
     119,    36,   287,   256,   233,   234,   235,   236,   198,   253,
     292,   254,   215,   201,   192,   205,   294,   270,   185,   296,
     210,   125,   218,   113,    52,    53,    54,    55,    56,    57,
       1,   286,    58,    59,    60,    61,    62,   229,   230,   153,
       1,    63,   231,   232,   237,   238,   290,   259,   264,    64,
     271,    65,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   272,   273,   288,   289,   295,   239,   241,    66,
     240,   242,   123,    43,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    67,    68,    69,   243,    70,    71,    72,
      73,    74,    75,    76,   214,   255,    12,   188,    77,    78,
       0,     0,   204,    36,    79,    52,    53,    54,    55,    56,
      57,     1,     0,    58,    59,    60,    61,    62,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,     0,     0,    12,     0,    77,
      78,     0,     0,     0,    36,   187,    52,    53,    54,    55,
      56,    57,     1,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    65,     0,     0,     0,    52,    53,    54,
      55,    56,    57,     1,     0,    58,    59,    60,    61,    62,
       0,    66,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    65,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
      77,    78,    66,     0,     0,    36,   189,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,    77,    78,     0,     0,     0,    36,   246,    52,    53,
      54,    55,    56,    57,     1,     0,    58,    59,    60,    61,
      62,     0,     0,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,    52,    53,    54,
      55,    56,    57,     1,     0,    58,    59,    60,    61,    62,
       0,     0,     0,    66,    63,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    52,    53,
      54,    55,    56,    57,     1,     0,    58,    59,    60,    61,
      62,     0,    66,    78,     0,    63,     0,   124,   278,     0,
       0,     0,     0,    64,     0,    65,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,    77,    78,    66,     0,     0,    36,    52,    53,    54,
      55,    56,    57,     1,     0,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    64,    78,    65,     0,     0,   124,    52,    53,
      54,    55,    56,    57,     1,     0,    58,    59,    60,    61,
      62,     0,    66,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,    52,    53,    54,
      55,    56,    57,     1,     0,    58,    59,    60,    61,    62,
       0,     0,    78,    66,    63,   118,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    52,    53,
      54,    55,    56,    57,     1,     0,    58,    59,    60,    61,
      62,     0,    66,    78,     0,    63,   250,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,    52,    53,    54,
      55,    56,    57,     1,     0,    58,    59,    60,    61,    62,
       0,     0,    78,    66,    63,   276,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,     0,    52,
      53,    54,    55,    56,    57,     1,     0,    58,    59,    60,
      61,    62,    66,    78,   221,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   284,    66,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    52,    53,
      54,    55,    56,    57,     1,     0,    58,    59,    60,    61,
      62,     0,     0,     0,    78,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,     0,     0,    52,
      53,    54,    55,    56,    57,     1,     0,    58,    59,    60,
      61,    62,     0,    66,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,   141,    78,    66,    52,    53,    54,    55,    56,
      57,     1,    12,    58,    59,    60,    61,    62,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,    77,    78,     0,    52,    53,    54,    55,
      56,    57,     1,     0,    58,    59,    60,    61,    62,     1,
      66,     0,     0,    63,     0,     2,     0,     0,     0,     0,
       0,    64,     0,    65,     0,    52,    53,    54,    55,    56,
      57,     1,     0,    58,    59,    60,    61,    62,     1,     0,
     127,    66,    63,     0,     2,     0,     0,     0,     0,     0,
      64,     0,    65,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,     1,     0,     0,     0,
      66,   130,     2,     0,     0,    12,     0,     0,   191,   247,
     192,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,    12,     0,    28,    13,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,     0,    12,     0,     0,    13,     0,     0,     0,     0,
       0,    12,     0,     0,   215,   247,   192,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,   274
};

static const yytype_int16 yycheck[] =
{
       0,    41,    13,    41,    21,    16,   138,    40,     2,    51,
      78,     9,    76,    85,    78,   124,     9,    17,    18,    30,
      60,    61,    22,    51,    67,    21,    66,    67,    72,    67,
      51,    19,     9,   113,     0,    15,     9,    48,    15,    51,
      40,    83,    15,    51,    50,    85,     9,    13,     0,    51,
      16,    79,    15,     0,    15,    21,    22,    79,    79,    21,
     104,    49,   130,   127,    30,   145,   130,    79,    50,    16,
     134,   135,   136,    81,    40,    22,   144,    79,    77,   211,
      78,    51,    48,    51,    51,    78,    82,    80,   152,   133,
      13,    14,    39,    51,   166,   167,   168,    78,    78,    46,
      80,    78,   113,    80,    77,    78,    78,    29,    80,    79,
      28,    79,    79,    78,    36,    78,    11,    12,   124,   113,
     184,    79,     9,    46,    47,    78,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   188,   151,   218,   113,   257,   192,
      78,   145,   192,   194,   192,    78,   103,    80,   164,    51,
      51,   205,    19,    15,    16,    17,    53,    54,    55,    56,
      57,    58,    59,    60,    61,   216,    33,   194,   218,   185,
     191,    77,    39,   149,   150,    77,    77,    51,    75,    46,
      31,   191,    79,    24,    25,    26,    27,   191,   198,    29,
     264,   265,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   254,    18,    77,   254,   215,   254,   261,   262,   263,
     253,   215,    32,    33,    75,   191,    22,    23,   194,    79,
     270,    82,   270,   199,   173,   174,   175,   176,    51,    78,
     284,    80,    78,    81,    80,    50,   290,    50,    51,   293,
      67,   257,    79,   253,     3,     4,     5,     6,     7,     8,
       9,   267,    11,    12,    13,    14,    15,   169,   170,    21,
       9,    20,   171,   172,   177,   178,    65,    79,    78,    28,
      79,    30,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    79,    81,    79,    81,    77,   179,   181,    48,
     180,   182,    48,    22,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   183,    66,    67,    68,
      69,    70,    71,    72,   144,   198,    75,   103,    77,    78,
      -1,    -1,   130,    82,    83,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    75,    -1,    77,
      78,    -1,    -1,    -1,    82,    83,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    48,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    48,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,    -1,    82,    83,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    48,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    48,    78,    -1,    20,    -1,    82,    83,    -1,
      -1,    -1,    -1,    28,    -1,    30,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    77,    78,    48,    -1,    -1,    82,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    78,    30,    -1,    -1,    82,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    48,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    78,    48,    20,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    48,    78,    -1,    20,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    78,    48,    20,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    48,    78,    79,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    48,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    78,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    48,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    77,    78,    48,     3,     4,     5,     6,     7,
       8,     9,    75,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    77,    78,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,     9,
      48,    -1,    -1,    20,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,     9,    -1,
      78,    48,    20,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      48,    78,    15,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    15,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    75,    -1,    77,    78,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    15,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    75,    78,    86,   108,   109,   110,   113,   115,
     116,   117,   136,   137,   138,   139,   117,   115,    77,   108,
     109,   111,   112,   115,   109,   109,    82,   108,   129,   130,
      78,    80,   116,   137,     0,    79,   130,   115,    51,    77,
      21,   129,     3,     4,     5,     6,     7,     8,    11,    12,
      13,    14,    15,    20,    28,    30,    48,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    77,    78,    83,
      85,    86,    87,    88,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   106,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   108,
     129,    79,    86,   109,   118,   119,   120,   121,    81,    90,
     103,   107,   129,   112,    82,   104,   125,    78,    90,    90,
      78,    90,   107,    50,    78,    78,    78,   127,    78,    77,
      77,    77,   106,   106,   113,   114,   122,    13,    14,    46,
      47,    78,    80,    21,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   105,    92,    15,    16,    17,    11,
      12,    32,    33,    24,    25,    26,    27,    22,    23,    28,
      31,    29,    18,    19,    49,    51,    77,    83,   131,    83,
     127,    78,    80,   115,   117,   123,   124,    79,    51,    51,
      79,    81,   125,   126,   122,    50,   127,   106,   106,   106,
      67,   132,    77,    79,   114,    78,   117,   123,    79,    86,
      86,    79,    89,   104,   106,   104,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    95,    95,    96,    96,    97,
      98,    99,   100,   101,   106,   104,    83,    79,   118,   123,
      81,   107,   124,    78,    80,   120,    86,    51,    83,    79,
     127,    79,    79,    79,    78,   132,    92,    51,    79,    81,
      50,    79,    79,    81,    79,   118,    81,   107,    83,   125,
     127,   127,   127,   106,    79,   106,   104,   103,    79,    81,
      65,    79,   127,    79,   127,    77,   127
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    86,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      96,    97,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   107,   108,   108,   109,   109,   109,   109,   110,   111,
     111,   112,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   114,   114,   115,   115,   116,   116,   116,   116,
     116,   116,   116,   117,   117,   118,   119,   119,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   125,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   133,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   137,   137,   138,   138,   138,   138,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       1,     3,     1,     2,     2,     2,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     1,     2,     1,     2,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     3,     3,     4,
       4,     4,     3,     1,     2,     1,     1,     3,     2,     1,
       2,     1,     3,     1,     2,     1,     2,     1,     3,     4,
       3,     3,     2,     4,     3,     3,     2,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     3,     2,     1,     2,     1,     2,     2,     1,
       7,     5,     5,     5,     7,     7,     6,     2,     2,     2,
       3,     1,     2,     1,     1,     2,     3,     3,     4,     1
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
#line 119 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new IdentiferNode; }
#line 1736 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 120 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "CONSTANT" << std::endl; }
#line 1742 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 121 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "STRING" << std::endl; }
#line 1748 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 122 "src/parser.y" /* yacc.c:1646  */
    { std::cout << "(x)" << std::endl; }
#line 1754 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = new IdentiferNode((yyvsp[0].text)); }
#line 1760 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 126 "src/parser.y" /* yacc.c:1646  */
    {}
#line 1766 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 127 "src/parser.y" /* yacc.c:1646  */
    {}
#line 1772 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 128 "src/parser.y" /* yacc.c:1646  */
    {}
#line 1778 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "src/parser.y" /* yacc.c:1646  */
    {}
#line 1784 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "src/parser.y" /* yacc.c:1646  */
    {}
#line 1790 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 133 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1796 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 134 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArraySubscript((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1802 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 135 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-2].expression)); }
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 137 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new MemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 138 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new DerefMemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1826 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostInc((yyvsp[-1].expression)); }
#line 1832 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 140 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostDec((yyvsp[-1].expression)); }
#line 1838 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 143 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArgExprList((yyvsp[0].expression)); }
#line 1844 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 144 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].expression))->AppendArgExpression((yyvsp[0].expression)); }
#line 1850 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 146 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[0].expression); }
#line 1856 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 147 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreInc((yyvsp[0].expression)); }
#line 1862 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 148 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreDec((yyvsp[0].expression)); }
#line 1868 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 149 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = PrefixExpr::DecodeUnaryOp((yyvsp[0].expression)); }
#line 1874 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 150 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofExpr((yyvsp[0].expression)); }
#line 1880 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 151 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofType((yyvsp[-1].node)); }
#line 1886 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("&");}
#line 1892 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("*");}
#line 1898 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("+");}
#line 1904 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 156 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("-");}
#line 1910 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("~");}
#line 1916 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("!");}
#line 1922 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 160 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1928 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CastExpr((yyvsp[-2].node), (yyvsp[0].expression)); }
#line 1934 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1940 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 164 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Multiply((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1946 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 165 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1952 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Modulo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1958 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 1964 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Add((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1970 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1976 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1982 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 174 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftLeft((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1988 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftRight((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1994 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2000 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2006 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2012 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2018 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2024 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new EqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2030 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new NotEqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2036 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2042 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2048 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 192 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2054 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseXOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2060 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2066 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2072 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2078 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2084 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2090 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2096 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2102 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new TernaryOpExpression((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2108 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2114 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = GenericAssignExpr::DecodeAssignOp((yyvsp[-2].expression), (yyvsp[-1].expression), (yyvsp[0].expression)); }
#line 2120 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("=");}
#line 2126 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("*=");}
#line 2132 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("/=");}
#line 2138 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("%=");}
#line 2144 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("+=");}
#line 2150 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("-=");}
#line 2156 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("<<=");}
#line 2162 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string(">>=");}
#line 2168 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("&=");}
#line 2174 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("^=");}
#line 2180 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new string("|=");}
#line 2186 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2192 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CommaSepExpression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2198 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { ConstantExpression((yyvsp[0].expression)); }
#line 2204 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2210 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration((yyvsp[-1].node)); }
#line 2216 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 237 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "stor" << std::endl; }
#line 2222 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 238 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "stor decspec" << std::endl; }
#line 2228 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration_specifiers((yyvsp[0].node)); }
#line 2234 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declaration_specifiers((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2240 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "typedef" << std::endl; }
#line 2246 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new init_declaration_list((yyvsp[0].node)); }
#line 2252 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new init_declaration_list((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2258 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new init_declarator((yyvsp[0].node)); }
#line 2264 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new init_declarator((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2270 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2276 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2282 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2288 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2294 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2300 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2306 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2312 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2318 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_specifier((yyvsp[0].text)); }
#line 2324 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "tysp" << std::endl; }
#line 2330 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "tysp spli" << std::endl; }
#line 2336 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declarator((yyvsp[0].node)); }
#line 2342 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new declarator((yyvsp[0].node), (yyvsp[-1].node)); }
#line 2348 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_declarator((yyvsp[0].identnode)); }
#line 2354 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_declarator(NULL, NULL, NULL, (yyvsp[-1].node)); }
#line 2360 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_declarator(NULL, (yyvsp[-2].node), new unspecified_array_length()); }
#line 2366 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_declarator(NULL, (yyvsp[-3].node), (yyvsp[-1].constexpr)); }
#line 2372 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_declarator(NULL, (yyvsp[-3].node), NULL, (yyvsp[-1].node)); }
#line 2378 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "still not sure what this does" << std::endl; }
#line 2384 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "still not sure what this does" << std::endl; }
#line 2390 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 309 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new pointer(); }
#line 2396 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new pointer((yyvsp[0].node)); }
#line 2402 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new parameter_list((yyvsp[0].node)); }
#line 2408 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 315 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new parameter_list((yyvsp[-2].node), (yyvsp[0].node)) }
#line 2414 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 317 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new parameter_declaration((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2420 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new parameter_declaration((yyvsp[0].node)); }
#line 2426 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new parameter_declaration((yyvsp[-1].node), NULL, (yyvsp[0].node)); }
#line 2432 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_name((yyvsp[0].node)); }
#line 2438 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 325 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new type_name((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2444 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new abstract_declarator(NULL, (yyvsp[0].node)); }
#line 2450 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 328 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new abstract_declarator((yyvsp[0].node), (yyvsp[-1].node)); }
#line 2456 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 329 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new abstract_declarator((yyvsp[0].node)); }
#line 2462 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 331 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator(NULL, (yyvsp[-1].node)); }
#line 2468 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator((yyvsp[-3].node), NULL, (yyvsp[-1].constexpr)); }
#line 2474 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator(NULL, NULL, (yyvsp[-1].constexpr)); }
#line 2480 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 334 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator((yyvsp[-2].node), NULL, new unspecified_array_length()); }
#line 2486 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 335 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator(NULL, NULL, new unspecified_array_length()); }
#line 2492 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator((yyvsp[-3].node), NULL, NULL, (yyvsp[-1].node)); }
#line 2498 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator(NULL, NULL, NULL, (yyvsp[-1].node)); }
#line 2504 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator((yyvsp[-2].node), NULL, NULL, new empty_parameter_list()); }
#line 2510 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 339 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new direct_abstract_declarator(NULL, NULL, NULL, new empty_parameter_list()); }
#line 2516 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new initializer((yyvsp[0].expression)); }
#line 2522 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new initializer(NULL, (yyvsp[-1].node)); }
#line 2528 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new initializer(NULL, (yyvsp[-2].node)); }
#line 2534 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 348 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new initializer_list((yyvsp[0].node)); }
#line 2540 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 349 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new initializer_list((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2546 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 363 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2552 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2558 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2564 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ExpressionStatement((yyvsp[0].node)); }
#line 2570 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 367 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2576 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2582 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CaseOrDefault((yyvsp[-2].constexpr), (yyvsp[0].node)); }
#line 2588 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 371 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CaseOrDefault((yyvsp[0].node)); }
#line 2594 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CompoundStatement((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 2600 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 374 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CompoundStatement((yyvsp[-1].node));}
#line 2606 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 375 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new CompoundStatement((yyvsp[-1].node)); /*Will need to use arg overloaded constructor to differentiate between the above*/}
#line 2612 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EmptyStatement; }
#line 2618 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 381 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StatementList((yyvsp[0].node)); }
#line 2624 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 382 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new StatementList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2630 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 384 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new ExpressionStatement((yyvsp[-1].expression)); }
#line 2636 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new EmptyStatement(); }
#line 2642 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 387 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new IfElse((yyvsp[-4].expression), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2648 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new If((yyvsp[-2].expression), (yyvsp[0].node)); }
#line 2654 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 389 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Switch((yyvsp[-2].expression), (yyvsp[0].node)); }
#line 2660 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new While((yyvsp[-2].expression), (yyvsp[0].node)); }
#line 2666 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 403 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new DoWhile((yyvsp[-5].node), (yyvsp[-2].expression)); }
#line 2672 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 404 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new For((yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].expression),(yyvsp[0].node));}
#line 2678 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 405 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new For((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2684 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 407 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Continue(); }
#line 2690 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 408 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Break(); }
#line 2696 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 409 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Return(); }
#line 2702 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 410 "src/parser.y" /* yacc.c:1646  */
    { (yyval.node) = new Return((yyvsp[-1].expression)); }
#line 2708 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 430 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "Its a valid program" << std::endl; }
#line 2714 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2718 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 432 "src/parser.y" /* yacc.c:1906  */

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
