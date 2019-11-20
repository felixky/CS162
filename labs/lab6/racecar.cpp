#include <iostream>
#include "racecar.h"
using namespace std;
const string Race_car::type = "race car";

Race_car::Race_car(){
	driver = NULL;
}

int Race_car::get_wheels() const {
   return Vehicle::get_wheels()+4;
}

void Race_car::set_wheels(const int &tires) {
   wheels=tires;
}

int Race_car::get_speed() const {
   return Vehicle::get_speed()+200;
}


const string Race_car::get_Vehicle() {
   return type;
}

float Race_car::get_distance(float time) {
   float distance;
   distance=time*speed;
   return distance;
}
string Race_car::get_motor() const {
   return Vehicle::get_motor()+"motor";
}

void Race_car::set_motor(string engine) {
   motor=engine;
}

Creature* Race_car::getDriver() {
   if(driver == NULL)
      cout << "Opps, driver was not set" << endl;
   return driver;
}

void Race_car::setDriver(Creature *c) {
   driver=c;
}

void Race_car::setSpeed(int v) {
   speed=v;
}

string Race_car::getVehicle() {
   return "Race car";
}

      
int Race_car::getDistance() {
  return speed*2;
}

