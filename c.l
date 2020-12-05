%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "table.h"
#include "y.tab.h"

int yywarp(void);
extern int yylex();
void move();
char* outputTitle();
void appentLexOutputFile(const char* type, const char* name, const char* attribute);
%}

%%
[\t \r]+		{ move(); }
(0|([1-9][0-9]*))     	{ appentLexOutputFile("CONSTANT", yytext, yytext); return(CONSTANT); }
\"(\\.|[^\\"\n])*\"	{ appentLexOutputFile("STRING_C", yytext, yytext); return(STRING_C); }
"print"			{ appentLexOutputFile("PRINT", yytext, ""); return(PRINT); }
"input"			{ appentLexOutputFile("INPUT", yytext, ""); return(INPUT); }

\(			{ appentLexOutputFile("LP", yytext, ""); return(LP); }
\)			{ appentLexOutputFile("RP", yytext, ""); return(RP); }
\[         		{ appentLexOutputFile("LSB", yytext, ""); return(LSB); }
\]         		{ appentLexOutputFile("RSB", yytext, ""); return(RSB); }
\{         		{ appentLexOutputFile("LBP", yytext, ""); return(LBP); }
\}         		{ appentLexOutputFile("RBP", yytext, ""); return(RBP); }
\-\>			{ appentLexOutputFile("POINTER", yytext, ""); return(POINTER); }
\&			{ appentLexOutputFile("ADDRESS", yytext, ""); return(ADDRESS); }
\!			{ appentLexOutputFile("NOT", yytext, ""); return(NOT); }
\^			{ appentLexOutputFile("POW", yytext, ""); return(POW); }
\*			{ appentLexOutputFile("TIMES", yytext, ""); return(TIMES); }
\/			{ appentLexOutputFile("DIVIDE", yytext, ""); return(DIVIDE); }
\%			{ appentLexOutputFile("MOD", yytext, ""); return(MOD); }
\+			{ appentLexOutputFile("PLUS", yytext, ""); return(PLUS); }
\-			{ appentLexOutputFile("MINUS", yytext, ""); return(MINUS); }
\<			{ appentLexOutputFile("GT", yytext, ""); return(GT); }
\>			{ appentLexOutputFile("LT", yytext, ""); return(LT); }
\<\=			{ appentLexOutputFile("LE", yytext, ""); return(LE); }
\>\=			{ appentLexOutputFile("GE", yytext, ""); return(GE); }
\=\=			{ appentLexOutputFile("EQ", yytext, ""); return(EQ); }
\!\=			{ appentLexOutputFile("NE", yytext, ""); return(NE); }
\&\&			{ appentLexOutputFile("AND", yytext, ""); return(AND); }
\|\|			{ appentLexOutputFile("OR", yytext, ""); return(OR); }
\=			{ appentLexOutputFile("ASSIGN", yytext, ""); return(ASSIGN); }
int			{ appentLexOutputFile("INT", yytext, ""); return(INT); }
void    		{ appentLexOutputFile("VOID", yytext, ""); return(VOID); }
\,			{ appentLexOutputFile("COMMA", yytext, ""); return(COMMA); }
\;			{ appentLexOutputFile("SEMICOLON", yytext, ""); return(SEMICOLON); }
if			{ appentLexOutputFile("IF", yytext, ""); return(IF); }
else			{ appentLexOutputFile("ELSE", yytext, ""); return(ELSE); }
while			{ appentLexOutputFile("WHILE", yytext, ""); return(WHILE); }
do			{ appentLexOutputFile("DO", yytext, ""); return(DO); }
for			{ appentLexOutputFile("FOR", yytext, ""); return(FOR); }
continue		{ appentLexOutputFile("CONTINUE", yytext, ""); return(CONTINUE); }
break			{ appentLexOutputFile("BREAK", yytext, ""); return(BREAK); }
return			{ appentLexOutputFile("RETURN", yytext, ""); return(RETURN); }
struct			{ appentLexOutputFile("STRUCT", yytext, ""); return(STRUCT); }

[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   {
	{
		if (searchWord(yytext)) {
			printf("Exist at line %d.\n", yylineno);
		}
		else {
			unsigned int position = addWord(yytext);
			char* attribute = (char*)malloc(sizeof(char)*64);
			sprintf(attribute, "0x%x", position);
			appentLexOutputFile("IDENTIFIER", yytext, attribute);
			free(attribute);
		}
	}
	yylval.str=yytext;
	return(IDENTIFIER);
}

%%

int yywrap(void) {
	return 1;
}

void move() {

}

char* outputTitle() {
	return "Type           Name           Attribute \n";
}

void appentLexOutputFile(const char* type, const char* name, const char* attribute) {
	char* result = (char*)malloc(sizeof(char)*64);
	sprintf(result, "%-15s%-15s%-15s\n", type, name, attribute);
	appendLEX(result);
	printf("%s", result);
	free(result);
}

