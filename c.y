%{
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "table.h"
#include "grammerTree.h"
#include "indirectTriple.h"
#include "pointer.h"
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

        _START=65500,

        _MAIN=65532,
        _ID=65533,
        _STRING=65534,
        _CONST=65535,
    } op;
    int indirectTripleCodeGenerator(GrammarTree root, struct Instruction* instruction);
    extern FILE* yyin;
    void yyerror(const char *s);
    extern int yylex(void);
    extern char* name;
    extern int yylineno;

#ifdef __cplusplus
};
#endif

char text[1024];
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
int starNum;
PtrInfo* currentArg = NULL;

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

/* noth_expression
    : {
        // saveNode();
    } not_expression pid_expression {
        // loadNode();
        // curNode->trueList = curNode->child[1]->falseList;
        // curNode->falseList = curNode->child[1]->trueList;
        // sprintf(curNode->value, "%s", curNode->child[0]->value);
    }
    ;

not_expression
    : NOT { 
        extendTree(NON_TERMINAL, "!", "expression", _NOT);

    } not_expression {

        backToParent();
        // curNode->isNotEmpty = 1 - curNode->child[0]->isNotEmpty;
    }
    | NOT error {
        extendTree(NON_TERMINAL, "!", "expression", _NOT);
        yyerror("invalid syntax after !");
        extendTerminal("error", "invalid syntax after !", _ERROR);
        backToParent();
    }
    | 
    ; */

noth_expression
    : {
        saveNode();
    } not_expression pid_expression {
        loadNode();
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
        // backToParent();
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
        extendTerminal("error", "() expression error", _ERROR);
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
    } single_expression RP {
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
    } single_expression RP { 
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
        extendTerminal("error", "for expression error", _ERROR);
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
    } single_expression RSB {
        backToParent();
        if (isInited == 0) {
            // initialize
            starNum++;
        }
    }
    ;

high_ay_decorator
    : array_decorator high_ay_decorator
    | /* epsilon */
    ;

high_nter_decorator
    : TIMES {
        extendTree(NON_TERMINAL, "*", "pointer", _POINTER);
        if (isInited == 0) {
            // initialize
            starNum++;
        }
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
    } LP init_identifier /* decorated_identifier */ RP {
        backToParent();
    } SEMICOLON
    | PRINT {
        extendTree(NON_TERMINAL, "print", "print", _PRINT);
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
        currentType = 1;
        starNum = 0;
        isInited = 0;
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

init_high_ay_decorator
    : init_array_decorator init_high_ay_decorator
    | /* epsilon */
    ;

init_array_decorator
    : LSB { 
        extendOptTree("[]", _SLPRP); 
    } CONSTANT {
        extendTerminal($<str>3, "const", _CONST);
        //printf("%s\n", $<str>1);
        //printf("%s\n", $3);
        //printf("%s\n", $<str>4);
        backToParent();
        setArrayWidth(currentArg, atoi($<str>3));
    } RSB 
    ;

init_identifier
    : high_nter_decorator IDENTIFIER {
        currentArg = createPtrInfo();
        sprintf(text, "%s", $<str>2);
        extendTerminal(text, "identifier", _ID);
	    // printf("HELP! The shit $ 2 is |%s|.\n", $<str>2);    
        // extendTerminal($<str>2, "identifier", _ID);
    } init_high_ay_decorator {
        loadNode();
        printf("ready to set: %d\n", starNum);
        for(int i = 0; i < starNum; i++){
            setArrayWidth(currentArg, -1);
        }
        printf("set over\n");
        starNum = 0;
	    // printf("HELP! The shit $ 2 is |%s| again.\n", $<str>2); 
        // declarationId($<str>2);
        declarationId(text);
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
    } single_expression RP {
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
    printf("HELP! Extend Tree %d %s %s %d\n", isTerminal, word, grammer, op);
    tempPointer = createGrammerNode(isTerminal, word, grammer);
    tempPointer->opt = op;
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
    /* grammerTree** child = curNode->child;
    for (int i = 0; i < curNode->size; i++) {
        push_child(parent, child[i]);
    } */
    /* grammerTree** child = (grammerTree**)malloc(sizeof(grammerTree*)); */
    int cursor = 0;
    for (; cursor < curNode->size; cursor++) {
        push_child(parent, getChildInGrammarTree(curNode, cursor));
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
    int store;
    char* attribute = (char*)malloc(sizeof(char)*64);
	if (searchWord(name)) {
		//printf("Exist at line %d.\n", yylineno);
		printf("mutidefined.\n");
		sprintf(attribute, "mutidefined");
	}
	else {
		unsigned int position = addWord(name);
        printf("%d\n", currentArg -> dimension);
        if (currentArg -> dimension > 0) {
            setType(name, 5);
            store = calculateStore(currentArg);
            setStore(name, store, NULL);
            printf("%d\n", store);
            registPtr(position, currentArg);
        }
        else {
            free(currentArg);
            currentArg = NULL;
            setStore(name, 4, NULL);
        }
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
    
    printf("root.\n");

    root = createGrammerNode(NON_TERMINAL, "", "start");
    root->opt = _START;
    curNode = root;
    tempPointer = NULL;

    printf("Before lex.\n");

    generateLEX();
    appendLEX("Type           Name           Attribute \n");
    generateCODE();

    printf("Before table.\n");

    launchTable();

    printf("After launch.\n");
        
    int err = yyparse();
    closeLEX();

    printf("Before yacc.\n");

    generateYACC();
    printGrammerTree(root);
    closeYACC();

    printf("Before restart table.\n");

    restartTable();

    printf("Before instruction.\n");

    instruction = generateInstruction();

    indirectTripleCodeGenerator(root, instruction);

    stopTable();

    printf("Before write code file.\n");

    destroyInstruction(instruction);

    freeGrammerTree(root);

    closeCODE();

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

int indirectTripleCodeGenerator(GrammarTree node, struct Instruction* instruction) {
    printf("HELP! Trap into node %s as %d.\n", node->word, node->opt);
    if (NULL == node) {
        return -65536;
    }
    if (NULL == instruction) {
        return -65535;
    }
    char go[64];

    int trueList;
    int falseList;

    int leftTrue;
    int rightTrue;
    int leftFalse;
    int rightFalse;
    int jump;
    int assign;

    int temp;

    struct Word* word = NULL;

    GrammarTree parent;
    GrammarTree child;

    int cursor = 0;
    switch (node->opt) {
        case _ERROR:
            printf("Error for %s.\n", node->word);
            exit(-1);
        case _VOID:
            node->type = 0;
            break;
        case _INT:
            node->type = 1;
            break;
        case _FOR:
            pushScope(0);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            indirectTripleCodeGenerator(node->child[0], instruction);
//            if (-1 != node->child[0]->begin) {
//                sprintf(go, "%d", node->child[0]->begin);
//                rewriteTemp(instruction, node->begin, 2, go);
//                if (-1 != node->child[0]->head) {
//                    node->head = node->child[0]->head;
//                }
//            }
            // These value must include in action at least.
            sprintf(go, "%d", node->child[0]->begin);
            rewriteTemp(instruction, node->begin, 2, go);
            node->head = node->child[0]->head;

            indirectTripleCodeGenerator(node->child[1], instruction);

            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, node->child[0]->child[2]->begin, 2, go);

            sprintf(go, "%d", node->child[0]->child[2]->begin);
            rewriteTemp(instruction, node->child[1]->end, 2, go);

            sprintf(go, "%d", node->head);
            rewriteTemp(instruction, node->child[0]->child[2]->end, 2, go);
            // Rewrite stmt head.
            // Rewrite stmt tail.
            // Rewrite action head.
            // End.
            jump = makeNewTemp(instruction, generateIndirectTriple("!", node->value, "_"));
            sprintf(go, "%d", jump);
            rewriteTemp(instruction, node->end, 2, go);
            popScope();

//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            if (-1 != node->child[1]->begin) {
//                sprintf(go, "%d", node->child[1]->begin);
//                rewriteTemp(instruction, node->begin, 2, go);
//            }
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            if (-1 == node->begin) {
//                node->begin = node->child[0]->begin;
//            }
//            trueList = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                       node->child[0]->value, "_"));
//            sprintf(go, "%d", node->end);
//            falseList = makeNewTemp(instruction, generateIndirectTriple("j", "_",
//                                                                        go));
//            if (-1 != node->child[0]->begin) {
//                node->head = node->child[0]->begin;
//            }
//            else {
//                node->head = trueList;
//            }
            break;
        case _FOR_INIT:
            if (0 == node->size) {
                break;
            }
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _FOR_CONDITION:
            if (0 == node->size) {
                break;
            }
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            node->type = node->child[0]->type;
            sprintf(node->value, "%s", node->child[0]->value);
            break;
        case _FOR_ACTION:
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            if (0 != node->size) {
                indirectTripleCodeGenerator(node->child[0], instruction);
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            break;
        case _FOR_EXPRESSION:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->head = node->child[1]->begin;
            indirectTripleCodeGenerator(node->child[2], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[2]->begin;
            }
            if (-1 == node->head) {
                node->head = node->child[2]->begin;
            }
            break;
        case _WHILE_CONDITION:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->type = node->child[0]->type;
            sprintf(node->value, "%s", node->child[0]->value);
            node->begin = node->child[0]->begin;
            trueList = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                       node->value, "_"));
            if (-1 == node->begin) {
                node->begin = trueList;
            }
            node->head = trueList;
            node->end = makeNewTemp(instruction, generateIndirectTriple("!",
                                                                        node->value, "_"));
            break;
        case _DO_WHILE:
            pushScope(0);
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->begin = node->child[0]->begin;
            node->head = node->child[0]->head;
            sprintf(go, "%d", node->begin);
            rewriteTemp(instruction, node->child[1]->head, 2, go);
            popScope();
            break;
        case _DO:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _WHILE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            trueList = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                       node->child[0]->value, "_"));
            falseList = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));

            pushScope(0);
            indirectTripleCodeGenerator(node->child[1], instruction);
            popScope();

            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, trueList, 2, go);

            sprintf(go, "%d", node->begin);
            makeNewTemp(instruction, generateIndirectTriple("j", "_",
                                                            go));

            node->end = makeNewTemp(instruction, generateIndirectTriple("!", "1", "_"));
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, falseList, 2, go);
            break;
        case _CONTINUE:
            parent = node->parent;
            while (NULL != parent) {
                if (_FOR != parent->opt) {

                }
                else if (_DO_WHILE != node->opt) {

                } else if (_WHILE != node->opt) {

                }
                else {
                    break;
                }
                parent = parent->parent;
            }
            sprintf(go, "%d", parent->head);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_",
                                                                          go));
            node->end = node->begin;
            break;
        case _BREAK:
            parent = node->parent;
            while (NULL != parent) {
                if (_FOR != parent->opt) {

                }
                else if (_DO_WHILE != node->opt) {

                } else if (_WHILE != node->opt) {

                }
                else {
                    break;
                }
                parent = parent->parent;
            }
            sprintf(go, "%d", parent->end);
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_",
                                                                          go));
            node->end = node->begin;
            break;
        case _IF:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            trueList = makeNewTemp(instruction, generateIndirectTriple("j", node->child[0]->value, "_"));
            falseList = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, trueList, 2, go);

            if (3 == node->size) {
                // ELSE;
                indirectTripleCodeGenerator(node->child[2], instruction);
                sprintf(go, "%d", node->child[2]->begin);
                rewriteTemp(instruction, falseList, 2, go);
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("!", node->value, "_"));
            if (2 == node->size) {
                sprintf(go, "%d", node->end);
                rewriteTemp(instruction, falseList, 2, go);
            }
            break;
        case _ELSE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _IF_STMT:
            pushScope(0);
            if (node->size && -1 != node->child[0]->begin) {
                indirectTripleCodeGenerator(node->child[0], instruction);
                node->begin = node->child[0]->begin;
                node->end = node->child[0]->end;
            }
            else {
                node->begin = makeNewTemp(instruction, generateIndirectTriple("!", "1", "_"));
                node->end = node->begin;
            }
            popScope();
            break;
        case _IF_CONDITION:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            sprintf(node->value, "%s", node->child[0]->value);
            node->end = node->child[0]->end;
            break;
        case _RETURN:
            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "-1"));
            node->end = node->begin;
            break;
        case _ADDRESS: // ==============================================================================================
            // &
            // 取址
            indirectTripleCodeGenerator(node->child[0], instruction);
            
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("&",
                                                           node->child[0]->value,
                                                           "_"));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _LPRP:
            // ()
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            if (-1 == node->child[0]->begin) {
                node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
                sprintf(go, "@%d", node->begin);
                rewriteTemp(instruction, node->begin, 1, go);
                node->end = node->begin;
            }
            sprintf(node->value, "%s", node->child[0]->value);
            break;
        case _SLPRP: // ================================================================================================
            // []
            // 格式不知是否正确
            parent = node->parent;
            if (parent != NULL && parent->child[0] == node) {
                parent = parent->parent;
                if (parent != NULL && parent->parent->opt == _ARGUMENT_DECLARATION_UNIT) {
                    break;
                }
            }
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            // begin 是左子节点的[]或变量，end是地址计算
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            if (node->child[0]->type < 1){
                // 出错
                exit(1);
            }
            else if (node->child[0]->type > 2){
                node->ptrType = findLowerPtr(node->child[0]->ptrType);
                // 偏移量的计算是动态的，需生成乘法三元式和地址偏移计算的三元式
                sprintf(node->value, "%d", calculateStore(node->ptrType));
                // 借用下。。。
                temp = makeNewTemp(instruction, generateIndirectTriple("*",
                                                                       node->value,
                                                                       node->child[1]->value)); 
                sprintf(go, "#%d", temp);              
                }
            else {
                temp = makeNewTemp(instruction, generateIndirectTriple("*",
                                                                       node->child[1]->value,
                                                                       "4"));  
                sprintf(go, "#%d", temp);              
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("offset",
                                                                   node->child[0]->value,
                                                                   go));
            sprintf(node->value, "#%d", node->end);
            node->type = node->child[0]->type - 1;
            if (node->type == 1) {
                // 如果type现在为int，寻址，end为寻址
                node->end = makeNewTemp(instruction, generateIndirectTriple("find",
                                                                            node->value,
                                                                            "_"));
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _LOOP:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->head = node->child[0]->head;
            node->end = node->child[0]->end;
            break;
        case _POINTER: // ==============================================================================================
            parent = node->parent;
            child = node->child[0];
            // declaration 不会深入左值，此处暂只考虑寻址操作
            // while (parent != NULL && parent->opt != _ARGUMENT_DECLARATION_UNIT){
            //     parent = parent->parent;
            // }
            //begin 为子节点begin
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->type = node->child[0]->type - 1;
            node->begin = node->child[0]->begin;
            if (node->type == 1) {
                // 如果type现在为int，寻址，end为寻址
                node->end = makeNewTemp(instruction, generateIndirectTriple("find",
                                                                            node->child[0]->value,
                                                                            "_"));
            }
            else if (node->type < 1) {
                // 错误
                exit(1);
            }
            else {
                // 如果对数组类型寻址， 地址不变，只有级数减一,begin end同子节点
                if (getArrayWidth(child->ptrType, 0) > 0) {
                    // 数组
                    strcpy(node->value, child->value);
                    node->begin = child->begin;
                    node->end = child->end;
                    node->ptrType = findLowerPtr(child->ptrType);
                    break;
                }
                // 如果对指针类型寻址， 直接获取指向的值（值为地址），级数减一
                else if (getArrayWidth(child->ptrType, 0) == -1) {
                    // 指针
                    node->end = makeNewTemp(instruction, generateIndirectTriple("find",
                                                                                node->child[0]->value,
                                                                                "_"));
                    node->ptrType = findLowerPtr(child->ptrType);
                }
            }
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _ASSIGN:
            node->type = 12;
            temp = node->child[0]->opt;
            if (_ID != temp && 2 != node->type && 5 != temp) { // 2 is array, and 5 is pointer.
                printf("Wrong assign for not id at left.\n");
                exit(-2);
            }
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (0 > getWordInfo(node->child[0]->word)->store) {
                printf("Using not inited value.\n");
                exit(-3);
            }
            node->begin = node->child[1]->begin;
            indirectTripleCodeGenerator(node->child[0], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[0]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _DECLARATION: // ==========================================================================================
            indirectTripleCodeGenerator(node->child[0], instruction);
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->begin = node->child[0]->begin;
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = node->child[1]->end;
            break;
        case _ARGUMENT_DECLARATION_LIST: // ============================================================================
            for (cursor = 0; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }
            node->begin = node->child[0]->begin;
            node->end = node->child[node->size - 1]->end;
            break;
        case _DECLARATION_BODY: // =====================================================================================
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _ARGUMENT_DECLARATION_UNIT: // ============================================================================
            child = node->child[0];
            while(child->opt != _ID){
                    child = child->child[0];
            }
            indirectTripleCodeGenerator(child, instruction);
            node->begin = child->begin;
            // not sure if the format is correct
            sprintf(go, "%d", getWordInfo(child->word)->store);
            jump = makeNewTemp(instruction,
                               generateIndirectTriple("n",
                                                      child->value,
                                                      go));
            sprintf(go, "@%d", jump);
            sprintf(child->value, "%s", go);
            rewriteTemp(instruction, jump, 1, go);
            if (-1 == node->begin){
                node->begin = jump;
            }
            setStore(child->word, getWordInfo(child->word)->store, child->value);
            if (node->child[0]->opt == _ASSIGN) {
                indirectTripleCodeGenerator(node->child[1], instruction);
                node->end = node->child[1]->end;
            }
            else {
                node->end = node->begin;
            }
            break;
        case _EQUAL:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("==",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _NOTEQUAL:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("!=",
                                                                        node->child[0]->value,
                                                                        node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _GT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple(">",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _LT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple("<",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _GE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction, generateIndirectTriple(">=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _LE:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            indirectTripleCodeGenerator(node->child[1], instruction);
            node->end = makeNewTemp(instruction, generateIndirectTriple("<=",
                                                            node->child[0]->value,
                                                            node->child[1]->value));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            sprintf(node->value, "#%d", node->end);
            break;
        case _AND:
            node->type = 12;
            node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
            sprintf(go, "@%d", node->begin);
            rewriteTemp(instruction, node->begin, 1, go);
            sprintf(node->value, "#%d", node->begin);

            indirectTripleCodeGenerator(node->child[0], instruction);
            leftTrue = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[0]->value, "_"));
            leftFalse = makeNewTemp(instruction, generateIndirectTriple("j","_", "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            sprintf(go, "%d", node->child[1]->begin);
            rewriteTemp(instruction, leftTrue, 2, go);
            rightTrue = makeNewTemp(instruction, generateIndirectTriple("j", node->child[1]->value, "_"));
            rightFalse = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->trueList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                             node->value, "1"));
            sprintf(go, "%d", node->trueList);
            rewriteTemp(instruction, rightTrue, 2, go);
            jump = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->falseList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                              node->value, "0"));
            sprintf(go, "%d", node->falseList);
            rewriteTemp(instruction, leftFalse, 2, go);
            rewriteTemp(instruction, rightFalse, 2, go);
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->value, node->value));
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, jump, 2, go);
//            node->type = 12;
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            node->end = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                          node->child[0]->value, "_"));
//            makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            sprintf(go, "%d", node->child[1]->begin);
//            rewriteTemp(instruction, node->begin, 2, go);
//
//            rewriteTemp(instruction, node->child[0]->end, 2, "end");
//            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _OR:
            node->type = 12;
            node->begin = makeNewTemp(instruction, generateIndirectTriple("n", "_", "4"));
            sprintf(go, "@%d", node->begin);
            rewriteTemp(instruction, node->begin, 1, go);
            sprintf(node->value, "#%d", node->begin);
            indirectTripleCodeGenerator(node->child[0], instruction);
            leftTrue = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[0]->value, "_"));
            indirectTripleCodeGenerator(node->child[1], instruction);
            leftFalse = makeNewTemp(instruction, generateIndirectTriple("j",
                                                                        node->child[1]->value, "_"));
            rightFalse = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->trueList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                             node->value, "1"));
            sprintf(go, "%d", node->trueList);
            rewriteTemp(instruction, leftTrue, 2, go);
            rewriteTemp(instruction, leftFalse, 2, go);
            jump = makeNewTemp(instruction, generateIndirectTriple("j", "_", "_"));
            node->falseList = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                              node->value, "0"));
            sprintf(go, "%d", node->falseList);
            rewriteTemp(instruction, rightFalse, 2, go);
            node->end = makeNewTemp(instruction, generateIndirectTriple("=",
                                                                        node->value, node->value));
            sprintf(go, "%d", node->end);
            rewriteTemp(instruction, jump, 2, go);
//            node->type = 12;
//            indirectTripleCodeGenerator(node->child[0], instruction);
//            node->begin = makeNewTemp(instruction, generateIndirectTriple("j",
//                                                                          node->child[0]->value, "_"));
//            indirectTripleCodeGenerator(node->child[1], instruction);
//            sprintf(go, "%d", node->child[1]->begin);
//            rewriteTemp(instruction, node->child[0]->end, 2, go);
//            sprintf(go, "%d", 2);
//            rewriteTemp(instruction, node->child[0]->end, 2, "end");
//            rewriteTemp(instruction, node->child[1]->end, 2, "end");
            break;
        case _NOT:
            node->type = 12;
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction, generateIndirectTriple("!",
                                                            node->child[0]->value, "_"));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _ADD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("+",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _MINUS:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("-",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _TIMES:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("*",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _DIVIDE:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("/",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _MOD:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("%",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _POW:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            indirectTripleCodeGenerator(node->child[1], instruction);
            if (-1 == node->begin) {
                node->begin = node->child[1]->begin;
            }
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("^",
                                                           node->child[0]->value,
                                                           node->child[1]->value));
            sprintf(node->value, "#%d", node->end);
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _COMMA:
            indirectTripleCodeGenerator(node->child[1], instruction);
            break;
        case _STMT_BODY:
            for (cursor = 0; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }
            node->begin = node->child[0]->begin;
            node->end = node->child[cursor - 1]->end;
            break;
        case _INPUT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("in",
                                                           node->child[0]->value, "_"));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _PRINT_CONTENT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = makeNewTemp(instruction, generateIndirectTriple("out",
                                                            node->child[0]->value, "_"));
            if (-1 == node->begin) {
                node->begin = node->end;
            }
            break;
        case _PRINT:
            indirectTripleCodeGenerator(node->child[0], instruction);
            node->begin = node->child[0]->begin;
            node->end = node->child[0]->end;
            break;
        case _START:
            for (cursor = 0; cursor < node->size; cursor++) {
                indirectTripleCodeGenerator(node->child[cursor], instruction);
            }
            break;
        case _MAIN:
            node->begin = makeNewTemp(instruction,
                                      generateIndirectTriple("j", "_", "_"));
            node->end = makeNewTemp(instruction,
                                    generateIndirectTriple("j", "_", "-1"));
            // Before.
            indirectTripleCodeGenerator(node->child[0], instruction); // Go code blocks.
            // After.
            if (-1 != node->child[0]->begin) {
                sprintf(go, "%d", node->child[0]->begin);
                rewriteTemp(instruction, node->begin, 2, go);
            }
            sprintf(go, "%d", node->end);
            /* rewriteTemp(instruction, node->child[0]->end, 2, go); */
            makeNewTemp(instruction, generateIndirectTriple("j", "_", go));
            break;
        case _ID:
            // Searching in symbol table.
            printf("ready: ID\n");
            word = getWordInfo(node->word);
            if (NULL == word) {
                printf("Undefined.\n");
                exit(-3);
            }
            printf("got info\n");
            node->type = word->type;
            printf("Before positon is null.\n");
            if (NULL == word->position) {
                printf("Word pos is't null.\n");
                sprintf(node->value, "%s", word->position);
            }
            // by zhu: 添加指针，指向描述类型的数据
            printf("try get type\n");
            node->ptrType = getPtrInfo(word->symbolPosition);
            break;
        case _STRING:
            node->type = 65535;
            sprintf(node->value, "%s", node->word);
            break;
        case _CONST:
            node->type = 1;
            sprintf(node->value, "%s", node->word);
            break;
        default:
            return -2;
    }
    printf("HELP! Leave node %s as %d.\n", node->word, node->opt);
    return 0;
}
