%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "table.h"


#define TYPE_OUTPUT_LENGTH 15
#define NAME_OUTPUT_LENGTH 15
#define ATTR_OUTPUT_LENGTH 15

int yywarp(void);
void move();
char* outputTitle();
void appentLexOutputFile(const char* type, const char* name, const char* attribute);
%}

%%
[\n]			{ move(); }
[\t \r]+		
(0|([1-9][0-9]*))       { appentLexOutputFile("CONSTANT", yytext, yytext); }
\"(\\.|[^\\"\n])*\"	{ appentLexOutputFile("STRING_C", yytext, yytext); }
"print"			{ appentLexOutputFile("PRINT", yytext, ""); }
"input"			{ appentLexOutputFile("INPUT", yytext, ""); }

\(			{ appentLexOutputFile("LP", yytext, ""); }
\)			{ appentLexOutputFile("RP", yytext, ""); }
\[         		{ appentLexOutputFile("LSB", yytext, ""); }
\]         		{ appentLexOutputFile("RSB", yytext, ""); }
\{         		{ appentLexOutputFile("LBP", yytext, ""); }
\}         		{ appentLexOutputFile("RBP", yytext, ""); }
\-\>			{ appentLexOutputFile("POINTER", yytext, ""); }
\&			{ appentLexOutputFile("ADDRESS", yytext, ""); }
\!			{ appentLexOutputFile("NOT", yytext, ""); }
\^			{ appentLexOutputFile("POW", yytext, ""); }
\*			{ appentLexOutputFile("TIMES", yytext, "");}
\/			{ appentLexOutputFile("DIVIDE", yytext, ""); }
\%			{ appentLexOutputFile("MOD", yytext, ""); }
\+			{ appentLexOutputFile("PLUS", yytext, ""); }
\-			{ appentLexOutputFile("MINUS", yytext, ""); }
\<			{ appentLexOutputFile("GT", yytext, ""); }
\>			{ appentLexOutputFile("LT", yytext, ""); }
\<\=			{ appentLexOutputFile("LE", yytext, ""); }
\>\=			{ appentLexOutputFile("GE", yytext, ""); }
\=\=			{ appentLexOutputFile("EQ", yytext, ""); }
\!\=			{ appentLexOutputFile("NE", yytext, ""); }
\&\&			{ appentLexOutputFile("AND", yytext, ""); }
\|\|			{ appentLexOutputFile("OR", yytext, ""); }
=			{ appentLexOutputFile("ASSIGN", yytext, ""); }
int			{ appentLexOutputFile("INT", yytext, ""); }
void      		{ appentLexOutputFile("VOID", yytext, ""); }
,			{ appentLexOutputFile("COMMA", yytext, ""); }
;			{ appentLexOutputFile("SEMICOLON", yytext, ""); }
if			{ appentLexOutputFile("IF", yytext, ""); }
else			{ appentLexOutputFile("ELSE", yytext, ""); }
while			{ appentLexOutputFile("WHILE", yytext, ""); }
do			{ appentLexOutputFile("DO", yytext, ""); }
for			{ appentLexOutputFile("FOR", yytext, ""); }
continue		{ appentLexOutputFile("CONTINUE", yytext, ""); }
break			{ appentLexOutputFile("BREAK", yytext, ""); }
return			{ appentLexOutputFile("RETURN", yytext, ""); }
struct			{ appentLexOutputFile("STRUCT", yytext, ""); }

[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   {
	{
		char* attribute = (char*)malloc(sizeof(char)*64);
		if (searchWord(yytext)) {
			printf("Exist at line %d.\n", yylineno);
			struct Word* word = getWordInfo(yytext);
			sprintf(attribute, "0x%x", word->symbolPosition);
			free(word);
		}
		else {
			unsigned int position = addWord(yytext);
			sprintf(attribute, "0x%x", position);
		}
		appentLexOutputFile("IDENTIFIER", yytext, attribute);
		free(attribute);
	}
}

%%

int main(int arg, char* argv[]) {
	printf("Type           Name           Attribute \n");
	yyin = fopen(argv[1], "r");
	generateLEX();
	launchTable();
	appendLEX(outputTitle());
	yylex();
	stopTable();
	closeLEX();
	fclose(yyin);
	return 0;
}

int yywrap(void) {
	return 1;
}

void move() {
	yylineno++;
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
