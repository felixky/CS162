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
      //string getSpecies();	 
      int num;
   public:
      Human();
      string getSpecies();	 

      int get_num() const;
      void set_num(const int &);

      int getStrength() const;
      void setStrength(const int );

      int getHitpoints() const;
      void setHitpoints(const int &);

      string get_name() const;
      void set_name(const string &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int getDamage();
      

};   
#endif
