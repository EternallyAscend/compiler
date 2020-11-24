%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.c"
%}

%token CONSTANT STRING_LITERAL // Constant String_literal
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

%token INT // int
%token COMMA SEMICOLON // , ;
%token IF ELSE // if else
%token WHILE DO FOR CONTINUE BREAK // while do for continue break
%token RETURN // return
%token STRUCT // struct

%start entry
%%

expression
    : orh_expression assign_expression
    ;

assign_expression
    : ASSIGN orh_expression assign_expression
    | /* epsilon */
    ;

orh_expression
    : andh_expression or_expression
    ;

or_expression
    : OR andh_expression or_expression
    | /* epsilon */
    ;

andh_expression
    : eneh_expression and_expression
    ;

and_expression
    : AND eneh_expression and_expression
    | /* epsilon */
    ;

eneh_expression
    : lgh_expression ene_expression
    ;

ene_expression
    : EQ lgh_expression ene_expression
    | NE lgh_expression ene_expression
    | /* epsilon */
    ;

lgh_expression
    : pmh_expression lg_expression
    ;

lg_expression
    : GT pmh_expression lg_expression
    | GE pmh_expression lg_expression
    | LT pmh_expression lg_expression
    | LE pmh_expression lg_expression
    | /* epsilon */
    ;

pmh_expression
    : mtdh_expression pm_expression
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
    | /* epsilon */
    ;

powh_expression
    : noth_expression pow_expression
    ;

pow_expression
    : POW noth_expression pow_expression
    | /* epsilon */
    ;

noth_expression
    : pid_expression not_expression
    ;

not_expression
    : NOT pid_expression not_expression
    | /* epsilon */
    ;

pid_expression
    : LP expression RP
    | IDENTIFIER
    ;

type_defination
    : INT
    | STRUCT IDENTIFIER
    ;

do_expression
    : DO statement_block WHILE LP expression RP SEMICOLON
    ;

while_expression
    : WHILE LP expression RP statement_block
    ;

for_init_expression
    : declaration
    | expression for_more_condition_expression
    | /* epsilon */
    ;

for_condition_expression
    : expression for_more_condition_expression
    | /* epsilon */
    ;

for_more_condition_expression
    : COMMA expression for_more_condition_expression
    | /* epsilon */
    ;
    
for_action_expression
    : expression for_more_action_expression
    | /* epsilon */
    ;

for_more_action_expression
    : COMMA expression
    | /* epsilon */
    ;

for_expression
    : FOR LP for_init_expression SEMICOLON for_condition_expression SEMICOLON for_action_expression RP statement_block
    ;

array_decorator
    : LSB expression RSB
    ;

high_level_array_decorator
    : array_decorator high_level_array_decorator
    |
    ;

high_level_pointer_decorator
    : TIMES high_level_pointer_decorator
    |
    ;

address_decorator
    : ADDRESS
    | 
    ;

decorated_identifier
    : address_decorator high_level_pointer_decorator IDENTIFIER high_level_array_decorator
    ;

condition_loop_block
    : statement_block
    | expression
    |
    ;

entry
    : statement_body INT 'main' LP function_argument_list RP statement_block statement_body

statement
    : expression SEMICOLON
    | function
    | for_expression
    | do_expression
    | while_expression
    | condition_expression
    | declaration SEMICOLON
    | statement_block
    ;

statement_block
    : LBP statement_body RBP
    ;

statement_body
    : statement statement_body
    |
    ;

function
    : type_defination decorated_identifier LP function_argument_list RP statement_block
    ;

declaration
    : type_defination declaration_list SEMICOLON
    ;


declaration_list
    : declaration_unit COMMA declaration_list
    | declaration_unit
    ;

declaration_unit
    : decorated_identifier declaration_init
    ;

declaration_init
    : ASSIGN expression
    | 
    ;

function_argument
    : type_defination decorated_identifier
    ;

function_argument_list
    : function_argument COMMA function_argument_list
    | function_argument
    |
    ;

condition_expression
    : condition_start_expression condition_branches_expression SEMICOLON
    | condition_start_expression SEMICOLON
    ;

condition_start_expression
    : IF LP expression RP condition_loop_block 
    ;

condition_branch_expression
    : ELSE condition_start_expression
    | ELSE condition_loop_block
    ;

condition_branches_expression
    : condition_branch_expression condition_branches_expression
    | condition_branch_expression
    ;

%%
