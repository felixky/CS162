#ifndef ELF_H
#define ELF_H
#include "Creature.h"
#include <string>
using namespace std;

class Elf:public Creature{
   protected:
      string name;
      int current_hitpoints;
      int num;
      //string getSpecies();	 
   public:
      Elf();
      string getSpecies();	 
      Elf(const Elf&);
      int getStrength() const;
      void setStrength(const int &);

      int get_num() const;
      void set_num (const int&);

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
