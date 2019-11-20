#ifndef CAVE_H
#define CAVE_H
#include "Event.h"
#include <string>
#include <iostream>
class Cave:public Event {
   private:
      Event * C;
   public:
      Cave();
      Event* getEvent();
      
      void setEvent(Event *);
      int get_stone();

};
#endif
