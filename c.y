%{
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "table.h"
#include "grammerTree.h"
#include "indirectTriple.h"
#include "y.tab.h"

#ifdef __cplusplus
extern "C" 

{
#endif
    enum OPERATORS {
        _ERROR=-1,
        _VOID=0,
        _INT=1,

        _FOR=10,
        _FOR_INIT=11,
        _FOR_CONDITION=12,
        _FOR_ACTION=13,
        _FOR_EXPRESSION=14,
        
        _WHILE_CONDITION=16,
        _DO_WHILE=17,
        _DO=18,
        _WHILE=19,

        _CONTINUE=999,
        _BREAK=1000,

        _IF=20,
        _ELSE=21,
        _IF_STMT=22,
        _IF_CONDITION=23,

        _RETURN=30,

        _ADDRESS=40,

        _ARRAY=50,

        _LPRP=60,
        _LP=61,
        _RP=62,
        _SLPRP=63,
        _LSP=64,
        _RSP=65,
        _BLPRP=66,
        _LBP=67,
        _RBP=68,

        _LOOP=70,

        _POINTER=80,

        _ASSIGN=100,
        _DECLARATION=101,
        _ARGUMENT_DECLARATION_LIST=102,
        _DECLARATION_BODY=103,
        _ARGUMENT_DECLARATION_UNIT=104,


        _EQUAL=200,
        _NOTEQUAL=201,
        _GT=202,
        _LT=203,
        _GE=204,
        _LE=205,

        _AND=300,
        _OR=301,
        _NOT=302,

        _ADD=400,
        _MINUS=401,
        _TIMES=402,
        _DIVIDE=403,
        _MOD=404,
        _POW=405,

        _COMMA=500,

        _STMT_BODY=600,

        _INPUT=65000,
        _PRINT_CONTENT=65001,
        _PRINT=65002,

        _MAIN=65532,
        _ID=65533,
        _STRING=65534,
        _CONST=65535,
    } op;
    extern FILE* yyin;
    void yyerror(const char *s);
    extern int yylex(void);
    extern char* name;
    extern int yylineno;

#ifdef __cplusplus
};
#endif

grammerTree* root;
grammerTree* curNode;
grammerTree* tempPointer;
grammerTree* stack[128];
int stackContentSize = 0;

void extendTree(int isTerminal, const char* word, const char* grammer, int op);
void backToParent();
void extendOptTree(const char* opt, int op);
void extendTerminal(const char* word, const char* grammer, int op);
void broToParent(int num);
void connectParentChild();

void saveNode();
void loadNode();

void appendLexOutputIDFile(const char* type, const char* name, const char* attribute);
void declarationId(const char* name);
void useId(const char* name);

/* Not write value here. */
struct Instruction* instruction = NULL;
int currentType = 1;
int isInited = 0;

%}

%union

{
    char* str;
}

%token<str> CONSTANT STRING_C PRINT INPUT // Constant "String" print input
%token<str> IDENTIFIER // Idenfifier

%token<str> LP RP LSB RSB LBP RBP // () [] {  }
%token<str> POINTER // ->
%token<str> ADDRESS // &
%token<str> NOT // !
%token<str> POW // ^
%token<str> TIMES DIVIDE MOD // * / %
%token<str> PLUS MINUS // + -
%token<str> GT LT GE LE // > < >= <=
%token<str> EQ NE // == !=
%token<str> AND // &&
%token<str> OR // ||
%token<str> ASSIGN // =

%token<str> INT VOID // int void
%token<str> COMMA SEMICOLON // , ;
%token<str> IF ELSE // if else
%token<str> WHILE DO FOR CONTINUE BREAK // while do for continue break
%token<str> RETURN // return
%token<str> STRUCT // struct
%token<str> MAIN // main

// expression
%type<str> expression assign_expression orh_expression or_expression andh_expression and_expression
%type<str> eneh_expression ene_expression lgh_expression lg_expression pmh_expression pm_expression
%type<str> mtd_expression mtdh_expression pow_expression powh_expression not_expression noth_expression
%type<str> pid_expression // pointer_expression

//type of argument
%type<str> type_defination

//for-loop while-loop
%type<str> for_expression while_expression do_expression
%type<str> for_action_expression for_condition_expression for_init_expression
//decorated_identifier eg: **a[3]
%type<str> decorated_identifier address_decorator array_decorator high_ay_decorator high_nter_decorator

//statement
%type<str> statement statement_body statement_block

//declaration of argument and function
%type<str> declaration function_declaration
%type<str> argument_declaration_unit argument_declaration_list argument_declaration_list_tail argument_declaration_init
%type<str> function_argument function_argument_list function_argument_tail

//condition
%type<str> condition_expression condition_tail

//output
%type<str> print_content

//opt
%type<str> cmp_opt ene_opt mtd_opt
%type<str> entry main_args public_statement action_defination
 /* interface */

%nonassoc NONE_ELSE
%nonassoc ELSE

%start entry
%%


expression
    : single_expression {
        curNode->type = curNode->child[0]->type;
        sprintf(curNode->value, "%s", curNode->child[0]->value);
    } comma_expression 
    ;

comma_expression
    : COMMA {
        extendOptTree(",", _COMMA);
    } single_expression {
        backToParent();
    } comma_expression
    | COMMA error {
        extendOptTree(",", _COMMA);
        yyerror("invalid syntax after ,");
        extendTerminal("error", "invalid syntax after ,", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

single_expression
    : orh_expression assign_expression {
        /*
        if (1 == curNode->size) {
            curNode->type = curNode->child[0]->type;
            sprintf(curNode->value, "%s", curNode->child[0]->value);
        }
        else {
            if (curNode->child[0]->type != curNode->child[1]->type) {
                yyerror("Wrong expression input.\n");
            }
            else {
                curNode->type = curNode->child[0]->type;
                curNode->end = makeNewTemp(instruction,
                 generateIndirectTriple(curNode->child[1]->operators,
                                        curNode->child[0]->value,
                                        curNode->child[1]->value));
                // curNode->value = instruction->values[curNode->end];
                sprintf(curNode->value, "#%d", curNode->end);
            }
        }
        */
        // sprintf(curNode->value, "%d", makeNewTemp(instruction,
        //  generateIndirectTriple("=", curNode->child[0]->value, curNode->child[1]->value)));
        // "=" curNode->child[0]->value, curNode->child[1]->value;
        // curNode->type = curNode->child[0]->type;
    }
    ;

assign_expression
    : ASSIGN { 
        extendOptTree("=", _ASSIGN);
    } orh_expression {
        /*
        curNode->parent->type = curNode->type; 
        sprintf(curNode->parent->value, "%s", curNode->value);
        */
        backToParent();
    } assign_expression {
        /*
        if (curNode->child[0]->type != curNode->child[1]->type) {
            yyerror("Wrong expression input.\n");
        }
        else {
            curNode->type = curNode->child[1]->type; // Whether is child1 here? @zzy
            curNode->end = makeNewTemp(instruction, generateIndirectTriple(curNode->child[1]->operators,
                                                                           curNode->value,
                                                                           curNode->child[1]->value));
            sprintf(curNode->value, "#%d", curNode->end);
            // sprintf(curNode->value, "%d", makeNewTemp(instruction,
            //  generateIndirectTriple("=", curNode->child[0]->value, curNode->child[1]->value)));
        }
        */
    }
    | ASSIGN error {
        extendOptTree("=", _ASSIGN);
        yyerror("Wrong assign expression.");
        extendTerminal("error", "assign expression error", _ERROR);
        backToParent();
    }
    | {

    } /* epsilon */
    ;

orh_expression
    : andh_expression or_expression {
        // char end[64];
        // sprintf(end, "\#%d", curNode->child[1]->begin);
        // curNode->begin = makeNewTemp(instruction, generateIndirectTriple("j", curNode->child[0]->value, "_"));
        // int temp = makeNewTemp(instruction, generateIndirectTriple("j", curNode->child[1]->value, "_"));
        // curNode->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
        // sprintf(end, "%d", curNode->end+1);
        // rewriteTemp(instruction, temp, 2, end);
        // rewriteTemp(instruction, curNode->begin, 2, end);

        // sprintf(end, "\#%d", curNode->child[1]->begin);
        // rewriteTemp(instruction, curNode->child[0]->end, 2, curNode->child[1]->begin);
        // curNode->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
        // rewriteTemp(instruction, curNode->child[1]->end, 2, curNode->end);
        // curNode->type = curNode->child[0]->type;
        // sprintf(curNode->value, "\#%d", curNode->end);
    }
    ;

or_expression
    : OR { 
        // sprintf(curNode->operators, "||");
        extendOptTree("||", _OR);
    } andh_expression {
        backToParent();
    } or_expression
    | OR error {
        extendOptTree("||", _OR);
        yyerror("invalid syntax after ||");
        extendTerminal("error", "invalid syntax after ||", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

andh_expression
    : eneh_expression and_expression 
    ;

and_expression
    : AND {  
        extendOptTree("&&", _AND);
    } eneh_expression {
        backToParent();
    } and_expression
    | AND {
        extendOptTree("&&", _AND);
        yyerror("invalid syntax after &&");
        extendTerminal("error", "invalid syntax after &&", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

eneh_expression
    : lgh_expression ene_expression
    ;

ene_expression
    : ene_opt lgh_expression {
        backToParent();
    }
    | ene_opt error {
        char str[64];
        sprintf(str, "invalid syntax after %s", $1);
        yyerror(str);
        extendTerminal("error", str, _ERROR);
        backToParent();
    }
    |
    ;

ene_opt
    : EQ {  
        extendOptTree("==", _EQUAL);
        strcpy($$, "==");
    }
    | NE  {  
        extendOptTree("!=", _NOTEQUAL);
        strcpy($$, "!=");
    }
    ;

lgh_expression
    : pmh_expression lg_expression {
        // generateIndirectTripleCode.
    }
    ;

lg_expression
    : cmp_opt pmh_expression {
        /*
        sprintf(curNode->operators, "%s", curNode->child[0]->operators);
        curNode->type = 1;
        sprintf(curNode->value, "%s", curNode->child[1]->value);
        */
        backToParent();
    }
    | cmp_opt error {
        char str[64];
        sprintf(str, "invalid syntax after %s", $1);
        yyerror(str);
        extendTerminal("error", str, _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

cmp_opt
    : GT {  
        extendOptTree(">", _GT);
        strcpy($$, ">");
    }
    | GE {  
        extendOptTree(">=", _GE);
        strcpy($$, ">=");
    }
    | LT {  
        extendOptTree("<", _LT);
        strcpy($$, "<");
    } 
    | LE {  
        extendOptTree("<=", _LE);
        strcpy($$, "<=");
    }
    ;

pmh_expression
    : mtdh_expression pm_expression
    ;

pm_expression
    : PLUS { 
        extendOptTree("+", _ADD);
    } mtdh_expression {
        // curNode->parent->value = curNode->value; 
        backToParent();
    } pm_expression {
        // 3 pos code.
    }
    | MINUS { 
        // curNode->parent->value = curNode->value;
        extendOptTree("-", _MINUS);
    } mtdh_expression {
        backToParent();
    } pm_expression {
        // 3 pos code.
    }
    | PLUS { 
        extendOptTree("+", _ADD);
    } error {
        yyerror("invalid syntax after +");
        extendTerminal("error", "invalid syntax after +", _ERROR);
        backToParent();
    }
    | MINUS { 
        extendOptTree("-", _MINUS);
    } error {
        yyerror("invalid syntax after -");
        extendTerminal("error", "invalid syntax after -", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

/* pm_opt
    : PLUS {
        extendOptTree("+");
    }
    | MINUS {
        extendOptTree("-");
    }
    ; */

mtdh_expression
    : powh_expression mtd_expression {
        // 3 pos code.
    }
    ;

mtd_expression
    : mtd_opt powh_expression {
        backToParent();
    } mtd_expression {
        
        // 3 pos code.
    }
    | mtd_opt error {
        char str[64];
        sprintf(str, "invalid syntax after %s", $1);
        yyerror(str);
        extendTerminal("error", str, _ERROR);
        backToParent();
    }
    |
    ;

mtd_opt
    : MOD { 
        extendOptTree("%", _MOD);
        strcpy($$, "%");
    }
    | TIMES { 
        extendOptTree("*", _TIMES);
        strcpy($$, "*");
    }
    | DIVIDE { 
        extendOptTree("/", _DIVIDE);
        strcpy($$, "/");
    } 
    ;

powh_expression
    : noth_expression pow_expression {
        // 3 pos code.
    }
    /*| noth_expression 
     error {
        yyerror("Wrong pow expression.");
    } */
    ;

pow_expression
    : POW { 
        extendOptTree("^", _POW);
    } noth_expression {
        backToParent();
    } pow_expression {
        // 3 pos code.
    }
    | POW error {
        extendOptTree("^", _POW);
        yyerror("invalid syntax after ^");
        extendTerminal("error", "invalid syntax after ^", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

noth_expression
    : {
        // saveNode();
    } not_expression pid_expression {
        // loadNode();
        /*
        if (curNode->parent->child[0]->isNotEmpty) {
            makeNewTemp(instruction, generateIndirectTriple("!", curNode->parent->child[1]->value, "_"));
        }
        else {
            sprintf(curNode->parent->value, "%s", curNode->parent->child[0]->value);
        }
        */
        // curNode->trueList = curNode->child[1]->falseList;
        // curNode->falseList = curNode->child[1]->trueList;
        // sprintf(curNode->value, "%s", curNode->child[0]->value);
    }
    ;

not_expression
    : NOT { 
        extendTree(NON_TERMINAL, "!", "expression", _NOT);
        /*
        sprintf(curNode->operators, "!");
        */
    } not_expression {
        /*
        sprintf(curNode->parent->value, "%s", curNode->value);
        */
        backToParent();
        // curNode->isNotEmpty = 1 - curNode->child[0]->isNotEmpty;
    }
    | NOT error {
        extendTree(NON_TERMINAL, "!", "expression", _NOT);
        yyerror("invalid syntax after !");
        extendTerminal("error", "invalid syntax after !", _ERROR);
        backToParent();
    }
    | /* epsilon */
    ;

pid_expression
    : LP { 
        extendTree(NON_TERMINAL, "()", "expression", _LPRP);
    } expression RP {
        /*
        curNode->type = curNode->child[0]->type;
        sprintf(curNode->value, "%s", curNode->child[0]->value);
        */
        // curNode->parent->type = curNode->type;
        // sprintf(curNode->parent->value, "%s", curNode->value);
        backToParent();
        // tempPointer = curNode;
    }
    | decorated_identifier {
        /*
        curNode->type = curNode->child[0]->type;
        sprintf(curNode->value, "%s", curNode->child[0]->value);
        */
    } // pointer_expression
      /* Not write value here current, later fill it. */
    | CONSTANT { 
        extendTree(TERMINAL, $<str>1, "const", _CONST);
        /*
        tempPointer->type = 1;
        sprintf(tempPointer->value, "%s", $<str>1);
        // print(reduce(lambda x, y : x + [[z for z in range(y)]], [1,2,3,4], []))
        */
    }
    | LP {
        extendTree(NON_TERMINAL, "()", "expression", _LPRP);
    } error {
        yyerror("Wrong expression in ().");
        extendTerminal("error", "() expression error");
        backToParent();
    }
    ;

/*
pointer_expression
    : POINTER IDENTIFIER high_ay_decorator {
        extendOptTree("->");
        extendTerminal("IDENTIFIER", $<str>2);
        backToParent();
    } pointer_expression 
    |
    ;
*/

type_defination
    : INT { 
        setCurrentType(1);
        extendTerminal("int", "type", _INT);
    } 
    | VOID { 
        setCurrentType(0);
        extendTerminal("void", "type", _VOID);
    } 

doh_expression
    : DO {
	    /* establish local scope */ ;
	    saveNode();
	    extendTree(NON_TERMINAL, "", "do while loop", _DO_WHILE);
	    extendTree(NON_TERMINAL, "do", "loop body", _DO);
	    pushScope(1);
    } statement_block
    ;

do_expression
    : doh_expression WHILE { 
	    popScope();
	    backToParent();
	    extendTree(NON_TERMINAL, "while", "loop condition", _WHILE_CONDITION);
    } LP {
	    extendTree(NON_TERMINAL, "()", "expression", _LPRP);
    } expression RP {
	    loadNode();
    } SEMICOLON
    | doh_expression WHILE {
        popScope();
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition", _WHILE_CONDITION);
    } error {
        yyerror("Wrong while condition in do while loop.");
        extendTerminal("error", "do while error", _ERROR);
        backToParent();
    }
    ;

while_expression
    : WHILE {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop", _WHILE);
    } LP { 
        extendTree(NON_TERMINAL, "()", "expression", _LPRP); 
    } expression RP { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body", _LOOP);
        pushScope(1);
    } statement_block {
        loadNode();
        popScope();
    }
    | WHILE {
        extendTree(NON_TERMINAL, "while", "while loop", _WHILE);
    } error {
        yyerror("Wrong while expression.");
        extendTerminal("error", "while loop error", _ERROR);
        backToParent();
    }
    ;

for_init_expression
    : {
        extendTree(NON_TERMINAL, "", "declaration", _DECLARATION);
    } type_defination {
        extendTree(NON_TERMINAL, "", "declaration body", _DECLARATION_BODY);
        saveNode();
    } argument_declaration_list {
        extendTree(NON_TERMINAL, "", "argument declaration list", _ARGUMENT_DECLARATION_LIST);
        broToParent(-1);
        backToParent();
        backToParent();
        backToParent();
        //connectParentChild();
    }
    | expression
    /* | error {
        yyerror("Wrong for init expression.");
        extendTerminal("error", "for init expression error");
    } */
    | 
    ;

for_condition_expression
    : expression
    /* | error {
        yyerror("Wrong for condition expression.");
        extendTerminal("error", "for condition expression error");
    } */
    | 
    ;

for_action_expression
    : expression
    /* | error {
        yyerror("Wrong for action expression.");
        extendTerminal("error", "for action expression error");
    } */
    | 
    ;

for_expression
    : FOR { 
        // establish local scope ;
        //saveNode();
        extendTree(NON_TERMINAL, "for", "for loop", _FOR);
        pushScope(1);
    } LP {  
        extendTree(NON_TERMINAL, "()", "for expression", _FOR_EXPRESSION);
        extendTree(NON_TERMINAL, "", "for init expression", _FOR_INIT);
    } for_init_expression SEMICOLON {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition", _FOR_CONDITION);
    } for_condition_expression SEMICOLON {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action", _FOR_ACTION);
    } for_action_expression RP {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body", _LOOP);
    } for_child_statement {
        backToParent();
        backToParent();
        popScope();
    }
    | FOR {
        // establish local scope ;
        //saveNode();
        extendTree(NON_TERMINAL, "for", "for loop", _FOR);
        pushScope(1);
    } error {
        yyerror("Wrong for expression for lack of (.");
        extendTerminal("error", "for expression error");
        backToParent();
    }
    ;

for_child_statement
    : statement_block
    | dependent_statement
    ;

array_decorator
    : LSB { 
        extendOptTree("[]", _SLPRP); 
    } expression RSB {
        backToParent();
    }
    ;

high_ay_decorator
    : array_decorator high_ay_decorator
    | /* epsilon */
    ;

high_nter_decorator
    : TIMES {
        extendTree(NON_TERMINAL, "*", "pointer", _POINTER);
    } high_nter_decorator
    | TIMES error {
        extendTree(NON_TERMINAL, "*", "pointer", _POINTER);
        extendTree(NON_TERMINAL, "error", "pointer error", _ERROR);
        yyerror("invalid syntax after pointer *");
    }
    | /* epsilon */
    ;

address_decorator
    : ADDRESS {
        extendTree(NON_TERMINAL, "&", "address", _ADDRESS);
    }
    | /* epsilon */
    ;

decorated_identifier
    : {
        saveNode();
    } address_decorator high_nter_decorator IDENTIFIER {
        useId($<str>4);
        extendTerminal($<str>4, "identifier", _ID);
        // sprintf(curNode->parent->value, "%s", $<str>3);
    } high_ay_decorator {
        loadNode();
        curNode->parent->type = currentType;
    }
    ;

statement
    : dependent_statement
    | { 
        pushScope(1); 
    } statement_block {
        popScope();
    }
    | error SEMICOLON {
        extendTerminal("error", "statement error", _ERROR);
        yyerror("invalid statement");
    }
    | error RBP {
        extendTerminal("error", "statement error", _ERROR);
        yyerror("invalid statement");
    }
    ;

dependent_statement
    : expression SEMICOLON
    | for_expression
    | do_expression
    | while_expression
    | condition_expression
    | declaration
    | BREAK {
        extendTerminal("break", "break", _BREAK);
    } SEMICOLON
    | CONTINUE {
        extendTerminal("continue", "continue", _CONTINUE);
    } SEMICOLON
    | RETURN {
        extendTree(NON_TERMINAL, "return", "return", _RETURN);
    } expression SEMICOLON {
        backToParent();
    }
    | SEMICOLON
    | PRINT {
        extendTree(NON_TERMINAL, "print", "print", _PRINT);
    } LP {
        extendTree(NON_TERMINAL, "", "print_content", _PRINT_CONTENT);
    } print_content RP {
        backToParent();
        backToParent();
    } SEMICOLON
    | INPUT {
        extendTree(NON_TERMINAL, "input", "input", _INPUT);
    } LP decorated_identifier RP {
        backToParent();
    } SEMICOLON
    | PRINT {
        extendTree(NON_TERMINAL, "print", "print", _INPUT);
    } error {
        yyerror("Wrong print expression.");
        extendTerminal("error", "print error", _ERROR);
        backToParent();
    } RP SEMICOLON
    | INPUT {
        extendTree(NON_TERMINAL, "input", "input", _INPUT);
    } error {
        yyerror("Wrong input expression.");
        extendTerminal("error", "input error", _ERROR);
    } RP {
        backToParent();
    } SEMICOLON
    ;

print_content
    : expression
    | STRING_C {
        extendTerminal($<str>1, "string", _STRING);
    }
    ;

statement_block
    : LBP {
        extendTree(NON_TERMINAL, "{}", "statement body", _STMT_BODY);
    } statement_body RBP {
        backToParent();
    }
    ;

main_args
    : VOID
    |
    ;

action_defination
    : {
        extendTree(NON_TERMINAL, "", "declaration", _DECLARATION);
    } type_defination
    ;

entry
    : public_statement entry
    | action_defination MAIN {
        /*
        curNode->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
        curNode->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "-1"));
        char end[64];
        sprintf(end, "%d", curNode->end+1);
        rewriteTemp(instruction, curNode->begin, 2, end);
        */
    } LP main_args RP {
        extendTree(NON_TERMINAL, "main", "main function", _MAIN);
    } statement_block {
        /* 
        char end[64];
        sprintf(end, "%d", curNode->parent->end);
        curNode->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", end));
         */
        // sprintf(end, "%d", curNode->parent->end);
        // sprintf(end, "%d", curNode->end);
        // rewriteTemp(instruction, curNode->end, 2, end);
        // rewriteTemp(instruction, curNode->end, 2, end);
        backToParent();
    }
    ;

public_statement
    : declaration
    | expression SEMICOLON
    | SEMICOLON
    ;

statement_body
    : {
        
    } statement statement_body
    |
    ;

declaration
    : action_defination {
        extendTree(NON_TERMINAL, "", "declaration body", _DECLARATION_BODY);
        saveNode();
    } declaration_body {
        backToParent();
        backToParent();
    }
    ;

declaration_body
    : argument_declaration_list {
        extendTree(NON_TERMINAL, "", "argument declaration list", _ARGUMENT_DECLARATION_LIST);
        broToParent(-1);
        backToParent();
        //connectParentChild();
    } SEMICOLON
    /* | function_declaration {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        backToParent();
        //connectParentChild();
    } */
    ;

/*
function_declaration
    : init_identifier LP {
        extendTree(NON_TERMINAL, "()", "function argument list");
        pushScope(1);
    } function_argument_list RP {
        backToParent();
        // establish local scope
    } function_defination {
        popScope();
    }
    ;

function_defination
    : {
        extendTree(NON_TERMINAL, "", "function defination");
    } statement_block {
        backToParent();
    }
    | SEMICOLON
    ;

*/

argument_declaration_list
    : argument_declaration_unit argument_declaration_list_tail
    ;

argument_declaration_list_tail
    : COMMA argument_declaration_list
    | COMMA error {
        yyerror("Wrong declaration list.");
        extendTerminal("error", "argument declaration unit error", _ERROR);
    }
    | /* epsilon */
    ;

argument_declaration_unit
    : init_identifier {
        extendTree(NON_TERMINAL, "", "argument declaration unit", _ARGUMENT_DECLARATION_UNIT);
        broToParent(1);
    } argument_declaration_init {
        backToParent();
    }
    ; 

argument_declaration_init
    : ASSIGN {
        extendOptTree("=", _ASSIGN);
    } single_expression {
        backToParent();
    }
    | /* epsilon */
    | ASSIGN {
        extendOptTree("=", _ASSIGN);
    } error {
        yyerror("Wrong init expression while argument declaration.");
        extendTerminal("error", "init expression error", _ERROR);
        backToParent();
    }
    ;

init_identifier
    : high_nter_decorator IDENTIFIER {
        declarationId($<str>2);
        extendTerminal($<str>2, "identifier", _ID);
    } high_ay_decorator {
        loadNode();
    }
    ;

/*
function_argument
    : {
        extendTree(NON_TERMINAL, "", "function argument unit");
        saveNode();
    } type_defination init_identifier argument_declaration_init {
        backToParent();
    }
    ;

function_argument_list
    : function_argument function_argument_tail
    | 
    ;

function_argument_tail
    : COMMA function_argument_list
    | 
    ;

*/

condition_expression
    : IF { 
        extendTree(NON_TERMINAL, "if", "if expression", _IF);
    } LP {
        extendTree(NON_TERMINAL, "()", "if condition", _IF_CONDITION);
    } expression RP {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement", _IF_STMT);
        pushScope(1);
    } statement {
        backToParent();
        popScope();
    } condition_tail {
        backToParent();
    }
    | IF {
        extendTree(NON_TERMINAL, "if", "if expression", _IF);
    } error {
        yyerror("Wrong if expression for lack of (.");
        extendTerminal("error", "if expression error", _ERROR);
        backToParent();
    }
    ;

condition_tail
    : ELSE {
        extendTree(NON_TERMINAL, "else", "else statement", _ELSE);
        pushScope(1); 
    } statement {
        popScope();
        backToParent();
    }
    | {} %prec NONE_ELSE
    ;

%%


   
void extendTree(int isTerminal, const char* word, const char* grammer, int op) {
    tempPointer = createGrammerNode(isTerminal, word, grammer);
    tempPointer->opt = opt;
    push_child(curNode, tempPointer); 
    if (isTerminal == NON_TERMINAL) curNode = tempPointer;
}

void backToParent() {
    if (curNode->parent == NULL) return;
    curNode = curNode->parent;
}

void saveNode() {
    stack[stackContentSize++] = curNode;
}

void loadNode() {
    if (stackContentSize <= 0) return;
    curNode = stack[--stackContentSize];
}

void extendOptTree(const char* opt, int op) {
    extendTree(NON_TERMINAL, opt, "expression", op);
    sprintf(curNode->value, "%s", opt);
    sprintf(curNode->operators, "%s", opt);
    adjustOptNode(curNode);
}

void extendTerminal(const char* word, const char* grammer, int op) {
    extendTree(TERMINAL, word, grammer, op);
}

void broToParent(int num) {
    grammerTree* parent = curNode->parent;
    int selfPos;
    int i;
    selfPos = findSelfPos(curNode);
    if (num == -1) i = 0;
    else i =  selfPos - num;
    /* printGrammerNode(parent);
    printGrammerNode(curNode); */
    for (int n = i; n < selfPos; n++) {
        /* printGrammerNode(parent->child[n]); */
        push_child(curNode, parent->child[n]);
    }
    parent->child[i++] = curNode;
    parent->size = i;
}

void connectParentChild() {
    grammerTree* parent = curNode->parent;
    grammerTree** child = curNode->child;
    for (int i = 0; i < curNode->size; i++) {
        push_child(parent, child[i]);
    }
    freeGrammerNode(curNode);
    curNode = parent;
}

void useId(const char* name) {
    char* attribute = (char*)malloc(sizeof(char)*64);
	if (searchWordGlobal(name)) {
		struct Word* word = getWordInfo(name);
		sprintf(attribute, "0x%x", word->symbolPosition);
		free(word);
	}
	else {
		printf("not defined.\n");
		sprintf(attribute, "undefined");
	}
	appendLexOutputIDFile("IDENTIFIER", name, attribute);
	free(attribute);
}

void declarationId(const char* name) {
    char* attribute = (char*)malloc(sizeof(char)*64);
	if (searchWord(name)) {
		//printf("Exist at line %d.\n", yylineno);
		printf("mutidefined.\n");
		sprintf(attribute, "mutidefined");
	}
	else {
		unsigned int position = addWord(name);
		sprintf(attribute, "0x%x", position);
	}
	appendLexOutputIDFile("IDENTIFIER", name, attribute);
	free(attribute);
}

void appendLexOutputIDFile(const char* type, const char* name, const char* attribute) {
	char* result = (char*)malloc(sizeof(char)*64);
	sprintf(result, "%-15s%-15s%-15s\n", type, name, attribute);
	appendLEX(result);
	// printf("%s", result);
	free(result);
}

int main(int arg, char* argv[]) {
    if (2 > arg) {
        exit(-1);
    }
    yyin = fopen(argv[1], "r");

    instruction = generateInstruction();

    root = createGrammerNode(NON_TERMINAL, "", "start");
    curNode = root;
    tempPointer = NULL;

    generateLEX();
    appendLEX("Type           Name           Attribute \n");
    generateCODE();

    launchTable();
    
    int err = yyparse();

    closeCODE();
    closeLEX();

    generateYACC();
    printGrammerTree(root);
    closeYACC();

    stopTable();

    freeGrammerTree(root);

    destroyInstruction(instruction);

    fclose(yyin);

    printf("%d\n", err);
    return 0; 
}   

void yyerror(const char* charactor) {
    char str[256];
    sprintf(str, "error in line %d: %s\n", yylineno, charactor);
    appendREPORT(str);
    //yyclearin;
    //yyparse();
}
