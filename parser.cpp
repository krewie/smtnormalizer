/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "parser.y" /* yacc.c:339  */

#include "scrambler.h"
#include "parser.h"
#include "lexer.h"
#include <limits.h>
#include <assert.h>
#include <iostream>

#define YYMAXDEPTH LONG_MAX
#define YYLTYPE_IS_TRIVIAL 1

void yyerror(const char *s);

using namespace scrambler;


#line 83 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BINCONSTANT = 258,
    HEXCONSTANT = 259,
    BVCONSTANT = 260,
    RATCONSTANT = 261,
    NUMERAL = 262,
    STRING = 263,
    SYMBOL = 264,
    KEYWORD = 265,
    TK_EOF = 266,
    TK_AS = 267,
    TK_UNDERSCORE = 268,
    TK_LET = 269,
    TK_BANG = 270,
    TK_FORALL = 271,
    TK_EXISTS = 272,
    TK_SET_LOGIC = 273,
    TK_DECLARE_SORT = 274,
    TK_DEFINE_SORT = 275,
    TK_DECLARE_FUN = 276,
    TK_DEFINE_FUN = 277,
    TK_PUSH = 278,
    TK_POP = 279,
    TK_ASSERT = 280,
    TK_CHECK_SAT = 281,
    TK_GET_ASSERTIONS = 282,
    TK_GET_UNSAT_CORE = 283,
    TK_GET_PROOF = 284,
    TK_SET_OPTION = 285,
    TK_GET_INFO = 286,
    TK_SET_INFO = 287,
    TK_GET_ASSIGNMENT = 288,
    TK_GET_MODEL = 289,
    TK_GET_VALUE = 290,
    TK_EXIT = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 50 "parser.y" /* yacc.c:355  */

    char *string;
    std::vector<scrambler::node *> *nodelist;
    scrambler::node *curnode;
    std::vector<char> *buf;

#line 167 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "parser.cpp" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  210

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      37,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   168,   174,   181,   192,   198,   209,   215,   224,
     230,   239,   251,   264,   271,   278,   285,   292,   300,   306,
     312,   318,   327,   336,   346,   350,   354,   358,   365,   372,
     380,   388,   392,   400,   410,   417,   424,   431,   435,   439,
     457,   459,   467,   472,   483,   488,   493,   498,   503,   513,
     518,   527,   536,   541,   545,   553,   558,   567,   573,   583,
     589,   599,   604,   613,   621,   631,   639,   644,   652,   662,
     667,   680,   685,   694,   699,   706,   718,   724,   732
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BINCONSTANT", "HEXCONSTANT",
  "BVCONSTANT", "RATCONSTANT", "NUMERAL", "STRING", "SYMBOL", "KEYWORD",
  "TK_EOF", "\"as\"", "\"_\"", "\"let\"", "\"!\"", "\"forall\"",
  "\"exists\"", "\"set-logic\"", "\"declare-sort\"", "\"define-sort\"",
  "\"declare-fun\"", "\"define-fun\"", "\"push\"", "\"pop\"", "\"assert\"",
  "\"check-sat\"", "\"get-assertions\"", "\"get-unsat-core\"",
  "\"get-proof\"", "\"set-option\"", "\"get-info\"", "\"set-info\"",
  "\"get-assignment\"", "\"get-model\"", "\"get-value\"", "\"exit\"",
  "'('", "')'", "'['", "']'", "$accept", "single_command", "command",
  "cmd_error", "cmd_set_logic", "cmd_declare_sort", "cmd_define_sort",
  "cmd_declare_fun", "cmd_define_fun", "cmd_push", "cmd_pop", "cmd_assert",
  "cmd_check_sat", "cmd_get_assertions", "cmd_get_unsat_core",
  "cmd_get_proof", "cmd_set_option", "cmd_get_info", "cmd_set_info",
  "info_argument", "cmd_get_assignment", "cmd_get_value", "cmd_exit",
  "a_term", "annotated_term", "plain_term", "term_symbol",
  "term_unqualified_symbol", "term_num_constant", "term_attribute_list",
  "term_attribute", "generic_sexp", "generic_sexp_list", "num_list",
  "int_list", "term_list", "quant_var_list", "begin_let_scope",
  "let_bindings", "let_binding", "logic_name", "shuffle_list", "a_sort",
  "sort_param_list", "a_sort_param", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,    40,    41,    91,
      93
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,   105,    32,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,    21,    73,    82,   107,   108,   111,   112,
      19,    84,   104,   106,   109,   133,   135,   136,   110,   116,
     117,  -105,   115,   118,   114,   120,   121,   122,   123,   124,
    -105,  -105,  -105,  -105,  -105,    83,   125,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,    78,   126,    95,  -105,
      19,  -105,   153,  -105,   127,    31,    28,    41,  -105,  -105,
      18,    65,  -105,    19,   129,   130,    76,    19,   131,  -105,
     132,   134,   137,   138,  -105,  -105,  -105,  -105,  -105,   139,
    -105,     5,   140,  -105,  -105,    20,    45,  -105,  -105,    64,
      20,    30,  -105,   160,    20,    68,   158,    20,   166,   167,
     168,   142,   142,   172,    12,   145,  -105,  -105,  -105,  -105,
    -105,   146,  -105,  -105,   147,    20,  -105,    20,   174,   148,
      20,  -105,    20,    19,   178,    20,   150,   151,  -105,    10,
      53,    25,  -105,    70,    72,  -105,   181,    74,  -105,  -105,
    -105,   154,    43,   184,  -105,   155,   156,   157,    20,    19,
    -105,  -105,  -105,  -105,    -4,  -105,  -105,  -105,  -105,    19,
      19,    19,    19,  -105,  -105,  -105,  -105,    13,  -105,  -105,
    -105,   159,   161,  -105,  -105,    38,   162,   163,   164,   165,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      22,     0,     0,     2,    21,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    89,     0,     0,     0,     0,     0,     0,     0,
      66,    67,    65,    64,    62,     0,     0,    51,    52,    58,
      60,    57,    34,    35,    36,    37,     0,     0,     0,    48,
       0,    50,     0,    23,     0,     0,     0,     0,    31,    32,
       0,     0,    85,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    42,    45,    44,    47,    46,     0,
      81,     0,     0,    24,    98,     0,     0,    96,    93,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    38,    41,    40,
      43,     0,    82,    90,     0,     0,    97,     0,     0,     0,
       0,    92,     0,     0,     0,     0,     0,     0,    77,     0,
       0,     0,    69,     0,     0,    59,     0,     0,    86,    49,
      25,     0,     0,     0,    27,     0,     0,     0,     0,     0,
      61,    68,    78,    63,     0,    72,    71,    53,    70,     0,
       0,     0,     0,    87,    26,    95,    79,     0,    28,    83,
      29,     0,     0,    73,    75,     0,     0,     0,     0,     0,
      80,    94,    84,    30,    74,    76,    55,    56,    88,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -105,   128,
    -105,  -105,  -105,   -30,  -105,  -105,   143,   141,  -105,  -105,
      54,  -102,  -105,  -105,  -105,   119,    -7,  -105,  -105,    47,
    -105,    71,  -104,  -105,   101
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   175,
      20,    21,    22,   100,    57,    58,    59,    60,    61,   151,
     152,   176,   195,   149,   187,   101,   115,    88,   157,   158,
      43,   111,   112,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,   134,    95,    96,    97,    98,   139,   141,    50,    51,
     143,    52,    53,   146,    54,    50,    51,   172,    52,    53,
     200,    54,    50,    51,     1,    52,    53,    54,    54,   108,
      42,   161,    41,   174,   193,   150,   165,   108,   166,   108,
     104,   169,    55,   131,    95,    96,    97,    98,   173,    55,
     155,   201,   108,   120,   104,   116,    55,   109,   141,    95,
      96,    97,    98,   177,   191,   109,   110,   109,   140,   105,
     118,   132,   194,   137,   119,   174,   204,   138,   113,   114,
     109,   185,    44,   135,    90,    91,    92,    93,    80,   123,
     174,    45,    54,   205,   132,    80,    81,    82,    83,    84,
      85,    95,    96,    97,    98,   144,   145,   144,   179,   144,
     180,   156,   182,   167,   153,   154,    46,    47,    48,    49,
      86,    74,    62,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   192,
      39,    40,    63,    66,    64,    67,    68,    65,    69,   196,
     197,   198,   199,    70,    72,    71,    73,    75,    76,    77,
     102,    78,    79,    89,    94,   103,   121,   122,   125,   142,
     126,   123,   127,   147,   148,   128,   129,   130,   150,   113,
     133,   119,   156,   163,   159,   160,   164,   168,   170,   171,
     181,   186,   184,   188,   189,   190,    99,   202,    87,   203,
     206,   207,   208,   209,   183,   178,   124,   136,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117
};

static const yytype_int16 yycheck[] =
{
      30,   105,     6,     7,     8,     9,   110,   111,     3,     4,
     114,     6,     7,   117,     9,     3,     4,     7,     6,     7,
       7,     9,     3,     4,    37,     6,     7,     9,     9,     9,
       9,   135,     0,    37,    38,    10,   140,     9,   142,     9,
       9,   145,    37,    38,     6,     7,     8,     9,    38,    37,
      38,    38,     9,    83,     9,    37,    37,    37,   162,     6,
       7,     8,     9,    38,   168,    37,    38,    37,    38,    38,
       5,   101,   174,     9,     9,    37,    38,    13,    37,    38,
      37,    38,     9,    38,     6,     7,     8,     9,    12,    13,
      37,     9,     9,   195,   124,    12,    13,    14,    15,    16,
      17,     6,     7,     8,     9,    37,    38,    37,    38,    37,
      38,    37,    38,   143,   121,   122,     9,     9,     7,     7,
      37,     7,    38,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,   169,
      35,    36,    38,    10,    38,    10,    10,    38,    38,   179,
     180,   181,   182,    37,    39,    38,    38,    37,    37,    37,
       7,    38,    38,    38,    38,    38,    37,    37,    37,     9,
      38,    13,    38,     7,     7,    38,    38,    38,    10,    37,
      40,     9,    37,     9,    38,    38,    38,     9,    38,    38,
       9,     7,    38,    38,    38,    38,    68,    38,    55,    38,
      38,    38,    38,    38,   157,   151,    87,   106,   137,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      61,    62,    63,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35,
      36,     0,     9,    81,     9,     9,     9,     9,     7,     7,
       3,     4,     6,     7,     9,    37,    64,    65,    66,    67,
      68,    69,    38,    38,    38,    38,    10,    10,    10,    38,
      37,    38,    39,    38,     7,    37,    37,    37,    38,    38,
      12,    13,    14,    15,    16,    17,    37,    67,    78,    38,
       6,     7,     8,     9,    38,     6,     7,     8,     9,    60,
      64,    76,     7,    38,     9,    38,    84,    85,     9,    37,
      38,    82,    83,    37,    38,    77,    37,    68,     5,     9,
      64,    37,    37,    13,    76,    37,    38,    38,    38,    38,
      38,    38,    64,    40,    83,    38,    85,     9,    13,    83,
      38,    83,     9,    83,    37,    38,    83,     7,     7,    74,
      10,    70,    71,    77,    77,    38,    37,    79,    80,    38,
      38,    83,    82,     9,    38,    83,    83,    64,     9,    83,
      38,    38,     7,    38,    37,    60,    72,    38,    71,    38,
      38,     9,    38,    80,    38,    38,     7,    75,    38,    38,
      38,    83,    64,    38,    72,    73,    64,    64,    64,    64,
       7,    38,    38,    38,    38,    72,    38,    38,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    44,    45,    46,    47,    47,    48,    48,    49,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    57,
      57,    57,    58,    59,    60,    60,    60,    60,    61,    62,
      63,    64,    64,    65,    66,    66,    66,    66,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    69,    70,
      70,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    83,    84,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     4,     5,     7,     8,     7,     8,     8,
       9,     4,     4,     4,     3,     3,     3,     3,     5,     5,
       5,     5,     4,     5,     1,     1,     1,     1,     3,     6,
       3,     1,     1,     5,     7,     7,     7,     1,     1,     4,
       1,     5,     1,     5,     1,     1,     1,     1,     5,     1,
       2,     2,     1,     2,     3,     1,     2,     1,     2,     1,
       2,     1,     2,     4,     5,     1,     1,     2,     4,     1,
       4,     1,     2,     1,     5,     4,     1,     2,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* BINCONSTANT  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1244 "parser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* HEXCONSTANT  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1250 "parser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* RATCONSTANT  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1256 "parser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* NUMERAL  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1262 "parser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* STRING  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1268 "parser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* SYMBOL  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1274 "parser.cpp" /* yacc.c:1257  */
        break;

    case 10: /* KEYWORD  */
#line 122 "parser.y" /* yacc.c:1257  */
      { free(((*yyvaluep).string)); }
#line 1280 "parser.cpp" /* yacc.c:1257  */
        break;

    case 67: /* term_symbol  */
#line 130 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).curnode); }
#line 1286 "parser.cpp" /* yacc.c:1257  */
        break;

    case 68: /* term_unqualified_symbol  */
#line 131 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).curnode); }
#line 1292 "parser.cpp" /* yacc.c:1257  */
        break;

    case 70: /* term_attribute_list  */
#line 133 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1298 "parser.cpp" /* yacc.c:1257  */
        break;

    case 73: /* generic_sexp_list  */
#line 132 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1304 "parser.cpp" /* yacc.c:1257  */
        break;

    case 74: /* num_list  */
#line 129 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1310 "parser.cpp" /* yacc.c:1257  */
        break;

    case 75: /* int_list  */
#line 129 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1316 "parser.cpp" /* yacc.c:1257  */
        break;

    case 76: /* term_list  */
#line 125 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1322 "parser.cpp" /* yacc.c:1257  */
        break;

    case 77: /* quant_var_list  */
#line 128 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1328 "parser.cpp" /* yacc.c:1257  */
        break;

    case 81: /* logic_name  */
#line 124 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).curnode); }
#line 1334 "parser.cpp" /* yacc.c:1257  */
        break;

    case 82: /* shuffle_list  */
#line 126 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1340 "parser.cpp" /* yacc.c:1257  */
        break;

    case 84: /* sort_param_list  */
#line 127 "parser.y" /* yacc.c:1257  */
      { delete ((*yyvaluep).nodelist); }
#line 1346 "parser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 140 "parser.y" /* yacc.c:1661  */
    {
      YYACCEPT;
  }
#line 1636 "parser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 168 "parser.y" /* yacc.c:1661  */
    {
      YYERROR;
  }
#line 1644 "parser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 175 "parser.y" /* yacc.c:1661  */
    {
      add_node("set-logic", (yyvsp[-1].curnode));
  }
#line 1652 "parser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 182 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-2].string));
      add_node("declare-sort", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1663 "parser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 193 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-4].string));
      add_node("define-sort", make_node((yyvsp[-4].string)), make_node(), (yyvsp[-1].curnode));
      free((yyvsp[-4].string));
  }
#line 1673 "parser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 199 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-5].string));
      add_node("define-sort", make_node((yyvsp[-5].string)), make_node((yyvsp[-3].nodelist)), (yyvsp[-1].curnode));
      pop_namespace();
      free((yyvsp[-5].string));
  }
#line 1684 "parser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 210 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-4].string));
      add_node("declare-fun", make_node((yyvsp[-4].string)), make_node(), (yyvsp[-1].curnode));
      free((yyvsp[-4].string));
  }
#line 1694 "parser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 216 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-5].string));
      add_node("declare-fun", make_node((yyvsp[-5].string)), make_node((yyvsp[-3].nodelist)), (yyvsp[-1].curnode));
      free((yyvsp[-5].string));
  }
#line 1704 "parser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 225 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-5].string));
      add_node("define-fun", make_node((yyvsp[-5].string)), make_node(), (yyvsp[-2].curnode), (yyvsp[-1].curnode));
      free((yyvsp[-5].string));
  }
#line 1714 "parser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 231 "parser.y" /* yacc.c:1661  */
    {
     // set_new_name((yyvsp[-6].string));
      add_node("define-fun", make_node((yyvsp[-6].string)), make_node((yyvsp[-4].nodelist)), (yyvsp[-2].curnode), (yyvsp[-1].curnode));
      free((yyvsp[-6].string));
  }
#line 1724 "parser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 240 "parser.y" /* yacc.c:1661  */
    {
      int n = atoi((yyvsp[-1].string));
      for (int i = 0; i < n; ++i) {
          push_namespace();
      }
      add_node("push", make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
  }
#line 1737 "parser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 252 "parser.y" /* yacc.c:1661  */
    {
      int n = atoi((yyvsp[-1].string));
      for (int i = 0; i < n; ++i) {
          pop_namespace();
      }
      add_node("pop", make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
  }
#line 1750 "parser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 265 "parser.y" /* yacc.c:1661  */
    {
      add_node("assert", (yyvsp[-1].curnode));
  }
#line 1758 "parser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 272 "parser.y" /* yacc.c:1661  */
    {
      add_node("check-sat");
  }
#line 1766 "parser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 279 "parser.y" /* yacc.c:1661  */
    {
      add_node("get-assertions");
  }
#line 1774 "parser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 286 "parser.y" /* yacc.c:1661  */
    {
      add_node("get-unsat-core");
  }
#line 1782 "parser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 293 "parser.y" /* yacc.c:1661  */
    {
      add_node("get-proof");
  }
#line 1790 "parser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 301 "parser.y" /* yacc.c:1661  */
    {
      add_node("set-option", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1800 "parser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 307 "parser.y" /* yacc.c:1661  */
    {
      add_node("set-option", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1810 "parser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 313 "parser.y" /* yacc.c:1661  */
    {
      add_node("set-option", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1820 "parser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 319 "parser.y" /* yacc.c:1661  */
    {
      add_node("set-option", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1830 "parser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 328 "parser.y" /* yacc.c:1661  */
    {
      //add_node("get-info", make_node($3));
      free((yyvsp[-1].string));
  }
#line 1839 "parser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 337 "parser.y" /* yacc.c:1661  */
    {
      //add_node("set-info", make_node($3), make_node($4));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 1849 "parser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 347 "parser.y" /* yacc.c:1661  */
    {
      (yyval.string) = (yyvsp[0].string);
  }
#line 1857 "parser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 351 "parser.y" /* yacc.c:1661  */
    {
      (yyval.string) = (yyvsp[0].string);
  }
#line 1865 "parser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 355 "parser.y" /* yacc.c:1661  */
    {
      (yyval.string) = (yyvsp[0].string);
  }
#line 1873 "parser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 359 "parser.y" /* yacc.c:1661  */
    {
      (yyval.string) = (yyvsp[0].string);
  }
#line 1881 "parser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 366 "parser.y" /* yacc.c:1661  */
    {
      add_node("get-assignment");
  }
#line 1889 "parser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 373 "parser.y" /* yacc.c:1661  */
    {
      add_node("get-value", make_node((yyvsp[-2].nodelist)));
      delete (yyvsp[-2].nodelist);
  }
#line 1898 "parser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 381 "parser.y" /* yacc.c:1661  */
    {
      add_node("exit");
  }
#line 1906 "parser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 389 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = (yyvsp[0].curnode);
  }
#line 1914 "parser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 393 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = (yyvsp[0].curnode);
  }
#line 1922 "parser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 401 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node("!", (yyvsp[-2].curnode));
      (yyval.curnode)->add_children((yyvsp[-1].nodelist));
      delete (yyvsp[-1].nodelist);
  }
#line 1932 "parser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 411 "parser.y" /* yacc.c:1661  */
    {
      shuffle_list((yyvsp[-3].nodelist));
      (yyval.curnode) = make_node("let", make_node((yyvsp[-3].nodelist)), (yyvsp[-1].curnode));
      delete (yyvsp[-3].nodelist);
      pop_namespace();
  }
#line 1943 "parser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 418 "parser.y" /* yacc.c:1661  */
    {
      shuffle_list((yyvsp[-3].nodelist));
      (yyval.curnode) = make_node("forall", make_node((yyvsp[-3].nodelist)), (yyvsp[-1].curnode));
      delete (yyvsp[-3].nodelist);
      pop_namespace();
  }
#line 1954 "parser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 425 "parser.y" /* yacc.c:1661  */
    {
      shuffle_list((yyvsp[-3].nodelist));
      (yyval.curnode) = make_node("exists", make_node((yyvsp[-3].nodelist)), (yyvsp[-1].curnode));
      delete (yyvsp[-3].nodelist);
      pop_namespace();
  }
#line 1965 "parser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 432 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = (yyvsp[0].curnode);
  }
#line 1973 "parser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 436 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = (yyvsp[0].curnode);
  }
#line 1981 "parser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 440 "parser.y" /* yacc.c:1661  */
    {
      node *n = (yyvsp[-2].curnode);
      if (is_commutative((yyvsp[-2].curnode))) {
          shuffle_list((yyvsp[-1].nodelist));
      } else if (flip_antisymm((yyvsp[-2].curnode), &n)) {
          std::swap((*((yyvsp[-1].nodelist)))[0], (*((yyvsp[-1].nodelist)))[1]);
      }
      (yyval.curnode) = make_node(n, (yyvsp[-1].nodelist));
      if (n != (yyvsp[-2].curnode)) {
          del_node((yyvsp[-2].curnode));
      }
      delete (yyvsp[-1].nodelist);
  }
#line 1999 "parser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 458 "parser.y" /* yacc.c:1661  */
    { (yyval.curnode) = (yyvsp[0].curnode); }
#line 2005 "parser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 460 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node("as", (yyvsp[-2].curnode), (yyvsp[-1].curnode));
  }
#line 2013 "parser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 468 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2022 "parser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 473 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node("_", make_node((yyvsp[-2].string)));
      (yyval.curnode)->add_children((yyvsp[-1].nodelist));
      free((yyvsp[-2].string));
      delete (yyvsp[-1].nodelist);
  }
#line 2033 "parser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 484 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2042 "parser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 489 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2051 "parser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 494 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2060 "parser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 499 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2069 "parser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 504 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node("_", make_node((yyvsp[-2].string)), make_node((yyvsp[-1].string)));
      free((yyvsp[-1].string));
      free((yyvsp[-2].string));
  }
#line 2079 "parser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 514 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2088 "parser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 519 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2097 "parser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 528 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[-1].string), (yyvsp[0].curnode));
      (yyval.curnode)->set_parens_needed(false);
  }
#line 2106 "parser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 537 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2115 "parser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 542 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node();
  }
#line 2123 "parser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 546 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[-1].nodelist));
      delete (yyvsp[-1].nodelist);
  }
#line 2132 "parser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 554 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2141 "parser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 559 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2150 "parser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 568 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back(make_node((yyvsp[0].string)));
      free((yyvsp[0].string));
  }
#line 2160 "parser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 574 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back(make_node((yyvsp[0].string)));
      free((yyvsp[0].string));
  }
#line 2170 "parser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 584 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back(make_node((yyvsp[0].string)));
      free((yyvsp[0].string));
  }
#line 2180 "parser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 590 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back(make_node((yyvsp[0].string)));
      free((yyvsp[0].string));
  }
#line 2190 "parser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 600 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2199 "parser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 605 "parser.y" /* yacc.c:1661  */
    {
      (yyvsp[-1].nodelist)->push_back((yyvsp[0].curnode));
      (yyval.nodelist) = (yyvsp[-1].nodelist);
  }
#line 2208 "parser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 614 "parser.y" /* yacc.c:1661  */
    {
      push_namespace();
      (yyval.nodelist) = new std::vector<node *>();
      //set_new_name((yyvsp[-2].string));
      (yyval.nodelist)->push_back(make_node((yyvsp[-2].string), (yyvsp[-1].curnode)));
      free((yyvsp[-2].string));
  }
#line 2220 "parser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 622 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-4].nodelist);
      //set_new_name((yyvsp[-2].string));
      (yyval.nodelist)->push_back(make_node((yyvsp[-2].string), (yyvsp[-1].curnode)));
      free((yyvsp[-2].string));
  }
#line 2231 "parser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 632 "parser.y" /* yacc.c:1661  */
    {
      push_namespace();
  }
#line 2239 "parser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 640 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2248 "parser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 645 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2257 "parser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 653 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[-2].string));
      (yyval.curnode) = make_node((yyvsp[-2].string), (yyvsp[-1].curnode));
      free((yyvsp[-2].string));
  }
#line 2267 "parser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 663 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2276 "parser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 668 "parser.y" /* yacc.c:1661  */
    {
      char *tmp = (char *)(malloc(strlen((yyvsp[-3].string)) + strlen((yyvsp[-1].string)) + 2 + 1));
      sprintf(tmp, "%s[%s]", (yyvsp[-3].string), (yyvsp[-1].string));
      (yyval.curnode) = make_node(tmp);
      free(tmp);
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
  }
#line 2289 "parser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 681 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2298 "parser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 686 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2307 "parser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 695 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2316 "parser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 700 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node("_", make_node((yyvsp[-2].string)));
      (yyval.curnode)->add_children((yyvsp[-1].nodelist));
      delete (yyvsp[-1].nodelist);
      free((yyvsp[-2].string));
  }
#line 2327 "parser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 707 "parser.y" /* yacc.c:1661  */
    {
      (yyval.curnode) = make_node((yyvsp[-2].string));
      (yyval.curnode)->add_children((yyvsp[-1].nodelist));
      (yyval.curnode)->set_parens_needed(true);
      delete (yyvsp[-1].nodelist);
      free((yyvsp[-2].string));
  }
#line 2339 "parser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 719 "parser.y" /* yacc.c:1661  */
    {
      push_namespace();
      (yyval.nodelist) = new std::vector<node *>();
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2349 "parser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 725 "parser.y" /* yacc.c:1661  */
    {
      (yyval.nodelist) = (yyvsp[-1].nodelist);
      (yyval.nodelist)->push_back((yyvsp[0].curnode));
  }
#line 2358 "parser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 733 "parser.y" /* yacc.c:1661  */
    {
      //set_new_name((yyvsp[0].string));
      (yyval.curnode) = make_node((yyvsp[0].string));
      free((yyvsp[0].string));
  }
#line 2368 "parser.cpp" /* yacc.c:1661  */
    break;


#line 2372 "parser.cpp" /* yacc.c:1661  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 741 "parser.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
    std::cerr << "ERROR: " << s << std::endl;
    exit(1);
}
