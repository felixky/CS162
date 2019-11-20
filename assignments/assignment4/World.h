#ifndef WORLD_H
#define WORLD_H
#include "Trainer.h"
#include "Location.h"
#include "Event.h"
#include "Pokemon.h"
#include <iostream>

class World {
   protected:
      Trainer T;
      Location *L;
      Event * E[15];
      Pokemon  P[15];
      int total_Pokemon;
   public:
      World();
      Trainer getTrainer();
      
      Location *getLocation();
      Event * get_Event(int);
      void setEvent(int, Event *); 
      Pokemon getSinglePokemon(int);
      void setPokemon(int, Pokemon );
      int getTotal_Pokemon();
      void setTotal_Pokemon(int);
};
#endif
