%token IDENTIFIER
%token IF ELSE
%token MAIN
%token INT
%token ASSIGN TIMES
%token LP RP LSB RSB LBP RBP
%token CONSTANT
%token ADDRESS

%%

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

statement_block
    : LBP statement_body RBP
    ;

statement_body
    : expression statement_body
    |
    ;

function
    : type_defination decorated_identifier LP function_argument_list RP statement_block
    ;

declaration
    : type_defination declaration_list
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