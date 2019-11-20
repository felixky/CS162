#include <string>
//#include "cart.h"

using namespace std;

class patron{
   private:
      string name;
      int id;
      int books_checked_out;
   public:
      patron(); 
      patron(string); //non-default  
      string get_name()const;
      void set_name(string&);

      int get_id() const;
      void set_id(const int &);

      int get_books_checked_out() const;
      void set_books_checked_out(const int &);
      void search_books(char []);
   //   void check_out_books(const cart &);
   /*   void check_in_books(const cart &);*/
      void view_my_books();
};
