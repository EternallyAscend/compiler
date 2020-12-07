%{
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "table.h"
#include "grammerTree.h"
#include "y.tab.h"

#ifdef __cplusplus
extern "C" 

{
#endif
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

void extendTree(int isTerminal, const char* word, const char* grammer);
void backToParent();
void extendOptTree(const char* opt);
void extendTerminal(const char* word, const char* grammer);
void broToParent(int num);
void connectParentChild();

void saveNode();
void loadNode();

void appendLexOutputIDFile(const char* type, const char* name, const char* attribute);
void declarationId(const char* name);
void useId(const char* name);

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


%nonassoc NONE_ELSE
%nonassoc ELSE

%start statement_body
%%


expression
    : single_expression comma_expression 
    ;

comma_expression
    : COMMA {
        extendOptTree(",");
    } single_expression {
        backToParent();
    } comma_expression 
    | /* epsilon */
    ;

single_expression
    : orh_expression assign_expression
    ;

assign_expression
    : ASSIGN { 
        extendOptTree("=");
    } orh_expression { 
        backToParent();
    } assign_expression
    | /* epsilon */
    ;

orh_expression
    : andh_expression or_expression
    ;

or_expression
    : OR { 
        extendOptTree("||");
    } andh_expression {
        backToParent();
    } or_expression
    | /* epsilon */
    ;

andh_expression
    : eneh_expression and_expression 
    ;

and_expression
    : AND {  
        extendOptTree("&&");
    } eneh_expression {
        backToParent();
    } and_expression
    | /* epsilon */
    ;

eneh_expression
    : lgh_expression ene_expression
    ;

ene_expression
    : EQ {  
        extendOptTree("==");
    } lgh_expression {
        backToParent();
    } //ene_expression
    | NE {  
        extendOptTree("!=");
    } lgh_expression {
        backToParent();
    } // ene_expression
    |
    ;

lgh_expression
    : pmh_expression lg_expression
    ;

lg_expression
    : GT {  
        extendOptTree(">");
    } pmh_expression {
        backToParent();
    } // lg_expression
    | GE {  
        extendOptTree(">=");
    } pmh_expression {
        backToParent();
    } // lg_expression
    | LT {  
        extendOptTree("<");
    } pmh_expression {
        backToParent();
    } // lg_expression
    | LE {  
        extendOptTree("<=");
    } pmh_expression {
        backToParent();
    } // lg_expression
    | /* epsilon */
    ;

pmh_expression
    : mtdh_expression pm_expression
    ;

pm_expression
    : PLUS { 
        extendOptTree("+");
    } mtdh_expression {
        backToParent();
    } pm_expression
    | MINUS { 
        extendOptTree("-");
    } mtdh_expression {
        backToParent();
    } pm_expression
    | /* epsilon */
    ;

mtdh_expression
    : powh_expression mtd_expression
    ;

mtd_expression
    : MOD { 
        extendOptTree("%");
    } powh_expression {
        backToParent();
    } mtd_expression
    | TIMES { 
        extendOptTree("*");
    } powh_expression {
        backToParent();
    } mtd_expression
    | DIVIDE { 
        extendOptTree("/");
    } powh_expression {
        backToParent();
    } mtd_expression
    | /* epsilon */
    ;

powh_expression
    : noth_expression pow_expression
    ;

pow_expression
    : POW { 
        extendOptTree("^");
    } noth_expression {
        backToParent();
    } pow_expression
    | /* epsilon */
    ;

noth_expression
    : {
        saveNode();
    } not_expression pid_expression {
        loadNode();
    }
    ;

not_expression
    : NOT { 
        extendTree(NON_TERMINAL, "!", "expression");
    } not_expression
    | /* epsilon */
    ;

pid_expression
    : LP { 
        extendTree(NON_TERMINAL, "()", "expression");
    } expression RP { 
        backToParent();
    }
    | decorated_identifier // pointer_expression
    | CONSTANT { 
        extendTree(TERMINAL, $<str>1, "const");
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
        extendTerminal("int", "type");
    } 
    | VOID { 
        extendTerminal("void", "type");
    } 
    /*
    | error {
        yyerror("invalid type declaration.");
    }
    */

/*
    | STRUCT {
        extendTree(NON_TERMINAL, "struct", "type");
    } IDENTIFIER {  
        extendTerminal($<str>3, "identifier");
        backToParent();
    }
*/
    ;

/*
do_expression
    : DO { 
        // establish local scope ;
        saveNode();
        extendTree(NON_TERMINAL, "", "do while loop");
        extendTree(NON_TERMINAL, "do", "loop body");
        pushScope(1);
    } statement_block WHILE {
        popScope();
        backToParent();
        extendTree(NON_TERMINAL, "while", "loop condition");
    } LP {  
        extendTree(NON_TERMINAL, "()", "expression");
    } expression RP { 
        loadNode();
    } SEMICOLON
    ;
*/

doh_expression
    : DO {
	/* establish local scope */ ;
	saveNode();
	extendTree(NON_TERMINAL, "", "do while loop");
	extendTree(NON_TERMINAL, "do", "loop body");
	pushScope(1);
    } statement_block
    ;

do_expression
    : doh_expression WHILE { 
	popScope();
	backToParent();
	extendTree(NON_TERMINAL, "while", "loop condition");
    } LP {
	extendTree(NON_TERMINAL, "()", "expression");
    } expression RP {
	loadNode();
    } SEMICOLON
    ;

while_expression
    : WHILE {  
        saveNode();
        extendTree(NON_TERMINAL, "while", "while loop");
    } LP { 
        extendTree(NON_TERMINAL, "()", "expression"); 
    } expression RP { 
        backToParent(); 
        /*establish local scope*/ ;
        extendTree(NON_TERMINAL, "", "loop body");
        pushScope(1);
    } statement_block {
        loadNode();
        popScope();
    }
    ;

for_init_expression
    : {
        extendTree(NON_TERMINAL, "", "declaration");
    } type_defination {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    } argument_declaration_list {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        backToParent();
        backToParent();
        backToParent();
        //connectParentChild();
    }
    | expression
    
    | error {
        yyerror("Wrong for init expression.");
    }
    
    | 
    ;

for_condition_expression
    : expression
    
    | error {
        yyerror("Wrong for condition expression.");
    }
    
    | 
    ;

for_action_expression
    : expression
    
    | error {
        yyerror("Wrong for action expression.");
    }
    
    | 
    ;

for_expression
    : FOR { 
        // establish local scope ;
        //saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
        pushScope(1);
    } LP {  
        extendTree(NON_TERMINAL, "()", "for expression");
        extendTree(NON_TERMINAL, "", "for init expression");
    } for_init_expression SEMICOLON {
        backToParent();
        extendTree(NON_TERMINAL, "", "for condition");
    } for_condition_expression SEMICOLON {
        backToParent();
        extendTree(NON_TERMINAL, "", "for action");
    } for_action_expression RP {  
        backToParent();
        backToParent();
        extendTree(NON_TERMINAL, "", "loop body");
    } for_child_statement {
        backToParent();
        backToParent();
        popScope();
    }
    | FOR {
        // establish local scope ;
        //saveNode();
        extendTree(NON_TERMINAL, "for", "for loop");
        pushScope(1);
    } error {
        yyerror("Wrong for expression.");
    }
    ;

for_child_statement
    : statement_block
    | dependent_statement
    ;

array_decorator
    : LSB { 
        extendOptTree("[]"); 
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
        extendTree(NON_TERMINAL, "*", "pointer");
    } high_nter_decorator
    | /* epsilon */
    ;

address_decorator
    : ADDRESS {
        extendTree(NON_TERMINAL, "&", "address");
    }
    | /* epsilon */
    ;

decorated_identifier
    : {
        saveNode();
    } address_decorator high_nter_decorator IDENTIFIER {
        useId($<str>4);
        extendTerminal($<str>4, "identifier");
    } high_ay_decorator {
        loadNode();
    }
    ;

statement
    : dependent_statement
    | { 
        pushScope(1); 
    } statement_block {
        popScope();
    }
    | error SEMICOLON
    | error RBP
    ;

dependent_statement
    : expression SEMICOLON
    | for_expression
    | do_expression
    | while_expression
    | condition_expression
    | declaration
    | BREAK {
        extendTerminal("break", "break");
    } SEMICOLON
    | CONTINUE {
        extendTerminal("continue", "continue");
    } SEMICOLON
    | RETURN {
        extendTree(NON_TERMINAL, "return", "return");
    } expression SEMICOLON {
        backToParent();
    }
    | SEMICOLON
    | PRINT {
        extendTree(NON_TERMINAL, "print", "print");
    } LP {
        extendTree(NON_TERMINAL, "", "print_content");
    } print_content RP {
        backToParent();
        backToParent();
    } SEMICOLON
    | INPUT {
        extendTree(NON_TERMINAL, "input", "input");
    } LP decorated_identifier RP {
        backToParent();
    } SEMICOLON
    ;

print_content
    : expression
    | STRING_C {
        extendTerminal($<str>1, "string");
    }
    ;

statement_block
    : LBP {
        extendTree(NON_TERMINAL, "{}", "statement body");
    } statement_body RBP {
        backToParent();
    }
    ;

statement_body
    : statement statement_body
    | { printf("statement body over!\n"); }
    ;

declaration
    : {
        extendTree(NON_TERMINAL, "", "declaration");
    } type_defination {
        extendTree(NON_TERMINAL, "", "declaration body");
        saveNode();
    } declaration_body {
        backToParent();
        backToParent();
    }
    ;

declaration_body
    : function_declaration {
        extendTree(NON_TERMINAL, "", "function declaration");
        broToParent(-1);
        backToParent();
        //connectParentChild();
    }
    | argument_declaration_list {
        extendTree(NON_TERMINAL, "", "argument declaration list");
        broToParent(-1);
        backToParent();
        //connectParentChild();
    } SEMICOLON
    ;

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

argument_declaration_list
    : argument_declaration_unit argument_declaration_list_tail
    ;

argument_declaration_list_tail
    : COMMA argument_declaration_list
    | error {
        yyerror("Wrong declaration list.");
    }
    | /* epsilon */
    ;

argument_declaration_unit
    : init_identifier {
        extendTree(NON_TERMINAL, "", "argument declaration unit");
        broToParent(1);
    } argument_declaration_init {
        backToParent();
    }
    ; 

argument_declaration_init
    : ASSIGN {
        extendOptTree("=");
    } single_expression {
        backToParent();
    }
    | /* epsilon */
    | ASSIGN {
        extendOptTree("=");
    } error {
        yyerror("Wrong init expression while argument declaration.");
    }
    ;

init_identifier
    : high_nter_decorator IDENTIFIER {
        declarationId($<str>2);
        extendTerminal($<str>2, "identifier");
    } high_ay_decorator {
        loadNode();
    }
    ;

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
    | /* epsilon */
    ;

function_argument_tail
    : COMMA function_argument_list
    | /* epsilon */
    ;

condition_expression
    : IF { 
        extendTree(NON_TERMINAL, "if", "if expression");
    } LP {
        extendTree(NON_TERMINAL, "()", "if condition");
    } expression RP {
        backToParent();
        extendTree(NON_TERMINAL, "", "if statement");
        pushScope(1);
    } statement {
        backToParent();
        popScope();
    } condition_tail {
        backToParent();
    }
    | IF {
        extendTree(NON_TERMINAL, "if", "if expression");
    } error {
        yyerror("Wrong if expression.");
    }
    ;

condition_tail
    : ELSE {
        extendTree(NON_TERMINAL, "else", "else statement");
        pushScope(1); 
    } statement {
        popScope();
        backToParent();
    }
    | {} %prec NONE_ELSE
    | ELSE {
        extendTree(NON_TERMINAL, "else", "else statement");
        pushScope(1); 
    } error {
        yyerror("Wrong else expression.");
    }
    ;

%%


   
void extendTree(int isTerminal, const char* word, const char* grammer) {
    tempPointer = createGrammerNode(isTerminal, word, grammer); 
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

void extendOptTree(const char* opt) {
    extendTree(NON_TERMINAL, opt, "expression");
    adjustOptNode(curNode);
}

void extendTerminal(const char* word, const char* grammer) {
    extendTree(TERMINAL, word, grammer);
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
    root = createGrammerNode(NON_TERMINAL, "", "start");
    curNode = root;
    tempPointer = NULL;
    generateLEX();
    appendLEX("Type           Name           Attribute \n");
    launchTable();
    int err = yyparse();
    closeLEX();
    generateYACC();
    printGrammerTree(root);
    closeYACC();
    stopTable();
    freeGrammerTree(root);
    fclose(yyin);
    printf("%d\n", err);
    return 0; 
}   

void yyerror(const char* charactor) {
    printf("error in line %d: %s\n", yylineno, charactor);
    //yyclearin;
    //yyparse();
}
