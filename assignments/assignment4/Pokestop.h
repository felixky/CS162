#ifndef POKESTOP_H
#define POKESTOP_H
#include "Event.h"
#include <string>
#include <iostream>

class Pokestop:public Event {
   private:
      Event * PS;
   public:
      Pokestop();  
      Event * getEvent();
      void setEvent(Event *);
      
      int give_pokeballs();

};
#endif
