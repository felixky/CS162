#ifndef BIKE_H
#define BIKE_H
#include "Vehicle.h"
#include <string>
using namespace std;

class Bike:public Vehicle {
   private:
      string pedals;
   public:
      Bike();
      string get_pedals() const;
      void set_pedals();

      int get_toll();
};
#endif
