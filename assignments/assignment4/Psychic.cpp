#include "Psychic.h"
#include <string>
#include <cstdlib>
/**************************************************************************
 * Function: default constructor
 * Description: Default values are assigned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Psychic::Psychic() {
   name="Abra";
   stage=1;
}
/**************************************************************************
 * Function: capture_Pokemon
 * Description: random number generated to catch pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: true or false
**************************************************************************/
bool Psychic::capture_Pokemon() {
   int x;
   x = rand() %4;
   cout << "You found a " << name << "! Press enter to throw a pokeball! ";
   cin.ignore();
   cin.ignore();
#ifdef DEBUG
   x=0;
#endif
   if(x==0 ){
      cout << "You caught the Psychic type!" << endl;
      return true;
   }
   else
      cout << "The Pokemon ran away..." << endl;
      return false;
}
/**************************************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 * Return:
**************************************************************************/
string Psychic::get_Poke_type() {
   string c="Psychic";
   return c;
}

/**************************************************************************
 * Function: getName
 * Description:  returns name
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: string name
**************************************************************************/
string Psychic::getName() {
   return name;
}

/**************************************************************************
 * Function: setName
 * Description: A new name is set from the user
 * Parameters: A string a
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Psychic::setName(string &a) {
   name=a;
}

/**************************************************************************
 * Function: getStage
 * Description: returns the stage of the pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: The Stage as an iteger
**************************************************************************/
int Psychic::getStage() {
   return stage;
}

/**************************************************************************
 * Function: setStage
 * Description: The stage is increased by 1
 * Parameters: AN integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Psychic::setStage(int a) {
   stage=1;
}
