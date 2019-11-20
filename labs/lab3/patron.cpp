#include "patron.h"
#include <cstring>
#include <fstream>
#include <iostream>

/***********************************************************
** Function: patron()
** Description: default constructor
** parameters: None
** Pre-Conditions: None
** Post-Conditions: The private members all have an assigned value
** Return: None
**********************************************************/
patron::patron(): name("Kyle"){
   this->name=name;
   this->id=id;
   id=1029;
}
/***********************************************************
** Function: Patron
** Description: none default constructor
** parameters: A string 
** Pre-Conditions: A string is given in the function call
** Post-Conditions: None
** Return: None
**********************************************************/
patron::patron(string s){
   name=s;
   id=1029;
}

/***********************************************************
** Function: get_name
** Description: Returns the name of the patron
** parameters: None
** Pre-Conditions: NOne
** Post-Conditions: None
** Return: A string name
**********************************************************/
string patron::get_name()const{
   return name;
}

/***********************************************************
** Function: set_name()
** Description: Allows the user to change the name of the patron
** parameters: A string name
** Pre-Conditions: A name is provided in the call
** Post-Conditions: None
** Return: None
**********************************************************/
void patron::set_name(string &s){
   name=s;
}

/***********************************************************
** Function: get_id()
** Description: An id number is returned
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: An int id
**********************************************************/
int patron::get_id() const{
   return id;
}

/***********************************************************
** Function: set_id()
** Description: Allows the user to set a new id number
** parameters: A new id number
** Pre-Conditions: None
** Post-Conditions: The id numer is changed
** Return: None
**********************************************************/
void patron::set_id(const int &id){
   this->id=id;
}

/***********************************************************
** Function: get_books_checked_out
** Description: Returns the number of books checked out
** parameters: None
** Pre-Conditions: None
** Post-Conditions: Noen
** Return: Int 
**********************************************************/
int patron::get_books_checked_out() const{
   return books_checked_out;
}

/***********************************************************
** Function: set_books_checked_out
** Description: adds or subtracts from the number of books checked out
** parameters: Number of books checked out
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void patron::set_books_checked_out(const int &books_checked_out){
   this->books_checked_out+=books_checked_out;
}

/***********************************************************
** Function: view_my_books()
** Description: Prints out all books checked out
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void patron::view_my_books(){
   char temp[256];
   ifstream ifile;
   ifile.open("my_books.txt");
   if(ifile.is_open()==true){
      while(ifile.eof()==false){
         ifile.getline(temp, 256);
         cout << temp << endl;
      }
   }
   else
      cout << "You have not checked out any books." << endl;
ifile.close();
}

/***********************************************************
** Function: search_books()
** Description: Searches for a book in the database based on the title
** parameters: A char[] with the title of a book
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void patron::search_books(char search[256]){
   ifstream ifile;
   int total=0;
   char temp[256],* temp2;
   ifile.open("books_data.txt");
   while(ifile.eof()==false && temp2!=NULL){ 
      ifile.getline(temp, 256);
      temp2= strtok(temp, "|" );
      //cout << temp2 << endl;
      if(cin.eof()==true)
	 return;
      if(temp2[0]==search[0] && temp2[1]==search[1] && temp2[2]==search[2] && temp2[3]==search[3]){
         if(temp2!=NULL)
	    cout << temp2 << endl;
      }
      /*    while(temp2!=NULL){
         cout << temp2 << endl;
         temp2=strtok(NULL, "|>" );
         if(strcmp(temp2,search)==0){
            cout << temp << endl;
         }     
      }   */ 
   }
}


//void check_out_books(const cart &c){


//}





