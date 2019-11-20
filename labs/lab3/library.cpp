/************************************************************
** Program: library.cpp
** Author: Kyle Felix
** Description: Function definitins for the class library.
** Input: None
** Output: Library class info.
************************************************************/
#include "library.h"
#include <iostream>
#include <fstream>

using namespace std;
/***********************************************************
** Function: Library
** Description: default constructor
** parameters: None
** Pre-Conditions: None
** Post-Conditions: Each private member has a value
** Return: None
**********************************************************/
library::library() : p("Kyle"){
   num_books=9;
   books=new book[num_books];
   p.set_id(1029);
   for(int i=0;i<7;i++){
      week[i].begin_time=1000;
      week[i].end_time=2030;
   }      
}

/***********************************************************
** Function: Library
** Description: copy constructor
** parameters: Library address
** Pre-Conditions: None
** Post-Conditions: Everything is copied to the new library
** Return: None
**********************************************************/
library::library(const library &other){
   num_books=other.num_books;
   if(num_books==0)
      books=NULL;
   else{
      books=new book[num_books];
      for(int i=0;i<num_books;i++){
	 books[i]=other.books[i];
         
      }
   }
   for(int i=0;i<7;i++){
      week[i].begin_time=other.week[i].begin_time;
      week[i].end_time=other.week[i].end_time;
   }      
}

/***********************************************************
** Function: ~library
** Description: deletes the dynamic memory
** parameters: None
** Pre-Conditions: None
** Post-Conditions: All memory is deleted
** Return: None
**********************************************************/
library::~library() {
   for(int i=0;i<num_books;i++)
      delete [] books[i].authors;
   delete [] books;
}

/***********************************************************
** Function: operator=()
** Description: assignment overload operator
** parameters: Address of a new library
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::operator=(const library &other){
   for(int i=0;i<num_books;i++)
      delete [] books[i].authors;
   delete [] books;
   num_books=other.num_books;
   if(num_books==0)
      books=NULL;
   else{
      books=new book[num_books];
      for(int i=0;i<num_books;i++){
	 books[i]=other.books[i];
         
      }
   }

}

/***********************************************************
** Function: get_patron
** Description: access patron info
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Patron info
**********************************************************/
patron library:: get_patron() const{
   return p;
}

/***********************************************************
** Function: set_patron
** Description: Gives you access to change the info in patron
** parameters: The address of variable patron
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::set_patron(const patron &p){
   this->p=p;
}

/***********************************************************
** Function: get_librarian
** Description: Gives you access to librarian info
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: librarian info
**********************************************************/
librarian library:: get_librarian() const{
   return l;
}

/***********************************************************
** Function: set_librarian
** Description: Gives you access to change librarian info
** parameters: Address of the librarain info
** Pre-Conditions: None
** Post-Conditions: The info was changed
** Return: None
**********************************************************/
void library::set_librarian(const librarian &l){
   this->l=l;
}

/***********************************************************
** Function: get_cart
** Description: gives access to cart info
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: A cart
**********************************************************/
cart library:: get_cart() const{
   return c;
}

/***********************************************************
** Function: set_cart
** Description: gives access to change contents of the cart
** parameters: An address of a cart
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::set_cart(const cart &c){
   this->c=c;
}
      
/***********************************************************
** Function: get_hours
** Description: Gives the time of a certain day
** parameters: A day number
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
hours library::get_hours(int day) const{
   day-=1; //arrays start at 0 and i asked for the day starting at 1
   cout << "Opening time: " << week[day].begin_time << endl;
   cout << "Closing time: " << week[day].end_time << endl;
   
   return week[day];
}

/***********************************************************
** Function: set_hours
** Description: Allows you to change hours for a certain day
** parameters: Pointer to a library and a day
** Pre-Conditions: None
** Post-Conditions: The time is changed on a certain day
** Return: None
**********************************************************/
void library::set_hours(library *l, int day){
   double open, end;
   int K;
   K=day-1;
      cout <<"Enter opening time(military time): ";
      cin >> open;
      l->week[K].begin_time=open; //Changes the time in the library
      cout << "Enter closing time(military time): ";
      cin >> end;
      l->week[K].end_time=end;
}


/***********************************************************
** Function: get_books
** Description: prints all the books in the book file
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: Address of books
**********************************************************/
book * library::get_books() const{
   char temp[256];
   ifstream input;
   input.open("books_data.txt"); //Prints out the books_data file to the screen
   cout <<"     Title     |     Author     |     Year     |     Number of copies " << endl;
   while(input.eof()==false && input.is_open()){
      input.getline(temp, 256);
      cout << temp << endl;

   }
   input.close();
   return books;
}

/***********************************************************
** Function: set_books
** Description: Changes number of books in library
** parameters: array of books
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::set_books(const book *books){
}

/***********************************************************
** Function: get_num_books
** Description: returns number of books
** parameters: none
** Pre-Conditions: none
** Post-Conditions: A number will be returned
** Return: Number of books
**********************************************************/
int library::get_num_books()const {
   return num_books;
}

/***********************************************************
** Function: set_num_books
** Description: changes number of books
** Parameters: number of books in library
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::set_num_books(const int &num_books){
   this->num_books=num_books;
}

      
/***********************************************************
** Function: display_weekly_hours
** Description: Prints hours for each day of the week.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void library::display_weekly_hours(){
   for(int i=0;i<7;i++){
      if(i==0)
	 cout << "Monday: " ;
      if(i==1)
	 cout << "Tuesday: " ;
      if(i==2)
	 cout << "Wednesday: " ;
      if(i==3)
	 cout << "Thursday: " ;
      if(i==4)
	 cout << "Friday: " ;
      if(i==5)
	 cout << "Saturday: " ;
      if(i==6)
	 cout << "Sunday: " ;
 
      cout << week[i].begin_time << "-" << week[i].end_time << endl; //Prints the opening and closing times for everyday of the week
   }

}






