%{
#include <stdio.h>
#include "y.tab.h"

#define TYPE_OUTPUT_LENGTH 15
#define NAME_OUTPUT_LENGTH 15
#define ATTR_OUTPUT_LENGTH 10

char* outputTitle();
void appentLexOutputFile(FILE* file, char* type, char* name, char* attribute);
char* combineItem(char* type, char* name, char* attribute);
void printItem(char* type, char* name, char* attribute);
%}

%%
(0|([1-9][0-9]*))       	    { count(); return(CONSTANT); }
\"(\\.|[^\\"\n])*\"				{ count(); return(STRING_C); }
"print"							{ count(); return(PRINT); }
"input"							{ count(); return(INPUT); }
[a-zA-Z_]([0-9]|[a-zA-Z_]|$)*   { count(); return(IDENTIFER); }
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
%%

int yywrap(void) {
	return 1;
}
char* outputTitle() {
	return "Type           Name           Attribute ";
 }

void appentLexOutputFile(FILE* file, char* type, char* name, char* attribute) {

}

char* combineItem(char* type, char* name, char* attribute) {
	char* result;
	strcpy(result, "");
	char* t, n, a;
	int cursor;
	if (strlen(type) > 15) {
		strncpy(t, type, type + 12);
		strcat(t, ".");
		strcat(t, ".");
		strcat(t, ".");
	}
	else {
		for(cursor = 0; cursor < 15 - strlen(type); cursor++) {
			strcat(t, " ");
		}
	}
	if (strlen(name) > 15) {
		strncpy(n, name, name + 12);
		strcat(n, ".");
		strcat(n, ".");
		strcat(n, ".");
	}
	else {
		for(cursor = 0; cursor < 15 - strlen(name); cursor++) {
			strcat(n, " ");
		}
	}
	if (strlen(attribute) > 10) {
		strncpy(a, attribute, attribute + 7);
		strcat(a, ".");
		strcat(a, ".");
		strcat(a, ".");
	}
	else {
		for(cursor = 0; cursor < 10 - strlen(attribute); cursor++) {
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