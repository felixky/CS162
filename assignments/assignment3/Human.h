#ifndef HUMAN_H
#define HUMAN_H
#include "Creature.h"
#include <string>
#include <iostream>
using namespace std;

class Human:public Creature {
   private:
      string name;
      int current_hitpoints;
      string get_species();	 
      int num;
   public:
      Human();

      int get_num() const;
      void set_num(const int &);

      int get_strength() const;
      void set_strength(const int &);

      int get_hitpoints() const;
      void set_current_hitpoints(const int &);

      string get_name() const;
      void set_name(const string &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int get_damage();
      

};   
#endif
