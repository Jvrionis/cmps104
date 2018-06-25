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
#line 1 "parser.y" /* yacc.c:339  */

// James Vrionis
// jvrionis
// Dummy parser for scanner project.
// asg3
//--------------------------------------------------------------------
#include <cassert>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#line 80 "yyparse.cc" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
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
    TOK_VOID = 258,
    TOK_CHAR = 259,
    TOK_INT = 260,
    TOK_BOOL = 261,
    TOK_STRING = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_RETURN = 266,
    TOK_STRUCT = 267,
    TOK_TRUE = 268,
    TOK_FALSE = 269,
    TOK_NULL = 270,
    TOK_NEW = 271,
    TOK_ARRAY = 272,
    TOK_EQ = 273,
    TOK_NE = 274,
    TOK_LT = 275,
    TOK_LE = 276,
    TOK_GT = 277,
    TOK_GE = 278,
    TOK_IDENT = 279,
    TOK_INTCON = 280,
    TOK_CHARCON = 281,
    TOK_STRINGCON = 282,
    TOK_BLOCK = 283,
    TOK_CALL = 284,
    TOK_IFELSE = 285,
    TOK_INITDECL = 286,
    TOK_POS = 287,
    TOK_NEG = 288,
    TOK_NEWARRAY = 289,
    TOK_TYPEID = 290,
    TOK_FIELD = 291,
    TOK_ORD = 292,
    TOK_CHR = 293,
    TOK_ROOT = 294,
    NUMBER = 295,
    TOK_PARAMLIST = 296,
    TOK_FUNCTION = 297,
    TOK_PROTOTYPE = 298,
    TOK_NEWSTRING = 299,
    TOK_INDEX = 300,
    TOK_DECLID = 301,
    TOK_RETURNVOID = 302,
    TOK_VARDECL = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 180 "yyparse.cc" /* yacc.c:358  */

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
#define YYLAST   501

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    54,     2,     2,
      58,    63,    52,    50,    62,    51,    57,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    59,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    50,    50,    54,    56,    58,    60,    62,    65,    68,
      71,    76,    80,    86,    89,    94,    95,    96,    97,    98,
     101,   104,   109,   114,   118,   124,   131,   134,   139,   142,
     146,   149,   154,   155,   156,   157,   158,   159,   162,   165,
     171,   176,   181,   186,   189,   194,   196,   198,   200,   202,
     206,   208,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   225,   226,   227,   228,   231,   235,   239,
     245,   248,   253,   256,   262,   264,   268,   273,   274,   275,
     276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_CHAR", "TOK_INT",
  "TOK_BOOL", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_RETURN", "TOK_STRUCT", "TOK_TRUE", "TOK_FALSE", "TOK_NULL",
  "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT",
  "TOK_GE", "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON",
  "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE", "TOK_INITDECL", "TOK_POS",
  "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID", "TOK_FIELD", "TOK_ORD",
  "TOK_CHR", "TOK_ROOT", "NUMBER", "TOK_PARAMLIST", "TOK_FUNCTION",
  "TOK_PROTOTYPE", "TOK_NEWSTRING", "TOK_INDEX", "TOK_DECLID",
  "TOK_RETURNVOID", "TOK_VARDECL", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'['", "'.'", "'('", "'}'", "';'", "'{'", "','", "')'",
  "']'", "$accept", "start", "program", "structstmts", "structdef",
  "fielddecl", "basetype", "params", "function", "identdecl", "body",
  "block", "statement", "vardecl", "while", "ifelse", "return", "expr",
  "binop", "unop", "allocator", "cexprs", "call", "variable", "constant", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    61,
      43,    45,    42,    47,    37,    33,    91,    46,    40,   125,
      59,   123,    44,    41,    93
};
# endif

#define YYPACT_NINF -64

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-64)))

#define YYTABLE_NINF -20

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,     8,    18,   -64,   -56,   -64,   -64,   -64,   -64,   -42,
     -31,   346,    31,   -64,   156,    -4,   -64,   -64,   -64,   -64,
     -64,   -64,   359,   -64,    85,   -64,   -15,   -64,   -34,   123,
     -64,   -64,   -64,   -64,   -64,   -64,   375,   359,   -64,   -26,
     -64,   -64,   -64,   -64,   -64,   359,   359,     1,   -64,   389,
       2,     4,     9,    13,   174,   239,   -64,    11,   -64,    47,
     -64,   359,     7,   -10,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   359,    50,   -64,
     359,   444,   359,   -64,   248,   294,   -64,    61,    99,   359,
      24,   359,   -64,   444,   -64,   -64,   432,   -64,   -13,   -64,
     220,    -3,   190,   -64,   444,   444,   161,   161,   -64,    34,
      22,   -64,    37,   303,   -64,   230,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,    82,   -64,   -64,    74,   -64,   -64,   -64,
     -64,   161,   -64,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    16,    17,    18,     0,
       0,     0,     0,    80,    66,    74,    77,    78,    79,    63,
      64,    65,     0,    38,     0,     3,     0,     4,     0,     0,
      32,     5,    33,    34,    35,    36,     0,     0,    47,     0,
      48,    50,    51,     6,     7,     0,     0,    74,    43,     0,
       0,    18,    19,     0,     0,     0,    31,     0,    28,     0,
      26,     0,     0,     0,    30,    29,    52,    53,    54,    55,
      56,    57,    62,    58,    59,    60,    61,     0,     0,    37,
       0,    46,     0,    72,     0,     0,    44,     0,     0,     0,
       0,     0,    73,    70,    49,    27,     0,    19,     0,    20,
       0,     0,     0,    76,    45,    71,     0,     0,    12,     0,
       0,    11,     0,     0,    67,     0,    39,    25,    24,    21,
      23,    22,    75,    42,    40,     9,     0,    13,    10,    68,
      69,     0,    14,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,   -64,   -64,   -64,    17,    -7,   -64,   -64,    -1,
     -64,   -63,   -24,   -64,   -64,   -64,   -64,    -5,   -64,   -64,
     -64,   -64,   -64,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    88,    25,   109,    26,    63,    27,    57,
      29,    30,    31,    32,    33,    34,    35,    36,    80,    37,
      38,    39,    40,    41,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    28,    59,    43,    44,    65,    49,    53,     3,    60,
       5,     6,     7,   -19,     8,    61,    45,    55,    -2,     4,
     -19,     5,     6,     7,    62,     8,     9,    46,    10,    11,
      12,    97,    81,    13,    14,   118,    82,    83,   121,   126,
      84,    85,    15,    16,    17,    18,   127,   117,    24,    93,
      19,    20,   100,   101,    54,    50,    96,   120,    24,    54,
      61,    99,    89,    87,     5,     6,     7,    90,     8,    91,
      98,    95,   102,    21,   103,   104,    22,   105,    23,    24,
     110,   110,   123,   124,   113,    97,   115,   114,     5,     6,
       7,   131,     8,     9,   125,    10,    11,   128,   132,   119,
      13,    14,     5,     6,     7,   112,     8,   133,     0,    15,
      16,    17,    18,     0,     0,     0,     0,    19,    20,     0,
     108,     0,     0,    97,     0,     0,     5,     6,     7,     0,
       8,     9,     0,    10,    11,     0,     0,     0,    13,    14,
      21,     0,     0,    22,    56,    23,    24,    15,    16,    17,
      18,     0,     0,     0,     0,    19,    20,     0,   111,     5,
       6,     7,     0,    51,     5,     6,     7,     0,     8,     9,
       0,    10,    11,     0,     0,     0,    13,    14,    21,     0,
      52,    22,    64,    23,    24,    15,    16,    17,    18,    13,
      14,     0,     0,    19,    20,     0,     0,     0,    47,    16,
      17,    18,     0,     0,     0,     0,    19,    20,    66,    67,
      68,    69,    70,    71,     0,     0,    21,     0,     0,    22,
       0,    23,    24,     5,     6,     7,     0,     8,     0,    21,
       0,     0,    22,     0,     0,     0,     0,    92,     0,    72,
      73,    74,    75,    76,    97,     0,    77,    78,    66,    67,
      68,    69,    70,    71,   122,     0,     0,    66,    67,    68,
      69,    70,    71,     0,     0,     0,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,     0,     0,    77,    78,    72,    73,
      74,    75,    76,     0,   130,    77,    78,    72,    73,    74,
      75,    76,    94,     0,    77,    78,     0,     0,     0,     0,
       0,   106,    66,    67,    68,    69,    70,    71,     0,     0,
       0,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,     0,     0,
      77,    78,    72,    73,    74,    75,    76,   107,     0,    77,
      78,    13,    14,     0,     0,     0,   129,     0,     0,     0,
      47,    16,    17,    18,    13,    14,     0,     0,    19,    20,
       0,     0,     0,    47,    16,    17,    18,     0,     0,     0,
       0,    19,    20,    66,    67,    68,    69,    70,    71,     0,
       0,    21,     0,     0,    22,     0,    48,    66,    67,    68,
      69,    70,    71,     0,    21,     0,     0,    22,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,     0,
       0,    77,    78,     0,     0,    79,     0,     0,    72,    73,
      74,    75,    76,     0,     0,    77,    78,     0,     0,    86,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,     0,     0,    77,    78,
       0,     0,   116,    72,    73,    74,    75,    76,     0,     0,
      77,    78
};

static const yytype_int16 yycheck[] =
{
      24,     2,    17,    59,    60,    29,    11,    14,     0,    24,
       3,     4,     5,    17,     7,    49,    58,    22,     0,     1,
      24,     3,     4,     5,    58,     7,     8,    58,    10,    11,
      12,    24,    37,    15,    16,    98,    62,    63,   101,    17,
      45,    46,    24,    25,    26,    27,    24,    60,    61,    54,
      32,    33,    62,    63,    58,    24,    61,    60,    61,    58,
      49,    62,    58,    61,     3,     4,     5,    58,     7,    56,
      63,    24,    77,    55,    24,    80,    58,    82,    60,    61,
      87,    88,   106,   107,    89,    24,    91,    63,     3,     4,
       5,     9,     7,     8,    60,    10,    11,    60,    24,   100,
      15,    16,     3,     4,     5,    88,     7,   131,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      59,    -1,    -1,    24,    -1,    -1,     3,     4,     5,    -1,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    15,    16,
      55,    -1,    -1,    58,    59,    60,    61,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    33,    -1,    59,     3,
       4,     5,    -1,     7,     3,     4,     5,    -1,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    15,    16,    55,    -1,
      24,    58,    59,    60,    61,    24,    25,    26,    27,    15,
      16,    -1,    -1,    32,    33,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    32,    33,    18,    19,
      20,    21,    22,    23,    -1,    -1,    55,    -1,    -1,    58,
      -1,    60,    61,     3,     4,     5,    -1,     7,    -1,    55,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    -1,    49,
      50,    51,    52,    53,    24,    -1,    56,    57,    18,    19,
      20,    21,    22,    23,    64,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    -1,    -1,    56,    57,    49,    50,
      51,    52,    53,    -1,    64,    56,    57,    49,    50,    51,
      52,    53,    63,    -1,    56,    57,    -1,    -1,    -1,    -1,
      -1,    63,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,
      56,    57,    49,    50,    51,    52,    53,    63,    -1,    56,
      57,    15,    16,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      24,    25,    26,    27,    15,    16,    -1,    -1,    32,    33,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    32,    33,    18,    19,    20,    21,    22,    23,    -1,
      -1,    55,    -1,    -1,    58,    -1,    60,    18,    19,    20,
      21,    22,    23,    -1,    55,    -1,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      -1,    56,    57,    -1,    -1,    60,    -1,    -1,    49,    50,
      51,    52,    53,    -1,    -1,    56,    57,    -1,    -1,    60,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    -1,    -1,    56,    57,
      -1,    -1,    60,    49,    50,    51,    52,    53,    -1,    -1,
      56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     1,     3,     4,     5,     7,     8,
      10,    11,    12,    15,    16,    24,    25,    26,    27,    32,
      33,    55,    58,    60,    61,    69,    71,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    84,    85,    86,
      87,    88,    89,    59,    60,    58,    58,    24,    60,    82,
      24,     7,    24,    71,    58,    82,    59,    74,    77,    17,
      24,    49,    58,    72,    59,    77,    18,    19,    20,    21,
      22,    23,    49,    50,    51,    52,    53,    56,    57,    60,
      83,    82,    62,    63,    82,    82,    60,    61,    68,    58,
      58,    56,    63,    82,    63,    24,    82,    24,    63,    74,
      62,    63,    82,    24,    82,    82,    63,    63,    59,    70,
      71,    59,    70,    82,    63,    82,    60,    60,    76,    74,
      60,    76,    64,    77,    77,    60,    17,    24,    60,    63,
      64,     9,    24,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    78,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    89,    89,    89,
      89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     3,
       3,     4,     4,     2,     3,     1,     1,     1,     1,     1,
       2,     3,     4,     4,     4,     4,     2,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     4,
       5,     7,     5,     2,     3,     3,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     5,
       3,     3,     2,     3,     1,     4,     3,     1,     1,     1,
       1
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
#line 51 "parser.y" /* yacc.c:1646  */
    { parser::root = (yyvsp[0]); }
#line 1436 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1442 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1448 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1454 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 6:
#line 61 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1460 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 63 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-2]); }
#line 1466 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 65 "parser.y" /* yacc.c:1646  */
    { (yyval) = new_parseroot(); }
#line 1472 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));}
#line 1479 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));}
#line 1486 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_TYPEID);
                (yyval) = (yyvsp[-3])->adopt((yyvsp[-2]), (yyvsp[-1]));}
#line 1494 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]), (yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_TYPEID);
                (yyval) = (yyvsp[-3])->adopt((yyvsp[-2]));}
#line 1502 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 87 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_FIELD);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1509 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_FIELD);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1516 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1522 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1528 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1534 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1540 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_TYPEID); }
#line 1546 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 102 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_PARAMLIST);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[0]));}
#line 1553 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 105 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));}
#line 1560 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 110 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                (yyval) = new astree(TOK_FUNCTION, (yyvsp[-3])->lloc, "");
                (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));
                (yyval) = (yyval)->adopt((yyvsp[0]));}
#line 1569 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 115 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]), (yyvsp[0]));
                (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[-3])->lloc, "");
                (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));}
#line 1577 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 119 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_PARAMLIST);
                (yyval) = new astree(TOK_FUNCTION, (yyvsp[-3])->lloc, "");
                (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));
                (yyval) = (yyval)->adopt((yyvsp[0]));}
#line 1587 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]), (yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_PARAMLIST);
                (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[-3])->lloc, "");
                (yyval) = (yyval)->adopt((yyvsp[-3]), (yyvsp[-2]));}
#line 1596 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_DECLID);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[0]));}
#line 1603 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_DECLID);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1610 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_BLOCK);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[0]));}
#line 1617 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[0])); }
#line 1623 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 147 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_BLOCK);}
#line 1630 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_BLOCK);}
#line 1637 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1643 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1649 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1655 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1661 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1667 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 160 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-1]);}
#line 1674 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1680 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 166 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_VARDECL);
                (yyval) = (yyvsp[-2])->adopt((yyvsp[-3]), (yyvsp[-1]));}
#line 1688 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 172 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-3]), (yyvsp[-1]));
                (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1695 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 177 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-5]), (yyvsp[-3]));
                (yyvsp[-6])->swap_sym((yyvsp[-6]), TOK_IFELSE);
                (yyval) = (yyvsp[-6])->adopt((yyvsp[-4]), (yyvsp[-2]));
                (yyval) = (yyval)->adopt((yyvsp[0]));}
#line 1704 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 182 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-3]), (yyvsp[-1]));
                (yyval) = (yyvsp[-4])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1711 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 187 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_RETURNVOID);}
#line 1718 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 190 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-2])->adopt((yyvsp[-1]));}
#line 1725 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0])); }
#line 1731 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 197 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyval)->adopt((yyvsp[0])); }
#line 1737 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 199 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1743 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 201 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1749 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 203 "parser.y" /* yacc.c:1646  */
    {  destroy((yyvsp[-2]), (yyvsp[0]));
                 (yyval) = (yyvsp[-1]);
              }
#line 1757 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 207 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1763 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 209 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1769 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 212 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1775 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1781 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 214 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1787 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 215 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1793 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 216 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1799 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 217 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1805 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 218 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1811 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 219 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1817 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 220 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1823 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 221 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1829 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 222 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1835 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 225 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1841 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 226 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1847 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 65:
#line 227 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1853 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 228 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1859 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 232 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]), (yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_TYPEID);
                (yyval) = (yyvsp[-3])->adopt((yyvsp[-2]));}
#line 1867 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 236 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-2]), (yyvsp[0]));
                (yyvsp[-4]) = (yyvsp[-4])->swap_sym((yyvsp[-4]), TOK_NEWSTRING);
                (yyval) = (yyvsp[-4])->adopt((yyvsp[-1]));}
#line 1875 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 240 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-2]), (yyvsp[0]));
                (yyvsp[-4]) = (yyvsp[-4])->swap_sym((yyvsp[-4]), TOK_NEWARRAY);
                (yyval) = (yyvsp[-4])->adopt((yyvsp[-3]), (yyvsp[-1]));}
#line 1883 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 246 "parser.y" /* yacc.c:1646  */
    { (yyvsp[-1]) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_CALL);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1890 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 249 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[-1]));
                (yyval) = (yyvsp[-2])->adopt((yyvsp[0]));}
#line 1897 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 254 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyval) = (yyvsp[-1]);}
#line 1904 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 257 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyvsp[-1]) = (yyvsp[-1])->swap_sym((yyvsp[-1]), TOK_CALL);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]));}
#line 1912 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 263 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1918 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 265 "parser.y" /* yacc.c:1646  */
    { destroy((yyvsp[0]));
                (yyvsp[-2]) = (yyvsp[-2])->swap_sym((yyvsp[-2]), TOK_INDEX);
                (yyval) = (yyvsp[-2])->adopt((yyvsp[-3]), (yyvsp[-1]));}
#line 1926 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 76:
#line 269 "parser.y" /* yacc.c:1646  */
    { (yyvsp[0]) = (yyvsp[0])->swap_sym((yyvsp[0]), TOK_FIELD);
                (yyval) = (yyvsp[-1])->adopt((yyvsp[-2]), (yyvsp[0]));}
#line 1933 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 273 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1939 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 274 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1945 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 275 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1951 "yyparse.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 276 "parser.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1957 "yyparse.cc" /* yacc.c:1646  */
    break;


#line 1961 "yyparse.cc" /* yacc.c:1646  */
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
#line 279 "parser.y" /* yacc.c:1906  */


const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

const char *get_yytname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}



