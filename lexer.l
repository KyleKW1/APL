%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yydebug;
extern int yylex_debug;
void yyerror(const char *s);
%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
ALPHA       [a-zA-Z]
ALPHANUM    [a-zA-Z0-9]
EXP         [Ee][+-]?{DIGIT}+

%%

"let"           { return LET; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"explain"       { return EXPLAIN; }
"show"          { return SHOW; }
"help"          { return HELP; }
"print"         { return PRINT; }
"input"         { return INPUT; }
"ask"           { return ASK; }

"int"           { return INT; }
"float"         { return FLOAT; }
"string"        { return STRING; }
"bool"          { return BOOL; }

"true"          { yylval.ival = 1; return BOOLEAN; }
"false"         { yylval.ival = 0; return BOOLEAN; }

">="            { return GE; }
"<="            { return LE; }
"=="            { return EQ; }
"!="            { return NEQ; }
">"             { return GT; }
"<"             { return LT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"**"            { return POW; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }

"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"*="            { return MUL_ASSIGN; }
"/="            { return DIV_ASSIGN; }
"="             { return ASSIGN; }

"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }

";"             { return SEMICOLON; }
","             { return COMMA; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }

{DIGIT}+        {
                    yylval.ival = atoi(yytext);
                    return NUMBER;
                }

{DIGIT}+\.{DIGIT}+ {
                    yylval.fval = atof(yytext);
                    return FLOAT_NUM;
                }

\"[^"]*\"       {
                    char *str_content = strdup(yytext + 1);
                    str_content[strlen(str_content) - 1] = '\0';
                    yylval.sval = str_content;
                    return STRING_LITERAL;
                }

{ALPHA}({ALPHANUM}|_)* {
                    yylval.sval = strdup(yytext);
                    return IDENTIFIER;
                }

[ \t]+          { /* skip spaces and tabs */ }
\r?\n           { printf("\n"); /* preserve newlines in output */ }
"//".*          { /* skip single-line comment */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* Multi-line comments */ }

.               {
                    fprintf(stderr, "Lexical error on line %d: Unexpected character '%s'\n", yylineno, yytext);
                    exit(1);
                }

%%