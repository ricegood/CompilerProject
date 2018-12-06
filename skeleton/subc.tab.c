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
#line 1 "subc.y" /* yacc.c:339  */

/*
 * File Name   : subc.y
 * Description : a skeleton bison input
 */

#include "subc.h"
#include "subc.tab.h"

int    yylex ();
int    yyerror (char* s);
void   REDUCE(char* s);

int num_of_err_message = 0; /* for print only 1 error for 1 line */

/* flag for subc.y */
int is_func_decl = 0; /* for scope stack management about block inside of function */
int block_number = 0; /* for scope stack management about block inside of function */
int start_param_parsing = 1; /* for prevent from conflicts. */

#line 87 "subc.tab.c" /* yacc.c:339  */

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
   by #include "subc.tab.h".  */
#ifndef YY_YY_SUBC_TAB_H_INCLUDED
# define YY_YY_SUBC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LOGICAL_OR = 258,
    LOGICAL_AND = 259,
    EQUOP = 260,
    RELOP = 261,
    INCOP = 262,
    DECOP = 263,
    STRUCTOP = 264,
    ELSE = 265,
    STRUCT = 266,
    RETURN = 267,
    IF = 268,
    WHILE = 269,
    FOR = 270,
    BREAK = 271,
    CONTINUE = 272,
    CHAR_CONST = 273,
    STRING = 274,
    INTEGER_CONST = 275,
    ID = 276,
    TYPE = 277,
    VOID = 278,
    NULL_TOKEN = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "subc.y" /* yacc.c:355  */

    int intVal;
    char *stringVal;
    struct id *idptr;
    struct decl *declptr;
    struct ste *steptr;

#line 160 "subc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 177 "subc.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    13,     2,     2,     2,     2,     7,     2,
      18,    19,    12,    10,     3,    11,    20,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,     2,    17,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     5,     6,
       8,     9,    14,    15,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    87,    98,   111,   115,
     114,   149,   150,   151,   155,   159,   154,   169,   182,   210,
     238,   273,   274,   277,   278,   281,   297,   315,   318,   321,
     332,   343,   344,   360,   366,   359,   379,   382,   383,   386,
     387,   388,   395,   402,   403,   404,   405,   406,   407,   408,
     413,   414,   421,   420,   456,   459,   462,   474,   477,   480,
     492,   495,   510,   530,   540,   550,   570,   575,   579,   586,
     590,   594,   627,   637,   647,   657,   667,   677,   687,   708,
     722,   727,   738,   749,   773,   787,   793,   803,   812
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "','", "'='", "LOGICAL_OR",
  "LOGICAL_AND", "'&'", "EQUOP", "RELOP", "'+'", "'-'", "'*'", "'!'",
  "INCOP", "DECOP", "'['", "']'", "'('", "')'", "'.'", "STRUCTOP", "ELSE",
  "STRUCT", "RETURN", "IF", "WHILE", "FOR", "BREAK", "CONTINUE",
  "CHAR_CONST", "STRING", "INTEGER_CONST", "ID", "TYPE", "VOID",
  "NULL_TOKEN", "';'", "'{'", "'}'", "$accept", "program", "ext_def_list",
  "ext_def", "$@1", "type_specifier", "struct_specifier", "$@2", "@3",
  "func_decl", "pointers", "param_list", "param_decl", "def_list", "def",
  "compound_stmt", "$@4", "$@5", "local_defs", "stmt_list", "stmt",
  "expr_e", "expr", "$@6", "or_expr", "or_list", "and_expr", "and_list",
  "binary", "unary", "codegen", "args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    44,    61,   258,   259,    38,   260,   261,
      43,    45,    42,    33,   262,   263,    91,    93,    40,    41,
      46,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,    59,   123,   125
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
    -136,    18,   -20,  -136,    -6,  -136,  -136,  -136,    -8,  -136,
       7,    31,  -136,  -136,    61,  -136,    50,  -136,    34,  -136,
    -136,  -136,   162,    -3,  -136,  -136,   -20,   162,   162,   162,
     162,   162,   162,   162,  -136,  -136,  -136,  -136,  -136,   167,
    -136,    65,    83,    51,  -136,   -20,  -136,    -7,    69,    67,
    -136,   201,   201,   201,   201,   201,   201,    95,  -136,   127,
    -136,   137,   109,    62,  -136,  -136,   162,   108,  -136,   118,
     119,  -136,   122,   -20,  -136,  -136,  -136,   128,  -136,  -136,
    -136,   162,   162,   162,   162,   162,   162,  -136,  -136,   143,
      71,  -136,   135,  -136,  -136,   148,  -136,    10,    35,  -136,
     201,   109,    46,    57,  -136,  -136,   162,  -136,  -136,  -136,
      55,   162,   126,   152,   154,   160,   142,   149,  -136,  -136,
    -136,  -136,   153,   162,  -136,  -136,   162,  -136,   185,  -136,
     159,   162,   162,   162,  -136,  -136,  -136,   193,  -136,  -136,
    -136,   170,   172,   175,  -136,   181,    98,    98,   162,  -136,
     182,  -136,   183,    98,   162,  -136,   178,    98,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    11,    12,     3,    22,    13,
       9,    17,    21,     8,     0,     7,     0,    14,     0,    33,
      10,    28,     0,     0,     5,    28,    15,     0,     0,     0,
       0,     0,     0,     0,    69,    70,    68,    71,    85,     0,
      18,    12,    22,     0,    23,    36,    34,    22,     0,     0,
      27,    78,    72,    79,    73,    76,    77,     0,    54,    55,
      57,    58,    60,    65,    74,    75,     0,     0,    86,     0,
       0,    19,     0,     0,    20,    38,    31,     0,    16,    32,
      66,     0,     0,     0,     0,     0,     0,    52,    67,     0,
      65,     6,     0,    81,    82,    25,    24,     0,     0,    56,
      65,    59,    62,    61,    63,    64,     0,    80,    84,    87,
       0,     0,     0,     0,     0,     0,     0,     0,    43,    35,
      40,    37,     0,     0,    29,    53,     0,    83,     0,    41,
       0,     0,     0,    51,    48,    49,    39,     0,    88,    26,
      42,     0,     0,     0,    50,     0,     0,     0,    51,    30,
      44,    46,     0,     0,    51,    45,     0,     0,    47
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,  -136,  -136,     0,  -136,  -136,  -136,   226,
      59,  -136,   156,   205,  -136,   215,  -136,  -136,  -136,  -136,
     -50,  -135,   -33,  -136,  -136,  -136,   151,  -136,   141,   -21,
    -136,  -136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    42,     9,    21,    48,    49,
      14,    43,    44,    26,    50,   120,    25,    75,    46,    97,
     121,   143,   122,   106,    58,    59,    60,    61,    62,    90,
      92,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    39,     8,     4,    12,    12,    51,    52,    53,    54,
      55,    56,    63,   152,     5,     6,    40,    27,     3,   156,
       4,    28,    29,    30,    31,    32,    47,    11,    33,    13,
      76,     5,    41,    89,   112,   113,   114,   115,   116,   117,
      34,    35,    36,    37,    15,    47,    38,   118,    19,   119,
      22,   123,    23,    23,    73,    84,    85,    86,   126,   109,
     100,   100,   100,   100,   100,   100,    87,    85,    86,    17,
      74,    24,   124,   125,   127,    87,    64,    65,    66,   130,
      68,    88,    69,    70,    71,    64,    65,    66,    19,    68,
     128,    69,    70,   138,    18,    12,   150,   151,   141,   142,
     144,    72,   137,   155,    79,    27,    77,   158,    78,    28,
      29,    30,    31,    32,    80,   144,    33,    83,    84,    85,
      86,   144,   112,   113,   114,   115,   116,   117,    34,    35,
      36,    37,    81,    27,    38,   118,    19,    28,    29,    30,
      31,    32,    27,    82,    33,    91,    28,    29,    30,    31,
      32,    93,    94,    33,   108,    95,    34,    35,    36,    37,
     107,    98,    38,   129,   111,    34,    35,    36,    37,    27,
     131,    38,   132,    28,    29,    30,    31,    32,   133,   134,
      33,    64,    65,    66,    67,    68,   135,    69,    70,   146,
     136,   147,    34,    35,    36,    37,   140,   157,    38,    64,
      65,    66,   139,    68,   153,    69,    70,    64,    65,    66,
     145,    68,   148,    69,    70,    64,    65,    66,   149,    68,
     154,    69,    70,   101,   102,   103,   104,   105,    10,    96,
      45,    20,    99
};

static const yytype_uint8 yycheck[] =
{
      33,    22,     2,    23,    12,    12,    27,    28,    29,    30,
      31,    32,    33,   148,    34,    35,    19,     7,     0,   154,
      23,    11,    12,    13,    14,    15,    26,    33,    18,    37,
      37,    34,    35,    66,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    37,    45,    36,    37,    38,    39,
      16,    16,    18,    18,     3,     9,    10,    11,     3,    92,
      81,    82,    83,    84,    85,    86,     4,    10,    11,    38,
      19,    37,    37,   106,    19,     4,    14,    15,    16,   112,
      18,    19,    20,    21,    19,    14,    15,    16,    38,    18,
     111,    20,    21,   126,    33,    12,   146,   147,   131,   132,
     133,    42,   123,   153,    37,     7,    47,   157,    39,    11,
      12,    13,    14,    15,    19,   148,    18,     8,     9,    10,
      11,   154,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,     5,     7,    36,    37,    38,    11,    12,    13,
      14,    15,     7,     6,    18,    37,    11,    12,    13,    14,
      15,    33,    33,    18,    19,    33,    30,    31,    32,    33,
      17,    33,    36,    37,    16,    30,    31,    32,    33,     7,
      18,    36,    18,    11,    12,    13,    14,    15,    18,    37,
      18,    14,    15,    16,    17,    18,    37,    20,    21,    19,
      37,    19,    30,    31,    32,    33,    37,    19,    36,    14,
      15,    16,    17,    18,    22,    20,    21,    14,    15,    16,
      17,    18,    37,    20,    21,    14,    15,    16,    37,    18,
      37,    20,    21,    82,    83,    84,    85,    86,     2,    73,
      25,    16,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,    23,    34,    35,    43,    45,    46,
      49,    33,    12,    37,    50,    37,    44,    38,    33,    38,
      55,    47,    16,    18,    37,    56,    53,     7,    11,    12,
      13,    14,    15,    18,    30,    31,    32,    33,    36,    69,
      19,    35,    45,    51,    52,    53,    58,    45,    48,    49,
      54,    69,    69,    69,    69,    69,    69,    62,    64,    65,
      66,    67,    68,    69,    14,    15,    16,    17,    18,    20,
      21,    19,    50,     3,    19,    57,    37,    50,    39,    37,
      19,     5,     6,     8,     9,    10,    11,     4,    19,    62,
      69,    37,    70,    33,    33,    33,    52,    59,    33,    66,
      69,    68,    68,    68,    68,    68,    63,    17,    19,    62,
      71,    16,    24,    25,    26,    27,    28,    29,    37,    39,
      55,    60,    62,    16,    37,    62,     3,    19,    69,    37,
      62,    18,    18,    18,    37,    37,    37,    69,    62,    17,
      37,    62,    62,    61,    62,    17,    19,    19,    37,    37,
      60,    60,    61,    22,    37,    60,    61,    19,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      43,    45,    45,    45,    47,    48,    46,    46,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    56,    57,    55,    58,    59,    59,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    63,    62,    62,    64,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     0,
       3,     1,     1,     1,     0,     0,     7,     2,     5,     6,
       6,     1,     0,     1,     3,     3,     6,     2,     0,     4,
       7,     2,     2,     0,     0,     6,     1,     2,     0,     2,
       1,     2,     3,     1,     5,     7,     5,     9,     2,     2,
       1,     0,     0,     4,     1,     1,     3,     1,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     3,     3,     5,     4,     1,     0,     1,     3
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
        case 5:
#line 77 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr)) {
                if ((yyvsp[-2].intVal) == 0) // no pointer
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl((yyvsp[-3].declptr)));
                else // pointer
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl(makeptrdecl((yyvsp[-3].declptr))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1386 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-6].declptr) && (yyvsp[-2].declptr)) {
                if ((yyvsp[-5].intVal) == 0) // no pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl((yyvsp[-6].declptr)))));
                else // pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1401 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 99 "subc.y" /* yacc.c:1646  */
    {   
            /* code generation */
            labelname = (yyvsp[-1].declptr)->id->name;
            LABEL(labelname);
            FUNC_LABEL(labelname, "start");
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
        }
#line 1418 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "subc.y" /* yacc.c:1646  */
    {
        }
#line 1425 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 115 "subc.y" /* yacc.c:1646  */
    {   
            pushscope();
            pushstelist((yyvsp[0].declptr)->formalswithreturnid);
            is_func_decl = 1;
            block_number = 0;

            /* code generation */
            labelname = (yyvsp[0].declptr)->id->name;
            top->sumofsize = 0; // reset after pushstelist
            LABEL(labelname);
        }
#line 1441 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "subc.y" /* yacc.c:1646  */
    {
            is_func_decl = 0;
            block_number = 0;
            struct ste *pop = popscope();

            /* [TODO] delete pop using loop (for prevent from memory leak) */

            /* code generation */
            labelname = (yyvsp[-2].declptr)->id->name;
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
            if (strcmp(labelname,"main") == 0) {
                // in main function, set global variable memory size
                printf("\tLglob. data %d\n", globalscope->sumofsize);
            }
        }
#line 1466 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 155 "subc.y" /* yacc.c:1646  */
    {
            pushscope();
        }
#line 1474 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 159 "subc.y" /* yacc.c:1646  */
    {
            struct ste *fields = popscope();
            decl *structdecl = makestructdecl(fields);
            declare((yyvsp[-3].idptr), structdecl);
            (yyval.declptr) = structdecl;
        }
#line 1485 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 166 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1493 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "subc.y" /* yacc.c:1646  */
    {   
            struct decl *decl_ptr = findstructdecl((yyvsp[0].idptr));
            if (check_is_struct_type(decl_ptr)) {
                (yyval.declptr) = decl_ptr;
            }
            else {
                (yyval.declptr) = NULL;
                ERROR("incomplete type error");
            }
        }
#line 1508 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 183 "subc.y" /* yacc.c:1646  */
    {
            struct decl *procdecl = makeprocdecl();
            if ((yyvsp[-4].declptr)) {
                declare((yyvsp[-2].idptr), procdecl);
            }
            pushscope(); /* for collecting formals */

            if ((yyvsp[-3].intVal) == 0) // no pointer
                declare(returnid, (yyvsp[-4].declptr));
            else // pointer
                declare(returnid, makeptrdecl((yyvsp[-4].declptr)));

            /* no formals */
            struct ste *formals;
            formals = popscope();

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev; // null in this production
            
            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            (yyval.declptr) = procdecl;
        }
#line 1540 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 211 "subc.y" /* yacc.c:1646  */
    {
            struct decl *procdecl = makeprocdecl();
            if ((yyvsp[-5].declptr)) {
                declare((yyvsp[-3].idptr), procdecl);
            }
            pushscope(); /* for collecting formals */

            if ((yyvsp[-4].intVal) == 0) // no pointer
                declare(returnid, (yyvsp[-5].declptr));
            else // pointer
                declare(returnid, makeptrdecl((yyvsp[-5].declptr)));

            /* no formals */
            struct ste *formals;
            formals = popscope();

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev; // null in this production
            
            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            (yyval.declptr) = procdecl;
        }
#line 1572 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 239 "subc.y" /* yacc.c:1646  */
    {   
            struct ste *formals;
            struct ste *returntype;
            struct decl *procdecl;
            formals = popscope();
            procdecl = makeprocdecl();

            if ((yyvsp[-5].declptr)) {
                declare((yyvsp[-3].idptr), procdecl);
            }

            pushscope(); /* for collecting returnid */
            if ((yyvsp[-4].intVal) == 0) // no pointer
                declare(returnid, (yyvsp[-5].declptr));
            else // pointer
                declare(returnid, makeptrdecl((yyvsp[-5].declptr)));
            returntype = popscope();
            returntype->prev = formals;
            formals = returntype;

            /* formals->decl is always returnid decl with return type*/
            procdecl->formalswithreturnid = formals;
            procdecl->returntype = formals->decl;
            procdecl->formals = formals->prev;

            /* error ; struct_specifier returns NULL, because this is not a struct*/
            if (procdecl->returntype == NULL)
                ERROR("incomplete type error");

            (yyval.declptr) = procdecl; 
            start_param_parsing = 1;
        }
#line 1609 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 273 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 1; }
#line 1615 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 0; }
#line 1621 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 282 "subc.y" /* yacc.c:1646  */
    {      
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ((yyvsp[-2].declptr)) {
                if ((yyvsp[-1].intVal) == 0) // no pointer
                    declare((yyvsp[0].idptr), (yyval.declptr) = makevardecl((yyvsp[-2].declptr)));
                else // pointer
                    declare((yyvsp[0].idptr), (yyval.declptr) = makevardecl(makeptrdecl((yyvsp[-2].declptr))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1641 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 298 "subc.y" /* yacc.c:1646  */
    {
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ((yyvsp[-5].declptr) && (yyvsp[-1].declptr)) {
                if ((yyvsp[-4].intVal) == 0) // no pointer
                    declare((yyvsp[-3].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-1].declptr)->value, makevardecl((yyvsp[-5].declptr)))));
                else // pointer
                    declare((yyvsp[-3].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-1].declptr)->value, makevardecl(makeptrdecl((yyvsp[-5].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1661 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 316 "subc.y" /* yacc.c:1646  */
    {
        }
#line 1668 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 322 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr)) {
                if ((yyvsp[-2].intVal) == 0) // no pointer
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl((yyvsp[-3].declptr)));
                else // pointer 
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl(makeptrdecl((yyvsp[-3].declptr))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1683 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 333 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-6].declptr) && (yyvsp[-2].declptr)) {
                if ((yyvsp[-5].intVal) == 0) // no pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl((yyvsp[-6].declptr)))));
                else // pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1698 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 345 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            labelname = (yyvsp[-1].declptr)->id->name;
            LABEL(labelname);
            FUNC_LABEL(labelname, "start");
            FUNC_LABEL(labelname, "final");
            CODE("push_reg fp");
            CODE("pop_reg sp");
            CODE("pop_reg fp");
            CODE("pop_reg pc");
            FUNC_LABEL(labelname, "end");
        }
#line 1715 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 360 "subc.y" /* yacc.c:1646  */
    {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
        }
#line 1725 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 366 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            printf("\tshift_sp %d\n", top->sumofsize);
            FUNC_LABEL(labelname, "start");
        }
#line 1735 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 372 "subc.y" /* yacc.c:1646  */
    {
            block_number--;
            if (!is_func_decl || block_number > 0)
                popscope();
        }
#line 1745 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 389 "subc.y" /* yacc.c:1646  */
    {
            if (!check_same_type(findcurrentdecl(returnid), voidtype)) {
                /* return type check */
                ERROR("return type was not matched");
            }
        }
#line 1756 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 396 "subc.y" /* yacc.c:1646  */
    {   
            if ((yyvsp[-1].declptr) && !check_same_type(findcurrentdecl(returnid), (yyvsp[-1].declptr))) {
                /* return type check */
                ERROR("return type was not matched");
            }
        }
#line 1767 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 421 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            CODE("push_reg sp");
            CODE("fetch");
        }
#line 1777 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 427 "subc.y" /* yacc.c:1646  */
    {
            /* assignment operation */
            /* should have same type (ppt 23p) & not const! (=>check_is_var) */
            if ((yyvsp[-3].declptr)) {
                if (check_is_var((yyvsp[-3].declptr))) {
                    if (check_same_type_for_unary((yyvsp[-3].declptr), (yyvsp[0].declptr)))
                        (yyval.declptr) = (yyvsp[-3].declptr)->type;
                    else {
                        if ((yyvsp[0].declptr) == nulltype) 
                            ERROR("RHS is not a const or variable");
                        else
                            ERROR("LHS and RHS are not same type");
                        (yyval.declptr) = NULL;
                    }
                }
                else {
                    ERROR("LHS is not a variable");
                    (yyval.declptr) = NULL;
                }
            }
            else
                (yyval.declptr) = NULL;


            /* code generation */
            CODE("assign");
            CODE("fetch");
            CODE("shift_sp -1");
        }
#line 1811 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 463 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2].declptr) && (yyvsp[0].declptr)) {
                /* only for int type */
                if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                    (yyval.declptr) = inttype;
                else
                    ERROR("not int type");
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1827 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 481 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2].declptr) && (yyvsp[0].declptr)) {
                /* only for int type */
                if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                    (yyval.declptr) = inttype;
                else
                    ERROR("not int type");
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1843 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 496 "subc.y" /* yacc.c:1646  */
    {   
            if (!(check_same_type((yyvsp[-2].declptr), chartype) || check_same_type((yyvsp[-2].declptr), inttype)) || !(check_same_type((yyvsp[0].declptr), chartype) || check_same_type((yyvsp[0].declptr), inttype))) {
                ERROR("not int or char type");
            }

            /* char RELOP char or int RELOP int */
            else if (check_same_type((yyvsp[-2].declptr), (yyvsp[0].declptr)))
                (yyval.declptr) = inttype;

            /* ERROR */
            else {
                ERROR("not comparable");
            }
        }
#line 1862 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 511 "subc.y" /* yacc.c:1646  */
    {   
            if (check_is_array((yyvsp[-2].declptr)) && check_is_array((yyvsp[0].declptr)) && check_same_type((yyvsp[-2].declptr)->elementvar->type, (yyvsp[0].declptr)->elementvar->type)) {
                /* for array EQUOP array */
                (yyval.declptr) = inttype;
            }

            else if (!(check_same_type((yyvsp[-2].declptr), chartype) || check_same_type((yyvsp[-2].declptr), inttype) || check_is_pointer_type((yyvsp[-2].declptr)) || check_is_array((yyvsp[-2].declptr))) || !(check_same_type((yyvsp[0].declptr), chartype) || check_same_type((yyvsp[0].declptr), inttype) || check_is_pointer_type((yyvsp[0].declptr)) || check_is_array((yyvsp[0].declptr)))) {
                ERROR("not int or char type");
            }

            /* char EQUOP char or int EQUOP int or pointer(same type) EQUOP pointer(same type) */
            else if (check_same_type((yyvsp[-2].declptr), (yyvsp[0].declptr)))
                (yyval.declptr) = inttype;

            /* ERROR */
            else {
                ERROR("not comparable");
            }
        }
#line 1886 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 531 "subc.y" /* yacc.c:1646  */
    {
            /* only for int+int */
            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1900 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 541 "subc.y" /* yacc.c:1646  */
    {
            /* only for int+int */
            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1914 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 551 "subc.y" /* yacc.c:1646  */
    {   
            if ((yyvsp[0].declptr) && (yyvsp[0].declptr)->type)
                (yyval.declptr) = (yyvsp[0].declptr)->type;
            else if ((yyvsp[0].declptr) == nulltype) {
                (yyval.declptr) = nulltype;
            }
            else {
                (yyval.declptr) = NULL;
            }

            /* code generation */
            // [TODO] is it work at array well????
            // this code is for prevent from such as const_int fetch
            // fetch only "unary->ID" reduce case. (same condition!)
            if (check_is_var((yyvsp[0].declptr)) || check_is_array((yyvsp[0].declptr)->type))
                CODE("fetch");
        }
#line 1936 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 571 "subc.y" /* yacc.c:1646  */
    {
            /* expr is type decl and unary is just decl => Make constdecl to solve this problem */
            (yyval.declptr) = makeconstdecl((yyvsp[-1].declptr));
        }
#line 1945 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 576 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1953 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 580 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = makeintconstdecl(inttype, (yyvsp[0].intVal));

            /* code generation */
            printf("\tpush_const %d\n", (yyval.declptr)->value);
        }
#line 1964 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 587 "subc.y" /* yacc.c:1646  */
    {   
            (yyval.declptr) = makeconstdecl(chartype);
        }
#line 1972 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 591 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = makeconstdecl(stringtype);
        }
#line 1980 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 594 "subc.y" /* yacc.c:1646  */
    {
            /* find ID */
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
            if (!(yyval.declptr))
                ERROR("not declared");

            /* code generation */
            // push address
            if (check_is_var((yyval.declptr)) || check_is_array((yyval.declptr)->type)) {
                switch (check_variable_scope((yyval.declptr))) {
                    case GLOBAL:
                        CODE("push_const Lglob");
                        printf("\tpush_const %d\n", (yyval.declptr)->offset);
                        CODE("add");
                        break;

                    case PARAM:
                        CODE("push_reg FP");
                        printf("\tpush_const %d\n", 1 + (yyval.declptr)->offset);
                        CODE("add");
                        break;

                    case LOCAL:
                        CODE("push_reg FP");
                        printf("\tpush_const %d\n", 1 + (yyval.declptr)->scope->sumofparams + (yyval.declptr)->offset);
                        CODE("add");
                        break;

                    default:
                        break;
                }
            }
        }
#line 2018 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 628 "subc.y" /* yacc.c:1646  */
    {   
            /* only integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 2032 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 638 "subc.y" /* yacc.c:1646  */
    {
            /* only for int type */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = inttype;
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 2046 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 648 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2060 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 658 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2074 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 668 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2088 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 678 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2102 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 688 "subc.y" /* yacc.c:1646  */
    {
            /*
                if use '&', unary becomes pointer type value.
                ex) int* a -> &a -> int**
                ex2) int a -> &a -> int*
            */
            if ((yyvsp[0].declptr)) {
                if (check_is_var((yyvsp[0].declptr))) {
                    /* '&value' can't be LHS */
                    (yyval.declptr) = makeconstdecl(makeptrdecl((yyvsp[0].declptr)->type));
                }
                else {
                    ERROR("not variable");
                    (yyval.declptr) = NULL;
                }
            }
            else
                (yyval.declptr) = NULL;
            
        }
#line 2127 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 709 "subc.y" /* yacc.c:1646  */
    {   
            if((yyvsp[0].declptr)) {
                if (check_is_pointer_type((yyvsp[0].declptr)->type)) {
                    (yyval.declptr) = makevardecl((yyvsp[0].declptr)->type->ptrto);
                }
                else {
                    ERROR("not a pointer");
                    (yyval.declptr) = NULL;
                }
            }
            else
                (yyval.declptr) = NULL;
        }
#line 2145 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 723 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr))
                (yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));
        }
#line 2154 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 728 "subc.y" /* yacc.c:1646  */
    {
            /* This is only for structure type on $1 */
            if ((yyvsp[-2].declptr) && !check_is_pointer_type((yyvsp[-2].declptr)->type)){
                (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            }
            else {
                ERROR("variable is not struct");
                (yyval.declptr) = NULL;
            }
        }
#line 2169 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 739 "subc.y" /* yacc.c:1646  */
    {
            /* this is only for pointer to structure type on $1 */
            if ((yyvsp[-2].declptr) && check_is_pointer_type((yyvsp[-2].declptr)->type)){
                (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            }
            else {
                ERROR("not a pointer");
                (yyval.declptr) = NULL;
            }
        }
#line 2184 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 750 "subc.y" /* yacc.c:1646  */
    {
            /*
                function call!
                args pointer last pushed args.
                args->elementvar field pointer first pushed args.
            */

            if (check_is_proc((yyvsp[-4].declptr))) {
                if ((yyvsp[-1].declptr))
                    (yyval.declptr) = check_function_call((yyvsp[-4].declptr), (yyvsp[-1].declptr)->elementvar);
            }
            else
                ERROR ("not a function");

            /* code generation */
            // push the actual parameters on the stack in 'args' reducing procedure
            CODE("push_reg sp"); // FP = SP
            printf("\tpush_const -%d\n", sumofargs);
            CODE("add");
            CODE("pop_reg fp");
            printf("\tjump %s\n", (yyvsp[-4].declptr)->id->name); // Then, jump
            printf("label_%d:\n", labelnumber); // print label
        }
#line 2212 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 774 "subc.y" /* yacc.c:1646  */
    {
            if (check_is_proc((yyvsp[-3].declptr)))
                (yyval.declptr) = check_function_call((yyvsp[-3].declptr), NULL);
            else
                ERROR ("not a function");

            /* code generation */
            // caller convention
            // no actual parameters
            CODE("push_reg sp"); // FP = SP
            CODE("pop_reg fp");
            printf("\tjump %s\n", (yyvsp[-3].declptr)->id->name); // Then, jump
        }
#line 2230 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 788 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = nulltype;
        }
#line 2238 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 793 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            // caller convention
            CODE("shift_sp 1"); // push a hole for return value
            printf("\tpush_const label_%d\n", new_label()); // push the return address
            CODE("push_reg fp"); // push the old FP
            sumofargs = 0; // reset
        }
#line 2251 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 804 "subc.y" /* yacc.c:1646  */
    {
            /* expr semantic value type is TYPEDECL */
            (yyval.declptr) = makeconstdecl((yyvsp[0].declptr));
            (yyval.declptr)->elementvar = (yyval.declptr); /* to save first args pointer. */

            /* code generation */
            sumofargs += (yyvsp[0].declptr)->size; // set global variable for caller convention
        }
#line 2264 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 813 "subc.y" /* yacc.c:1646  */
    {
            if ((yyval.declptr) && (yyvsp[-2].declptr)) {
                (yyvsp[-2].declptr)->next = makeconstdecl((yyvsp[0].declptr));
                (yyvsp[-2].declptr)->next->elementvar = (yyval.declptr)->elementvar;
                (yyval.declptr) = (yyvsp[-2].declptr)->next;
            }
            else
                (yyval.declptr) = NULL;

            /* code generation */
            sumofargs += (yyvsp[-2].declptr)->size; // set global variable for caller convention
        }
#line 2281 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2285 "subc.tab.c" /* yacc.c:1646  */
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
#line 826 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void REDUCE(char* s) {
    printf("%s\n",s);
}

void ERROR(char* s) {
    int lineno = read_line();

    /* print only 1 error message by 1 line */
    if (num_of_err_message < lineno) {
        printf("%s:%d: error:%s\n", filename, read_line(), s);
        num_of_err_message = lineno;
    }
}

void CODE(char *s) {
    printf("\t%s\n",s);
}

void LABEL(char *s) {
    printf("%s:\n",s);
}

void FUNC_LABEL(char *func_name, char *label) {
    printf("%s_%s:\n", func_name, label);
}

int new_label() {
    return ++labelnumber;
}
