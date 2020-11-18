%{
#include <stdio.h>
#include <stdlib.h>
#include <y.tab.c>
%}

%token IDENTIFIER // Idenfifier
%token CONSTANT STRING_LITERAL // Constant String_literal
%token INT VOID// int void
%token ASSIGN // =
%token PLUS MINUS TIMES DIVIDE MOD XOR // + - * / % ^
%token LP RP LSB RSB LBP RBP // () [] {}
%token EQ GT LT GE LE NE // == > < >= <= !=
%token IF ELSE // if else
%token AND OR NOT // && || !
%token WHILE DO FOR CONTINUE BREAK // while do for continue break
%token RETURN // return
%token STRUCT // struct

%start translate_unit

%%

%%