%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.c"

extern "C" 

{
    void yyerror(const char *s);
    extern int yylex(void);
}

%}

%token CONSTANT STRING_C PRINT INPUT // Constant "String" print input
%token IDENTIFIER // Idenfifier

%token LP RP LSB RSB LBP RBP // () [] {}
%token POINTER // ->
%token ADDRESS // &
%token NOT // !
%token POW // ^
%token TIMES DIVIDE MOD // * / %
%token PLUS MINUS // + -
%token GT LT GE LE // > < >= <=
%token EQ NE // == !=
%token AND // &&
%token OR // ||
%token ASSIGN // =

%token INT VOID // int void
%token COMMA SEMICOLON // , ;
%token IF ELSE // if else
%token WHILE DO FOR CONTINUE BREAK // while do for continue break
%token RETURN // return
%token STRUCT // struct

%nonassoc NONE_ELSE
%nonassoc ELSE

%start statement_body
%%

expression
    : {level++;}orh_expression assign_expression { level--; }
    ;

assign_expression
    : {level++;} ASSIGN orh_expression assign_expression { level--; }
    | /* epsilon */
    ;

orh_expression
    : {level++;} andh_expression or_expression { level--; }
    ;

or_expression
    : {level++;} OR andh_expression or_expression { level--; }
    | /* epsilon */
    ;

andh_expression
    : {level++;} eneh_expression and_expression { level--; }
    ;

and_expression
    : {level++;} AND eneh_expression and_expression { level--; }
    | /* epsilon */
    ;

eneh_expression
    : {level++;} lgh_expression ene_expression { level--; }
    ;

ene_expression
    : {level++;} EQ lgh_expression ene_expression { level--; }
    | {level++;} NE lgh_expression ene_expression { level--; }
    | /* epsilon */
    ;

lgh_expression
    : {level++;} pmh_expression lg_expression { level--; }
    ;

lg_expression
    : {level++;} GT pmh_expression lg_expression { level--; }
    | {level++;} GE pmh_expression lg_expression { level--; }
    | {level++;} LT pmh_expression lg_expression { level--; }
    | {level++;} LE pmh_expression lg_expression { level--; }
    | /* epsilon */
    ;

pmh_expression
    : {level++;} mtdh_expression pm_expression { level--; }
    ;

pm_expression
    : {level++;} PLUS mtdh_expression pm_expression { level--; }
    | {level++;} MINUS mtdh_expression pm_expression { level--; }
    | /* epsilon */
    ;

mtdh_expression
    : {level++;} powh_expression mtd_expression { level--; }
    ;

mtd_expression
    : {level++;} MOD powh_expression mtd_expression { level--; }
    | {level++;} TIMES powh_expression mtd_expression { level--; }
    | {level++;} DIVIDE powh_expression mtd_expression { level--; }
    | /* epsilon */
    ;

powh_expression
    : {level++;} noth_expression pow_expression { level--; }
    ;

pow_expression
    : {level++;} POW noth_expression pow_expression { level--; }
    | /* epsilon */
    ;

noth_expression
    : {level++;} pid_expression not_expression { level--; }
    ;

not_expression
    : {level++;} NOT pid_expression not_expression { level--; }
    | /* epsilon */
    ;

pid_expression
    : {level++;} LP expression RP { level--; }
    | {level++;} IDENTIFIER pointer_expression { level--; }
    | {level++;} CONSTANT { level--; }
    ;

pointer_expression
    : {level++;} POINTER IDENTIFIER pointer_expression
    |
    ;

type_defination
    : {level++;} INT { level--; }
    | {level++;} VOID { level--; }
    | {level++;} STRUCT IDENTIFIER { level--; }
    ;

do_expression
    : {level++;} DO { /*establish local scope*/ ;} statement_block WHILE LP expression RP SEMICOLON { level--; }
    ;

while_expression
    : {level++;} WHILE LP expression RP { /*establish local scope*/ ;} statement_block { level--; }
    ;

for_init_expression
    : {level++;} declaration { level--; }
    | {level++;} expression for_more_condition_expression { level--; }
    | /* epsilon */
    ;

for_condition_expression
    : {level++;} expression for_more_condition_expression { level--; }
    | /* epsilon */
    ;

for_more_condition_expression
    : {level++;} COMMA expression for_more_condition_expression { level--; }
    | /* epsilon */
    ;
    
for_action_expression
    : {level++;} expression for_more_action_expression { level--; }
    | /* epsilon */
    ;

for_more_action_expression
    : {level++;} COMMA expression { level--; }
    | /* epsilon */
    ;

for_expression
    : {level++;} FOR { /*establish local scope*/ ;} LP for_init_expression SEMICOLON for_condition_expression SEMICOLON for_action_expression RP statement_block { level--; }
    ;

array_decorator
    : {level++;} LSB expression RSB { level--; }
    ;

high_level_array_decorator
    : {level++;} array_decorator high_level_array_decorator { level--; }
    |
    ;

high_level_pointer_decorator
    : {level++;} TIMES high_level_pointer_decorator { level--; }
    |
    ;

address_decorator
    : {level++;} ADDRESS { level--; }
    | 
    ;

decorated_identifier
    : {level++;} address_decorator high_level_pointer_decorator IDENTIFIER high_level_array_decorator { level--; }
    ;

statement
    : {level++;} expression SEMICOLON { level--; }
    //| function { level--; }
    | {level++;} for_expression { level--; }
    | {level++;} do_expression { level--; }
    | {level++;} while_expression { level--; }
    | {level++;} condition_expression { level--; }
    | {level++;} declaration SEMICOLON { level--; }
    |  {{level++;} /*establish local scope*/ ;}statement_block { level--; }
    | {level++;} BREAK SEMICOLON { level--; }
    | {level++;} CONTINUE SEMICOLON { level--; }
    | {level++;} RETURN expression SEMICOLON { level--; }
    | {level++;} SEMICOLON { level--; }
    | {level++;} PRINT LP print_content RP SEMICOLON { level--; }
    | {level++;} INPUT LP expression RP SEMICOLON { level--; }
    ;

print_content
    : {level++;} expression
    | {level++;} STRING_C
    ;

statement_block
    : {level++;} LBP statement_body RBP { level--; }
    ;

statement_body
    : {level++;} statement statement_body { level--; }
    |
    ;

function_declaration
    : {level++;} LP function_argument_list RP { /*establish local scope*/ ;} statement_block { level--; }
    ;

argument_declaration
    : {level++;} declaration_list SEMICOLON { level--; }
    ;

declaration
    : {level++;} declaration_name declaration_content
    ;

declaration_content
    : {level++;} function_declaration
    | {level++;} argument_declaration
    ;

declaration_name
    : {level++;} type_defination decorated_identifier
    ;

// declaration_list
//     : declaration_unit COMMA declaration_list { level--; }
//     | declaration_unit { level--; }
//     ;
declaration_list
    : {level++;} declaration_unit declaration_list_tail { level--; }
    ;

declaration_list_tail
    : {level++;} COMMA declaration_list { level--; }
    | 
    ;

declaration_unit
    : {level++;} decorated_identifier declaration_init { level--; }
    ;

declaration_init
    : {level++;} ASSIGN expression { level--; }
    | 
    ;

function_argument
    : {level++;} type_defination decorated_identifier { level--; }
    ;

function_argument_list
    : {level++;} function_argument function_argument_tail { level--; }
    |
    ;

function_argument_tail
    : {level++;} COMMA function_argument_list
    |
    ;

condition_expression
    : {level++;} IF LP expression RP statement {level++;} condition_tail { level--; } { level--; }
    ;

condition_tail
    : ELSE statement 
    | %prec NONE_ELSE

%%

%{
    void print_sentence(int offset){
        for(int i = 0; i < offset; i++){
            printf('\t');
        }
    }

    int main(void)  { 
        int level = 0;
        yyparse(); 
        return 0; 
    }   
%}
