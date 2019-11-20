#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
   private:
      string id;
   protected:
      int wheels;  
   public:
      Vehicle();
      string get_id() const;
      void set_id(const string &);

      int get_wheels() const;
      void set_wheels(const int &);

      virtual int get_toll();
};
#endif
