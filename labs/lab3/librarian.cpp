#include "librarian.h"
#include <cstring>
#include <fstream>
/******************************************************
 * Function: default constructor
 * Description: Defalut values when a library is created
 * Parameters: None
 * Pre-Conditions: None
 * Post-Coditions: None
*****************************************************/
librarian::librarian() : name("Martha") {
   id=1224;
}

/******************************************************
 * Function: get_name()
 * Description: The librarians name is returned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Coditions: None
*****************************************************/
string librarian::get_name() const{
   return name;

}
/******************************************************
 * Function: set_name()
 * Description: The user can set the librarians name
 * Parameters: A string
 * Pre-Conditions: None
 * Post-Coditions: none
*****************************************************/
void librarian::set_name(string &name){
   this->name=name;

}

/******************************************************
 * Function: get_id
 * Description: The librarian id is returned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Coditions: None
*****************************************************/
int librarian::get_id() const{
   return id;
}

/******************************************************
 * Function: set_id
 * Description: Allows the user to set the id of the librarian.
 * Parameters: an id number
 * Pre-Conditions: A number is provided in the call
 * Post-Coditions: None
*****************************************************/
void librarian::set_id(int &id){
   this->id=id;
}

/******************************************************
 * Function: add_new_books
 * Description: Appends a book to the end of the books file.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Coditions: A book is added to the books file.
*****************************************************/
void librarian::add_new_books(){
   ifstream ifile;
   ofstream ofile;
   char temp[256], title[256],author[256];
   int year, copies, num_authors;
   
   ofile.open("temp.txt", ios::app);
   ifile.open("books_data.txt");
   while(ifile.eof()==false){

      ifile.getline(temp,256);
      if(strlen(temp)>0)
         ofile << temp << endl;
   }
   cin.ignore();
   cout << "Enter the title of the book: "; //I get all the book information here
   cin.getline(title,256);
   ofile << title << " | ";
   cout << "How many authors are there: ";
   cin >> num_authors;
   for(int i=0; i<num_authors;i++){
      cout << "Type in an authors name: ";
      cin.ignore();
      cin.getline(author,256);   
      ofile << author << ", ";
   }
   cout << "Enter the year of publication: ";
   cin >> year;
   cout << "Enter number of copies being added: ";
   cin >> copies;   
   ofile << " | " << year << " | " << copies << " >" << endl;
   remove("books_data.txt"); //Delete the old file 
   rename("temp.txt" , "books_data.txt"); //Create a new file and rename it the sames as the old file
   ifile.close();
   ofile.close();
} //25 lines

/******************************************************
 * Function: remove_old_books
 * Description: removes a books from the file of books
 * Parameters: None
 * Pre-Conditions: None
 * Post-Coditions: The Books has been removed
*****************************************************/
void librarian::remove_old_books(){
   ifstream ifile;
   ofstream ofile;
   ofile.open("temp.txt");
   ifile.open("books_data.txt");
   char temp[256], name[256], *temp3, temp2[256];
   cout << "Enter the whole book title to remove: ";
   cin >> name;
   while(ifile.eof()==false){
      ifile.getline(temp,256);
      for(int i=0;i<256;i++)
	 temp2[i]=temp[i];
      temp3=strtok(temp,"|>"); //Not writing files properly
      if(temp3!=NULL && strcmp(temp3,name)!=0){
         ofile << temp2 << endl;
      } 
   }
   remove("books_data.txt"); 
   rename("temp.txt" , "books_data.txt");
   ifile.close();
   ofile.close();
}



