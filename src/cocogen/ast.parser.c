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
#line 1 "ast.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "cocogen/ast.h"
#include "cocogen/create-ast.h"

#include "ast.lexer.h"

#include "lib/array.h"
#include "lib/imap.h"
#include "lib/print.h"
#include "lib/str.h"

extern bool yy_lex_keywords;

/* Array to append config entries to during reducing */
static array *config_phases;
static array *config_passes;
static array *config_enums;
static array *config_traversals;
static array *config_nodesets;
static array *config_nodes;

static struct Config* parse_result = NULL;

char *yy_filename;
array *yy_lines;
imap_t *yy_parser_locations;

void yyerror(const char* s);
int yydebug = 1;

#define YYLTYPE YYLTYPE
typedef struct ParserLocation YYLTYPE;

struct ParserLocation yy_parser_location;

static void new_location(void *ptr, struct ParserLocation *loc);

// Override YYLLOC_DEFAULT so we can set yy_parser_location
// to the current location
#define YYLLOC_DEFAULT(Cur, Rhs, N)                         \
    if (N) {                                                \
        (Cur).first_line   = YYRHSLOC(Rhs, 1).first_line;   \
        (Cur).first_column = YYRHSLOC(Rhs, 1).first_column; \
        (Cur).last_line    = YYRHSLOC(Rhs, N).last_line;    \
        (Cur).last_column  = YYRHSLOC(Rhs, N).last_column;  \
    } else {                                                \
        (Cur).first_line   = (Cur).last_line   =            \
          YYRHSLOC(Rhs, 0).last_line;                       \
        (Cur).first_column = (Cur).last_column =            \
          YYRHSLOC(Rhs, 0).last_column;                     \
    }                                                       \
    yy_parser_location = (Cur);


#line 127 "ast.parser.c" /* yacc.c:339  */

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
   by #include "ast.parser.h".  */
#ifndef YY_YY_AST_PARSER_H_INCLUDED
# define YY_YY_AST_PARSER_H_INCLUDED
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
    END = 0,
    T_INTVAL = 258,
    T_UINTVAL = 259,
    T_FLOATVAL = 260,
    T_CHARVAL = 261,
    T_STRINGVAL = 262,
    T_ID = 263,
    T_INT = 264,
    T_UINT = 265,
    T_INT8 = 266,
    T_INT16 = 267,
    T_INT32 = 268,
    T_INT64 = 269,
    T_UINT8 = 270,
    T_UINT16 = 271,
    T_UINT32 = 272,
    T_UINT64 = 273,
    T_BOOL = 274,
    T_TRUE = 275,
    T_FALSE = 276,
    T_ATTRIBUTES = 277,
    T_CHILDREN = 278,
    T_CONSTRUCTOR = 279,
    T_CYCLE = 280,
    T_ENUM = 281,
    T_MANDATORY = 282,
    T_NODE = 283,
    T_NODES = 284,
    T_NODESET = 285,
    T_PASS = 286,
    T_PASSES = 287,
    T_PHASE = 288,
    T_PHASES = 289,
    T_ACTIONS = 290,
    T_PREFIX = 291,
    T_INFO = 292,
    T_FUNC = 293,
    T_ROOT = 294,
    T_START = 295,
    T_SUBPHASES = 296,
    T_TO = 297,
    T_TRAVERSAL = 298,
    T_FLOAT = 299,
    T_DOUBLE = 300,
    T_STRING = 301,
    T_VALUES = 302,
    T_NULL = 303,
    T_LIFETIME = 304,
    T_DISALLOWED = 305,
    T_GATE = 306,
    T_ARROW = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 62 "ast.y" /* yacc.c:355  */

    int64_t intval;
    uint64_t uintval;
    long double fval;
    char *string;
    char *str;
    struct array *array;
    struct Config *config;
    struct Phase *phase;
    struct Pass *pass;
    struct Traversal *traversal;
    struct Enum *attr_enum;
    struct Nodeset *nodeset;
    struct SetExpr *setexpr;
    struct SetOperation *setoperation;
    struct Action *action;
    struct Lifetime *lifetime;
    struct Range_spec *range_spec;
    struct Node *node;
    struct Child *child;
    struct PhaseRange *phaserange;
    struct MandatoryPhase *mandatoryphase;
    enum AttrType attrtype;
    struct Attr *attr;
    struct AttrValue *attrval;

#line 248 "ast.parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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

#endif /* !YY_YY_AST_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 279 "ast.parser.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  325

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,     2,
      61,    62,     2,     2,    59,    54,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    56,
       2,    57,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    55,    60,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   175,   175,   184,   185,   186,   190,   191,   192,   193,
     194,   195,   198,   204,   208,   213,   217,   222,   228,   233,
     238,   247,   253,   258,   267,   271,   275,   279,   286,   292,
     298,   304,   312,   319,   327,   334,   340,   347,   353,   359,
     365,   371,   378,   385,   392,   399,   407,   414,   420,   427,
     434,   442,   454,   453,   464,   470,   477,   485,   490,   495,
     500,   507,   511,   515,   521,   527,   534,   545,   550,   555,
     560,   566,   572,   581,   585,   592,   597,   602,   609,   613,
     620,   625,   630,   635,   642,   647,   654,   659,   663,   670,
     675,   679,   686,   693,   699,   708,   715,   722,   729,   736,
     744,   747,   753,   761,   766,   771,   778,   784,   793,   795,
     797,   799,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   819,   822,   824,   826,   828,   830,   832,   834,   836,
     841,   848,   858
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"End-of-file (EOF)\"", "error", "$undefined", "\"integer value\"",
  "\"unsigned integer value\"", "\"float value\"", "\"char value\"",
  "\"string value\"", "\"identifier\"", "\"int\"", "\"uint\"", "\"int8\"",
  "\"int16\"", "\"int32\"", "\"int64\"", "\"uint8\"", "\"uint16\"",
  "\"uint32\"", "\"uint64\"", "\"bool\"", "\"true\"", "\"false\"",
  "\"attributes\"", "\"children\"", "\"construct\"", "\"cycle\"",
  "\"enum\"", "\"mandatory\"", "\"node\"", "\"nodes\"", "\"nodeset\"",
  "\"pass\"", "\"passes\"", "\"phase\"", "\"phases\"", "\"actions\"",
  "\"prefix\"", "\"info\"", "\"func\"", "\"root\"", "\"start\"",
  "\"subphases\"", "\"to\"", "\"traversal\"", "\"float\"", "\"double\"",
  "\"string\"", "\"values\"", "\"NULL\"", "\"lifetime\"", "\"disallowed\"",
  "\"gate\"", "\"->\"", "'&'", "'-'", "'|'", "';'", "'='", "'{'", "','",
  "'}'", "'('", "')'", "'.'", "'['", "']'", "$accept", "root", "entries",
  "entry", "prefix", "phase", "actionsbody", "actions", "action",
  "phaseheader", "pass", "traversal", "func", "traversalnodes", "enum",
  "enumvalues", "$@1", "nodeset", "setexpr", "setoperation", "node",
  "nodebody", "lifetimelistwithvalues", "lifetimewithvalues",
  "lifetimelist", "lifetime", "namespacelist", "rangespec_start",
  "rangespec_end", "children", "childlist", "child", "attrs", "attrlist",
  "attr", "attrhead", "attrprimitivetype", "attrval", "idlist", "info", YY_NULLPTR
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
     305,   306,   307,    38,    45,   124,    59,    61,   123,    44,
     125,    40,    41,    46,    91,    93
};
# endif

#define YYPACT_NINF -240

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-240)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     132,    20,    25,    43,    50,    66,    68,    55,    52,    90,
     127,  -240,    77,  -240,    79,  -240,  -240,  -240,  -240,  -240,
    -240,    84,   103,    86,    97,  -240,   156,   158,   162,   116,
    -240,   132,     1,    53,    93,     9,    51,   181,   143,   165,
    -240,  -240,     9,   143,  -240,   145,    37,   166,   161,   167,
     169,   168,   170,   172,   173,   -20,   174,  -240,   175,  -240,
     220,     9,   123,  -240,   178,   177,  -240,   180,   182,    93,
     123,   183,   184,   224,   230,   205,    40,   236,   238,   188,
     211,    17,    94,   240,   191,  -240,   228,   159,  -240,   124,
     123,   189,     9,     9,     9,     9,   223,   215,   218,   195,
      -4,   218,  -240,   197,   199,   198,   202,    60,   200,   203,
    -240,  -240,   204,   206,   207,   256,  -240,  -240,  -240,  -240,
    -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
     126,  -240,   130,   257,   259,   131,  -240,   -11,  -240,   209,
    -240,   261,  -240,  -240,  -240,  -240,  -240,    71,   213,   214,
     133,  -240,   216,   217,   135,   212,   137,   205,    89,  -240,
     267,   269,   205,  -240,   231,   220,   271,   272,   241,  -240,
      94,  -240,    39,   258,  -240,   225,   240,  -240,    92,    92,
     139,  -240,   228,  -240,  -240,     9,   273,   246,  -240,     9,
     277,   260,  -240,  -240,    -4,  -240,   226,  -240,  -240,     5,
     232,  -240,  -240,   233,   234,   227,   235,   141,   237,   239,
     242,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,  -240,
    -240,   144,    -9,  -240,   282,   282,   244,   248,   -11,   243,
    -240,    81,   245,   247,   123,  -240,   249,   146,   250,  -240,
    -240,   251,  -240,   -16,   205,  -240,  -240,  -240,  -240,   231,
     283,    -1,  -240,   148,   150,  -240,   252,   252,     4,     4,
    -240,  -240,  -240,  -240,   286,  -240,   260,  -240,  -240,  -240,
      91,   253,   254,   262,   263,    88,   152,  -240,  -240,   -11,
    -240,     0,  -240,   293,  -240,    30,  -240,  -240,   264,   265,
     295,   205,  -240,  -240,  -240,  -240,   268,   266,    -1,  -240,
     154,   270,  -240,  -240,  -240,  -240,  -240,   274,   275,   220,
       4,  -240,  -240,  -240,   205,  -240,   157,   255,   276,  -240,
     279,  -240,   220,   160,  -240
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     6,     0,     7,     8,     9,    10,    11,
      29,     0,     0,     0,    35,    28,     0,     0,     0,    37,
       1,     5,     0,     0,     0,     0,     0,     0,     0,     0,
      31,    30,     0,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    68,    69,     0,    60,
       0,     0,    56,    57,     0,     0,    36,     0,     0,     0,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    64,     0,     0,   131,     0,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
     132,    52,     0,     0,     0,     0,   108,   113,   109,   110,
     111,   112,   114,   115,   116,   117,   120,   118,   119,   121,
       0,   102,     0,     0,     0,     0,    94,     0,    67,    71,
      72,     0,    59,    58,    62,    63,    61,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,    15,     0,     0,     0,     0,     0,   107,
       0,   100,     0,     0,   106,    95,     0,    92,    83,    81,
       0,    79,     0,   130,    54,     0,     0,     0,    34,     0,
       0,     0,    38,    40,     0,    41,     0,    27,    26,     0,
       0,    25,    24,     0,     0,     0,     0,     0,     0,     0,
       0,   101,   123,   124,   125,   122,   126,   127,   128,   129,
     105,     0,     0,    93,    87,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    47,    46,     0,     0,     0,    19,
      21,     0,    23,     0,     0,    13,    48,    53,    49,     0,
       0,     0,   104,     0,     0,    85,    86,    88,     0,     0,
      78,    66,    55,    32,     0,    39,     0,    42,    44,    22,
       0,     0,     0,     0,     0,    81,     0,    74,    76,     0,
      98,     0,    99,     0,    90,     0,    82,    80,     0,     0,
       0,     0,    14,    18,    50,    51,     0,     0,     0,   103,
       0,     0,    84,    89,    91,    33,    43,     0,     0,     0,
       0,    73,    96,    97,     0,    16,     0,    80,     0,    77,
       0,    17,     0,     0,    75
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -240,  -240,   280,  -240,   -29,  -137,   -76,  -240,   107,  -240,
    -136,  -126,   114,  -184,  -240,   -80,  -240,  -240,   -38,   278,
    -240,   281,  -240,    18,  -211,  -220,    -3,  -176,  -239,   284,
    -240,   151,   -81,  -240,   147,  -240,  -240,  -240,  -163,    85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    47,    13,   105,   199,   200,    14,
      15,    16,   154,   155,    17,    51,   165,    18,    62,    63,
      19,    55,   276,   277,   180,   181,   285,   226,   286,    56,
     135,   136,    57,   130,   131,   132,   133,   220,    89,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     108,   114,   207,   227,    70,   138,   140,   236,   260,    67,
     238,   254,   255,   197,    71,   253,   178,    59,   178,   104,
     287,   198,   201,    90,   301,   152,   178,   178,    20,    84,
       1,   278,   202,    21,   153,   270,     5,    45,     6,   179,
      85,   179,   212,   213,   214,     8,   215,   216,     9,   275,
     179,    22,    46,   113,   144,   145,   146,   147,    23,   217,
     218,   260,   198,   201,    50,   240,   284,    60,   300,   150,
      61,   317,   156,   202,    24,   104,    25,    27,   278,   106,
      64,   196,   289,    26,   206,    28,   205,   219,    49,    48,
      49,   107,   303,   283,    74,   304,    75,   197,    29,   297,
      50,   230,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,     1,    53,    54,   161,    52,   162,
       5,    65,     6,    68,    92,    93,    94,    30,    72,     8,
      49,   184,     9,    31,    92,    93,    94,    32,   127,   128,
     129,   262,    33,    35,    36,   296,   316,   231,   290,   224,
     291,   234,   225,   224,    37,    38,   225,     1,     2,   323,
       3,    34,     4,     5,    39,     6,    40,   271,   272,   273,
      41,     7,     8,    42,    43,     9,    92,    93,    94,    45,
      49,    53,    54,   141,   142,   170,   171,   172,   173,    66,
     176,   177,   187,   188,   191,   192,   194,   195,   228,   229,
     141,   247,    73,   251,   252,   266,   267,   279,   280,   281,
     282,   298,   299,   228,   312,   308,   141,   319,    77,   141,
     324,   256,   257,    69,    78,    76,    79,    80,    88,    81,
      82,    83,   102,    86,    87,    95,    96,   103,   318,    97,
     104,    98,   100,   101,   109,   110,   111,   112,   134,   137,
      53,   143,   148,   149,    45,   151,   157,   158,   159,   160,
     163,   166,   164,   167,   169,   174,   168,   175,   182,   183,
     185,   186,   193,   189,   190,   203,   204,   210,    50,   208,
     209,   232,   221,   222,   233,   235,   239,   245,   242,   152,
     255,   274,   243,   244,   288,   246,   258,   248,   249,   250,
     259,   302,   307,   261,   264,   263,   241,   269,   237,   265,
     268,    44,   320,   292,   293,   283,   311,   211,   310,     0,
       0,     0,   294,   295,   305,   306,   309,   223,     0,     0,
     313,     0,     0,   314,     0,   315,   321,   322,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   139
};

static const yytype_int16 yycheck[] =
{
      76,    81,   165,   179,    42,    86,    87,   191,   228,    38,
     194,   222,     8,     8,    43,    24,    27,     8,    27,    35,
     259,   158,   158,    61,    24,    29,    27,    27,     8,    49,
      25,   251,   158,     8,    38,    51,    31,    36,    33,    50,
      60,    50,     3,     4,     5,    40,     7,     8,    43,    50,
      50,     8,    51,    36,    92,    93,    94,    95,     8,    20,
      21,   281,   199,   199,    47,    60,    62,    58,   279,    98,
      61,   310,   101,   199,     8,    35,     8,    25,   298,    39,
      29,   157,   266,    28,   164,    33,   162,    48,    37,    36,
      37,    51,    62,    63,    57,    65,    59,     8,     8,   275,
      47,   182,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    25,    22,    23,    57,    33,    59,
      31,    36,    33,    38,    53,    54,    55,     0,    43,    40,
      37,    60,    43,    56,    53,    54,    55,    58,    44,    45,
      46,    60,    58,    57,    58,    57,   309,   185,    57,    61,
      59,   189,    64,    61,    57,    58,    64,    25,    26,   322,
      28,    58,    30,    31,     8,    33,     8,   243,   244,   249,
       8,    39,    40,    57,    58,    43,    53,    54,    55,    36,
      37,    22,    23,    59,    60,    59,    60,    57,    58,     8,
      59,    60,    59,    60,    59,    60,    59,    60,    59,    60,
      59,    60,    57,    59,    60,    59,    60,    59,    60,    59,
      60,    59,    60,    59,    60,   291,    59,    60,    57,    59,
      60,   224,   225,    58,    57,    59,    57,    59,     8,    59,
      58,    58,     8,    59,    59,    57,    59,     7,   314,    59,
      35,    59,    59,    59,     8,     7,    58,    36,     8,    58,
      22,    62,    29,    38,    36,    60,    59,    58,    60,    57,
      60,    57,    59,    57,     8,     8,    59,     8,    59,     8,
      57,    57,    60,    57,    57,     8,     7,    36,    47,     8,
       8,     8,    24,    58,    38,     8,    60,    60,    56,    29,
       8,     8,    59,    59,     8,    60,    52,    60,    59,    57,
      52,     8,     7,    60,    57,    60,   199,    56,   194,    60,
      60,    31,    57,    60,    60,    63,   298,   170,    52,    -1,
      -1,    -1,    60,    60,    60,    60,    58,   176,    -1,    -1,
      60,    -1,    -1,    59,    -1,    60,    60,    58,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    28,    30,    31,    33,    39,    40,    43,
      67,    68,    69,    71,    75,    76,    77,    80,    83,    86,
       8,     8,     8,     8,     8,     8,    28,    25,    33,     8,
       0,    56,    58,    58,    58,    57,    58,    57,    58,     8,
       8,     8,    57,    58,    68,    36,    51,    70,    36,    37,
      47,    81,   105,    22,    23,    87,    95,    98,   105,     8,
      58,    61,    84,    85,    29,   105,     8,    70,   105,    58,
      84,    70,   105,    57,    57,    59,    59,    57,    57,    57,
      59,    59,    58,    58,    49,    60,    59,    59,     8,   104,
      84,    85,    53,    54,    55,    57,    59,    59,    59,    87,
      59,    59,     8,     7,    35,    72,    39,    51,    72,     8,
       7,    58,    36,    36,    81,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    44,    45,    46,
      99,   100,   101,   102,     8,    96,    97,    58,    98,    95,
      98,    59,    60,    62,    84,    84,    84,    84,    29,    38,
      70,    60,    29,    38,    78,    79,    70,    59,    58,    60,
      57,    57,    59,    60,    59,    82,    57,    57,    59,     8,
      59,    60,    57,    58,     8,     8,    59,    60,    27,    50,
      90,    91,    59,     8,    60,    57,    57,    59,    60,    57,
      57,    59,    60,    60,    59,    60,    72,     8,    71,    73,
      74,    76,    77,     8,     7,    72,    81,   104,     8,     8,
      36,   100,     3,     4,     5,     7,     8,    20,    21,    48,
     103,    24,    58,    97,    61,    64,    93,    93,    59,    60,
      98,    84,     8,    38,    84,     8,    79,    78,    79,    60,
      60,    74,    56,    59,    59,    60,    60,    60,    60,    59,
      57,    59,    60,    24,    90,     8,    92,    92,    52,    52,
      91,    60,    60,    60,    57,    60,    59,    60,    60,    56,
      51,    72,    72,    81,     8,    50,    88,    89,    91,    59,
      60,    59,    60,    63,    62,    92,    94,    94,     8,    79,
      57,    59,    60,    60,    60,    60,    57,    93,    59,    60,
      90,    24,     8,    62,    65,    60,    60,     7,    72,    58,
      52,    89,    60,    60,    59,    60,   104,    94,    72,    60,
      57,    60,    58,   104,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    73,    73,    74,    74,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    78,    79,    80,    80,
      80,    80,    82,    81,    83,    83,    83,    84,    84,    84,
      84,    85,    85,    85,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    89,    90,    90,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    94,
      94,    94,    95,    96,    96,    97,    97,    97,    97,    97,
      98,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     104,   104,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     1,     1,     1,     1,
       1,     1,     3,     8,    10,     6,    12,    14,    10,     8,
       6,     4,     3,     2,     1,     1,     1,     1,     2,     2,
       3,     3,     9,    11,     7,     2,     4,     2,     7,     9,
       7,     7,     9,    11,     9,     4,     3,     3,     9,     9,
      11,    11,     0,     6,     7,     9,     4,     1,     3,     3,
       1,     3,     3,     3,     5,     6,     9,     3,     1,     1,
       5,     3,     3,     3,     1,     8,     1,     5,     3,     1,
       4,     1,     4,     1,     3,     1,     2,     1,     2,     2,
       1,     2,     4,     3,     1,     2,     7,     7,     5,     5,
       4,     3,     1,     6,     4,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3
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
  YYUSE (yytype);
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
#line 175 "ast.y" /* yacc.c:1646  */
    { parse_result = create_config(config_phases,
                                 config_passes,
                                 config_traversals,
                                 config_enums,
                                 config_nodesets,
                                 config_nodes);
              }
#line 1689 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 190 "ast.y" /* yacc.c:1646  */
    { array_append(config_phases, (yyvsp[0].phase)); }
#line 1695 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 191 "ast.y" /* yacc.c:1646  */
    { array_append(config_passes, (yyvsp[0].pass)); }
#line 1701 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 192 "ast.y" /* yacc.c:1646  */
    { array_append(config_traversals, (yyvsp[0].traversal)); }
#line 1707 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 193 "ast.y" /* yacc.c:1646  */
    { array_append(config_enums, (yyvsp[0].attr_enum)); }
#line 1713 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 194 "ast.y" /* yacc.c:1646  */
    { array_append(config_nodesets, (yyvsp[0].nodeset)); }
#line 1719 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 195 "ast.y" /* yacc.c:1646  */
    { array_append(config_nodes, (yyvsp[0].node));  }
#line 1725 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 199 "ast.y" /* yacc.c:1646  */
    {
          (yyval.string) = (yyvsp[0].string);
          new_location((yyval.string), &(yyloc));
      }
#line 1734 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-7].phase), NULL, (yyvsp[-5].string), (yyvsp[-1].array), ccn_str_cat((yyvsp[-7].phase)->id, "_gate"));
     }
#line 1742 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 209 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-9].phase), (yyvsp[-3].string), (yyvsp[-7].string), (yyvsp[-1].array), NULL);
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 1751 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 214 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-5].phase), NULL, (yyvsp[-3].string), (yyvsp[-1].array), NULL);
     }
#line 1759 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 218 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-11].phase), (yyvsp[-5].string), (yyvsp[-9].string), (yyvsp[-1].array), ccn_str_cat((yyvsp[-11].phase)->id, "_gate"));
         new_location((yyvsp[-5].string), &(yylsp[-5]));
     }
#line 1768 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 223 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-13].phase), (yyvsp[-7].string), (yyvsp[-11].string), (yyvsp[-1].array), (yyvsp[-3].string));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
         new_location((yyvsp[-7].string), &(yylsp[-7]));
     }
#line 1778 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-9].phase), NULL, (yyvsp[-7].string), (yyvsp[-1].array), (yyvsp[-3].string));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 1787 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 234 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-7].phase), NULL, NULL, (yyvsp[-1].array), (yyvsp[-3].string));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 1796 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 239 "ast.y" /* yacc.c:1646  */
    {
         (yyval.phase) = create_phase((yyvsp[-5].phase), NULL, NULL, (yyvsp[-1].array), ccn_str_cat((yyvsp[-5].phase)->id, "_gate"));
     }
#line 1804 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "ast.y" /* yacc.c:1646  */
    {
         (yyval.array) = (yyvsp[-1].array);
     }
#line 1812 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 254 "ast.y" /* yacc.c:1646  */
    {
           array_append((yyvsp[-2].array), (yyvsp[-1].action));
           (yyval.array) = (yyvsp[-2].array);
       }
#line 1821 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 259 "ast.y" /* yacc.c:1646  */
    {
           array *tmp = create_array();
           array_append(tmp, (yyvsp[-1].action));
           (yyval.array) = tmp;
       }
#line 1831 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 268 "ast.y" /* yacc.c:1646  */
    {
          (yyval.action) = create_action(ACTION_TRAVERSAL, (yyvsp[0].traversal), (yyvsp[0].traversal)->id);
      }
#line 1839 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 272 "ast.y" /* yacc.c:1646  */
    {
          (yyval.action) = create_action(ACTION_PASS, (yyvsp[0].pass), (yyvsp[0].pass)->id);
      }
#line 1847 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 276 "ast.y" /* yacc.c:1646  */
    {
          (yyval.action) = create_action(ACTION_PHASE, (yyvsp[0].phase), (yyvsp[0].phase)->id);
      }
#line 1855 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 280 "ast.y" /* yacc.c:1646  */
    {
          (yyval.action) = create_action(ACTION_REFERENCE, (yyvsp[0].string), (yyvsp[0].string));
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 1864 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 287 "ast.y" /* yacc.c:1646  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), false, false);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1874 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 293 "ast.y" /* yacc.c:1646  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), false, true);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1884 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 299 "ast.y" /* yacc.c:1646  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), true, false);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1894 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 305 "ast.y" /* yacc.c:1646  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), true, true);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1904 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 313 "ast.y" /* yacc.c:1646  */
    {
        (yyval.pass) = create_pass((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-5].string));
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 1915 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 320 "ast.y" /* yacc.c:1646  */
    {
        (yyval.pass) = create_pass((yyvsp[-9].string), (yyvsp[-1].string), (yyvsp[-5].string));
        (yyval.pass)->info = (yyvsp[-7].string);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 1927 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 328 "ast.y" /* yacc.c:1646  */
    {
        (yyval.pass) = create_pass((yyvsp[-5].string), NULL, (yyvsp[-1].string));
        (yyval.pass)->info = (yyvsp[-3].string);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-5].string), &(yylsp[-5]));
    }
#line 1938 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 335 "ast.y" /* yacc.c:1646  */
    {
        (yyval.pass) = create_pass((yyvsp[0].string), NULL, NULL);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 1948 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 341 "ast.y" /* yacc.c:1646  */
    {
        (yyval.pass) = create_pass((yyvsp[-2].string), (yyvsp[0].string), NULL);
    }
#line 1956 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 348 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[0].string), NULL, NULL, NULL);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[0].string), &(yylsp[0]));
         }
#line 1966 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 354 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), (yyvsp[-1].string), (yyvsp[-3].string), NULL);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 1976 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 360 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), (yyvsp[-3].string), (yyvsp[-5].string), (yyvsp[-1].setexpr));
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 1986 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 366 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), NULL, (yyvsp[-3].string), (yyvsp[-1].setexpr));
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 1996 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 372 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), NULL, (yyvsp[-1].string), NULL);
             (yyval.traversal)->info = (yyvsp[-3].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 2007 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 379 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-3].string), NULL);
             (yyval.traversal)->info = (yyvsp[-5].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 2018 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 386 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-9].string), (yyvsp[-3].string), (yyvsp[-5].string), (yyvsp[-1].setexpr));
             (yyval.traversal)->info = (yyvsp[-7].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-9].string), &(yylsp[-9]));
         }
#line 2029 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 393 "ast.y" /* yacc.c:1646  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), NULL, (yyvsp[-3].string), (yyvsp[-1].setexpr));
             (yyval.traversal)->info = (yyvsp[-5].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 2040 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 400 "ast.y" /* yacc.c:1646  */
    {
            (yyval.traversal) = create_traversal((yyvsp[-2].string), NULL, NULL, (yyvsp[0].setexpr));
            new_location((yyval.traversal), &(yyloc));
            new_location((yyvsp[-2].string), &(yylsp[-2]));
         }
#line 2050 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 408 "ast.y" /* yacc.c:1646  */
    {
        (yyval.string) = (yyvsp[0].string);
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 2059 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 415 "ast.y" /* yacc.c:1646  */
    {
                  (yyval.setexpr) = (yyvsp[0].setexpr);
              }
#line 2067 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 421 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-7].string), (yyvsp[-3].string), (yyvsp[-1].array));
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2078 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 428 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-5].array));
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-1].string), &(yylsp[-3]));
    }
#line 2089 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 435 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-9].string), (yyvsp[-3].string), (yyvsp[-1].array));
        (yyval.attr_enum)->info = (yyvsp[-7].string);
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2101 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 443 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-9].string), (yyvsp[-1].string), (yyvsp[-5].array));
        (yyval.attr_enum)->info = (yyvsp[-7].string);
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 2113 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 454 "ast.y" /* yacc.c:1646  */
    {
            yy_lex_keywords = false;
        }
#line 2121 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 458 "ast.y" /* yacc.c:1646  */
    {
            (yyval.array) = (yyvsp[-1].array);
            yy_lex_keywords = true;
        }
#line 2130 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 465 "ast.y" /* yacc.c:1646  */
    {
            (yyval.nodeset) = create_nodeset((yyvsp[-5].string), (yyvsp[-1].setexpr));
            new_location((yyval.nodeset), &(yyloc));
            new_location((yyvsp[-5].string), &(yylsp[-5]));
        }
#line 2140 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 471 "ast.y" /* yacc.c:1646  */
    {
           (yyval.nodeset) = create_nodeset((yyvsp[-7].string), (yyvsp[-1].setexpr));
           (yyval.nodeset)->info = (yyvsp[-5].string);
           new_location((yyval.nodeset), &(yyloc));
           new_location((yyvsp[-7].string), &(yylsp[-7]));
       }
#line 2151 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 478 "ast.y" /* yacc.c:1646  */
    {
           (yyval.nodeset) = create_nodeset((yyvsp[-2].string), (yyvsp[0].setexpr));
           new_location((yyval.nodeset), &(yyloc));
           new_location((yyvsp[-2].string), &(yylsp[-2]));
       }
#line 2161 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 486 "ast.y" /* yacc.c:1646  */
    {
           (yyval.setexpr) = create_set_expr(SET_OPERATION, (yyvsp[0].setoperation));
           new_location((yyval.setexpr), &(yyloc));
       }
#line 2170 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 491 "ast.y" /* yacc.c:1646  */
    {
           (yyval.setexpr) = create_set_expr(SET_OPERATION, (yyvsp[-1].setoperation));
           new_location((yyval.setexpr), &(yyloc));
       }
#line 2179 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 496 "ast.y" /* yacc.c:1646  */
    {
           (yyval.setexpr) = create_set_expr(SET_LITERAL, (yyvsp[-1].array));
           new_location((yyval.setexpr), &(yyloc));
       }
#line 2188 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 501 "ast.y" /* yacc.c:1646  */
    {
           (yyval.setexpr) = create_set_expr(SET_REFERENCE, (yyvsp[0].string));
           new_location((yyval.setexpr), &(yyloc));
       }
#line 2197 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 508 "ast.y" /* yacc.c:1646  */
    {
                (yyval.setoperation) = create_set_operation(SET_UNION, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2205 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 512 "ast.y" /* yacc.c:1646  */
    {
                (yyval.setoperation) = create_set_operation(SET_INTERSECT, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2213 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 516 "ast.y" /* yacc.c:1646  */
    {
                (yyval.setoperation) = create_set_operation(SET_DIFFERENCE, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2221 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 522 "ast.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_node((yyvsp[-3].string), (yyvsp[-1].node));
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2231 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 528 "ast.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_node((yyvsp[-3].string), (yyvsp[-1].node));
        (yyval.node)->root = true;
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2242 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 535 "ast.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_node((yyvsp[-7].string), (yyvsp[-5].node));
        (yyval.node)->lifetimes = (yyvsp[-2].array);
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
    }
#line 2253 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 546 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody((yyvsp[-2].array), (yyvsp[0].array));
            new_location((yyval.node), &(yyloc));
        }
#line 2262 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 551 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody((yyvsp[0].array), NULL);
            new_location((yyval.node), &(yyloc));
        }
#line 2271 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 556 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody(NULL, (yyvsp[0].array));
            new_location((yyval.node), &(yyloc));
        }
#line 2280 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 561 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody((yyvsp[-2].array), (yyvsp[0].array));
            (yyval.node)->info = (yyvsp[-4].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2290 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 567 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody((yyvsp[0].array), NULL);
            (yyval.node)->info = (yyvsp[-2].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2300 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 573 "ast.y" /* yacc.c:1646  */
    {
            (yyval.node) = create_nodebody(NULL, (yyvsp[0].array));
            (yyval.node)->info = (yyvsp[-2].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2310 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 582 "ast.y" /* yacc.c:1646  */
    {
            array_append((yyval.array), (yyvsp[0].lifetime));
        }
#line 2318 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 586 "ast.y" /* yacc.c:1646  */
    {
            (yyval.array) = array_init(2);
            array_append((yyval.array), (yyvsp[0].lifetime));
        }
#line 2327 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 593 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-6].range_spec), (yyvsp[-4].range_spec), LIFETIME_DISALLOWED, (yyvsp[-1].array));
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2336 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 598 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = (yyvsp[0].lifetime);

        }
#line 2345 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 603 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_DISALLOWED, (yyvsp[-1].array));
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2354 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 610 "ast.y" /* yacc.c:1646  */
    {
                array_append((yyval.array), (yyvsp[0].lifetime));
            }
#line 2362 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 614 "ast.y" /* yacc.c:1646  */
    {
                (yyval.array) = array_init(2);
                array_append((yyval.array), (yyvsp[0].lifetime));
                new_location((yyvsp[0].lifetime), &(yylsp[0]));
            }
#line 2372 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 621 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-2].range_spec), (yyvsp[0].range_spec), LIFETIME_DISALLOWED, NULL);
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2381 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 626 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_DISALLOWED, NULL);
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2390 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 631 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-2].range_spec), (yyvsp[0].range_spec), LIFETIME_MANDATORY, NULL);
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2399 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 636 "ast.y" /* yacc.c:1646  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_MANDATORY, NULL);
            new_location((yyval.lifetime), &(yyloc));
        }
#line 2408 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 643 "ast.y" /* yacc.c:1646  */
    {
                array_append((yyvsp[-2].array), (yyvsp[0].string));
                new_location((yyvsp[0].string), &(yylsp[0]));
            }
#line 2417 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 648 "ast.y" /* yacc.c:1646  */
    {
                (yyval.array) = create_array();
                array_append((yyval.array), (yyvsp[0].string));
                new_location((yyvsp[0].string), &(yylsp[0]));
            }
#line 2427 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 655 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = create_range_spec(false, (yyvsp[0].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2436 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 660 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = NULL;
          }
#line 2444 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 664 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = create_range_spec(true, (yyvsp[0].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2453 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 671 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = create_range_spec(false, (yyvsp[-1].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2462 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 676 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = NULL;
          }
#line 2470 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 680 "ast.y" /* yacc.c:1646  */
    {
              (yyval.range_spec) = create_range_spec(true, (yyvsp[-1].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2479 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 687 "ast.y" /* yacc.c:1646  */
    {
            (yyval.array) = (yyvsp[-1].array);
            new_location((yyval.array), &(yyloc));
        }
#line 2488 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 694 "ast.y" /* yacc.c:1646  */
    {
             array_append((yyvsp[-2].array), (yyvsp[0].child));
             (yyval.array) = (yyvsp[-2].array);
             // $$ is an array and should not be in the locations list
         }
#line 2498 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 700 "ast.y" /* yacc.c:1646  */
    {
             array *tmp = create_array();
             array_append(tmp, (yyvsp[0].child));
             (yyval.array) = tmp;
             // $$ is an array and should not be in the locations list
         }
#line 2509 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 709 "ast.y" /* yacc.c:1646  */
    {
         (yyval.child) = create_child(0, NULL, (yyvsp[0].string), (yyvsp[-1].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-1].string), &(yylsp[-1]));
         new_location((yyvsp[0].string), &(yylsp[0]));
     }
#line 2520 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 716 "ast.y" /* yacc.c:1646  */
    {
         (yyval.child) = create_child(1, (yyvsp[-1].array), (yyvsp[-5].string), (yyvsp[-6].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-6].string), &(yylsp[-6]));
         new_location((yyvsp[-5].string), &(yylsp[-5]));
     }
#line 2531 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 723 "ast.y" /* yacc.c:1646  */
    {
         (yyval.child) = create_child(1, (yyvsp[-3].array), (yyvsp[-5].string), (yyvsp[-6].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-6].string), &(yylsp[-6]));
         new_location((yyvsp[-5].string), &(yylsp[-5]));
     }
#line 2542 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 730 "ast.y" /* yacc.c:1646  */
    {
         (yyval.child) = create_child(1, NULL, (yyvsp[-3].string), (yyvsp[-4].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-4].string), &(yylsp[-4]));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 2553 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 737 "ast.y" /* yacc.c:1646  */
    {
         (yyval.child) = create_child(0, (yyvsp[-1].array), (yyvsp[-3].string), (yyvsp[-4].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-4].string), &(yylsp[-4]));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 2564 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 745 "ast.y" /* yacc.c:1646  */
    { (yyval.array) = (yyvsp[-1].array); }
#line 2570 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 748 "ast.y" /* yacc.c:1646  */
    {
            array_append((yyvsp[-2].array), (yyvsp[0].attr));
            (yyval.array) = (yyvsp[-2].array);
            // $$ is an array and should not be in the locations list
        }
#line 2580 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 754 "ast.y" /* yacc.c:1646  */
    {
            array *tmp = create_array();
            array_append(tmp, (yyvsp[0].attr));
            (yyval.array) = tmp;
            // $$ is an array and should not be in the locations list
        }
#line 2591 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 762 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr) = create_attr((yyvsp[-5].attr), NULL, 1, (yyvsp[-1].array));
        new_location((yyval.attr), &(yyloc));
    }
#line 2600 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 767 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr) = create_attr((yyvsp[-3].attr), NULL, 1, NULL);
        new_location((yyval.attr), &(yyloc));
    }
#line 2609 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 772 "ast.y" /* yacc.c:1646  */
    {
        (yyval.attr) = create_attr((yyvsp[-2].attr), (yyvsp[0].attrval), 0, NULL);
        new_location((yyval.attr), &(yyloc));
    }
#line 2618 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 779 "ast.y" /* yacc.c:1646  */
    {
            (yyval.attr) = create_attrhead_primitive((yyvsp[-1].attrtype), (yyvsp[0].string));
            new_location((yyval.attr), &(yyloc));
            new_location((yyvsp[0].string), &(yylsp[0]));
        }
#line 2628 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 785 "ast.y" /* yacc.c:1646  */
    {
            (yyval.attr) = create_attrhead_idtype((yyvsp[-1].string), (yyvsp[0].string));
            new_location((yyval.attr), &(yyloc));
            new_location((yyvsp[-1].string), &(yylsp[-1]));
            new_location((yyvsp[0].string), &(yylsp[0]));
        }
#line 2639 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 794 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_int; }
#line 2645 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 796 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_int8; }
#line 2651 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 798 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_int16; }
#line 2657 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 800 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_int32; }
#line 2663 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 802 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_int64; }
#line 2669 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 804 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_uint; }
#line 2675 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 806 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_uint8; }
#line 2681 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 808 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_uint16; }
#line 2687 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 810 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_uint32; }
#line 2693 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 812 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_uint64; }
#line 2699 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 814 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_float; }
#line 2705 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 816 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_double; }
#line 2711 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 818 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_bool; }
#line 2717 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 820 "ast.y" /* yacc.c:1646  */
    { (yyval.attrtype) = AT_string; }
#line 2723 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 823 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_string((yyvsp[0].string)); }
#line 2729 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 825 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_int((yyvsp[0].intval)); }
#line 2735 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 827 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_uint((yyvsp[0].uintval)); }
#line 2741 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 829 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_float((yyvsp[0].fval)); }
#line 2747 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 831 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_id((yyvsp[0].string)); }
#line 2753 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 833 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_bool(true); }
#line 2759 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 835 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = create_attrval_bool(false); }
#line 2765 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 837 "ast.y" /* yacc.c:1646  */
    { (yyval.attrval) = NULL; }
#line 2771 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 842 "ast.y" /* yacc.c:1646  */
    {
          array_append((yyvsp[-2].array), (yyvsp[0].string));
          (yyval.array) = (yyvsp[-2].array);
          // $$ is an array and should not be added to location list.
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 2782 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 849 "ast.y" /* yacc.c:1646  */
    {
          array *tmp = create_array();
          array_append(tmp, (yyvsp[0].string));
          (yyval.array) = tmp;
          // $$ is an array and should not be added to location list.
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 2794 "ast.parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 859 "ast.y" /* yacc.c:1646  */
    {
        (yyval.string) = (yyvsp[0].string);
        new_location((yyval.string), &(yyloc));
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 2804 "ast.parser.c" /* yacc.c:1646  */
    break;


#line 2808 "ast.parser.c" /* yacc.c:1646  */
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
#line 865 "ast.y" /* yacc.c:1906  */


static void new_location(void *ptr, struct ParserLocation *loc) {
    struct ParserLocation *loc_copy = malloc(sizeof(struct ParserLocation));
    memcpy(loc_copy, loc, sizeof(struct ParserLocation));

    imap_insert(yy_parser_locations, ptr, loc_copy);
}

struct Config* parse(FILE *fp) {
    yyin = fp;
    config_phases = create_array();
    config_passes = create_array();
    config_enums = create_array();
    config_traversals = create_array();
    config_nodesets = create_array();
    config_nodes = create_array();

    yy_lines = array_init(32);
    yy_parser_locations = imap_init(128);

    print_init_compilation_messages(NULL, yy_filename,
        yy_lines, yy_parser_locations);
    yyparse();
    yylex_destroy();

    return parse_result;
}
