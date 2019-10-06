/* A Bison parser, made by GNU Bison 3.4.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 62 "ast.y"

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

#line 138 "ast.parser.h"

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
