#include "structs.h"
class cart{
   private:
      book *books;
      int num_books;
      void resize_books(int);
   public:
      cart(); //non-default constructor
      cart(const cart &); //copy constructor
      ~cart(); //destructor
      void operator=(const cart&);

      book * get_books() const;
      void set_books(const int, const book &);

      int get_num_books() const;
      void set_num_books(const int);

  /*    void add_to_cart(const book &);
      void display_books();
      void empty_cart();*/
};
