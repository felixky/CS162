#include "Elf.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
Elf::Elf() {
   num=0;
   name;
   current_hitpoints=Creature::getHitpoints();
}

string Elf::getSpecies() {
   string c="Elf";
   return c;
}

Elf::Elf(const Elf & other) {
   name=other.name;
   current_hitpoints=other.current_hitpoints;
}

int Elf::getStrength() const {
   return Creature::getStrength();
}

int Elf::getHitpoints() const {
   cout <<"In the Elf getHitpoints function" << endl;
   return current_hitpoints;
}
void Elf::setHitpoints(const int &hp) {
   cout <<"In the Elf setHitpoints function" << endl;
   current_hitpoints-=hp;
}

double Elf::get_payoff() const {
   return Creature::get_payoff();
}
/*void Elf::set_payoff(const double &mon) {
   payoff=mon;
}*/

double Elf::get_cost() const {
   return Creature::get_cost();
}
/*void Elf::set_cost(const double &price) {
   cost=price;
}*/

int Elf::getDamage() {
   int x, y;

      x=rand () %9;
      if(x=3){
         y= Creature::getDamage()*40;
         return y;
      }
      else 
         return Creature::getDamage()*10;
}

string Elf::get_name() const{
   return name;
}
void Elf::set_name(const string &nam) {
   name=nam;
}
int Elf::get_num() const{
   return num;
}

void Elf::set_num(const int &nu) {
   num+=nu;
}
