/* 
 * Description: Tokenizer
 *
 * cs152: Project 1
 * Student: Quoc Anh Doan
 * ID: 860759993
 * UN: qdoan
 */

%{
/* need this for the call to atof() below */
/* isdigit is in ctype library */

unsigned int line = 1;
unsigned int column = 0;
#include <string.h>
#include <ctype.h> 
%}
  

DIGIT		[0-9]
ALPHA		[a-zA-Z]

%%


	 
"program"   { column = column + 7;  
              printf( "PROGRAM\n", yytext );
            }
	  
"beginprogram"     { column = column + 12;  
                     printf( "BEGIN_PROGRAM\n", yytext );
                   }
	        
"endprogram"    { column = column + 10;  printf( "END_PROGRAM\n", yytext ); }
	       
"integer"        {   column = column + 7;  printf( "INTEGER\n", yytext ); }
	      
"array"           { column = column + 5;   printf( "ARRAY\n", yytext ); }
	  
"of"            { column = column + 2;  printf( "OF\n", yytext ); }
	 
"if"              { column = column + 2;   printf( "IF\n", yytext ); }
	    
"then"          {column = column + 4;   printf( "THEN\n", yytext ); }
	     
"endif"          {column = column + 5;  printf( "ENDIF\n", yytext ); }
	     
"else"          { column = column + 4;  printf( "ELSE\n", yytext ); }
	   
"while"        { column = column + 5; printf( "WHILE\n", yytext ); }
	
"loop"         { column = column + 4;    printf( "LOOP\n", yytext ); }
	 
"endloop"      { column = column + 7;  printf( "ENDLOOP\n", yytext ); }
	
"read"        {  column = column + 4;   printf( "READ\n", yytext ); }
	     
"write"        { column = column + 5;  printf( "WRITE\n", yytext ); }
	
"and"         { column = column + 3;   printf( "AND\n", yytext ); }

"or"          { column = column + 2;   printf( "OR\n", yytext ); }

"not"      { column = column + 3;  printf( "NOT\n", yytext ); }

"true"      {  column = column + 4;   printf( "TRUE\n", yytext ); }

"false"     {  column = column + 5;   printf( "FALSE\n", yytext ); }

("--"(.)*) ++line; 

"+" {  ++column;  printf( "ADD\n", yytext ); }

"-" { ++column;   printf( "SUB\n", yytext ); }

"*" { ++column;   printf( "MULT\n", yytext );  }

"/" {  ++column;  printf( "DIV\n", yytext ); }

"=" { ++column;   printf( "EQ\n", yytext); }

"<>" { ++column; ++column;    printf( "NEQ\n", yytext); }
 
"<" { ++column;  printf( "LT\n", yytext); }

">" { ++column;   printf( "GT\n", yytext); }
 
"<=" { ++column; ++column;     printf( "LTE\n", yytext); }

">=" { ++column; ++column;    printf( "GTE\n", yytext); }

";" {  ++column;  printf("SEMICOLON\n", yytext); }
    
":" { ++column;   printf("COLON\n", yytext); }
   
"," { ++column;   printf("COMMA\n", yytext); }

"(" { ++column;   printf("L_PAREN\n", yytext); }

")" { ++column;   printf("R_PAREN\n", yytext); }

":=" { column +=2;     printf("ASSIGN\n", yytext); }

[ ] ++column;   
[\t]        
[\n] {++line; column = 0;  } 



({DIGIT})*({ALPHA}|"_")+({DIGIT}|{ALPHA}|"_")* { 
                                                 if(isdigit(yytext[0]))
                                                 {
                                                   printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", line, column, yytext);
                                                 }
						 if(yytext[yyleng-1]=='_')
                                                 {
                                                   printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", line, column, yytext);
                                                 }
                                                 else
                                                 {
                                                  printf("IDENT %s\n", yytext); column += yyleng;
                                                 }
                                               }
	           
{DIGIT}+       {   column = column + yyleng;
                   printf( "NUMBER %s\n", yytext); 
               }
            
. {  

        printf( "Error at line %d, column %d: unrecognized symbol \"%s\" \n", line, column, yytext  ); 
  }

%%

int main()
{
yylex();
}
