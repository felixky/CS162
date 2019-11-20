#include "Human.h"
#include <iostream>
using namespace std;
Human::Human() {
   num=0;  
   name="Human"; 
   current_hitpoints=Creature::get_hitpoints();
}

string Human::get_species(){
   return "Human";
} 

int Human::get_strength() const {
   return Creature::get_strength();
}
int Human::get_hitpoints() const {
   return current_hitpoints;
}
void Human::set_current_hitpoints(const int &hp) {
   current_hitpoints = current_hitpoints-hp;
}

double Human::get_payoff() const {
   return Creature::get_payoff();
}
double Human::get_cost() const {
   return Creature::get_cost();
}

int Human::get_damage() {
   return Creature::get_damage();
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
