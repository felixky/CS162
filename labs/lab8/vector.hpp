#include <iostream>
#include <stdlib.h>
#include <exception>
#include <stdexcept>
using std::cout;
template <class T>
class vector {
   private:
      T *v;
      int s;
   public:
      vector(){
	     s=0;
	     v=NULL;
      }
	  
      ~vector(){
	     delete [] v;
      }

      vector(vector<T> &other) {
         s=other.s;
	 if(s==0)
	    v=NULL;
	 else{
	    v=new T [s];
	    for(int i=0;i<s;i++){
               v[i]=other.v[i];
	    }
	 }
      }

      void operator=(vector<T> &other) {
         delete [] v;
         s=other.s;
	 if(s==0)
	    v=NULL;
	 else{
	    v= new T [s];
	    for(int i=0;i<s;i++){
               v[i]=other.v[i];
	    }
	 }
      }

      int size() {
	     return s;
      }
	  
      void push_back(T ele) {
	     T *temp;
	     temp = new T[++s];
	     for(int i=0; i<s-1; i++)
	        temp[i]=v[i];

	     delete [] v;
	     v=temp;
	     v[s-1]=ele;
      }

      T operator [] (int i) {
	 return v[i];
      }

      T at(int i) {
         try{
            v[i];
	    if(i>s)
	       throw std::out_of_range("Out of my vector bounds");
	 }
         catch(std::out_of_range &e) {
	    cout << e.what() << '\n';
	 }	    
	 return v[i];
      }


};
