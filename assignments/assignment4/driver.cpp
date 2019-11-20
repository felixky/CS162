/**************************************************************************
 * Program: driver.cpp
 * Author: Kyle Felix
 * Date: May 28, 2017
 * Description: This is a Pokemon Go styled game where a user captures pokemon and returns them to a professor at a starting location.
 * Input: A grid size and trainer movements
 * Output: A Pokemon Go style game
**************************************************************************/
#include <iostream>
#include "World.h"
#include "Trainer.h"
#include "Event.h"
#include "Location.h"
#include "Cave.h"
#include "Pokemon.h"
#include "Pokestop.h"
#include "Rock.h"
#include "Flying.h"
#include "Psychic.h"
#include <cstdlib>
#include <cctype>
#include <cstdlib>
using namespace std;

bool check(int , char **, int &, int &);
void create_board(int, int, World &, Event ****);
void assign_polymorphism(World &);
void removeEvent(Event ****, int, int);
void gameplay(World &, Event ****, int, int);
void catchPoke(World &);
void findCave(World &);
void getAPokestop(World &);


int main(int argc, char **argv) {
   Event ***e;
   int x, y;
   World w;
   Trainer r;
   srand(time(NULL));
   if(check(argc, argv, x, y)==false)
      return 0;
  
   cout << "Trainer name: " << w.getTrainer().getName() << endl;
   assign_polymorphism(w);
   //create_board(x,y,w,&e);
   gameplay(w, &e, x, y);
   
//   removeEvent(&e, x, y, &p);
   cout << "At the end." << endl;
   return 0;
}

/**************************************************************************
 * Function: check
 * Description: Makes sure the command line argument is within the acceptable range
 * Parameters: The command line arguants and 2 variables to store them in.
 * Pre-Conditions: None
 * Post-Conditions: X and Y are integers greater than 3
 * Return: true or false
**************************************************************************/
bool check(int argc, char **argv, int &x, int &y) {
   if(argc!=3)
      return false;
   x = atoi(argv[1]);
   y = atoi(argv[2]);
   while(x<=2){
      cout << "Thats not a valid row size (must be at least 3). Enter a new row size: " ;
      cin >> x;
      cin.ignore();
      cin.clear();
   }
   while(y<=2){
      cout << "Thats not a valid column size (must be at least 3). Enter a new column size: " ;
      cin >> y;
      cin.ignore();
      cin.clear();
   }
return true;
}

/**************************************************************************
 * Function: assign_polymorphism
 * Description: Creates all the Pokemon, caves, and pokestops and makes them events
 * Parameters: A World that holds everything
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void assign_polymorphism(World &w) {
   Pokemon *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11, *p12;
   Cave c1;
   Pokestop ps, ps1;
   Rock geo, geo1, lav, lav1; //Geodude->Graveler->Golem and Lavitar->Pupitar->Tyranitar 
   Flying pid, pid1, star, star1; //Pidgey->Pidgeotto->Pidgeot and Starly->Staravia->Staraptor
   Psychic abra, abra1, ralt, ralt1; //Abra->Kadabra->Alakazam and Ralts->Kirlia->Gardevoir

   p1 = & geo;
   p2 = & geo1;
   p3 = & lav;
   p4 = & lav1;
   p5 = & pid;
   p6 = & pid1;
   p7 = & star;
   p8 = & star1;
   p9 = & abra;
   p10 = & abra1;
   p11 = & ralt;
   p12 = & ralt1;

   Event *e2=&c1, *e3=&ps, *e4=&ps1;//, *e5=p1, *e6=p2, *e7=p3, *e8=p4, *e9=p5, *e10=p6, *e11=p7, *e12=p8, *e13=p9, *e14=p10, *e15=p11 ,*e16=p12;
  /*
   * The first two event are caves, the next two are poketops, and the remaining twelve are pokemon the user has to catch.
  */ 
   w.setEvent(0 , e2);   //Seting all the events in the world class
   w.setEvent(1 , e3);   
   w.setEvent(2 , e4);   
   w.setPokemon(0 , (*p1));   
   w.setPokemon(1 , (*p2));   
   w.setPokemon(2 , (*p3));   
   w.setPokemon(3 , (*p4));   
   w.setPokemon(4 , (*p5));   
   w.setPokemon(5 , (*p6));   
   w.setPokemon(6 , (*p7));   
   w.setPokemon(7 , (*p8));   
   w.setPokemon(8 , (*p9));   
   w.setPokemon(9 , (*p10));   
   w.setPokemon(10 , (*p11));   
   w.setPokemon(11 , (*p12));   
} // 29 lines with a lot of declarations of variables

/**************************************************************************
 * Function: create_board
 * Description: Creates a board of events and events are randomly placed everywhere.
 * Parameters: Size of grid, World, and a points to the board of events
 * Pre-Conditions: None
 * Post-Conditions:None
 * Return: None
**************************************************************************/
void create_board(int x, int y, World &w, Event ****e) {
   int r,c,k=0, m, n;
   *e= new Event ** [x];
   for(int i=0;i<x;i++)
      (*e)[i]= new Event * [y];

   r = rand() % x;
   c =rand() % y;

   cout << "r: " << r << " and c: " << c << endl;

   w.getTrainer().set_starting_row(r);
   w.getTrainer().set_starting_column(c);
cout << "Before loop" << endl;    
   while(k<16) {
      m = rand() % x;
      n =rand() % y;
      if(m!=r && n!=c){
         (*e)[m][n]=w.get_Event(k);
         k++;
      }
   }
cout << "After loop" << endl;    
}

/**************************************************************************
 * Function: removeEvent
 * Description: Deletes the Memory allocated to create the grid
 * Parameters: The grid and it's dimensions
 * Pre-Conditions: None
 * Post-Conditions: All the memory has been deleted
 * Return: None
**************************************************************************/
void removeEvent(Event ****e, int x, int y) {
   for(int i=0;i<y;i++)
      delete [] (*e)[i];
   delete [] (*e);
}


/**************************************************************************
 * Function: gameplay
 * Description: Asks that user what they want to do.
 * Parameters: A world variable, the grid and its dimensions
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void gameplay(World &w, Event ****e, int x, int y) {
   int Q;
   while(true){
      cout << "Do you want to capture Pokemon(1), find a cave(2), or go to a Pokestop(3)? Enter the number: ";
      cin >> Q;
   if(Q==1)
      catchPoke(w);
   else if(Q==2)
      findCave(w);
   else if(Q==3)
      getAPokestop(w);
   else 
      cout << "Thats not an option!" << endl;
   }   

}

/**************************************************************************
 * Function: catchPoke
 * Description: Randomly chooses a Pokemon and you try to catch it.
 * Parameters: A world variable
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void catchPoke(World &w) {
   int x;
   x =rand () % 12;
   //cout << w.getTrainer().getName() << endl;
   w.getSinglePokemon(x).capture_Pokemon();
}
/**************************************************************************
 * Function: findCave
 * Description: Goes to a cave and gets a stone
 * Parameters: A World variable
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void findCave(World &w) {
   int c=0, r=1;
   cout << "You Found a Stone in a cave! It can Be used to evolve a Pokemon to stage 2." << endl;
   w.getTrainer().set_num_stones(r);
   cout << "You Have " << w.getTrainer().get_num_stones() << "." <<  endl;
   //w.get_Event(c)->getEvent()->get_stone(); 
}
/**************************************************************************
 * Function: getAPokestop
 * Description: Gives the user Pokeballs
 * Parameters: A world variable
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
**************************************************************************/
void getAPokestop(World &w) {
   int a=1;
   int x;
   x = rand() %8;
   x+=3;
#ifdef DEBUG
   x=10;
#endif
   cout << "You gained " << x << " poke-balls." << endl;
   w.getTrainer().setPokeballs(x);
   cout << "You have " << w.getTrainer().getPokeballs() << "." << endl;
   //w.get_Event(a)->getEvent()->give_pokeballs();
}



