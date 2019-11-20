#include "cart.h"
/***********************************************************
** Function: cart()
** Description: default constructor
** parameters: None
** Pre-Conditions: None
** Post-Conditions:  None
** Return: None
**********************************************************/
cart::cart(){
   num_books=1;
   books = new book[num_books];
}

/***********************************************************
** Function: cart()
** Description: Non-default constructor
** parameters:  Another cart
** Pre-Conditions:  The old cart has values
** Post-Conditions: None
** Return: None
**********************************************************/
cart::cart(const cart &other){
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
** Function: ~cart()
** Description: Deletes the dynamic memory
** parameters:  None
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
cart::~cart(){
   for(int i=0;i<num_books;i++)
      delete [] books[i].authors;
   delete [] books;
}

/***********************************************************
** Function: operator=()
** Description: assignment overload operator
** parameters:  Another cart
** Pre-Conditions:  None
** Post-Conditions: None
** Return: None
**********************************************************/
void cart::operator=(const cart &other){
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
** Function: get_books()
** Description: return the address of books
** parameters: None
** Pre-Conditions: None
** Post-Conditions: None
** Return: A book*
**********************************************************/
book * cart::get_books() const{
   return books;
}

/***********************************************************
** Function: set_books
** Description: Create a larger or smaller array of books
** parameters:  A new number of books b and the address of the books in the cart
** Pre-Conditions: None
** Post-Conditions: If there are 0 books the array points to NULL
** Return: None
**********************************************************/
void cart::set_books(const int b, const book &book){

}

/***********************************************************
** Function: get_num_books()
** Description: returns the number of books
** parameters: None
** Pre-Conditions: None
** Post-Conditions: Noen
** Return: The integer number of books
**********************************************************/
int cart::get_num_books() const{
   return num_books;
}

/***********************************************************
** Function: set_num_books
** Description: Sets a new number of books
** parameters: A new number of books
** Pre-Conditions: None
** Post-Conditions: None
** Return: None
**********************************************************/
void cart::set_num_books(const int num_books){
   this->num_books=num_books;
}


