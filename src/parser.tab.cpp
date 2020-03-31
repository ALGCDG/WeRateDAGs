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
  #include "./feSymtab.hpp"
  #include "./feSymtabDec.hpp"


  extern TranslationUnit *g_root; // A way of getting the AST out
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

#line 264 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 281 "src/parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  320

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
       0,   166,   166,   167,   168,   169,   171,   175,   176,   177,
     178,   179,   181,   182,   183,   184,   185,   186,   187,   188,
     190,   191,   193,   194,   195,   196,   197,   198,   200,   201,
     202,   203,   204,   205,   207,   208,   210,   211,   212,   213,
     216,   217,   218,   220,   221,   222,   224,   225,   226,   227,
     228,   230,   231,   232,   236,   237,   239,   240,   242,   243,
     245,   246,   248,   249,   251,   252,   254,   255,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   271,
     272,   274,   281,   282,   284,   285,   286,   287,   289,   291,
     292,   294,   295,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   308,   310,   312,   314,   318,   319,   321,
     323,   324,   326,   327,   336,   337,   338,   340,   341,   343,
     344,   346,   348,   349,   352,   353,   354,   355,   356,   358,
     360,   361,   363,   365,   366,   368,   369,   370,   377,   378,
     380,   381,   382,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   397,   398,   399,   401,   402,   416,   417,   418,
     419,   420,   421,   423,   424,   426,   427,   428,   429,   431,
     432,   434,   435,   437,   438,   440,   441,   442,   455,   456,
     457,   458,   460,   461,   462,   463,   471,   472,   474,   475,
     477,   478,   482
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
  "enum_specifier", "enum_list", "enumerator", "ENUM_CONST", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "labeled_statement", "compound_statement",
  "declaration_list", "statement_list", "EXPR_statement",
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
     335,   336,   337,   338
};
# endif

#define YYPACT_NINF -155

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-155)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1002,  -155,    46,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,     5,    17,  -155,    40,  -155,  -155,    31,  1117,
    1117,  -155,  -155,   -38,   -22,     7,  1002,  -155,  -155,    64,
    -155,    70,    41,   306,    44,    -8,  -155,    62,  -155,    39,
    -155,  -155,   247,  -155,  1081,   630,   -22,  -155,  -155,  -155,
     -42,  -155,   108,    70,   306,  1039,  -155,    40,   306,  -155,
      40,  -155,   581,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,   935,   935,  -155,  -155,  -155,  -155,   966,   995,
     127,    56,   101,   117,   550,   130,   115,   126,   858,  -155,
     782,  -155,  -155,  -155,  -155,   193,   249,   995,  -155,   173,
     174,   168,   157,   196,   103,   181,   199,   216,    19,  -155,
    -155,   114,  -155,    31,  -155,  -155,  -155,   328,   409,  -155,
    -155,  -155,  -155,  -155,    27,   158,   190,  -155,  -155,  -155,
    -155,   176,    70,  -155,   995,   -21,  -155,  -155,  -155,   122,
    -155,  1070,  -155,   242,   581,  -155,  -155,   995,  -155,  -155,
     782,  -155,   214,   550,   995,   995,   995,   198,   889,  -155,
    -155,  -155,   125,   -31,    24,   187,  -155,  -155,    70,    70,
     721,   995,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,   995,  -155,   995,   995,   995,   995,   995,
     995,   995,   995,   995,   995,   995,   995,   995,   995,   995,
     995,   995,   995,   995,   995,  -155,  -155,  -155,   440,  -155,
    -155,   973,   661,  -155,     8,  -155,   -13,  -155,  1117,  -155,
    -155,  -155,  -155,    40,  -155,  -155,  -155,    32,   189,   550,
    -155,    43,    49,    81,   194,   889,  -155,  -155,  1030,    36,
    -155,   995,  -155,  -155,  -155,    84,  -155,    -6,  -155,  -155,
    -155,  -155,   173,   173,   174,   174,   168,   168,   168,   168,
     157,   157,   196,   103,   181,   199,   216,   175,  -155,  -155,
    -155,   195,   197,  -155,   200,   -13,  1108,   690,  -155,  -155,
     521,  -155,  -155,  -155,   550,   550,   550,   995,   750,  -155,
     995,  -155,  -155,   995,  -155,  -155,  -155,  -155,   201,  -155,
     212,  -155,  -155,   213,  -155,  -155,   118,   550,   119,  -155,
    -155,  -155,  -155,   550,   205,  -155,   550,  -155,  -155,  -155
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,   130,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     0,     0,    88,     0,   124,   189,     0,    84,
      86,   103,   102,     0,   122,     0,   192,   186,   188,     0,
     131,     0,   114,     0,   106,     0,    83,     0,    89,    91,
      85,    87,     0,   190,     0,     0,   123,   187,     1,   121,
       0,   117,   119,     0,   110,     0,   107,     0,     0,   125,
       0,    82,     0,   191,     7,     8,     9,    10,    11,     4,
      30,    31,     0,     0,    29,    33,    28,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
       0,   168,    12,     2,     3,    22,    34,     0,    36,    40,
      43,    46,    51,    54,    56,    58,    60,    62,    64,    66,
      79,     0,   169,     0,   171,   158,   159,     0,     0,   160,
     157,   161,   162,   129,   136,     0,   132,   133,   126,    34,
      81,     0,     0,   116,     0,     0,   111,   105,   108,     0,
     112,     0,    90,    91,     0,   152,    92,     0,    23,    24,
       0,    26,     0,     0,     0,     0,     0,     0,     0,   182,
     183,   184,     0,     0,   138,     0,    18,    19,     0,     0,
       0,     0,    68,    72,    73,    69,    70,    71,    76,    78,
      77,    75,    74,     0,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   166,   170,     0,   167,
     172,     0,     0,   135,   140,   137,   142,   128,     0,   127,
     118,   120,   115,     0,   109,   104,   155,     0,     0,     0,
     164,     0,     0,     0,     0,     0,   185,     5,     0,   140,
     139,     0,    16,    17,    14,     0,    20,     0,    67,    37,
      38,    39,    41,    42,    44,    45,    48,    47,    50,    49,
      52,    53,    55,    57,    59,    61,    63,     0,    80,   165,
     151,     0,     0,   147,     0,   141,     0,     0,   134,   113,
       0,   153,    27,   163,     0,     0,     0,     0,     0,    35,
       0,    15,    13,     0,   149,   143,   145,   150,     0,   146,
       0,   154,   156,   176,   177,   178,     0,     0,     0,    21,
      65,   148,   144,     0,     0,   181,     0,   175,   179,   180
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -155,  -155,     6,  -155,  -155,  -155,   -45,  -155,   -75,    42,
      53,    29,    50,    96,    98,    99,    95,   110,  -155,   -44,
     -11,  -155,   -78,   -50,   -19,    54,  -155,  -155,   238,    37,
    -155,   265,   -40,   -47,  -155,  -155,   273,   206,  -155,    -7,
     -20,     0,   -41,  -155,   109,   178,   -67,   -34,  -119,  -155,
     -71,  -155,    97,  -155,   227,  -154,  -155,  -155,  -155,  -155,
     319,  -155,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    94,    95,   245,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   183,   111,   131,    17,   124,    19,    37,    38,    20,
      21,    55,    56,    57,   139,    22,    50,    51,    52,    23,
      24,    25,   271,   126,   127,   165,   272,   216,   146,   227,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    26,
      27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     129,   130,    30,   125,   235,    46,    16,   136,    35,   132,
     162,    39,   163,   157,     1,   138,     1,     1,    32,    34,
     204,    16,   184,   112,    16,   226,     1,   148,   149,   152,
     132,    16,    16,   151,   129,   130,     1,    49,   202,     2,
       1,   133,     2,   164,    42,   204,     2,   210,   237,     1,
     140,   145,   129,   143,    18,     2,    44,   215,    45,    49,
      62,     2,   222,    16,    48,   276,    16,   277,   203,   163,
      54,    59,   163,    40,    41,   292,   231,   232,   233,     1,
      18,   288,   230,   280,   221,    15,   211,    31,   212,   129,
     130,    54,    54,   247,   204,    54,   113,   240,   207,    33,
     204,   138,   238,   164,   212,   211,   143,   212,    36,    15,
     249,   250,   251,    60,   238,   281,   212,   213,    15,    16,
      43,    42,   284,    53,   214,   267,    58,    54,   285,   134,
      16,   198,   204,   145,   154,   290,    63,   210,    49,    61,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   283,   246,
     286,   302,   274,   291,   239,   204,   289,   129,   130,   204,
     204,   113,   248,   223,   242,   243,   204,   153,    54,   155,
     275,   192,   193,   194,   195,   188,   189,    54,   185,   186,
     187,   205,   159,   268,    46,   156,   129,   314,   316,   224,
     190,   191,   236,   160,    35,   275,   166,   167,   158,   306,
     308,   214,   199,   303,   304,   305,   279,    16,   196,   197,
      16,   256,   257,   258,   259,   293,   204,   300,   200,    16,
     252,   253,   129,   130,   201,   298,   315,   217,   239,   168,
     169,   218,   317,   254,   255,   319,   260,   261,   129,   310,
      64,    65,    66,    67,    68,    69,     1,   219,    70,    71,
      72,    73,    74,    62,   229,   234,   241,    75,   282,   145,
     172,   170,   287,   171,   294,    76,   295,    77,   313,   309,
     311,   296,   318,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   312,   262,    78,   265,   263,   142,   264,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    79,
      80,    81,   266,    82,    83,    84,    85,    86,    87,    88,
      12,    13,    14,   141,    89,    90,   135,   278,   228,    42,
      91,    64,    65,    66,    67,    68,    69,     1,   220,    70,
      71,    72,    73,    74,   208,    47,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,    77,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    12,
      13,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      79,    80,    81,     0,    82,    83,    84,    85,    86,    87,
      88,    12,    13,    14,     0,    89,    90,     0,     0,     0,
      42,   206,    64,    65,    66,    67,    68,    69,     1,     0,
      70,    71,    72,    73,    74,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    77,
       0,     0,     0,    64,    65,    66,    67,    68,    69,     1,
       0,    70,    71,    72,    73,    74,     0,    78,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      77,    79,    80,    81,     0,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,    89,    90,    78,     0,
       0,    42,   209,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,    80,    81,     0,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,    89,    90,     0,
       0,     0,    42,   269,    64,    65,    66,    67,    68,    69,
       1,     0,    70,    71,    72,    73,    74,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    77,     0,    64,    65,    66,    67,    68,    69,     1,
       0,    70,    71,    72,    73,    74,     0,     0,     0,    78,
      75,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      77,     0,     0,     0,    64,    65,    66,    67,    68,    69,
       1,     0,    70,    71,    72,    73,    74,     0,    78,    90,
       0,    75,     0,   144,   301,     0,     0,     0,     0,    76,
       0,    77,    79,    80,    81,     0,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,    89,    90,    78,
       0,     0,    42,    64,    65,    66,    67,    68,    69,     1,
       0,    70,    71,    72,    73,    74,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,     0,     0,    76,    90,
      77,     0,     0,   144,    64,    65,    66,    67,    68,    69,
       1,     0,    70,    71,    72,    73,    74,     0,    78,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    77,     0,    64,    65,    66,    67,    68,    69,     1,
       0,    70,    71,    72,    73,    74,     0,     0,    90,    78,
      75,   128,     0,     0,     0,     0,     0,     0,    76,     0,
      77,     0,     0,     0,    64,    65,    66,    67,    68,    69,
       1,     0,    70,    71,    72,    73,    74,     0,    78,    90,
       0,    75,   273,     0,     0,     0,     0,     0,     0,    76,
       0,    77,     0,    64,    65,    66,    67,    68,    69,     1,
       0,    70,    71,    72,    73,    74,     0,     0,    90,    78,
      75,   299,     0,     0,     0,     0,     0,     0,    76,     0,
      77,     0,     0,     0,     0,    64,    65,    66,    67,    68,
      69,     1,     0,    70,    71,    72,    73,    74,    78,    90,
     244,     0,    75,     0,     0,     0,     0,     0,     0,     0,
      76,     0,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,   307,
      78,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
      90,    64,    65,    66,    67,    68,    69,     1,     0,    70,
      71,    72,    73,    74,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    76,     0,    77,     0,
       0,     0,    64,    65,    66,    67,    68,    69,     1,     0,
      70,    71,    72,    73,    74,     0,    78,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,    90,    78,    64,    65,
      66,    67,    68,    69,     1,     0,    70,    71,    72,    73,
      74,     0,     0,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,    76,     0,    77,    89,    90,     0,    64,
      65,    66,    67,    68,    69,     1,     0,    70,    71,    72,
      73,    74,     1,    78,     0,     0,    75,     0,     2,     0,
       0,     0,     0,     0,    76,     0,    77,     0,    64,    65,
      66,    67,    68,    69,     1,     0,    70,    71,    72,    73,
      74,     1,     0,   147,    78,    75,     0,     2,     0,     0,
       0,     0,     0,    76,     0,    77,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,    78,   150,     2,    12,    13,    14,     0,
       0,   211,   270,   212,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    90,     0,    12,    13,    14,     0,     0,
      15,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     3,     4,     5,     6,     7,     8,     9,    10,
      11,     0,     0,    12,    13,    14,     0,     0,   238,   270,
     212,     0,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,   225,    12,    13,    14,     0,     0,     0,
     123,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
       0,    12,    13,    14,     0,     0,     0,   297,     0,     0,
      12,    13,    14
};

static const yytype_int16 yycheck[] =
{
      45,    45,     2,    44,   158,    25,     0,    54,    15,    51,
      88,    18,    90,    84,     9,    55,     9,     9,    12,    13,
      51,    15,    97,    42,    18,   144,     9,    72,    73,    79,
      51,    25,    26,    78,    79,    79,     9,    31,    19,    15,
       9,    83,    15,    90,    82,    51,    15,   118,    79,     9,
      57,    62,    97,    60,     0,    15,    78,   124,    80,    53,
      21,    15,    83,    57,     0,    78,    60,    80,    49,   147,
      33,    79,   150,    19,    20,    81,   154,   155,   156,     9,
      26,   235,   153,    51,   134,    78,    78,    82,    80,   134,
     134,    54,    55,   171,    51,    58,    42,   164,   117,    82,
      51,   141,    78,   150,    80,    78,   113,    80,    77,    78,
     185,   186,   187,    51,    78,    83,    80,   124,    78,   113,
      23,    82,    79,    82,   124,   203,    82,    90,    79,    21,
     124,    28,    51,   144,    78,    51,    39,   208,   132,    77,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   229,   170,
      79,   280,   212,    79,   164,    51,   241,   212,   212,    51,
      51,   117,   183,    51,   168,   169,    51,    50,   141,    78,
     214,    24,    25,    26,    27,    11,    12,   150,    15,    16,
      17,    77,    77,   204,   214,    78,   241,    79,    79,    77,
      32,    33,    77,    77,   211,   239,    13,    14,    78,   287,
     288,   211,    31,   284,   285,   286,   223,   211,    22,    23,
     214,   192,   193,   194,   195,    50,    51,   277,    29,   223,
     188,   189,   277,   277,    18,   276,   307,    79,   238,    46,
      47,    51,   313,   190,   191,   316,   196,   197,   293,   293,
       3,     4,     5,     6,     7,     8,     9,    81,    11,    12,
      13,    14,    15,    21,    50,    67,    79,    20,    79,   280,
      21,    78,    78,    80,    79,    28,    79,    30,    65,   290,
      79,    81,    77,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    81,   198,    48,   201,   199,    60,   200,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   202,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    58,    77,    78,    53,   218,   150,    82,
      83,     3,     4,     5,     6,     7,     8,     9,   132,    11,
      12,    13,    14,    15,   117,    26,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    73,
      74,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    77,    78,    -1,    -1,    -1,
      82,    83,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    48,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    62,    63,    64,    -1,    66,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    77,    78,    48,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    77,    78,    -1,
      -1,    -1,    82,    83,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,    48,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    48,    78,
      -1,    20,    -1,    82,    83,    -1,    -1,    -1,    -1,    28,
      -1,    30,    62,    63,    64,    -1,    66,    67,    68,    69,
      70,    71,    72,    -1,    -1,    -1,    -1,    77,    78,    48,
      -1,    -1,    82,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    78,
      30,    -1,    -1,    82,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    48,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    78,    48,
      20,    81,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    -1,    48,    78,
      -1,    20,    81,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    30,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    -1,    -1,    78,    48,
      20,    81,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      30,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    48,    78,
      79,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    -1,    -1,
      78,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    -1,    48,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    48,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    77,    78,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,     9,    48,    -1,    -1,    20,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,     9,    -1,    78,    48,    20,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    30,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    78,    15,    73,    74,    75,    -1,
      -1,    78,    79,    80,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    73,    74,    75,    -1,    -1,
      78,    -1,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    73,    74,    75,    -1,    -1,    78,    79,
      80,    -1,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    73,    74,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    73,    74,    75,    -1,    -1,    -1,
      79,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    73,    74,    75,    -1,    -1,    -1,    79,    -1,    -1,
      73,    74,    75
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    15,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    73,    74,    75,    78,    86,   108,   109,   110,
     113,   114,   119,   123,   124,   125,   143,   144,   145,   146,
     125,    82,    86,    82,    86,   123,    77,   111,   112,   123,
     109,   109,    82,   136,    78,    80,   124,   144,     0,    86,
     120,   121,   122,    82,   113,   115,   116,   117,    82,    79,
      51,    77,    21,   136,     3,     4,     5,     6,     7,     8,
      11,    12,    13,    14,    15,    20,    28,    30,    48,    62,
      63,    64,    66,    67,    68,    69,    70,    71,    72,    77,
      78,    83,    85,    86,    87,    88,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   106,   108,   109,   134,   135,   136,   137,   138,   139,
     140,   141,   142,    79,   109,   126,   127,   128,    81,    90,
     103,   107,    51,    83,    21,   120,   117,    83,   116,   118,
     123,   115,   112,   123,    82,   104,   132,    78,    90,    90,
      78,    90,   107,    50,    78,    78,    78,   134,    78,    77,
      77,    77,   106,   106,   117,   129,    13,    14,    46,    47,
      78,    80,    21,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   105,    92,    15,    16,    17,    11,    12,
      32,    33,    24,    25,    26,    27,    22,    23,    28,    31,
      29,    18,    19,    49,    51,    77,    83,   108,   138,    83,
     134,    78,    80,   123,   125,   130,   131,    79,    51,    81,
     121,   107,    83,    51,    77,    83,   132,   133,   129,    50,
     134,   106,   106,   106,    67,   139,    77,    79,    78,   125,
     130,    79,    86,    86,    79,    89,   104,   106,   104,    92,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    98,    99,   100,   101,   106,   104,    83,
      79,   126,   130,    81,   107,   131,    78,    80,   128,   123,
      51,    83,    79,   134,    79,    79,    79,    78,   139,    92,
      51,    79,    81,    50,    79,    79,    81,    79,   126,    81,
     107,    83,   132,   134,   134,   134,   106,    79,   106,   104,
     103,    79,    81,    65,    79,   134,    79,   134,    77,   134
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
     113,   113,   113,   113,   114,   114,   114,   115,   115,   116,
     117,   117,   118,   118,   119,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     125,   125,   126,   127,   127,   128,   128,   128,   129,   129,
     130,   130,   130,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   133,   133,   134,   134,   134,
     134,   134,   134,   135,   135,   136,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   140,   140,   140,   141,   141,
     141,   141,   142,   142,   142,   142,   143,   143,   144,   144,
     145,   145,   146
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
       1,     1,     1,     1,     5,     4,     2,     1,     2,     3,
       1,     2,     1,     3,     2,     5,     4,     1,     3,     1,
       3,     1,     1,     2,     1,     3,     3,     4,     4,     3,
       1,     2,     1,     1,     3,     2,     1,     2,     1,     2,
       1,     2,     1,     3,     4,     3,     3,     2,     4,     3,
       3,     2,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     1,
       2,     1,     2,     2,     1,     7,     5,     5,     5,     7,
       7,     6,     2,     2,     2,     3,     1,     2,     1,     1,
       2,     3,     1
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
#line 166 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].identnode); }
#line 1802 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 167 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1808 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "src/parser.y" /* yacc.c:1646  */
    { std::cerr << "new string literal" << std::endl;(yyval.expression) = new StringLiteral(*(yyvsp[0].text)); }
#line 1814 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 169 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1820 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 171 "src/parser.y" /* yacc.c:1646  */
    { 
      (yyval.identnode) = new IdentifierNode(*((yyvsp[0].text))); 
}
#line 1828 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 175 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_int((yyvsp[0].ivalue)); }
#line 1834 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 176 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_char(*(yyvsp[0].text)); }
#line 1840 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 177 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1846 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 178 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new constant_float((yyvsp[0].fvalue)); }
#line 1852 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 179 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Constant(); }
#line 1858 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 181 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1864 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 182 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ArraySubscript((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1870 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 183 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-2].expression)); }
#line 1876 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new FuncCall((yyvsp[-3].expression), (yyvsp[-1].argexprlist)); }
#line 1882 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new MemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1888 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new DerefMemberAccess((yyvsp[-2].expression), (yyvsp[0].identnode)); }
#line 1894 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostInc((yyvsp[-1].expression)); }
#line 1900 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 188 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PostDec((yyvsp[-1].expression)); }
#line 1906 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 190 "src/parser.y" /* yacc.c:1646  */
    { (yyval.argexprlist) = new ArgExprList((yyvsp[0].expression)); }
#line 1912 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].argexprlist))->AppendArgExpression((yyvsp[0].expression)); }
#line 1918 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 193 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression)=(yyvsp[0].expression); }
#line 1924 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 194 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreInc((yyvsp[0].expression)); }
#line 1930 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 195 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new PreDec((yyvsp[0].expression)); }
#line 1936 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 196 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = PrefixExpr::DecodeUnaryOp((yyvsp[-1].text),(yyvsp[0].expression)); }
#line 1942 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofExpr((yyvsp[0].expression)); }
#line 1948 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 198 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new SizeofType((yyvsp[-1].t_type_name)); }
#line 1954 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 200 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&");}
#line 1960 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 201 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*");}
#line 1966 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 202 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+");}
#line 1972 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-");}
#line 1978 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 204 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("~");}
#line 1984 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 205 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("!");}
#line 1990 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 207 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1996 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CastExpr((yyvsp[-2].t_type_name), (yyvsp[0].expression)); }
#line 2002 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2008 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Multiply((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2014 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2020 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Modulo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2026 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 216 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression);}
#line 2032 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 217 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Add((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2038 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new Sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2044 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2050 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftLeft((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2056 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 222 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new ShiftRight((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2062 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 224 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2068 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 225 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2074 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 226 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThan((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2080 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 227 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LessThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2086 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 228 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new GreaterThanOrEqual((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2092 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 230 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2098 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 231 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new EqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2104 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 232 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new NotEqualTo((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2110 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 236 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2116 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 237 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2122 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2128 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseXOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2134 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 242 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2140 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new BitwiseOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2146 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 245 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2152 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 246 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalAND((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2158 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2164 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 249 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new LogicalOR((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2170 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2176 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new TernaryOpExpression((yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2182 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2188 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = GenericAssignExpr::DecodeAssignOp((yyvsp[-2].expression), (yyvsp[-1].text), (yyvsp[0].expression)); }
#line 2194 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("=");}
#line 2200 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("*=");}
#line 2206 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 260 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("/=");}
#line 2212 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 261 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("%=");}
#line 2218 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("+=");}
#line 2224 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 263 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("-=");}
#line 2230 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 264 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("<<=");}
#line 2236 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 265 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string(">>=");}
#line 2242 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 266 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("&=");}
#line 2248 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 267 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("^=");}
#line 2254 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 268 "src/parser.y" /* yacc.c:1646  */
    { (yyval.text) = new std::string("|=");}
#line 2260 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 271 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2266 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 272 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression) = new CommaSepExpression((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 2272 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 274 "src/parser.y" /* yacc.c:1646  */
    { (yyval.constexp) = new ConstantExpression((yyvsp[0].expression)); std::cerr << "new constant expression" << std::endl;}
#line 2278 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_init_declarator_list));}
#line 2284 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 282 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration) = new declaration((yyvsp[-1].t_declaration_specifiers));}
#line 2290 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,NULL,(yyvsp[0].t_storage_class_specifier));}
#line 2296 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 285 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers(NULL,(yyvsp[0].t_declaration_specifiers),(yyvsp[-1].t_storage_class_specifier)); }
#line 2302 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 286 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[0].t_type_specifier));}
#line 2308 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declaration_specifiers) = new declaration_specifiers((yyvsp[-1].t_type_specifier), (yyvsp[0].t_declaration_specifiers)); }
#line 2314 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 289 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_storage_class_specifier) = new TypedefNode;}
#line 2320 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 291 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator)); }
#line 2326 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 292 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator_list) = new init_declarator_list((yyvsp[0].t_init_declarator), (yyvsp[-2].t_init_declarator_list)); }
#line 2332 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 294 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[0].t_declarator)); }
#line 2338 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 295 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_init_declarator) = new init_declarator((yyvsp[-2].t_declarator), (yyvsp[0].t_initializer)); }
#line 2344 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("void"); }
#line 2350 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("char"); }
#line 2356 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 299 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("short"); }
#line 2362 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 300 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("int"); }
#line 2368 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 301 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("long"); }
#line 2374 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 302 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("float"); }
#line 2380 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 303 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("double"); }
#line 2386 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 304 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("signed"); }
#line 2392 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 305 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new type_specifier("unsigned"); }
#line 2398 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 306 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = (yyvsp[0].t_type_specifier); }
#line 2404 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 308 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = (yyvsp[0].t_type_specifier); }
#line 2410 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 311 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier((yyvsp[-3].identnode), (yyvsp[-1].struct_dection_list)); }
#line 2416 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 313 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier(NULL, (yyvsp[-1].struct_dection_list)); }
#line 2422 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 314 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new struct_specifier((yyvsp[0].identnode)); }
#line 2428 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 318 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection_list) = new struct_declaration_list((yyvsp[0].struct_dection)); }
#line 2434 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 319 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-1].struct_dection_list)->AppendDeclaration((yyvsp[0].struct_dection)); }
#line 2440 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 321 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dection) = new struct_declaration((yyvsp[-2].t_specifier_list), (yyvsp[-1].struct_dec_list)); }
#line 2446 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 323 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[0].t_type_specifier)); }
#line 2452 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 324 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_specifier_list) = new specifier_list((yyvsp[-1].t_type_specifier), (yyvsp[0].t_specifier_list)); }
#line 2458 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 326 "src/parser.y" /* yacc.c:1646  */
    { (yyval.struct_dec_list) = new struct_declarator_list((yyvsp[0].t_declarator)); }
#line 2464 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 327 "src/parser.y" /* yacc.c:1646  */
    { (yyvsp[-2].struct_dec_list)->AppendDeclarator((yyvsp[0].t_declarator)); }
#line 2470 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 336 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[0].identnode)); }
#line 2476 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 337 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[-3].identnode), (yyvsp[-1].t_enumlist)); }
#line 2482 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 338 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_specifier) = new EnumSpecifier((yyvsp[-1].t_enumlist)); }
#line 2488 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 340 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumlist) = new EnumeratorList((yyvsp[0].t_enumerator)); }
#line 2494 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 341 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-2].t_enumlist))->AppendEnumerator((yyvsp[0].t_enumerator));}
#line 2500 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumerator) = new Enumerator((yyvsp[0].identnode));}
#line 2506 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_enumerator) = new Enumerator((yyvsp[-2].identnode), (yyvsp[0].constexp));}
#line 2512 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 346 "src/parser.y" /* yacc.c:1646  */
    { (yyval.identnode) = (yyvsp[0].identnode); }
#line 2518 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 348 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator)); }
#line 2524 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 349 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declarator) = new declarator((yyvsp[0].t_direct_declarator), (yyvsp[-1].t_pointer)); }
#line 2530 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 352 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator((yyvsp[0].identnode));}
#line 2536 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 353 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, NULL, NULL,NULL, (yyvsp[-1].t_declarator)); }
#line 2542 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 354 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), new unspecified_array_length()); }
#line 2548 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 355 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), (yyvsp[-1].constexp)); }
#line 2554 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 356 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-3].t_direct_declarator), NULL, (yyvsp[-1].t_parameter_list)); }
#line 2560 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 358 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_declarator) = new direct_declarator(NULL, (yyvsp[-2].t_direct_declarator), NULL, new empty_parameter_list()); }
#line 2566 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 360 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer(); }
#line 2572 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_pointer) = new pointer((yyvsp[0].t_pointer)); }
#line 2578 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 363 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = (yyvsp[0].t_parameter_list); std::cerr << "Finished params" << std::endl; }
#line 2584 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration)); std::cerr << "LHS most param" <<std::endl; }
#line 2590 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 366 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_list) = new parameter_list((yyvsp[0].t_parameter_declaration), (yyvsp[-2].t_parameter_list)); }
#line 2596 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), (yyvsp[0].t_declarator)); }
#line 2602 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[0].t_declaration_specifiers)); }
#line 2608 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 370 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_parameter_declaration) = new parameter_declaration((yyvsp[-1].t_declaration_specifiers), NULL, (yyvsp[0].t_abstract_declarator)); }
#line 2614 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 377 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[0].t_specifier_list)); }
#line 2620 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 378 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_type_name) = new type_name((yyvsp[-1].t_specifier_list), (yyvsp[0].t_abstract_declarator)); }
#line 2626 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 380 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator(NULL, (yyvsp[0].t_pointer)); }
#line 2632 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 381 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator), (yyvsp[-1].t_pointer)); }
#line 2638 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 382 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_abstract_declarator) = new abstract_declarator((yyvsp[0].t_direct_abstract_declarator)); }
#line 2644 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 384 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, (yyvsp[-1].t_abstract_declarator)); }
#line 2650 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 385 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, (yyvsp[-1].constexp)); }
#line 2656 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 386 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, (yyvsp[-1].constexp)); }
#line 2662 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 387 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, new unspecified_array_length()); }
#line 2668 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 388 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, new unspecified_array_length()); }
#line 2674 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 389 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-3].t_direct_abstract_declarator), NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2680 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 390 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, (yyvsp[-1].t_parameter_list)); }
#line 2686 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 391 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator((yyvsp[-2].t_direct_abstract_declarator), NULL, NULL, new empty_parameter_list()); }
#line 2692 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 392 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_direct_abstract_declarator) = new direct_abstract_declarator(NULL, NULL, NULL, new empty_parameter_list()); }
#line 2698 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 397 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer((yyvsp[0].expression)); }
#line 2704 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 398 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-1].t_initializer_list)); }
#line 2710 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 399 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer) = new initializer(NULL, (yyvsp[-2].t_initializer_list)); }
#line 2716 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 401 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer)); }
#line 2722 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 402 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_initializer_list) = new initializer_list((yyvsp[0].t_initializer), (yyvsp[-2].t_initializer_list)); }
#line 2728 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 416 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2734 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 417 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2740 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 418 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].cmpstmt); }
#line 2746 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 419 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].exprstmt); }
#line 2752 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 420 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2758 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 421 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 2764 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 423 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[-2].constexp), (yyvsp[0].stmt)); }
#line 2770 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 424 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new CaseOrDefault((yyvsp[0].stmt)); }
#line 2776 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 426 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-2].t_declist), (yyvsp[-1].stmtlist)); }
#line 2782 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 427 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].t_declist));}
#line 2788 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 428 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement((yyvsp[-1].stmtlist)); /*Will need to use arg overloaded constructor to differentiate between the above*/}
#line 2794 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 429 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cmpstmt) = new CompoundStatement(); }
#line 2800 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 431 "src/parser.y" /* yacc.c:1646  */
    {(yyval.t_declist) = new DeclarationList((yyvsp[0].t_declaration)); }
#line 2806 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 432 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_declist) = new DeclarationList((yyvsp[-1].t_declist), (yyvsp[0].t_declaration)); }
#line 2812 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 434 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StatementList((yyvsp[0].stmt)); }
#line 2818 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 435 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmtlist) = new StatementList((yyvsp[-1].stmtlist), (yyvsp[0].stmt)); }
#line 2824 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 437 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new ExpressionStatement((yyvsp[-1].expression)); }
#line 2830 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 438 "src/parser.y" /* yacc.c:1646  */
    { (yyval.exprstmt) = new EmptyStatement(); }
#line 2836 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 440 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new IfElse((yyvsp[-4].expression), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 2842 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 441 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new If((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2848 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 442 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Switch((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2854 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 455 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new While((yyvsp[-2].expression), (yyvsp[0].stmt)); }
#line 2860 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 456 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new DoWhile((yyvsp[-5].stmt), (yyvsp[-2].expression)); }
#line 2866 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 457 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-4].exprstmt),(yyvsp[-3].exprstmt),(yyvsp[-2].expression),(yyvsp[0].stmt));}
#line 2872 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 458 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new For((yyvsp[-3].exprstmt),(yyvsp[-2].exprstmt),(yyvsp[0].stmt));}
#line 2878 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 460 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Continue(); }
#line 2884 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 461 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Break(); }
#line 2890 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 462 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return(); }
#line 2896 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 463 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new Return((yyvsp[-1].expression)); }
#line 2902 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 471 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_translation_unit) = new TranslationUnit((yyvsp[0].t_external_declaration)); }
#line 2908 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 472 "src/parser.y" /* yacc.c:1646  */
    { ((yyvsp[-1].t_translation_unit))->AppendDeclaration((yyvsp[0].t_external_declaration)); }
#line 2914 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 474 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = (yyvsp[0].t_function_definition); }
#line 2920 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 475 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_external_declaration) = new ExternalDeclaration((yyvsp[0].t_declaration)); }
#line 2926 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 477 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 2932 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 478 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_function_definition) = new FunctionDefinition((yyvsp[-2].t_declaration_specifiers), (yyvsp[-1].t_declarator), (yyvsp[0].cmpstmt)); }
#line 2938 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 482 "src/parser.y" /* yacc.c:1646  */
    {g_root = (yyvsp[0].t_translation_unit); }
#line 2944 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2948 "src/parser.tab.cpp" /* yacc.c:1646  */
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
#line 484 "src/parser.y" /* yacc.c:1906  */


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

