#ifndef ROCK_H
#define ROCK_H
#include "Pokemon.h"
#include <string>
using namespace std;

class Rock:public Pokemon {
   private:
      string name; //Specific name like geodude
      int stage; //1, 2, or 3
      
   public:
      Rock();
      bool capture_Pokemon();
      string get_Poke_type();
      string getName();
      void setName(string &);

      int getStage();
      void setStage(int);
};
#endif
