/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_INT = 258,                  /* KW_INT  */
    KW_FLOAT = 259,                /* KW_FLOAT  */
    KW_CHAR = 260,                 /* KW_CHAR  */
    KW_VOID = 261,                 /* KW_VOID  */
    KW_RETURN = 262,               /* KW_RETURN  */
    KW_IF = 263,                   /* KW_IF  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_WHILE = 265,                /* KW_WHILE  */
    KW_FOR = 266,                  /* KW_FOR  */
    KW_DO = 267,                   /* KW_DO  */
    KW_BREAK = 268,                /* KW_BREAK  */
    KW_CONT = 269,                 /* KW_CONT  */
    IDENTIFIER = 270,              /* IDENTIFIER  */
    INT_LITERAL = 271,             /* INT_LITERAL  */
    FLOAT_LITERAL = 272,           /* FLOAT_LITERAL  */
    CHAR_LITERAL = 273,            /* CHAR_LITERAL  */
    STRING_LITERAL = 274,          /* STRING_LITERAL  */
    OP_PLUS = 275,                 /* OP_PLUS  */
    OP_MINUS = 276,                /* OP_MINUS  */
    OP_MUL = 277,                  /* OP_MUL  */
    OP_DIV = 278,                  /* OP_DIV  */
    OP_MOD = 279,                  /* OP_MOD  */
    OP_EQ = 280,                   /* OP_EQ  */
    OP_NEQ = 281,                  /* OP_NEQ  */
    OP_LT = 282,                   /* OP_LT  */
    OP_GT = 283,                   /* OP_GT  */
    OP_LTE = 284,                  /* OP_LTE  */
    OP_GTE = 285,                  /* OP_GTE  */
    OP_AND = 286,                  /* OP_AND  */
    OP_OR = 287,                   /* OP_OR  */
    OP_NOT = 288,                  /* OP_NOT  */
    OP_ASSIGN = 289,               /* OP_ASSIGN  */
    OP_PLUSEQ = 290,               /* OP_PLUSEQ  */
    OP_MINEQ = 291,                /* OP_MINEQ  */
    OP_MULEQ = 292,                /* OP_MULEQ  */
    OP_DIVEQ = 293,                /* OP_DIVEQ  */
    OP_INC = 294,                  /* OP_INC  */
    OP_DEC = 295,                  /* OP_DEC  */
    LPAREN = 296,                  /* LPAREN  */
    RPAREN = 297,                  /* RPAREN  */
    LBRACE = 298,                  /* LBRACE  */
    RBRACE = 299,                  /* RBRACE  */
    LBRACKET = 300,                /* LBRACKET  */
    RBRACKET = 301,                /* RBRACKET  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COMMA = 303,                   /* COMMA  */
    UMINUS = 304,                  /* UMINUS  */
    LOWER_THAN_ELSE = 305          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    int      ival;
    char    *str;
    struct {
        ASTNode *node;
        char     temp[64];
        int      type;
    } expr;

#line 124 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
