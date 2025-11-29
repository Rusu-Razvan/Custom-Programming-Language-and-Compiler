%{
#include <stdio.h>
#include <string>
#include "limbaj.tab.h"
#include "AST.cpp"
%}

%x comment
%option noyywrap
%%
"int"|"float"|"char"|"string"|"bool" {yylval.string = strdup(yytext);return TYPE;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"||" {return OR;}
"&&" {return AND;}
"if" {return IF;}
"while" {return WHILE;}
"for" {return FOR;}
"else" {return ELSE;}
"struct" {yylval.string = strdup(yytext); return STRUCT;}
"begin_progr" {return BGIN;}
"end_progr" {return END;}
"begin_func" {return BGINF;}
"end_func" {return ENDF;}
"begin_class" {return BGINC;}
"end_class" {return ENDC;}
"begin_decl" {return BGIND;}
"end_decl" {return ENDD;}
"Print" {return PRINT;}
"TypeOf" {return TYPEOF;}
"return" {return RETURN;}
"real" {yylval.string = strdup(yytext); return REAL;}
"fake" {yylval.string = strdup(yytext); return FAKE;}
"/*" {BEGIN comment; }
<comment>.|\n
<comment>"*/" {BEGIN 0; }
[a-zA-Z][a-zA-Z0-9]* {yylval.string = strdup(yytext); return ID;}
":=" {return ASSIGN;}
[0-9]+ {yylval.Int = atoi(yytext); return NR;}
[0-9]+\.[0-9]+ {yylval.string = strdup(yytext); return NRFLOAT;}
\"[a-zA-Z0-9]+\" {yylval.string = strdup(yytext); return STRING;}
\'[a-zA-Z0-9]\' {yylval.string = strdup(yytext); return CHAR; }
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
