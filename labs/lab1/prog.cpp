
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "./mult_div.h"
using namespace std;
int main(int argc, char *argv[]){
  struct mult_div_values **table; 
  int Q=2;
   int m=atoi(argv[1]), n=atoi(argv[2]);
  do{
   if(argc<3){
      cout << "Not enough arguments." << endl;
      return 0;
   }
   check(m, n);
   table=create_table(table,m, n);
   set_mult_values(table,m,n);
   set_div_values(table,m,n);
   cout << "Do you want to see a different size matrix (0-no, 1-yes)? ";
   cin >> Q;
   if(Q==1){
	 cout << "Rows: ";
	 cin >> m;
	 cout << "Columns: ";
	 cin >> n;
   }
   delete_table(table,m,n);   
  } while(Q==1);
return 0;
}
