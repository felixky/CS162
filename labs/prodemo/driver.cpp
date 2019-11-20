#include <iostream>
#include <string>
#include "Vehicle.h"
#include "bike.h"

using namespace std;

int main() {
   Vehicle v, *v2, *v3;
   Bike b, b2;
   
   v3 = &b2;
   v2 = &b;
  
   b2.set_pedals();

   cout << "Toll of Vehicle: " << v.get_toll() << endl;
   cout << "Toll of bike: " << v2->get_toll() << endl;
   cout << "Toll of bike2: " << v3->get_toll() << endl;


   return 0;
}
