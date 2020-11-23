D	[0-9]
L	[a-zA-Z_]
H	[a-fA-F0-9]
E	([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS	(f|F|l|L)
IS  ((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

%{
#include <stdio.h>
#include "y.tab.h"

void count();
%}

%%
0[xX]{H}+{IS}?		            { count(); return(CONSTANT); } // 16
0[0-7]*{IS}?		            { count(); return(CONSTANT); } // 8
[1-9]{D}*{IS}?		            { count(); return(CONSTANT); } // 10
L?'(\\.|[^\\'\n])+'	            { count(); return(CONSTANT); }
{D}+{E}{FS}?		            { count(); return(CONSTANT); }
{D}*"."{D}+{E}?{FS}?	        { count(); return(CONSTANT); }
{D}+"."{D}*{E}?{FS}?	        { count(); return(CONSTANT); }
0[xX]{H}+{P}{FS}?	            { count(); return(CONSTANT); }
0[xX]{H}*"."{H}+{P}?{FS}?       { count(); return(CONSTANT); }
0[xX]{H}+"."{H}*{P}?{FS}?       { count(); return(CONSTANT); }
L?\"(\\.|[^\\"\n])*\"	        { count(); return(STRING_LITERAL); }
L(D|L|$)*                       { count(); return(IDENTIFER); }

"("			    { count(); return(LP); }
")"			    { count(); return(RP); }
"["             { count(); return(LSB); }
"]"             { count(); return(RSB); }
"{"             { count(); return(LBP); }
"}"             { count(); return(RBP); }
"->"			{ count(); return(POINTER); }
"&"			    { count(); return(ADDRESS); }
"!"			    { count(); return(NOT); }
"^"			    { count(); return(POW); }
"*"			    { count(); return(TIMES); }
"/"			    { count(); return(DIVIDE); }
"%"			    { count(); return(MOD); }
"+"			    { count(); return(PLUS); }
"-"			    { count(); return(MINUS); }
"<"			    { count(); return(GT); }
">"			    { count(); return(LT); }
"<="			{ count(); return(LE); }
">="			{ count(); return(GE); }
"=="			{ count(); return(EQ); }
"!="			{ count(); return(NE); }
"&&"			{ count(); return(AND); }
"||"			{ count(); return(OR); }
"="			    { count(); return(ASSIGN); }

"int"			{ count(); return(INT); }
","			    { count(); return(COMMA); }
";"			    { count(); return(SEMICOLON); }
"if"			{ count(); return(IF); }
"else"			{ count(); return(ELSE); }
"while"			{ count(); return(WHILE); }
"do"			{ count(); return(DO); }
"for"			{ count(); return(FOR); }
"continue"		{ count(); return(CONTINUE); }
"break"			{ count(); return(BREAK); }
"return"		{ count(); return(RETURN); }
"struct"		{ count(); return(STRUCT); }

%%

int yywrap(void) {
    return 1;
}