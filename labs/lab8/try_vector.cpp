#include "./vector.hpp"
#include <vector>
#include <iostream>
//#include <exception>
//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector
   int i;
   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);
   v.push_back(43);
   stdv.push_back(63);
   
   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   cout << "Enter a number: ";
      cin >> i;
   
   cout << "Our vector using []: " << v[i] << endl;
   cout << "Our vector using .at(): " << v.at(i) << endl;
   return 0;
}

