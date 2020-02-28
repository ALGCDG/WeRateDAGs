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

#line 67 "basic.tab.c" /* yacc.c:339  */

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
   by #include "basic.tab.h".  */
#ifndef YY_YY_BASIC_TAB_H_INCLUDED
# define YY_YY_BASIC_TAB_H_INCLUDED
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

#line 110 "basic.tab.c" /* yacc.c:355  */

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
    Punctuator = 330,
    Punctuator_eol = 331,
    Punctuator_par_open = 332,
    Punctuator_par_close = 333,
    Punctuator_squ_open = 334,
    Punctuator_squ_close = 335,
    Punctuator_cur_open = 336,
    Punctuator_cur_close = 337
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

#line 214 "basic.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BASIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "basic.tab.c" /* yacc.c:358  */

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
#define YYFINAL  126
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  159
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  241

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   337

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
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    48,    50,    52,    55,    56,    57,    58,
      59,    62,    63,    64,    65,    66,    67,    68,    69,    72,
      73,    75,    76,    77,    78,    79,    80,    82,    82,    82,
      82,    82,    82,    84,    84,    84,    84,    84,    84,    84,
      86,    87,    89,    90,    91,    92,    95,    96,    97,    99,
     100,   101,   103,   104,   105,   106,   107,   109,   110,   111,
     115,   116,   118,   119,   121,   122,   124,   125,   127,   128,
     130,   131,   133,   134,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   139,   140,   142,   149,   150,
     152,   153,   159,   160,   162,   163,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   166,   167,   168,   172,   181,
     182,   192,   193,   194,   196,   197,   199,   200,   202,   204,
     205,   207,   208,   209,   210,   211,   212,   213,   215,   216,
     222,   224,   225,   227,   228,   229,   231,   232,   234,   235,
     237,   238,   239,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   252,   254,   255,   256,   258,   259,   261,   262
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
  "Keyword_return", "Keyword_enum", "Keyword_struct", "Punctuator",
  "Punctuator_eol", "Punctuator_par_open", "Punctuator_par_close",
  "Punctuator_squ_open", "Punctuator_squ_close", "Punctuator_cur_open",
  "Punctuator_cur_close", "$accept", "primary_EXPR", "Constant",
  "postfix_EXPR", "argument_EXPR_list", "unary_EXPR", "unary_operator",
  "type_name", "cast_EXPR", "multiplicative_EXPR", "additive_EXPR",
  "shift_EXPR", "relational_EXPR", "equality_EXPR", "BIT_AND_EXPR",
  "BIT_XBIT_OR_EXPR", "BIT_OR_EXPR", "LOGIC_AND_EXPR", "LOGIC_OR_EXPR",
  "conditional_EXPR", "assignment_EXPR", "assignment", "EXPR",
  "constant_EXPR", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "struct_specifier", "specifier_qualifier_list", "enum_specifier",
  "enum_list", "enumerator", "ENUM_CONST", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "abstract_declarator",
  "direct_abstract_declarator", "typedef_name", "initializer",
  "initializer_list", "ROOT", YY_NULLPTR
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
     335,   336,   337
};
# endif

#define YYPACT_NINF -184

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-184)))

#define YYTABLE_NINF -153

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     310,  -184,  -184,  -184,  -184,  -184,  -184,   590,  -184,  -184,
     460,   460,  -184,  -184,  -184,  -184,   490,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,     6,    28,   385,  -184,
    -184,    44,   203,   520,  -184,   180,   108,   122,   138,   137,
      15,    24,    20,    42,    69,  -184,  -184,    21,  -184,    30,
     363,  -184,  -184,  -184,    89,  -184,   520,  -184,  -184,   385,
    -184,    29,    84,  -184,    61,    64,    68,    74,    95,   103,
     133,   142,    -4,   363,    -2,  -184,  -184,   213,   214,   279,
     520,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,   520,  -184,  -184,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,  -184,   215,  -184,    26,    80,
    -184,   207,   -16,     9,  -184,  -184,  -184,   154,    84,  -184,
     -32,  -184,   212,   520,  -184,  -184,   498,   171,    66,  -184,
      71,  -184,  -184,  -184,     3,  -184,    57,  -184,  -184,  -184,
    -184,   180,   180,   108,   108,   122,   122,   122,   122,   138,
     138,   137,    15,    24,    20,    42,   117,  -184,  -184,   156,
      26,  -184,    18,   554,   201,   -16,  -184,    -9,    84,  -184,
     520,  -184,  -184,    25,   157,   196,  -184,   172,  -184,  -184,
     179,    71,   564,   249,   520,  -184,  -184,   520,  -184,  -184,
      18,  -184,  -184,    19,  -184,   187,    31,  -184,   186,  -184,
    -184,  -184,   527,  -184,    -1,  -184,  -184,   363,  -184,  -184,
    -184,   189,  -184,   188,  -184,  -184,  -184,     1,  -184,   261,
    -184,  -184,   148,  -184,  -184,  -184,   121,  -184,  -184,  -184,
    -184
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     7,     8,     9,    10,     4,     2,    29,    30,
       0,     0,    28,    32,    27,    31,     0,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,    11,
       3,    21,    40,     0,    42,    46,    49,    52,    57,    60,
      62,    64,    66,    68,    70,    72,    85,   158,   159,     0,
      90,   105,   106,   107,     0,     2,     0,    22,    23,     0,
      25,   111,     0,   108,    96,    97,    98,    99,   100,   101,
     102,     0,     0,   109,   138,    17,    18,     0,     0,     0,
       0,    74,    78,    79,    75,    76,    77,    82,    84,    83,
      81,    80,     0,    40,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,   128,    89,     0,     0,
      92,    94,   119,     0,   152,    91,     1,     0,     0,   118,
       0,   114,   116,     0,     5,   110,     0,     0,   140,   139,
     142,    15,    16,    13,     0,    19,     0,    73,    43,    44,
      45,    47,    48,    50,    51,    54,    53,    56,    55,    58,
      59,    61,    63,    65,    67,    69,     0,    86,   129,     0,
       0,    88,     0,     0,     0,   120,    26,     0,     0,   113,
       0,    41,   151,   134,     0,   130,   131,     0,   147,    87,
       0,   141,     0,     0,     0,    14,    12,     0,   122,    93,
       0,   153,    95,   152,   127,     0,     0,   123,     0,   112,
     115,   117,     0,   133,   140,   135,   149,     0,   143,   145,
     150,     0,   146,     0,    20,    71,   156,     0,   125,     0,
     126,   124,   152,   132,   148,   144,     0,   154,   137,   155,
     157
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,  -184,  -184,  -184,     0,  -184,   216,   -28,    72,
      92,    85,   111,   163,   164,   162,   165,   168,  -184,   -36,
     -78,  -184,     4,   -27,  -184,    12,  -184,   104,    -8,  -184,
     222,  -184,   161,   118,  -184,  -112,  -116,   -72,   -77,  -184,
      81,  -184,   -71,  -129,  -184,  -183,  -184,  -184
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    29,    30,    31,   144,    93,    33,    71,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    92,    72,   190,    48,   183,   119,   120,    50,    51,
      74,    52,   130,   131,   132,   121,   122,   123,   184,   185,
     186,   206,   187,   140,    53,   202,   227,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   145,   138,   139,    47,    94,   169,   175,   115,   191,
      57,    58,    49,   116,   147,    61,    60,   226,   115,   178,
      73,     1,     2,     3,     4,     5,     6,    55,    32,     8,
       9,    10,    11,    12,   115,   115,   167,    63,    13,   115,
     116,   116,   178,   108,   168,   116,    14,   114,    15,   110,
     179,    73,   236,   240,   194,   109,    32,    75,    76,    32,
     111,   173,   125,   174,   138,    73,    16,   148,   149,   150,
    -136,   213,   114,   209,   134,   136,   212,   137,   137,    32,
      32,   195,   229,   237,   146,   191,   118,    62,   112,   126,
      77,    78,    32,   129,   201,    28,   205,  -136,   175,   200,
     169,   189,   212,   118,   137,   181,   117,   118,   114,   230,
     128,   214,   215,    32,    32,   221,   224,   166,   113,    98,
      99,    79,   201,    80,     1,     2,     3,     4,     5,     6,
      55,   170,     8,     9,    10,    11,    12,   196,   189,   -33,
     214,    13,   -34,   136,   189,   137,   -35,   208,   192,    14,
     193,    15,   -36,   211,   100,   101,   171,   189,   201,   106,
     107,   225,   102,   103,   104,   105,   223,   197,   114,    16,
     151,   152,    32,   -37,     1,     2,     3,     4,     5,     6,
      55,   -38,     8,     9,    10,    11,    12,   155,   156,   157,
     158,    13,   153,   154,    32,    95,    96,    97,    28,    14,
      32,    15,   200,   239,     1,     2,     3,     4,     5,     6,
      55,   -39,     8,     9,    10,    11,    12,   159,   160,    16,
     133,    13,   141,   142,    81,  -121,  -121,  -121,   172,    14,
     116,    15,   176,   180,   198,   216,    32,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   217,    28,    16,
     218,   188,     1,     2,     3,     4,     5,     6,    55,   219,
       8,     9,    10,    11,    12,   228,   231,   234,   235,    13,
     238,   161,   163,   162,   199,   127,   164,    14,    28,    15,
     165,   207,     1,     2,     3,     4,     5,     6,    55,   177,
       8,     9,    10,    11,    12,   135,   210,    16,   233,    13,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       0,     8,     9,    10,    11,    12,    28,    16,     0,   222,
      13,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    28,   143,    16,     0,
       0,     0,     0,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,     0,    28,     1,     2,
       3,     4,     5,     6,     7,     0,     8,     9,    10,    11,
      12,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    15,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    26,    27,    64,    65,
      66,    67,    68,    69,    70,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,    28,     1,     2,     3,     4,     5,     6,    55,
       0,     8,     9,    10,    11,    12,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,     0,     0,     1,     2,     3,     4,     5,     6,    55,
       0,     8,     9,    10,    11,    12,     0,   124,    16,     0,
      13,     0,     0,   116,     0,     0,     0,     0,    14,     0,
      15,     0,     0,     1,     2,     3,     4,     5,     6,    55,
       0,     8,     9,    10,    11,    12,   232,    56,    16,     0,
      13,     0,   116,     0,     0,     0,     0,     0,    14,     0,
      15,    17,    18,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     0,   203,     0,     0,     0,    59,    16,     0,
       0,    26,    27,   124,     0,   136,   182,   137,     0,     0,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,  -152,
      26,    27,     0,     0,   212,   182,   137,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    17,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,     0,
       0,     0,   204,     0,     0,     0,     0,    26,    27,     0,
       0,     0,   220,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -152,  -152,     0,  -152
};

static const yytype_int16 yycheck[] =
{
       0,    79,    74,    74,     0,    33,   118,   123,     9,   138,
      10,    11,     0,    15,    92,     9,    16,   200,     9,    51,
      28,     3,     4,     5,     6,     7,     8,     9,    28,    11,
      12,    13,    14,    15,     9,     9,   114,     9,    20,     9,
      15,    15,    51,    28,   116,    15,    28,    51,    30,    29,
      82,    59,    51,   236,    51,    31,    56,    13,    14,    59,
      18,    77,    50,    79,   136,    73,    48,    95,    96,    97,
      51,   183,    51,    82,    78,    77,    77,    79,    79,    79,
      80,    78,    51,    82,    80,   214,    77,    81,    19,     0,
      46,    47,    92,     9,   172,    77,   173,    78,   214,    81,
     212,   137,    77,    77,    79,   133,    76,    77,    51,    78,
      81,   183,   183,   113,   114,   192,   194,   113,    49,    11,
      12,    77,   200,    79,     3,     4,     5,     6,     7,     8,
       9,    51,    11,    12,    13,    14,    15,    80,   174,    78,
     212,    20,    78,    77,   180,    79,    78,   174,    77,    28,
      79,    30,    78,   180,    32,    33,    76,   193,   236,    22,
      23,   197,    24,    25,    26,    27,   193,    50,    51,    48,
      98,    99,   172,    78,     3,     4,     5,     6,     7,     8,
       9,    78,    11,    12,    13,    14,    15,   102,   103,   104,
     105,    20,   100,   101,   194,    15,    16,    17,    77,    28,
     200,    30,    81,    82,     3,     4,     5,     6,     7,     8,
       9,    78,    11,    12,    13,    14,    15,   106,   107,    48,
      78,    20,     9,     9,    21,    77,    78,    79,    21,    28,
      15,    30,    78,    21,    78,    78,   236,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    51,    77,    48,
      78,    80,     3,     4,     5,     6,     7,     8,     9,    80,
      11,    12,    13,    14,    15,    78,    80,    78,    80,    20,
       9,   108,   110,   109,   170,    59,   111,    28,    77,    30,
     112,    80,     3,     4,     5,     6,     7,     8,     9,   128,
      11,    12,    13,    14,    15,    73,   178,    48,   217,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    77,    48,    -1,    80,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    48,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    -1,    77,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    73,    74,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      -1,    -1,    77,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,     9,    48,    -1,
      20,    -1,    -1,    15,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,     9,    77,    48,    -1,
      20,    -1,    15,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    77,    48,    -1,
      -1,    73,    74,     9,    -1,    77,    78,    79,    -1,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,     9,
      73,    74,    -1,    -1,    77,    78,    79,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    -1,    73,    74,    -1,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    73,    74,    -1,
      -1,    -1,    78,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    12,
      13,    14,    15,    20,    28,    30,    48,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    73,    74,    77,    84,
      85,    86,    88,    89,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   105,   107,   108,
     111,   112,   114,   127,   130,     9,    77,    88,    88,    77,
      88,     9,    81,     9,    53,    54,    55,    56,    57,    58,
      59,    90,   105,   111,   113,    13,    14,    46,    47,    77,
      79,    21,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   104,    88,    91,    15,    16,    17,    11,    12,
      32,    33,    24,    25,    26,    27,    22,    23,    28,    31,
      29,    18,    19,    49,    51,     9,    15,    76,    77,   109,
     110,   118,   119,   120,     9,   108,     0,    90,    81,     9,
     115,   116,   117,    78,    78,   113,    77,    79,   120,   125,
     126,     9,     9,    78,    87,   103,   105,   103,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      95,    96,    97,    98,    99,   100,   105,   103,   120,   118,
      51,    76,    21,    77,    79,   119,    78,   115,    51,    82,
      21,    91,    78,   108,   121,   122,   123,   125,    80,   102,
     106,   126,    77,    79,    51,    78,    80,    50,    78,   110,
      81,   103,   128,     9,    78,   121,   124,    80,   106,    82,
     116,   106,    77,   118,   120,   125,    78,    51,    78,    80,
      78,   121,    80,   106,   103,   102,   128,   129,    78,    51,
      78,    80,     9,   123,    78,    80,    51,    82,     9,    82,
     128
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    84,    84,    84,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    95,    95,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   106,   107,   107,
     108,   108,   109,   109,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   113,
     113,   114,   114,   114,   115,   115,   116,   116,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     121,   122,   122,   123,   123,   123,   124,   124,    90,    90,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   128,   128,   128,   129,   129,   130,   130
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     2,     5,     4,     1,     3,     1,     3,     1,     1,
       2,     1,     3,     3,     4,     4,     4,     3,     1,     2,
       1,     1,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     2,     1,     3,     4,     3,     3,     2,     4,     3,
       3,     2,     1,     1,     3,     4,     1,     3,     1,     1
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
#line 1605 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "basic.y" /* yacc.c:1646  */
    { std::cerr << "CONSTANT" << std::endl; // $$ = new constant($1); 
				 }
#line 1612 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 50 "basic.y" /* yacc.c:1646  */
    { std::cerr << "STRING" << std::endl; // $$ = new string($1); 
				  }
#line 1619 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "basic.y" /* yacc.c:1646  */
    { std::cout << "(x)" << std::endl; }
#line 1625 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 55 "basic.y" /* yacc.c:1646  */
    {}
#line 1631 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "basic.y" /* yacc.c:1646  */
    {}
#line 1637 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "basic.y" /* yacc.c:1646  */
    {}
#line 1643 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 58 "basic.y" /* yacc.c:1646  */
    {}
#line 1649 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 59 "basic.y" /* yacc.c:1646  */
    {}
#line 1655 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 62 "basic.y" /* yacc.c:1646  */
    { std::cerr << "prim" << std::endl; }
#line 1661 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x[y]" << std::endl; }
#line 1667 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x(y)" << std::endl; }
#line 1673 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 65 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x(y,z)" << std::endl; }
#line 1679 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 66 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x.y" << std::endl; }
#line 1685 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 67 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x->y" << std::endl; }
#line 1691 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 68 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x++" << std::endl; }
#line 1697 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 69 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x--" << std::endl; }
#line 1703 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 73 "basic.y" /* yacc.c:1646  */
    { std::cerr << "argument list" << std::endl; }
#line 1709 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 75 "basic.y" /* yacc.c:1646  */
    { std::cerr << "as;dklfj" << std::endl; }
#line 1715 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 76 "basic.y" /* yacc.c:1646  */
    { std::cerr << "++x" << std::endl; }
#line 1721 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 77 "basic.y" /* yacc.c:1646  */
    { std::cerr << "--x" << std::endl; }
#line 1727 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 78 "basic.y" /* yacc.c:1646  */
    { std::cerr << "unary op" << std::endl; }
#line 1733 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 79 "basic.y" /* yacc.c:1646  */
    { std::cerr << "size of" << std::endl; }
#line 1739 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 80 "basic.y" /* yacc.c:1646  */
    { std::cerr << "size of" << std::endl; }
#line 1745 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 87 "basic.y" /* yacc.c:1646  */
    { std::cerr << "(cast) x" << std::endl; }
#line 1751 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 90 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x * cast" << std::endl; }
#line 1757 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 91 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x / cast" << std::endl; }
#line 1763 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 92 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x % cast" << std::endl; }
#line 1769 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 96 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x + y" << std::endl; }
#line 1775 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 97 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x - y" << std::endl; }
#line 1781 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 100 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x << y" << std::endl; }
#line 1787 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 101 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x >> y" << std::endl; }
#line 1793 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 104 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x < y" << std::endl; }
#line 1799 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 105 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x > y" << std::endl; }
#line 1805 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 106 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x <= y" << std::endl; }
#line 1811 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 107 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x >= y" << std::endl; }
#line 1817 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 110 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x == y" << std::endl; }
#line 1823 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 111 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x != y" << std::endl; }
#line 1829 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 116 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x & y" << std::endl; }
#line 1835 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 119 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x ^ y" << std::endl; }
#line 1841 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 122 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x | y" << std::endl; }
#line 1847 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 125 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x || y" << std::endl; }
#line 1853 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 128 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x && y" << std::endl; }
#line 1859 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 131 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x?y:z" << std::endl; }
#line 1865 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 134 "basic.y" /* yacc.c:1646  */
    { std::cerr << "assignment" << std::endl; }
#line 1871 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 140 "basic.y" /* yacc.c:1646  */
    { std::cerr << "x, y" << std::endl; }
#line 1877 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 142 "basic.y" /* yacc.c:1646  */
    { std::cerr << "cond expr" << std::endl; }
#line 1883 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 149 "basic.y" /* yacc.c:1646  */
    { std::cerr << "decspec list ;" << std::endl; }
#line 1889 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 150 "basic.y" /* yacc.c:1646  */
    { std::cerr << "decspec ;" << std::endl; }
#line 1895 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 152 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typspec list" << std::endl; }
#line 1901 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 153 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typspec decspec" << std::endl; }
#line 1907 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 159 "basic.y" /* yacc.c:1646  */
    { std::cerr << "initdec" << std::endl; }
#line 1913 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 160 "basic.y" /* yacc.c:1646  */
    { std::cerr << "initdeclist , initdec " << std::endl; }
#line 1919 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 162 "basic.y" /* yacc.c:1646  */
    { std::cerr << "dec" << std::endl; }
#line 1925 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 163 "basic.y" /* yacc.c:1646  */
    { std::cerr << "dec = init" << std::endl; }
#line 1931 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 166 "basic.y" /* yacc.c:1646  */
    { std::cerr << "struct" << std::endl; }
#line 1937 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 167 "basic.y" /* yacc.c:1646  */
    { std::cerr << "enum" << std::endl; }
#line 1943 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 168 "basic.y" /* yacc.c:1646  */
    { std::cerr << "typedef type" << std::endl; }
#line 1949 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 172 "basic.y" /* yacc.c:1646  */
    { std::cerr << "struct x" << std::endl; }
#line 1955 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 261 "basic.y" /* yacc.c:1646  */
    { std::cerr << "exp" << std::endl; }
#line 1961 "basic.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 262 "basic.y" /* yacc.c:1646  */
    { std::cerr << "Its a declaration" << std::endl; }
#line 1967 "basic.tab.c" /* yacc.c:1646  */
    break;


#line 1971 "basic.tab.c" /* yacc.c:1646  */
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
#line 263 "basic.y" /* yacc.c:1906  */

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
