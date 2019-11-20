#ifndef PSYCHIC_H
#define PSYCHIC_H
#include "Pokemon.h"
#include <string>
using namespace std;

class Psychic:public Pokemon {
   private:
      string name; //Specific name
      int stage; //1, 2, or 3
   public:
      Psychic();
      bool capture_Pokemon();
      string get_Poke_type();
      string getName();
      void setName(string &);

      int getStage();
      void setStage(int);


};
#endif
