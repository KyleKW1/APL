/* ====== STREAMLINED PARSER (parser.y) ====== */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define variable types
#define VAR_INT 0
#define VAR_FLOAT 1
#define VAR_BOOL 2

// Forward declarations
void explain_with_llm(const char* msg);
void yyerror(const char *s);
int yylex(void);
void execute_cloud_function(const char* operation, const char* data);

// Variable structure
typedef struct Var {
    char name[64];
    int type;
    union {
        int ival;
        float fval;
        int bval;
    } value;
    struct Var* next;
} Var;

Var* var_list = NULL;

// External declarations
extern int debug_mode;
extern int cloud_enabled;

// Symbol table operations
Var* find_var(const char* name);
void declare_var(const char* name, int type);
void set_var_value(const char* name, int ival, float fval, int bval);
void print_var(const char* name);
void cleanup_vars();

%}

%union {
    int ival;
    float fval;
    char *sval;
    struct {
        int type;
        union {
            int ival;
            float fval;
            int bval;
        } value;
    } expr_val;
}

%token <sval> IDENTIFIER STRING_LITERAL
%token <ival> NUMBER BOOLEAN
%token <fval> FLOAT_NUM
%token LET IF ELSE WHILE FOR EXPLAIN ASK SHOW HELP
%token INT FLOAT BOOL STRING
%token PLUS MINUS MUL DIV MOD POW ASSIGN
%token PLUS_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIV_ASSIGN
%token SEMICOLON COMMA LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token EQ NEQ LE GE LT GT AND OR NOT
%token PRINT INPUT

/* Precedence - PEMDAS/BODMAS */
%right ASSIGN
%left OR
%left AND
%left EQ NEQ
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right POW
%right NOT UMINUS
%left LPAREN RPAREN

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%type <expr_val> expression logical_or logical_and equality relational
%type <expr_val> additive multiplicative exponential unary primary
%type <ival> statement_list statement declaration assignment
%type <ival> if_statement while_statement for_statement print_statement

%start program

%%

program:
    /* empty */               { printf("ExplainScript Ready!\n"); }
  | program statement         { }
  ;

statement_list:
    /* empty */               { $$ = 0; }
  | statement_list statement  { $$ = $1 + $2; }
  ;

statement:
    declaration SEMICOLON     { $$ = 1; }
  | assignment SEMICOLON      { $$ = 1; }
  | if_statement              { $$ = 1; }
  | while_statement           { $$ = 1; }
  | for_statement             { $$ = 1; }
  | print_statement SEMICOLON { $$ = 1; }
  | LBRACE statement_list RBRACE { $$ = $2; }
  | ASK LPAREN IDENTIFIER RPAREN SEMICOLON { 
        char msg[128];
        snprintf(msg, sizeof(msg), "Explaining variable '%s'", $3);
        explain_with_llm(msg);
        print_var($3);
        free($3);
        $$ = 1;
    }
  ;

declaration:
    LET IDENTIFIER ASSIGN expression {
        declare_var($2, $4.type);
        set_var_value($2, $4.value.ival, $4.value.fval, $4.value.bval);
        
        printf("Declared %s : ", $2);
        if ($4.type == VAR_INT) printf("%d\n", $4.value.ival);
        else if ($4.type == VAR_FLOAT) printf("%.2f\n", $4.value.fval);
        else printf("%s\n", $4.value.bval ? "true" : "false");
        
        if (debug_mode) explain_with_llm("Variable declaration");
        free($2);
    }
  | INT IDENTIFIER ASSIGN expression {
        declare_var($2, VAR_INT);
        set_var_value($2, $4.value.ival, 0, 0);
        printf("Declared int %s : %d\n", $2, $4.value.ival);
        free($2);
    }
  | FLOAT IDENTIFIER ASSIGN expression {
        declare_var($2, VAR_FLOAT);
        set_var_value($2, 0, $4.value.fval, 0);
        printf("Declared float %s : %.2f\n", $2, $4.value.fval);
        free($2);
    }
  | BOOL IDENTIFIER ASSIGN expression {
        declare_var($2, VAR_BOOL);
        set_var_value($2, 0, 0, $4.value.bval);
        printf("Declared bool %s : %s\n", $2, $4.value.bval ? "true" : "false");
        free($2);
    }
  ;

assignment:
    IDENTIFIER ASSIGN expression {
        Var* v = find_var($1);
        if (!v) {
            fprintf(stderr, "Error: Variable '%s' not declared\n", $1);
            exit(1);
        }
        set_var_value($1, $3.value.ival, $3.value.fval, $3.value.bval);
        printf("Assigned %s\n", $1);
        free($1);
    }
  ;

if_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
        if ($3.value.bval) {
            printf("If condition true - executing then branch\n");
            if (debug_mode) explain_with_llm("If condition evaluated to true");
        } else {
            printf("If condition false - skipping then branch\n");
        }
    }
  | IF LPAREN expression RPAREN statement ELSE statement {
        if ($3.value.bval) {
            printf("If condition true - executing then branch\n");
        } else {
            printf("If condition false - executing else branch\n");
        }
        if (debug_mode) explain_with_llm("If-else statement executed");
    }
  ;

while_statement:
    WHILE LPAREN expression RPAREN statement {
        printf("While loop executed\n");
        if (debug_mode) explain_with_llm("While loop iteration");
    }
  ;

for_statement:
    FOR LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement {
        printf("For loop executed\n");
        if (debug_mode) explain_with_llm("For loop iteration");
    }
  ;

print_statement:
    PRINT LPAREN expression RPAREN {
        printf("Output: ");
        if ($3.type == VAR_INT) printf("%d\n", $3.value.ival);
        else if ($3.type == VAR_FLOAT) printf("%.2f\n", $3.value.fval);
        else printf("%s\n", $3.value.bval ? "true" : "false");
    }
  ;

/* Expression grammar with PEMDAS precedence */
expression:
    logical_or                        { $$ = $1; }
  ;

logical_or:
    logical_and                       { $$ = $1; }
  | logical_or OR logical_and         {
        $$.type = VAR_BOOL;
        $$.value.bval = $1.value.bval || $3.value.bval;
        if (debug_mode) explain_with_llm("Logical OR operation");
    }
  ;

logical_and:
    equality                          { $$ = $1; }
  | logical_and AND equality          {
        $$.type = VAR_BOOL;
        $$.value.bval = $1.value.bval && $3.value.bval;
        if (debug_mode) explain_with_llm("Logical AND operation");
    }
  ;

equality:
    relational                        { $$ = $1; }
  | equality EQ relational            {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival == $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 == v2);
        }
    }
  | equality NEQ relational           {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival != $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 != v2);
        }
    }
  ;

relational:
    additive                          { $$ = $1; }
  | relational LT additive            {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival < $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 < v2);
        }
    }
  | relational GT additive            {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival > $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 > v2);
        }
    }
  | relational LE additive            {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival <= $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 <= v2);
        }
    }
  | relational GE additive            {
        $$.type = VAR_BOOL;
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.value.bval = ($1.value.ival >= $3.value.ival);
        } else {
            float v1 = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval);
            float v2 = ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
            $$.value.bval = (v1 >= v2);
        }
    }
  ;

additive:
    multiplicative                    { $$ = $1; }
  | additive PLUS multiplicative      {
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.type = VAR_INT;
            $$.value.ival = $1.value.ival + $3.value.ival;
        } else {
            $$.type = VAR_FLOAT;
            $$.value.fval = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval) + 
                           ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
        }
        if (debug_mode) explain_with_llm("Addition operation");
    }
  | additive MINUS multiplicative     {
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.type = VAR_INT;
            $$.value.ival = $1.value.ival - $3.value.ival;
        } else {
            $$.type = VAR_FLOAT;
            $$.value.fval = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval) - 
                           ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
        }
        if (debug_mode) explain_with_llm("Subtraction operation");
    }
  ;

multiplicative:
    exponential                       { $$ = $1; }
  | multiplicative MUL exponential    {
        if ($1.type == VAR_INT && $3.type == VAR_INT) {
            $$.type = VAR_INT;
            $$.value.ival = $1.value.ival * $3.value.ival;
        } else {
            $$.type = VAR_FLOAT;
            $$.value.fval = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval) * 
                           ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
        }
        if (debug_mode) explain_with_llm("Multiplication operation");
    }
  | multiplicative DIV exponential    {
        if (($3.type == VAR_INT && $3.value.ival == 0) || 
            ($3.type == VAR_FLOAT && $3.value.fval == 0.0)) {
            fprintf(stderr, "Error: Division by zero\n");
            exit(1);
        }
        $$.type = VAR_FLOAT;
        $$.value.fval = ($1.type == VAR_INT ? $1.value.ival : $1.value.fval) / 
                       ($3.type == VAR_INT ? $3.value.ival : $3.value.fval);
        if (debug_mode) explain_with_llm("Division operation");
    }
  | multiplicative MOD exponential    {
        if ($1.type != VAR_INT || $3.type != VAR_INT) {
            fprintf(stderr, "Error: Modulo requires integers\n");
            exit(1);
        }
        if ($3.value.ival == 0) {
            fprintf(stderr, "Error: Modulo by zero\n");
            exit(1);
        }
        $$.type = VAR_INT;
        $$.value.ival = $1.value.ival % $3.value.ival;
        if (debug_mode) explain_with_llm("Modulo operation");
    }
  ;

exponential:
    unary                             { $$ = $1; }
  | exponential POW unary             {
        $$.type = VAR_FLOAT;
        $$.value.fval = pow(($1.type == VAR_INT ? $1.value.ival : $1.value.fval),
                           ($3.type == VAR_INT ? $3.value.ival : $3.value.fval));
        if (debug_mode) explain_with_llm("Exponentiation operation");
    }
  ;

unary:
    primary                           { $$ = $1; }
  | NOT unary                         {
        $$.type = VAR_BOOL;
        $$.value.bval = !$2.value.bval;
        if (debug_mode) explain_with_llm("Logical NOT operation");
    }
  | MINUS unary %prec UMINUS          {
        if ($2.type == VAR_INT) {
            $$.type = VAR_INT;
            $$.value.ival = -$2.value.ival;
        } else {
            $$.type = VAR_FLOAT;
            $$.value.fval = -($2.type == VAR_INT ? $2.value.ival : $2.value.fval);
        }
        if (debug_mode) explain_with_llm("Unary minus operation");
    }
  ;

primary:
    IDENTIFIER                        {
        Var* v = find_var($1);
        if (!v) {
            fprintf(stderr, "Error: Variable '%s' not declared\n", $1);
            exit(1);
        }
        $$.type = v->type;
        // Fix: Assign union values field by field instead of entire union
        switch (v->type) {
            case VAR_INT:
                $$.value.ival = v->value.ival;
                break;
            case VAR_FLOAT:
                $$.value.fval = v->value.fval;
                break;
            case VAR_BOOL:
                $$.value.bval = v->value.bval;
                break;
        }
        free($1);
    }
  | NUMBER                            {
        $$.type = VAR_INT;
        $$.value.ival = $1;
    }
  | FLOAT_NUM                         {
        $$.type = VAR_FLOAT;
        $$.value.fval = $1;
    }
  | BOOLEAN                           {
        $$.type = VAR_BOOL;
        $$.value.bval = $1;
    }
  | LPAREN expression RPAREN          {
        $$ = $2;
    }
  ;

%%

// Symbol table implementation
Var* find_var(const char* name) {
    for (Var* v = var_list; v; v = v->next) {
        if (strcmp(v->name, name) == 0) return v;
    }
    return NULL;
}

void declare_var(const char* name, int type) {
    if (find_var(name)) {
        fprintf(stderr, "Warning: Variable '%s' already declared\n", name);
        return;
    }
    Var* new_var = malloc(sizeof(Var));
    strcpy(new_var->name, name);
    new_var->type = type;
    new_var->next = var_list;
    var_list = new_var;
}

void set_var_value(const char* name, int ival, float fval, int bval) {
    Var* v = find_var(name);
    if (!v) {
        fprintf(stderr, "Error: Variable '%s' not declared\n", name);
        exit(1);
    }
    
    switch (v->type) {
        case VAR_INT:    v->value.ival = ival; break;
        case VAR_FLOAT:  v->value.fval = fval; break;
        case VAR_BOOL:   v->value.bval = bval; break;
    }
}

void print_var(const char* name) {
    Var* v = find_var(name);
    if (!v) {
        fprintf(stderr, "Error: Variable '%s' not declared\n", name);
        return;
    }
    
    printf("Variable '%s': ", name);
    switch (v->type) {
        case VAR_INT:   printf("int = %d\n", v->value.ival); break;
        case VAR_FLOAT: printf("float = %.2f\n", v->value.fval); break;
        case VAR_BOOL:  printf("bool = %s\n", v->value.bval ? "true" : "false"); break;
    }
}

void cleanup_vars() {
    while (var_list) {
        Var* temp = var_list;
        var_list = var_list->next;
        free(temp);
    }
}

// LLM interface function
void explain_with_llm(const char* msg) {
    printf("[LLM] %s\n", msg);
    execute_cloud_function("explain", msg);
    
    // Educational explanations
    if (strstr(msg, "variable")) {
        printf("Variables store values in memory with specific types\n");
    } else if (strstr(msg, "Addition") || strstr(msg, "Subtraction") || 
               strstr(msg, "Multiplication") || strstr(msg, "Division")) {
        printf("→ Arithmetic follows PEMDAS precedence rules\n");
    } else if (strstr(msg, "If")) {
        printf("→ Conditional statements control program flow\n");
    } else if (strstr(msg, "loop")) {
        printf("→ Loops enable repetitive execution\n");
    }
}

// Cloud function interface
void execute_cloud_function(const char* operation, const char* data) {
    if (cloud_enabled) {
        printf("[CLOUD] %s: %s\n", operation, data);
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}