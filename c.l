%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "table.h"
#include "y.tab.h"

// #ifdef __cplusplus
extern "C" 
{
// #endif
	int yywarp(void);
    int yylex(void);

// #ifdef __cplusplus
};
// #endif

void move();
char* outputTitle();
void appendLexOutputFile(const char* type, const char* name, const char* attribute);
%}

%%
[\n]			{ move(); }
[\t \r]+
(0|([1-9][0-9]*))     	{ appendLexOutputFile("CONSTANT", yytext, yytext); yylval.str=yytext; return(CONSTANT); }
\"(\\.|[^\\"\n])*\"	{ appendLexOutputFile("STRING_C", yytext, yytext); yylval.str=yytext; return(STRING_C); }
"print"			{ appendLexOutputFile("PRINT", yytext, ""); return(PRINT); }
"input"			{ appendLexOutputFile("INPUT", yytext, ""); return(INPUT); }

\(			{ appendLexOutputFile("LP", yytext, ""); return(LP); }
\)			{ appendLexOutputFile("RP", yytext, ""); return(RP); }
\[         		{ appendLexOutputFile("LSB", yytext, ""); return(LSB); }
\]         		{ appendLexOutputFile("RSB", yytext, ""); return(RSB); }
\{         		{ appendLexOutputFile("LBP", yytext, ""); return(LBP); }
\}         		{ appendLexOutputFile("RBP", yytext, ""); return(RBP); }
\-\>			{ appendLexOutputFile("POINTER", yytext, ""); return(POINTER); }
\&			{ appendLexOutputFile("ADDRESS", yytext, ""); return(ADDRESS); }
\!			{ appendLexOutputFile("NOT", yytext, ""); return(NOT); }
\^			{ appendLexOutputFile("POW", yytext, ""); return(POW); }
\*			{ appendLexOutputFile("TIMES", yytext, ""); return(TIMES); }
\/			{ appendLexOutputFile("DIVIDE", yytext, ""); return(DIVIDE); }
\%			{ appendLexOutputFile("MOD", yytext, ""); return(MOD); }
\+			{ appendLexOutputFile("PLUS", yytext, ""); return(PLUS); }
\-			{ appendLexOutputFile("MINUS", yytext, ""); return(MINUS); }
\<			{ appendLexOutputFile("GT", yytext, ""); return(GT); }
\>			{ appendLexOutputFile("LT", yytext, ""); return(LT); }
\<\=			{ appendLexOutputFile("LE", yytext, ""); return(LE); }
\>\=			{ appendLexOutputFile("GE", yytext, ""); return(GE); }
\=\=			{ appendLexOutputFile("EQ", yytext, ""); return(EQ); }
\!\=			{ appendLexOutputFile("NE", yytext, ""); return(NE); }
\&\&			{ appendLexOutputFile("AND", yytext, ""); return(AND); }
\|\|			{ appendLexOutputFile("OR", yytext, ""); return(OR); }
\=			{ appendLexOutputFile("ASSIGN", yytext, ""); return(ASSIGN); }
int			{ appendLexOutputFile("INT", yytext, ""); return(INT); }
void    		{ appendLexOutputFile("VOID", yytext, ""); return(VOID); }
\,			{ appendLexOutputFile("COMMA", yytext, ""); return(COMMA); }
\;			{ appendLexOutputFile("SEMICOLON", yytext, ""); return(SEMICOLON); }
if			{ appendLexOutputFile("IF", yytext, ""); return(IF); }
else			{ appendLexOutputFile("ELSE", yytext, ""); return(ELSE); }
while			{ appendLexOutputFile("WHILE", yytext, ""); return(WHILE); }
do			{ appendLexOutputFile("DO", yytext, ""); return(DO); }
for			{ appendLexOutputFile("FOR", yytext, ""); return(FOR); }
continue		{ appendLexOutputFile("CONTINUE", yytext, ""); return(CONTINUE); }
break			{ appendLexOutputFile("BREAK", yytext, ""); return(BREAK); }
return			{ appendLexOutputFile("RETURN", yytext, ""); return(RETURN); }
struct			{ appendLexOutputFile("STRUCT", yytext, ""); return(STRUCT); }

[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   {
	{
		char* attribute = (char*)malloc(sizeof(char)*64);
		if (searchWord(yytext)) {
			// printf("Exist at line %d.\n", yylineno);
			struct Word* word = getWordInfo(yytext);
			sprintf(attribute, "0x%x", word->symbolPosition);
			free(word);
		}
		else {
			unsigned int position = addWord(yytext);
			sprintf(attribute, "0x%x", position);
		}
		appendLexOutputFile("IDENTIFIER", yytext, attribute);
		free(attribute);
	}
	yylval.str=yytext;
	return(IDENTIFIER);
}

%%

int yywrap(void) {
	return 1;
}

void move() {
	yylineno++;
}

char* outputTitle() {
	return "Type           Name           Attribute \n";
}

void appendLexOutputFile(const char* type, const char* name, const char* attribute) {
	char* result = (char*)malloc(sizeof(char)*64);
	sprintf(result, "%-15s%-15s%-15s\n", type, name, attribute);
	appendLEX(result);
	// printf("%s", result);
	free(result);
}

