/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_LIMBAJ_TAB_H_INCLUDED
# define YY_YY_LIMBAJ_TAB_H_INCLUDED
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
    BGIN = 258,                    /* BGIN  */
    END = 259,                     /* END  */
    ASSIGN = 260,                  /* ASSIGN  */
    IF = 261,                      /* IF  */
    WHILE = 262,                   /* WHILE  */
    FOR = 263,                     /* FOR  */
    LE = 264,                      /* LE  */
    EQ = 265,                      /* EQ  */
    GE = 266,                      /* GE  */
    AND = 267,                     /* AND  */
    OR = 268,                      /* OR  */
    PRINT = 269,                   /* PRINT  */
    TYPEOF = 270,                  /* TYPEOF  */
    BGINF = 271,                   /* BGINF  */
    BGINC = 272,                   /* BGINC  */
    BGIND = 273,                   /* BGIND  */
    ENDF = 274,                    /* ENDF  */
    ENDC = 275,                    /* ENDC  */
    ENDD = 276,                    /* ENDD  */
    STRUCT = 277,                  /* STRUCT  */
    RETURN = 278,                  /* RETURN  */
    REAL = 279,                    /* REAL  */
    FAKE = 280,                    /* FAKE  */
    ELSE = 281,                    /* ELSE  */
    ID = 282,                      /* ID  */
    TYPE = 283,                    /* TYPE  */
    STRING = 284,                  /* STRING  */
    CHAR = 285,                    /* CHAR  */
    NRFLOAT = 286,                 /* NRFLOAT  */
    NR = 287                       /* NR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "limbaj.y"

    struct ASTNode* node;
    int Int;
    float Float;
    char* string;

#line 103 "limbaj.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LIMBAJ_TAB_H_INCLUDED  */
