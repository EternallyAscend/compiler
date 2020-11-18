%{
#include <stdio.h>
#include <stdlib.h>
#include <y.tab.c>
%}

%token IDENTIFIER // Idenfifier
%token CONSTANT STRING_LITERAL // Constant String_literal
%token INT VOID// int void
%token ASSIGN // =
%token PLUS MINUS TIMES DIVIDE MOD POW // + - * / % ^
%token LP RP LSB RSB LBP RBP // () [] {}
%token EQ GT LT GE LE NE // == > < >= <= !=
%token IF ELSE // if else
%token AND OR NOT // && || !
%token WHILE DO FOR CONTINUE BREAK // while do for continue break
%token RETURN // return
%token STRUCT // struct

%start translate_unit
// sharp expression // #
// define expression // #define MAX 5; => sharp define NAME STRING_LITERAL;
// header expression // stdio.h
// include expression // #include <stdio.h>/"stack.h" => sharp include header
// statement expression // int item;
// function statement expression // int main(void);
// function expression // int main(void) {-- body --}
// function body expression // --int main(void){-- body --}--
// program expression // define, include, statement, assign ,main. // Finish analysis all file.
// formula_expression // 1+2*3%4;
// assgin expression // item = value/formula_expression;
// status expression // true/false (the expression in cpp) 1/0 in fact; // == > < >= <= !=
// while expression // while() {}
// for expression // for (init; status; operation) {}
// if expression // if (status) {} else if () {} else {}

%%

value_expression
    : mtdh_expression pm_expression
    ;

or_expression
    :
    ;

and_expression
    :
    ;

pm_expression
    : PLUS mtdh_expression pm_expression
    | MINUS mtdh_expression pm_expression
    | /* epsilon */
    ;

mtdh_expression
    : powh_expression mtd_expression
    ;

mtd_expression
    : MOD powh_expression mtd_expression
    | TIMES powh_expression mtd_expression
    | DIVIDE powh_expression mtd_expression
    | /* espilon */
    ;

powh_expression
    : pid_expression pow_expression
    ;

pow_expression
    : POW pid_expression pow_expression
    | /* epsilon */
    ;

not_expression
    :
    ;

pid_expression
    : LP value_expression RP
    | IDENTIFIER /* value_expression */
    ;

type_defination
    : INT
    | STRUCT IDENTIFIER
    ;

formula_expression
    : IDENTIFIER
    ;

value_expression
    : IDENTIFIER
    | formula_expression
    ;

assign_expression
    : ASSIGN value_expression
    ;

primary_expression
    : IDENTIFIER
    | CONSTANT
    | STRING_LITERAL
    | `(``)`
    ;

%%
