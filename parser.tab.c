/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 2 "parser.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 258 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 271 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNRULES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    14,    17,    19,
      21,    23,    26,    30,    36,    41,    46,    51,    56,    60,
      66,    74,    80,    90,    95,    97,    99,   103,   105,   109,
     111,   115,   119,   121,   125,   129,   133,   137,   139,   143,
     147,   149,   153,   157,   161,   163,   167,   169,   172,   175,
     177,   179,   181,   183
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    56,    -1,    -1,    55,    56,
      -1,    57,    32,    -1,    58,    32,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    32,    -1,    36,    55,    37,    -1,
      14,    34,     3,    35,    32,    -1,     8,     3,    27,    63,
      -1,    17,     3,    27,    63,    -1,    18,     3,    27,    63,
      -1,    19,     3,    27,    63,    -1,     3,    27,    63,    -1,
       9,    34,    63,    35,    56,    -1,     9,    34,    63,    35,
      56,    10,    56,    -1,    11,    34,    63,    35,    56,    -1,
      12,    34,    58,    32,    63,    32,    58,    35,    56,    -1,
      49,    34,    63,    35,    -1,    64,    -1,    65,    -1,    64,
      47,    65,    -1,    66,    -1,    65,    46,    66,    -1,    67,
      -1,    66,    40,    67,    -1,    66,    41,    67,    -1,    68,
      -1,    67,    44,    68,    -1,    67,    45,    68,    -1,    67,
      42,    68,    -1,    67,    43,    68,    -1,    69,    -1,    68,
      21,    69,    -1,    68,    22,    69,    -1,    70,    -1,    69,
      23,    70,    -1,    69,    24,    70,    -1,    69,    25,    70,
      -1,    71,    -1,    70,    26,    71,    -1,    72,    -1,    48,
      71,    -1,    22,    71,    -1,     3,    -1,     5,    -1,     7,
      -1,     6,    -1,    34,    63,    35,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   101,   102,   106,   107,   108,   109,
     110,   111,   112,   113,   124,   136,   142,   148,   157,   170,
     178,   189,   196,   203,   213,   217,   218,   226,   227,   235,
     236,   246,   259,   260,   270,   280,   290,   303,   304,   315,
     329,   330,   341,   352,   368,   369,   378,   379,   384,   397,
     418,   422,   426,   430
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL", "NUMBER",
  "BOOLEAN", "FLOAT_NUM", "LET", "IF", "ELSE", "WHILE", "FOR", "EXPLAIN",
  "ASK", "SHOW", "HELP", "INT", "FLOAT", "BOOL", "STRING", "PLUS", "MINUS",
  "MUL", "DIV", "MOD", "POW", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "EQ", "NEQ", "LE", "GE",
  "LT", "GT", "AND", "OR", "NOT", "PRINT", "INPUT", "UMINUS",
  "LOWER_THAN_ELSE", "$accept", "program", "statement_list", "statement",
  "declaration", "assignment", "if_statement", "while_statement",
  "for_statement", "print_statement", "expression", "logical_or",
  "logical_and", "equality", "relational", "additive", "multiplicative",
  "exponential", "unary", "primary", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    58,    59,
      59,    60,    61,    62,    63,    64,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    71,    71,    71,    72,
      72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     2,     2,     1,     1,
       1,     2,     3,     5,     4,     4,     4,     4,     3,     5,
       7,     5,     9,     4,     1,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     2,     2,     1,
       1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     3,     0,     0,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     7,    11,    49,    50,    52,    51,     0,
       0,     0,    18,    24,    25,    27,    29,    32,    37,    40,
      44,    46,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     5,     0,    48,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,    15,    16,    17,    23,    53,
      26,    28,    30,    31,    35,    36,    33,    34,    38,    39,
      41,    42,    43,    45,    19,    21,     0,    13,     0,     0,
      20,     0,     0,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    30,    14,    15,    16,    17,    18,    19,    20,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int8 yypact[] =
{
     -48,     6,   -48,   -11,    24,    -1,     5,    20,    22,    60,
      67,    73,   -48,    43,   -48,    46,    50,   -48,   -48,   -48,
      55,    23,    63,    23,    23,    89,    90,    70,    71,    72,
      32,    23,   -48,   -48,   -48,   -48,   -48,   -48,   -48,    23,
      23,    23,   -48,    53,    56,   -36,    16,   -14,   -12,    75,
     -48,   -48,    23,    68,    69,    74,    76,    23,    23,    23,
     -48,   -48,    79,   -48,    80,   -48,    23,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    23,    23,
     -48,    77,    77,    23,    78,   -48,   -48,   -48,   -48,   -48,
      56,   -36,    16,    16,   -14,   -14,   -14,   -14,   -12,   -12,
      75,    75,    75,   -48,    95,   -48,    84,   -48,    77,    89,
     -48,    82,    77,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -29,   -48,   -25,   -48,   -48,   -48,   -48,
     -21,   -48,    41,    42,   -47,    -6,   -27,    -3,    -7,   -48
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      55,    61,    53,    54,    68,    69,     2,    74,    75,     3,
      62,    76,    77,    78,     4,     5,    21,     6,     7,    64,
       8,    92,    93,     9,    10,    11,    35,    22,    36,    37,
      38,    80,    63,    23,    65,     3,    85,    86,    87,    24,
       4,     5,    12,     6,     7,    39,     8,    98,    99,     9,
      10,    11,   104,   105,    25,    13,    26,    40,    70,    71,
      72,    73,   106,    27,    94,    95,    96,    97,    12,    60,
      28,    41,   103,   100,   101,   102,    29,    31,    32,   110,
       3,    13,    33,   113,   111,     4,     5,    34,     6,     7,
      52,     8,     3,    56,     9,    10,    11,    57,    58,    59,
      66,    79,    67,    81,    82,   108,    83,    90,     0,    91,
     107,    84,     0,    12,    88,    89,   109,   112,     0,     0,
       0,     0,     0,     0,     0,     0,    13
};

static const yytype_int8 yycheck[] =
{
      25,    30,    23,    24,    40,    41,     0,    21,    22,     3,
      31,    23,    24,    25,     8,     9,    27,    11,    12,    40,
      14,    68,    69,    17,    18,    19,     3,     3,     5,     6,
       7,    52,    39,    34,    41,     3,    57,    58,    59,    34,
       8,     9,    36,    11,    12,    22,    14,    74,    75,    17,
      18,    19,    81,    82,    34,    49,    34,    34,    42,    43,
      44,    45,    83,     3,    70,    71,    72,    73,    36,    37,
       3,    48,    79,    76,    77,    78,     3,    34,    32,   108,
       3,    49,    32,   112,   109,     8,     9,    32,    11,    12,
      27,    14,     3,     3,    17,    18,    19,    27,    27,    27,
      47,    26,    46,    35,    35,    10,    32,    66,    -1,    67,
      32,    35,    -1,    36,    35,    35,    32,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,     0,     3,     8,     9,    11,    12,    14,    17,
      18,    19,    36,    49,    56,    57,    58,    59,    60,    61,
      62,    27,     3,    34,    34,    34,    34,     3,     3,     3,
      55,    34,    32,    32,    32,     3,     5,     6,     7,    22,
      34,    48,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    27,    63,    63,    58,     3,    27,    27,    27,
      37,    56,    63,    71,    63,    71,    47,    46,    40,    41,
      42,    43,    44,    45,    21,    22,    23,    24,    25,    26,
      63,    35,    35,    32,    35,    63,    63,    63,    35,    35,
      65,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    56,    56,    63,    32,    10,    32,
      56,    58,    35,    56
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 96 "parser.y"
    { printf("ExplainScript Ready!\n"); ;}
    break;

  case 3:
#line 97 "parser.y"
    { ;}
    break;

  case 4:
#line 101 "parser.y"
    { (yyval.ival) = 0; ;}
    break;

  case 5:
#line 102 "parser.y"
    { (yyval.ival) = (yyvsp[(1) - (2)].ival) + (yyvsp[(2) - (2)].ival); ;}
    break;

  case 6:
#line 106 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 7:
#line 107 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 8:
#line 108 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 9:
#line 109 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 10:
#line 110 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 11:
#line 111 "parser.y"
    { (yyval.ival) = 1; ;}
    break;

  case 12:
#line 112 "parser.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival); ;}
    break;

  case 13:
#line 113 "parser.y"
    { 
        char msg[128];
        snprintf(msg, sizeof(msg), "Explaining variable '%s'", (yyvsp[(3) - (5)].sval));
        explain_with_llm(msg);
        print_var((yyvsp[(3) - (5)].sval));
        free((yyvsp[(3) - (5)].sval));
        (yyval.ival) = 1;
    ;}
    break;

  case 14:
#line 124 "parser.y"
    {
        declare_var((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).type);
        set_var_value((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).value.ival, (yyvsp[(4) - (4)].expr_val).value.fval, (yyvsp[(4) - (4)].expr_val).value.bval);
        
        printf("Declared %s : ", (yyvsp[(2) - (4)].sval));
        if ((yyvsp[(4) - (4)].expr_val).type == VAR_INT) printf("%d\n", (yyvsp[(4) - (4)].expr_val).value.ival);
        else if ((yyvsp[(4) - (4)].expr_val).type == VAR_FLOAT) printf("%.2f\n", (yyvsp[(4) - (4)].expr_val).value.fval);
        else printf("%s\n", (yyvsp[(4) - (4)].expr_val).value.bval ? "true" : "false");
        
        if (debug_mode) explain_with_llm("Variable declaration");
        free((yyvsp[(2) - (4)].sval));
    ;}
    break;

  case 15:
#line 136 "parser.y"
    {
        declare_var((yyvsp[(2) - (4)].sval), VAR_INT);
        set_var_value((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).value.ival, 0, 0);
        printf("Declared int %s : %d\n", (yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).value.ival);
        free((yyvsp[(2) - (4)].sval));
    ;}
    break;

  case 16:
#line 142 "parser.y"
    {
        declare_var((yyvsp[(2) - (4)].sval), VAR_FLOAT);
        set_var_value((yyvsp[(2) - (4)].sval), 0, (yyvsp[(4) - (4)].expr_val).value.fval, 0);
        printf("Declared float %s : %.2f\n", (yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).value.fval);
        free((yyvsp[(2) - (4)].sval));
    ;}
    break;

  case 17:
#line 148 "parser.y"
    {
        declare_var((yyvsp[(2) - (4)].sval), VAR_BOOL);
        set_var_value((yyvsp[(2) - (4)].sval), 0, 0, (yyvsp[(4) - (4)].expr_val).value.bval);
        printf("Declared bool %s : %s\n", (yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].expr_val).value.bval ? "true" : "false");
        free((yyvsp[(2) - (4)].sval));
    ;}
    break;

  case 18:
#line 157 "parser.y"
    {
        Var* v = find_var((yyvsp[(1) - (3)].sval));
        if (!v) {
            fprintf(stderr, "Error: Variable '%s' not declared\n", (yyvsp[(1) - (3)].sval));
            exit(1);
        }
        set_var_value((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].expr_val).value.ival, (yyvsp[(3) - (3)].expr_val).value.fval, (yyvsp[(3) - (3)].expr_val).value.bval);
        printf("Assigned %s\n", (yyvsp[(1) - (3)].sval));
        free((yyvsp[(1) - (3)].sval));
    ;}
    break;

  case 19:
#line 170 "parser.y"
    {
        if ((yyvsp[(3) - (5)].expr_val).value.bval) {
            printf("If condition true - executing then branch\n");
            if (debug_mode) explain_with_llm("If condition evaluated to true");
        } else {
            printf("If condition false - skipping then branch\n");
        }
    ;}
    break;

  case 20:
#line 178 "parser.y"
    {
        if ((yyvsp[(3) - (7)].expr_val).value.bval) {
            printf("If condition true - executing then branch\n");
        } else {
            printf("If condition false - executing else branch\n");
        }
        if (debug_mode) explain_with_llm("If-else statement executed");
    ;}
    break;

  case 21:
#line 189 "parser.y"
    {
        printf("While loop executed\n");
        if (debug_mode) explain_with_llm("While loop iteration");
    ;}
    break;

  case 22:
#line 196 "parser.y"
    {
        printf("For loop executed\n");
        if (debug_mode) explain_with_llm("For loop iteration");
    ;}
    break;

  case 23:
#line 203 "parser.y"
    {
        printf("Output: ");
        if ((yyvsp[(3) - (4)].expr_val).type == VAR_INT) printf("%d\n", (yyvsp[(3) - (4)].expr_val).value.ival);
        else if ((yyvsp[(3) - (4)].expr_val).type == VAR_FLOAT) printf("%.2f\n", (yyvsp[(3) - (4)].expr_val).value.fval);
        else printf("%s\n", (yyvsp[(3) - (4)].expr_val).value.bval ? "true" : "false");
    ;}
    break;

  case 24:
#line 213 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 25:
#line 217 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 26:
#line 218 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        (yyval.expr_val).value.bval = (yyvsp[(1) - (3)].expr_val).value.bval || (yyvsp[(3) - (3)].expr_val).value.bval;
        if (debug_mode) explain_with_llm("Logical OR operation");
    ;}
    break;

  case 27:
#line 226 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 28:
#line 227 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        (yyval.expr_val).value.bval = (yyvsp[(1) - (3)].expr_val).value.bval && (yyvsp[(3) - (3)].expr_val).value.bval;
        if (debug_mode) explain_with_llm("Logical AND operation");
    ;}
    break;

  case 29:
#line 235 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 30:
#line 236 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival == (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 == v2);
        }
    ;}
    break;

  case 31:
#line 246 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival != (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 != v2);
        }
    ;}
    break;

  case 32:
#line 259 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 33:
#line 260 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival < (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 < v2);
        }
    ;}
    break;

  case 34:
#line 270 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival > (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 > v2);
        }
    ;}
    break;

  case 35:
#line 280 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival <= (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 <= v2);
        }
    ;}
    break;

  case 36:
#line 290 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).value.bval = ((yyvsp[(1) - (3)].expr_val).value.ival >= (yyvsp[(3) - (3)].expr_val).value.ival);
        } else {
            float v1 = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval);
            float v2 = ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
            (yyval.expr_val).value.bval = (v1 >= v2);
        }
    ;}
    break;

  case 37:
#line 303 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 38:
#line 304 "parser.y"
    {
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).type = VAR_INT;
            (yyval.expr_val).value.ival = (yyvsp[(1) - (3)].expr_val).value.ival + (yyvsp[(3) - (3)].expr_val).value.ival;
        } else {
            (yyval.expr_val).type = VAR_FLOAT;
            (yyval.expr_val).value.fval = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval) + 
                           ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
        }
        if (debug_mode) explain_with_llm("Addition operation");
    ;}
    break;

  case 39:
#line 315 "parser.y"
    {
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).type = VAR_INT;
            (yyval.expr_val).value.ival = (yyvsp[(1) - (3)].expr_val).value.ival - (yyvsp[(3) - (3)].expr_val).value.ival;
        } else {
            (yyval.expr_val).type = VAR_FLOAT;
            (yyval.expr_val).value.fval = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval) - 
                           ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
        }
        if (debug_mode) explain_with_llm("Subtraction operation");
    ;}
    break;

  case 40:
#line 329 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 41:
#line 330 "parser.y"
    {
        if ((yyvsp[(1) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).type == VAR_INT) {
            (yyval.expr_val).type = VAR_INT;
            (yyval.expr_val).value.ival = (yyvsp[(1) - (3)].expr_val).value.ival * (yyvsp[(3) - (3)].expr_val).value.ival;
        } else {
            (yyval.expr_val).type = VAR_FLOAT;
            (yyval.expr_val).value.fval = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval) * 
                           ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
        }
        if (debug_mode) explain_with_llm("Multiplication operation");
    ;}
    break;

  case 42:
#line 341 "parser.y"
    {
        if (((yyvsp[(3) - (3)].expr_val).type == VAR_INT && (yyvsp[(3) - (3)].expr_val).value.ival == 0) || 
            ((yyvsp[(3) - (3)].expr_val).type == VAR_FLOAT && (yyvsp[(3) - (3)].expr_val).value.fval == 0.0)) {
            fprintf(stderr, "Error: Division by zero\n");
            exit(1);
        }
        (yyval.expr_val).type = VAR_FLOAT;
        (yyval.expr_val).value.fval = ((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval) / 
                       ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval);
        if (debug_mode) explain_with_llm("Division operation");
    ;}
    break;

  case 43:
#line 352 "parser.y"
    {
        if ((yyvsp[(1) - (3)].expr_val).type != VAR_INT || (yyvsp[(3) - (3)].expr_val).type != VAR_INT) {
            fprintf(stderr, "Error: Modulo requires integers\n");
            exit(1);
        }
        if ((yyvsp[(3) - (3)].expr_val).value.ival == 0) {
            fprintf(stderr, "Error: Modulo by zero\n");
            exit(1);
        }
        (yyval.expr_val).type = VAR_INT;
        (yyval.expr_val).value.ival = (yyvsp[(1) - (3)].expr_val).value.ival % (yyvsp[(3) - (3)].expr_val).value.ival;
        if (debug_mode) explain_with_llm("Modulo operation");
    ;}
    break;

  case 44:
#line 368 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 45:
#line 369 "parser.y"
    {
        (yyval.expr_val).type = VAR_FLOAT;
        (yyval.expr_val).value.fval = pow(((yyvsp[(1) - (3)].expr_val).type == VAR_INT ? (yyvsp[(1) - (3)].expr_val).value.ival : (yyvsp[(1) - (3)].expr_val).value.fval),
                           ((yyvsp[(3) - (3)].expr_val).type == VAR_INT ? (yyvsp[(3) - (3)].expr_val).value.ival : (yyvsp[(3) - (3)].expr_val).value.fval));
        if (debug_mode) explain_with_llm("Exponentiation operation");
    ;}
    break;

  case 46:
#line 378 "parser.y"
    { (yyval.expr_val) = (yyvsp[(1) - (1)].expr_val); ;}
    break;

  case 47:
#line 379 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        (yyval.expr_val).value.bval = !(yyvsp[(2) - (2)].expr_val).value.bval;
        if (debug_mode) explain_with_llm("Logical NOT operation");
    ;}
    break;

  case 48:
#line 384 "parser.y"
    {
        if ((yyvsp[(2) - (2)].expr_val).type == VAR_INT) {
            (yyval.expr_val).type = VAR_INT;
            (yyval.expr_val).value.ival = -(yyvsp[(2) - (2)].expr_val).value.ival;
        } else {
            (yyval.expr_val).type = VAR_FLOAT;
            (yyval.expr_val).value.fval = -((yyvsp[(2) - (2)].expr_val).type == VAR_INT ? (yyvsp[(2) - (2)].expr_val).value.ival : (yyvsp[(2) - (2)].expr_val).value.fval);
        }
        if (debug_mode) explain_with_llm("Unary minus operation");
    ;}
    break;

  case 49:
#line 397 "parser.y"
    {
        Var* v = find_var((yyvsp[(1) - (1)].sval));
        if (!v) {
            fprintf(stderr, "Error: Variable '%s' not declared\n", (yyvsp[(1) - (1)].sval));
            exit(1);
        }
        (yyval.expr_val).type = v->type;
        // Fix: Assign union values field by field instead of entire union
        switch (v->type) {
            case VAR_INT:
                (yyval.expr_val).value.ival = v->value.ival;
                break;
            case VAR_FLOAT:
                (yyval.expr_val).value.fval = v->value.fval;
                break;
            case VAR_BOOL:
                (yyval.expr_val).value.bval = v->value.bval;
                break;
        }
        free((yyvsp[(1) - (1)].sval));
    ;}
    break;

  case 50:
#line 418 "parser.y"
    {
        (yyval.expr_val).type = VAR_INT;
        (yyval.expr_val).value.ival = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 51:
#line 422 "parser.y"
    {
        (yyval.expr_val).type = VAR_FLOAT;
        (yyval.expr_val).value.fval = (yyvsp[(1) - (1)].fval);
    ;}
    break;

  case 52:
#line 426 "parser.y"
    {
        (yyval.expr_val).type = VAR_BOOL;
        (yyval.expr_val).value.bval = (yyvsp[(1) - (1)].ival);
    ;}
    break;

  case 53:
#line 430 "parser.y"
    {
        (yyval.expr_val) = (yyvsp[(2) - (3)].expr_val);
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2057 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 435 "parser.y"


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
