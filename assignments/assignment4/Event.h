#ifndef EVENT_H
#define EVENT_H
/*
 * This class is pure virtual so no Event.cpp is needed
*/
#include <iostream>
#include <string>
using namespace std;

class Event {
   protected:
   public:
      virtual Event* getEvent()=0;
      virtual void setEvent(Event *)=0;
};
#endif
