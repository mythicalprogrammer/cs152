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
 


%}

%union{
  int	ival;
  char*	idval;
}

%error-verbose
//%start	input 
%token PROGRAM BEGIN_PROGRAM END_PROGRAM OF IF THEN ENDIF ELSE WHILE LOOP ENDLOOP READ WRITE AND OR NOT TRUE FALSE ADD SUB MULT DIV EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
%token	<idval>	NUMBER 
%token	<idval>	IDENT
%token	<idval>	INTEGER
%token	<idval>	ARRAY
//%type	<idval>	declaration3
%type	<idval>	declaration2
%type <idval> Statement
%type <idval> varloop
%type <idval> Bool_Exp
%type <idval> Bool_ExpLoop
%type <idval> Var
%type <idval> ExpressionLoop
%type <idval> Expression
%type <idval> Term
%type <idval> Factor
%type <idval> TermLoop
%type <idval> number
%type <idval> Comp
%type <idval> Relation_Exp
/*

*/
%left	ADD SUB
%left	MULT DIV


%%


Program:		PROGRAM IDENT {addSymbolTable($2,1);} SEMICOLON {flagTemp = 1;} Block END_PROGRAM;

		
Block:			BlockDeclarationLoop BEGIN_PROGRAM  {
		                                              string temp =  ": START";
							      buffer.push_back(temp);
                                                            }
			BlockStatmentLoop;
		
BlockDeclarationLoop: 	Declaration SEMICOLON {flagTemp = 1;} BlockDeclarationLoop
                     	| Declaration SEMICOLON {flagTemp = 1;}
			;

BlockStatmentLoop:	Statement SEMICOLON {flagTemp = 1;} BlockStatmentLoop {    }
			| Statement SEMICOLON {flagTemp = 1;}
			;

Declaration:		IDENT declaration2 COLON INTEGER { 	
							        string temp $1;								

								l.push_back(temp);
                                                                string add = ". _";
			                                        for(int i=0; i < l.size(); ++i)
		                                                {
                                                                  temp = add+l[i];
                                                                  addSymbolTable(temp,0);
		                                                }
			                                        l.clear();
                                      

							  }
			| IDENT declaration2 COLON ARRAY L_PAREN number R_PAREN OF INTEGER 			  
			        {
				
				  string temp = $1;
			          l.push_back(temp);

				  string add = ".[] _";
				   string arrayNumber = $6;



			          for(int i=0; i < l.size(); ++i)
			          {
                                    temp = add+l[i]+", " +arrayNumber;
                                    addSymbolTable(temp,4);
			          }
			          l.clear();				  
                                }
		        ;
					

declaration2:	        COMMA IDENT {   

				       string temp = $2;
				       l.push_back($2);

                                     } declaration2 {}
			| {$$=NULL;}/*empty*/
			;		
	

varloop:		Var{$$=$1;}
			| Var COMMA varloop{};

Statement:		Var ASSIGN Expression {

						if($1 != NULL && $3 != NULL)
                                                {
					          string t2 = $3;
						  string t1 = $1;

                                                  

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



					      }
			| IF Bool_Exp THEN BlockStatmentLoop ENDIF {flagTemp = 0;}
                        | IF Bool_Exp THEN BlockStatmentLoop ELSE BlockStatmentLoop ENDIF{flagTemp = 0;}
			| WHILE 
				{
				  string temp = newLabel();
                                      
			   	  buffer.push_back(temp); //pushing LABEL
				 // $<idval>$=const_cast<char *>(temp.c_str());
 
				  /*l_1 = newlabel(); genCode('label', l_1, 0, 0); $<sval>$=l_1;*/
				}
			  Bool_Exp
				{
			      
				 
				} 
			  LOOP BlockStatmentLoop ENDLOOP
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
			         
                                                 }
			| READ varloop 
                                      { 
					string temp2 = $2;
					string temp = ".< "+temp2; 
					buffer.push_back(temp);
				      }
			| WRITE varloop{}
                        ;

Bool_Exp:		Relation_Exp Bool_ExpLoop {}
			| Relation_Exp { }
			;

Bool_ExpLoop:		AND Relation_Exp Bool_ExpLoop  {}
			| AND Relation_Exp {}
			| OR Relation_Exp Bool_ExpLoop {}
			| OR Relation_Exp {}
			;

Relation_Exp:		Expression Comp 
                        Expression  {




			              if ($1 != NULL ) 
				      {
                                        string exp2;






flagBool = 1;

  int curTemp = tempCounter - 1 ; 
  string realTemp;
  stringstream in;
  in << curTemp;
   realTemp = in.str();
   exp2 = "t"+realTemp;



				         string comp = $2;
                                         string exp1 = $1;

					 
 
   if(flagTemp==0)
    exp2 =$3;
  
                                         
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
				     
			             

			            }
			| TRUE {}
			| FALSE {}
			| NOT Expression Comp Expression {}
			| NOT TRUE {}
			| NOT FALSE {}
			;

Comp:			EQ {$$="==";}
			| NEQ {$$="!=";}
			| LT {$$="<";}
			| GT {$$=">";}
			| LTE {$$="<=";}
			| GTE {$$=">=";}
			;

Expression:	          SUB Term ExpressionLoop
			  { 
                            if($2 !=NULL)
                             {
			    string temp = $2;
			    temp = "-"+temp;
			    $$ = const_cast<char *>(temp.c_str());
                             }
			  }
			| Term ExpressionLoop
			  {
				
                            if($2 == NULL && flagBool == 0)
			      flagTemp = 0;
			    else if( flagBool == 1)
			      flagTemp = 1;
                     
                             if($2 !=NULL)
                            {
			      string add;
                              
                              if(flagAdd == 1)
                               add = "+ ";
                              else
                               add = "- ";

                              $$=$2;

                              string t1 = $1;
                              string t2;
if(flagTemp == 1)
{
  
  stringstream out;
  int curTemp = tempCounter - 1;
  out << curTemp;
  t2 = "t"+out.str();

  
}	
else
                              t2 = $2;
			      string tlabel = newTemp();
                              string temp = add+tlabel+", "+t1+", "+t2;

			      buffer.push_back(temp);
			      flagAdd = 0;
                             }

	  	      


			    
			  }
;

ExpressionLoop:		ADD Term ExpressionLoop { flagAdd = 1;
						  $$=$2;
                                                }
			| SUB Term ExpressionLoop {flagAdd = 0;  $$=$2;}
			| {$$=NULL;}
			;

Term:			Factor {$$=$1;}
			| Factor  TermLoop { 
					       if ($2 !=NULL && $1 !=NULL)
                                               {  
                                                  string fact_1;                                               

                                                  if(flagTemp == 0)
						    fact_1 = $1;
						  else
 {
  stringstream out;
  int curTemp = tempCounter - 1;
  out << curTemp;
  fact_1 = "t"+out.str();
 }
						   string fact_2 = $2;
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
					     
					   }
			;

TermLoop:		MULT Factor TermLoop {$$ =$2;flagDiv = 0;}
			| MULT Factor {$$ = $2;flagDiv = 0;}
			| DIV Factor TermLoop {$$=$2;flagDiv = 1;}
			| DIV Factor {$$ = $2;flagDiv = 1;}
			;		

Factor:			Var {$$=$1;}
			| number {$$=$1;}
			| L_PAREN Expression R_PAREN {$$=$2;}
			;

number:			NUMBER {
                                   string add = $1;
                                strcpy($$,add.c_str());
			       };

Var:			IDENT { 
	                        string add = $1;				
                                string temp = "_"+add;
                                strcpy($$,temp.c_str());
                                //$$=const_cast<char *>(temp.c_str());
			      }
			| IDENT L_PAREN Expression R_PAREN {$$=$1; flagTemp = 1;}
			;

%%




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
