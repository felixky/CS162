#ifndef LOCATION_H
#define LOCATION_H
#include "Event.h"

class Location {
   private:
      Event *event;
   public:
      Event * get_event();
      void set_event(Event *);
};
#endif
