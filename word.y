%token IDENTIFIER
%token IF ELSE ELSEIF
%token MAIN
%token INT
%token ASSIGN

%%
statement_block
    : '{' statement_body '}'
    ;

statement_body
    : expression statement_body
    | expression
    |
    ;

main_function
    : INT MAIN '(' argument_list ')' statement_block
    ;

statement
    : type_defination IDENTIFIER ASSIGN expression
    | type_defination IDENTIFIER
    ;

argument
    : INT IDENTIFIER
    ;

argument_list
    : argument ',' argument_list
    | argument
    |
    ;

condition_expression
    : condition_start_expression condition_branches_expression condition_end_expression
    | condition_start_expression  condition_end_expression
    | condition_start_expression
    ;

condition_start_expression
    : IF '(' expression ')' statement_block 
    ;

condition_end_expression
    : ELSE '(' expression ')' statement_block
    ;

condition_branch_expression
    : ELSEIF '(' expression ')' statement_block
    ;

condition_branches_expression
    : condition_branch_expression condition_branches_expression
    | condition_branch_expression
    ;


%%