#include <iostream>

#ifndef CREATURE_H
#define CREATURE_H
#include "creature.h"
#endif

using namespace std;

int main(){
#ifdef DEBUG
   cout << "Inside #ifdef DEBUG." << endl;
   creature();
#endif

return 0;
}

void creature(){
   cout << "In creature function." << endl;
}
