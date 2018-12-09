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
int labelnumber; /* for codegen (function call) */

/* flag for subc.y */
int is_func_decl = 0; /* for scope stack management about block inside of function */
int block_number = 0; /* for scope stack management about block inside of function */
int start_param_parsing = 1; /* for prevent from conflicts. */
int is_array_decl = 0; /* for prevent from printing 'push_const int' */
int no_fetch = 0; /* no fetch flag for INCOP, DECOP in unary->ID production */
struct decl* parsing_binary_decl = NULL; /* to save the decl upper binary */

#line 91 "subc.tab.c" /* yacc.c:339  */

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
    STRING = 273,
    CHAR_CONST = 274,
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
#line 27 "subc.y" /* yacc.c:355  */

    int intVal;
    char *stringVal;
    struct id *idptr;
    struct decl *declptr;
    struct ste *steptr;

#line 164 "subc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SUBC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "subc.tab.c" /* yacc.c:358  */

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
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
       0,    71,    71,    75,    76,    80,    92,    96,    91,   110,
     123,   127,   126,   161,   162,   163,   167,   171,   166,   181,
     194,   222,   250,   285,   286,   289,   290,   293,   310,   314,
     309,   335,   338,   341,   353,   357,   352,   371,   372,   388,
     394,   387,   409,   412,   413,   416,   417,   418,   430,   476,
     477,   483,   482,   495,   501,   494,   513,   520,   530,   537,
     542,   512,   553,   554,   557,   567,   574,   575,   582,   581,
     658,   661,   664,   679,   682,   685,   700,   703,   732,   760,
     773,   786,   810,   815,   819,   827,   834,   842,   851,   868,
     885,   912,   939,   964,   989,  1014,  1034,  1045,  1069,  1086,
    1121,  1136,  1142,  1155,  1170
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
  "STRUCT", "RETURN", "IF", "WHILE", "FOR", "BREAK", "CONTINUE", "STRING",
  "CHAR_CONST", "INTEGER_CONST", "ID", "TYPE", "VOID", "NULL_TOKEN", "';'",
  "'{'", "'}'", "$accept", "program", "ext_def_list", "ext_def", "$@1",
  "$@2", "$@3", "type_specifier", "struct_specifier", "$@4", "@5",
  "func_decl", "pointers", "param_list", "param_decl", "$@6", "$@7",
  "def_list", "def", "$@8", "$@9", "compound_stmt", "$@10", "$@11",
  "local_defs", "stmt_list", "stmt", "@12", "@13", "@14", "@15", "@16",
  "@17", "$@18", "$@19", "return_code_gen", "if_branch_code_gen", "expr_e",
  "expr", "$@20", "or_expr", "or_list", "and_expr", "and_list", "binary",
  "unary", "codegen", "args", YY_NULLPTR
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

#define YYPACT_NINF -148

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-148)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -148,    12,    46,  -148,   -13,  -148,  -148,  -148,    -9,  -148,
     -12,     7,  -148,  -148,    37,  -148,     9,  -148,   -10,  -148,
    -148,  -148,  -148,    23,  -148,  -148,    46,   173,  -148,    56,
      70,     2,  -148,    46,  -148,    -8,    55,    48,  -148,   173,
     173,   173,   173,   173,   173,   173,  -148,  -148,  -148,  -148,
    -148,   196,  -148,    64,    46,  -148,  -148,  -148,    66,  -148,
    -148,   196,   196,   196,   196,   196,   196,    81,  -148,   102,
    -148,   105,   147,    20,  -148,  -148,   173,  -148,    80,    86,
      91,   104,  -148,   103,    -7,  -148,   173,   173,   173,   173,
     173,   173,  -148,  -148,   106,    75,   164,  -148,  -148,    85,
    -148,  -148,   107,  -148,   108,   100,   101,  -148,  -148,  -148,
    -148,   109,  -148,  -148,  -148,   196,   147,    57,    77,  -148,
    -148,   173,  -148,  -148,  -148,     4,  -148,   173,    41,   173,
     126,   173,  -148,  -148,  -148,   173,  -148,   173,  -148,   196,
    -148,   115,   134,   173,   122,  -148,   196,  -148,   128,  -148,
    -148,   151,  -148,   172,  -148,   136,  -148,   173,   144,   168,
     136,  -148,  -148,  -148,  -148,   155,   136,  -148,  -148,   173,
    -148,   174,  -148,   136,  -148
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,    13,    14,     3,    24,    15,
      11,    19,    23,    10,     0,     9,     0,    16,     0,    39,
      12,    32,     6,     0,     5,    32,    17,     0,    20,    14,
      24,     0,    25,    42,    40,    24,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,    86,    85,    84,    87,
     101,     7,    21,     0,     0,    22,    44,    37,     0,    18,
      38,    94,    88,    95,    89,    92,    93,     0,    70,    71,
      73,    74,    76,    81,    90,    91,     0,   102,     0,     0,
       0,    27,    26,     0,     0,    82,     0,     0,     0,     0,
       0,     0,    68,    83,     0,    81,     0,    97,    98,     0,
      28,    64,     0,    53,     0,     0,     0,    49,    41,    46,
      43,     0,    34,    33,    72,    81,    75,    78,    77,    79,
      80,     0,    96,   100,   103,     0,     8,     0,     0,     0,
       0,    67,    62,    63,    45,     0,    69,     0,    99,    29,
      47,     0,     0,     0,     0,    66,    35,   104,     0,    48,
      65,     0,    56,     0,    30,     0,    54,    67,     0,    50,
       0,    57,    36,    51,    55,     0,     0,    58,    52,    67,
      59,     0,    60,     0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,  -148,     0,  -148,  -148,
    -148,   197,    14,  -148,   148,  -148,  -148,   176,  -148,  -148,
    -148,   182,  -148,  -148,  -148,  -148,  -123,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -147,   -45,  -148,
    -148,  -148,   121,  -148,    15,   -26,  -148,  -148
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,    27,    80,    16,    30,     9,    21,
      36,    37,    14,    31,    32,   127,   148,    26,    38,   135,
     153,   109,    25,    56,    34,    83,   110,   166,   130,   160,
     157,   165,   169,   171,   173,   128,   155,   144,   111,   121,
      68,    69,    70,    71,    72,    95,    96,   125
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    51,     8,    12,    12,    54,    22,   137,    23,   112,
     161,    23,     3,    61,    62,    63,    64,    65,    66,    73,
      11,    55,   170,   138,    92,    15,    35,    24,    13,    57,
     113,    94,   159,    35,    74,    75,    76,   164,    77,    93,
      78,    79,    28,   168,    53,    17,     4,    19,    39,    58,
     174,   124,    40,    41,    42,    43,    44,     5,    29,    45,
     115,   115,   115,   115,   115,   115,    89,    90,    91,     4,
      18,    46,    47,    48,    49,    52,   136,    50,   140,    92,
       5,     6,    12,   141,   142,    60,   145,    90,    91,    74,
      75,    76,   147,    77,    59,    78,    79,    81,   151,    84,
      85,   139,   116,   117,   118,   119,   120,    86,    99,   146,
      39,    87,   145,    97,    40,    41,    42,    43,    44,    98,
     100,    45,   126,   122,   145,   129,   131,   101,   102,   103,
     104,   105,   106,    46,    47,    48,    49,   132,   133,    50,
     107,    19,   108,    39,   143,   154,   134,    40,    41,    42,
      43,    44,   149,   150,    45,    88,    89,    90,    91,   152,
     101,   102,   103,   104,   105,   106,    46,    47,    48,    49,
     156,    39,    50,   107,    19,    40,    41,    42,    43,    44,
      39,   162,    45,   123,    40,    41,    42,    43,    44,   158,
     163,    45,   167,   172,    46,    47,    48,    49,    20,    10,
      50,    33,    82,    46,    47,    48,    49,   114,     0,    50,
      74,    75,    76,     0,    77,     0,    78,    79
};

static const yytype_int16 yycheck[] =
{
      45,    27,     2,    12,    12,     3,    16,     3,    18,    16,
     157,    18,     0,    39,    40,    41,    42,    43,    44,    45,
      33,    19,   169,    19,     4,    37,    26,    37,    37,    37,
      37,    76,   155,    33,    14,    15,    16,   160,    18,    19,
      20,    21,    19,   166,    30,    38,    23,    38,     7,    35,
     173,    96,    11,    12,    13,    14,    15,    34,    35,    18,
      86,    87,    88,    89,    90,    91,     9,    10,    11,    23,
      33,    30,    31,    32,    33,    19,   121,    36,    37,     4,
      34,    35,    12,   128,   129,    37,   131,    10,    11,    14,
      15,    16,   137,    18,    39,    20,    21,    33,   143,    33,
      19,   127,    87,    88,    89,    90,    91,     5,    17,   135,
       7,     6,   157,    33,    11,    12,    13,    14,    15,    33,
      16,    18,    37,    17,   169,    18,    18,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    37,    37,    36,
      37,    38,    39,     7,    18,    17,    37,    11,    12,    13,
      14,    15,    37,    19,    18,     8,     9,    10,    11,    37,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      19,     7,    36,    37,    38,    11,    12,    13,    14,    15,
       7,    37,    18,    19,    11,    12,    13,    14,    15,    17,
      22,    18,    37,    19,    30,    31,    32,    33,    16,     2,
      36,    25,    54,    30,    31,    32,    33,    86,    -1,    36,
      14,    15,    16,    -1,    18,    -1,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,    23,    34,    35,    43,    47,    48,
      51,    33,    12,    37,    52,    37,    46,    38,    33,    38,
      61,    49,    16,    18,    37,    62,    57,    44,    19,    35,
      47,    53,    54,    57,    64,    47,    50,    51,    58,     7,
      11,    12,    13,    14,    15,    18,    30,    31,    32,    33,
      36,    85,    19,    52,     3,    19,    63,    37,    52,    39,
      37,    85,    85,    85,    85,    85,    85,    78,    80,    81,
      82,    83,    84,    85,    14,    15,    16,    18,    20,    21,
      45,    33,    54,    65,    33,    19,     5,     6,     8,     9,
      10,    11,     4,    19,    78,    85,    86,    33,    33,    17,
      16,    24,    25,    26,    27,    28,    29,    37,    39,    61,
      66,    78,    16,    37,    82,    85,    84,    84,    84,    84,
      84,    79,    17,    19,    78,    87,    37,    55,    75,    18,
      68,    18,    37,    37,    37,    59,    78,     3,    19,    85,
      37,    78,    78,    18,    77,    78,    85,    78,    56,    37,
      19,    78,    37,    60,    17,    76,    19,    70,    17,    66,
      69,    77,    37,    22,    66,    71,    67,    37,    66,    72,
      77,    73,    19,    74,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    45,    43,    43,
      43,    46,    43,    47,    47,    47,    49,    50,    48,    48,
      51,    51,    51,    52,    52,    53,    53,    54,    55,    56,
      54,    57,    57,    58,    59,    60,    58,    58,    58,    62,
      63,    61,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    67,    66,    68,    69,    66,    70,    71,    72,    73,
      74,    66,    66,    66,    75,    76,    77,    77,    79,    78,
      78,    80,    81,    81,    82,    83,    83,    84,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     0,     0,     9,     2,
       2,     0,     3,     1,     1,     1,     0,     0,     7,     2,
       5,     6,     6,     1,     0,     1,     3,     3,     0,     0,
       8,     2,     0,     4,     0,     0,     9,     2,     2,     0,
       0,     6,     1,     2,     0,     2,     1,     3,     4,     1,
       6,     0,     9,     0,     0,     7,     0,     0,     0,     0,
       0,    14,     2,     2,     0,     0,     1,     0,     0,     4,
       1,     1,     3,     1,     1,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     4,     3,     3,     5,
       4,     1,     0,     1,     3
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
#line 81 "subc.y" /* yacc.c:1646  */
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
#line 1402 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 92 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
#line 1410 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 96 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 0; // reset
        }
#line 1418 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 100 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-8].declptr) && (yyvsp[-3].declptr)) {
                if ((yyvsp[-7].intVal) == 0) // no pointer
                    declare((yyvsp[-6].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-3].declptr)->value, makevardecl((yyvsp[-8].declptr)))));
                else // pointer
                    declare((yyvsp[-6].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-3].declptr)->value, makevardecl(makeptrdecl((yyvsp[-8].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1433 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "subc.y" /* yacc.c:1646  */
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
#line 1450 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "subc.y" /* yacc.c:1646  */
    {
        }
#line 1457 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 127 "subc.y" /* yacc.c:1646  */
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
#line 1473 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "subc.y" /* yacc.c:1646  */
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
#line 1498 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 167 "subc.y" /* yacc.c:1646  */
    {
            pushscope();
        }
#line 1506 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 171 "subc.y" /* yacc.c:1646  */
    {
            struct ste *fields = popscope();
            decl *structdecl = makestructdecl(fields);
            declare((yyvsp[-3].idptr), structdecl);
            (yyval.declptr) = structdecl;
        }
#line 1517 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 178 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 1525 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 182 "subc.y" /* yacc.c:1646  */
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
#line 1540 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "subc.y" /* yacc.c:1646  */
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
#line 1572 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "subc.y" /* yacc.c:1646  */
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
#line 1604 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 251 "subc.y" /* yacc.c:1646  */
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
#line 1641 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 285 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 1; }
#line 1647 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 286 "subc.y" /* yacc.c:1646  */
    { (yyval.intVal) = 0; }
#line 1653 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 294 "subc.y" /* yacc.c:1646  */
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
#line 1673 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 310 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
#line 1681 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 314 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 0; // reset
        }
#line 1689 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 318 "subc.y" /* yacc.c:1646  */
    {
            if (start_param_parsing) {
                pushscope();
                start_param_parsing = 0;
            }

            if ((yyvsp[-7].declptr) && (yyvsp[-2].declptr)) {
                if ((yyvsp[-6].intVal) == 0) // no pointer
                    declare((yyvsp[-5].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl((yyvsp[-7].declptr)))));
                else // pointer
                    declare((yyvsp[-5].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-2].declptr)->value, makevardecl(makeptrdecl((yyvsp[-7].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1709 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 336 "subc.y" /* yacc.c:1646  */
    {
        }
#line 1716 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 342 "subc.y" /* yacc.c:1646  */
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
#line 1731 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 353 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 1; // prevent from printing 'push_const' in unary
        }
#line 1739 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 357 "subc.y" /* yacc.c:1646  */
    {
            is_array_decl = 0; // reset
        }
#line 1747 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 361 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-8].declptr) && (yyvsp[-3].declptr)) {
                if ((yyvsp[-7].intVal) == 0) // no pointer
                    declare((yyvsp[-6].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-3].declptr)->value, makevardecl((yyvsp[-8].declptr)))));
                else // pointer
                    declare((yyvsp[-6].idptr), (yyval.declptr) = makeconstdecl(makearraydecl((yyvsp[-3].declptr)->value, makevardecl(makeptrdecl((yyvsp[-8].declptr))))));
            }
            else
                (yyval.declptr) = NULL;
        }
#line 1762 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 373 "subc.y" /* yacc.c:1646  */
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
#line 1779 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 388 "subc.y" /* yacc.c:1646  */
    {
            if (!is_func_decl || block_number > 0)
                pushscope();
            block_number++;
        }
#line 1789 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 394 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            if (is_func_decl && block_number == 1) {
                printf("\tshift_sp %d\n", top->sumofsize);
                FUNC_LABEL(labelname, "start");
            }
        }
#line 1801 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 402 "subc.y" /* yacc.c:1646  */
    {
            block_number--;
            if (!is_func_decl || block_number > 0)
                popscope();
        }
#line 1811 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 419 "subc.y" /* yacc.c:1646  */
    {
            if (!check_same_type(findcurrentdecl(returnid), voidtype)) {
                /* return type check */
                ERROR("return type was not matched");
            }

            /* code generation */
            CODE("push_const 0"); // no return expr, so return value = 0
            CODE("assign");
            printf("\tjump %s_final\n", labelname);
        }
#line 1827 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 431 "subc.y" /* yacc.c:1646  */
    {   
            if ((yyvsp[-1].declptr) && !check_same_type(findcurrentdecl(returnid), (yyvsp[-1].declptr))) {
                /* return type check */
                ERROR("return type was not matched");
            }

            /* code generation */
            
            // assign return value (fp-2)
            //CODE("assign"); 

            int var_offset = 0;

            // fill the value
            while (++var_offset < findcurrentdecl(returnid)->size) {
                // for not singleton variable (struct) *array assignment is semantic error*
                push_address(parsing_binary_decl, var_offset);
                CODE("fetch");
            }
            
            // assign
            while (--var_offset > 0) {
                // push address
                CODE("push_reg fp");
                CODE("push_const -1");
                CODE("add"); // fp-1 (return address)
                printf("\tpush_const %d\n", -findcurrentdecl(returnid)->size + var_offset);
                CODE("add"); // return value : fp-2 => (struct : fp-1-size)

                // push value
                CODE("push_reg sp");
                CODE("push_const -1");
                CODE("add");
                CODE("fetch");

                // assign
                CODE("assign");

                // shift sp
                CODE("shift_sp -1");
            }

            CODE("assign");
            printf("\tjump %s_final\n", labelname);
        }
#line 1877 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 478 "subc.y" /* yacc.c:1646  */
    {   
            /* code generation */
            printf("label_%d:\n", (yyvsp[-1].intVal));
        }
#line 1886 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 483 "subc.y" /* yacc.c:1646  */
    {   
            /* code generation */
            (yyval.intVal) = new_label();
            printf("\tjump label_%d\n", (yyval.intVal));
            printf("label_%d:\n", (yyvsp[-2].intVal));
        }
#line 1897 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 490 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            printf("label_%d:\n", (yyvsp[-1].intVal));
        }
#line 1906 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 495 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            (yyval.intVal) = new_label();
            printf("label_%d:\n", (yyval.intVal));
        }
#line 1916 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 501 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            (yyval.intVal) = new_label();
            printf("\tbranch_false label_%d\n", (yyval.intVal));
        }
#line 1926 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 507 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            printf("\tjump label_%d\n", (yyvsp[-5].intVal));
            printf("label_%d:\n", (yyvsp[-1].intVal));
        }
#line 1936 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 513 "subc.y" /* yacc.c:1646  */
    {
            /* $<intVal>5 */
            /* code generation */
            (yyval.intVal) = new_label();
            printf("label_%d:\n", (yyval.intVal));
        }
#line 1947 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 520 "subc.y" /* yacc.c:1646  */
    {
            /* $<intVal>7 */
            /* code generation */
            (yyval.intVal) = new_label();
            CODE("push_reg sp");
            CODE("fetch"); // to compare false condition
            printf("\tbranch_true label_%d\n", (yyval.intVal));
            printf("\tbranch_false label_%d\n", new_label()); // $<intVal>7+1
        }
#line 1961 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 530 "subc.y" /* yacc.c:1646  */
    {
            /* $<intVal>9 */
            /* code generation */
            (yyval.intVal) = new_label();
            printf("label_%d:\n", (yyval.intVal));
        }
#line 1972 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 537 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            printf("\tjump label_%d\n", (yyvsp[-5].intVal));
        }
#line 1981 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 542 "subc.y" /* yacc.c:1646  */
    {
           /* code generation */
            printf("label_%d:\n", (yyvsp[-5].intVal)); // branch true
            CODE("shift_sp -1"); // pop the top one which pushed to compare the false label
        }
#line 1991 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 548 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            printf("\tjump label_%d\n", (yyvsp[-5].intVal));
            printf("label_%d:\n", (yyvsp[-7].intVal) + 1); // branch false
        }
#line 2001 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 557 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            CODE("push_reg fp");
            CODE("push_const -1");
            CODE("add"); // fp-1 (return address)
            printf("\tpush_const %d\n", -findcurrentdecl(returnid)->size);
            CODE("add"); // return value : fp-2 => (struct : fp-1-size)
        }
#line 2014 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 567 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            (yyval.intVal) = new_label();
            printf("\tbranch_false label_%d\n", (yyval.intVal));
        }
#line 2024 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 582 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            CODE("push_reg sp");
            CODE("fetch");
        }
#line 2034 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 588 "subc.y" /* yacc.c:1646  */
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

            int var_offset = 0;

            // fill the value
            if(!check_is_struct_from_return(parsing_binary_decl)) {
                // if it has its struct scope (declared struct)
                while (++var_offset < (yyvsp[-3].declptr)->size) {
                    // for not singleton variable (struct) *array assignment is semantic error*
                    push_address(parsing_binary_decl, var_offset);
                    CODE("fetch");
                }

                // no has its scope : struct pointer
                // (ex. return from function pointer struct, declared pointer struct...)
            }

            var_offset = (yyvsp[-3].declptr)->size;

            // assign
            while (var_offset > 1) {
                // push address
                CODE("push_reg sp");
                printf("\tpush_const %d\n", -var_offset);
                CODE("add");
                CODE("fetch");
                printf("\tpush_const %d\n", --var_offset);
                CODE("add");

                // push value
                CODE("push_reg sp");
                CODE("push_const -1");
                CODE("add");
                CODE("fetch");

                // assign
                CODE("assign");

                // shift sp
                CODE("shift_sp -1");
            }
            
            CODE("assign");
            CODE("fetch");
            CODE("shift_sp -1");
        }
#line 2109 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 665 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            CODE("or");
        }
#line 2128 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 686 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            CODE("and");
        }
#line 2147 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 704 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            if (strcmp((yyvsp[-1].stringVal), "<") == 0) {
                CODE("less");
            }
            else if (strcmp((yyvsp[-1].stringVal), "<=") == 0){
                CODE("less_equal");
            }
            else if (strcmp((yyvsp[-1].stringVal), ">") == 0){
                CODE("greater");
            }
            else if (strcmp((yyvsp[-1].stringVal), ">=") == 0){
                CODE("greater_equal");
            }
        }
#line 2180 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 733 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            if (strcmp((yyvsp[-1].stringVal), "==") == 0) {
                CODE("equal");
            }
            else {
                CODE("not_equal");
            }
        }
#line 2212 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 761 "subc.y" /* yacc.c:1646  */
    {
            /* only for int+int */
            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            CODE("add");
        }
#line 2229 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 774 "subc.y" /* yacc.c:1646  */
    {
            /* only for int+int */
            if (check_same_type((yyvsp[-2].declptr), inttype) && check_same_type((yyvsp[0].declptr), inttype))
                (yyval.declptr) = plustype((yyvsp[-2].declptr), (yyvsp[0].declptr));
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            CODE("sub");
        }
#line 2246 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 787 "subc.y" /* yacc.c:1646  */
    {
            parsing_binary_decl = (yyvsp[0].declptr);

            if ((yyvsp[0].declptr) && (yyvsp[0].declptr)->type) {
                (yyval.declptr) = (yyvsp[0].declptr)->type;
            }
            else if ((yyvsp[0].declptr) == nulltype) {
                (yyval.declptr) = nulltype;
            }
            else {
                (yyval.declptr) = NULL;
            }

            /* code generation */
            // this code is for prevent from such as const_int fetch
            // fetch only "unary->ID" reduce case. (same condition!)
            if ((check_is_var((yyvsp[0].declptr)) || check_is_array((yyvsp[0].declptr)->type)) && !no_fetch) {
                CODE("fetch");
            }
            no_fetch = 0; // reset
        }
#line 2272 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 811 "subc.y" /* yacc.c:1646  */
    {
            /* expr is type decl and unary is just decl => Make constdecl to solve this problem */
            (yyval.declptr) = makeconstdecl((yyvsp[-1].declptr));
        }
#line 2281 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 816 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = (yyvsp[-1].declptr);
        }
#line 2289 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 820 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = makeintconstdecl(inttype, (yyvsp[0].intVal));

            /* code generation */
            if (!is_array_decl)
                printf("\tpush_const %d\n", (yyval.declptr)->value);
        }
#line 2301 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 828 "subc.y" /* yacc.c:1646  */
    {   
            (yyval.declptr) = makeintconstdecl(chartype, (yyvsp[0].intVal));

            /* code generation */
            printf("\tpush_const %d\n", (yyval.declptr)->value);
        }
#line 2312 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 835 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = makestringconstdecl(stringtype, (yyvsp[0].stringVal));

            /* code generation */
            printf("str_%d. string %s\n", new_string(), (yyval.declptr)->stringvalue);
            printf("\tpush_const str_%d\n", stringnumber);
        }
#line 2324 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 842 "subc.y" /* yacc.c:1646  */
    {
            /* find ID */
            (yyval.declptr) = findcurrentdecl((yyvsp[0].idptr));
            if (!(yyval.declptr))
                ERROR("not declared");

            /* code generation */
            push_address((yyval.declptr), 0);
        }
#line 2338 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 852 "subc.y" /* yacc.c:1646  */
    {   
            /* only integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            if (check_is_var((yyvsp[0].declptr)) || check_is_array((yyvsp[0].declptr)->type)) {
                CODE("fetch");
                no_fetch = 1;
            }
            CODE("negate");
        }
#line 2359 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 869 "subc.y" /* yacc.c:1646  */
    {
            /* only for int type */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype))
                (yyval.declptr) = inttype;
            else {
                ERROR("not int type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            if (check_is_var((yyvsp[0].declptr)) || check_is_array((yyvsp[0].declptr)->type)) {
                CODE("fetch");
                no_fetch = 1;
            }
            CODE("not");
        }
#line 2380 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 886 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype) || check_is_pointer_type((yyvsp[-1].declptr)->type) || check_is_struct_type((yyvsp[-1].declptr)->type))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            CODE("fetch"); /* fetch! */
            push_address((yyval.declptr), 0);
            push_address((yyval.declptr), 0);
            CODE("fetch");
            if (check_is_pointer_type((yyvsp[-1].declptr)->type)){
                // pointer (++ptrto size)
                printf("\tpush_const %d\n", (yyvsp[-1].declptr)->type->ptrto->size);
            }
            else {
                // int, char, struct
                printf("\tpush_const %d\n", (yyvsp[-1].declptr)->size);
            }
            CODE("add");
            CODE("assign");
            no_fetch = 1; /* it has already fetched */
        }
#line 2411 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 913 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[-1].declptr), inttype) || check_same_type_for_unary((yyvsp[-1].declptr), chartype))
                (yyval.declptr) = (yyvsp[-1].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            CODE("fetch"); /* fetch! */
            push_address((yyval.declptr), 0);
            push_address((yyval.declptr), 0);
            CODE("fetch");
            if (check_is_pointer_type((yyvsp[-1].declptr)->type)){
                // pointer (++ptrto size)
                printf("\tpush_const -%d\n", (yyvsp[-1].declptr)->type->ptrto->size);
            }
            else {
                // int, char, struct
                printf("\tpush_const -%d\n", (yyvsp[-1].declptr)->size);
            }
            CODE("add");
            CODE("assign");
            no_fetch = 1; /* it has already fetched */
        }
#line 2442 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 940 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            push_address((yyval.declptr), 0);
            push_address((yyval.declptr), 0);
            CODE("fetch");
            if (check_is_pointer_type((yyvsp[0].declptr)->type)){
                // pointer (++ptrto size)
                printf("\tpush_const %d\n", (yyvsp[0].declptr)->type->ptrto->size);
            }
            else {
                // int, char, struct
                printf("\tpush_const %d\n", (yyvsp[0].declptr)->size);
            }
            CODE("add");
            CODE("assign");
        }
#line 2471 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 965 "subc.y" /* yacc.c:1646  */
    {
            /* only char, integer */
            if (check_same_type_for_unary((yyvsp[0].declptr), inttype) || check_same_type_for_unary((yyvsp[0].declptr), chartype))
                (yyval.declptr) = (yyvsp[0].declptr);
            else {
                ERROR("not int or char type");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            push_address((yyval.declptr), 0);
            push_address((yyval.declptr), 0);
            CODE("fetch");
            if (check_is_pointer_type((yyvsp[0].declptr)->type)){
                // pointer (++ptrto size)
                printf("\tpush_const -%d\n", (yyvsp[0].declptr)->type->ptrto->size);
            }
            else {
                // int, char, struct
                printf("\tpush_const -%d\n", (yyvsp[0].declptr)->size);
            }
            CODE("add");
            CODE("assign");
        }
#line 2500 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 990 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            // no need to generate code!
            // Naturally no fetch step, just add address. (no unary->binary)
            
        }
#line 2529 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1015 "subc.y" /* yacc.c:1646  */
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

            /* code generation */
            // one more fetch to read address
            // but pointer from function return is already fetched value (already true address)
            if (!check_is_pointer_from_return((yyvsp[0].declptr)))
                CODE("fetch");
        }
#line 2553 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1035 "subc.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-3].declptr))
                (yyval.declptr) = arrayaccess((yyvsp[-3].declptr), (yyvsp[-1].declptr));

            /* code generation */
            // array access
            printf("\tpush_const %d\n", ((yyvsp[-3].declptr)->size)/((yyvsp[-3].declptr)->num_index));
            CODE("mul");
            CODE("add");
        }
#line 2568 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1046 "subc.y" /* yacc.c:1646  */
    {
            /* This is only for structure type on $1 */
            if ((yyvsp[-2].declptr) && !check_is_pointer_type((yyvsp[-2].declptr)->type)){
                (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            }
            else {
                ERROR("variable is not struct");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            // struct access

            // print unary address (in case of struct from function return)
            if (check_is_struct_from_return((yyvsp[-2].declptr))) {
                CODE("push_reg sp");
                printf("\tpush_const %d\n", -((yyvsp[-2].declptr)->size-1));
                CODE("add");
            }
            
            printf("\tpush_const %d\n", (yyval.declptr)->offset);
            CODE("add");
        }
#line 2596 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1070 "subc.y" /* yacc.c:1646  */
    {
            /* this is only for pointer to structure type on $1 */
            if ((yyvsp[-2].declptr) && check_is_pointer_type((yyvsp[-2].declptr)->type)){
                (yyval.declptr) = structaccess((yyvsp[-2].declptr), (yyvsp[0].idptr));
            }
            else {
                ERROR("not a pointer");
                (yyval.declptr) = NULL;
            }

            /* code generation */
            // struct access
            CODE("fetch");
            printf("\tpush_const %d\n", (yyval.declptr)->offset);
            CODE("add");
        }
#line 2617 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1087 "subc.y" /* yacc.c:1646  */
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
            if ((yyvsp[-4].declptr) == write_int) {
                CODE("write_int");
            }
            else if ((yyvsp[-4].declptr) == write_string) {
                CODE("write_string");
            }
            else if ((yyvsp[-4].declptr) == write_char) {
                CODE("write_char");
            }
            else {
                // push the actual parameters on the stack in 'args' reducing procedure
                CODE("push_reg sp"); // FP = SP
                printf("\tpush_const -%d\n", sumofargs);
                CODE("add");
                CODE("pop_reg fp");
                printf("\tjump %s\n", (yyvsp[-4].declptr)->id->name); // Then, jump
                printf("label_%d:\n", (yyvsp[-2].intVal)); // print label
            }
        }
#line 2656 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1122 "subc.y" /* yacc.c:1646  */
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
            printf("label_%d:\n", (yyvsp[-1].intVal)); // print label
        }
#line 2675 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1137 "subc.y" /* yacc.c:1646  */
    {
            (yyval.declptr) = nulltype;
        }
#line 2683 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1142 "subc.y" /* yacc.c:1646  */
    {
            /* code generation */
            // caller convention
            if((yyvsp[(-1) - (0)].declptr) != write_int && (yyvsp[(-1) - (0)].declptr) != write_string && (yyvsp[(-1) - (0)].declptr) != write_char) {
                printf("\tshift_sp %d\n", (yyvsp[(-1) - (0)].declptr)->returntype->size); // push a hole for return value
                (yyval.intVal) = new_label();
                printf("\tpush_const label_%d\n", (yyval.intVal)); // push the return address
                CODE("push_reg fp"); // push the old FP
            }
            sumofargs = 0; // reset
        }
#line 2699 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1156 "subc.y" /* yacc.c:1646  */
    {
            /* expr semantic value type is TYPEDECL */
            (yyval.declptr) = makeconstdecl((yyvsp[0].declptr));
            (yyval.declptr)->elementvar = (yyval.declptr); /* to save first args pointer. */

            /* code generation */
            sumofargs += (yyvsp[0].declptr)->size; // set global variable for caller convention
            // if expr is struct, push remain values
            int var_offset = 0;
            while (++var_offset < (yyvsp[0].declptr)->size) {
                push_address(parsing_binary_decl, var_offset);
                CODE("fetch");
            }
        }
#line 2718 "subc.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1171 "subc.y" /* yacc.c:1646  */
    {
            if ((yyval.declptr) && (yyvsp[-2].declptr)) {
                (yyvsp[-2].declptr)->next = makeconstdecl((yyvsp[0].declptr));
                (yyvsp[-2].declptr)->next->elementvar = (yyval.declptr)->elementvar;
                (yyval.declptr) = (yyvsp[-2].declptr)->next;
            }
            else
                (yyval.declptr) = NULL;

            /* code generation */
            sumofargs += (yyvsp[0].declptr)->size; // set global variable for caller convention
            // if expr is struct, push remain values
            int var_offset = 0;
            while (++var_offset < (yyvsp[0].declptr)->size) {
                push_address(parsing_binary_decl, var_offset);
                CODE("fetch");
            }
        }
#line 2741 "subc.tab.c" /* yacc.c:1646  */
    break;


#line 2745 "subc.tab.c" /* yacc.c:1646  */
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
#line 1190 "subc.y" /* yacc.c:1906  */


/*  Additional C Codes  */

int yyerror (char* s) {
    fprintf (stderr, "%s\n", s);
}

void push_address(struct decl* decl_ptr, int offset) {
    if (check_is_var(decl_ptr) || check_is_array(decl_ptr->type)) {
        switch (check_variable_scope(decl_ptr)) {
            case GLOBAL:
                CODE("push_const Lglob");
                printf("\tpush_const %d\n", decl_ptr->offset + offset);
                CODE("add");
                break;

            case PARAM:
                CODE("push_reg fp");
                printf("\tpush_const %d\n", 1 + decl_ptr->offset + offset);
                CODE("add");
                break;

            case LOCAL:
                CODE("push_reg fp");
                printf("\tpush_const %d\n", 1 + decl_ptr->scope->sumofparams + decl_ptr->offset + offset);
                CODE("add");
                break;

            default:
                break;
        }
    }
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

int new_string() {
    return ++stringnumber;
}
