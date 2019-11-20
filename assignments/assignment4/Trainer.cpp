#include "Trainer.h"

/**************************************************************************
 * Function: Default constructor
 * Description: Sets default values for class
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
Trainer::Trainer():name("Ash") {
   //name="Harry";
   Pokeballs=0;
   num_Pokemon=0;
   num_stones=0;
}

/**************************************************************************
 * Function: getName
 * Description: returns the Trainners name
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: the trainers name
**************************************************************************/
string Trainer::getName() {
   return name;
}

/**************************************************************************
 * Function: setName
 * Description: Sets a new Name from the user input
 * Parameters: A string 
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::setName(string &a) {
   name=a;
}

/**************************************************************************
 * Function:getPokeballs
 * Description: returns the number of POkeballs the user has
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An integer of Pokeballs
**************************************************************************/
int Trainer::getPokeballs() {
   return Pokeballs;
}

/**************************************************************************
 * Function: setPokeballs
 * Description: Pokeballs are added or subtraacted from the users total
 * Parameters: an integer of Pokeballs
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::setPokeballs(int &a) {
   Pokeballs+=a;
}

/**************************************************************************
 * Function: get_Pokemon
 * Description: returns a specific pokemon
 * Parameters: an index for the pokemon
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: A pokemon *
**************************************************************************/
Pokemon * Trainer::get_Pokemon(int a) {
   return caught[a];
}

/**************************************************************************
 * Function: add_Pokemon
 * Description: A pokemon is added to the Pokemon the trainer caught
 * Parameters: A Pokemon *
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::add_Pokemon(Pokemon* x) {
   set_num_Pokemon();
   caught[num_Pokemon-1] = x;
}
      
/**************************************************************************
 * Function: get_num_Pokemon
 * Description: returns the number of pokemon
 * Parameters: None
 * Pre-Conditions:None
 * Post-Conditions: None
 * Return: The number of Pokemon
**************************************************************************/
int Trainer::get_num_Pokemon() {
   return num_Pokemon;
}
 
/**************************************************************************
 * Function: set_Num_Pokemon
 * Description: The number of pokemon caught by the user increases by 1.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::set_num_Pokemon() {
   num_Pokemon+=1;
}  
      
/**************************************************************************
 * Function: get_num_stones
 * Description: the numberr of stones the user has is returned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: number of stones is returned
**************************************************************************/
int Trainer::get_num_stones() {
   return num_stones;
}

/**************************************************************************
 * Function: set_num_stones
 * Description: Number of stones is increased by 1
 * Parameters: an integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::set_num_stones(int a) {
   num_stones += 1;
cout << "Number of Stones: " << num_stones << endl;
}

/**************************************************************************
 * Function: get_current_row
 * Description: returns current_row of the user
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: the row of the user
**************************************************************************/
int Trainer::get_current_row() {
   return current_row;
}

/**************************************************************************
 * Function: set_current_row
 * Description: sets the current row
 * Parameters: a new row
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer:: set_current_row(int a) {
   current_row=a;
}

/**************************************************************************
 * Function: get_current_column
 * Description: returns the column
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: an integer
**************************************************************************/
int Trainer::get_current_column() {
   return current_column;
}

/**************************************************************************
 * Function: set_current_column
 * Description: A new column is passed and stored as the current column
 * Parameters: A integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer:: set_current_column(int a) {
   current_column=a;
}

/**************************************************************************
 * Function: get_starting_row
 * Description: the starting row is returned
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: The starting row
**************************************************************************/
int Trainer::get_starting_row() {
   return starting_row;
}

/**************************************************************************
 * Function: set_starting row
 * Description: Sets a new starting row
 * Parameters: An integer
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::set_starting_row(int a) {
   starting_row=a;
}

/**************************************************************************
 * Function: get_starting_column
 * Description: returns the starting column
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: the starting column
**************************************************************************/
int Trainer::get_starting_column() {
   return starting_column;
}

/**************************************************************************
 * Function: set_starting_column
 * Description: A new starting_column is set
 * Parameters: the Column number
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void Trainer::set_starting_column(int a) {
   starting_column=a;
}
