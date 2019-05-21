/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/cocogen/ast.y" /* yacc.c:337  */


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


#line 130 "src/cocogen/ast.parser.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
#ifndef YY_YY_SRC_COCOGEN_AST_PARSER_H_INCLUDED
# define YY_YY_SRC_COCOGEN_AST_PARSER_H_INCLUDED
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
    T_ARROW = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "src/cocogen/ast.y" /* yacc.c:352  */

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

#line 253 "src/cocogen/ast.parser.c" /* yacc.c:352  */
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

#endif /* !YY_YY_SRC_COCOGEN_AST_PARSER_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   305

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

#define YYUNDEFTOK  2
#define YYMAXUTOK   306

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
      61,    63,     2,     2,    55,    59,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    52,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,    57,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   170,   170,   179,   180,   181,   185,   186,   187,   188,
     189,   190,   193,   199,   203,   210,   216,   221,   230,   234,
     238,   242,   249,   255,   261,   267,   275,   282,   290,   297,
     306,   312,   318,   324,   330,   337,   344,   351,   360,   367,
     373,   380,   387,   395,   407,   406,   417,   423,   432,   436,
     440,   446,   450,   454,   460,   466,   473,   484,   489,   494,
     499,   505,   511,   520,   524,   531,   535,   539,   545,   549,
     555,   559,   563,   567,   573,   578,   585,   590,   594,   601,
     606,   610,   617,   624,   630,   639,   646,   653,   660,   667,
     675,   678,   684,   692,   697,   702,   709,   715,   724,   726,
     728,   730,   732,   734,   736,   738,   740,   742,   744,   746,
     748,   750,   753,   755,   757,   759,   761,   763,   765,   767,
     772,   779,   789
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
  "\"->\"", "';'", "'='", "'{'", "','", "'}'", "'|'", "'&'", "'-'", "'.'",
  "'('", "'['", "')'", "']'", "$accept", "root", "entries", "entry",
  "prefix", "phase", "actionsbody", "actions", "action", "phaseheader",
  "pass", "traversal", "func", "traversalnodes", "enum", "enumvalues",
  "$@1", "nodeset", "setexpr", "setoperation", "node", "nodebody",
  "lifetimelistwithvalues", "lifetimewithvalues", "lifetimelist",
  "lifetime", "namespacelist", "rangespec_start", "rangespec_end",
  "children", "childlist", "child", "attrs", "attrlist", "attr",
  "attrhead", "attrprimitivetype", "attrval", "idlist", "info", YY_NULLPTR
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
     305,   306,    59,    61,   123,    44,   125,   124,    38,    45,
      46,    40,    91,    41,    93
};
# endif

#define YYPACT_NINF -212

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-212)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,    15,    61,    76,    92,   119,   160,    -3,    71,   173,
      28,  -212,    65,  -212,   128,  -212,  -212,  -212,  -212,  -212,
    -212,   129,   130,   131,   132,  -212,   179,   180,   181,   136,
    -212,    -4,   155,    17,    68,    74,    20,   138,  -212,  -212,
      20,  -212,   140,   139,   142,   143,   144,   145,   146,   148,
     149,    63,   150,  -212,   151,   154,   153,   156,   157,    68,
     158,   159,   191,    59,   196,   192,   161,   174,    45,    33,
     201,   162,  -212,   195,   113,     4,   189,   182,   155,   163,
      57,   155,  -212,   167,   169,   168,   170,  -212,  -212,   175,
     176,   171,   215,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,    82,  -212,    86,
     219,   222,    87,  -212,   -10,  -212,   177,  -212,  -212,   223,
      67,  -212,   183,   184,    89,  -212,   185,   186,    91,   178,
      93,    30,   225,  -212,   188,   223,   232,   233,   206,  -212,
      33,  -212,    11,   220,  -212,   193,   201,  -212,    90,    90,
      99,  -212,   195,  -212,   101,  -212,     4,     4,     4,     4,
     235,   207,  -212,     4,   238,   221,  -212,  -212,    57,  -212,
    -212,  -212,   103,  -212,  -212,  -212,   194,   197,   105,   198,
     200,   199,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   107,    47,  -212,   240,   240,   205,   208,   -10,
     202,  -212,   243,  -212,    75,    75,    75,    72,   204,   209,
      75,  -212,   210,   109,   211,    30,  -212,   226,  -212,  -212,
    -212,   188,   249,    10,  -212,   111,   114,  -212,   203,   203,
       5,     5,  -212,  -212,  -212,  -212,  -212,   256,  -212,   221,
    -212,  -212,  -212,   212,   213,   214,    40,   116,  -212,  -212,
     -10,  -212,    56,  -212,   257,  -212,    58,  -212,  -212,   216,
     217,  -212,  -212,  -212,   224,   228,    10,  -212,   118,   218,
    -212,  -212,  -212,  -212,  -212,   223,     5,  -212,  -212,  -212,
     120,   227,  -212,   229,   223,   122,  -212
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     4,     6,     0,     7,     8,     9,    10,    11,
      23,     0,     0,     0,    29,    22,     0,     0,     0,    30,
       1,     5,     0,     0,     0,     0,     0,     0,    25,    24,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,   122,    44,     0,
       0,     0,     0,    98,   103,    99,   100,   101,   102,   104,
     105,   106,   107,   110,   108,   109,   111,     0,    92,     0,
       0,     0,     0,    84,     0,    57,    61,    62,    50,     0,
       0,    48,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,    97,
       0,    90,     0,     0,    96,    85,     0,    82,    73,    71,
       0,    69,     0,   121,     0,    46,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,    31,    33,     0,    34,
      21,    20,     0,    17,    19,    18,     0,     0,     0,     0,
       0,     0,    91,   113,   114,   115,   112,   116,   117,   118,
     119,    95,     0,     0,    83,    77,     0,     0,     0,     0,
       0,    60,     0,    49,    51,    52,    53,     0,     0,     0,
      39,    38,     0,     0,     0,     0,    15,     0,    40,    45,
      41,     0,     0,     0,    94,     0,     0,    75,    76,    78,
       0,     0,    68,    56,   120,    47,    26,     0,    32,     0,
      35,    37,    16,     0,     0,     0,    71,     0,    64,    66,
       0,    88,     0,    89,     0,    80,     0,    72,    70,     0,
       0,    14,    42,    43,     0,     0,     0,    93,     0,     0,
      74,    79,    81,    27,    36,     0,     0,    63,    86,    87,
       0,    70,    67,     0,     0,     0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,   244,  -212,    -6,  -128,    54,  -212,    62,  -212,
    -127,  -126,   108,  -157,  -212,   -68,  -212,  -212,   -49,  -212,
    -212,   230,  -212,    16,  -183,  -190,   -16,  -147,  -211,   231,
    -212,   135,   -67,  -212,   147,  -212,  -212,  -212,  -134,    80
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    43,    13,    85,   172,   173,    14,
      15,    16,   128,   129,    17,    47,   135,    18,   120,   121,
      19,    51,   247,   248,   150,   151,   256,   197,   257,    52,
     112,   113,    53,   107,   108,   109,   110,   191,   154,    54
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      91,   178,   198,   171,   174,   175,   115,   117,   212,   232,
     226,   214,   118,   227,   183,   184,   185,   148,   186,   187,
     258,     1,     2,    20,     3,    26,     4,     5,    30,     6,
      57,   188,   189,   249,    60,     7,     8,   148,   170,     9,
     149,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    44,    45,     1,    42,    45,   119,   190,
     246,     5,   232,     6,    46,   281,   177,   268,   255,    21,
       8,   225,   124,     9,   148,   130,   249,   104,   105,   106,
     269,    90,   260,   148,    22,   201,   126,   171,   174,   175,
      49,    50,    46,   264,    83,   127,    27,   149,    84,   265,
      23,   195,   196,    55,    28,    45,   149,   204,   205,   206,
     207,    45,    71,    48,   210,    56,    58,    31,   254,    72,
      61,   271,   272,   155,   156,   157,   158,    24,   235,   156,
     157,   158,   156,   157,   158,    49,    50,   140,   141,   142,
     143,   280,   146,   147,   161,   162,   165,   166,   168,   169,
     285,   195,   196,   244,   199,   200,   202,   203,   215,   216,
     202,   219,   223,   224,   239,   240,   250,   251,    25,   252,
     253,   266,   267,   199,   278,   202,   282,   202,   286,   228,
     229,    29,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    42,    59,    62,    63,    64,    65,    66,    82,    87,
      67,    68,    69,    70,    86,    73,    74,    75,    76,   111,
      89,    77,    78,    80,    81,    88,   114,    49,   122,   125,
     123,   131,   132,   139,   133,   134,   138,   144,   136,   137,
     145,   153,   152,   176,   167,    46,   159,   160,   163,   164,
     179,   180,   181,   208,   192,   209,   211,   193,   227,   217,
     126,   234,   222,   218,   220,   221,   230,   245,   233,   231,
     236,    83,   237,   254,   259,   270,   238,   241,   261,   262,
     263,   243,   273,   274,   279,    41,   213,   242,   275,   276,
     283,   194,   277,   284,     0,     0,     0,   182,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116
};

static const yytype_int16 yycheck[] =
{
      68,   135,   149,   131,   131,   131,    73,    74,   165,   199,
     193,   168,     8,     8,     3,     4,     5,    27,     7,     8,
     231,    25,    26,     8,    28,    28,    30,    31,     0,    33,
      36,    20,    21,   223,    40,    39,    40,    27,     8,    43,
      50,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    36,    37,    25,    36,    37,    54,    48,
      50,    31,   252,    33,    47,   276,   134,   250,    63,     8,
      40,    24,    78,    43,    27,    81,   266,    44,    45,    46,
      24,    36,   239,    27,     8,   152,    29,   215,   215,   215,
      22,    23,    47,    53,    35,    38,    25,    50,    39,   246,
       8,    61,    62,    29,    33,    37,    50,   156,   157,   158,
     159,    37,    49,    33,   163,    35,    36,    52,    60,    56,
      40,    63,    64,    56,    57,    58,    59,     8,    56,    57,
      58,    59,    57,    58,    59,    22,    23,    55,    56,    53,
      54,   275,    55,    56,    55,    56,    55,    56,    55,    56,
     284,    61,    62,   221,    55,    56,    55,    56,    55,    56,
      55,    56,    55,    56,    55,    56,    55,    56,     8,    55,
      56,    55,    56,    55,    56,    55,    56,    55,    56,   195,
     196,     8,    54,    54,    54,    54,    54,     8,     8,     8,
      54,    36,    54,    53,    55,    53,    53,    53,     7,     7,
      55,    55,    54,    54,     8,    55,    55,    53,    55,     8,
      36,    55,    55,    55,    55,    54,    54,    22,    29,    56,
      38,    54,    53,     8,    56,    55,    55,     8,    53,    53,
       8,     8,    55,     8,    56,    47,    53,    53,    53,    53,
       8,     8,    36,     8,    24,    38,     8,    54,     8,    55,
      29,     8,    53,    56,    56,    55,    51,     8,    56,    51,
      56,    35,    53,    60,     8,     8,    56,    56,    56,    56,
      56,   217,    56,    56,    56,    31,   168,   215,    54,    51,
      53,   146,   266,    54,    -1,    -1,    -1,   140,    -1,    59,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,    28,    30,    31,    33,    39,    40,    43,
      66,    67,    68,    70,    74,    75,    76,    79,    82,    85,
       8,     8,     8,     8,     8,     8,    28,    25,    33,     8,
       0,    52,    54,    54,    54,    54,    54,     8,     8,     8,
      54,    67,    36,    69,    36,    37,    47,    80,   104,    22,
      23,    86,    94,    97,   104,    29,   104,    69,   104,    54,
      69,   104,    53,    55,    53,    53,    53,    55,    55,    54,
      54,    49,    56,    55,    55,    53,    55,    55,    55,    86,
      55,    55,     7,    35,    39,    71,     8,     7,    54,    36,
      36,    80,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    44,    45,    46,    98,    99,   100,
     101,     8,    95,    96,    54,    97,    94,    97,     8,    54,
      83,    84,    29,    38,    69,    56,    29,    38,    77,    78,
      69,    54,    53,    56,    55,    81,    53,    53,    55,     8,
      55,    56,    53,    54,     8,     8,    55,    56,    27,    50,
      89,    90,    55,     8,   103,    56,    57,    58,    59,    53,
      53,    55,    56,    53,    53,    55,    56,    56,    55,    56,
       8,    70,    72,    73,    75,    76,     8,    80,   103,     8,
       8,    36,    99,     3,     4,     5,     7,     8,    20,    21,
      48,   102,    24,    54,    96,    61,    62,    92,    92,    55,
      56,    97,    55,    56,    83,    83,    83,    83,     8,    38,
      83,     8,    78,    77,    78,    55,    56,    55,    56,    56,
      56,    55,    53,    55,    56,    24,    89,     8,    91,    91,
      51,    51,    90,    56,     8,    56,    56,    53,    56,    55,
      56,    56,    73,    71,    80,     8,    50,    87,    88,    90,
      55,    56,    55,    56,    60,    63,    91,    93,    93,     8,
      78,    56,    56,    56,    53,    92,    55,    56,    89,    24,
       8,    63,    64,    56,    56,    54,    51,    88,    56,    56,
     103,    93,    56,    53,    54,   103,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    68,    69,    70,    70,    71,    72,    72,    73,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      79,    79,    79,    79,    81,    80,    82,    82,    83,    83,
      83,    84,    84,    84,    85,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    91,    91,    92,    92,    92,    93,
      93,    93,    94,    95,    95,    96,    96,    96,    96,    96,
      97,    98,    98,    99,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     1,     0,     1,     1,     1,     1,
       1,     1,     3,     6,    10,     4,     3,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     9,    11,     7,     2,
       2,     7,     9,     7,     7,     9,    11,     9,     3,     3,
       9,     9,    11,    11,     0,     6,     7,     9,     1,     3,
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

#define YYBACKUP(Token, Value)                                    \
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
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 170 "src/cocogen/ast.y" /* yacc.c:1652  */
    { parse_result = create_config(config_phases,
                                 config_passes,
                                 config_traversals,
                                 config_enums,
                                 config_nodesets,
                                 config_nodes);
              }
#line 1664 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 6:
#line 185 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_phases, (yyvsp[0].phase)); }
#line 1670 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 7:
#line 186 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_passes, (yyvsp[0].pass)); }
#line 1676 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 8:
#line 187 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_traversals, (yyvsp[0].traversal)); }
#line 1682 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 9:
#line 188 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_enums, (yyvsp[0].attr_enum)); }
#line 1688 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 10:
#line 189 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_nodesets, (yyvsp[0].nodeset)); }
#line 1694 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 11:
#line 190 "src/cocogen/ast.y" /* yacc.c:1652  */
    { array_append(config_nodes, (yyvsp[0].node));  }
#line 1700 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 12:
#line 194 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          (yyval.string) = (yyvsp[0].string);
          new_location((yyval.string), &(yyloc));
      }
#line 1709 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 13:
#line 200 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.phase) = create_phase((yyvsp[-5].phase), NULL, (yyvsp[-3].string), (yyvsp[-1].array));
     }
#line 1717 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 14:
#line 204 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.phase) = create_phase((yyvsp[-9].phase), (yyvsp[-3].string), (yyvsp[-7].string), (yyvsp[-1].array));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 1726 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 15:
#line 211 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.array) = (yyvsp[-1].array);
     }
#line 1734 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 16:
#line 217 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           array_append((yyvsp[-2].array), (yyvsp[0].action));
           (yyval.array) = (yyvsp[-2].array);
       }
#line 1743 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 17:
#line 222 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           array *tmp = create_array();
           array_append(tmp, (yyvsp[0].action));
           (yyval.array) = tmp;
       }
#line 1753 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 18:
#line 231 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          (yyval.action) = create_action(ACTION_TRAVERSAL, (yyvsp[0].traversal), (yyvsp[0].traversal)->id);
      }
#line 1761 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 19:
#line 235 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          (yyval.action) = create_action(ACTION_PASS, (yyvsp[0].pass), (yyvsp[0].pass)->id);
      }
#line 1769 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 20:
#line 239 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          (yyval.action) = create_action(ACTION_PHASE, (yyvsp[0].phase), (yyvsp[0].phase)->id);
      }
#line 1777 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 21:
#line 243 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          (yyval.action) = create_action(ACTION_REFERENCE, (yyvsp[0].string), (yyvsp[0].string));
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 1786 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 22:
#line 250 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), false, false);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1796 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 23:
#line 256 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), false, true);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1806 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 24:
#line 262 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), true, false);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1816 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 25:
#line 268 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
               (yyval.phase) = create_phase_header((yyvsp[0].string), true, true);
               new_location((yyval.phase), &(yyloc));
               new_location((yyvsp[0].string), &(yylsp[0]));
           }
#line 1826 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 26:
#line 276 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.pass) = create_pass((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-5].string));
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 1837 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 27:
#line 283 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.pass) = create_pass((yyvsp[-9].string), (yyvsp[-1].string), (yyvsp[-5].string));
        (yyval.pass)->info = (yyvsp[-7].string);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 1849 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 28:
#line 291 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.pass) = create_pass((yyvsp[-5].string), NULL, (yyvsp[-1].string));
        (yyval.pass)->info = (yyvsp[-3].string);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[-5].string), &(yylsp[-5]));
    }
#line 1860 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 29:
#line 298 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.pass) = create_pass((yyvsp[0].string), NULL, NULL);
        new_location((yyval.pass), &(yyloc));
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 1870 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 307 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[0].string), NULL, NULL, NULL);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[0].string), &(yylsp[0]));
         }
#line 1880 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 313 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), (yyvsp[-1].string), (yyvsp[-3].string), NULL);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 1890 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 319 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), (yyvsp[-3].string), (yyvsp[-5].string), (yyvsp[-1].setexpr));
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 1900 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 325 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), NULL, (yyvsp[-3].string), (yyvsp[-1].setexpr));
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 1910 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 331 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-5].string), NULL, (yyvsp[-1].string), NULL);
             (yyval.traversal)->info = (yyvsp[-3].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-5].string), &(yylsp[-5]));
         }
#line 1921 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 338 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-3].string), NULL);
             (yyval.traversal)->info = (yyvsp[-5].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 1932 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 345 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-9].string), (yyvsp[-3].string), (yyvsp[-5].string), (yyvsp[-1].setexpr));
             (yyval.traversal)->info = (yyvsp[-7].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-9].string), &(yylsp[-9]));
         }
#line 1943 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 352 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             (yyval.traversal) = create_traversal((yyvsp[-7].string), NULL, (yyvsp[-3].string), (yyvsp[-1].setexpr));
             (yyval.traversal)->info = (yyvsp[-5].string);
             new_location((yyval.traversal), &(yyloc));
             new_location((yyvsp[-7].string), &(yylsp[-7]));
         }
#line 1954 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 361 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.string) = (yyvsp[0].string);
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 1963 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 39:
#line 368 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                  (yyval.setexpr) = (yyvsp[0].setexpr);
              }
#line 1971 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 374 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-7].string), (yyvsp[-3].string), (yyvsp[-1].array));
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 1982 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 381 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-7].string), (yyvsp[-1].string), (yyvsp[-5].array));
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
        new_location((yyvsp[-1].string), &(yylsp[-3]));
    }
#line 1993 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 388 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-9].string), (yyvsp[-3].string), (yyvsp[-1].array));
        (yyval.attr_enum)->info = (yyvsp[-7].string);
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2005 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 396 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr_enum) = create_enum((yyvsp[-9].string), (yyvsp[-1].string), (yyvsp[-5].array));
        (yyval.attr_enum)->info = (yyvsp[-7].string);
        new_location((yyval.attr_enum), &(yyloc));
        new_location((yyvsp[-9].string), &(yylsp[-9]));
        new_location((yyvsp[-1].string), &(yylsp[-1]));
    }
#line 2017 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 44:
#line 407 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            yy_lex_keywords = false;
        }
#line 2025 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 45:
#line 411 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.array) = (yyvsp[-1].array);
            yy_lex_keywords = true;
        }
#line 2034 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 46:
#line 418 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.nodeset) = create_nodeset((yyvsp[-5].string), (yyvsp[-1].setexpr));
            new_location((yyval.nodeset), &(yyloc));
            new_location((yyvsp[-5].string), &(yylsp[-5]));
        }
#line 2044 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 47:
#line 424 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           (yyval.nodeset) = create_nodeset((yyvsp[-7].string), (yyvsp[-1].setexpr));
           (yyval.nodeset)->info = (yyvsp[-5].string);
           new_location((yyval.nodeset), &(yyloc));
           new_location((yyvsp[-7].string), &(yylsp[-7]));
       }
#line 2055 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 48:
#line 433 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           (yyval.setexpr) = create_set_expr(SET_OPERATION, (yyvsp[0].setoperation));
       }
#line 2063 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 49:
#line 437 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           (yyval.setexpr) = create_set_expr(SET_LITERAL, (yyvsp[-1].array));
       }
#line 2071 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 441 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
           (yyval.setexpr) = create_set_expr(SET_REFERENCE, (yyvsp[0].string));
       }
#line 2079 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 447 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                (yyval.setoperation) = create_set_operation(SET_UNION, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2087 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 52:
#line 451 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                (yyval.setoperation) = create_set_operation(SET_INTERSECT, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2095 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 53:
#line 455 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                (yyval.setoperation) = create_set_operation(SET_DIFFERENCE, (yyvsp[-2].setexpr), (yyvsp[0].setexpr));
            }
#line 2103 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 54:
#line 461 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.node) = create_node((yyvsp[-3].string), (yyvsp[-1].node));
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2113 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 55:
#line 467 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.node) = create_node((yyvsp[-3].string), (yyvsp[-1].node));
        (yyval.node)->root = true;
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-3].string), &(yylsp[-3]));
    }
#line 2124 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 56:
#line 474 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.node) = create_node((yyvsp[-7].string), (yyvsp[-5].node));
        (yyval.node)->lifetimes = (yyvsp[-2].array);
        new_location((yyval.node), &(yyloc));
        new_location((yyvsp[-7].string), &(yylsp[-7]));
    }
#line 2135 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 57:
#line 485 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody((yyvsp[-2].array), (yyvsp[0].array));
            new_location((yyval.node), &(yyloc));
        }
#line 2144 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 58:
#line 490 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody((yyvsp[0].array), NULL);
            new_location((yyval.node), &(yyloc));
        }
#line 2153 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 59:
#line 495 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody(NULL, (yyvsp[0].array));
            new_location((yyval.node), &(yyloc));
        }
#line 2162 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 60:
#line 500 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody((yyvsp[-2].array), (yyvsp[0].array));
            (yyval.node)->info = (yyvsp[-4].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2172 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 61:
#line 506 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody((yyvsp[0].array), NULL);
            (yyval.node)->info = (yyvsp[-2].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2182 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 62:
#line 512 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.node) = create_nodebody(NULL, (yyvsp[0].array));
            (yyval.node)->info = (yyvsp[-2].string);
            new_location((yyval.node), &(yyloc));
        }
#line 2192 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 63:
#line 521 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            array_append((yyval.array), (yyvsp[0].lifetime));
        }
#line 2200 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 64:
#line 525 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.array) = array_init(2);
            array_append((yyval.array), (yyvsp[0].lifetime));
        }
#line 2209 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 65:
#line 532 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-6].range_spec), (yyvsp[-4].range_spec), LIFETIME_DISALLOWED, (yyvsp[-1].array));
        }
#line 2217 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 66:
#line 536 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = (yyvsp[0].lifetime);
        }
#line 2225 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 67:
#line 540 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_DISALLOWED, (yyvsp[-1].array));
        }
#line 2233 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 68:
#line 546 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                array_append((yyval.array), (yyvsp[0].lifetime));
            }
#line 2241 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 69:
#line 550 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                (yyval.array) = array_init(2);
                array_append((yyval.array), (yyvsp[0].lifetime));
            }
#line 2250 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 70:
#line 556 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-2].range_spec), (yyvsp[0].range_spec), LIFETIME_DISALLOWED, NULL);
        }
#line 2258 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 560 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_DISALLOWED, NULL);
        }
#line 2266 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 564 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime((yyvsp[-2].range_spec), (yyvsp[0].range_spec), LIFETIME_MANDATORY, NULL);
        }
#line 2274 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 568 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.lifetime) = create_lifetime(NULL, NULL, LIFETIME_MANDATORY, NULL);
        }
#line 2282 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 574 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                array_append((yyvsp[-2].array), (yyvsp[0].string));
                new_location((yyvsp[0].string), &(yylsp[0]));
            }
#line 2291 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 579 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
                (yyval.array) = create_array();
                array_append((yyval.array), (yyvsp[0].string));
                new_location((yyvsp[0].string), &(yylsp[0]));
            }
#line 2301 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 586 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = create_range_spec(false, (yyvsp[0].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2310 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 591 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = NULL;
          }
#line 2318 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 595 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = create_range_spec(true, (yyvsp[0].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2327 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 602 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = create_range_spec(false, (yyvsp[-1].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2336 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 607 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = NULL;
          }
#line 2344 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 611 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
              (yyval.range_spec) = create_range_spec(true, (yyvsp[-1].array));
              new_location((yyval.range_spec), &(yyloc));
          }
#line 2353 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 618 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.array) = (yyvsp[-1].array);
            new_location((yyval.array), &(yyloc));
        }
#line 2362 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 625 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             array_append((yyvsp[-2].array), (yyvsp[0].child));
             (yyval.array) = (yyvsp[-2].array);
             // $$ is an array and should not be in the locations list
         }
#line 2372 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 631 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
             array *tmp = create_array();
             array_append(tmp, (yyvsp[0].child));
             (yyval.array) = tmp;
             // $$ is an array and should not be in the locations list
         }
#line 2383 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 640 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.child) = create_child(0, NULL, (yyvsp[0].string), (yyvsp[-1].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-1].string), &(yylsp[-1]));
         new_location((yyvsp[0].string), &(yylsp[0]));
     }
#line 2394 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 647 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.child) = create_child(1, (yyvsp[-1].array), (yyvsp[-5].string), (yyvsp[-6].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-6].string), &(yylsp[-6]));
         new_location((yyvsp[-5].string), &(yylsp[-5]));
     }
#line 2405 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 654 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.child) = create_child(1, (yyvsp[-3].array), (yyvsp[-5].string), (yyvsp[-6].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-6].string), &(yylsp[-6]));
         new_location((yyvsp[-5].string), &(yylsp[-5]));
     }
#line 2416 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 88:
#line 661 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.child) = create_child(1, NULL, (yyvsp[-3].string), (yyvsp[-4].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-4].string), &(yylsp[-4]));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 2427 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 89:
#line 668 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
         (yyval.child) = create_child(0, (yyvsp[-1].array), (yyvsp[-3].string), (yyvsp[-4].string));
         new_location((yyval.child), &(yyloc));
         new_location((yyvsp[-4].string), &(yylsp[-4]));
         new_location((yyvsp[-3].string), &(yylsp[-3]));
     }
#line 2438 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 90:
#line 676 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.array) = (yyvsp[-1].array); }
#line 2444 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 91:
#line 679 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            array_append((yyvsp[-2].array), (yyvsp[0].attr));
            (yyval.array) = (yyvsp[-2].array);
            // $$ is an array and should not be in the locations list
        }
#line 2454 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 92:
#line 685 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            array *tmp = create_array();
            array_append(tmp, (yyvsp[0].attr));
            (yyval.array) = tmp;
            // $$ is an array and should not be in the locations list
        }
#line 2465 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 693 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr) = create_attr((yyvsp[-5].attr), NULL, 1, (yyvsp[-1].array));
        new_location((yyval.attr), &(yyloc));
    }
#line 2474 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 698 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr) = create_attr((yyvsp[-3].attr), NULL, 1, NULL);
        new_location((yyval.attr), &(yyloc));
    }
#line 2483 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 703 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.attr) = create_attr((yyvsp[-2].attr), (yyvsp[0].attrval), 0, NULL);
        new_location((yyval.attr), &(yyloc));
    }
#line 2492 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 710 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.attr) = create_attrhead_primitive((yyvsp[-1].attrtype), (yyvsp[0].string));
            new_location((yyval.attr), &(yyloc));
            new_location((yyvsp[0].string), &(yylsp[0]));
        }
#line 2502 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 716 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
            (yyval.attr) = create_attrhead_idtype((yyvsp[-1].string), (yyvsp[0].string));
            new_location((yyval.attr), &(yyloc));
            new_location((yyvsp[-1].string), &(yylsp[-1]));
            new_location((yyvsp[0].string), &(yylsp[0]));
        }
#line 2513 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 725 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_int; }
#line 2519 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 727 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_int8; }
#line 2525 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 100:
#line 729 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_int16; }
#line 2531 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 101:
#line 731 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_int32; }
#line 2537 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 102:
#line 733 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_int64; }
#line 2543 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 735 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_uint; }
#line 2549 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 737 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_uint8; }
#line 2555 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 739 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_uint16; }
#line 2561 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 741 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_uint32; }
#line 2567 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 743 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_uint64; }
#line 2573 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 745 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_float; }
#line 2579 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 109:
#line 747 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_double; }
#line 2585 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 110:
#line 749 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_bool; }
#line 2591 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 111:
#line 751 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrtype) = AT_string; }
#line 2597 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 112:
#line 754 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_string((yyvsp[0].string)); }
#line 2603 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 113:
#line 756 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_int((yyvsp[0].intval)); }
#line 2609 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 758 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_uint((yyvsp[0].uintval)); }
#line 2615 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 760 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_float((yyvsp[0].fval)); }
#line 2621 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 762 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_id((yyvsp[0].string)); }
#line 2627 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 764 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_bool(true); }
#line 2633 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 766 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = create_attrval_bool(false); }
#line 2639 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 768 "src/cocogen/ast.y" /* yacc.c:1652  */
    { (yyval.attrval) = NULL; }
#line 2645 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 120:
#line 773 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          array_append((yyvsp[-2].array), (yyvsp[0].string));
          (yyval.array) = (yyvsp[-2].array);
          // $$ is an array and should not be added to location list.
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 2656 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 121:
#line 780 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
          array *tmp = create_array();
          array_append(tmp, (yyvsp[0].string));
          (yyval.array) = tmp;
          // $$ is an array and should not be added to location list.
          new_location((yyvsp[0].string), &(yylsp[0]));
      }
#line 2668 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;

  case 122:
#line 790 "src/cocogen/ast.y" /* yacc.c:1652  */
    {
        (yyval.string) = (yyvsp[0].string);
        new_location((yyval.string), &(yyloc));
        new_location((yyvsp[0].string), &(yylsp[0]));
    }
#line 2678 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
    break;


#line 2682 "src/cocogen/ast.parser.c" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 796 "src/cocogen/ast.y" /* yacc.c:1918  */


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
