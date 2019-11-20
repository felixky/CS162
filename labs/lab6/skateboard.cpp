#include "skateboard.h"
const string Skateboard::type = "skateboard";

int Skateboard::get_wheels() const {
   return Vehicle::get_wheels()+4;
}

void Skateboard::set_wheels(const int &tires) {
   wheels=tires;
}

int Skateboard::get_speed() const {
   return Vehicle::get_speed()+15;
}


const string Skateboard::get_Vehicle() {
   return type;
}

float Skateboard::get_distance(float time) {
   float distance;
   distance=time*speed;
   return distance;
}
string Skateboard::get_motor() const {
   return Vehicle::get_motor()+"no motor";
}

void Skateboard::set_motor(string engine) {
   motor=engine;
}
      
Creature* Skateboard::getDriver() {
   
   return driver;
}

void Skateboard::setDriver(Creature *c) {
   driver=c;
}

void Skateboard::setSpeed(int v) {
   speed=v;
}

string Skateboard::getVehicle() {
   return "Skateboard";
}


int Skateboard::getDistance() {
  return speed*2;
}
