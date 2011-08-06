#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Data
{
int type;
string name;
	
};
int main()
{
vector<Data> symbolTable;

Data temp;
temp.type =-2;
temp.name = "program";

symbolTable.push_back(temp);

cout << symbolTable.size()<<endl;

cout<<"Type: " <<symbolTable[0].type <<" Name: "<<symbolTable[0].name<<endl;

return 0;
}
