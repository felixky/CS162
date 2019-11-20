#include <iostream>
#include "Vehicle.h"
#include "skateboard.h"
#include "motorcycle.h"
#include "bike.h"
#include "racecar.h"
#include "Creature.h"
#include "Human.h"
#include "Demon.h"
#include "Elf.h"
#include "Witch.h"
#include "race.h"
using namespace std;

int main() {
   int x=50, y=200, z=30, r=25;
   Creature *c, *c1;
   Elf e;
   Human h;
   
   Vehicle *v, *v1;
   Race_car rc;
   Motorcycle m;
   
   v=&rc;
   v1=&m;
   c=&e;
   c1=&h;
  
   v->setDriver(c);
   v1->setDriver(c1);

   //v->getDriver();
   //cout << v->getDriver()->getSpecies() << endl;

   c->setStrength(x);
   c1->setStrength(x);

//   c->setHitpoints(y);
  // c1->setHitpoints(y);

   v->setSpeed(z);
   v1->setSpeed(r);

cout << v->getDriver()->getHitpoints() << endl;
   cout <<"Before execute race." << endl;
   execute_race(v, v1);


   return 0;
}


   /*
   Vehicle v;
   Skateboard s;
   Motorcycle m;
   Bike b;
   Race_car r;

   cout << "Base Vehicle speed: " << v.get_speed() << endl;
   cout << "Skateboard speed: " << s.get_speed() << endl;
   cout << "Motorcycle speed: " << m.get_speed() << endl;
   cout << "Bike speed: " << b.get_speed() << endl;
   cout << "Race car speed: " << r.get_speed() << endl;

   if(m.get_speed()> s.get_speed())
      cout << "Motorcycle is faster than skateboard." << endl;
   if(m.get_speed()< s.get_speed())
      cout << "Skateboard is faster than a motorcycle." << endl;
   if(b.get_speed()> r.get_speed())
      cout << "Bike is faster than Race car." << endl;
   if(b.get_speed()< r.get_speed())
      cout << "Race car is faster than bike." << endl;
      
   return 0;
}*/
