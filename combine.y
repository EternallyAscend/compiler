%{
#include <stdio.h>
#include <stdlib.h>
#include "childNode.h"
#include "y.tab.c"

extern "C" 

{
    void yyerror(const char *s);
    extern int yylex(void);
}



%}

%union

{
    char* symbolName;
    child child_label;
}

%token<symbolName> CONSTANT STRING_C PRINT INPUT // Constant "String" print input
%token<symbolName> IDENTIFIER // Idenfifier

%token<symbolName> LP RP LSB RSB LBP RBP // () [] { print_terminal_symbol(word_pos++, ); }
%token<symbolName> POINTER // ->
%token<symbolName> ADDRESS // &
%token<symbolName> NOT // !
%token<symbolName> POW // ^
%token<symbolName> TIMES DIVIDE MOD // * / %
%token<symbolName> PLUS MINUS // + -
%token<symbolName> GT LT GE LE // > < >= <=
%token<symbolName> EQ NE // == !=
%token<symbolName> AND // &&
%token<symbolName> OR // ||
%token<symbolName> ASSIGN // =

%token<symbolName> INT VOID // int void
%token<symbolName> COMMA SEMICOLON // , ;
%token<symbolName> IF ELSE // if else
%token<symbolName> WHILE DO FOR CONTINUE BREAK // while do for continue break
%token<symbolName> RETURN // return
%token<symbolName> STRUCT // struct

// expression
%type<child_label> expression assign_expression orh_expression or_expression andh_expression and_expression
%type<child_label> eneh_expression ene_expression lgh_expression lg_expression pmh_expression pm_expression
%type<child_label> mtd_expression mtdh_expression pow_expression powh_expression not_expression noth_expression
%type<child_label> pid_expression pointer_expression

//type of argument
%type<child_label> type_defination

//for-loop while-loop
%type<child_label> for_expression while_expression do_expression
%type<child_label> for_action_expression for_condition_expression for_init_expression for_more_action_expression for_more_condition_expression

//decorated_identifier eg: **a[3]
%type<child_label> decorated_identifier address_decorator array_decorator high_ay_decorator high_nter_decorator

//statement
%type<child_label> statement statement_body statement_block

//declaration of argument and function
%type<child_label> declaration declaration_name declaration_content argument_declaration function_declaration
%type<child_label> declaration_unit declaration_list declaration_list_tail declaration_init
%type<child_label> function_argument function_argument_list function_argument_tail

//condition
%type<child_label> condition_expression condition_tail

//output
%type<child_label> print_content


%nonassoc NONE_ELSE
%nonassoc ELSE

%start statement_body
%%

expression
    : orh_expression { 
        push_child(word_pos - 1, &($<child_label>$)); 
      } assign_expression { 
        push_child(word_pos - 1, &($$.child_label)); 
        print_non_terminal_symbol(word_pos++, "expression"); 
      }
    ;

assign_expression
    : ASSIGN { 
        print_terminal_symbol(word_pos++, );
        push_child(word_pos - 1, &($<child_label>$));
      } orh_expression { 
        push_child(word_pos - 1, &($<child_label>$)); 
      } assign_expression { 
        push_child(word_pos - 1, &($<child_label>$)); 
        print_non_terminal_symbol(word_pos++, "assign_expression", &($<child_label>$)); 
      }
    | /* epsilon */
    ;

orh_expression
    : andh_expression { push_child(word_pos - 1, &($<child_label>$)); } or_expression { push_child(word_pos - 1, &($<child_label>$)); print_non_terminal_symbol(word_pos++, "orh_expression"); }
    ;

or_expression
    : OR { print_terminal_symbol(word_pos++, ); } andh_expression or_expression { push_child(word_pos - 1, &($<child_label>$)); print_non_terminal_symbol(word_pos++, "or_expression"); }
    | /* epsilon */
    ;

andh_expression
    : eneh_expression and_expression { print_non_terminal_symbol(word_pos++, "andh_expression"); }
    ;

and_expression
    : AND { print_terminal_symbol(word_pos++, ); } eneh_expression and_expression { print_non_terminal_symbol(word_pos++, "and_expression"); }
    | /* epsilon */
    ;

eneh_expression
    : lgh_expression ene_expression { print_non_terminal_symbol(word_pos++, "eneh_expression"); }
    ;

ene_expression
    : EQ { print_terminal_symbol(word_pos++, ); } lgh_expression ene_expression { print_non_terminal_symbol(word_pos++, "ene_expression"); }
    | NE { print_terminal_symbol(word_pos++, ); } lgh_expression ene_expression { print_non_terminal_symbol(word_pos++, "ene_expression"); }
    | /* epsilon */
    ;

lgh_expression
    : pmh_expression lg_expression { print_non_terminal_symbol(word_pos++, "lgh_expression"); }
    ;

lg_expression
    : GT { print_terminal_symbol(word_pos++, ); } pmh_expression lg_expression { print_non_terminal_symbol(word_pos++, "lg_expression"); }
    | GE { print_terminal_symbol(word_pos++, ); } pmh_expression lg_expression { print_non_terminal_symbol(word_pos++, "lg_expression"); }
    | LT { print_terminal_symbol(word_pos++, ); } pmh_expression lg_expression { print_non_terminal_symbol(word_pos++, "lg_expression"); }
    | LE { print_terminal_symbol(word_pos++, ); } pmh_expression lg_expression { print_non_terminal_symbol(word_pos++, "lg_expression"); }
    | /* epsilon */
    ;

pmh_expression
    : mtdh_expression pm_expression { print_non_terminal_symbol(word_pos++, "pmh_expression"); }
    ;

pm_expression
    : PLUS { print_terminal_symbol(word_pos++, ); } mtdh_expression pm_expression { print_non_terminal_symbol(word_pos++, "pm_expression"); }
    | MINUS { print_terminal_symbol(word_pos++, ); } mtdh_expression pm_expression { print_non_terminal_symbol(word_pos++, "pm_expression"); }
    | /* epsilon */
    ;

mtdh_expression
    : powh_expression mtd_expression { print_non_terminal_symbol(word_pos++, "mtdh_expression"); }
    ;

mtd_expression
    : MOD { print_terminal_symbol(word_pos++, ); } powh_expression mtd_expression { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
    | TIMES { print_terminal_symbol(word_pos++, ); } powh_expression mtd_expression { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
    | DIVIDE { print_terminal_symbol(word_pos++, ); } powh_expression mtd_expression { print_non_terminal_symbol(word_pos++, "mtd_expression"); }
    | /* epsilon */
    ;

powh_expression
    : noth_expression pow_expression { print_non_terminal_symbol(word_pos++, "powh_expression"); }
    ;

pow_expression
    : POW { print_terminal_symbol(word_pos++, ); } noth_expression pow_expression { print_non_terminal_symbol(word_pos++, "pow_expression"); }
    | /* epsilon */
    ;

noth_expression
    : pid_expression not_expression { print_non_terminal_symbol(word_pos++, "noth_expression"); }
    ;

not_expression
    : NOT { print_terminal_symbol(word_pos++, ); } pid_expression not_expression { print_non_terminal_symbol(word_pos++, "noth_expression"); }
    | /* epsilon */
    ;

pid_expression
    : LP { print_terminal_symbol(word_pos++, ); } expression RP { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "pid_expression"); }
    | IDENTIFIER { print_terminal_symbol(word_pos++, ); } pointer_expression { print_non_terminal_symbol(word_pos++, "pid_expression"); }
    | CONSTANT { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "pid_expression"); }
    ;

pointer_expression
    : POINTER IDENTIFIER { print_terminal_symbol(word_pos++, ); } pointer_expression { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
    |
    ;

type_defination
    : INT { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
    | VOID { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
    | STRUCT { print_terminal_symbol(word_pos++, ); } IDENTIFIER { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "pointer_expression"); }
    ;

do_expression
    : DO { print_terminal_symbol(word_pos++, ); } { /*establish local scope*/ ;} statement_block WHILE { print_terminal_symbol(word_pos++, ); } LP { print_terminal_symbol(word_pos++, ); } expression RP { print_terminal_symbol(word_pos++, ); } SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "do_expression"); }
    ;

while_expression
    : WHILE { print_terminal_symbol(word_pos++, ); } LP { print_terminal_symbol(word_pos++, ); } expression RP { print_terminal_symbol(word_pos++, ); } { /*establish local scope*/ ;} statement_block { print_non_terminal_symbol(word_pos++, "while_expression"); }
    ;

for_init_expression
    : declaration { print_non_terminal_symbol(word_pos++, "for_init_expression"); }
    | expression for_more_condition_expression { print_non_terminal_symbol(word_pos++, "for_init_expression"); }
    | /* epsilon */
    ;

for_condition_expression
    : expression for_more_condition_expression { print_non_terminal_symbol(word_pos++, "for_condition_expression"); }
    | /* epsilon */
    ;

for_more_condition_expression
    : COMMA { print_terminal_symbol(word_pos++, ); } expression for_more_condition_expression { print_non_terminal_symbol(word_pos++, "for_condition_expression"); }
    | /* epsilon */
    ;
    
for_action_expression
    : expression for_more_action_expression { print_non_terminal_symbol(word_pos++, "for_action_expression"); }
    | /* epsilon */
    ;

for_more_action_expression
    : COMMA { print_terminal_symbol(word_pos++, ); } expression { print_non_terminal_symbol(word_pos++, "for_action_expression"); }
    | /* epsilon */
    ;

for_expression
    : FOR { print_terminal_symbol(word_pos++, ); } { /*establish local scope*/ ;} LP { print_terminal_symbol(word_pos++, ); } for_init_expression SEMICOLON { print_terminal_symbol(word_pos++, ); } for_condition_expression SEMICOLON { print_terminal_symbol(word_pos++, ); } for_action_expression RP { print_terminal_symbol(word_pos++, ); } statement_block { print_non_terminal_symbol(word_pos++, "for_expression"); }
    ;

array_decorator
    : LSB { print_terminal_symbol(word_pos++, ); } expression RSB { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "array_decorator"); }
    ;

high_ay_decorator
    : array_decorator high_ay_decorator { print_non_terminal_symbol(word_pos++, "high_ay_decorator"); }
    |
    ;

high_nter_decorator
    : TIMES { print_terminal_symbol(word_pos++, ); } high_nter_decorator { print_non_terminal_symbol(word_pos++, "high_nter_decorator"); }
    |
    ;

address_decorator
    : ADDRESS { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "address_decorator"); }
    | 
    ;

decorated_identifier
    : address_decorator high_nter_decorator IDENTIFIER { print_terminal_symbol(word_pos++, ); } high_ay_decorator { print_non_terminal_symbol(word_pos++, "decorated_identifier"); }
    ;

statement
    : expression SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    //| function { print_non_terminal_symbol(word_pos++, ""); }
    | for_expression { print_non_terminal_symbol(word_pos++, "statement"); }
    | do_expression { print_non_terminal_symbol(word_pos++, "statement"); }
    | while_expression { print_non_terminal_symbol(word_pos++, "statement"); }
    | condition_expression { print_non_terminal_symbol(word_pos++, "statement"); }
    | declaration SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    | { /*establish local scope*/ ; }statement_block { print_non_terminal_symbol(word_pos++, "statement"); }
    | BREAK { print_terminal_symbol(word_pos++, ); } SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    | CONTINUE { print_terminal_symbol(word_pos++, ); } SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    | RETURN { print_terminal_symbol(word_pos++, ); } expression SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    | SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, ""); }
    | PRINT { print_terminal_symbol(word_pos++, ); } LP { print_terminal_symbol(word_pos++, ); } print_content RP { print_terminal_symbol(word_pos++, ); } SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    | INPUT { print_terminal_symbol(word_pos++, ); } LP { print_terminal_symbol(word_pos++, ); } decorated_identifier RP { print_terminal_symbol(word_pos++, ); } SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement"); }
    ;



print_content
    : expression { print_non_terminal_symbol(word_pos++, "print_content"); }
    | STRING_C { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "print_content"); }
    ;

statement_block
    : LBP { print_terminal_symbol(word_pos++, ); } statement_body RBP { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "statement_block"); }
    ;

statement_body
    : statement statement_body { print_non_terminal_symbol(word_pos++, "statement_body"); }
    |
    ;

function_declaration
    : LP { print_terminal_symbol(word_pos++, ); } function_argument_list RP { print_terminal_symbol(word_pos++, ); } { /*establish local scope*/ ;} statement_block { print_non_terminal_symbol(word_pos++, "function_declaration"); }
    ;

argument_declaration
    : declaration_list SEMICOLON { print_terminal_symbol(word_pos++, ); } { print_non_terminal_symbol(word_pos++, "argument_declaration"); }
    ;

declaration
    : declaration_name declaration_content { print_non_terminal_symbol(word_pos++, "declaration"); }
    ;

declaration_content
    : function_declaration { print_non_terminal_symbol(word_pos++, "declaration_content"); }
    | argument_declaration { print_non_terminal_symbol(word_pos++, "declaration_content"); }
    ;

declaration_name
    : type_defination decorated_identifier { print_non_terminal_symbol(word_pos++, "declaration_name"); }
    ;

// declaration_list
//     : declaration_unit COMMA declaration_list { print_non_terminal_symbol(word_pos++, ""); }
//     | declaration_unit { print_non_terminal_symbol(word_pos++, ""); }
//     ;
declaration_list
    : declaration_unit declaration_list_tail { print_non_terminal_symbol(word_pos++, "declaration_list"); }
    ;

declaration_list_tail
    : COMMA { print_terminal_symbol(word_pos++, ); } declaration_list //{ print_non_terminal_symbol(word_pos++, "declaration_list_tail"); }
    | 
    ;

declaration_unit
    : decorated_identifier declaration_init { print_non_terminal_symbol(word_pos++, "declaration_unit"); }
    ;

declaration_init
    : ASSIGN { print_terminal_symbol(word_pos++, ); } expression { print_non_terminal_symbol(word_pos++, "declaration_init"); }
    | 
    ;

function_argument
    : declaration_name declaration_init{ print_non_terminal_symbol(word_pos++, "function_argument"); }
    ;

function_argument_list
    : function_argument function_argument_tail { print_non_terminal_symbol(word_pos++, "function_argument_list"); }
    |
    ;

function_argument_tail
    : COMMA { print_terminal_symbol(word_pos++, ); } function_argument_list //{ print_non_terminal_symbol(word_pos++, "function_argument_tail"); }
    |
    ;

condition_expression
    : IF { print_terminal_symbol(word_pos++, ); } LP { print_terminal_symbol(word_pos++, ); } expression RP { print_terminal_symbol(word_pos++, ); } statement condition_tail { print_non_terminal_symbol(word_pos++, "condition_tail"); } { print_non_terminal_symbol(word_pos++, "condition_expression"); }
    ;

condition_tail
    : ELSE { print_terminal_symbol(word_pos++, ); } statement 
    | {}%prec NONE_ELSE
    ;

%%

%{
    void print_non_terminal_symbol(int word_pos, const char* sentence, child* childSymbol){
        printf(sentence);
        printf(":%d", word_pos);
        printf("/t/tchild:");
        for (int i = 0; i < childSymbol)
    }

    void print_terminal_symbol(){

    }

    int main(void)  { 
        int word_pos = 0;
        yyparse(); 
        return 0; 
        // grammerItem grammerHead
        // grammerItem* grammerStackTail;
        // int size = 0;
    }   
%}
