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
     ARRAY = 261,
     OF = 262,
     IF = 263,
     THEN = 264,
     ENDIF = 265,
     ELSE = 266,
     WHILE = 267,
     LOOP = 268,
     ENDLOOP = 269,
     READ = 270,
     WRITE = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     TRUE = 275,
     FALSE = 276,
     ADD = 277,
     SUB = 278,
     MULT = 279,
     DIV = 280,
     EQ = 281,
     NEQ = 282,
     LT = 283,
     GT = 284,
     LTE = 285,
     GTE = 286,
     SEMICOLON = 287,
     COLON = 288,
     COMMA = 289,
     L_PAREN = 290,
     R_PAREN = 291,
     ASSIGN = 292,
     INTEGER = 293,
     NUMBER = 294,
     IDENT = 295,
     USUB = 296
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define BEGIN_PROGRAM 259
#define END_PROGRAM 260
#define ARRAY 261
#define OF 262
#define IF 263
#define THEN 264
#define ENDIF 265
#define ELSE 266
#define WHILE 267
#define LOOP 268
#define ENDLOOP 269
#define READ 270
#define WRITE 271
#define AND 272
#define OR 273
#define NOT 274
#define TRUE 275
#define FALSE 276
#define ADD 277
#define SUB 278
#define MULT 279
#define DIV 280
#define EQ 281
#define NEQ 282
#define LT 283
#define GT 284
#define LTE 285
#define GTE 286
#define SEMICOLON 287
#define COLON 288
#define COMMA 289
#define L_PAREN 290
#define R_PAREN 291
#define ASSIGN 292
#define INTEGER 293
#define NUMBER 294
#define IDENT 295
#define USUB 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 27 "project2.y"
{
  int		ival;
  char*		idval;
}
/* Line 1529 of yacc.c.  */
#line 136 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

