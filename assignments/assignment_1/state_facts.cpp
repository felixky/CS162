/***********************************************************************************************
** Program Filename: state_county.cpp
** Author: Kyle Felix
** Date: 4/16/17
** Description: This program recieves state/county info from a file provided in the command line argument and sorts out the statistics for each state.
** Input: A command line argument with number of states and a file with state info in it.
** Output: Statistics on the states and counties 
***********************************************************************************************/
#include "./state_facts.h"

/**********************************************************************************************
** Function: is_valid_arguments
** Description: checks the command line arguments for errors.
** Parameters: argv and argc.
** Pre-Conditions: None
** Post_Conditions: Number of states and the file provided are valid.
** Return: True or False
**********************************************************************************************/
bool is_valid_arguments(char **argv , int argc){
   int num_states, total=0, k, m, n;
   char temp[10]="-s", temp2[10]="-f", *file_name;
   state *places;
   file_name=new char [50];
   
   if(argc!=5){
	cout <<"You're missing at least one argument." << endl;
	return false; //Not all arguments provided
   }

   if((strcmp(argv[1],temp)!=0 && strcmp(argv[1],temp2)!=0) || (strcmp(argv[3],temp)!=0 && strcmp(argv[3],temp2)!=0)){
      cout<< "You did not have -f or -s. " << endl;
      return false;
   } //Checks if -s and -f are there

   for(int i=1;i<5;i++){
      k=i+1;
      if(strcmp(argv[i],temp)==0){ //Test both possible positions for -s
	 num_states=atoi(argv[k]);
	 if(num_states==0){
	    cout << "Error getting number of states. Enter a new number: " ;
	    cin>> num_states;
	    while(cin.fail() || num_states<=0){
	       cin.clear();
	       cin.ignore();
	       cout << "Error getting number of states. Enter a new number: " ;
	       cin>> num_states;
	    }
	 }
	 total+=1;
      }
      if(strcmp(argv[i],temp2)==0){ //Tests both possible positions for -f
	 file_name=argv[k];

	 total+=1;
      }
      if(total==2)
	 break; //After both number of states and file name are valid
      else
	 i+=1;
   }
	 ifstream input;
	 input.open(file_name); //opens provided file
	 while(input.is_open()==false){
            cin.clear();
	    //cin.ignore();
	    cout << "Error opening the file provided. Enter a new file name: " ;
            cin>> file_name;
	    input.open(file_name);
	    }
   places=create_states(num_states);
   get_state_data(places, num_states, input);
return true;
}


/**********************************************************************************************
** Function: create_states *
** Description: creates an array of state structs.
** Parameters: Number of states from the command line.
** Pre-Conditions: num_states is a valid number.
** Post_Conditions: None.
** Return: array of states called places.
**********************************************************************************************/
state * create_states(int num_states){

   state *places;
   places= new state[num_states];

return places;
}
/**********************************************************************************************
** Function:get_state_data
** Description: Accesses the provided file and it's information.
** Parameters: Array of states, number of states, and an input file.
** Pre-Conditions: Input file and number of states are valid.
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void get_state_data(state * places, int num_states , ifstream & input){
   int temp;
   for(int i=0; i< num_states; i++){
      input >> places[i].name; //Name of state
      cout << places[i].name << " " ;
      input >> places[i].population; //Satae population
      cout << places[i].population << " " ;
      input >> places[i].counties; //Number of counties
      cout <<places[i].counties << endl;
      places[i].c = create_counties(places[i].counties); //Stores array of counties in c
      get_county_data(places[i].c, places[i].counties, input);
   }
   input.close(); //Here after taking all data from file
   largest_pop(places, num_states);
   county_income(places, num_states);   
   avg_home_price(places,num_states);
   sort_by_pop(places,num_states);
   delete_info(&places, num_states);
}
/**********************************************************************************************
** Function: create_counties
** Description: Creates an array of counties
** Parameters: number of counties 
** Pre-Conditions: None
** Post_Conditions: None
** Return:  An array of counties
**********************************************************************************************/
county * create_counties(int num_counties){
 
   county * counties;
   counties= new county[num_counties];

return counties;
}
/**********************************************************************************************
** Function: get_county_data
** Description: Accesses the data from the input file and stores it in the struct counties.
** Parameters: An array of counties, number of counties, and an input from the file.
** Pre-Conditions: None
** Post_Conditions: None
** Return:  None
**********************************************************************************************/
void get_county_data(county *counties, int num_counties, ifstream & input){
   char temp[256];
   for(int k=0; k<num_counties; k++){ //for loop for however many counties there are
      input >> counties[k].name; //Name of county
      cout <<counties[k].name << " " ;
      input >> counties[k].population; //Pop of county
      cout <<counties[k].population << " " ;
      input >> counties[k].avg_income; //Average income of county
      cout <<counties[k].avg_income << " " ;
      input >> counties[k].avg_house; //Average price of a home
      cout << counties[k].avg_house  << " " ;
      input >> counties[k].cities;
      cout << counties[k].cities  << " " ;
      counties[k].city = new string[counties[k].cities]; //Dynamic array to hold multiple city names
      for(int i=0; i<(counties[k].cities);i++){
         input >> counties[k].city[i];
         cout << counties[k].city[i] << " " ;
      }
      cout << endl;
   }
}
/**********************************************************************************************
** Function: delete_info
** Description: Deletes array's created during the program.
** Parameters: array of places and number of states.
** Pre-Conditions: None
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void delete_info(state **places, int num_states){
 /* for(int j=0;j<num_states;j++){
     cout << "FIRST LOOP" << endl;
      for(int i=0; i<(*places)[j].counties;i++){
	 cout << "SECOND LOOP" << endl;
         for(int l=0;l<(*places)[j].c[i].cities;l++){
	    cout <<"THIRD LOOP" << endl;
	    delete (*places)[j].c[i].city;
	 }
      }
  }*/
  for(int j=0;j<num_states;j++){
      //for(int i=0; i<(*places)[j].counties;i++)
         delete [] (*places)[j].c; 
   }
   delete [] (*places);
}

/**********************************************************************************************
** Function: largest_pop
** Description: Prints the state and county with the largest population.
** Parameters:  Array of structs with the file info in it and number of states.
** Pre-Conditions: None
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void largest_pop(state * places, int num_states){
   int pop=0, num=0, county_pop=0, num2=0, num3=0;
   for(int i=0; i<num_states;i++){
      if(places[i].population>pop){ //pop starts at 0 and only changes if the new pop is larger than the last
	 pop=places[i].population;
	 num=i;
      }	
   }
   cout << "The state with the largest population is " << places[num].name << "." << endl;
   
   for(int i=0; i<num_states;i++){
      for(int k=0; k<places[i].counties;k++){
         if(places[i].c[k].population>county_pop){
	    county_pop=places[i].c[k].population;
	    num2=i;
	    num3=k;
	 }
      }
   }
   cout << "The county with the largest population is " << places[num2].c[num3].name << "." << endl;
}

/**********************************************************************************************
** Function: county_income
** Description: Print all counties with an income above a user specified amount.
** Parameters: Array of structs with the file info in it and number of states.
** Pre-Conditions: None
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void county_income(state * places,int num_states){
   float income;
   cout << "Enter an income: ";
   cin >> income; //USer provides income amount here

   cout << "These counties have a higher income than " << income << " : ";
   for(int i=0; i<num_states;i++){
      for(int k=0; k<places[i].counties;k++){
         if(places[i].c[k].avg_income>income) //Compares inputted income to county income
	    cout << places[i].c[k].name << ", " ;
      }
   }
      cout << endl;
}

/**********************************************************************************************
** Function: avg_home_price
** Description: Prints the average home price for each county in each state.
** Parameters: Array of structs with the file info in it and number of states.
** Pre-Conditions: None
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void avg_home_price(state *places, int num_states){
   float total=0.0, avg=0.0;
   
   for(int i=0; i<num_states;i++){
      for(int k=0; k<places[i].counties;k++){
         cout << "The average home price in " << places[i].c[k].name << " county is: " << places[i].c[k].avg_house << endl; //Average home price for each county
	 total+=places[i].c[k].avg_house;
      }
      avg= total/places[i].counties;
      cout << "The average home price for the whole state of " << places[i].name <<" is: "<< avg << "." << endl; //Average price of every county combined
      total=0;
   }
}


/**********************************************************************************************
** Function: sort_by_pop
** Description: Prints the states is order of population.
** Parameters: Array of structs with the file info in it and number of states.
** Pre-Conditions: None
** Post_Conditions: None
** Return: None
**********************************************************************************************/
void sort_by_pop(state *places, int num_states){

   int pop=0, num=52, num2=100000000, num3=0;
   cout<< "State population(largest to smallest): " ;
   for(int j=0;j<num_states;j++){
      for(int i=0; i<num_states;i++){
         if(places[i].population>pop && places[i].population<num2 && num!=i){ //pop starts at 0 and only changes if the new pop is larger than the last
	    pop=places[i].population;
	    num=i;
         }	
      }

   cout<<  places[num].name << ", ";
   }
}



















