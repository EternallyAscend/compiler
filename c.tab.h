/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
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
    CONSTANT = 258,
    STRING_C = 259,
    PRINT = 260,
    INPUT = 261,
    IDENTIFIER = 262,
    LP = 263,
    RP = 264,
    LSB = 265,
    RSB = 266,
    LBP = 267,
    RBP = 268,
    POINTER = 269,
    ADDRESS = 270,
    NOT = 271,
    POW = 272,
    TIMES = 273,
    DIVIDE = 274,
    MOD = 275,
    PLUS = 276,
    MINUS = 277,
    GT = 278,
    LT = 279,
    GE = 280,
    LE = 281,
    EQ = 282,
    NE = 283,
    AND = 284,
    OR = 285,
    ASSIGN = 286,
    INT = 287,
    VOID = 288,
    COMMA = 289,
    SEMICOLON = 290,
    IF = 291,
    ELSE = 292,
    WHILE = 293,
    DO = 294,
    FOR = 295,
    CONTINUE = 296,
    BREAK = 297,
    RETURN = 298,
    STRUCT = 299,
    NONE_ELSE = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "c.y" /* yacc.c:1909  */

    char* str;

#line 104 "c.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */
