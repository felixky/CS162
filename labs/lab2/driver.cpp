#include "./f.h"
#include <string>
int main(int argc, char **argv){
   ifstream ifile;
   char *file_name;
   file_name=new char[50];

   file_name=argv[1];
   ifile.open(file_name);
   if(ifile.is_open()==false){
      cout<< "Enter a new filename: " ;
      cin >> file_name;
      ifile.open(file_name);
   }
   create_html(ifile);

   //delete [] file_name;
return 0;
}
