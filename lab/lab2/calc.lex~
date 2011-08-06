/* cs152 */
/* Quoc Anh Doan */

%{
   #include "y.tab.h"
   int currLine = 1, currPos = 1;
   int numNumbers = 0;
   int numOperators = 0;
   int numParens = 0;
   int numEquals = 0;

%}

DIGIT [0-9]

%%

"-" {currPos += yyleng; numOperators++; return MINUS;}
"+" {currPos += yyleng; numOperators++; return PLUS;}
"*" {currPos += yyleng; numOperators++; return MULT;}
"/" {currPos += yyleng; numOperators++; return DIV;}
"=" {currPos += yyleng; numOperators++; return EQUAL;}
"(" {currPos += yyleng; numOperators++; return L_PAREN;}
")" {currPos += yyleng; numOperators++; return R_PAREN;}

(\.{DIGIT}+)|({DIGIT}+(\.{DIGIT}*)?([eE][+-]?[0-9]+)?) {currPos += yyleng; yylval.dval = atof(yytext); numNumbers++; return NUMBER;}

[ \t]+ {/* ignore spaces */ currPos += yyleng;}

"\n" {currLine++; currPos = 1; return END;}

. {printf("ERROR at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%
