#include "World.h"


/**************************************************************************
 * Function: default constructor
 * Description: Sets the total pokemon in the game to 12 
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
World::World() {
   total_Pokemon=12;

}

/**************************************************************************
 * Function: getTrainer
 * Description: returns a ptr to the trainer class
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Trainer *
**************************************************************************/
Trainer World::getTrainer() {
   return *(&T);
}

/**************************************************************************
 * Function:getLocation
 * Description: returns a location ptr
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Loaction address
**************************************************************************/
Location * World::getLocation() {
   return &(*L);
}

/**************************************************************************
 * Function: get_Event
 * Description: returns an event *
 * Parameters: an integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: Event*
**************************************************************************/
Event * World::get_Event(int a) {
   return E[a];
}      
      
/**************************************************************************
 * Function:setPokemon
 * Description: Sets a Pokemon in the array of Pokemon
 * Parameters: and index and a Pokemon
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void World::setPokemon(int a, Pokemon c) {
   P[a]=c;
}
/**************************************************************************
 * Function: setEvent
 * Description: Sets the event for this class' array and the event .
 * Parameters: an index and an Event *
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void World::setEvent(int a, Event *c) {
  E[a]= c;
  (*E[a]).setEvent(c);
} 

/**************************************************************************
 * Function: getSinglePokemon
 * Description: Returns a Pokemon
 * Parameters: An integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: A Pokemon *
**************************************************************************/
Pokemon World::getSinglePokemon(int a) {
   return P[a];
} 

/**************************************************************************
 * Function: getTotal_Pokemon
 * Description: returns the number of Pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An integer
**************************************************************************/
int World::getTotal_Pokemon() {
   return total_Pokemon;
}

/**************************************************************************
 * Function: setTotal_Pokemon
 * Description: Adds a Pokemon
 * Parameters: An integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void World::setTotal_Pokemon(int a) {
   total_Pokemon += a;
}
