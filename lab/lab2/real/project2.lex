/* 
 * Description: Tokenizer
 *
 * cs152: Project 2
 * Student: Quoc Anh Doan
 * ID: 860759993
 * UN: qdoan
 */

%{
#include <string.h>
#include <ctype.h> 
#include "y.tab.h"

/* need this for the call to atof() below */
/* isdigit is in ctype library */

unsigned int line = 1; //currentline
unsigned int currPos = 1; // current position or column

%}
  

DIGIT		[0-9]
ALPHA		[a-zA-Z]

%%


	 
"program"   {currPos += yyleng; return PROGRAM;}
	  
"beginprogram"     {currPos += yyleng; return BEGIN_PROGRAM;}
	        
"endprogram"    {currPos += yyleng; return END_PROGRAM;}
	       
"integer"        {currPos += yyleng; return INTEGER;}
	      
"array"           {currPos += yyleng; return ARRAY;}
	  
"of"            {currPos += yyleng; return OF;}
	 
"if"              {currPos += yyleng; return IF;}
	    
"then"          {currPos += yyleng; return THEN;}
	     
"endif"          {currPos += yyleng; return ENDIF;}
	     
"else"          {currPos += yyleng; return ELSE;}
	   
"while"        {currPos += yyleng; return WHILE;}
	
"loop"         {currPos += yyleng; return LOOP;}
	 
"endloop"      {currPos += yyleng; return ENDLOOP;}
	
"read"        {currPos += yyleng; return READ;}
	     
"write"        {currPos += yyleng; return WRITE;}
	
"and"         {currPos += yyleng; return AND;}

"or"          {currPos += yyleng; return OR;}

"not"      {currPos += yyleng; return NOT;}

"true"      {currPos += yyleng; return TRUE;}

"false"     {currPos += yyleng; return FALSE;}

("--"(.)*) ++line; 

"+" {currPos += yyleng; return ADD;}

"-" {currPos += yyleng; return SUB;}

"*" {currPos += yyleng; return MULT;}

"/" {currPos += yyleng; return DIV;}

"=" {currPos += yyleng; return EQ;}

"<>" {currPos += yyleng; return NEQ;}
 
"<" {currPos += yyleng; return LT;}

">" {currPos += yyleng; return GT;}
 
"<=" {currPos += yyleng; return LTE;}

">=" {currPos += yyleng; return GTE;}

";" {currPos += yyleng; return SEMICOLON;}
    
":" {currPos += yyleng; return COLON;}
   
"," {currPos += yyleng; return COMMA;}

"(" {currPos += yyleng; return L_PAREN;}

")" {currPos += yyleng; return R_PAREN;}

":=" {currPos += yyleng; return ASSIGN;}

[ ] {currPos += yyleng;}   
[\t] {currPos += yyleng;}       
[\n] {currPos = 1; ++line;} 



({DIGIT})*({ALPHA}|"_")+({DIGIT}|{ALPHA}|"_")* { 
                                                 if(isdigit(yytext[0]))
                                                 {
                                                   printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", line, currPos, yytext);
                                                 }
						 if(yytext[yyleng-1]=='_')
                                                 {
                                                   printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", line, currPos, yytext);
                                                 }
                                                 else
                                                 {
                                                  yylval.idval=new char[yyleng+1]; strcpy(yylval.idval,yytext); currPos += yyleng; return IDENT;
                                                 }
                                               }
	           
{DIGIT}+       {  /*
		   currPos += yyleng;
		   yylval.idval = yytext; 
                   return NUMBER; 
                  */
		  yylval.idval=new char[yyleng+1]; strcpy(yylval.idval,yytext); currPos += yyleng;
	          return NUMBER;
               }
            
. {  

        printf( "Error at line %d, column %d: unrecognized symbol \"%s\" \n", line, currPos, yytext  ); 
  }

%%
