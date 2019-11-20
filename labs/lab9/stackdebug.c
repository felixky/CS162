#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//using namespace std;

//This function grows the stack by one and places the num at the end
//Pre-conditions: the value pointed to by s is the size of the stack
//Post-conditions: the stack points to an array 1 bigger than it was  
//retaining the same information plus the new number at the end.  The
//size of the stack increases by one.
//Return: none
void push(int **stack, int *s, int num) {
   int *temp, i;
   (*s)+=1;
   temp=(int *) malloc(sizeof(int)*(*s));
   (*s)-=1;
   for(i=0; i<((*s)); i++) {
      temp[i]=(*stack)[i];
      printf("temp: %d\n", temp[i]);
   }
   (*s)+=1;
   free((*stack));
   (*stack)=temp;
   (*stack)[(*s)]=num;
//   printf("Num: %d\n", *s);
   printf("Number in stack: %d\n", (*stack)[(*s)]);
   printf("Number in stack: %d\n", (*stack)[(*s-1)]);
}

//This function shrinks the stack by one and returns the num at the end
//Pre-conditions: the value pointed to by s is the size of the stack
//Post-conditions: the stack points to an array 1 smaller than it was  
//retaining the same information except the new number at the end.  The
//size of the stack decreases by one.
//Return: number at the end of the stack before shrinking it by one
int pop(int **stack, int *s) {
   int *temp, i;
   (*s)-=1;
   temp=(int *) malloc(sizeof(int)*(*s));
   for(i=0; i<(*s); i++) 
      temp[i]=(*stack)[i];
   (*s)+=1;
   i=(*stack)[(*s)];
   printf("i in pop: %d\n", i);
   (*s)-=1;
   free((*stack));
   (*stack)=temp;
   return i;
}

int main() {
   int *stack=NULL;
   int size=0, op1, op2;
   char c[11];

   stack=malloc(sizeof(int)*size);
   do {
      scanf("%s", c);
      if(atoi(c)>0 || (strlen(c)==1 && c[0]=='0')){
	 push(&stack, &size, atoi(c));
//	 printf("size: %d\n",size);
      }
      else if(c[0]=='+'|| c[0]=='-') {
	 if(size<2) {
	    printf( "Error!\n");
	    break;
	 }
         op2=pop(&stack, &size); 	 
         op1=pop(&stack, &size);
	 if(c[0]=='+'){
	    push(&stack, &size, op1+op2);
      }
	 else if(c[0]=='-')	 {
	    push(&stack, &size, op1-op2);
      }
      }
      else if(c[0]=='p' && size>0)
	 printf("%d\n",stack[size-1]);
   } while(c[0]!='q');
  
   free(stack);

   return 0;
}
