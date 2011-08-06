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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 72 "project2.y"
{
  int	ival;
  char*	idval;
}
/* Line 1529 of yacc.c.  */
#line 134 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

