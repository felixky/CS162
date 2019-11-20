#ifndef ELF_H
#define ELF_H
#include "Creature.h"
#include <string>
using namespace std;

class Elf:public Creature{
   private:
      string name;
      int current_hitpoints;
      int num;
      string get_species();	 
   public:
      Elf();
      Elf(const Elf&);
      int get_strength() const;
      void set_strength(const int &);

      int get_num() const;
      void set_num (const int&);

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
