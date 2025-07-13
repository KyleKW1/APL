/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     NUMBER = 260,
     BOOLEAN = 261,
     FLOAT_NUM = 262,
     LET = 263,
     IF = 264,
     ELSE = 265,
     WHILE = 266,
     FOR = 267,
     EXPLAIN = 268,
     ASK = 269,
     SHOW = 270,
     HELP = 271,
     INT = 272,
     FLOAT = 273,
     BOOL = 274,
     STRING = 275,
     PLUS = 276,
     MINUS = 277,
     MUL = 278,
     DIV = 279,
     MOD = 280,
     POW = 281,
     ASSIGN = 282,
     PLUS_ASSIGN = 283,
     MINUS_ASSIGN = 284,
     MUL_ASSIGN = 285,
     DIV_ASSIGN = 286,
     SEMICOLON = 287,
     COMMA = 288,
     LPAREN = 289,
     RPAREN = 290,
     LBRACE = 291,
     RBRACE = 292,
     LBRACKET = 293,
     RBRACKET = 294,
     EQ = 295,
     NEQ = 296,
     LE = 297,
     GE = 298,
     LT = 299,
     GT = 300,
     AND = 301,
     OR = 302,
     NOT = 303,
     PRINT = 304,
     INPUT = 305,
     UMINUS = 306,
     LOWER_THAN_ELSE = 307
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define NUMBER 260
#define BOOLEAN 261
#define FLOAT_NUM 262
#define LET 263
#define IF 264
#define ELSE 265
#define WHILE 266
#define FOR 267
#define EXPLAIN 268
#define ASK 269
#define SHOW 270
#define HELP 271
#define INT 272
#define FLOAT 273
#define BOOL 274
#define STRING 275
#define PLUS 276
#define MINUS 277
#define MUL 278
#define DIV 279
#define MOD 280
#define POW 281
#define ASSIGN 282
#define PLUS_ASSIGN 283
#define MINUS_ASSIGN 284
#define MUL_ASSIGN 285
#define DIV_ASSIGN 286
#define SEMICOLON 287
#define COMMA 288
#define LPAREN 289
#define RPAREN 290
#define LBRACE 291
#define RBRACE 292
#define LBRACKET 293
#define RBRACKET 294
#define EQ 295
#define NEQ 296
#define LE 297
#define GE 298
#define LT 299
#define GT 300
#define AND 301
#define OR 302
#define NOT 303
#define PRINT 304
#define INPUT 305
#define UMINUS 306
#define LOWER_THAN_ELSE 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "parser.y"
{
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
/* Line 1529 of yacc.c.  */
#line 167 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

