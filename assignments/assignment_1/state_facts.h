#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;
struct county{
   string name;
   string *city;
   int cities;
   int population;
   float avg_income;
   float avg_house;
};
struct state{
   string name;
   struct county *c;
   int counties;
   int population;
};
bool is_valid_arguments(char*[], int);
state * create_states(int);
void get_state_data(state *, int , ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state **, int);
void largest_pop(state *, int);
void county_income(state *,int );   
void avg_home_price(state *places, int num_states);
void sort_by_pop(state *places, int num_states);

