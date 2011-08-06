/* 
 * Description: Parser
 *
 * cs152: Project 2
 * Student: Quoc Anh Doan
 * ID: 860759993
 * UN: qdoan
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void yyerror(const char * msg);
extern unsigned int line;
extern unsigned int currPos;
extern char* yytext;
extern char* ID;
extern int yylex();
extern FILE * yyin;


%}

%union{
  int		ival;
  char*		idval;
}

%error-verbose
//%start	input 
%token PROGRAM BEGIN_PROGRAM END_PROGRAM ARRAY OF IF THEN ENDIF ELSE WHILE LOOP ENDLOOP READ WRITE AND OR NOT TRUE FALSE ADD SUB MULT DIV EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN INTEGER
%token	<ival>	NUMBER 
%type	<ival>	Expression 
%token	<idval>	IDENT
%left	ADD SUB
%left	MULT DIV
%nonassoc USUB

%%


Program:		PROGRAM {printf("program -> PROGRAM \n");} IDENT {printf("ident -> IDENT (%s) \n", $3);} SEMICOLON {printf("semicolon -> SEMICOLON \n");} Block END_PROGRAM {printf("end_program -> END_PROGRAM \n");}; 


		
Block:			BlockDeclarationLoop BEGIN_PROGRAM {printf("begin_program -> BEGIN_PROGRAM \n");} BlockStatmentLoop;
		
BlockDeclarationLoop: 	Declaration SEMICOLON {printf("semicolon -> SEMICOLON \n");} BlockDeclarationLoop
                     	| Declaration SEMICOLON {printf("semicolon -> SEMICOLON \n");}
			;

BlockStatmentLoop:	Statement SEMICOLON {printf("semicolon -> SEMICOLON \n");} BlockStatmentLoop
			| Statement SEMICOLON {printf("semicolon -> SEMICOLON \n");}
			;

Declaration:		DeclarationIdLoop COLON {printf("colon -> COLON \n");} INTEGER {printf("integer -> INTEGER \n");}
			| DeclarationIdLoop COLON {printf("colon -> COLON \n");} ARRAY {printf("array -> ARRAY \n");} L_PAREN {printf("l_paren -> L_PAREN \n");} NUMBER {printf("number -> NUMBER (%s) \n", yytext);} R_PAREN{printf("r_paren -> R_PAREN \n");}  OF {printf("of -> OF \n");} INTEGER {printf("integer -> INTEGER \n");}
			;	

DeclarationIdLoop:	IDENT {printf("ident -> IDENT (%s) \n", $1);} COMMA {printf("comma -> COMMA \n");} DeclarationIdLoop
			| IDENT {printf("ident -> IDENT (%s) \n", $1);}
			;				

Statement:		Var {printf("var -> ident#%d \n",line-1);} ASSIGN {printf("assign -> ASSIGN \n");} Expression {printf("statement -> var assign expression \n");}
			| IF {printf("if -> IF \n");} Bool_Exp {printf("bool_exp ->  \n");} THEN {printf("then -> THEN \n");} BlockStatmentLoop ENDIF {printf("endif -> ENDIF \n");}
                        | IF {printf("if -> IF \n");} Bool_Exp THEN {printf("then -> THEN \n");} BlockStatmentLoop ELSE {printf("else -> ELSE \n");} BlockStatmentLoop ENDIF {printf("endif -> ENDIF \n");}
			| WHILE {printf("while -> WHILE \n");} Bool_Exp {printf("bool_exp ->  \n");} LOOP {printf("loop -> LOOP \n");} BlockStatmentLoop ENDLOOP {printf("loop -> ENDLOOP \n");}
			| READ {printf("read -> READ \n");} DeclarationIdLoop
			| WRITE {printf("write -> WRITE \n");} DeclarationIdLoop
                        ;

Bool_Exp:		Relation_Exp {printf("relation_exp -> \n");} Bool_ExpLoop
			| Relation_Exp {printf("relation_exp -> \n");}
			;

Bool_ExpLoop:		AND {printf("and -> AND \n");} Relation_Exp {printf("relation_exp -> \n");} Bool_ExpLoop 
			| AND {printf("and -> AND \n");} Relation_Exp {printf("relation_exp -> \n");}
			| OR {printf("or -> OR \n");} Relation_Exp {printf("relation_exp -> \n");} Bool_ExpLoop
			| OR {printf("or -> OR \n");} Relation_Exp {printf("relation_exp -> \n");}
			;

Relation_Exp:		Expression {printf("relation_exp2 -> expression ");} Comp Expression 
			| TRUE {printf("true -> TRUE \n");}
			| FALSE {printf("false -> FALSE \n");}
			| NOT {printf("not -> NOT ");} Expression {printf("expression \n ");} Comp Expression {printf("expression \n ");}
			| NOT {printf("not -> NOT ");} TRUE {printf("true -> TRUE \n");}
			| NOT {printf("not -> NOT ");} FALSE {printf("false -> FALSE \n");}
			;

Comp:			EQ {printf("comp-> EQ ");}
			| NEQ {printf("comp-> NEQ ");}
			| LT {printf("comp-> LT ");}
			| GT {printf("comp-> GT ");}
			| LTE {printf("comp-> LTE ");}
			| GTE {printf("comp-> GTE ");}
			;

Expression:	        Term
			| SUB Term %prec USUB 
			| Term {printf("term ");} ExpressionLoop
			;

ExpressionLoop:		ADD {printf("add -> ADD ");} Term ExpressionLoop
			| ADD Term
			| SUB {printf("sub -> SUB ");} Term ExpressionLoop
			| SUB Term
			;

Term:			Factor 
			| Factor  TermLoop
			;

TermLoop:		MULT {printf("mult -> MULT \n");} Factor TermLoop
			| MULT Factor
			| DIV {printf("div -> DIV \n");} Factor TermLoop
			| DIV Factor
			;		

Factor:			Var {printf("var -> VAR \n");}
			| NUMBER {printf("number -> NUMBER(%i) \n", $1);}
			| L_PAREN Expression R_PAREN
			;

Var:			IDENT
			| IDENT L_PAREN Expression R_PAREN
			;

%%



int main() {
yyparse();
         return 0;
}



void yyerror(const char* msg)
{
	printf("** Line %d, position %d: %s\n", line, currPos, msg);
}

