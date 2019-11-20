#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int main() {
   struct list s;

   init(&s); //initialize empty list
   push_front(&s, 10);//push to front of list
   push_back(&s, 5); //push to end of list
   push_front(&s, 12);//push to front of list
   push_back(&s, 97; //push to end of list
   front(s);  //returns value at the front of the list
   back(s);  //returns value at the back of the list
   size(s); //return number of nodes in list
   print(s); //print the values in list
   pop_back(&s); //remove node from back and return value
   remove_front(&s);//remove node from front and return value
   empty(s);  //returns true if list is empty
   delete(&s);  //remove all nodes from list
   return 0;
}
/***********************************************************
 * Function: init
 * Description: Initalizes the head and tail pointer in the list to null.
 * Parameters: A pointer to the list s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************/
void init(struct list *s) { //initialize empty list
   s->head = NULL;
   s->tail = NULL;
}

/***********************************************************
 * Function: size
 * Description: Returns the number of nodes in the list
 * Parameters: A list s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: The size of the linked list.
 ***********************************************************/
int size(struct list s) { //return number of nodes in list
   int count=0;
   struct node *temp;
   temp = s.head;
   while(temp != NULL) {
      temp =  temp->next;
      count++;
   }
   printf("The size is: %d\n",count);
   return count;
}

/***********************************************************
 * Function: print
 * Description: Prints the values of all the nodes
 * Parameters: A list s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************/
void print(struct list s) { //print the values in list
   struct node *temp;
   temp = s.head;
   while(temp != NULL) {
      printf("%d\n", temp->val);
      temp =  temp->next;
   }
}

/***********************************************************
 * Function: push_front
 * Description: Adds a new node to the front of the list.
 * Parameters: A pointer to the list s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************/
void push_front(struct list *s, int t) {//push to front of list
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->val = t;
   temp->next = s->head;
   s->head = temp;
}

/***********************************************************
 * Function: push_back
 * Description: Adds a node to the end of the list
 * Parameters: A pointer to the list s and an integer.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
 ***********************************************************/
void push_back(struct list *s, int t) { //push to end of list
   struct node *temp = NULL;

   temp = s->head;
   if(temp = NULL) {
      //printf("Here in push_back in the if statement.\n");
      temp = (struct node*) malloc(sizeof(struct node));
      s->head = temp;
      temp->next = NULL;
      s->tail = temp;
   }
   else {
      //printf("Here in push_back before while loop.\n");
      while(temp != NULL) {
	 temp = temp->next;
      }
      //printf("Here in push_back after while loop.\n");
      temp = (struct node*) malloc(sizeof(struct node));
      s->tail = temp;
      s->tail->val = t;
      s->tail->next = NULL;
   }
   //printf("Here.\n");
}

/***********************************************************
 * Function: front
 * Description: Returns the value stored in the first node
 * Parameters: A list of nodes s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An integer stored in the node or 0 if the list is empty
 ***********************************************************/
int front(struct list s) {  //returns value at the front of the list
   if(s.head == NULL) {
      //printf("The list is completly empty!\n");
      return 0;
   }
   else
      //printf("The value in the first node is %d.\n", s.head->val);
      return s.head->val;   
}

/***********************************************************
 * Function: back
 * Description: Returns the vlue in the last node.
 * Parameters: The list s
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An iteger stored in the node or 0 if there were no nodes.
 ***********************************************************/
int back(struct list s) {  //returns value at the back of the list
   if(s.tail == NULL) {
      //printf("The list is completly empty!\n");
      return 0;
   }
   else
      //printf("The value in the last node is %d.\n", s.tail->val);
      return s.tail->val;
}

/***********************************************************
 * Function: pop_back
 * Description: Removs the last node and return its value
 * Parameters: A pointer to the list s.
 * Pre-Conditions: head is pointing to the list
 * Post-Conditions: None
 * Return: An integer the node stored
 ***********************************************************/
int pop_back(struct list *s) { //remove node from back and return value
   struct node * temp = NULL;
   int i=73, count=0, j;
   temp = s->head;
   while(temp!=NULL){
      temp = temp->next;
      count++;
   }
   count-=2;
   temp = s->head;
   for(j=0;j<count;j++)
      temp = temp->next;
   // printf("Here @ 109\n");
   i = temp->next->val;
   // printf("Here @ 111\n");
   free(temp->next);
   // printf("Here @ 113\n");
   s->tail = temp;
   temp->next = NULL;
   //   printf("Number that was in the removed last node: %d\n", i);
   return i;
}

/***********************************************************
 * Function: remove front
 * Description: removes the node from the front of the list and returns its value
 * Parameters: A pointer to the list s.
 * Pre-Conditions: there must be a node in the list
 * Post-Conditions: None
 * Return: An integer.
 ***********************************************************/
int remove_front(struct list *s) {//remove node from front and return value
   int i;
   struct node * temp = NULL;
   i = s->head->val;
   temp = s->head->next;
   free(s->head);
   s->head = temp;
   //   printf("Number that was in the removed first node: %d\n", i);
   return i;
}

/***********************************************************
 * Function: empty
 * Description: Return 1 if the list id empty and 0 if there are nodes present
 * Parameters: the list s.
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: An int 1 or 0.
 ***********************************************************/
int empty(struct list s) {  //returns true if list is empty
   if(s.head == NULL) {
      //printf("The list is empty.\n");
      return 1;
   }
   else
      //printf("There are nodes in the list.\n");
      return 0;
}
/***********************************************************
 * Function: delete
 * Description: Delete the dynamically allocated memory
 * Parameters: A pointer to the list
 * Pre-Conditions: None
 * Post-Conditions: All memory is freed
 * Return: None
 ***********************************************************/
void delete(struct list *s) {  //remove all nodes from list
   struct node * temp = NULL;
   if(s->head==NULL)
      return;
   while(s->head != NULL) {
      temp = s->head->next;
      free(s->head);
      s->head = temp;
   }
}


