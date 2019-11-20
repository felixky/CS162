#ifndef CREATURE_H
#define CREATURE_H
#include <string>
using namespace std;
class Creature{
   private:
      int hitpoints;
      int strength;
      double payoff;
      double cost;
   public:
      Creature();
      ~Creature();
      Creature(const Creature &);

      int get_strength() const;
      void set_strength(const int &);

      int get_hitpoints() const;
      void set_hitpoints(const int &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int get_damage();

};
#endif
