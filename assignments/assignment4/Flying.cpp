#include "Flying.h"
#include <string>
#include <cstdlib>

/**************************************************************************
 * Function: default constructor
 * Description: default values are assigned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Flying::Flying() {
   name="Pidgey";
   stage=1;
}

/**************************************************************************
 * Function: capture_Pokemon
 * Description: Random chance at capturing a Pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: true or false
**************************************************************************/
bool Flying::capture_Pokemon() {
   int x;
   x = rand() %4;
   cout << "You found a " << name << "! Press enter to throw a pokeball! ";
   cin.ignore();
   cin.ignore();
#ifdef DEBUG
   x=0;
#endif
   if(x==0 || x==1 ){
      cout << "You caught the Flying type!" << endl;
      return true;
   }
   else
      cout << "The Pokemon ran away..." << endl;
      return false;
}
/**************************************************************************
 * Function: get_Poke_type
 * Description: Returns type as flying
 * Parameters: None
 * Pre-Conditions: NOne
 * Post-Conditions: None
 * Return: a string
**************************************************************************/
string Flying::get_Poke_type() {
   string c="Flying";
   return c;
}

/**************************************************************************
 * Function: getName
 * Description: returns the Pokemons name
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: string
**************************************************************************/
string Flying::getName() {
   return name;
}

/**************************************************************************
 * Function: setName
 * Description: Sets a new name
 * Parameters: a string
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Flying::setName(string &a) {
   name=a;
}

/**************************************************************************
 * Function: getStage
 * Description: The pokemons stage is returned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: integer stage
**************************************************************************/
int Flying::getStage() {
   return stage;
}

/**************************************************************************
 * Function: setStage
 * Description: the stage is increased by 1
 * Parameters: an integer
 * Pre-Conditions: None
 * Post-Conditions: NOne
 * Return: None
**************************************************************************/
void Flying::setStage(int a) {
   stage+=1;
}
