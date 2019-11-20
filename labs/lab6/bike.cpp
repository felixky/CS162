#include "bike.h"
const string Bike::type = "bike";

int Bike::get_wheels() const {
   return Vehicle::get_wheels()+2;
}

void Bike::set_wheels(const int &tires) {
   wheels=tires;
}

int Bike::get_speed() const {
   return Vehicle::get_speed()+30;
}


const string Bike::get_Vehicle() {
   return type;
}

float Bike::get_distance(float time) {
   float distance;
   distance=time*speed;
   return distance;
}
string Bike::get_motor() const {
   return Vehicle::get_motor()+"no motor";
}

void Bike::set_motor(string engine) {
   motor=engine;
}
Creature* Bike::getDriver() {

   return driver;
}

void Bike::setDriver(Creature *c) {
   driver=c;
}

void Bike::setSpeed(int v) {
   speed=v;
}

string Bike::getVehicle() {
   return "Bike";
}
int Bike::getDistance() {
  return speed*2;
}
