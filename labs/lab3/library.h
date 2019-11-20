#include "patron.h"
//#include "structs.h"
#include "cart.h"
#include "librarian.h"

class library{
   private:
      hours week[7];
      int num_books;
      book *books;
      cart c;
      librarian l;
      patron p;
   public:
      library(); //default constructor
      library(const library &); //copy constructor
      ~library(); //destructor
      void operator=(const library &);

      patron get_patron() const;
      void set_patron(const patron &); 
      
      librarian get_librarian() const;
      void set_librarian(const librarian &);

      cart get_cart() const;
      void set_cart(const cart &);

      book* get_books() const;
      void set_books(const book*);
     
      int get_num_books() const;
      void set_num_books(const int &num_books);

      hours get_hours(int) const;
      void set_hours(library *, int);

      void display_weekly_hours();
};  
