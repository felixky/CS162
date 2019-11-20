#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <string>
#include "Vehicle.h"
using namespace std;

class Motorcycle:public Vehicle {
   private:
      Creature *driver;
      int wheels;
      int speed;
      string motor;
      static const string type;
   public:
      int get_wheels() const;
      void set_wheels(const int &);

      int get_speed() const;
      void set_speed(const int &);
      string get_motor() const;
      void set_motor(string);

      const string get_Vehicle();
      //void set_type(const string &);

      float get_distance(float);
      int getDistance(); 
      virtual Creature *getDriver();
      void setDriver(Creature *);
      void setSpeed(int);
      string getVehicle();
};
#endif
