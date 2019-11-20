/****************************************************************************
 * Program: Creatures
 * Author: Kyle Felix
 * Date: May 14, 2017
 * Description: This if a fantasy fighting game.
 * Input: Money, Creatures, and their names.
 * Output: A turn by turn fighting game
 ***************************************************************************/
#include "World.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void starting_creatures(World*);
void intro(World *);
void Names(int, World **);
void Next(int&, int, World***);
void Create_enemies(World&);
void Battle_human(World*, World *);
void Battle_balrog(World*, World *);
void Battle_cyberdemon(World*, World *);
void Battle_elf(World*, World *);
void Battle_witch(World*, World*);
void Result_human(World *,int ,int,int) ;
void Result_elf(World *,int ,int,int) ;
void Result_balrog(World *,int ,int,int) ;
void Result_cyberdemon(World *,int ,int,int) ;
void Result_witch(World *,int ,int,int) ;

/************************************************************************
 * Function: main
 * Description: declares variables and calls functions
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * Return: 0
 ***********************************************************************/
int main() {
   srand (time(NULL));
   World w, Ew;
   int i=0;

   intro(&w); 
   starting_creatures(&w);
   Create_enemies(Ew);
   /*while((w.get_money()>9 && Ew.get_witch(i)->get_hitpoints()>0) || 
     (w.get_money()>24  && Ew.get_elf(i)->get_hitpoints()>0) || 
     (w.get_money()>29 && Ew.get_cyberdemon(i)->get_hitpoints()>0) || 
     (w.get_money()>49 && Ew.get_balrog(i)->get_hitpoints()>0) ) {*/  //While statement test to see if the user has enough money to challenge a creature
   if(Ew.get_witch(i)->get_hitpoints()>0 && w.get_num_human()>0) //if statements make sure the enemy has hitpoints before they fight again
      Battle_human(&w, &Ew);
   if(Ew.get_human(i)->get_hitpoints()>0 && w.get_num_elf()>0)
      Battle_elf(&w, &Ew);
   if(Ew.get_balrog(i)->get_hitpoints()>0 && w.get_num_witch()>0)
      Battle_witch(&w, &Ew);
   if(Ew.get_cyberdemon(i)->get_hitpoints()>0 && w.get_num_balrog()>0)
      Battle_balrog(&w, &Ew);
   if(Ew.get_elf(i)->get_hitpoints()>0 && w.get_num_cyberdemon()>0)
      Battle_cyberdemon(&w, &Ew);
   // }
   return 0;
}

/************************************************************************
 * Function: Intro
 * Description: Asks for starting money and calls next function
 * Parameters: Money and a pointer for each creature
 * Pre-Conditions:None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void intro(World *w) {
   int money, k;
   cout << endl;
   cout << endl; //Opening title/ introduction
   cout << endl;
   cout << endl;
   cout <<"          WELCOME TO CREATURE WARS         " << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   cout << "The game will continue untill all your enemies are defeated or you no longer have the means to buy new creatures." << endl;
   cout << endl;
   cout << endl;
   cout << "Enter how much money are you starting with: ";
   cin >> money;
   (*w).set_money(money);
}

/************************************************************************
 * Function: starting_creatures
 * Description: Asks for type of creature you want to buy
 * Parameters: money and a pointer for each creature
 * Pre-Conditions: money has already been inputted
 * Post-Conditions: Atleast one Creature is bought
 * Return: None
 ***********************************************************************/
void starting_creatures(World *w) {
   char c[15];
   while((*w).get_money()>=10){
      cout << "Humans cost $10, Elves cost $15, Cyberdemons cost $25, Balrogs cost $30, and Witches cost $50. Type the name of the creature you want to purchase or done to be done buying Creatures: ";
      cin >> c;
      if(c[0]=='d' || c[0]=='D')
	 return;
      else if(c[0]=='C' || c[0]=='c') //checks the first letter of input for creature
	 Names(25, &w);
      else if(c[0]=='B' || c[0]=='b')//checks the first letter of input for creature
	 Names(30, &w);
      else if(c[0]=='H' || c[0]=='h')//checks the first letter of input for creature
	 Names(10, &w);
      else if(c[0]=='E' || c[0]=='e')//checks the first letter of input for creature
	 Names(15,&w);
      else if(c[0]=='W'|| c[0]=='w')//checks the first letter of input for creature
	 Names(50, &w);
      else
	 cout << "Thats not a Creature" << endl;
      cout << "Money: " << (*w).get_money() << endl; //prints the amount of money the user has after a purchase
   }
}

/************************************************************************
 * Function: Names
 * Description:Number of creatures is chosen and money is checked for amount.
 * Parameters: money, the creature choice , and a pointer for each creature type
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Names(int choice, World **w) {
   int num, cost;
   cout << "Enter how many do you want to buy: ";
   cin >> num;
   cost=num*choice*(-1);
   //cout << (**w).get_money() << endl;
   if((**w).get_money()+cost<0){ //checks if the user has enough money to complete purchase
      cout<< "You do not have enough money." << endl;
   }
   else{
      (**w).set_money(cost);
      Next(num, choice, &w);
   }
}

/************************************************************************
 * Function:Next
 * Description: Arrays of creatures are made
 * Parameters: Number of creatures, the type, and pointers for each creature type
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Next(int &num, int choice, World ***w) {   
   string c;
   if(choice==25) { //price of creature
      (***w).set_num_cyberdemon(num);
      for(int i=((***w).get_num_cyberdemon()-num);i<(***w).get_num_cyberdemon();i++){ //for statement takse previously made creature into account
	 cout << "Enter the name of the Cyberdemon: ";
	 cin.clear();
	 cin.ignore();
	 getline(cin, c);
	 (***w).get_cyberdemon(i)->set_name(c); //sets name in world class
      }
   }
   else if(choice==30) {
      (***w).set_num_balrog(num);
      for(int i=((***w).get_num_balrog()-num);i<(***w).get_num_balrog();i++){
	 cout << "Enter the name of the Balrog: ";
	 cin.clear();
	 cin.ignore();
	 getline(cin, c); //get name of creature from user here
	 (***w).get_balrog(i)->set_name(c);
      }
   }
   else if(choice==10) {
      (***w).set_num_human(num);
      for(int i=((***w).get_num_human()-num);i<(***w).get_num_human();i++){
	 cout << "Enter the name of the Human: ";
	 cin.clear();
	 cin.ignore();
	 getline(cin, c);
	 (***w).get_human(i)->set_name(c);
      }
   }
   else if(choice==15) {
      (***w).set_num_elf(num);
      for(int i=((***w).get_num_elf()-num);i<(***w).get_num_elf();i++){
	 cout << "Enter the name of the Elf: ";
	 cin.clear();
	 cin.ignore();
	 getline(cin, c);
	 (***w).get_elf(i)->set_name(c);
      }
   }
   else if(choice==50) {
      (***w).set_num_witch(num);
      for(int i=((***w).get_num_witch()-num);i<(***w).get_num_witch();i++){
	 cout << "Enter the name of the Witch: ";
	 cin.clear();
	 cin.ignore();
	 getline(cin, c);
	 (***w).get_witch(i)->set_name(c);
      }
   }
} //40 lines

/************************************************************************
 * Function: Create_enemies
 * Description: Deafult enemies are created.
 * Parameters: A world for the enemies
 * Pre-Conditions: None
 * Post-Conditions None
 * Return: None
 ***********************************************************************/
void Create_enemies(World &Ew) {
   int i=1, m=0, x=-50;
   string a="Cyborg", b="Barry", c="John Cena", d="Frodo", e="Hermione";
   /* 
    * Sets all the enemies you will be fighting. They have a name and start with
    * a 50 point increase to their health
    */
   Ew.set_num_cyberdemon(i);
   Ew.get_cyberdemon(m)->set_name(a);
   Ew.get_cyberdemon(m)->set_current_hitpoints(x);

   Ew.set_num_balrog(i);
   Ew.get_balrog(m)->set_name(b);
   Ew.get_balrog(m)->set_current_hitpoints(x);

   Ew.set_num_human(i);
   Ew.get_human(m)->set_name(c);
   Ew.get_human(m)->set_current_hitpoints(x);

   Ew.set_num_elf(i);
   Ew.get_elf(m)->set_name(d);
   Ew.get_elf(m)->set_current_hitpoints(x);

   Ew.set_num_witch(i);
   Ew.get_witch(m)->set_name(e);
   Ew.get_witch(m)->set_current_hitpoints(x);

}

/************************************************************************
 * Function: Battle_human
 * Description: Humans fight witches until one has 0 health points.
 * Parameters: A world with you creatures and a world with the evil creatures
 * Pre-Conditions: None
 * Post-Conditions: A creature a 0 or less hitpoints
 * Return: None
 ***********************************************************************/
void Battle_human(World *w, World *Ew) {
   int k=0, damage, Edamage,win=50, lose=-50, result=0, round=1, a;
   string x;
   if(w->get_num_human()>0){
      for(int i=0;i<w->get_num_human();i++){
	 if(Ew->get_witch(k)->get_hitpoints()<1)
	    return;
	 while(w->get_human(i)->get_hitpoints()>0 && Ew->get_witch(k)->get_hitpoints()>0){
	    cout << "Press enter to attack!" << endl;
	    cin.ignore();
	    cout <<"Round " << round << endl;

	    damage=w->get_human(i)->get_damage();
	    cout << w->get_human(i)->get_name() << " does " << damage << " damage to " << Ew->get_witch(k)->get_name() << endl;

	    Ew->get_witch(k)->set_current_hitpoints(damage);//Applies damage to enemy here

	    cout << "Health of " << w->get_human(i)->get_name()<< ": " << w->get_human(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_witch(k)->get_name()<< ": " << Ew->get_witch(k)->get_hitpoints() << endl;

	    Edamage= Ew->get_witch(k)->get_damage();
	    cout << Ew->get_witch(k)->get_name() << " does " << Edamage << " damage to " << w->get_human(i)->get_name() << endl;

	    w->get_human(i)->set_current_hitpoints(Edamage);//Applies damage to your creature here

	    cout << "Health of " << w->get_human(i)->get_name()<< ": " << w->get_human(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_witch(k)->get_name()<< ": " << Ew->get_witch(k)->get_hitpoints() << endl;

	    cout << endl;
	    round+=1;
	 }
	 Result_human(w, i, win, lose); 
      }
   }
}
/************************************************************************
 * Function: Result_human
 * Description: Either a reward or a cost is given to the user.
 * Parameters: A world with your creatures, int i for the number of the creature fighting, reward, and lose value
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Result_human(World *w, int i, int win, int lose) {
   int a;
   if(w->get_human(i)->get_hitpoints()>0){
      cout << "Congrats!! You won and earned the payoff of $50." << endl;  //Reward for winning
      w->set_money(win);
      cout << "Money: " << w->get_money() << endl;
      return;
   }
   else{
      cout << "You lost and were charged $50. Try again next time." << endl; //Cost of losing
      w->set_money(lose);
   }
   cout << "Money: " << w->get_money() << endl;

   cout << "Do you wish to buy more Creatures? Type 1 for yes or 2 for no: " ;
   cin >> a;
   if(a==1)
      starting_creatures(w);
}

/************************************************************************
 * Function: Battle_cyberdemon
 * Description: cyberdemons fight elves until one has 0 health points.
 * Parameters: A world with you creatures and a world with the evil creatures
 * Pre-Conditions: None
 * Post-Conditions: A creature a 0 or less hitpoints
 * Return: None
 ***********************************************************************/
void Battle_cyberdemon(World *w, World *Ew) {
   int k=0, damage, Edamage,win=50, lose=-50, result=0, round=1, x, a;
   if(w->get_num_cyberdemon()>0){
      for(int i=0;i<w->get_num_cyberdemon();i++){
	 if(Ew->get_elf(k)->get_hitpoints()<1)
	    return;
	 while(w->get_cyberdemon(i)->get_hitpoints()>0 && Ew->get_elf(k)->get_hitpoints()>0){
	    cout << "Press enter to attack!" << endl;
	    cin.ignore();
	    cout <<"Round " << round << endl;

	    damage=w->get_cyberdemon(i)->get_damage();
	    cout << w->get_cyberdemon(i)->get_name() << " does " << damage << " damage to " << Ew->get_elf(k)->get_name() << endl;

	    Ew->get_elf(k)->set_current_hitpoints(damage);//Applies damage to enemy here

	    cout << "Health of " << w->get_cyberdemon(i)->get_name()<< ": " << w->get_cyberdemon(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_elf(k)->get_name()<< ": " << Ew->get_elf(k)->get_hitpoints() << endl;

	    Edamage= Ew->get_elf(k)->get_damage();
	    cout << Ew->get_elf(k)->get_name() << " does " << Edamage << " damage to " << w->get_cyberdemon(i)->get_name() << endl;

	    w->get_cyberdemon(i)->set_current_hitpoints(Edamage);//Applies damage to your creature here

	    cout << "Health of " << w->get_cyberdemon(i)->get_name()<< ": " << w->get_cyberdemon(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_elf(k)->get_name()<< ": " << Ew->get_elf(k)->get_hitpoints() << endl;

	    cout << endl;
	    round+=1;
	 }
	 Result_cyberdemon(w, i, win, lose);
      }
   }
}
/************************************************************************
 * Function: Result_cyberdemon
 * Description: Either a reward or a cost is given to the user.
 * Parameters: A world with your creatures, int i for the number of the creature fighting, reward, and lose value
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Result_cyberdemon(World *w, int i, int win, int lose) {
   int a;
   if(w->get_cyberdemon(i)->get_hitpoints()>0){
      cout << "Congrats!! You won and earned the payoff of $50." << endl;
      w->set_money(win);
      cout << "Money: " << w->get_money() << endl;
      return;
   }
   else{
      cout << "You lost and were charged $50. Try again next time." << endl;
      w->set_money(lose);
   }
   cout << "Money: " << w->get_money() << endl;

   cout << "Do you wish to buy more Creatures? Type 1 for yes or 2 for no: " ;
   cin >> a;
   if(a==1)
      starting_creatures(w);
}

/************************************************************************
 * Function: Battle_balrog
 * Description: balrogs fight cyberdemons until one has 0 health points.
 * Parameters: A world with you creatures and a world with the evil creatures
 * Pre-Conditions: None
 * Post-Conditions: A creature a 0 or less hitpoints
 * Return: None
 ***********************************************************************/
void Battle_balrog(World *w, World *Ew) {
   int k=0, damage, Edamage,win=50, lose=-50, result=0, round=1, x, a;
   if(w->get_num_balrog()>0){
      for(int i=0;i<w->get_num_balrog();i++){
	 if(Ew->get_cyberdemon(k)->get_hitpoints()<1)
	    return;
	 while(w->get_balrog(i)->get_hitpoints()>0 && Ew->get_cyberdemon(k)->get_hitpoints()>0){
	    cout << "Press enter to attack!" << endl;
	    cin.ignore();
	    cout <<"Round " << round << endl;
	    for (int j=0;j<2;j++){
	       damage=w->get_balrog(i)->get_damage();
	       cout << w->get_balrog(i)->get_name() << " does " << damage << " damage to " << Ew->get_cyberdemon(k)->get_name() << endl;

	       Ew->get_cyberdemon(k)->set_current_hitpoints(damage);//Applies damage to enemy here

	       cout << "Health of " << w->get_balrog(i)->get_name()<< ": " << w->get_balrog(i)->get_hitpoints()<< ". Health of "
		  << Ew->get_cyberdemon(k)->get_name()<< ": " << Ew->get_cyberdemon(k)->get_hitpoints() << endl;
	    }
	    Edamage= Ew->get_cyberdemon(k)->get_damage();
	    cout << Ew->get_cyberdemon(k)->get_name() << " does " << Edamage << " damage to " << w->get_balrog(i)->get_name() << endl;

	    w->get_balrog(i)->set_current_hitpoints(Edamage);//Applies damage to your creature here

	    cout << "Health of " << w->get_balrog(i)->get_name()<< ": " << w->get_balrog(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_cyberdemon(k)->get_name()<< ": " << Ew->get_cyberdemon(k)->get_hitpoints() << endl;
	    cout << endl;
	    round+=1;
	 }
	 Result_balrog(w, i, win, lose);
      }
   }
}
/************************************************************************
 * Function: Result_balrog
 * Description: Either a reward or a cost is given to the user.
 * Parameters: A world with your creatures, int i for the number of the creature fighting, reward, and lose value
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Result_balrog(World *w, int i, int win, int lose) {
   int a;
   if(w->get_balrog(i)->get_hitpoints()>0){
      cout << "Congrats!! You won and earned the payoff of $50." << endl;
      w->set_money(win);
      cout << "Money: " << w->get_money() << endl;
      return;
   }
   else{
      cout << "You lost and were charged $50. Try again next time." << endl;
      w->set_money(lose);
   }
   cout << "Money: " << w->get_money() << endl;

   cout << "Do you wish to buy more Creatures? Type 1 for yes or 2 for no: " ;
   cin >> a;
   if(a==1)
      starting_creatures(w);
}

/************************************************************************
 * Function: Battle_elf
 * Description: Elves fight Humans until one has 0 health points.
 * Parameters: A world with you creatures and a world with the evil creatures
 * Pre-Conditions: None
 * Post-Conditions: A creature a 0 or less hitpoints
 * Return: None
 ***********************************************************************/
void Battle_elf(World *w, World *Ew) {
   int k=0, damage, Edamage,win=50, lose=-50, result=0, round=1, x, a;
   if(w->get_num_elf()>0){
      for(int i=0;i<w->get_num_elf();i++){
	 if(Ew->get_human(k)->get_hitpoints()<1)
	    return;
	 while(w->get_elf(i)->get_hitpoints()>0 && Ew->get_human(k)->get_hitpoints()>0){
	    cout << "Press enter to attack!" << endl;
	    cin.ignore();
	    cout <<"Round " << round << endl;

	    damage=w->get_elf(i)->get_damage();
	    cout << w->get_elf(i)->get_name() << " does " << damage << " damage to " << Ew->get_human(k)->get_name() << endl;

	    Ew->get_human(k)->set_current_hitpoints(damage);//Applies damage to enemy here

	    cout << "Health of " << w->get_elf(i)->get_name()<< ": " << w->get_elf(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_human(k)->get_name()<< ": " << Ew->get_human(k)->get_hitpoints() << endl;

	    Edamage= Ew->get_human(k)->get_damage();
	    cout << Ew->get_human(k)->get_name() << " does " << Edamage << " damage to " << w->get_elf(i)->get_name() << endl;

	    w->get_elf(i)->set_current_hitpoints(Edamage);//Applies damage to your creature here

	    cout << "Health of " << w->get_elf(i)->get_name()<< ": " << w->get_elf(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_human(k)->get_name()<< ": " << Ew->get_human(k)->get_hitpoints() << endl;

	    cout << endl;
	    round+=1;
	 }
	 Result_elf(w, i, win, lose);
      }
   }
}
/************************************************************************
 * Function: Result_elf
 * Description: Either a reward or a cost is given to the user.
 * Parameters: A world with your creatures, int i for the number of the creature fighting, reward, and lose value
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Result_elf(World *w, int i, int win, int lose) {
   int a;
   if(w->get_elf(i)->get_hitpoints()>0){
      cout << "Congrats!! You won and earned the payoff of $50." << endl;
      w->set_money(win);
      cout << "Money: " << w->get_money() << endl;
      return;
   }
   else{
      cout << "You lost and were charged $50. Try again next time." << endl;
      w->set_money(lose);
   }
   cout << "Money: " << w->get_money() << endl;

   cout << "Do you wish to buy more Creatures? Type 1 for yes or 2 for no: " ;
   cin >> a;
   if(a==1)
      starting_creatures(w);
}

/************************************************************************
 * Function: Battle_witch
 * Description: Witches fight balrogs until one has 0 health points.
 * Parameters: A world with you creatures and a world with the evil creatures
 * Pre-Conditions: None
 * Post-Conditions: A creature a 0 or less hitpoints
 * Return: None
 ***********************************************************************/
void Battle_witch(World *w, World *Ew) {
   int k=0, damage, Edamage,win=50, lose=-50, result=0, round=1, x, a;
   if(w->get_num_witch()>0){
      for(int i=0;i<w->get_num_witch();i++){
	 if(Ew->get_balrog(k)->get_hitpoints()<1)
	    return;
	 while(w->get_witch(i)->get_hitpoints()>0 && Ew->get_balrog(k)->get_hitpoints()>0){
	    cout << "Press enter to attack!" << endl;
	    cin.ignore();
	    cout <<"Round " << round << endl;

	    damage=w->get_witch(i)->get_damage();
	    cout << w->get_witch(i)->get_name() << " does " << damage << " damage to " << Ew->get_balrog(k)->get_name() << endl;

	    Ew->get_balrog(k)->set_current_hitpoints(damage);//Applies damage to enemy here

	    cout << "Health of " << w->get_witch(i)->get_name()<< ": " << w->get_witch(i)->get_hitpoints()<< ". Health of "
	       << Ew->get_balrog(k)->get_name()<< ": " << Ew->get_balrog(k)->get_hitpoints() << endl;

	    for(int j=0;j<2;j++){			  
	       Edamage= Ew->get_balrog(k)->get_damage();
	       cout << Ew->get_balrog(k)->get_name() << " does " << Edamage << " damage to " << w->get_witch(i)->get_name() << endl;

	       w->get_witch(i)->set_current_hitpoints(Edamage);//Applies damage to your creature here

	       cout << "Health of " << w->get_witch(i)->get_name()<< ": " << w->get_witch(i)->get_hitpoints()<< ". Health of "
		  << Ew->get_balrog(k)->get_name()<< ": " << Ew->get_balrog(k)->get_hitpoints() << endl;
	    }	
	    cout << endl;
	    round+=1;

	 }
	 Result_witch(w, i, win, lose);
      }
   }
}

/************************************************************************
 * Function: Result_witch
 * Description: Either a reward or a cost is given to the user.
 * Parameters: A world with your creatures, int i for the number of the creature fighting, reward, and lose value
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************************/
void Result_witch(World *w, int i, int win, int lose) {
   int a;
   if(w->get_witch(i)->get_hitpoints()>0){
      cout << "Congrats!! You won and earned the payoff of $50." << endl;
      w->set_money(win);
      cout << "Money: " << w->get_money() << endl;
      return;
   }
   else{
      cout << "You lost and were charged $50. Try again next time." << endl;
      w->set_money(lose);
   }
   cout << "Money: " << w->get_money() << endl;

   cout << "Do you wish to buy more Creatures? Type 1 for yes or 2 for no: " ;
   cin >> a;
   if(a==1)
      starting_creatures(w);
}

