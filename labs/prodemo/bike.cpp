#include "bike.h"
#include <iostream>
#include <string>  
using namespace std;

Bike::Bike():Vehicle() {
   pedals= "Below";
}

string Bike::get_pedals() const {
   return pedals;
}

void Bike::set_pedals() {
   int i;
   cout<< "Enter 1 for pedals below the rider and 2 for pedals in front of the rider: " << endl;
   cin >> i;
   if(i==1){
      pedals = "Below";
   }
   else{
      pedals = "Infront";
   }
}

int Bike::get_toll() {
   if(pedals=="Below")
      return 0;
   else
      return 1;
}
