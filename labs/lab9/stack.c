#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "stack.h"

struct node {
   int val; //integer node value
   struct node *next; //pointer to next node
};

struct stack {
   struct node *head; //pointer to first node in stack
   struct node *tail; //pointer to top of stack aka the last node
};

void init(struct stack *s) { //initalize stack members
   s->head = NULL;
   s->tail = NULL;

}

void push(struct stack *s, int t) { //grow contents to store int
   struct node *temp = NULL;
   if(s->head == NULL) {
      s->head = (struct node *) malloc(sizeof(struct node));
      s->head->val = t;
      s->tail = s->head;
   }
   else{
      temp = s->head;
      s->head = (struct node *) malloc(sizeof(struct node));
      s->head->val = t;
      s->head->next = temp;
   }
}

int pop(struct stack *s) { //shrink contents and return top int
   struct node * temp = NULL;
 
   int i = s->head->val;
   printf("%d\n", s->head->val);
   temp = s->head->next;
   free(s->head);
   s->head = temp;
   return i;
}

int main () {
   int m;
   struct stack s;
   init(&s);

   push(&s, 2);
   push(&s, 4);
   push(&s, 6);
   push(&s, 8);
   pop(&s);
   pop(&s);
   pop(&s);
   pop(&s);
   return 0;
}










