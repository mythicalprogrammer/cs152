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
     PROGRAM = 258,
     BEGIN_PROGRAM = 259,
     END_PROGRAM = 260,
     OF = 261,
     IF = 262,
     THEN = 263,
     ENDIF = 264,
     ELSE = 265,
     WHILE = 266,
     LOOP = 267,
     ENDLOOP = 268,
     READ = 269,
     WRITE = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     TRUE = 274,
     FALSE = 275,
     ADD = 276,
     SUB = 277,
     MULT = 278,
     DIV = 279,
     EQ = 280,
     NEQ = 281,
     LT = 282,
     GT = 283,
     LTE = 284,
     GTE = 285,
     SEMICOLON = 286,
     COLON = 287,
     COMMA = 288,
     L_PAREN = 289,
     R_PAREN = 290,
     ASSIGN = 291,
     NUMBER = 292,
     IDENT = 293,
     INTEGER = 294,
     ARRAY = 295
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define BEGIN_PROGRAM 259
#define END_PROGRAM 260
#define OF 261
#define IF 262
#define THEN 263
#define ENDIF 264
#define ELSE 265
#define WHILE 266
#define LOOP 267
#define ENDLOOP 268
#define READ 269
#define WRITE 270
#define AND 271
#define OR 272
#define NOT 273
#define TRUE 274
#define FALSE 275
#define ADD 276
#define SUB 277
#define MULT 278
#define DIV 279
#define EQ 280
#define NEQ 281
#define LT 282
#define GT 283
#define LTE 284
#define GTE 285
#define SEMICOLON 286
#define COLON 287
#define COMMA 288
#define L_PAREN 289
#define R_PAREN 290
#define ASSIGN 291
#define NUMBER 292
#define IDENT 293
#define INTEGER 294
#define ARRAY 295




/* Copy the first part of user declarations.  */
#line 10 "project2.y"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
using namespace std;

void yyerror(const char * msg);
void init_symbolTable();
void addSymbolTable(string name, int type);
void AddIdentifierList(string var1);
void addSymbolTable2(int type);
string newLabel();
string newTemp();
string newP();

extern unsigned int line;
extern unsigned int currPos;
extern char* yytext;
extern char* ID;
extern int yylex();
extern FILE * yyin;

vector<string> buffer;
vector<string> tempBuffer;
vector<string> l;



struct symStruct{
int type;
string name;
};

struct divStruct{
string type;
string fact1;
string fact2;
};

vector<string> addBuffer;
vector<string> subBuffer;
vector<string> multBuffer;
vector<divStruct> divBuffer;


unsigned int labelCounter = 0;
unsigned int tempCounter = 0;
unsigned int pCounter = 0;
int flagTemp = 0;
int flagAdd = 0;
int flagDiv = 0;
int flagBool = 0;
vector<symStruct> symbolTable;
 




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "project2.y"
{
  int	ival;
  char*	idval;
}
/* Line 193 of yacc.c.  */
#line 243 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 256 "y.tab.c"

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
# if YYENABLE_NLS
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   111

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  115

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     5,    13,    14,    19,    20,    25,
      28,    29,    34,    37,    42,    52,    53,    58,    59,    61,
      65,    69,    75,    83,    84,    85,    93,    96,    99,   102,
     104,   108,   111,   115,   118,   122,   124,   126,   131,   134,
     137,   139,   141,   143,   145,   147,   149,   153,   156,   160,
     164,   165,   167,   170,   174,   177,   181,   184,   186,   188,
     192,   194,   196
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    -1,    -1,     3,    38,    43,    31,    44,
      45,     5,    -1,    -1,    47,     4,    46,    49,    -1,    -1,
      51,    31,    48,    47,    -1,    51,    31,    -1,    -1,    55,
      31,    50,    49,    -1,    55,    31,    -1,    38,    52,    32,
      39,    -1,    38,    52,    32,    40,    34,    67,    35,     6,
      39,    -1,    -1,    33,    38,    53,    52,    -1,    -1,    68,
      -1,    68,    33,    54,    -1,    68,    36,    62,    -1,     7,
      58,     8,    49,     9,    -1,     7,    58,     8,    49,    10,
      49,     9,    -1,    -1,    -1,    11,    56,    58,    57,    12,
      49,    13,    -1,    14,    54,    -1,    15,    54,    -1,    60,
      59,    -1,    60,    -1,    16,    60,    59,    -1,    16,    60,
      -1,    17,    60,    59,    -1,    17,    60,    -1,    62,    61,
      62,    -1,    19,    -1,    20,    -1,    18,    62,    61,    62,
      -1,    18,    19,    -1,    18,    20,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,    22,
      64,    63,    -1,    64,    63,    -1,    21,    64,    63,    -1,
      22,    64,    63,    -1,    -1,    66,    -1,    66,    65,    -1,
      23,    66,    65,    -1,    23,    66,    -1,    24,    66,    65,
      -1,    24,    66,    -1,    68,    -1,    67,    -1,    34,    62,
      35,    -1,    37,    -1,    38,    -1,    38,    34,    62,    35,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   109,   109,   109,   109,   112,   112,   118,   118,   119,
     122,   122,   123,   126,   140,   161,   161,   167,   171,   172,
     174,   200,   201,   203,   212,   202,   234,   240,   243,   244,
     247,   248,   249,   250,   253,   312,   313,   314,   315,   316,
     319,   320,   321,   322,   323,   324,   327,   336,   383,   386,
     387,   390,   391,   424,   425,   426,   427,   430,   431,   432,
     435,   440,   446
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BEGIN_PROGRAM",
  "END_PROGRAM", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "LOOP",
  "ENDLOOP", "READ", "WRITE", "AND", "OR", "NOT", "TRUE", "FALSE", "ADD",
  "SUB", "MULT", "DIV", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON",
  "COLON", "COMMA", "L_PAREN", "R_PAREN", "ASSIGN", "NUMBER", "IDENT",
  "INTEGER", "ARRAY", "$accept", "Program", "@1", "@2", "Block", "@3",
  "BlockDeclarationLoop", "@4", "BlockStatmentLoop", "@5", "Declaration",
  "declaration2", "@6", "varloop", "Statement", "@7", "@8", "Bool_Exp",
  "Bool_ExpLoop", "Relation_Exp", "Comp", "Expression", "ExpressionLoop",
  "Term", "TermLoop", "Factor", "number", "Var", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    43,    44,    42,    46,    45,    48,    47,    47,
      50,    49,    49,    51,    51,    53,    52,    52,    54,    54,
      55,    55,    55,    56,    57,    55,    55,    55,    58,    58,
      59,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      67,    68,    68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     7,     0,     4,     0,     4,     2,
       0,     4,     2,     4,     9,     0,     4,     0,     1,     3,
       3,     5,     7,     0,     0,     7,     2,     2,     2,     1,
       3,     2,     3,     2,     3,     1,     1,     4,     2,     2,
       1,     1,     1,     1,     1,     1,     3,     2,     3,     3,
       0,     1,     2,     3,     2,     3,     2,     1,     1,     3,
       1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     3,     0,    17,     0,
       0,     0,     0,     0,     4,     5,     7,    15,     0,     0,
       0,    17,    13,     0,     0,    23,     0,     0,    61,     6,
       0,     0,     8,    16,     0,     0,    35,    36,     0,     0,
      60,     0,    29,     0,    50,    51,    58,    57,     0,    26,
      18,    27,     0,    10,     0,     0,    38,    39,     0,    50,
       0,     0,     0,     0,    28,    40,    41,    42,    43,    44,
      45,     0,     0,     0,    47,     0,     0,    52,    24,     0,
       0,     0,    20,     0,     0,    46,    59,     0,    31,    33,
      34,    50,    50,    54,    56,     0,    19,    62,    11,     0,
      37,    21,     0,    30,    32,    48,    49,    53,    55,     0,
      14,     0,     0,    22,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     7,     9,    19,    10,    20,    29,    81,
      11,    13,    21,    49,    30,    48,    95,    41,    64,    42,
      71,    43,    74,    44,    77,    45,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int8 yypact[] =
{
       2,   -22,    20,   -58,   -58,    -3,   -58,   -15,    -1,    43,
      55,    53,    25,    18,   -58,   -58,    85,   -58,     0,     3,
     -15,    -1,   -58,    57,    -7,   -58,    54,    54,    59,   -58,
      63,    60,   -58,   -58,    58,    27,   -58,   -58,   -12,    32,
     -58,    89,    39,    46,    36,    44,   -58,   -58,    -7,   -58,
      65,   -58,    32,    24,    32,    64,   -58,   -58,    46,    36,
      66,     3,    -7,    -7,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,    32,   -12,   -12,   -58,   -12,   -12,   -58,   -58,    54,
      67,     3,   -58,    94,    32,   -58,   -58,    68,    39,    39,
     -58,    36,    36,    44,    44,    91,   -58,   -58,   -58,    69,
     -58,   -58,     3,   -58,   -58,   -58,   -58,   -58,   -58,     3,
     -58,    95,    92,   -58,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,    86,   -58,   -57,   -58,
     -58,    88,   -58,   -26,   -58,   -58,   -58,    62,    -9,    19,
      49,   -33,   -56,   -29,    -8,    12,    77,   -19
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -13
static const yytype_int8 yytable[] =
{
      31,    51,    58,    85,    87,     1,    60,    50,    50,    59,
      24,    35,    36,    37,    25,    38,     3,    26,    27,    80,
       4,    82,    39,     8,    98,    40,    28,    39,     6,   -12,
      40,    28,    12,   -12,   -12,   105,   106,   -12,    90,    22,
      23,    28,    31,    91,    92,   111,    56,    57,    14,    38,
      18,   100,   112,    96,    38,    62,    63,    72,    73,    15,
      50,    39,    31,    17,    40,    28,    39,    75,    76,    40,
      28,    65,    66,    67,    68,    69,    70,   101,   102,   103,
     104,    88,    89,    31,    16,   107,   108,    93,    94,    -9,
      31,    34,    28,    52,    53,    40,    54,    61,    79,    83,
      99,    86,    97,   109,   113,   114,    32,    84,   110,    33,
      78,    55
};

static const yytype_uint8 yycheck[] =
{
      19,    27,    35,    59,    61,     3,    39,    26,    27,    38,
       7,    18,    19,    20,    11,    22,    38,    14,    15,    52,
       0,    54,    34,    38,    81,    37,    38,    34,    31,     5,
      37,    38,    33,     9,    10,    91,    92,    13,    71,    39,
      40,    38,    61,    72,    73,   102,    19,    20,     5,    22,
      32,    84,   109,    79,    22,    16,    17,    21,    22,     4,
      79,    34,    81,    38,    37,    38,    34,    23,    24,    37,
      38,    25,    26,    27,    28,    29,    30,     9,    10,    88,
      89,    62,    63,   102,    31,    93,    94,    75,    76,     4,
     109,    34,    38,    34,    31,    37,    36,     8,    33,    35,
       6,    35,    35,    12,     9,    13,    20,    58,    39,    21,
      48,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    38,     0,    43,    31,    44,    38,    45,
      47,    51,    33,    52,     5,     4,    31,    38,    32,    46,
      48,    53,    39,    40,     7,    11,    14,    15,    38,    49,
      55,    68,    47,    52,    34,    18,    19,    20,    22,    34,
      37,    58,    60,    62,    64,    66,    67,    68,    56,    54,
      68,    54,    34,    31,    36,    67,    19,    20,    62,    64,
      62,     8,    16,    17,    59,    25,    26,    27,    28,    29,
      30,    61,    21,    22,    63,    23,    24,    65,    58,    33,
      62,    50,    62,    35,    61,    63,    35,    49,    60,    60,
      62,    64,    64,    66,    66,    57,    54,    35,    49,     6,
      62,     9,    10,    59,    59,    63,    63,    65,    65,    12,
      39,    49,    49,     9,    13
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
# if YYLTYPE_IS_TRIVIAL
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
#line 109 "project2.y"
    {addSymbolTable((yyvsp[(2) - (2)].idval),1);;}
    break;

  case 3:
#line 109 "project2.y"
    {flagTemp = 1;;}
    break;

  case 5:
#line 112 "project2.y"
    {
		                                              string temp =  ": START";
							      buffer.push_back(temp);
                                                            ;}
    break;

  case 7:
#line 118 "project2.y"
    {flagTemp = 1;;}
    break;

  case 9:
#line 119 "project2.y"
    {flagTemp = 1;;}
    break;

  case 10:
#line 122 "project2.y"
    {flagTemp = 1;;}
    break;

  case 11:
#line 122 "project2.y"
    {    ;}
    break;

  case 12:
#line 123 "project2.y"
    {flagTemp = 1;;}
    break;

  case 13:
#line 126 "project2.y"
    { 	
							        string temp (yyvsp[(1) - (4)].idval);								

								l.push_back(temp);
                                                                string add = ". _";
			                                        for(int i=0; i < l.size(); ++i)
		                                                {
                                                                  temp = add+l[i];
                                                                  addSymbolTable(temp,0);
		                                                }
			                                        l.clear();
                                      

							  ;}
    break;

  case 14:
#line 141 "project2.y"
    {
				
				  string temp = (yyvsp[(1) - (9)].idval);
			          l.push_back(temp);

				  string add = ".[] _";
				   string arrayNumber = (yyvsp[(6) - (9)].idval);



			          for(int i=0; i < l.size(); ++i)
			          {
                                    temp = add+l[i]+", " +arrayNumber;
                                    addSymbolTable(temp,4);
			          }
			          l.clear();				  
                                ;}
    break;

  case 15:
#line 161 "project2.y"
    {   

				       string temp = (yyvsp[(2) - (2)].idval);
				       l.push_back((yyvsp[(2) - (2)].idval));

                                     ;}
    break;

  case 16:
#line 166 "project2.y"
    {;}
    break;

  case 17:
#line 167 "project2.y"
    {(yyval.idval)=NULL;;}
    break;

  case 18:
#line 171 "project2.y"
    {(yyval.idval)=(yyvsp[(1) - (1)].idval);;}
    break;

  case 19:
#line 172 "project2.y"
    {;}
    break;

  case 20:
#line 174 "project2.y"
    {

						if((yyvsp[(1) - (3)].idval) != NULL && (yyvsp[(3) - (3)].idval) != NULL)
                                                {
					          string t2 = (yyvsp[(3) - (3)].idval);
						  string t1 = (yyvsp[(1) - (3)].idval);

                                                  

   if(flagTemp == 1)
{                                   
  stringstream out;
  int curTemp = tempCounter - 1;
  out << curTemp;
  t2 = "t"+out.str();
}				                    

						  t1 = "= "+t1+", "+t2;
						  buffer.push_back(t1);
                                                  flagTemp = 0;

						}



					      ;}
    break;

  case 21:
#line 200 "project2.y"
    {flagTemp = 0;;}
    break;

  case 22:
#line 201 "project2.y"
    {flagTemp = 0;;}
    break;

  case 23:
#line 203 "project2.y"
    {
				  string temp = newLabel();
                                      
			   	  buffer.push_back(temp); //pushing LABEL
				 // $<idval>$=const_cast<char *>(temp.c_str());
 
				  /*l_1 = newlabel(); genCode('label', l_1, 0, 0); $<sval>$=l_1;*/
				;}
    break;

  case 24:
#line 212 "project2.y"
    {
			      
				 
				;}
    break;

  case 25:
#line 217 "project2.y"
    {
						   
		
  int currCounter = labelCounter - 1;			

  stringstream out;
  out << currCounter;
  string temp = ":= L"+out.str();


			   	                   buffer.push_back(temp);
				                   temp = newLabel();
			   	                   buffer.push_back(temp); //pushing LABEL
flagTemp = 0;
flagBool = 0;
			         
                                                 ;}
    break;

  case 26:
#line 235 "project2.y"
    { 
					string temp2 = (yyvsp[(2) - (2)].idval);
					string temp = ".< "+temp2; 
					buffer.push_back(temp);
				      ;}
    break;

  case 27:
#line 240 "project2.y"
    {;}
    break;

  case 28:
#line 243 "project2.y"
    {;}
    break;

  case 29:
#line 244 "project2.y"
    { ;}
    break;

  case 30:
#line 247 "project2.y"
    {;}
    break;

  case 31:
#line 248 "project2.y"
    {;}
    break;

  case 32:
#line 249 "project2.y"
    {;}
    break;

  case 33:
#line 250 "project2.y"
    {;}
    break;

  case 34:
#line 254 "project2.y"
    {




			              if ((yyvsp[(1) - (3)].idval) != NULL ) 
				      {
                                        string exp2;






flagBool = 1;

  int curTemp = tempCounter - 1 ; 
  string realTemp;
  stringstream in;
  in << curTemp;
   realTemp = in.str();
   exp2 = "t"+realTemp;



				         string comp = (yyvsp[(2) - (3)].idval);
                                         string exp1 = (yyvsp[(1) - (3)].idval);

					 
 
   if(flagTemp==0)
    exp2 =(yyvsp[(3) - (3)].idval);
  
                                         
					 string plabel = newP(); 


					 string temp = comp+" "+plabel+", "+exp1+", "+exp2;
					 buffer.push_back(temp);
					 
					 string anotherP = newP();
					 temp = "== "+anotherP+", "+plabel+", 0";
					 buffer.push_back(temp);
					 
					
  string int2str;
  stringstream out;
  out << labelCounter;
  int2str = out.str();
  string exitLoop = "L"+int2str;
  temp = "?:= "+exitLoop+", "+anotherP;
					 buffer.push_back(temp);
                                         
                                      }
				     
			             

			            ;}
    break;

  case 35:
#line 312 "project2.y"
    {;}
    break;

  case 36:
#line 313 "project2.y"
    {;}
    break;

  case 37:
#line 314 "project2.y"
    {;}
    break;

  case 38:
#line 315 "project2.y"
    {;}
    break;

  case 39:
#line 316 "project2.y"
    {;}
    break;

  case 40:
#line 319 "project2.y"
    {(yyval.idval)="==";;}
    break;

  case 41:
#line 320 "project2.y"
    {(yyval.idval)="!=";;}
    break;

  case 42:
#line 321 "project2.y"
    {(yyval.idval)="<";;}
    break;

  case 43:
#line 322 "project2.y"
    {(yyval.idval)=">";;}
    break;

  case 44:
#line 323 "project2.y"
    {(yyval.idval)="<=";;}
    break;

  case 45:
#line 324 "project2.y"
    {(yyval.idval)=">=";;}
    break;

  case 46:
#line 328 "project2.y"
    { 
                            if((yyvsp[(2) - (3)].idval) !=NULL)
                             {
			    string temp = (yyvsp[(2) - (3)].idval);
			    temp = "-"+temp;
			    (yyval.idval) = const_cast<char *>(temp.c_str());
                             }
			  ;}
    break;

  case 47:
#line 337 "project2.y"
    {
				
                            if((yyvsp[(2) - (2)].idval) == NULL && flagBool == 0)
			      flagTemp = 0;
			    else if( flagBool == 1)
			      flagTemp = 1;
                     
                             if((yyvsp[(2) - (2)].idval) !=NULL)
                            {
			      string add;
                              
                              if(flagAdd == 1)
                               add = "+ ";
                              else
                               add = "- ";

                              (yyval.idval)=(yyvsp[(2) - (2)].idval);

                              string t1 = (yyvsp[(1) - (2)].idval);
                              string t2;
if(flagTemp == 1)
{
  
  stringstream out;
  int curTemp = tempCounter - 1;
  out << curTemp;
  t2 = "t"+out.str();

  
}	
else
                              t2 = (yyvsp[(2) - (2)].idval);
			      string tlabel = newTemp();
                              string temp = add+tlabel+", "+t1+", "+t2;

			      buffer.push_back(temp);
			      flagAdd = 0;
                             }

	  	      


			    
			  ;}
    break;

  case 48:
#line 383 "project2.y"
    { flagAdd = 1;
						  (yyval.idval)=(yyvsp[(2) - (3)].idval);
                                                ;}
    break;

  case 49:
#line 386 "project2.y"
    {flagAdd = 0;  (yyval.idval)=(yyvsp[(2) - (3)].idval);;}
    break;

  case 50:
#line 387 "project2.y"
    {(yyval.idval)=NULL;;}
    break;

  case 51:
#line 390 "project2.y"
    {(yyval.idval)=(yyvsp[(1) - (1)].idval);;}
    break;

  case 52:
#line 391 "project2.y"
    { 
					       if ((yyvsp[(2) - (2)].idval) !=NULL && (yyvsp[(1) - (2)].idval) !=NULL)
                                               {  
                                                  string fact_1;                                               

                                                  if(flagTemp == 0)
						    fact_1 = (yyvsp[(1) - (2)].idval);
						  else
 {
  stringstream out;
  int curTemp = tempCounter - 1;
  out << curTemp;
  fact_1 = "t"+out.str();
 }
						   string fact_2 = (yyvsp[(2) - (2)].idval);
						   string type;
 
					   if(flagDiv==0)
                                             type = "*";
					   else
					     type = "/";

					           
                                         string tlabel = newTemp();

					 string temp2 = type+" "+tlabel+", "+fact_1+", "+fact_2;
					 buffer.push_back(temp2);
 flagTemp = 1;
                                                }
					     
					   ;}
    break;

  case 53:
#line 424 "project2.y"
    {(yyval.idval) =(yyvsp[(2) - (3)].idval);flagDiv = 0;;}
    break;

  case 54:
#line 425 "project2.y"
    {(yyval.idval) = (yyvsp[(2) - (2)].idval);flagDiv = 0;;}
    break;

  case 55:
#line 426 "project2.y"
    {(yyval.idval)=(yyvsp[(2) - (3)].idval);flagDiv = 1;;}
    break;

  case 56:
#line 427 "project2.y"
    {(yyval.idval) = (yyvsp[(2) - (2)].idval);flagDiv = 1;;}
    break;

  case 57:
#line 430 "project2.y"
    {(yyval.idval)=(yyvsp[(1) - (1)].idval);;}
    break;

  case 58:
#line 431 "project2.y"
    {(yyval.idval)=(yyvsp[(1) - (1)].idval);;}
    break;

  case 59:
#line 432 "project2.y"
    {(yyval.idval)=(yyvsp[(2) - (3)].idval);;}
    break;

  case 60:
#line 435 "project2.y"
    {
                                   string add = (yyvsp[(1) - (1)].idval);
                                strcpy((yyval.idval),add.c_str());
			       ;}
    break;

  case 61:
#line 440 "project2.y"
    { 
	                        string add = (yyvsp[(1) - (1)].idval);				
                                string temp = "_"+add;
                                strcpy((yyval.idval),temp.c_str());
                                //$$=const_cast<char *>(temp.c_str());
			      ;}
    break;

  case 62:
#line 446 "project2.y"
    {(yyval.idval)=(yyvsp[(1) - (4)].idval); flagTemp = 1;;}
    break;


/* Line 1267 of yacc.c.  */
#line 2083 "y.tab.c"
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


#line 449 "project2.y"





int main() {

 
init_symbolTable();	
yyparse();
for(int i = 21; i < symbolTable.size(); ++i)
{
cout << symbolTable[i].name <<endl;
} 

for(int i = 0; i < buffer.size(); ++i)
{
cout << buffer[i]<<endl;
} 


///*Debugger Symbol Table
/*
for(int i = 0; i < symbolTable.size(); ++i)
{
cout << "Name: "<< symbolTable[i].name << " Type: " << symbolTable[i].type <<endl;
} 
*/

return 0;
}

string newTemp()
{
  string int2str;
  stringstream out;
  out << tempCounter;
  int2str = out.str();
  string temp = "t"+int2str;
  ++tempCounter;
  return temp;
}

string newP()
{
  string int2str;
  stringstream out;
  out << pCounter;
  int2str = out.str();
  string temp = "p"+int2str;
  ++pCounter;
  return temp;
}

string newLabel()
{
  string int2str;
  stringstream out;
  out << labelCounter;
  int2str = out.str();
  string temp = ": L"+int2str;
  ++labelCounter;
  return temp;
}

void AddIdentifierList(string var1)
{
l.push_back(var1);
buffer.push_back(var1);
}


void yyerror(const char* msg)
{
	printf("** Line %d, position %d: %s\n", line, currPos, msg);
}

void addSymbolTable(string name, int type)
{
symStruct temp;
temp.type = type;
temp.name = name;
symbolTable.push_back(temp);

}

void addSymbolTable2(int type)
{
string name;
symStruct temp;
int i;

for(i=0; i < l.size(); ++i)
{
  name = l[i];
  temp.type = type;
  temp.name = name;
  symbolTable.push_back(temp);
 }
l.clear();
}

void init_symbolTable()
{

//type
// -2 = reserved
//  0 = integer
//  1 = program name
//  4 = array
symStruct temp;
temp.type =-2;
temp.name = "program";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "beginprogram";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "endprogram";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "integer";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "array";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "of";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "if";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "then";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "endif";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "else";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "while";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "loop";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "endloop";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "read";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "write";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "and";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "or";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "not";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "true";
symbolTable.push_back(temp);

temp.type =-2;
temp.name = "false";
symbolTable.push_back(temp);
//cout << symbolTable.size()<<endl;
}

