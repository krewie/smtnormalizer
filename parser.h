/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 50 "parser.y" /* yacc.c:1915  */

    char *string;
    std::vector<scrambler::node *> *nodelist;
    scrambler::node *curnode;
    std::vector<char> *buf;

#line 98 "parser.h" /* yacc.c:1915  */
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
