#include <iostream>
#include "motorcycle.h"
using namespace std;
const string Motorcycle::type = "motorcycle";

int Motorcycle::get_wheels() const {
   return Vehicle::get_wheels()+2;
}

void Motorcycle::set_wheels(const int &tires) {
   wheels=tires;
}

int Motorcycle::get_speed() const {
   return Vehicle::get_speed()+150;
}


const string Motorcycle::get_Vehicle() {
   return type;
}

float Motorcycle::get_distance(float time) {
   float distance;
   distance=time*speed;
   return distance;
}
string Motorcycle::get_motor() const {
   return Vehicle::get_motor()+"motor";
}

void Motorcycle::set_motor(string engine) {
   motor=engine;
}

Creature* Motorcycle::getDriver() {
   
   return driver;
}

void Motorcycle::setDriver(Creature *c) {
   driver=c;
}

void Motorcycle::setSpeed(int v) {
   speed=v;
}

string Motorcycle::getVehicle() {
   return "Motorcycle";
}
int Motorcycle::getDistance() {
  return speed*2;
}
