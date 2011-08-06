/* Mini Calculator */
/* calc.y */

%{
#include "heading.h"
void yyerror(const char *msg);
%}

%union{
double dval;
int ival;
}

