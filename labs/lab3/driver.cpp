/*********************************************************************************
** Program: main.cpp
** Author: Kyle Felix
** Date: April 30, 2017
** Description: This program is a simple online library.
** Input: Inputs are user commands and a database of books.
** Output: This program outputs based on user input. 
*********************************************************************************/
#include <iostream>
#include "library.h"
#include <fstream>
#include <cstdlib>

void day_week_hours(library &);
void patron_login(library &);
void librarian_login(library &);
void patron_books(library &, int);
void librarian_books(library &, int);

/******************************************************************************
** Function: int main
** Description: Front of program and is where the program loops through all options.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: The program is over.
** Return: 0
*****************************************************************************/
int main(){
   library l;
   int choice=1;
   while(choice!=4){ //Loop to continuously ask user what they want to do
      cout << "Do you want to view hours(1), login as a patron(2), login as a librarian(3), or quit(4)? Enter a number response: " ;
      cin >> choice;
     
      if(choice==1)
         day_week_hours(l);
      if(choice==2)
         patron_login(l);
      if(choice==3)
         librarian_login(l);
      if(choice==4)
	 return 0;
      else if(choice==0){
	 cout << "You entered an invalid number." << endl; //Error checking for input above
         while(cin.fail()){
            cin.clear();
	    cin.ignore();
         } 
      }
   }
}
/******************************************************************************
** Function: void day_week_hours()
** Description: If the user does not login, they can view hours in this function.
** Parameters: The address of the library created in main.
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
*****************************************************************************/
void day_week_hours(library &l){
   int ans;
   cout << "Would you like hours for the whole week(1) or a certain day(2)?" ;
   cin >> ans;

   if(ans==1)
      l.display_weekly_hours();
   if(ans==2){
      cout << "What day?(Mon(1), Tue(2), Wed(3), Thurs(4), Fri(5), Sat(6), or Sun(7)): ";
      cin >> ans;
      l.get_hours(ans); //take the day number input and displays those hours
   }
}
/******************************************************************************
** Function: void patron_login()
** Description: A patron logs in here and is sent to other functions based on their choices.
** Parameters: The address of the library so the patron can edit its contents.
** Pre-Conditions: None
** Post-Conditions: The patron has already decided what they are doing. Searching, view books or cart or loging out.
** Return: None
*****************************************************************************/
void patron_login(library &l){
   int code, choice, login;
   char temp[256];
   ifstream p_login; 
   cout << "Enter yourr 4 digit patron login code or type 0 to exit: ";
   cin >> code;

   while(code!=0){
      p_login.open("patron_login.txt"); //patron login info
      while(p_login.eof()==false){ //runs through all the possible id numbers
	 p_login >> login; //id number
	 p_login.getline(temp,256); //Name with the id
      	 if(code==l.get_patron().get_id() || code==login){ //compares it to the default constructor and the patron login file
            while(code!=0){
	       cout << "Hello" << temp << "." << " Would you like to view the database of books(1), search for a book(2), view your cart(3), check out a book(4), or logout(0)? ";
               cin >> choice;
	       if(choice==0)
	          return;
               patron_books(l, choice);
	    }
         }
      }
         if(code>0 && code!=l.get_patron().get_id()){ //If the code goes through here none of the id's were the same as the users code
            cout << "You entered an incorrect id. Would you like to try again? Yes(1) or No(0): ";
            cin >> choice;
            if(choice==0)
	       return;
            else{
               cin.clear();
               cin.ignore();
               cout << "Enter your 4 digit patron login code or type 0 to exit: ";
               cin >> code;
	       p_login.close(); //I close the file here so the file will be reopened at the top and be at the top of the txt file
            }   
         } 
   }
   p_login.close();
} //25 lines

/******************************************************************************
** Function: void patron_books
** Description: The patron views the books, searches for one, views their cart, or changes their personal data.
** Parameters: An address of the library and the choice from the previous function.
** Pre-Conditions: A choice between 1 and 4 is already made.
** Post-Conditions: None
** Return: None
*****************************************************************************/
void patron_books(library &l, int choice){
   char temp[256], search[256];
   if(choice==1){
     l.get_books(); //Function in library
   }
   else if(choice==2){
      cout << "Enter the title or author of the book: ";
      cin.ignore();
      cin.getline(search,256);
      l.get_patron().search_books(search); //Searches for a books with the given input
   }
   else if(choice==3){
      l.get_patron().view_my_books(); //Prints out the contents of my_books
   }
   else if(choice==4){
     cout <<"I didn't get this to work yet" << endl;
   }
}

/******************************************************************************
** Function: void librarian_login()
** Description: A librarian logs in here and is sent to other functions based on their choices.
** Parameters: An address of the library.
** Pre-Conditions: None
** Post-Conditions: A choice of what the user wants to do has been made.
** Return: None
*****************************************************************************/
void librarian_login(library &l){
   int code, choice, login;
   char temp[256];
   ifstream l_login;
   cout << "Enter yourr 4 digit librarian login code or type 0 to exit: ";
   cin >> code;
   
   while(code!=0){
      l_login.open("librarian_login.txt"); //Librarian id's
      while(l_login.eof()==false){ //reads untill the end of the file
	 l_login >> login;
	 l_login.getline(temp,256);
         if(code==l.get_librarian().get_id() || code==login){
	    while(code!=0){
	       cout << "Hello" << temp << "." << " Would you like to change operation hours(1), remove old books(2), add new books(3), view checked out books(4), or logout(0)? ";
               cin >> choice;
	       if(choice==0)
	          return;
               librarian_books(l, choice);
	    }
         }
      }
      if(code>0 && code!=l.get_librarian().get_id()){
         cout << "You entered an incorrect id. Would you like to try again? Yes(1) or No(0): ";
         cin >> choice;
         if(choice==2)
	    return;
         else{
            cin.clear();
            cin.ignore();
            cout << "Enter your 4 digit librarian login code or type 0 to exit: ";
            cin >> code;
	    l_login.close(); //Close it here to be at the top of the txt file when I reopen it
         }   
      }
   }
   l_login.close();
} //26 lines

/******************************************************************************
** Function: librarian_books()
** Description: The librarian can change hours, add/remove books, and view checked out books.
** Parameters: An address of the library and the choice from the previous function.
** Pre-Conditions: A choice has alredy been made.
** Post-Conditions: None
** Return: None
*****************************************************************************/
void librarian_books(library &l, int choice){
   char temp[256], search[256];
   int day, stay=1;
   if(choice==1){
      while(stay!=0){ //Looped to change multiple days at once
         cout << "Which day do you want to change hours for? (Mon(1)...Sund(7)) "; //change operation hours in here
         cin >> day;
	 if(day==0)
	    return;
	 l.set_hours(&l, day);

	 cout << "Do you want to change anothr days operation hours? Yes(1) or No(0): ";
	   cin >> stay;
      }
   }
   else if(choice==2){
      l.get_librarian().remove_old_books();//remove old books
   } //This is not writing to my new file correctly
   else if(choice==3){
      l.get_librarian().add_new_books(); // adds new books to the book database 
   }
   else if(choice==4){
     l.get_patron().view_my_books(); //view checked out books
   } //Prints out the contents of my_books.txt file
}























