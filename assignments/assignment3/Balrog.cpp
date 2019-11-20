#include "Balrog.h"
#include <ctime>
#include <cstdlib>
Balrog::Balrog() {
   num=0;
   name;
   current_hitpoints=Creature::get_hitpoints();
}
int Balrog::get_strength() const {
   return Creature::get_strength();
}

int Balrog::get_hitpoints() const {
   return current_hitpoints;
}
void Balrog::set_current_hitpoints(const int &hp) {
   current_hitpoints= current_hitpoints-hp;
}

double Balrog::get_payoff() const {
   return Creature::get_payoff();
}

double Balrog::get_cost() const{
   return Creature::get_cost();
}

int Balrog::get_damage() {
   return Demon::get_damage();
}
string Balrog::get_name() const{
   return name;
}
void Balrog::set_name(const string &nam) {
   name=nam;
}
int Balrog::get_num() const{
   return num;
}

void Balrog::set_num(const int &nu) {
   num+=nu;
}
