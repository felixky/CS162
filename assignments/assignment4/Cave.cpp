#include "Cave.h"
#include <cstdlib>
#include <string>
#include <iostream>
/**************************************************************************
 * Function: default constructor
 * Description: Sets the Event ptr to Null
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Cave::Cave() {
   C=NULL;
}

/**************************************************************************
 * Function: setEvent
 * Description: makes this cave an event ptr.
 * Parameters: An event ptr
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Cave::setEvent(Event *a) {
   C=a;
}

/**************************************************************************
 * Function: get_stones
 * Description: gives 1 stone
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: integer
**************************************************************************/
int Cave::get_stone() {
   return 1;
}
      
/**************************************************************************
 * Function: getEvent
 * Description: returns an event ptr
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Event *
**************************************************************************/
Event * Cave::getEvent() {
   return C;
}
