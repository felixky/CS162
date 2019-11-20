#include "Creature.h"
#include <ctime>
#include <cstdlib>

Creature::Creature() {
   strength=30;
   hitpoints=200;
   payoff=50;
   cost=20;

}
Creature::~Creature() {}

Creature::Creature(const Creature & other) {
   strength=other.strength;
   hitpoints=other.hitpoints;
   payoff=other.payoff;
   cost=other.cost;
}
   
int Creature::get_strength() const {
   return strength;
}
void Creature::set_strength(const int & str) {
   strength=str;
}

int Creature::get_hitpoints() const {
   return hitpoints;
}
void Creature::set_hitpoints(const int &hp) {
   hitpoints=hp;
}

double Creature::get_payoff() const {
   return payoff;
}
void Creature::set_payoff(const double &mon) {
   payoff=mon;
}

double Creature::get_cost() const {
   return cost;
}
void Creature::set_cost(const double &price) {
   cost=price;
}

int Creature::get_damage() {
   int x;
   
   x=rand()%20;
   return x;   
}

