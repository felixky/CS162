#include <iostream>
#include <string>
using namespace std;
class librarian{
   private:
      string name;
      int id;
   public:
      librarian();
      string get_name() const;
      void set_name(string &);

      int get_id() const;
      void set_id(int &);

    //  void change_library_hours();
      void add_new_books();
      void remove_old_books();
    //  void view_all_books_checked_out();
    //  void view_specific_book_checked_out(string);
};
