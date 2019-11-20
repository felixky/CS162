#include "Elf.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Elf::Elf() {
   num=0;
   name;
   current_hitpoints=Creature::get_hitpoints();
}

string Elf::get_species() {
   return "Elf";
}

Elf::Elf(const Elf & other) {
   name=other.name;
   current_hitpoints=other.current_hitpoints;
}

int Elf::get_strength() const {
   return Creature::get_strength();
}

int Elf::get_hitpoints() const {
   return current_hitpoints;
}
void Elf::set_current_hitpoints(const int &hp) {
   current_hitpoints-=hp;
}

double Elf::get_payoff() const {
   return Creature::get_payoff();
}

double Elf::get_cost() const {
   return Creature::get_cost();
}

int Elf::get_damage() {
   int x, y;
      x=rand () %9;
      if(x==3){
	 cout << "A mystical attack occured!!! Double the damage!!" << endl;
         y= Creature::get_damage()*2;
         return y;
      }
      else 
         return Creature::get_damage();
   return Creature::get_damage();
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
