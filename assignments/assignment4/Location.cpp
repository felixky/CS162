#include "Location.h"


/**************************************************************************
 * Function: getEvent
 * Description: Returns the event at the users current location
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: Noen
 * Return: an Event *
**************************************************************************/
Event * Location::get_event() {
   return event;
}

/**************************************************************************
 * Function: setEvent
 * Description: sets the event * to One at the users current location
 * Parameters: An event *
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Location::set_event(Event *c) {
   event=c;
}
