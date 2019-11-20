#ifndef WITCH_H
#define WITCH_H
#include "Demon.h"
#include <string>
using namespace std;
class Witch:public Demon{
   protected:
      string name;
      int num;
      int current_hitpoints;
      //string getSpecies();
   public:
      Witch();
      string getSpecies();
      int getStrength() const;
      void setStrength(const int &);

      int getHitpoints() const;
      void setHitpoints(const int &);

      int get_num() const;
      void set_num(const int &);

      string get_name() const;
      void set_name(const string &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int getDamage() ;
      


};   
#endif
