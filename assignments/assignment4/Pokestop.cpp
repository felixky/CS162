#include "Pokestop.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

/**************************************************************************
 * Function: Default constructor
 * Description: Sets the Event ptr PS to NUll
 * Parameters: None
 * Pre-Conditions: Noen
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Pokestop::Pokestop() {
   PS=NULL;
}

/**************************************************************************
 * Function: give_pokeballs
 * Description: randomly gives 3-10 pokeballs to the user
 * Parameters: none
 * Pre-Conditions: noe
 * Post-Conditions: noe
 * Return: none
**************************************************************************/
int Pokestop::give_pokeballs() {
   int x;
   x = rand() %8;
   x+=3;
#ifdef DEBUG
   x=10;
#endif
   cout << "You gained " << x << " poke-balls." << endl;
   return x;
}
     
/**************************************************************************
 * Function: getevent
 * Description: returns an event ptr 
 * Parameters:None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Event *
**************************************************************************/
Event * Pokestop::getEvent() {
   return PS;
}
      
/**************************************************************************
 * Function: setEvent
 * Description: Sets the event in the class
 * Parameters: An Event * 
 * Pre-Conditions: None
 * Post-Conditions:None
 * Return: None
**************************************************************************/
void Pokestop::setEvent(Event *a) {
   PS=a;
}
