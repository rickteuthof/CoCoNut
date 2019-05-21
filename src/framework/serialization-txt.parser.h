/* A Bison parser, made by GNU Bison 3.3.2.  */

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

#ifndef YY_AST_SRL_YY_SRC_FRAMEWORK_SERIALIZATION_TXT_PARSER_H_INCLUDED
# define YY_AST_SRL_YY_SRC_FRAMEWORK_SERIALIZATION_TXT_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef AST_SRL_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define AST_SRL_YYDEBUG 1
#  else
#   define AST_SRL_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define AST_SRL_YYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined AST_SRL_YYDEBUG */
#if AST_SRL_YYDEBUG
extern int ast_srl_yydebug;
#endif

/* Token type.  */
#ifndef AST_SRL_YYTOKENTYPE
# define AST_SRL_YYTOKENTYPE
  enum ast_srl_yytokentype
  {
    END = 0,
    T_INTVAL = 258,
    T_UINTVAL = 259,
    T_FLOATVAL = 260,
    T_STRINGVAL = 261,
    T_ID = 262,
    T_TRUE = 263,
    T_FALSE = 264,
    T_ROOT = 265,
    T_ATTRIBUTES = 266,
    T_CHILDREN = 267
  };
#endif

/* Value type.  */
#if ! defined AST_SRL_YYSTYPE && ! defined AST_SRL_YYSTYPE_IS_DECLARED

union AST_SRL_YYSTYPE
{
#line 50 "src/framework/serialization-txt.y" /* yacc.c:1921  */

    int64_t intval;
    uint64_t uintval;
    long double fval;
    char *string;
    char *str;
    array *array;
    AST_TXT_File *file;
    AST_TXT_Node *node;
    AST_TXT_NodeHeader *nodeheader;
    AST_TXT_Child *child;
    AST_TXT_Attribute *attribute;
    AST_TXT_AttributeValue *attributevalue;

#line 95 "src/framework/serialization-txt.parser.h" /* yacc.c:1921  */
};

typedef union AST_SRL_YYSTYPE AST_SRL_YYSTYPE;
# define AST_SRL_YYSTYPE_IS_TRIVIAL 1
# define AST_SRL_YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined AST_SRL_YYLTYPE && ! defined AST_SRL_YYLTYPE_IS_DECLARED
typedef struct AST_SRL_YYLTYPE AST_SRL_YYLTYPE;
struct AST_SRL_YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define AST_SRL_YYLTYPE_IS_DECLARED 1
# define AST_SRL_YYLTYPE_IS_TRIVIAL 1
#endif


extern AST_SRL_YYSTYPE ast_srl_yylval;
extern AST_SRL_YYLTYPE ast_srl_yylloc;
int ast_srl_yyparse (void);

#endif /* !YY_AST_SRL_YY_SRC_FRAMEWORK_SERIALIZATION_TXT_PARSER_H_INCLUDED  */
