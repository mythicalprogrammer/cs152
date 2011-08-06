%{
#include <iostream>
#include "y.tab.h"
#include <string>

int currline = 1;
int currpos = 1;

using namespace std;
%}

DIGIT [0-9]
A [A-Z]
LA [a-z]

%%

"program"      {currpos += yyleng; return PROGRAM;}
"beginprogram" {currpos += yyleng; return BEGIN_PROGRAM;}
"endprogram"   {currpos += yyleng; return END_PROGRAM;}
"integer"      {currpos += yyleng; return INTEGER;}
"array"        {currpos += yyleng; return ARRAY;}
"of"           {currpos += yyleng; return OF;}
"if"           {currpos += yyleng; return IF;}
"then"         {currpos += yyleng; return THEN;}
"endif"        {currpos += yyleng; return ENDIF;}
"else"         {currpos += yyleng; return ELSE;}
"while"        {currpos += yyleng; return WHILE;}
"loop"         {currpos += yyleng; return LOOP;}
"endloop"      {currpos += yyleng; return ENDLOOP;}
"read"         {currpos += yyleng; return READ;}
"write"        {currpos += yyleng; return WRITE;}
"and"          {currpos += yyleng; return AND;}
"or"           {currpos += yyleng; return OR;}
"not"          {currpos += yyleng; return NOT;}
"true"         {currpos += yyleng; return TRUE;}
"false"        {currpos += yyleng; return FALSE;}
"-"            {currpos += yyleng; return SUB;}
"+"            {currpos += yyleng; return ADD;}
"*"            {currpos += yyleng; return MULT;}
"/"            {currpos += yyleng; return DIV;}
"="            {currpos += yyleng; return EQUAL;}
"<>"           {currpos += yyleng; return NEQ;}
"<"            {currpos += yyleng; return LT;}
">"            {currpos += yyleng; return GT;}
"<="           {currpos += yyleng; return LTE;}
">="           {currpos += yyleng; return GTE;}
(({A}|{LA})+((\_|{A}|{LA}|{DIGIT})*({A}|{LA}|{DIGIT})+)*) {yylval.sval = new char(yyleng + 1); strcpy(yylval.sval, yytext); currpos += yyleng; return IDENT;}
{DIGIT}+       {yylval.sval = new char(yyleng + 1); strcpy(yylval.sval, yytext); currpos += yyleng; return NUMBER;}
";"            {currpos += yyleng; return SEMICOLON;}
":"            {currpos += yyleng; return COLON;}
","            {currpos += yyleng; return COMMA;}
"("            {currpos += yyleng; return L_PAREN;}
")"            {currpos += yyleng; return R_PAREN;}
":="           {currpos += yyleng; return COLEQL;}
" "            {/* space */ currpos += yyleng;}
\t             {/* tab */ currpos += yyleng;}
("--"(.)*\n)   {/*comment*/ currline++; currpos = 1;}
\n             {/*newline*/ currline++; currpos = 1;}
.              {cout << "Error @ Line:" << currline << " Pos:" << currpos 
                     << endl; currpos += yyleng;}

%%
/*
int main()
{
  yylex();
}*/
