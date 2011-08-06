%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <iostream>
  #include <string>
  #include <vector>
  #include <sstream>
  #include <fstream>

  void yyerror (const char* msg);

  extern int yylex ();
  extern int currline;
  extern int currpos;
  extern FILE * yyin;

  using namespace std;

  //helper function prototypes
  bool is_var_declared (string input);
  bool valid_size(int size);
  bool is_array(string input);

  //types used in variables declarations
  enum e_type
  {
    INTEGER_TYPE,
    ARRAY_TYPE
  };

  //types used in arithemetic calculations
  enum a_type
  {
    ADD_a,
    SUB_a,
    MULT_a,
    DIV_a
  };

  //types used in boolean calculations
  enum b_type
  {
    AND_b,
    OR_b
  };

  //variable object
  struct symbol_info
  {
    string name;
    e_type type;
    int size;
  };

  //temporary arithemetic result object
  struct temp_type
  {
	  string name;
	  e_type type;
	  int size;
    bool used;
  };

  //temporary boolean result object
  struct pemp_type
  {
    string name;
    e_type type;
    int size;
  };

  vector <string> numbers;
  vector <symbol_info> symbol_table;
  vector <string> the_list;
  vector <temp_type> temporary;
  vector <pemp_type> pemporary;
  vector <string> labels;

  a_type arith;
  b_type boolian;
  int label_size = 0;
  bool error_flag = false;
  int line_num = 1;

  string program_name;


  ostringstream output;
  ostringstream variables;
  ostringstream errors;
  
%}

%union{char* sval; int ival;}

%error-verbose
%start s

%token PROGRAM BEGIN_PROGRAM END_PROGRAM INTEGER ARRAY OF
%token IF THEN ENDIF ELSE WHILE LOOP ENDLOOP
%token READ WRITE AND OR NOT TRUE FALSE
%token ADD SUB MULT DIV EQUAL NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA R_PAREN L_PAREN
%token COLEQL 
%token <sval> IDENT
%token <sval> NUMBER

%left ADD SUB
%left MULT DIV

%type <sval> factor1
%type <sval> var1
%type <sval> var2
%type <sval> term2
%type <sval> term1
%type <sval> expression1
%type <sval> statement1
%type <sval> bool_exp1
%type <sval> bool_exp2
%type <sval> comp1
%type <sval> rel_exp2
%type <sval> rel_exp1
%type <sval> expression2

%%

s: PROGRAM IDENT {program_name = $2;} SEMICOLON {line_num++;} block1 END_PROGRAM {}
 | {}
 ;

block1: declare1 SEMICOLON {line_num++;} block2 BEGIN_PROGRAM {
                                                               ostringstream sin;
		                                                           output<< ": " << "START" << endl;
                                                               line_num++;
                                                              }
                                                       block3 {}
      ;

block2: declare1 SEMICOLON {line_num++;} block2 {}
      | {}
      ;

block3: statement1 SEMICOLON {line_num++;} block3 {}
	    | {}
      ;

declare1: IDENT declare2 COLON INTEGER {
                                         bool duplicate;
                                         //if the symbol is not in the symbol table or a key word then add it
                                         if (!is_var_declared($1))
                                         {
                                           symbol_info temp;
                                           ostringstream sin;
                                             
                                           sin << "_" << $1; 
                                            
                                           temp.name = sin.str();
                                           temp.type = INTEGER_TYPE;
                                           temp.size = 0;
                                           
                                           symbol_table.push_back(temp);
                                           variables << ". " << temp.name << endl;  
                                         }
                                         //generate an error
                                         else
                                         {
                                           errors << "Error line " << line_num << ": Variable '"<< $1 
                                                  << "' already exists in the symbol table." << endl;
                                           error_flag = true;
                                         } 
                                        
                                         for(unsigned int j = 0; j < the_list.size();j++)
                                         {
                                           if (!is_var_declared(the_list[j]))
                                           {
                                             symbol_info temp2;
                                             temp2.name = "_" + the_list[j];
                                             temp2.type = INTEGER_TYPE;
                                             temp2.size = 0;
                                             symbol_table.push_back(temp2);
                                             variables << ". " << temp2.name << endl;
                                           }
                                           else
                                           {
                                             errors << "Error line " << line_num << ": Variable '"<< the_list[j] 
                                                    << "' already exists in the symbol table." << endl;
                                             error_flag = true;
                                           }
                                         }
 
                                         the_list.clear();
                                       }
        | IDENT declare2 COLON ARRAY L_PAREN declare3 NUMBER R_PAREN OF INTEGER {
                                                                         symbol_info temp;
                                                                         ostringstream sin;
                                                                         bool duplicate;
                                                                         if (valid_size(atoi($7)))
                                                                         {
                                                                           //if the symbol is not in the symbol table or a key word then add it
                                                                           if (!is_var_declared($1))
                                                                           {
                                                                             sin << "_" << $1; 

                                                                             temp.name = sin.str();
                                                                             temp.type = ARRAY_TYPE;
                                                                             temp.size = atoi($7);

                                                                             symbol_table.push_back(temp);
                                                                             variables << ".[] " << temp.name << ", " 
                                                                                       << temp.size << endl;
                                                                           }
                                                                           //else generate an error
                                                                           else
                                                                           {
                                                                             errors << "Error line " << line_num << ": Variable '"<< $1 
                                                                                    << "' already exists in the symbol table." << endl;
                                                                             error_flag = true;
                                                                           }
                                                                         }
                                                                         else
                                                                         {
                                                                           errors << "Error line " << line_num << ": Invalid array size." << endl;
                                                                           error_flag = true;
                                                                         } 


                                                                         for(unsigned int j = 0; j < the_list.size();j++)
                                                                         {
                                                                           if (!is_var_declared(the_list[j]))
                                                                           {
                                                                             symbol_info temp2;
                                                                             temp2.name = "_" + the_list[j];
                                                                             temp2.type = ARRAY_TYPE;
                                                                             temp2.size = atoi($7);
                                                                             symbol_table.push_back(temp2);
                                                                             variables << ".[] " << temp2.name << ", " 
                                                                                       << temp2.size << endl;
                                                                           }
                                                                           else 
                                                                           {
                                                                             errors << "Error line " << line_num << ": Variable '"<< the_list[j] 
                                                                                    << "' already exists in the symbol table." << endl;
                                                                             error_flag = true;
                                                                           }
                                                                         }

                                                                         the_list.clear();
                                                                       }
        ;

declare2: COMMA IDENT declare2 {
                                 ostringstream sin;
                                 sin << $2;
                                 the_list.push_back(sin.str());
                               }
        | {}
        ;

declare3: SUB {
                errors << "Error line " << line_num << ": Invalid array size." << endl;
                error_flag = true;
              }
        | {}
        ;

statement1: var2 COLEQL expression1 {
                                      size_t found;
	                                    string temp; 
	                                    ostringstream sin;

				                              sin << "_" << $1;
				                              temp = sin.str();
	                                    found=temp.find(",");

				                              if (found == string::npos)
				                              {
				                                output << "= " << $1 << ", "<< $3 << endl;
				                              }
				                              else
				                              {
				                                output << "[]= " << sin.str() << ", "<< $3 << endl;
				                              }
                                    }
          | IF bool_exp1 THEN {line_num++;} statement1 SEMICOLON {line_num++;} statement2 {
						                                                    ostringstream sin;

				        	                                              labels.push_back("L");
		        			                                              sin << "L" << label_size;
		        			                                              labels[labels.size() - 1] = sin.str(); label_size++;

						                                                    output << ":= " << labels[labels.size() - 1] << endl;
							                                                }
                                                   statement4 {
                                                                output << ": " << labels[labels.size() - 2] << endl;
                                                              }
		                                                    ENDIF {
                                                                output << ": " << labels[labels.size() -1] << endl; 
                                                                labels.pop_back();
                                                                labels.pop_back();
                                                              }
          | WHILE {
			              ostringstream sin;
                   
	                  labels.push_back("L");
		                sin << "L" << label_size;
		                labels[labels.size() - 1] = sin.str(); 
                    label_size++;
                      
		                output << ": " << sin.str() << endl;
	   	            }
            bool_exp1 LOOP {line_num++;}
                  {
                  }
	          statement1 SEMICOLON {line_num++;} statement2 ENDLOOP 
                  {
                    output << ":= " << labels[labels.size()- 2] << endl;
                    output << ": " << labels[labels.size() - 1] << endl; 
                    labels.pop_back(); 
                    labels.pop_back();
                  }
          | READ var1 statement3 {output << ".< " << $2 << endl;}
								
          | WRITE var1 statement3 {output << ".> " << $2 << endl;}
          ;

statement2: {}
		      | statement1 SEMICOLON {line_num++;} statement2 {}
          ;

statement3: COMMA var1 statement3 {}
          | {}
          ;

statement4: ELSE {line_num++;} statement1 SEMICOLON {line_num++;} statement2 {
                                                   output << ":= " << labels[labels.size() -1]; labels.pop_back();
                                                 } 
	        | {}
	        ;

expression1: SUB term1 expression2 {
                                     if ($3 == NULL)
                                     {
                                       ostringstream sin;
                                       string temp; 
                                       sin << "-" << $2;
                                       temp = sin.str();
                                       strcpy($$, temp.c_str());
                                     }
                                   }
		       | term1 expression2 {
						                     if($2 == NULL)
						                     {
                                   $$ = $1;
                                 }
						                     else
                                 {
                                   //Creates a Temp Type
                                   temp_type temp;  
                                   //Adds the variable t to the name
						                       temp.name="t";   
                                   //Adds the temp to the temporary array with only the name t and no # following it
						                       temporary.push_back(temp); 
   
						                       ostringstream sin;
						                       sin << temporary.size()-1;

                                   //Add the # to the t
						                       temporary[temporary.size()-1].name += sin.str();
                                                  
                                   if (arith == ADD_a)
                                   {
                                     //Output the line to the screen
                                     output << "+ " << temporary[temporary.size()-1].name << ", " << $1 << ", " << $2 << endl;
                      
                                     //Copies the t# or name from the new temp added to the vector to be passed up
						                         strcpy($$,temporary[temporary.size()-1].name.c_str());
                                   }
						                       else if (arith == SUB_a)
                                   {
                                     //Output the line to the screen
					                           output << "- " << temporary[temporary.size()-1].name << ", " << $1 << ", " << $2 << endl;

                                     //Copies the t# or name from the new temp added to the vector to be passed up
					                           strcpy($$,temporary[temporary.size()-1].name.c_str());
						                       }
                                 }
					                     }
           ;
 
expression2: ADD term1 expression2 {$$ = $2; arith = ADD_a;}
           | SUB term1 expression2 {$$ = $2; arith = SUB_a;}						
           | {$$ = NULL;}
           ;

term1: factor1 term2 { 
						           if($2 == NULL)
							         {
                         $$ = $1;
                       }
						           else
						           {
                         //Creates a Temp Type
					               temp_type temp;

                         //Adds the variable t to the name
					               temp.name="t";

                         //Adds the temp to the temporary array with only the name t and no # following it
					               temporary.push_back(temp);
					          
                         ostringstream sin;
					               sin << temporary.size()-1;

                         //Add the # to the t
					               temporary[temporary.size()-1].name += sin.str();
                                                  
                         if (arith == DIV_a)
                         {

                           //Output the line to the screen
                           output << "/ " << temporary[temporary.size()-1].name << ", " << $1 << ", " << $2 << endl;

                           //Copies the t# or name from the new temp added to the vector to be passed up
						               strcpy($$,temporary[temporary.size()-1].name.c_str());
                         }
						             else if (arith == MULT_a)
                         {

                           //Output the line to the screen
					                 output<< "* " << temporary[temporary.size()-1].name << ", " << $1 << ", " << $2 << endl;

                           //Copies the t# or name from the new temp added to the vector to be passed up
					                 strcpy($$,temporary[temporary.size()-1].name.c_str());
						             }
                       }
					           }
     ;

term2: MULT factor1 term2 {$$ = $2; arith = MULT_a;}
     | DIV factor1 term2 {$$ = $2; arith = DIV_a;}
     | {$$=NULL;}
     ;

factor1: var1 {$$=$1;}
	     | NUMBER {$$=$1;}
       | L_PAREN expression1 R_PAREN {$$=$2;}
       ;

var1: IDENT { if (!is_var_declared($1))
              {
                errors << "Error line " << line_num << ": Variable '" << $1 << "' has not been declared."<< endl;
                error_flag = true;
              }
              if (is_array($1))
              {
                errors << "Error line " << line_num << ": Variable '" << $1 
                       << "' is declared as an Array but is being accessed as an Integer."<< endl;
                error_flag = true;
              }
              ostringstream sin;
              sin << "_" << $1;
              strcpy($$,sin.str().c_str());
            }
    | IDENT L_PAREN expression1 R_PAREN { if (!is_var_declared($1))
                                          {
                                            errors << "Error line " << line_num << ": Variable '" << $1 << "' has not been declared."<< endl;
                                            error_flag = true;
                                          }
                                          if (!is_array($1))
                                          {
                                            errors << "Error line " << line_num << ": Variable '" << $1 
                                            << "' is declared as an Integer but is being accessed as an Array."<< endl;
                                            error_flag = true;
                                          }

					                                temp_type temp;
					                                temp.name="t";
					                                temporary.push_back(temp);

					                                ostringstream sin;
					                                sin << temporary.size()-1;

					                                temporary[temporary.size()-1].name += sin.str();//Add the # to the t
                                          temporary[temporary.size()-1].used = false;

                                          ostringstream sin2;
                                          sin2 << "_" << $1;

					                                output << "=[] " << temporary[temporary.size()-1].name << ", " << sin2.str() << ", " << $3 << endl;
					                                strcpy($$,temporary[temporary.size()-1].name.c_str());
                                        }
    ;

var2: IDENT { if (!is_var_declared($1))
              {
                errors << "Error line " << line_num << ": Variable '" << $1 << "' has not been declared."<< endl;
                error_flag = true;
              }
              if (is_array($1))
              {
                errors << "Error line " << line_num << ": Variable '" << $1 
                       << "' is declared as an Array but is being accessed as an Integer."<< endl;
                error_flag = true;
              }
              ostringstream sin;
              sin << "_" << $1;
              strcpy($$,sin.str().c_str());
            }
    | IDENT L_PAREN expression1 R_PAREN {
                                          if (!is_var_declared($1))
                                          {
                                            errors << "Error line " << line_num << ": Variable '" << $1 << "' has not been declared."<< endl;
                                            error_flag = true;
                                          }
                                          if (!is_array($1))
                                          {
                                            errors << "Error line " << line_num << ": Variable '" << $1 
                                            << "' is declared as an Integer but is being accessed as an Array."<< endl;
                                            error_flag = true;
                                          }
					                                ostringstream sin2;
  			                                  string temp;

					                                  sin2  << $1 << ", " << $3;
					                                  temp = sin2.str();
					                                  strcpy($$,temp.c_str());
                                        }
    ;

bool_exp1: rel_exp1 bool_exp2 {
				                        ostringstream sin2;
		                            labels.push_back("L");
			                          sin2 << "L" << label_size;
    		                        labels[labels.size()-1] = sin2.str(); label_size++;
				                        output << "?:= " << labels[labels.size()-1] << ", " << $1 << endl;
				
                                if($2 != NULL)
				                        {
                                  pemp_type pemp;
	                                pemp.name="p";
	                                pemporary.push_back(pemp);

	                                ostringstream sin;
	                                sin << pemporary.size()-1;
	                                pemporary[pemporary.size()-1].name += sin.str();
                                            
                                  if (boolian == AND_b)
                                  {
                                    output << "&& " << pemporary[pemporary.size()-1].name << ", " << $1 << ", " << $2 << endl;
					                          strcpy($$,pemporary[pemporary.size()-1].name.c_str());
                                  }
				                          else if (boolian == OR_b)
                                  {
				                            output << "|| " << pemporary[pemporary.size()-1].name << ", " << $1 << ", " << $2 << endl;
				                            strcpy($$,pemporary[pemporary.size()-1].name.c_str());
				                          } 
				                        }
				                        else
                                {
					                        $$ = $1;
                                }
                              }
         ;

bool_exp2: AND rel_exp1 bool_exp2{$$ = $2; boolian = AND_b;}
         | OR rel_exp1 bool_exp2{$$ = $2; boolian = OR_b;}
         | {$$ = NULL;}
         ;

rel_exp1: NOT rel_exp2 {$$ = '!' + $2}
        | rel_exp2 {$$ = $1}
        ;

rel_exp2: TRUE {$$="TRUE"}
        | FALSE {$$="FALSE"}
        | expression1 comp1 expression1 { 
                                          pemp_type pemp;
                                          //add p to the pemp.name
	                                        pemp.name="p";
                                          //push pemp into pemporary with out adding the # to p
	                                        pemporary.push_back(pemp);

	                                        ostringstream sin;
	                                        sin << pemporary.size()-1;

                                          //add # to the name of last inserted element
	                                        pemporary[pemporary.size()-1].name += sin.str();

                                          output << $2 << " " << pemporary[pemporary.size()-1].name << ", " << $1 << ", " << $3 << endl;//output the line
	  
                                          //Compare if its false
                                          pemp_type pemp1;//make p temp type
                                          pemp1.name="p";//add p to the pemp.name
                                          pemporary.push_back(pemp1);//push pemp into pemporary with out adding the # to p
                                          ostringstream fin;
                                          fin << pemporary.size()-1;
                                          pemporary[pemporary.size()-1].name += fin.str();//add # to the name of last inserted element
                                          output << "== " << pemporary[pemporary.size()-1].name << ", " << pemporary[pemporary.size()-2].name << ", 0" << endl;//output the line					
                                          strcpy($$,pemporary[pemporary.size()-1].name.c_str());						                                        
                                        }
        ;

comp1: EQUAL {$$ = "==";} 
     | NEQ   {$$ = "!=";}
     | LT    {$$ = "<";}
     | GT    {$$ = ">";}
     | LTE   {$$ = "<=";}
     | GTE   {$$ = ">=";}
     ;

%%
void yyerror (const char* msg)
{
}

//helper function to check if a variable is being redeclared
bool is_var_declared(string input)
{
  //check to see if the new var is the same name at the program name
  if (input == program_name)
  {
    return true;
  }

  input = "_" + input;

  //check to see if the component is in the symbol table
  for (unsigned int i = 0;i < symbol_table.size(); i++)
  {
    if (input == symbol_table[i].name)
    {
      return true;
    }
  }
  return false;
}

//helper function to test if a array has been declared a valid size
bool valid_size(int size)
{
  if (size > 0)
  {
    return true;
  }

  return false;
}

//helper function to test if a variable is being accessed correctly
bool is_array(string input)
{
  input = "_" + input;

  //check to see if the component is in the symbol table
  for (unsigned int i = 0;i < symbol_table.size(); i++)
  {
    if (input == symbol_table[i].name)
    {
      if (symbol_table[i].type == ARRAY_TYPE)
      {
        return true;
      }
      else
      {
        return false;
      }
    }
  }  
  return false;
}

int main(int argc, char **argv)
{

  ostringstream final;
  ofstream myfile;

  if (argc > 1)
  {
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) 
    {
      cout << "Unable to open the input file";
      exit(1); 
    }
  }

  yyparse();

  if (error_flag == true)
  {
    cout << errors.str();
    cout << "...as a result of semantic errors no mil code will be generated." << endl;
  }
  else
  {
    final << variables.str();

    for(unsigned int i = 0; i < temporary.size(); i++)
    {
      final << ". " << temporary[i].name << endl;
    }

    for(unsigned int i = 0; i < pemporary.size(); i++)
    {
      final << ". " << pemporary[i].name << endl;
    }

    final << output.str();

    //cout << final.str();

    myfile.open ("output.txt");
    myfile << final.str();
    myfile.close();

    cout << "mil code has been successfully created." << endl;
  }

  return 0;
}
