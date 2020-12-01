%{
#include <stdio.h>
#include "file.h"
#include "table.h"
#include "y.tab.h"

#define TYPE_OUTPUT_LENGTH 15
#define NAME_OUTPUT_LENGTH 15
#define ATTR_OUTPUT_LENGTH 10

void move();
char* outputTitle();
void appentLexOutputFile(FILE* file, char* type, char* name, char* attribute);
char* combineItem(char* type, char* name, char* attribute);
void printItem(char* type, char* name, char* attribute);
%}

%%
[\t \r]+						{ move(); }
(0|([1-9][0-9]*))       	    { appentLexOutputFile("CONSTANT", yytext, yytext); return(CONSTANT); }
\"(\\.|[^\\"\n])*\"				{ appentLexOutputFile("STRING_C", yytext, yytext); return(STRING_C); }
"print"							{ appentLexOutputFile("PRINT", yytext, ""); return(PRINT); }
"input"							{ appentLexOutputFile("INPUT", yytext, ""); return(INPUT); }
[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   {
	{
		if (search(yytext)) {
			printf("Exist at line %d.\n", yylineno);
		}
		else {
			int position = add(yytext);
			char* attr;
			itoa(position, attr, 10);
			char* attribute;
			strcpy(attribute, "0x");
			strcat(attribute, attr);
			appentLexOutputFile("IDENTIFER", yytext, );
		}
	}
	yyval.str=yytext;
	return(IDENTIFER);
}

"("			{ appentLexOutputFile("LP", yytext, ""); return(LP); }
")"			{ appentLexOutputFile("RP", yytext, ""); return(RP); }
"["         { appentLexOutputFile("LSB", yytext, ""); return(LSB); }
"]"         { appentLexOutputFile("RSB", yytext, ""); return(RSB); }
"{"         { appentLexOutputFile("LBP", yytext, ""); return(LBP); }
"}"         { appentLexOutputFile("RBP", yytext, ""); return(RBP); }
"->"		{ appentLexOutputFile("POINTER", yytext, ""); return(POINTER); }
"&"			{ appentLexOutputFile("ADDRESS", yytext, ""); return(ADDRESS); }
"!"			{ appentLexOutputFile("NOT", yytext, ""); return(NOT); }
"^"			{ appentLexOutputFile("POW", yytext, ""); return(POW); }
"*"			{ appentLexOutputFile("TIMES", yytext, ""); return(TIMES); }
"/"			{ appentLexOutputFile("DIVIDE", yytext, ""); return(DIVIDE); }
"%"			{ appentLexOutputFile("MOD", yytext, ""); return(MOD); }
"+"			{ appentLexOutputFile("PLUS", yytext, ""); return(PLUS); }
"-"			{ appentLexOutputFile("MINUS", yytext, ""); return(MINUS); }
"<"			{ appentLexOutputFile("GT", yytext, ""); return(GT); }
">"			{ appentLexOutputFile("LT", yytext, ""); return(LT); }
"<="		{ appentLexOutputFile("LE", yytext, ""); return(LE); }
">="		{ appentLexOutputFile("GE", yytext, ""); return(GE); }
"=="		{ appentLexOutputFile("EQ", yytext, ""); return(EQ); }
"!="		{ appentLexOutputFile("NE", yytext, ""); return(NE); }
"&&"		{ appentLexOutputFile("AND", yytext, ""); return(AND); }
"||"		{ appentLexOutputFile("OR", yytext, ""); return(OR); }
"="			{ appentLexOutputFile("ASSIGN", yytext, ""); return(ASSIGN); }
"int"		{ appentLexOutputFile("INT", yytext, ""); return(INT); }
"void"      { appentLexOutputFile("VOID", yytext, ""); return(VOID); }
","			{ appentLexOutputFile("COMMA", yytext, ""); return(COMMA); }
";"			{ appentLexOutputFile("SEMICOLON", yytext, ""); return(SEMICOLON); }
"if"		{ appentLexOutputFile("IF", yytext, ""); return(IF); }
"else"		{ appentLexOutputFile("ELSE", yytext, ""); return(ELSE); }
"while"		{ appentLexOutputFile("WHILE", yytext, ""); return(WHILE); }
"do"		{ appentLexOutputFile("DO", yytext, ""); return(DO); }
"for"		{ appentLexOutputFile("FOR", yytext, ""); return(FOR); }
"continue"	{ appentLexOutputFile("CONTINUE", yytext, ""); return(CONTINUE); }
"break"		{ appentLexOutputFile("BREAK", yytext, ""); return(BREAK); }
"return"	{ appentLexOutputFile("RETURN", yytext, ""); return(RETURN); }
"struct"	{ appentLexOutputFile("STRUCT", yytext, ""); return(STRUCT); }
%%

int yywrap(void) {
	return 1;
}
char* outputTitle() {
	return "Type           Name           Attribute ";
 }

void appentLexOutputFile(char* type, char* name, char* attribute) {
	appendLEX(combineItem(type, name, attribute));
	printItem(type, name, attribute);
}

char* combineItem(char* type, char* name, char* attribute) {
	char* result;
	strcpy(result, "");
	char* t, n, a;
	int cursor;
	if (strlen(type) > TYPE_OUTPUT_LENGTH) {
		strncpy(t, type, type + TYPE_OUTPUT_LENGTH - 3);
		strcat(t, ".");
		strcat(t, ".");
		strcat(t, ".");
	}
	else {
		for(cursor = 0; cursor < TYPE_OUTPUT_LENGTH - strlen(type); cursor++) {
			strcat(t, " ");
		}
	}
	if (strlen(name) > NAME_OUTPUT_LENGTH) {
		strncpy(n, name, name + NAME_OUTPUT_LENGTH - 3);
		strcat(n, ".");
		strcat(n, ".");
		strcat(n, ".");
	}
	else {
		for(cursor = 0; cursor < NAME_OUTPUT_LENGTH - strlen(name); cursor++) {
			strcat(n, " ");
		}
	}
	if (strlen(attribute) > ATTR_OUTPUT_LENGTH) {
		strncpy(a, attribute, attribute + ATTR_OUTPUT_LENGTH - 3);
		strcat(a, ".");
		strcat(a, ".");
		strcat(a, ".");
	}
	else {
		for(cursor = 0; cursor < ATTR_OUTPUT_LENGTH - strlen(attribute); cursor++) {
			strcat(a, " ");
		}
	}
	strcat(result, t);
	strcat(result, n);
	strcat(result, a);
	return result;
}

void printItem(char* type, char* name, char* attribute) {
	printf("%s\n", combineItem(type, name, attribute));
}
