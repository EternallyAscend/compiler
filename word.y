%token IDENTIFIER
%token IF ELSE
%token MAIN
%token INT
%token ASSIGN TIMES
%token LP RP LSB RSB LBP RBP
%token CONSTANT

%%

array_decorator
    : LSB expression RSB
    ;

high_level_array_decorator
    : array_decorator high_level_array_decorator
    | array_decorator
    ;

high_level_pointer_decorator
    : TIMES high_level_pointer_decorator
    | TIMES
    ;

address_decorator
    :

decorated_identifier
    : high_level_pointer_decorator IDENTIFIER high_level_array_decorator
    ;

statement_block
    : LBP statement_body RBP
    ;

statement_body
    : expression statement_body
    | expression
    |
    ;

main_function
    : INT MAIN LP argument_list RP statement_block
    ;

statement
    : type_defination statement_argument_list
    | type_defination statement_init_list
    ;

statement_argument_list
    : decorated_identifier ',' statement_argument_list
    | decorated_identifier
    ;

statement_init_unit
    : decorated_identifier ASSIGN expression
    ;

statement_init_list
    : statement_init_unit ',' statement_init_list
    | statement_init_unit
    ;

function_argument
    : type_defination decorated_identifier
    ;

function_argument_list
    : function_argument ',' function_argument_list
    | function_argument
    |
    ;

condition_expression
    : condition_start_expression condition_branches_expression
    | condition_start_expression
    ;

condition_start_expression
    : IF LP expression RP statement_block 
    ;

condition_branch_expression
    : ELSE condition_start_expression
    | ELSE statement_block
    ;

condition_branches_expression
    : condition_branch_expression condition_branches_expression
    | condition_branch_expression
    ;


%%