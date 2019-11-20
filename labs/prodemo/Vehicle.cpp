#include "Vehicle.h"

Vehicle::Vehicle() {
   id = "Vehicle";
   wheels = 2;
}

string Vehicle::get_id() const {
   return id;
}

void Vehicle::set_id(const string &s) {
   id = s;
}

int Vehicle::get_wheels() const {
   return wheels;
}

void Vehicle::set_wheels(const int &w) {
   wheels=w;
}

int Vehicle::get_toll() {
   return 4*wheels;
}
