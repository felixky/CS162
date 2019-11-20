#ifndef WORLD_H
#define WORLD_H
#include "Human.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Balrog.h"
#include "Witch.h"

using namespace std;

class World{
   private:
      Human *H;
      Elf *E;
      Cyberdemon *CD;
      Balrog *B;
      Witch *W;
      int money;
      int num_cyberdemon;
      int num_balrog;
      int num_human;
      int num_elf;
      int num_witch;
   public:
      World();
      ~World();
      World(const World&);
      void operator=(const World &);

      int get_money() const;
      void set_money(const int &);

      Human* get_human(int);
      Elf* get_elf(int);
      Balrog* get_balrog(int);
      Witch* get_witch(int);
      Cyberdemon* get_cyberdemon(int);

      int get_num_witch() const;
      void set_num_witch(int &);
      int get_num_cyberdemon() const;
      void set_num_cyberdemon(int &);
      int get_num_balrog() const;
      void set_num_balrog(int &);
      int get_num_human() const;
      void set_num_human(int &);
      int get_num_elf() const;
      void set_num_elf(int &);
}; 
#endif
