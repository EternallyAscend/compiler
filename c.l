%{
#include <stdio.h>
#include "y.tab.h"

void count();
int yywarp(void);
// int yylex(void);
%}

%%
[1-9][0-9]*       	            { count(); return(CONSTANT); }
\"(\\.|[^\\"\n])*\"				{ count(); return(STRING_C); }
"print"							{ count(); return(PRINT); }
"input"							{ count(); return(INPUT); }
[\n\t \r]*						{ count(); }

"("			{ count(); return(LP); }
")"			{ count(); return(RP); }
"["         { count(); return(LSB); }
"]"         { count(); return(RSB); }
"{"         { count(); return(LBP); }
"}"         { count(); return(RBP); }
"->"		{ count(); return(POINTER); }
"&"			{ count(); return(ADDRESS); }
"!"			{ count(); return(NOT); }
"^"			{ count(); return(POW); }
"*"			{ count(); return(TIMES); }
"/"			{ count(); return(DIVIDE); }
"%"			{ count(); return(MOD); }
"+"			{ count(); return(PLUS); }
"-"			{ count(); return(MINUS); }
"<"			{ count(); return(GT); }
">"			{ count(); return(LT); }
"<="		{ count(); return(LE); }
">="		{ count(); return(GE); }
"=="		{ count(); return(EQ); }
"!="		{ count(); return(NE); }
"&&"		{ count(); return(AND); }
"||"		{ count(); return(OR); }
"="			{ count(); return(ASSIGN); }
"int"		{ count(); return(INT); }
"void"      { count(); return(VOID); }
","			{ count(); return(COMMA); }
";"			{ count(); return(SEMICOLON); }
"if"		{ count(); return(IF); }
"else"		{ count(); return(ELSE); }
"while"		{ count(); return(WHILE); }
"do"		{ count(); return(DO); }
"for"		{ count(); return(FOR); }
"continue"	{ count(); return(CONTINUE); }
"break"		{ count(); return(BREAK); }
"return"	{ count(); return(RETURN); }
"struct"	{ count(); return(STRUCT); }

[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   { count(); return(IDENTIFIER); }
%%

int yywrap(void) {
	return 1;
}

// int yylex(void) {
// 	return 1;
// }

void comment(void) {
	char c, prev = 0;
	while ((c = getchar()) != 0) {
		if (c == '/' && prev == '*') {
			return;
        }
		prev = c;
	}
	perror("unterminated comment");
}


int column = 0;
void count(void) {
	int i;
	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n') {
			column = 0;
        }
		else if (yytext[i] == '\t') {
			column += 8 - (column % 8);
        }
		else {
			column++;
        }
	ECHO;
}

int check_type(void) {
	return IDENTIFIER;
}
