#ifndef POKEMON_H
#define POKEMON_H
#include "Event.h"
#include <string>
#include <iostream>
using namespace std;

class Pokemon:public Event {
   private:
      string name;
      Event * PM;
      int stage;
   public:
      Pokemon();
      virtual string get_Poke_type();
      virtual bool capture_Pokemon();
      Event * getEvent();
      void setEvent(Event *);

      int getStage();
      void setStage(int);

};
#endif
