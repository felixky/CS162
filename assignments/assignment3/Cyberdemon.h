#ifndef CYBERDEMON_H
#define CYBERDEMON_H
#include "Demon.h"
#include <string>
using namespace std;
class Cyberdemon:public Demon{
   private:
      string name;
      int num;
      int current_hitpoints;
      string get_species();
   public:
      Cyberdemon();
      int get_strength() const;
      void set_strength(const int &);

      int get_hitpoints() const;
      void set_current_hitpoints(const int &);

      int get_num() const;
      void set_num(const int &);

      string get_name() const;
      void set_name(const string &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int get_damage() ;
      


};   
#endif
