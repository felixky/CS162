#include <iostream>
#include <string>
using namespace std;

struct hours{
   double begin_time;
   double end_time;
};

struct book{
   string title;
   int num_authors;
   string *authors;
   int year;
   int copies;
};
