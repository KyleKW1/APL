/* ====== STREAMLINED PARSER WITH WORKING LOOPS (parser.y) ====== */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define variable types
#define VAR_INT 0
#define VAR_FLOAT 1
#define VAR_BOOL 2

// AST Node types
#define NODE_PROGRAM 0
#define NODE_DECLARATION 1
#define NODE_ASSIGNMENT 2
#define NODE_IF 3
#define NODE_WHILE 4
#define NODE_FOR 5
#define NODE_PRINT 6
#define NODE_BLOCK 7
#define NODE_EXPRESSION 8
#define NODE_ASK 9

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

// AST Node structure
typedef struct ASTNode {
    int type;
    union {
        struct {
            char name[64];
            int var_type;
            struct ASTNode* init_expr;
        } declaration;
        
        struct {
            char name[64];
            struct ASTNode* expr;
        } assignment;
        
        struct {
            struct ASTNode* condition;
            struct ASTNode* then_stmt;
            struct ASTNode* else_stmt;
        } if_node;
        
        struct {
            struct ASTNode* condition;
            struct ASTNode* body;
        } while_node;
        
        struct {
            struct ASTNode* init;
            struct ASTNode* condition;
            struct ASTNode* increment;
            struct ASTNode* body;
        } for_node;
        
        struct {
            struct ASTNode* expr;
        } print_node;
        
        struct {
            struct ASTNode** statements;
            int count;
            int capacity;
        } block;
        
        struct {
            int op;
            struct ASTNode* left;
            struct ASTNode* right;
            union {
                int ival;
                float fval;
                int bval;
                char name[64];
            } value;
            int expr_type;
        } expression;
        
        struct {
            char name[64];
        } ask_node;
    } data;
    
    struct ASTNode* next;
} ASTNode;

Var* var_list = NULL;
ASTNode* ast_root = NULL;

// External declarations
extern int debug_mode;
extern int cloud_enabled;

// Symbol table operations
Var* find_var(const char* name);
void declare_var(const char* name, int type);
void set_var_value(const char* name, int ival, float fval, int bval);
void print_var(const char* name);
void cleanup_vars();

// AST operations
ASTNode* create_node(int type);
ASTNode* create_expression_node(int op, ASTNode* left, ASTNode* right);
ASTNode* create_value_node(int type, int ival, float fval, int bval);
ASTNode* create_variable_node(const char* name);
void add_to_block(ASTNode* block, ASTNode* stmt);
void execute_ast(ASTNode* node);
void cleanup_ast(ASTNode* node);

// Expression evaluation
typedef struct {
    int type;
    union {
        int ival;
        float fval;
        int bval;
    } value;
} ExprResult;

ExprResult evaluate_expression(ASTNode* expr);

%}

%union {
    int ival;
    float fval;
    char *sval;
    struct ASTNode* node;
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

%type <node> expression logical_or logical_and equality relational
%type <node> additive multiplicative exponential unary primary
%type <node> statement_list statement declaration assignment
%type <node> if_statement while_statement for_statement print_statement
%type <node> block_statement program

%start program

%%

program:
    /* empty */               { 
        ast_root = create_node(NODE_PROGRAM);
        ast_root->data.block.statements = NULL;
        ast_root->data.block.count = 0;
        ast_root->data.block.capacity = 0;
        printf("ExplainScript Ready!\n");
        $$ = ast_root;
    }
  | program statement         { 
        add_to_block($1, $2);
        execute_ast($2);
        $$ = $1;
    }
  ;

statement_list:
    /* empty */               { 
        $$ = create_node(NODE_BLOCK);
        $$->data.block.statements = NULL;
        $$->data.block.count = 0;
        $$->data.block.capacity = 0;
    }
  | statement_list statement  { 
        add_to_block($1, $2);
        $$ = $1;
    }
  ;

statement:
    declaration SEMICOLON     { $$ = $1; }
  | assignment SEMICOLON      { $$ = $1; }
  | if_statement              { $$ = $1; }
  | while_statement           { $$ = $1; }
  | for_statement             { $$ = $1; }
  | print_statement SEMICOLON { $$ = $1; }
  | block_statement           { $$ = $1; }
  | ASK LPAREN IDENTIFIER RPAREN SEMICOLON { 
        $$ = create_node(NODE_ASK);
        strcpy($$->data.ask_node.name, $3);
        free($3);
    }
  ;

block_statement:
    LBRACE statement_list RBRACE { $$ = $2; }
  ;

declaration:
    LET IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_DECLARATION);
        strcpy($$->data.declaration.name, $2);
        $$->data.declaration.var_type = -1; // Auto-infer type
        $$->data.declaration.init_expr = $4;
        free($2);
    }
  | INT IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_DECLARATION);
        strcpy($$->data.declaration.name, $2);
        $$->data.declaration.var_type = VAR_INT;
        $$->data.declaration.init_expr = $4;
        free($2);
    }
  | FLOAT IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_DECLARATION);
        strcpy($$->data.declaration.name, $2);
        $$->data.declaration.var_type = VAR_FLOAT;
        $$->data.declaration.init_expr = $4;
        free($2);
    }
  | BOOL IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_DECLARATION);
        strcpy($$->data.declaration.name, $2);
        $$->data.declaration.var_type = VAR_BOOL;
        $$->data.declaration.init_expr = $4;
        free($2);
    }
  ;

assignment:
    IDENTIFIER ASSIGN expression {
        $$ = create_node(NODE_ASSIGNMENT);
        strcpy($$->data.assignment.name, $1);
        $$->data.assignment.expr = $3;
        free($1);
    }
  ;

if_statement:
    IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
        $$ = create_node(NODE_IF);
        $$->data.if_node.condition = $3;
        $$->data.if_node.then_stmt = $5;
        $$->data.if_node.else_stmt = NULL;
    }
  | IF LPAREN expression RPAREN statement ELSE statement {
        $$ = create_node(NODE_IF);
        $$->data.if_node.condition = $3;
        $$->data.if_node.then_stmt = $5;
        $$->data.if_node.else_stmt = $7;
    }
  ;

while_statement:
    WHILE LPAREN expression RPAREN statement {
        $$ = create_node(NODE_WHILE);
        $$->data.while_node.condition = $3;
        $$->data.while_node.body = $5;
    }
  ;

for_statement:
    FOR LPAREN assignment SEMICOLON expression SEMICOLON assignment RPAREN statement {
        $$ = create_node(NODE_FOR);
        $$->data.for_node.init = $3;
        $$->data.for_node.condition = $5;
        $$->data.for_node.increment = $7;
        $$->data.for_node.body = $9;
    }
  ;

print_statement:
    PRINT LPAREN expression RPAREN {
        $$ = create_node(NODE_PRINT);
        $$->data.print_node.expr = $3;
    }
  ;

/* Expression grammar with PEMDAS precedence */
expression:
    logical_or                        { $$ = $1; }
  ;

logical_or:
    logical_and                       { $$ = $1; }
  | logical_or OR logical_and         {
        $$ = create_expression_node(OR, $1, $3);
    }
  ;

logical_and:
    equality                          { $$ = $1; }
  | logical_and AND equality          {
        $$ = create_expression_node(AND, $1, $3);
    }
  ;

equality:
    relational                        { $$ = $1; }
  | equality EQ relational            {
        $$ = create_expression_node(EQ, $1, $3);
    }
  | equality NEQ relational           {
        $$ = create_expression_node(NEQ, $1, $3);
    }
  ;

relational:
    additive                          { $$ = $1; }
  | relational LT additive            {
        $$ = create_expression_node(LT, $1, $3);
    }
  | relational GT additive            {
        $$ = create_expression_node(GT, $1, $3);
    }
  | relational LE additive            {
        $$ = create_expression_node(LE, $1, $3);
    }
  | relational GE additive            {
        $$ = create_expression_node(GE, $1, $3);
    }
  ;

additive:
    multiplicative                    { $$ = $1; }
  | additive PLUS multiplicative      {
        $$ = create_expression_node(PLUS, $1, $3);
    }
  | additive MINUS multiplicative     {
        $$ = create_expression_node(MINUS, $1, $3);
    }
  ;

multiplicative:
    exponential                       { $$ = $1; }
  | multiplicative MUL exponential    {
        $$ = create_expression_node(MUL, $1, $3);
    }
  | multiplicative DIV exponential    {
        $$ = create_expression_node(DIV, $1, $3);
    }
  | multiplicative MOD exponential    {
        $$ = create_expression_node(MOD, $1, $3);
    }
  ;

exponential:
    unary                             { $$ = $1; }
  | exponential POW unary             {
        $$ = create_expression_node(POW, $1, $3);
    }
  ;

unary:
    primary                           { $$ = $1; }
  | NOT unary                         {
        $$ = create_expression_node(NOT, $2, NULL);
    }
  | MINUS unary %prec UMINUS          {
        $$ = create_expression_node(UMINUS, $2, NULL);
    }
  ;

primary:
    IDENTIFIER                        {
        $$ = create_variable_node($1);
        free($1);
    }
  | NUMBER                            {
        $$ = create_value_node(VAR_INT, $1, 0, 0);
    }
  | FLOAT_NUM                         {
        $$ = create_value_node(VAR_FLOAT, 0, $1, 0);
    }
  | BOOLEAN                           {
        $$ = create_value_node(VAR_BOOL, 0, 0, $1);
    }
  | LPAREN expression RPAREN          {
        $$ = $2;
    }
  ;

%%

// AST Node creation functions
ASTNode* create_node(int type) {
    ASTNode* node = malloc(sizeof(ASTNode));
    memset(node, 0, sizeof(ASTNode));
    node->type = type;
    return node;
}

ASTNode* create_expression_node(int op, ASTNode* left, ASTNode* right) {
    ASTNode* node = create_node(NODE_EXPRESSION);
    node->data.expression.op = op;
    node->data.expression.left = left;
    node->data.expression.right = right;
    return node;
}

ASTNode* create_value_node(int type, int ival, float fval, int bval) {
    ASTNode* node = create_node(NODE_EXPRESSION);
    node->data.expression.op = 0; // Literal value
    node->data.expression.expr_type = type;
    node->data.expression.left = NULL;
    node->data.expression.right = NULL;
    
    switch (type) {
        case VAR_INT:   node->data.expression.value.ival = ival; break;
        case VAR_FLOAT: node->data.expression.value.fval = fval; break;
        case VAR_BOOL:  node->data.expression.value.bval = bval; break;
    }
    return node;
}

ASTNode* create_variable_node(const char* name) {
    ASTNode* node = create_node(NODE_EXPRESSION);
    node->data.expression.op = -1; // Variable reference
    strcpy(node->data.expression.value.name, name);
    return node;
}

void add_to_block(ASTNode* block, ASTNode* stmt) {
    if (block->data.block.count >= block->data.block.capacity) {
        block->data.block.capacity = (block->data.block.capacity == 0) ? 4 : block->data.block.capacity * 2;
        block->data.block.statements = realloc(block->data.block.statements, 
            block->data.block.capacity * sizeof(ASTNode*));
    }
    block->data.block.statements[block->data.block.count++] = stmt;
}

// Expression evaluation
ExprResult evaluate_expression(ASTNode* expr) {
    ExprResult result = {0};
    
    if (expr->data.expression.op == 0) { // Literal value
        result.type = expr->data.expression.expr_type;
        switch (expr->data.expression.expr_type) {
            case VAR_INT:
                result.value.ival = expr->data.expression.value.ival;
                break;
            case VAR_FLOAT:
                result.value.fval = expr->data.expression.value.fval;
                break;
            case VAR_BOOL:
                result.value.bval = expr->data.expression.value.bval;
                break;
        }
        return result;
    }
    
    if (expr->data.expression.op == -1) { // Variable reference
        Var* v = find_var(expr->data.expression.value.name);
        if (!v) {
            fprintf(stderr, "Error: Variable '%s' not declared\n", expr->data.expression.value.name);
            exit(1);
        }
        result.type = v->type;
        switch (v->type) {
            case VAR_INT:
                result.value.ival = v->value.ival;
                break;
            case VAR_FLOAT:
                result.value.fval = v->value.fval;
                break;
            case VAR_BOOL:
                result.value.bval = v->value.bval;
                break;
        }
        return result;
    }
    
    // Binary operations
    ExprResult left = {0}, right = {0};
    if (expr->data.expression.left) left = evaluate_expression(expr->data.expression.left);
    if (expr->data.expression.right) right = evaluate_expression(expr->data.expression.right);
    
    switch (expr->data.expression.op) {
        case PLUS:
            if (left.type == VAR_FLOAT || right.type == VAR_FLOAT) {
                result.type = VAR_FLOAT;
                float left_val = (left.type == VAR_FLOAT) ? left.value.fval : (float)left.value.ival;
                float right_val = (right.type == VAR_FLOAT) ? right.value.fval : (float)right.value.ival;
                result.value.fval = left_val + right_val;
            } else {
                result.type = VAR_INT;
                result.value.ival = left.value.ival + right.value.ival;
            }
            break;
        case MINUS:
            if (left.type == VAR_FLOAT || right.type == VAR_FLOAT) {
                result.type = VAR_FLOAT;
                float left_val = (left.type == VAR_FLOAT) ? left.value.fval : (float)left.value.ival;
                float right_val = (right.type == VAR_FLOAT) ? right.value.fval : (float)right.value.ival;
                result.value.fval = left_val - right_val;
            } else {
                result.type = VAR_INT;
                result.value.ival = left.value.ival - right.value.ival;
            }
            break;
            
        case MUL:
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.type = VAR_INT;
                result.value.ival = left.value.ival * right.value.ival;
            } else {
                result.type = VAR_FLOAT;
                result.value.fval = (left.type == VAR_INT ? left.value.ival : left.value.fval) * 
                                   (right.type == VAR_INT ? right.value.ival : right.value.fval);
            }
            break;
            
        case DIV:
            if ((right.type == VAR_INT && right.value.ival == 0) || 
                (right.type == VAR_FLOAT && right.value.fval == 0.0)) {
                fprintf(stderr, "Error: Division by zero\n");
                exit(1);
            }
            result.type = VAR_FLOAT;
            result.value.fval = (left.type == VAR_INT ? left.value.ival : left.value.fval) / 
                               (right.type == VAR_INT ? right.value.ival : right.value.fval);
            break;
            
        case MOD:
            if (left.type != VAR_INT || right.type != VAR_INT) {
                fprintf(stderr, "Error: Modulo requires integers\n");
                exit(1);
            }
            if (right.value.ival == 0) {
                fprintf(stderr, "Error: Modulo by zero\n");
                exit(1);
            }
            result.type = VAR_INT;
            result.value.ival = left.value.ival % right.value.ival;
            break;
            
        case POW:
            result.type = VAR_FLOAT;
            result.value.fval = pow((left.type == VAR_INT ? left.value.ival : left.value.fval),
                                   (right.type == VAR_INT ? right.value.ival : right.value.fval));
            break;
            
        case LT:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival < right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 < v2);
            }
            break;
            
        case GT:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival > right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 > v2);
            }
            break;
            
        case LE:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival <= right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 <= v2);
            }
            break;
            
        case GE:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival >= right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 >= v2);
            }
            break;
            
        case EQ:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival == right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 == v2);
            }
            break;
            
        case NEQ:
            result.type = VAR_BOOL;
            if (left.type == VAR_INT && right.type == VAR_INT) {
                result.value.bval = (left.value.ival != right.value.ival);
            } else {
                float v1 = (left.type == VAR_INT ? left.value.ival : left.value.fval);
                float v2 = (right.type == VAR_INT ? right.value.ival : right.value.fval);
                result.value.bval = (v1 != v2);
            }
            break;
            
        case AND:
            result.type = VAR_BOOL;
            result.value.bval = left.value.bval && right.value.bval;
            break;
            
        case OR:
            result.type = VAR_BOOL;
            result.value.bval = left.value.bval || right.value.bval;
            break;
            
        case NOT:
            result.type = VAR_BOOL;
            result.value.bval = !left.value.bval;
            break;
            
        case UMINUS:
            if (left.type == VAR_INT) {
                result.type = VAR_INT;
                result.value.ival = -left.value.ival;
            } else {
                result.type = VAR_FLOAT;
                result.value.fval = -(left.type == VAR_INT ? left.value.ival : left.value.fval);
            }
            break;
    }
    
    return result;
}

// AST execution - THIS IS WHERE THE MAGIC HAPPENS
void execute_ast(ASTNode* node) {
    if (!node) return;
    
    switch (node->type) {
        case NODE_DECLARATION: {
            ExprResult result = evaluate_expression(node->data.declaration.init_expr);
            int var_type = (node->data.declaration.var_type == -1) ? result.type : node->data.declaration.var_type;
            
            declare_var(node->data.declaration.name, var_type);
            set_var_value(node->data.declaration.name, result.value.ival, result.value.fval, result.value.bval);
            
            printf("Declared %s : ", node->data.declaration.name);
            if (var_type == VAR_INT) printf("%d\n", result.value.ival);
            else if (var_type == VAR_FLOAT) printf("%.2f\n", result.value.fval);
            else printf("%s\n", result.value.bval ? "true" : "false");
            
            if (debug_mode) explain_with_llm("Variable declaration");
            break;
        }
        
        case NODE_ASSIGNMENT: {
            ExprResult result = evaluate_expression(node->data.assignment.expr);
            Var* v = find_var(node->data.assignment.name);
            if (!v) {
                fprintf(stderr, "Error: Variable '%s' not declared\n", node->data.assignment.name);
                exit(1);
            }
            set_var_value(node->data.assignment.name, result.value.ival, result.value.fval, result.value.bval);
            printf("Assigned %s\n", node->data.assignment.name);
            break;
        }
        
        case NODE_IF: {
            ExprResult condition = evaluate_expression(node->data.if_node.condition);
            if (condition.value.bval) {
                printf("If condition true - executing then branch\n");
                execute_ast(node->data.if_node.then_stmt);
            } else if (node->data.if_node.else_stmt) {
                printf("If condition false - executing else branch\n");
                execute_ast(node->data.if_node.else_stmt);
            } else {
                printf("If condition false - skipping then branch\n");
            }
            if (debug_mode) explain_with_llm("If statement executed");
            break;
        }
        
        case NODE_WHILE: {
            int iteration = 0;
            printf("Starting while loop...\n");
            
            // THIS IS THE KEY: We can now re-evaluate the condition in a loop!
            while (1) {
                ExprResult condition = evaluate_expression(node->data.while_node.condition);
                if (!condition.value.bval) break;
                
                printf("  While loop iteration %d\n", ++iteration);
                execute_ast(node->data.while_node.body);
                
                if (debug_mode) explain_with_llm("While loop iteration");
                
                // Safety break to prevent infinite loops in demo
                if (iteration > 100) {
                    printf("  [Warning: Loop stopped after 100 iterations]\n");
                    break;
                }
            }
            printf("While loop completed after %d iterations\n", iteration);
            break;
        }
        
        case NODE_FOR: {
            printf("Starting for loop...\n");
            
            // Execute initialization
            execute_ast(node->data.for_node.init);
            
            int iteration = 0;
            while (1) {
                // Check condition
                ExprResult condition = evaluate_expression(node->data.for_node.condition);
                if (!condition.value.bval) break;
                
                printf("  For loop iteration %d\n", ++iteration);
                
                // Execute body
                execute_ast(node->data.for_node.body);
                
                // Execute increment
                execute_ast(node->data.for_node.increment);
                
                if (debug_mode) explain_with_llm("For loop iteration");
                
                // Safety break
                if (iteration > 100) {
                    printf("  [Warning: Loop stopped after 100 iterations]\n");
                    break;
                }
            }
            printf("For loop completed after %d iterations\n", iteration);
            break;
        }
        
        case NODE_PRINT: {
            ExprResult result = evaluate_expression(node->data.print_node.expr);
            printf("Output: ");
            if (result.type == VAR_INT) printf("%d\n", result.value.ival);
            else if (result.type == VAR_FLOAT) printf("%.2f\n", result.value.fval);
            else printf("%s\n", result.value.bval ? "true" : "false");
            break;
        }
        
        case NODE_BLOCK: {
            for (int i = 0; i < node->data.block.count; i++) {
                execute_ast(node->data.block.statements[i]);
            }
            break;
        }
        
        case NODE_ASK: {
            char msg[128];
            snprintf(msg, sizeof(msg), "Explaining variable '%s'", node->data.ask_node.name);
            explain_with_llm(msg);
            print_var(node->data.ask_node.name);
            break;
        }
    }
}

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
