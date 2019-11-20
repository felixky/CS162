#include "Pokemon.h"
#include <iostream>
#include <string>
#include  <cstdlib>
using namespace std;
   

/**************************************************************************
 * Function: Default constructor
 * Description: Sets the event ptr to NULL to begin
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Pokemon::Pokemon() {
   name = "Pokemon" ;
   PM=NULL;
}

/**************************************************************************
 * Function: getStage
 * Description: returns the stage of the pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: integer
**************************************************************************/
int Pokemon::getStage() {
   return stage;
}

/**************************************************************************
 * Function: capture_Pokemon
 * Description: Random number is generated to see if the pokemon is captured
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: True or false
**************************************************************************/
bool Pokemon::capture_Pokemon() {
   int x;
   x = rand() %4;
   cout << "You found a " << name << "! Press enter to throw a pokeball! ";
   cin.ignore();
   cin.ignore();
#ifdef DEBUG
   x=0;
#endif
   if(x==0 || x==1 || x==2){
      cout << "You caught a Pokemon!" << endl;
      return true;
   }
   else
      cout << "The Pokemon ran away..." << endl;
   return false;
}
/**************************************************************************
 * Function: setStage
 * Description: increases the stage by 1
 * Parameters: an integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Pokemon::setStage(int a) {
   stage += 1;
}

      
/**************************************************************************
 * Function: get_Poke_type
 * Description: returns a type of Pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: none
 * Return: string
**************************************************************************/
string Pokemon::get_Poke_type() {
   string c="Pokemon";
   return c;
}
      
/**************************************************************************
 * Function: getEvent
 * Description: Returns the event in the Pokemon class
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Event *
**************************************************************************/
Event * Pokemon::getEvent() {
   if(PM==NULL)
      cout << "What can I do now?" << endl;
   return PM;
}
      
/**************************************************************************
 * Function: setEvent
 * Description: sets the This Pokemon class to be a event
 * Parameters: an Event ptr
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Pokemon::setEvent(Event *a) {
   if(a==NULL)
      cout << "What can I do now?" << endl;
   PM=a;
   cout <<"AAAAAA" << endl;
}
