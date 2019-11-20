#include "World.h"
     
World::World() {
   num_cyberdemon=0;
   num_balrog=0;
   num_human=0;
   num_elf=0;
   num_witch=0;

   H=new Human[num_human];
   E=new Elf [num_elf];
   CD=new Cyberdemon [num_cyberdemon];
   B=new Balrog [num_balrog];
   W=new Witch [num_witch];
   money=0;
}

World::~World() {
   delete [] H;
   delete [] E;
   delete [] CD;
   delete [] B;
   delete [] W;
}

World::World(const World &other) {
   money=other.money;
   num_cyberdemon=other.num_cyberdemon;
   if(num_cyberdemon==0)
      CD=NULL;
   else{
      CD=new Cyberdemon[num_cyberdemon];
      for(int i=0;i<num_cyberdemon;i++){
	 CD[i]=other.CD[i];
      }
   }

   num_balrog=other.num_balrog;
   if(num_balrog==0)
      B=NULL;
   else{
      B=new Balrog[num_balrog];
      for(int i=0;i<num_balrog;i++){
	 B[i]=other.B[i];
      }
   }

   num_human=other.num_human;
   if(num_human==0)
      H=NULL;
   else{
      H=new Human[num_human];
      for(int i=0;i<num_human;i++){
	 H[i]=other.H[i];
      }
   }

   num_elf=other.num_elf;
   if(num_elf==0)
      E=NULL;
   else{
      E=new Elf[num_elf];
      for(int i=0;i<num_elf;i++){
	 E[i]=other.E[i];
      }
   }
   num_witch=other.num_witch;
   if(num_witch==0)
      W=NULL;
   else{
      W=new Witch[num_witch];
      for(int i=0;i<num_witch;i++){
	 W[i]=other.W[i];
      }
   }
}

void World::operator=(const World &other) {
   delete [] H;
   delete [] E;
   delete [] CD;
   delete [] B;
   money=other.money;
   num_cyberdemon=other.num_cyberdemon;
   if(num_cyberdemon==0)
      CD=NULL;
   else{
      CD=new Cyberdemon[num_cyberdemon];
      for(int i=0;i<num_cyberdemon;i++){
	 CD[i]=other.CD[i];
      }
   }

   num_balrog=other.num_balrog;
   if(num_balrog==0)
      B=NULL;
   else{
      B=new Balrog[num_balrog];
      for(int i=0;i<num_balrog;i++){
	 B[i]=other.B[i];
      }
   }

   num_human=other.num_human;
   if(num_human==0)
      H=NULL;
   else{
      H=new Human[num_human];
      for(int i=0;i<num_human;i++){
	 H[i]=other.H[i];
      }
   }

   num_elf=other.num_elf;
   if(num_elf==0)
      E=NULL;
   else{
      E=new Elf[num_elf];
      for(int i=0;i<num_elf;i++){
	 E[i]=other.E[i];
      }
   }
   num_witch=other.num_witch;
   if(num_witch==0)
      W=NULL;
   else{
      W=new Witch[num_witch];
      for(int i=0;i<num_witch;i++){
	 W[i]=other.W[i];
      }
   }

}


int World::get_money() const {
   return money;
}

void World::set_money(const int & num) {
   money+=num;
}
int World::get_num_cyberdemon () const{
   return num_cyberdemon;
}
void World::set_num_cyberdemon (int &num) {
   Cyberdemon *temp;
   int tem=num_cyberdemon+num;
   temp=new Cyberdemon[tem];
   for(int i=0;i<num_cyberdemon;i++)
      temp[i]=CD[i];
   delete [] CD;
   CD=temp;
   num_cyberdemon+=num;
}

int World::get_num_balrog() const {
   return num_balrog;
}
void World::set_num_balrog(int &num) {
   Balrog *temp;
   int tem=num_balrog+num;
   temp=new Balrog[tem];
   for(int i=0;i<num_balrog;i++)
      temp[i]=B[i];
   delete [] B;
   B=temp;
   num_balrog+=num;
}

int World::get_num_human () const{
   return num_human;
}
void World::set_num_human (int &num) {
   Human *temp;
   int tem=num_human+num;
   temp=new Human[tem];
   for(int i=0;i<num_human;i++)
      temp[i]=H[i];
   delete [] H;
   H=temp;
   num_human+=num;
}

int World::get_num_elf () const{
   return num_elf;
}
void World::set_num_elf (int &num) {
   Elf *temp;
   int tem=num_elf+num;
   temp=new Elf[tem];
   for(int i=0;i<num_elf;i++)
      temp[i]=E[i];
   delete [] E;
   E=temp;
   num_elf+=num;
}
int World::get_num_witch () const{
   return num_witch;
}
void World::set_num_witch (int &num) {
   Witch *temp;
   int tem=num_witch+num;
   temp=new Witch[tem];
   for(int i=0;i<num_witch;i++)
      temp[i]=W[i];
   delete [] W;
   W=temp;
   num_witch+=num;
}

Human* World::get_human(int i) {
  return &H[i];   
}
Cyberdemon* World::get_cyberdemon(int i) {
  return &CD[i];   
}
Balrog* World::get_balrog(int i) {
  return &B[i];   
}
Elf* World::get_elf(int i) {
  return &E[i];   
}

Witch* World::get_witch(int i) {
   return &W[i];
}


