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

      int getStrength() const;
      void setStrength(const int &);

      int getHitpoints() const;
      void setHitpoints(const int &);

      double get_payoff() const;
      void set_payoff(const double &);

      double get_cost() const;
      void set_cost(const double &);

      int getDamage();
      virtual string getSpecies()=0;
};
#endif
