#include "./state_facts.h"
/**********************************************************************************************
** Function: main
** Description: calls is_valid_arguments to check the command line.
** Parameters: argc and argv. They are the number of arguments and a character array of the arguments.
** Pre-Conditions: None
** Post_Conditions: None
** Return: 0
**********************************************************************************************/
int main(int argc, char **argv){

   if(is_valid_arguments(argv, argc)==false)
      return 0;

   return 0;   
}
