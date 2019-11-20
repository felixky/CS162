#include "Human.h"
#include <iostream>
using namespace std;
Human::Human() {
   num=0;  
   name="Human"; 
   current_hitpoints=Creature::getHitpoints();
}

string Human::getSpecies(){
   string c="Human";
   return c;
} 

int Human::getStrength() const {
   return Creature::getStrength();
}
void Human::setStrength(const int a) {
   Creature::setStrength(a);
}

int Human::getHitpoints() const {
   return current_hitpoints;
}
void Human::setHitpoints(const int &hp) {
   current_hitpoints = current_hitpoints-hp;
}

double Human::get_payoff() const {
   return Creature::get_payoff();
}
double Human::get_cost() const {
   return Creature::get_cost();
}

int Human::getDamage() {
   return Creature::getDamage()*100;
}
string Human::get_name() const{
   return name;
}
void Human::set_name(const string &nam) {
   Human::name=nam;
}
      
int Human::get_num() const{
   return num;
}

void Human::set_num(const int &nu) {
   num+=nu;
}
