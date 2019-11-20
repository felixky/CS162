#ifndef DEMON_H
#define DEMON_H
#include "Creature.h"
using namespace std;

class Demon: public Creature{
   private:
      int num_demons;
   public:
      Demon();
      int get_damage();

      int get_num_demons() const;
      void set_num_demons(const int &);
};   
#endif
