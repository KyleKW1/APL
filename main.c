


#include <stdio.h>
#include <string.h>

// Global variables for runtime configuration
int debug_mode = 0;    // 0 = disabled, 1 = enabled
int cloud_enabled = 1; // 1 = enabled, 0 = disabled

// Forward declarations (if needed) 
extern int yyparse(void);
extern void cleanup_vars(void);

int main(int argc, char** argv) {
    printf("=== ExplainScript Programming Language ===\n");
    printf("Features: Variables, Arithmetic, Control Flow, LLM Integration\n");
    printf("Type 'help' for assistance or start coding!\n\n");
    
    // Check command line arguments 
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug") == 0) {
            debug_mode = 1;
            printf("Debug mode enabled\n");
        } else if (strcmp(argv[i], "--no-cloud") == 0) {
            cloud_enabled = 0;
            printf("Cloud features disabled\n\n\n");
        }
    } 
    
    int result = yyparse();
    cleanup_vars();
    
    printf("\nProgram execution completed.\n");
    return result;
}





