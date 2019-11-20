#include "Demon.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Demon::Demon() {
   num_demons=0;
}

int Demon::get_damage() {
   int x,y;
   x=rand()%19;
   if(x==13){
      cout << "You get a Demonic Attack!! +50 damage!!" << endl;
      return Creature::getDamage()+50;
   }
   return Creature::getDamage();
}

int Demon::get_num_demons() const {
   return num_demons;
}

void Demon::set_num_demons(const int &nu) {
   num_demons=nu;
}
