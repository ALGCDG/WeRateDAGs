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
  #include "./ast_allnodes.hpp"

  extern TranslationUnit *g_root; // A way of getting the AST out
  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 111 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 16 "src/parser.y" /* yacc.c:355  */

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

#line 254 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   1156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  303

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
       0,   152,   152,   153,   154,   155,   157,   159,   160,   161,
     162,   163,   166,   167,   168,   169,   170,   171,   172,   173,
     176,   177,   179,   180,   181,   182,   183,   184,   186,   187,
     188,   189,   190,   191,   193,   194,   196,   197,   198,   199,
     202,   203,   204,   206,   207,   208,   210,   211,   212,   213,
     214,   216,   217,   218,   222,   223,   225,   226,   228,   229,
     231,   232,   234,   235,   237,   238,   240,   241,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   257,
     258,   260,   267,   268,   270,   271,   272,   273,   275,   277,
     278,   280,   281,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   294,   296,   298,   300,   302,   303,   305,   307,
     308,   310,   311,   332,   333,   336,   337,   338,   339,   340,
     342,   344,   345,   347,   349,   350,   352,   353,   354,   361,
     362,   364,   365,   366,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   381,   382,   383,   385,   386,   400,   401,
     402,   403,   404,   405,   407,   408,   410,   411,   412,   413,
     415,   416,   418,   419,   421,   422,   424,   425,   426,   439,
     440,   441,   442,   444,   445,   446,   447,   455,   456,   458,
     459,   461,   462,   466
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
  "type_specifier", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "specifier_list", "struct_declarator_list",
  "declarator", "direct_declarator", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name",
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

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1008,  -136,    20,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,     3,  -136,    39,  -136,  -136,    41,  1081,  1081,
    -136,    18,    -3,    23,  1008,  -136,  -136,   130,  -136,   312,
      25,    76,  -136,   -25,  -136,    -6,  -136,  -136,   253,  -136,
    1045,   636,    -3,  -136,  -136,   312,   120,  -136,    39,   312,
    -136,    39,  -136,   587,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   941,   941,  -136,  -136,  -136,  -136,   972,
    1001,   134,   122,   127,   133,   556,   149,   112,   121,   864,
    -136,   788,  -136,  -136,  -136,  -136,   150,   250,  1001,  -136,
     154,    -2,    35,    98,   144,   201,   203,   208,   220,     8,
    -136,  -136,   -18,  -136,    41,  -136,  -136,  -136,   334,   415,
    -136,  -136,  -136,  -136,  -136,    34,   160,   189,  -136,  -136,
    -136,  -136,   161,  -136,  -136,  -136,   190,  -136,   800,  -136,
     222,   587,  -136,  -136,  1001,  -136,  -136,   788,  -136,   195,
     556,  1001,  1001,  1001,   181,   895,  -136,  -136,  -136,     4,
     -17,    30,   170,  -136,  -136,   241,   241,   727,  1001,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    1001,  -136,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,
    1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,  1001,
    1001,  1001,  -136,  -136,  -136,   446,  -136,  -136,   979,   667,
    -136,    31,  -136,   107,  -136,  1081,  -136,    39,  -136,  -136,
     -32,   172,   556,  -136,    -7,    42,    75,   176,   895,  -136,
    -136,  1036,   126,  -136,  1001,  -136,  -136,  -136,   109,  -136,
      10,  -136,  -136,  -136,  -136,   154,   154,    -2,    -2,    35,
      35,    35,    35,    98,    98,   144,   201,   203,   208,   220,
     141,  -136,  -136,  -136,   184,   191,  -136,   188,   107,  1072,
     696,  -136,  -136,   527,  -136,  -136,  -136,   556,   556,   556,
    1001,   756,  -136,  1001,  -136,  -136,  1001,  -136,  -136,  -136,
    -136,   193,  -136,   194,  -136,  -136,   209,  -136,  -136,   111,
     556,   114,  -136,  -136,  -136,  -136,   556,   199,  -136,   556,
    -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   121,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     0,    88,     0,   115,   180,     0,    84,    86,
     102,     0,   113,     0,   183,   177,   179,     0,   122,     0,
     105,     0,    83,     0,    89,    91,    85,    87,     0,   181,
       0,     0,   114,   178,     1,   109,     0,   106,     0,     0,
     116,     0,    82,     0,   182,     7,     8,     9,    10,    11,
       4,    30,    31,     0,     0,    29,    33,    28,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,   159,    12,     2,     3,    22,    34,     0,    36,
      40,    43,    46,    51,    54,    56,    58,    60,    62,    64,
      66,    79,     0,   160,     0,   162,   149,   150,     0,     0,
     151,   148,   152,   153,   120,   127,     0,   123,   124,   117,
      34,    81,     0,   110,   104,   107,   108,   111,     0,    90,
      91,     0,   143,    92,     0,    23,    24,     0,    26,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,     0,
       0,   129,     0,    18,    19,     0,     0,     0,     0,    68,
      72,    73,    69,    70,    71,    76,    78,    77,    75,    74,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   157,   161,     0,   158,   163,     0,     0,
     126,   131,   128,   133,   119,     0,   118,     0,   103,   146,
       0,     0,     0,   155,     0,     0,     0,     0,     0,   176,
       5,     0,   131,   130,     0,    16,    17,    14,     0,    20,
       0,    67,    37,    38,    39,    41,    42,    44,    45,    48,
      47,    50,    49,    52,    53,    55,    57,    59,    61,    63,
       0,    80,   156,   142,     0,     0,   138,     0,   132,     0,
       0,   125,   112,     0,   144,    27,   154,     0,     0,     0,
       0,     0,    35,     0,    15,    13,     0,   140,   134,   136,
     141,     0,   137,     0,   145,   147,   167,   168,   169,     0,
       0,     0,    21,    65,   139,   135,     0,     0,   172,     0,
     166,   170,   171
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,    46,  -136,  -136,  -136,   -41,  -136,   -68,    37,
      32,    36,    49,    92,    93,    91,    94,   105,  -136,   -40,
     -42,  -136,   -63,   -46,   -24,    64,  -136,  -136,   229,    -8,
    -136,   246,   -38,   -39,  -136,   -12,   -19,     1,   -33,  -136,
      95,   159,   -98,  -135,  -106,  -136,   -44,  -136,    78,  -136,
     196,  -132,  -136,  -136,  -136,  -136,   273,  -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    83,    84,    85,    86,   228,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   170,   102,   122,    16,   115,    18,    33,    34,    19,
      20,    46,    47,    48,   126,    21,    22,    23,   254,   117,
     118,   152,   255,   203,   133,   210,   105,   106,   107,   108,
     109,   110,   111,   112,   113,    24,    25,    26,    27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     120,   121,    31,    28,    42,    35,   123,   116,   125,   175,
     176,   132,     1,   218,   103,    53,   149,   202,   150,   263,
     171,    45,   135,   136,   139,   209,    51,   189,   138,   120,
     121,   144,     1,   191,   191,     2,   127,    45,    45,   130,
       1,    45,   151,     1,   191,     2,    15,   120,     1,     2,
       1,   264,    52,   223,     2,   191,     2,   190,    30,   192,
      15,   191,   220,    15,    17,   197,   258,   177,   178,    15,
      15,   150,   267,    45,   150,    40,    38,    41,   214,   215,
     216,   219,    36,    37,   194,    29,   271,   258,    17,   132,
     125,   275,   130,   191,    15,   230,   213,    15,   151,    39,
      38,    14,   104,   200,   232,   233,   234,    49,   221,   198,
     199,   199,   198,    54,   199,   229,   201,    14,    32,    14,
      45,   268,   179,   180,   181,   182,   191,   250,   231,    45,
      44,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   251,
      15,   197,   222,   257,   269,    50,   272,   285,   120,   121,
     273,    15,   191,   153,   154,   191,   183,   184,   266,   172,
     173,   174,   104,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    42,   120,   140,   259,    31,   260,   274,   146,
     297,   276,   191,   299,    12,   262,   155,   156,   147,   201,
     141,   225,   226,   124,   221,   142,   199,   289,   291,   237,
     238,   143,   235,   236,   283,   239,   240,   241,   242,   120,
     121,   132,   222,   286,   287,   288,   281,   145,   157,   185,
     158,   292,   243,   244,   186,   120,   293,   187,   188,   204,
     205,   207,   206,    53,    15,   212,   298,    15,   217,   224,
       1,   265,   300,    15,   270,   302,    55,    56,    57,    58,
      59,    60,     1,   277,    61,    62,    63,    64,    65,   279,
     278,   159,   294,    66,   296,   295,   301,   245,   247,   246,
     129,    67,   248,    68,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   249,   128,   211,    43,     0,     0,
     261,    69,     0,     0,   195,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    70,    71,    72,     0,    73,
      74,    75,    76,    77,    78,    79,     0,    12,    13,     0,
      80,    81,     0,     0,     0,    38,    82,    55,    56,    57,
      58,    59,    60,     1,     0,    61,    62,    63,    64,    65,
       0,     0,     0,     0,    66,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    68,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,    12,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    70,    71,    72,     0,
      73,    74,    75,    76,    77,    78,    79,     0,    12,    13,
       0,    80,    81,     0,     0,     0,    38,   193,    55,    56,
      57,    58,    59,    60,     1,     0,    61,    62,    63,    64,
      65,     0,     0,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    68,     0,     0,     0,    55,
      56,    57,    58,    59,    60,     1,     0,    61,    62,    63,
      64,    65,     0,    69,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,    67,     0,    68,    70,    71,    72,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,    80,    81,    69,     0,     0,    38,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
      72,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,    80,    81,     0,     0,     0,    38,   252,
      55,    56,    57,    58,    59,    60,     1,     0,    61,    62,
      63,    64,    65,     0,     0,     0,     0,    66,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    68,     0,    55,
      56,    57,    58,    59,    60,     1,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    69,    66,     0,     0,     0,
       0,     0,     0,     0,    67,     0,    68,     0,     0,     0,
      55,    56,    57,    58,    59,    60,     1,     0,    61,    62,
      63,    64,    65,     0,    69,    81,     0,    66,     0,   131,
     284,     0,     0,     0,     0,    67,     0,    68,    70,    71,
      72,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,    80,    81,    69,     0,     0,    38,    55,
      56,    57,    58,    59,    60,     1,     0,    61,    62,    63,
      64,    65,     0,     0,     0,     0,    66,     0,     0,     0,
       0,     0,     0,     0,    67,    81,    68,     0,     0,   131,
      55,    56,    57,    58,    59,    60,     1,     0,    61,    62,
      63,    64,    65,     0,    69,     0,     0,    66,     0,     0,
       0,     0,     0,     0,     0,    67,     0,    68,     0,    55,
      56,    57,    58,    59,    60,     1,     0,    61,    62,    63,
      64,    65,     0,     0,    81,    69,    66,   119,     0,     0,
       0,     0,     0,     0,    67,     0,    68,     0,     0,     0,
      55,    56,    57,    58,    59,    60,     1,     0,    61,    62,
      63,    64,    65,     0,    69,    81,     0,    66,   256,     0,
       0,     0,     0,     0,     0,    67,     0,    68,     0,    55,
      56,    57,    58,    59,    60,     1,     0,    61,    62,    63,
      64,    65,     0,     0,    81,    69,    66,   282,     0,     0,
       0,     0,     0,     0,    67,     0,    68,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,     1,     0,    61,
      62,    63,    64,    65,    69,    81,   227,     0,    66,     0,
       0,     0,     0,     0,     0,     0,    67,     0,    68,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    81,   290,    69,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,    81,    55,    56,    57,
      58,    59,    60,     1,    12,    61,    62,    63,    64,    65,
       0,     0,     0,   208,    66,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    68,     0,     0,     0,    55,    56,
      57,    58,    59,    60,     1,     0,    61,    62,    63,    64,
      65,     0,    69,     0,     0,    66,     0,     0,     0,     0,
       0,     0,     0,    67,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,    81,    69,    55,    56,    57,    58,    59,    60,
       1,     0,    61,    62,    63,    64,    65,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,    67,
       0,    68,    80,    81,     0,    55,    56,    57,    58,    59,
      60,     1,     0,    61,    62,    63,    64,    65,     1,    69,
       0,     0,    66,     0,     2,     0,     0,     0,     0,     0,
      67,     0,    68,     0,    55,    56,    57,    58,    59,    60,
       1,     0,    61,    62,    63,    64,    65,     1,     0,   134,
      69,    66,     0,     2,     0,     0,     0,     0,     0,    67,
       0,    68,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    69,
     137,     2,     0,    12,    13,     0,     0,   198,   253,   199,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    12,    13,     0,     0,    14,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,     0,     0,
      12,    13,     0,     0,   221,   253,   199,     0,     0,    12,
      13,     0,     0,     0,   114,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,     0,    12,    13,     0,     0,
       0,   280,     0,     0,     0,    12,    13
};

static const yytype_int16 yycheck[] =
{
      41,    41,    14,     2,    23,    17,    45,    40,    46,    11,
      12,    53,     9,   145,    38,    21,    79,   115,    81,    51,
      88,    29,    63,    64,    70,   131,    51,    19,    69,    70,
      70,    75,     9,    51,    51,    15,    48,    45,    46,    51,
       9,    49,    81,     9,    51,    15,     0,    88,     9,    15,
       9,    83,    77,   151,    15,    51,    15,    49,    12,    77,
      14,    51,    79,    17,     0,   109,   201,    32,    33,    23,
      24,   134,    79,    81,   137,    78,    82,    80,   141,   142,
     143,    77,    18,    19,   108,    82,   218,   222,    24,   131,
     128,    81,   104,    51,    48,   158,   140,    51,   137,    21,
      82,    78,    38,   115,   172,   173,   174,    82,    78,    78,
      80,    80,    78,    35,    80,   157,   115,    78,    77,    78,
     128,    79,    24,    25,    26,    27,    51,   190,   170,   137,
       0,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   191,
     104,   195,   151,   199,    79,    79,   224,   263,   199,   199,
      51,   115,    51,    13,    14,    51,    22,    23,   212,    15,
      16,    17,   108,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   201,   224,    50,    78,   198,    80,    79,    77,
      79,    50,    51,    79,    74,   207,    46,    47,    77,   198,
      78,   155,   156,    83,    78,    78,    80,   270,   271,   177,
     178,    78,   175,   176,   260,   179,   180,   181,   182,   260,
     260,   263,   221,   267,   268,   269,   259,    78,    78,    28,
      80,   273,   183,   184,    31,   276,   276,    29,    18,    79,
      51,    51,    81,    21,   198,    50,   290,   201,    67,    79,
       9,    79,   296,   207,    78,   299,     3,     4,     5,     6,
       7,     8,     9,    79,    11,    12,    13,    14,    15,    81,
      79,    21,    79,    20,    65,    81,    77,   185,   187,   186,
      51,    28,   188,    30,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   189,    49,   137,    24,    -1,    -1,
     205,    48,    -1,    -1,   108,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    72,    -1,    74,    75,    -1,
      77,    78,    -1,    -1,    -1,    82,    83,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    74,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      66,    67,    68,    69,    70,    71,    72,    -1,    74,    75,
      -1,    77,    78,    -1,    -1,    -1,    82,    83,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    48,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    62,    63,    64,
      -1,    66,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    77,    78,    48,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    82,    83,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    48,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    48,    78,    -1,    20,    -1,    82,
      83,    -1,    -1,    -1,    -1,    28,    -1,    30,    62,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    77,    78,    48,    -1,    -1,    82,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    78,    30,    -1,    -1,    82,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    48,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    -1,    78,    48,    20,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,    48,    78,    -1,    20,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    -1,    -1,    78,    48,    20,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    48,    78,    79,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    48,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    74,    -1,    -1,    -1,    78,     3,     4,     5,
       6,     7,     8,     9,    74,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    83,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    48,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    48,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    77,    78,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,     9,    48,
      -1,    -1,    20,    -1,    15,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,     9,    -1,    78,
      48,    20,    -1,    15,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      78,    15,    -1,    74,    75,    -1,    -1,    78,    79,    80,
      -1,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    -1,    74,    75,    -1,    -1,    78,    -1,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      74,    75,    -1,    -1,    78,    79,    80,    -1,    -1,    74,
      75,    -1,    -1,    -1,    79,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    79,    -1,    -1,    -1,    74,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    15,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    74,    75,    78,    86,   108,   109,   110,   113,
     114,   119,   120,   121,   139,   140,   141,   142,   121,    82,
      86,   119,    77,   111,   112,   119,   109,   109,    82,   132,
      78,    80,   120,   140,     0,   113,   115,   116,   117,    82,
      79,    51,    77,    21,   132,     3,     4,     5,     6,     7,
       8,    11,    12,    13,    14,    15,    20,    28,    30,    48,
      62,    63,    64,    66,    67,    68,    69,    70,    71,    72,
      77,    78,    83,    85,    86,    87,    88,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   106,   108,   109,   130,   131,   132,   133,   134,
     135,   136,   137,   138,    79,   109,   122,   123,   124,    81,
      90,   103,   107,   117,    83,   116,   118,   119,   115,   112,
     119,    82,   104,   128,    78,    90,    90,    78,    90,   107,
      50,    78,    78,    78,   130,    78,    77,    77,    77,   106,
     106,   117,   125,    13,    14,    46,    47,    78,    80,    21,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     105,    92,    15,    16,    17,    11,    12,    32,    33,    24,
      25,    26,    27,    22,    23,    28,    31,    29,    18,    19,
      49,    51,    77,    83,   108,   134,    83,   130,    78,    80,
     119,   121,   126,   127,    79,    51,    81,    51,    83,   128,
     129,   125,    50,   130,   106,   106,   106,    67,   135,    77,
      79,    78,   121,   126,    79,    86,    86,    79,    89,   104,
     106,   104,    92,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    99,   100,   101,
     106,   104,    83,    79,   122,   126,    81,   107,   127,    78,
      80,   124,   119,    51,    83,    79,   130,    79,    79,    79,
      78,   135,    92,    51,    79,    81,    50,    79,    79,    81,
      79,   122,    81,   107,    83,   128,   130,   130,   130,   106,
      79,   106,   104,   103,    79,    81,    65,    79,   130,    79,
     130,    77,   130
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
     113,   113,   113,   114,   114,   114,   115,   115,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   121,   121,   122,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   128,   129,   129,   130,   130,
     130,   130,   130,   130,   131,   131,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   137,
     137,   137,   137,   138,   138,   138,   138,   139,   139,   140,
     140,   141,   141,   142
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
       1,     1,     1,     5,     4,     2,     1,     2,     2,     1,
       2,     1,     3,     1,     2,     1,     3,     3,     4,     4,
       3,     1,     2,     1,     1,     3,     2,     1,     2,     1,
       2,     1,     2,     1,     3,     4,     3,     3,     2,     4,
       3,     3,     2,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     2,
       1,     2,     1,     2,     2,     1,     7,     5,     5,     5,
       7,     7,     6,     2,     2,     2,     3,     1,     2,     1,
       1,     2,     3,     1
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
#line 152 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "parsed id"<<std::endl;(yyval.expression) = (yyvsp[0].identnode); }
#line 1775 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 153 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1781 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 154 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "STRING" << std::endl; }
#line 1787 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 155 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1793 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = new IdentifierNode(*((yyvsp[0].text))); }
#line 1799 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 159 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_int((yyvsp[0].ivalue)); }
#line 1805 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 160 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1811 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 161 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1817 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 162 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1823 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 163 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1829 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1835 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArraySubscript((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1841 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-2].expression)); }
#line 1847 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-3].expression), (yyvsp[-1].argexprlist)); }
#line 1853 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new MemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1859 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new DerefMemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1865 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 172 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostInc((yyvsp[-1].expression)); }
#line 1871 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostDec((yyvsp[-1].expression)); }
#line 1877 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argexprlist) = new ArgExprList((yyvsp[0].expression)); }
#line 1883 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].argexprlist))->AppendArgExpression((yyvsp[0].expression)); }
#line 1889 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[0].expression); }
#line 1895 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 180 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreInc((yyvsp[0].expression)); }
#line 1901 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreDec((yyvsp[0].expression)); }
#line 1907 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = PrefixExpr::DecodeUnaryOp((yyvsp[-1].text),(yyvsp[0].expression)); }
#line 1913 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofExpr((yyvsp[0].expression)); }
#line 1919 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofType((yyvsp[-1].t_type_name)); }
#line 1925 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&");}
#line 1931 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*");}
#line 1937 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+");}
#line 1943 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 189 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-");}
#line 1949 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("~");}
#line 1955 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("!");}
#line 1961 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1967 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CastExpr((yyvsp[-2].t_type_name), (yyvsp[0].expression)); }
#line 1973 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1979 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Multiply((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1985 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1991 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 199 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Modulo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1997 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 2003 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Add((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2009 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2015 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 206 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2021 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftLeft((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2027 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftRight((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2033 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2039 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2045 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2051 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2057 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 214 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2063 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2069 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new EqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2075 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new NotEqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2081 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2087 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 223 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2093 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2099 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseXOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2105 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2111 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 229 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2117 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 231 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2123 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2129 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 234 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2135 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 235 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2141 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 237 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2147 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 238 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new TernaryOpExpression((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2153 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2159 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 241 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = GenericAssignExpr::DecodeAssignOp((yyvsp[-2].expression), (yyvsp[-1].text), (yyvsp[0].expression)); }
#line 2165 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("=");}
#line 2171 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*=");}
#line 2177 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("/=");}
#line 2183 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("%=");}
#line 2189 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+=");}
#line 2195 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-=");}
#line 2201 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 250 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("<<=");}
#line 2207 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string(">>=");}
#line 2213 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&=");}
#line 2219 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("^=");}
#line 2225 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("|=");}
#line 2231 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2237 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CommaSepExpression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2243 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.constexp) = new ConstantExpression((yyvsp[0].expression)); std::cout << "new const expr" << std::endl;}
#line 2249 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_init_declarator_list)); }
#line 2255 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-1].t_declaration_specifiers)); }
#line 2261 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 270 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,NULL,(yyvsp[0].t_storage_class_specifier)); }
#line 2267 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,(yyvsp[0].t_declaration_specifiers),(yyvsp[-1].t_storage_class_specifier)); }
#line 2273 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[0].t_type_specifier)); }
#line 2279 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 273 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[-1].t_type_specifier), (yyvsp[0].t_declaration_specifiers)); }
#line 2285 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_storage_class_specifier) = new TypedefNode; }
#line 2291 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 277 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator)); }
#line 2297 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator), (yyvsp[-2].t_init_declarator_list)); }
#line 2303 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 280 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[0].t_declarator)); }
#line 2309 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[-2].t_declarator), (yyvsp[0].t_initializer)); }
#line 2315 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 283 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("void"); }
#line 2321 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("char"); }
#line 2327 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("short"); }
#line 2333 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("int"); }
#line 2339 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("long"); }
#line 2345 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 288 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("float"); }
#line 2351 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("double"); }
#line 2357 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 290 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("signed"); }
#line 2363 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("unsigned"); }
#line 2369 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = (yyvsp[0].struct_spec); }
#line 2375 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_spec) = new struct_specifier((yyvsp[-3].identnode), (yyvsp[-1].struct_dection_list)); }
#line 2381 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_spec) = new struct_specifier(NULL, (yyvsp[-1].struct_dection_list)); }
#line 2387 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_spec) = new struct_specifier((yyvsp[0].identnode)); }
#line 2393 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection_list) = new struct_declaration_list((yyvsp[0].struct_dection)); }
#line 2399 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].struct_dection_list)->AppendDeclaration((yyvsp[0].struct_dection)); }
#line 2405 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection) = new struct_declaration((yyvsp[-1].t_specifier_list), (yyvsp[0].struct_dec_list)); }
#line 2411 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 307 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[0].t_type_specifier)); }
#line 2417 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[-1].t_type_specifier), (yyvsp[0].t_specifier_list)); }
#line 2423 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 310 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dec_list) = new struct_declarator_list((yyvsp[0].t_declarator)); }
#line 2429 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].struct_dec_list)->AppendDeclarator((yyvsp[0].t_declarator)); }
#line 2435 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 332 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator)); }
#line 2441 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 333 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator), (yyvsp[-1].t_pointer)); }
#line 2447 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator((yyvsp[0].identnode)); }
#line 2453 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, NULL, NULL,NULL, (yyvsp[-1].t_declarator)); }
#line 2459 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), new unspecified_array_length()); }
#line 2465 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 339 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), (yyvsp[-1].constexp)); }
#line 2471 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 340 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), NULL, (yyvsp[-1].t_parameter_list)); }
#line 2477 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 342 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), NULL, new empty_parameter_list()); }
#line 2483 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer(); }
#line 2489 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer((yyvsp[0].t_pointer)); }
#line 2495 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 347 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = (yyvsp[0].t_parameter_list); }
#line 2501 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 349 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration)); }
#line 2507 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 350 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration), (yyvsp[-2].t_parameter_list)); }
#line 2513 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 352 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), (yyvsp[0].t_declarator)); }
#line 2519 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[0].t_declaration_specifiers)); }
#line 2525 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 354 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), NULL, (yyvsp[0].t_abstract_declarator)); }
#line 2531 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[0].t_specifier_list)); }
#line 2537 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 362 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[-1].t_specifier_list), (yyvsp[0].t_abstract_declarator)); }
#line 2543 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator(NULL, (yyvsp[0].t_pointer)); }
#line 2549 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator), (yyvsp[-1].t_pointer)); }
#line 2555 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator)); }
#line 2561 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, (yyvsp[-1].t_abstract_declarator)); }
#line 2567 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, (yyvsp[-1].constexp)); }
#line 2573 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, (yyvsp[-1].constexp)); }
#line 2579 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 371 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, new unspecified_array_length()); }
#line 2585 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, new unspecified_array_length()); }
#line 2591 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2597 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 374 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2603 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 375 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, NULL, new empty_parameter_list()); }
#line 2609 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, new empty_parameter_list()); }
#line 2615 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 381 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer((yyvsp[0].expression)); }
#line 2621 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 382 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-1].t_initializer_list)); }
#line 2627 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 383 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-2].t_initializer_list)); }
#line 2633 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer)); }
#line 2639 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 386 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer), (yyvsp[-2].t_initializer_list)); }
#line 2645 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 400 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2651 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 401 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2657 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].cmpstmt); }
#line 2663 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 403 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].exprstmt); }
#line 2669 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 404 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2675 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 405 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2681 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 407 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[-2].constexp), (yyvsp[0].stmt)); }
#line 2687 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 408 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[0].stmt)); }
#line 2693 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 410 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-2].t_declist), (yyvsp[-1].stmtlist)); }
#line 2699 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 411 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].t_declist));}
#line 2705 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 412 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].stmtlist)); /*Will need to use arg overloaded constructor to differentiate between the above*/}
#line 2711 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 413 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement(); }
#line 2717 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 415 "src/parser.y" /* yacc.c:1646  */
    {(yyval.t_declist) = new DeclarationList((yyvsp[0].t_declaration)); }
#line 2723 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 416 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declist) = new DeclarationList((yyvsp[-1].t_declist), (yyvsp[0].t_declaration)); }
#line 2729 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 418 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "parsing single statement" << std::endl;(yyval.stmtlist) = new StatementList((yyvsp[0].stmt)); }
#line 2735 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 419 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StatementList((yyvsp[-1].stmtlist), (yyvsp[0].stmt)); }
#line 2741 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 421 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new ExpressionStatement((yyvsp[-1].expression)); }
#line 2747 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 422 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new EmptyStatement(); }
#line 2753 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 424 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfElse((yyvsp[-4].expression), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 2759 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 425 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new If((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2765 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 426 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Switch((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2771 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 439 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new While((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2777 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 440 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DoWhile((yyvsp[-5].stmt), (yyvsp[-2].expression)); }
#line 2783 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 441 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-4].exprstmt),(yyvsp[-3].exprstmt),(yyvsp[-2].expression),(yyvsp[0].stmt));}
#line 2789 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 442 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-3].exprstmt),(yyvsp[-2].exprstmt),(yyvsp[0].stmt));}
#line 2795 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 444 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Continue(); }
#line 2801 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 445 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Break(); }
#line 2807 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 446 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return(); }
#line 2813 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 447 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return((yyvsp[-1].expression)); }
#line 2819 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 455 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_translation_unit) = new TranslationUnit((yyvsp[0].t_external_declaration)); }
#line 2825 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 456 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-1].t_translation_unit))->AppendDeclaration((yyvsp[0].t_external_declaration)); }
#line 2831 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 458 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = (yyvsp[0].t_function_definition); }
#line 2837 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 459 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = new ExternalDeclaration((yyvsp[0].t_declaration)); }
#line 2843 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 461 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 2849 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 462 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 2855 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 466 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "Its a valid program" << std::endl; g_root = (yyvsp[0].t_translation_unit); }
#line 2861 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2865 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 468 "src/parser.y" /* yacc.c:1906  */


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
