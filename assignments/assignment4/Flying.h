#ifndef FLYING_H
#define FLYING_H
#include "Pokemon.h"
#include <string>
using namespace std;

class Flying:public Pokemon {
   private:
      string name; //specific type
      int stage; //1, 2, or 3
   public:
      Flying();
      bool capture_Pokemon();
      string get_Poke_type();
      string getName();
      void setName(string &);

      int getStage();
      void setStage(int);


};
#endif
