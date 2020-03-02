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

#line 67 "basic.tab.cpp" /* yacc.c:339  */

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
   by #include "basic.tab.hpp".  */
#ifndef YY_YY_BASIC_TAB_HPP_INCLUDED
# define YY_YY_BASIC_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "basic.y" /* yacc.c:355  */


  #include<iostream>
  #include<string>
 /* extern const Expression *g_root; // A way of getting the AST out
*/
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 110 "basic.tab.cpp" /* yacc.c:355  */

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
#line 15 "basic.y" /* yacc.c:355  */

    std::string *text;
    int ivalue;
    char cvalue;
    double dvalue;
	float fvalue;
	long double ldvalue;

#line 215 "basic.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BASIC_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 232 "basic.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1108

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

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
       0,    46,    46,    48,    50,    52,    55,    56,    57,    58,
      59,    62,    63,    64,    65,    66,    67,    68,    69,    72,
      73,    75,    76,    77,    78,    79,    80,    82,    82,    82,
      82,    82,    82,    84,    85,    87,    88,    89,    90,    93,
      94,    95,    97,    98,    99,   101,   102,   103,   104,   105,
     107,   108,   109,   113,   114,   116,   117,   119,   120,   122,
     123,   125,   126,   128,   129,   131,   132,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   137,   138,
     140,   147,   148,   150,   151,   152,   153,   155,   157,   158,
     160,   161,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   179,   180,   202,   203,   206,   207,   208,   209,   210,
     211,   212,   214,   215,   217,   219,   220,   222,   223,   224,
     226,   227,   229,   230,   232,   233,   234,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   249,   250,   251,   253,
     254,   268,   269,   270,   271,   272,   273,   275,   276,   278,
     279,   280,   281,   283,   284,   286,   287,   289,   290,   292,
     293,   294,   307,   308,   309,   310,   312,   313,   314,   315,
     323,   324,   326,   327,   329,   330,   331,   332,   335
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
  "Constant", "postfix_EXPR", "argument_EXPR_list", "unary_EXPR",
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

#define YYPACT_NINF -149

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-149)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     987,  -149,    51,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,    26,  -149,    17,  1033,  1033,   827,    21,
      27,   987,  -149,  -149,    54,  -149,     4,  -149,  1033,    25,
      49,  -149,    28,  -149,  -149,   250,  -149,  -149,   827,   959,
     604,    21,  -149,  -149,  -149,   827,    94,    26,  -149,   555,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
     892,   892,  -149,  -149,  -149,  -149,   923,   952,    -8,    73,
      80,    84,   524,   117,    72,   123,   815,  -149,   756,  -149,
    -149,  -149,    39,   247,   952,  -149,   187,   195,   191,   186,
     206,   155,   199,   197,   229,    19,  -149,  -149,   131,  -149,
    -149,  -149,   331,   412,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,     9,   170,   209,  -149,   -31,  -149,  -149,  -149,
     169,  -149,  -149,   555,  -149,  -149,   952,  -149,  -149,   756,
    -149,   216,   524,   952,   952,   952,   200,   846,  -149,  -149,
    -149,   145,    42,   309,    29,   192,  -149,  -149,   260,   263,
     695,   952,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,   952,  -149,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   952,   952,   952,   952,   952,   952,
     952,   952,   952,   952,   952,  -149,  -149,   443,  -149,  -149,
     930,   635,  -149,    10,  -149,    38,  -149,  1033,   264,  -149,
    -149,  -149,   -14,   196,   524,  -149,    71,   101,   105,   198,
     846,  -149,  -149,  -149,   996,    81,  -149,   952,  -149,  -149,
    -149,   106,  -149,    31,  -149,  -149,  -149,  -149,   187,   187,
     195,   195,   191,   191,   191,   191,   186,   186,   206,   155,
     199,   197,   229,   190,  -149,  -149,  -149,   212,   213,  -149,
     193,    38,  1024,   664,  -149,  -149,   161,  -149,  -149,  -149,
     524,   524,   524,   952,   724,  -149,   952,  -149,  -149,   952,
    -149,  -149,  -149,  -149,   214,  -149,   215,  -149,  -149,   230,
    -149,  -149,   109,   524,   120,  -149,  -149,  -149,  -149,   524,
     202,  -149,   524,  -149,  -149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   105,   112,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    87,     0,   173,     0,    83,    85,     0,   103,
       0,   178,   170,   172,     0,   113,     0,    82,     0,     0,
       0,    88,    90,    84,    86,     0,   153,   174,     0,     0,
       0,   104,   171,     1,   106,     0,    90,     0,    81,     0,
     176,     6,     7,     8,     9,    10,     4,     2,    29,    30,
       0,     0,    28,    32,    27,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,   152,
      11,     3,    21,    33,     0,    35,    39,    42,    45,    50,
      53,    55,    57,    59,    61,    63,    65,    78,     0,   155,
     142,   143,     0,     0,   144,   141,   145,   146,   154,   175,
     120,   111,   118,     0,   114,   115,     0,   107,    33,    80,
       0,   177,    89,     0,   136,    91,     0,    22,    23,     0,
      25,     0,     0,     0,     0,     0,     0,     0,   166,   167,
     168,     0,     0,   101,   122,     0,    17,    18,     0,     0,
       0,     0,    67,    71,    72,    68,    69,    70,    75,    77,
      76,    74,    73,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   150,     0,   151,   156,
       0,     0,   117,   124,   119,   126,   109,     0,     0,   110,
     108,   139,     0,     0,     0,   148,     0,     0,     0,     0,
       0,   169,     5,   102,     0,   124,   123,     0,    15,    16,
      13,     0,    19,     0,    66,    36,    37,    38,    40,    41,
      43,    44,    47,    46,    49,    48,    51,    52,    54,    56,
      58,    60,    62,     0,    79,   149,   135,     0,     0,   131,
       0,   125,     0,     0,   116,   121,     0,   137,    26,   147,
       0,     0,     0,     0,     0,    34,     0,    14,    12,     0,
     133,   127,   129,   134,     0,   130,     0,   138,   140,   160,
     161,   162,     0,     0,     0,    20,    64,   132,   128,     0,
       0,   165,     0,   159,   163,   164
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -149,  -149,  -149,   -38,  -149,   -69,  -108,    67,
      61,    69,    99,   115,   119,   116,   118,  -149,   -37,   -39,
    -149,   -70,   -66,    12,     0,  -149,  -149,   254,   -23,   159,
      -4,   -16,    11,   -34,  -149,   126,  -149,   201,   -65,  -148,
    -109,  -149,   -41,  -149,   160,    23,   222,  -130,  -149,  -149,
    -149,  -149,   294,  -149,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    80,    81,    82,   221,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     163,    98,   120,    36,    29,    16,    30,    31,    17,   144,
      18,    19,    20,   247,   114,   115,   116,   145,   248,   195,
     125,   202,    99,   100,   101,    38,   103,   104,   105,   106,
     107,    21,    22,    23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      15,   131,   118,   119,    41,   113,   141,   210,   142,    26,
     124,    32,    14,    25,   201,   164,    33,    34,     1,     1,
     198,    15,   127,   128,     2,    46,     1,    28,   130,   118,
     119,   136,     2,    14,     1,     1,     1,   256,   182,   112,
       2,     2,   132,    46,     2,   251,   118,   194,   199,    49,
     108,    45,   146,   147,    43,   143,   142,   108,   102,   142,
     228,   229,   189,   206,   207,   208,     2,   251,   183,   257,
       3,     4,     5,     6,     7,     8,     9,    10,    11,   216,
     264,   223,   184,    44,   124,   148,   149,   190,   190,   191,
     191,   205,    12,   184,    27,    13,   225,   226,   227,    39,
      47,    40,    27,    13,    13,    13,   143,   214,   192,   191,
      35,   222,   268,   243,   108,    49,   252,   150,   253,   151,
     143,   212,   184,   193,   224,   250,    48,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   244,   189,   278,   265,   138,
     260,   133,   184,   118,   119,   215,   184,   266,   134,   214,
     184,   191,   135,   259,    51,    52,    53,    54,    55,    56,
      57,   184,    58,    59,    60,    61,    62,    41,    37,   118,
     261,    63,   184,   178,   262,   267,    26,   276,   290,    64,
     112,    65,    50,   282,   284,   137,   184,   112,   109,   292,
     139,   193,   165,   166,   167,   121,   168,   169,   185,    66,
     172,   173,   174,   175,   112,   118,   119,   124,   274,   279,
     280,   281,   211,   170,   171,   215,   180,   285,   176,   177,
     179,   118,   286,   232,   233,   234,   235,   230,   231,    78,
     269,   184,   291,   123,   277,   236,   237,   181,   293,   196,
     200,   295,   112,    51,    52,    53,    54,    55,    56,    57,
     197,    58,    59,    60,    61,    62,   204,   209,   152,   218,
      63,   217,   219,   255,   272,   258,   263,   238,    64,   294,
      65,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   270,   271,   287,   239,   289,   288,   241,    66,   240,
     242,   122,   213,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    67,    68,    69,    42,    70,    71,    72,    73,
      74,    75,    76,   254,   187,    12,     0,    77,    78,     0,
     203,     0,    35,    79,    51,    52,    53,    54,    55,    56,
      57,     0,    58,    59,    60,    61,    62,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,    64,
       0,    65,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    67,    68,    69,     0,    70,    71,    72,
      73,    74,    75,    76,     0,     0,    12,     0,    77,    78,
       0,     0,     0,    35,   186,    51,    52,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,     0,
      66,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,    64,     0,    65,    67,    68,    69,     0,    70,    71,
      72,    73,    74,    75,    76,     0,     0,     0,     0,    77,
      78,    66,     0,     0,    35,   188,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    68,    69,     0,    70,
      71,    72,    73,    74,    75,    76,     0,     0,     0,     0,
      77,    78,     0,     0,     0,    35,   245,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,     0,    66,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,    67,    68,    69,     0,
      70,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,    77,    78,    66,     0,     0,    35,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
       0,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    64,    78,    65,     0,     0,   123,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,     0,    66,     0,     0,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
       0,     0,    78,    66,    63,   117,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,     0,    66,    78,     0,    63,   249,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,    51,    52,    53,
      54,    55,    56,    57,     0,    58,    59,    60,    61,    62,
       0,     0,    78,    66,    63,   275,     0,     0,     0,     0,
       0,     0,    64,     0,    65,     0,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,    66,    78,   220,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,   283,    66,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    51,    52,
      53,    54,    55,    56,    57,     0,    58,    59,    60,    61,
      62,     0,     0,     0,    78,    63,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    65,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,    58,    59,    60,
      61,    62,     0,    66,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    64,     0,    65,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,     0,   140,    78,    66,    51,    52,    53,    54,    55,
      56,    57,    12,    58,    59,    60,    61,    62,     0,    35,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,    77,    78,     0,    51,    52,    53,    54,
      55,    56,    57,     0,    58,    59,    60,    61,    62,     1,
      66,     0,     0,    63,     0,     2,     0,     0,     0,     0,
       0,    64,     0,    65,     0,    51,    52,    53,    54,    55,
      56,    57,     0,    58,    59,    60,    61,    62,   110,     0,
     126,    66,    63,     0,     0,     0,     0,     0,     0,     0,
      64,     0,    65,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     0,     0,     1,     0,     0,     0,
      66,   129,     2,     0,     0,    12,     0,     0,   190,   246,
     191,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,     0,    12,     0,     0,     0,   111,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,     0,    12,     0,     0,    13,     0,     0,     0,     0,
       0,    12,     0,     0,   214,   246,   191,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,     0,    12,
       0,     0,     0,   273,     0,     0,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
       0,    67,    40,    40,    20,    39,    76,   137,    78,    13,
      49,    15,     0,     2,   123,    84,    16,    17,     9,     9,
      51,    21,    60,    61,    15,    29,     9,    15,    66,    67,
      67,    72,    15,    21,     9,     9,     9,    51,    19,    39,
      15,    15,    50,    47,    15,   193,    84,   112,    79,    21,
      38,    28,    13,    14,     0,    78,   126,    45,    35,   129,
     168,   169,   103,   133,   134,   135,    15,   215,    49,    83,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   144,
     210,   151,    51,    79,   123,    46,    47,    78,    78,    80,
      80,   132,    75,    51,    77,    78,   165,   166,   167,    78,
      51,    80,    77,    78,    78,    78,   129,    78,   112,    80,
      82,   150,    81,   183,   102,    21,    78,    78,    80,    80,
     143,    79,    51,   112,   163,   191,    77,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   184,   187,   256,   217,    77,
      79,    78,    51,   191,   191,   144,    51,    51,    78,    78,
      51,    80,    78,   204,     3,     4,     5,     6,     7,     8,
       9,    51,    11,    12,    13,    14,    15,   193,    18,   217,
      79,    20,    51,    28,    79,    79,   190,   253,    79,    28,
     190,    30,    32,   263,   264,    78,    51,   197,    38,    79,
      77,   190,    15,    16,    17,    45,    11,    12,    77,    48,
      24,    25,    26,    27,   214,   253,   253,   256,   252,   260,
     261,   262,    77,    32,    33,   214,    29,   266,    22,    23,
      31,   269,   269,   172,   173,   174,   175,   170,   171,    78,
      50,    51,   283,    82,    83,   176,   177,    18,   289,    79,
      81,   292,   252,     3,     4,     5,     6,     7,     8,     9,
      51,    11,    12,    13,    14,    15,    50,    67,    21,     9,
      20,    79,     9,     9,    81,    79,    78,   178,    28,    77,
      30,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    79,    79,    79,   179,    65,    81,   181,    48,   180,
     182,    47,   143,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    21,    66,    67,    68,    69,
      70,    71,    72,   197,   102,    75,    -1,    77,    78,    -1,
     129,    -1,    82,    83,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    67,    68,
      69,    70,    71,    72,    -1,    -1,    75,    -1,    77,    78,
      -1,    -1,    -1,    82,    83,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    -1,
      48,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    62,    63,    64,    -1,    66,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    77,
      78,    48,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    82,    83,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    48,    -1,    -1,    20,    -1,    -1,    -1,    -1,
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
       8,     9,    75,    11,    12,    13,    14,    15,    -1,    82,
      -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    77,    78,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,     9,
      48,    -1,    -1,    20,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,     9,    -1,
      78,    48,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      48,    78,    15,    -1,    -1,    75,    -1,    -1,    78,    79,
      80,    15,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    79,    80,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    15,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    75,    78,   107,   108,   109,   112,   114,   115,
     116,   135,   136,   137,   138,   116,   114,    77,   107,   108,
     110,   111,   114,   108,   108,    82,   107,   128,   129,    78,
      80,   115,   136,     0,    79,   129,   114,    51,    77,    21,
     128,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    20,    28,    30,    48,    62,    63,    64,
      66,    67,    68,    69,    70,    71,    72,    77,    78,    83,
      85,    86,    87,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   105,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   107,   128,
       9,    79,   108,   117,   118,   119,   120,    81,    89,   102,
     106,   128,   111,    82,   103,   124,    78,    89,    89,    78,
      89,   106,    50,    78,    78,    78,   126,    78,    77,    77,
      77,   105,   105,   112,   113,   121,    13,    14,    46,    47,
      78,    80,    21,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   104,    91,    15,    16,    17,    11,    12,
      32,    33,    24,    25,    26,    27,    22,    23,    28,    31,
      29,    18,    19,    49,    51,    77,    83,   130,    83,   126,
      78,    80,   114,   116,   122,   123,    79,    51,    51,    79,
      81,   124,   125,   121,    50,   126,   105,   105,   105,    67,
     131,    77,    79,   113,    78,   116,   122,    79,     9,     9,
      79,    88,   103,   105,   103,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    95,    95,    96,    97,
      98,    99,   100,   105,   103,    83,    79,   117,   122,    81,
     106,   123,    78,    80,   119,     9,    51,    83,    79,   126,
      79,    79,    79,    78,   131,    91,    51,    79,    81,    50,
      79,    79,    81,    79,   117,    81,   106,    83,   124,   126,
     126,   126,   105,    79,   105,   103,   102,    79,    81,    65,
      79,   126,    79,   126,    77,   126
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    92,    92,    93,
      93,    93,    94,    94,    94,    95,    95,    95,    95,    95,
      96,    96,    96,    97,    97,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   105,   105,
     106,   107,   107,   108,   108,   108,   108,   109,   110,   110,
     111,   111,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   118,   118,   119,   119,   119,
     120,   120,   121,   121,   122,   122,   122,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   131,   132,
     132,   132,   133,   133,   133,   133,   134,   134,   134,   134,
     135,   135,   136,   136,   137,   137,   137,   137,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     2,     1,     2,     1,     2,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     3,     3,     4,     4,
       4,     3,     1,     2,     1,     1,     3,     2,     1,     2,
       1,     3,     1,     2,     1,     2,     1,     3,     4,     3,
       3,     2,     4,     3,     3,     2,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     1,     2,     1,     2,     2,     1,     7,
       5,     5,     5,     7,     7,     6,     2,     2,     2,     3,
       1,     2,     1,     1,     2,     3,     3,     4,     1
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
#line 46 "basic.y" /* yacc.c:1646  */
    { std::cerr << "IDENTIFIER" << std::endl; // $$ = new identifier($1); 
}
#line 1720 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "basic.y" /* yacc.c:1646  */
    { std::cerr << "CONSTANT" << std::endl; // $$ = new constant($1); 
				 }
#line 1727 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "basic.y" /* yacc.c:1646  */
    { std::cerr << "STRING" << std::endl; // $$ = new string($1); 
				  }
#line 1734 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "basic.y" /* yacc.c:1646  */
    { std::cout << "(x)" << std::endl; }
#line 1740 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "basic.y" /* yacc.c:1646  */
    {}
#line 1746 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "basic.y" /* yacc.c:1646  */
    {}
#line 1752 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "basic.y" /* yacc.c:1646  */
    {}
#line 1758 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 58 "basic.y" /* yacc.c:1646  */
    {}
#line 1764 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 59 "basic.y" /* yacc.c:1646  */
    {}
#line 1770 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "basic.y" /* yacc.c:1646  */
    { std::cerr << "prim" << std::endl; }
#line 1776 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x[y]" << std::endl; }
#line 1782 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x(y)" << std::endl; }
#line 1788 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 65 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x(y,z)" << std::endl; }
#line 1794 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 66 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x.y" << std::endl; }
#line 1800 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 67 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x->y" << std::endl; }
#line 1806 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x++" << std::endl; }
#line 1812 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 69 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x--" << std::endl; }
#line 1818 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "basic.y" /* yacc.c:1646  */
    { std::cerr << "argument list" << std::endl; }
#line 1824 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "basic.y" /* yacc.c:1646  */
    { std::cerr << "as;dklfj" << std::endl; }
#line 1830 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 76 "basic.y" /* yacc.c:1646  */
    { std::cerr << "++x" << std::endl; }
#line 1836 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 77 "basic.y" /* yacc.c:1646  */
    { std::cerr << "--x" << std::endl; }
#line 1842 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "basic.y" /* yacc.c:1646  */
    { std::cerr << "unary op" << std::endl; }
#line 1848 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "basic.y" /* yacc.c:1646  */
    { std::cerr << "size of" << std::endl; }
#line 1854 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 80 "basic.y" /* yacc.c:1646  */
    { std::cerr << "size of" << std::endl; }
#line 1860 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 85 "basic.y" /* yacc.c:1646  */
    { std::cerr << "(cast) x" << std::endl; }
#line 1866 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 88 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x * cast" << std::endl; }
#line 1872 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 89 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x / cast" << std::endl; }
#line 1878 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 90 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x % cast" << std::endl; }
#line 1884 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x + y" << std::endl; }
#line 1890 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 95 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x - y" << std::endl; }
#line 1896 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 98 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x << y" << std::endl; }
#line 1902 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 99 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x >> y" << std::endl; }
#line 1908 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 102 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x < y" << std::endl; }
#line 1914 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 103 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x > y" << std::endl; }
#line 1920 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 104 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x <= y" << std::endl; }
#line 1926 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 105 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x >= y" << std::endl; }
#line 1932 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 108 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x == y" << std::endl; }
#line 1938 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 109 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x != y" << std::endl; }
#line 1944 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 114 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x & y" << std::endl; }
#line 1950 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 117 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x ^ y" << std::endl; }
#line 1956 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 120 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x | y" << std::endl; }
#line 1962 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 123 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x || y" << std::endl; }
#line 1968 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 126 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x && y" << std::endl; }
#line 1974 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 129 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x?y:z" << std::endl; }
#line 1980 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 132 "basic.y" /* yacc.c:1646  */
    { std::cerr << "assignment" << std::endl; }
#line 1986 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 138 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x, y" << std::endl; }
#line 1992 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 140 "basic.y" /* yacc.c:1646  */
    { std::cerr << "cond expr" << std::endl; }
#line 1998 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 147 "basic.y" /* yacc.c:1646  */
    { std::cerr << "decspec list ;" << std::endl; }
#line 2004 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 148 "basic.y" /* yacc.c:1646  */
    { std::cerr << "decspec ;" << std::endl; }
#line 2010 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 150 "basic.y" /* yacc.c:1646  */
    { std::cerr << "stor" << std::endl; }
#line 2016 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 151 "basic.y" /* yacc.c:1646  */
    { std::cerr << "stor decspec" << std::endl; }
#line 2022 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 152 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typspec list" << std::endl; }
#line 2028 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 153 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typspec decspec" << std::endl; }
#line 2034 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 155 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typedef" << std::endl; }
#line 2040 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 157 "basic.y" /* yacc.c:1646  */
    { std::cerr << "initdec" << std::endl; }
#line 2046 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 158 "basic.y" /* yacc.c:1646  */
    { std::cerr << "initdeclist , initdec " << std::endl; }
#line 2052 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 160 "basic.y" /* yacc.c:1646  */
    { std::cerr << "dec" << std::endl; }
#line 2058 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 161 "basic.y" /* yacc.c:1646  */
    { std::cerr << "dec = init" << std::endl; }
#line 2064 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 179 "basic.y" /* yacc.c:1646  */
    { std::cerr << "tysp" << std::endl; }
#line 2070 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 180 "basic.y" /* yacc.c:1646  */
    { std::cerr << "tysp spli" << std::endl; }
#line 2076 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 202 "basic.y" /* yacc.c:1646  */
    { std::cerr << "direct dec" << std::endl; }
#line 2082 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 203 "basic.y" /* yacc.c:1646  */
    { std::cerr << "point direct dec" << std::endl; }
#line 2088 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 214 "basic.y" /* yacc.c:1646  */
    { std::cerr << "dumb pointer" << std::endl; }
#line 2094 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 215 "basic.y" /* yacc.c:1646  */
    { std::cerr << "pointer" << std::endl; }
#line 2100 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 219 "basic.y" /* yacc.c:1646  */
    { std::cerr << "a parameter" << std::endl; }
#line 2106 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 220 "basic.y" /* yacc.c:1646  */
    { std::cerr << "multiple parameters" << std::endl; }
#line 2112 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 222 "basic.y" /* yacc.c:1646  */
    { std::cerr << "param dec" << std::endl; }
#line 2118 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 223 "basic.y" /* yacc.c:1646  */
    { std::cerr << "no param name" << std::endl; }
#line 2124 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 224 "basic.y" /* yacc.c:1646  */
    { std::cerr << "pass by reference" << std::endl; }
#line 2130 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 249 "basic.y" /* yacc.c:1646  */
    { std::cerr << "assigning an initialiser" << std::endl; }
#line 2136 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 250 "basic.y" /* yacc.c:1646  */
    { std::cerr << "{init}" << std::endl; }
#line 2142 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 251 "basic.y" /* yacc.c:1646  */
    { std::cerr << "{init,}" << std::endl; }
#line 2148 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 253 "basic.y" /* yacc.c:1646  */
    { std::cerr << "iniz" << std::endl; }
#line 2154 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 254 "basic.y" /* yacc.c:1646  */
    { std::cerr << "iniz, iniz" << std::endl; }
#line 2160 "basic.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 335 "basic.y" /* yacc.c:1646  */
    { std::cerr << "Its a valid program" << std::endl; }
#line 2166 "basic.tab.cpp" /* yacc.c:1646  */
    break;


#line 2170 "basic.tab.cpp" /* yacc.c:1646  */
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
#line 337 "basic.y" /* yacc.c:1906  */

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
