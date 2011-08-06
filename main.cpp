#include <iostream>
#include "database.h"

using namespace std;

int main()
{
  int rows;
  db mydb;
  mydb.db_init();

  mydb.insert_ip("127.0.0.1");
  mydb.insert_ip("68.90.134.234");
  mydb.insert_server("59.9.223.54");
  cout << "hello"<<endl;
  mydb.insert_file("asdf.xps","127.0.0.1");
  cout << "hello"<<endl;
  mydb.clearBuffer();
    cout << "hello"<<endl;
  rows = mydb.search_file("asdf.xps");
  cout << "hello"<<endl;
  cout << "server ip with file asdf.xps\n";
  for( int i = 0; i < rows; i++ )
    {
      string s = mydb.getBuffer(i);
      cout << s << endl;
    }

  mydb.clearBuffer();
  rows = mydb.get_serverip();

  cout << "server ip:\n";
  for( int i = 0; i < rows; i++ )
    {
      string s = mydb.getBuffer(i);
      cout << s << endl;
    }

  mydb.clearBuffer();
  rows = mydb.get_clientip();

  cout << "client ip:\n";
  for( int i = 0; i < rows; i++ )
    {
      string s = mydb.getBuffer(i);
      cout << s << endl;
    }

  return 0;
}
