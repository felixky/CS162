#include "Cyberdemon.h"

Cyberdemon::Cyberdemon():num(0) {
   num=0;
   name;
   current_hitpoints=Creature::get_hitpoints();
}
int Cyberdemon::get_strength() const {
   return Creature::get_strength();
}

int Cyberdemon::get_hitpoints() const {
   return current_hitpoints;
}
void Cyberdemon::set_current_hitpoints(const int &hp) {
   current_hitpoints= current_hitpoints -hp;
}

double Cyberdemon::get_payoff() const {
   return Creature::get_payoff();
}

double Cyberdemon::get_cost() const{
   return Creature::get_cost();
}

int Cyberdemon::get_damage() {
   return Demon::get_damage();
}
string Cyberdemon::get_name() const{
   return name;
}
void Cyberdemon::set_name(const string &nam) {
   name=nam;
}
int Cyberdemon::get_num() const{
   return num;
}

void Cyberdemon::set_num(const int &nu) {
   num+=nu;
}
