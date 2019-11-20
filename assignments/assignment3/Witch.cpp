#include "Witch.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Witch::Witch():num(0) {
   num=0;
   name;
   current_hitpoints=Creature::get_hitpoints();
}
int Witch::get_strength() const {
   return Creature::get_strength();
}

int Witch::get_hitpoints() const {
   return current_hitpoints;
}
void Witch::set_current_hitpoints(const int &hp) {
   current_hitpoints= current_hitpoints -hp;
}

double Witch::get_payoff() const {
   return Creature::get_payoff();
}

double Witch::get_cost() const{
   return Creature::get_cost();
}

int Witch::get_damage() {
   int x,y=-50;
   x=rand()%49;
   if(x==13){
      cout << "The witch casts a spell healing spell!! Her health was raised by 50 points!!" << endl;
      set_current_hitpoints(y);
      return Creature::get_damage();
   }
   return Demon::get_damage();
}
string Witch::get_name() const{
   return name;
}
void Witch::set_name(const string &nam) {
   name=nam;
}
int Witch::get_num() const{
   return num;
}

void Witch::set_num(const int &nu) {
   num+=nu;
}
