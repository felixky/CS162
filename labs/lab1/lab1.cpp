#include <iostream>
#include <cstdlib>
#include <cctype>
#include "./mult_div.h"
using namespace std;

/*struct mult_div_values {
   int mult;
   float div;
};
void check(int &rows,int &cols);
void set_mult_values(mult_div_values **table, int m, int n);
void set_div_values(mult_div_values **table, int m, int n);
void delete_table(mult_div_values **table, int m, int n);   
struct mult_div_values** create_table(mult_div_values **table, int m, int n);

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
}*/

void check(int &rows,int &cols){
   bool good=false;
   while(good==false){
      if(rows>0 && cols>0)
	 good=true;
      else{
	 cout<< "Either rows or columns are not greater than 0. Enter new values." << endl;
	 cout << "Rows: ";
	 cin >> rows;
	 if(cin.fail()==true){
	    cin.clear();
	    cin.ignore();
	    cout<< "Not a vaild input."<< endl;
	 }
	 cout << "Columns: ";
	 cin >> cols;
	 if(cin.fail()==true){
	    cin.clear();
	    cin.ignore();
	    cout<< "Not a vaild input."<< endl;
	 }
      }

   }
}

struct mult_div_values** create_table(mult_div_values **table, int m, int n){
	struct mult_div_values **temp;
   temp= new struct mult_div_values*[m];
   for(int i=0;i<m;i++)
      temp[i]=new struct mult_div_values[n];
return temp;
}

void set_mult_values(mult_div_values **table, int m, int n){
   int total=1, temp=1, r=1;
   cout << "Multiplication Table:" << endl;
   for(int k=0;k<m;k++){
      for(int i=0;i<n;i++){
         table[k][i].mult=temp;
         temp+=r;
      }
      ++total;
      temp=total;
      r=total;
      
   }
   for(int k=0;k<m;k++){
      for(int i=0;i<n;i++){
         cout << table[k][i].mult << " ";
      }
      cout << endl;
   }
cout << endl;
}

void set_div_values(mult_div_values **table, int m, int n){

   float total=1.0, temp=1.0, r=1.0;
   cout << "Divison Table:" << endl;
   for(int k=0;k<m;k++){
      for(int i=0;i<n;i++){
         table[k][i].div=temp;
	 if(temp<total)
	    temp=total;
         temp/=(++r);
      }
      ++total;
      temp=total;
      r=1.0;
      
   }
   for(int k=0;k<m;k++){
      for(int i=0;i<n;i++){
         cout << table[k][i].div << " ";
      }
      cout << endl;
   }

cout << endl;
}

void delete_table(mult_div_values **table, int m, int n){
   for(int i=0;i<n;i++)
     delete [] table[i];
   delete []table;
   table=NULL;
}




