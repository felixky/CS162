#ifndef TRAINER_H
#define TRAINER_H
#include <string>
#include <iostream>
#include "Pokemon.h"
using namespace std;

class Trainer {
   private:
      string name;
      int Pokeballs;
      Pokemon* caught[20];
      int num_Pokemon;
      int current_row;
      int current_column;
      int starting_row;
      int starting_column;
      int num_stones;
   public:
      Trainer();
      string getName();
      void setName(string &);

      void add_Pokemon(Pokemon * );
      Pokemon *get_Pokemon(int);

      int get_num_Pokemon();
      void set_num_Pokemon();

      int getPokeballs();
      void setPokeballs(int &);

      int get_current_row();
      void set_current_row(int);
      int get_current_column();
      void set_current_column(int);
      
      int get_starting_row();
      void set_starting_row(int);
      int get_starting_column();
      void set_starting_column(int);

      int get_num_stones();
      void set_num_stones(int);
};
#endif
