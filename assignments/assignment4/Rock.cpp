#include "Rock.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

/**************************************************************************
 * Function:default constructor
 * Description: Sets the generic name
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Rock::Rock() {
   name="geodude";
   stage=1;
}
/**************************************************************************
 * Function: get_Poke_type
 * Description: returns a the type
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: A string
**************************************************************************/
string Rock::get_Poke_type() {
   string c="Rock";
   return c;
}

/**************************************************************************
 * Function: capture_Pokemon
 * Description: Random number is generated to see if the pokemon is captured
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: True or false
**************************************************************************/
bool Rock::capture_Pokemon() {
   int x;
   x = rand() %4;
   cout << "You found a " << name << "! Press enter to throw a pokeball! ";
   cin.ignore();
   cin.ignore();
#ifdef DEBUG
   x=0;
#endif
   if(x==0 || x==1 || x==2){
      cout << "You caught the Rock type!" << endl;
      return true;
   }
   else
      cout << "The Pokemon ran away..." << endl;
   return false;
}

/**************************************************************************
 * Function: getName
 * Description: Returns name of Pokemon
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: string name
**************************************************************************/
string Rock::getName() {
   return name;
}

/**************************************************************************
 * Function: setName
 * Description: Sets the name to a user input
 * Parameters: String
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Rock::setName(string &a) {
   name=a;
}

/**************************************************************************
 * Function: getStage
 * Description: Returns pokemons stage
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An integer
**************************************************************************/
int Rock::getStage() {
   return stage;
}

/**************************************************************************
 * Function: setStage
 * Description: increases the stage by 1
 * Parameters: an integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Rock::setStage(int a) {
   stage=1;
}
