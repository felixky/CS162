#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include "Creature.h"

using namespace std;
class Vehicle {
   private:
      Creature *driver;
      int wheels;
      int speed;
      string motor;
      static const string description;
   public:
      Vehicle();
      bool operator>(Vehicle &);
      bool operator<(Vehicle &);
      
      int get_wheels() const;
      void set_wheels(const int &);

      int get_speed() const;
      void set_speed(const int &);

      string get_motor() const;
      void set_motor(string);

//      const string get_Vehicle();
      //void set_type(const string &);
      virtual void setDriver(Creature *);
      int getDistance();
      void setSpeed(int);
      virtual string getVehicle()=0;
      virtual Creature* getDriver();
};   
#endif
