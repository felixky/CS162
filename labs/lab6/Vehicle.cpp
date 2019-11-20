#include <iostream>
#include "Vehicle.h"
using namespace std;
const string Vehicle::description = "Vehicle";

Vehicle::Vehicle() {
   wheels=0;
   speed=0.0;
   motor="This vehicle has ";
}

bool Vehicle::operator>(Vehicle & other) {
   if(getDistance() > other.getDistance())
      return true;
   else
      return false;
}

bool Vehicle::operator<(Vehicle & other) {
   if(getDistance() < other.getDistance())
      return true;
   else
      return false;
}

int Vehicle::get_wheels() const {
   return wheels;
}

void Vehicle::set_wheels(const int &tires) {
   wheels=tires;
}

int Vehicle::get_speed() const {
   return speed;
}

/*string Vehicle:: getVehicle() {
   return description;
}*/

int Vehicle::getDistance() {
   return speed*2;
}
string Vehicle::get_motor() const {
   return motor;
}

void Vehicle::set_motor(string engine) {
   motor=engine;
}
Creature * Vehicle::getDriver() {
   return driver;
}
      
void Vehicle::setDriver(Creature *other) {
   driver=other;
}
void Vehicle::setSpeed(int v) {
   speed=v;
}
