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

int num_of_err_message = 0; // print only 1 error for 1 line

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
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

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
       0,    67,    67,    71,    72,    76,    88,   100,   104,   109,
     108,   127,   128,   129,   133,   143,   132,   157,   170,   199,
     228,   265,   266,   269,   270,   273,   290,   309,   313,   316,
     328,   340,   346,   353,   352,   368,   371,   372,   375,   376,
     377,   381,   388,   389,   390,   391,   392,   393,   394,   399,
     400,   403,   406,   430,   433,   436,   448,   451,   454,   466,
     469,   484,   499,   511,   523,   537,   543,   547,   551,   556,
     562,   568,   578,   588,   598,   608,   618,   628,   650,   664,
     669,   680,   691,   705,   712,   719,   725
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
  "ext_def", "$@1", "type_specifier", "struct_specifier", "@2", "@3",
  "func_decl", "pointers", "param_list", "param_decl", "def_list", "def",
  "compound_stmt", "$@4", "local_defs", "stmt_list", "stmt", "expr_e",
  "const_expr", "expr", "or_expr", "or_list", "and_expr", "and_list",
  "binary", "unary", "args", YY_NULLPTR
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

#define YYPACT_NINF -134

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-134)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -134,    22,   156,  -134,   -32,  -134,  -134,  -134,     1,  -134,
     -14,    -1,  -134,  -134,    17,  -134,    18,  -134,    50,  -134,
    -134,  -134,   122,   149,  -134,  -134,   156,   122,   122,   122,
     122,   122,   122,   122,  -134,  -134,  -134,  -134,  -134,    63,
    -134,  -134,    80,  -134,    84,   197,   155,  -134,    73,    86,
      62,  -134,   156,  -134,    12,    64,    71,  -134,   178,   178,
     178,   178,   178,   178,    90,   146,    79,   122,   122,   122,
     122,   122,   122,   122,  -134,  -134,   122,   113,    89,   105,
    -134,   106,   156,  -134,     3,  -134,   108,  -134,  -134,  -134,
    -134,  -134,  -134,   178,   197,   171,    52,  -134,  -134,  -134,
     100,  -134,  -134,    88,  -134,  -134,   126,  -134,    82,   103,
     129,   130,   114,   119,  -134,  -134,  -134,  -134,   120,    51,
    -134,   122,  -134,   122,  -134,   137,   122,   122,   122,  -134,
    -134,  -134,   122,  -134,  -134,   169,  -134,   144,   168,   151,
    -134,   180,  -134,    46,    46,   122,   158,   187,  -134,   173,
    -134,    46,   122,  -134,   192,    46,  -134
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    11,    12,     3,    22,    13,
       9,    17,    21,     8,     0,     7,     0,    14,     0,    33,
      10,    28,     0,     0,     5,    28,    15,     0,     0,     0,
       0,     0,     0,     0,    68,    69,    67,    70,    84,     0,
      51,    53,    54,    56,    57,    59,    64,    18,    12,    22,
       0,    23,    35,    37,    22,     0,     0,    27,    77,    71,
      78,    72,    75,    76,     0,    64,     0,     0,     0,     0,
       0,     0,     0,     0,    73,    74,     0,     0,     0,     0,
      19,     0,     0,    20,     0,    31,     0,    16,    32,    65,
      66,     6,    55,    64,    58,    61,    60,    62,    63,    52,
       0,    83,    85,     0,    80,    81,    25,    24,     0,     0,
       0,     0,     0,     0,    42,    34,    39,    36,     0,     0,
      79,     0,    82,     0,    40,     0,     0,     0,    50,    47,
      48,    38,     0,    29,    86,     0,    41,     0,     0,     0,
      49,     0,    26,     0,     0,    50,     0,    43,    45,     0,
      30,     0,    50,    44,     0,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,  -134,  -134,     0,  -134,  -134,  -134,   210,
     -29,  -134,   131,   189,  -134,   199,  -134,  -134,  -134,    34,
    -133,   -21,   -22,  -134,  -134,   150,  -134,   132,   -24,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    16,    49,     9,    21,    55,    56,
      14,    50,    51,    26,    57,   116,    25,    53,    84,   117,
     139,    39,   118,    41,    42,    43,    44,    45,    46,   103
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    11,     8,    58,    59,    60,    61,    62,    63,    65,
      27,    64,   149,    12,    28,    29,    30,    31,    32,   154,
      81,    33,     3,    15,    12,    86,    54,   108,   109,   110,
     111,   112,   113,    34,    35,    36,    37,    17,    13,    38,
     114,    19,   115,    93,    93,    93,    93,    93,    93,    85,
      18,    99,    54,    27,   100,   102,    19,    28,    29,    30,
      31,    32,    71,    72,    33,    82,    22,   132,    23,    23,
     108,   109,   110,   111,   112,   113,    34,    35,    36,    37,
      66,    83,    38,   114,    19,    67,   125,    24,   133,    27,
      68,   121,    80,    28,    29,    30,    31,    32,    12,   134,
      33,    40,   135,    87,   137,   138,   140,   122,    88,    89,
      40,   141,    34,    35,    36,    37,    91,   120,    38,   124,
      27,   126,   104,   140,    28,    29,    30,    31,    32,    27,
     140,    33,   101,    28,    29,    30,    31,    32,   105,   106,
      33,   119,   123,    34,    35,    36,    37,   127,   128,    38,
      73,   129,    34,    35,    36,    37,   130,   131,    38,    73,
      74,    75,    76,   143,    77,    90,    78,    79,    47,    74,
      75,    76,     4,    77,   136,    78,    79,   147,   148,     4,
      70,    71,    72,     5,    48,   153,   142,   144,   145,   156,
       5,     6,    74,    75,    76,   150,    77,   146,    78,    79,
      94,    95,    96,    97,    98,    69,    70,    71,    72,   151,
     152,   155,    10,   107,    52,    20,     0,    92
};

static const yytype_int16 yycheck[] =
{
      22,    33,     2,    27,    28,    29,    30,    31,    32,    33,
       7,    33,   145,    12,    11,    12,    13,    14,    15,   152,
      49,    18,     0,    37,    12,    54,    26,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    38,    37,    36,
      37,    38,    39,    67,    68,    69,    70,    71,    72,    37,
      33,    73,    52,     7,    76,    77,    38,    11,    12,    13,
      14,    15,    10,    11,    18,     3,    16,    16,    18,    18,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      17,    19,    36,    37,    38,     5,   108,    37,    37,     7,
       6,     3,    19,    11,    12,    13,    14,    15,    12,   121,
      18,   123,   123,    39,   126,   127,   128,    19,    37,    19,
     132,   132,    30,    31,    32,    33,    37,    17,    36,    37,
       7,    18,    33,   145,    11,    12,    13,    14,    15,     7,
     152,    18,    19,    11,    12,    13,    14,    15,    33,    33,
      18,    33,    16,    30,    31,    32,    33,    18,    18,    36,
       4,    37,    30,    31,    32,    33,    37,    37,    36,     4,
      14,    15,    16,    19,    18,    19,    20,    21,    19,    14,
      15,    16,    23,    18,    37,    20,    21,   143,   144,    23,
       9,    10,    11,    34,    35,   151,    17,    19,    37,   155,
      34,    35,    14,    15,    16,    37,    18,    17,    20,    21,
      68,    69,    70,    71,    72,     8,     9,    10,    11,    22,
      37,    19,     2,    82,    25,    16,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,    23,    34,    35,    43,    45,    46,
      49,    33,    12,    37,    50,    37,    44,    38,    33,    38,
      55,    47,    16,    18,    37,    56,    53,     7,    11,    12,
      13,    14,    15,    18,    30,    31,    32,    33,    36,    61,
      62,    63,    64,    65,    66,    67,    68,    19,    35,    45,
      51,    52,    53,    57,    45,    48,    49,    54,    68,    68,
      68,    68,    68,    68,    62,    68,    17,     5,     6,     8,
       9,    10,    11,     4,    14,    15,    16,    18,    20,    21,
      19,    50,     3,    19,    58,    37,    50,    39,    37,    19,
      19,    37,    65,    68,    67,    67,    67,    67,    67,    62,
      62,    19,    62,    69,    33,    33,    33,    52,    24,    25,
      26,    27,    28,    29,    37,    39,    55,    59,    62,    33,
      17,     3,    19,    16,    37,    62,    18,    18,    18,    37,
      37,    37,    16,    37,    62,    61,    37,    62,    62,    60,
      62,    61,    17,    19,    19,    37,    17,    59,    59,    60,
      37,    22,    37,    59,    60,    19,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      43,    45,    45,    45,    47,    48,    46,    46,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    54,    54,    56,    55,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    60,
      60,    61,    62,    62,    63,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     0,
       3,     1,     1,     1,     0,     0,     7,     2,     5,     6,
       6,     1,     0,     1,     3,     3,     6,     2,     0,     4,
       7,     2,     2,     0,     5,     1,     2,     0,     2,     1,
       2,     3,     1,     5,     7,     5,     9,     2,     2,     1,
       0,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     4,
       3,     3,     4,     3,     1,     1,     3
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
            //printscopestack();
        }
#line 1381 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 89 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-6].declptr) && (yyvsp[-2].declptr)) {
                if ((yyvsp[-5].intVal) == 0) // no pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl((yyvsp[-6].declptr)))));
                else // pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
            //printscopestack();
        }
#line 1397 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "subc.y" /* yacc.c:1646  */
    {   
            //printscopestack();
        }
#line 1405 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 105 "subc.y" /* yacc.c:1646  */
    {
            // [TODO] what here?
        }
#line 1413 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 109 "subc.y" /* yacc.c:1646  */
    {   
            pushscope();
            pushstelist((yyvsp[0].declptr)->formalswithreturnid);
            //printscopestack();
            is_func_decl = 1;
            block_number = 0;
        }
#line 1425 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 117 "subc.y" /* yacc.c:1646  */
    {
            is_func_decl = 0;
            block_number = 0;
            struct ste *pop = popscope();
            //printscopestack();
            // [TODO] delete pop using loop (for prevent from memory leak)
            // delete hash table id also!?
        }
#line 1438 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "subc.y" /* yacc.c:1646  */
    {
            decl *structdecl = makestructdecl(NULL);
            declare((yyvsp[-1].idptr), structdecl);
            
            pushscope();
            //printscopestack();
            
            (yyval.declptr) = structdecl;
        }
#line 1452 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "subc.y" /* yacc.c:1646  */
    {
                struct decl *structdecl = (yyvsp[-1].declptr);
                //printscopestack();
                struct ste *fields = popscope();
                //printscopestack();
                structdecl->fieldlist = fields;
                (yyval.declptr) = structdecl;
                //printscopestack();
        }
#line 1466 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "subc.y" /* yacc.c:1646  */
    {
            // initial set
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1475 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "subc.y" /* yacc.c:1646  */
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
#line 1490 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 171 "subc.y" /* yacc.c:1646  */
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

            // no formals

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
#line 1523 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "subc.y" /* yacc.c:1646  */
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

            // no formals

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
#line 1556 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "subc.y" /* yacc.c:1646  */
    {   
            struct ste *formals;
            struct ste *returntype;
            struct decl *procdecl;
            //printscopestack();
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
            //printscopestack();
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
#line 1595 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 265 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 1; }
#line 1601 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 266 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 0; }
#line 1607 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 274 "subc.y" /* yacc.c:1646  */
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
            //printscopestack();
        }
#line 1628 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 291 "subc.y" /* yacc.c:1646  */
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
            //printscopestack();
        }
#line 1649 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 310 "subc.y" /* yacc.c:1646  */
    {
            //printf("def list!\n");
        }
#line 1657 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 317 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr)) {
                if ((yyvsp[-2].intVal) == 0) // no pointer
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl((yyvsp[-3].declptr)));
                else // pointer 
                    declare((yyvsp[-1].idptr), (yyval.declptr) = makevardecl(makeptrdecl((yyvsp[-3].declptr))));
            }
            else
                (yyval.declptr) = NULL;
            //printscopestack();
        }
#line 1673 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 329 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-6].declptr) && (yyvsp[-2].declptr)) {
                if ((yyvsp[-5].intVal) == 0) // no pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl((yyvsp[-6].declptr)))));
                else // pointer
                    declare((yyvsp[-4].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl(makeptrdecl((yyvsp[-6].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
            //printscopestack();
        }
#line 1689 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 341 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-1].declptr)) {
                // [TODO] what here?
            }
        }
#line 1699 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 347 "subc.y" /* yacc.c:1646  */
    {
            //printscopestack();
        }
#line 1707 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 353 "subc.y" /* yacc.c:1646  */
    {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
            //printscopestack();
        }
#line 1718 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 360 "subc.y" /* yacc.c:1646  */
    {
            block_number--;
            if (!is_func_decl || block_number > 0)
                popscope();
            //printscopestack();
        }
#line 1729 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 378 "subc.y" /* yacc.c:1646  */
    {

        }
#line 1737 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 382 "subc.y" /* yacc.c:1646  */
    {   
            if ((yyvsp[-1].declptr) && !check_same_type(findcurrentdecl(returnid), (yyvsp[-1].declptr))) {
                /* return type check */
                ERROR("return type was not matched");
            }
        }
#line 1748 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 407 "subc.y" /* yacc.c:1646  */
    {
            /* assignment */
            // should have same type (ppt 23p) & not const! (=>check_is_var)
            if ((yyvsp[-2].declptr)) {
                if (check_is_var((yyvsp[-2].declptr))) {
                    if (check_same_type_for_unary((yyvsp[-2].declptr), (yyvsp[0].declptr)))
                        (yyval.declptr) = (yyvsp[-2].declptr)->type;
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
        }
#line 1776 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 437 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2].declptr) && (yyvsp[0].declptr)) {
                /* only for int type */
                if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                    (yyval.declptr) = inttype;
                else
                    ERROR("not comparable");
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1792 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 455 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-2].declptr) && (yyvsp[0].declptr)) {
                /* only for int type */
                if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                    (yyval.declptr) = inttype;
                else
                    ERROR("not comparable");
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1808 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 470 "subc.y" /* yacc.c:1646  */
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
#line 1827 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 485 "subc.y" /* yacc.c:1646  */
    {
            if (!(check_same_type((yyvsp[-2].declptr), chartype) || check_same_type((yyvsp[-2].declptr), inttype) || check_is_pointer_type((yyvsp[-2].declptr))) || !(check_same_type((yyvsp[0].declptr), chartype) || check_same_type((yyvsp[0].declptr), inttype) || check_is_pointer_type((yyvsp[0].declptr)))) {
                ERROR("not int or char or pointer type");
            }

            /* char EQUOP char or int EQUOP int or pointer(same type) EQUOP pointer(same type) */
            else if (check_same_type((yyvsp[-2].declptr), (yyvsp[0].declptr)))
                (yyval.declptr) = inttype;

            /* ERROR */
            else {
                ERROR("not comparable");
            }
        }
#line 1846 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 500 "subc.y" /* yacc.c:1646  */
    {
            // [TODO] is it only okay for int+int ?
            // then, plustype is always inttype ?

            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1862 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 512 "subc.y" /* yacc.c:1646  */
    {
            // [TODO] is it only okay for int-int ?
            // then, plustype is always inttype ?

            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1878 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 524 "subc.y" /* yacc.c:1646  */
    {   
            if ((yyvsp[0].declptr) && (yyvsp[0].declptr)->type)
                (yyval.declptr) = (yyvsp[0].declptr)->type;
            else if ((yyvsp[0].declptr) == nulltype) {
                (yyval.declptr) = nulltype;
            }
            else {
                (yyval.declptr) = NULL;
                // ERROR("ERROR : unary is NULL or unary semantic value->type is null!");
            }
        }
#line 1894 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 538 "subc.y" /* yacc.c:1646  */
    {
            // [TODO] problem : expr is type decl....
            // unary is just decl...
            (yyval.declptr) = makeconstdecl((yyvsp[-1].declptr));
        }
#line 1904 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 544 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1912 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 548 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = makeintconstdecl(inttype, (yyvsp[0].intVal));
        }
#line 1920 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 552 "subc.y" /* yacc.c:1646  */
    {   
            // [TODO] how about value ?
            (yyval.declptr) = makeconstdecl(chartype);
        }
#line 1929 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 557 "subc.y" /* yacc.c:1646  */
    {
            // [TODO] how about value ?
            // [Q] is this const ???
            (yyval.declptr) = makeconstdecl(stringtype);
        }
#line 1939 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 562 "subc.y" /* yacc.c:1646  */
    {
            // find ID
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
            if (!(yyval.declptr))
                ERROR("not declared");
        }
#line 1950 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 569 "subc.y" /* yacc.c:1646  */
    {   
            /* only integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1964 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 579 "subc.y" /* yacc.c:1646  */
    {
            /* only for int type */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = inttype;
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }
        }
#line 1978 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 589 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 1992 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 599 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2006 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 609 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2020 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 619 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }
        }
#line 2034 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 629 "subc.y" /* yacc.c:1646  */
    {
            // [TODO]
            /*
                if use '&', unary becomes pointer type value.
                ex) int* a -> &a -> int**
                ex2) int a -> &a -> int*
            */
            if ((yyvsp[0].declptr)) {
                if (check_is_var((yyvsp[0].declptr))) {
                    // it can't be RHS
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
#line 2060 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 651 "subc.y" /* yacc.c:1646  */
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
#line 2078 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 665 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr))
                (yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));
        }
#line 2087 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 670 "subc.y" /* yacc.c:1646  */
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
#line 2102 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 681 "subc.y" /* yacc.c:1646  */
    {
            // this is only for pointer to structure type on $1
            if ((yyvsp[-2].declptr) && check_is_pointer_type((yyvsp[-2].declptr)->type)){
                (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            }
            else {
                ERROR("not a pointer");
                (yyval.declptr) = NULL;
            }
        }
#line 2117 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 692 "subc.y" /* yacc.c:1646  */
    {
            /*
                args pointer last pushed args.
                args->elementvar field pointer first pushed args.
            */

            if (check_is_proc((yyvsp[-3].declptr))) {
                if ((yyvsp[-1].declptr))
                    (yyval.declptr) = check_function_call((yyvsp[-3].declptr), (yyvsp[-1].declptr)->elementvar);
            }
            else
                ERROR ("not a function");
        }
#line 2135 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 706 "subc.y" /* yacc.c:1646  */
    {
            if (check_is_proc((yyvsp[-2].declptr)))
                (yyval.declptr) = check_function_call((yyvsp[-2].declptr), NULL);
            else
                ERROR ("not a function");
        }
#line 2146 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 713 "subc.y" /* yacc.c:1646  */
    {
            // [TODO]
            (yyval.declptr) = nulltype;
        }
#line 2155 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 720 "subc.y" /* yacc.c:1646  */
    {
            // expr semantic value type is TYPEDECL.
            (yyval.declptr) = makeconstdecl((yyvsp[0].declptr));
            (yyval.declptr)->elementvar = (yyval.declptr); /* to save first args pointer. */
        }
#line 2165 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 726 "subc.y" /* yacc.c:1646  */
    {
            if ((yyval.declptr) && (yyvsp[-2].declptr)) {
                (yyvsp[-2].declptr)->next = makeconstdecl((yyvsp[0].declptr));
                (yyvsp[-2].declptr)->next->elementvar = (yyval.declptr)->elementvar;
                (yyval.declptr) = (yyvsp[-2].declptr)->next;
            }
            else
                (yyval.declptr) = NULL;
        }
#line 2179 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2183 "subc.tab.c" /* yacc.c:1646  */
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
#line 736 "subc.y" /* yacc.c:1906  */


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
