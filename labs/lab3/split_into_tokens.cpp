#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
   ifstream ifile;
   //ofstream ofile;
   //ofile.open("temp.txt");
   char temp[256],* temp2;
   ifile.open("books_data.txt");
   
   cout << temp << endl;
   temp2= strtok(temp, "|" );
   while(temp2!=NULL){
      cout << temp2 << endl;
      temp2=strtok(NULL, "|%" );
   }
   /*while(ifile.eof()==false){

      ifile.getline(temp,256);
      ofile << temp << endl;
   }
   ofile << "Basketball | louis Sachar | 1998 | 1 %" << endl;
   remove("books_data.txt");
   rename("temp.txt" , "books_data.txt");
   */
   return 0;
}
