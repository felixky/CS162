/*************************************************************
 * Program: list.c /mini complier
 * Author: Kyle Felix
 * Date: June 11, 2017
 * Description: This is a mini compiler program.
 * Input: Curly braces, parenthesis, and brackets.
 * Output: A message accepting or rejecting the input.
************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

/***********************************************************
 * Function: main
 * Description: Asks user for input and calls the other functions
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The program is over.
 * Return: 0
***********************************************************/
int main() {
   struct list s;
   int j=0, length, t=0;
   char c[50];   
   
   init(&s); //initialize empty list. Good
   printf("Enter a series of brackets [], parenthesis (), and curly braces {}: "); 
   scanf("%s", c); 
   length = strlen(c); //Gives me the length of the input

   for(j=0;j<length;j++) { //loops through each character inputted
      if(c[j] == '[')
	 t = 1;
      else if(c[j] == ']') //closing ones are negative so they can cancel out the opening one
	 t = -1;
      else if(c[j] == '(')
	 t = 2;
      else if(c[j] == ')')
	 t = -2;
      else if(c[j] == '{')
	 t = 3;
      else if(c[j] == '}')
	 t = -3;
      else
         printf("%c should not be in the input.\n",c[j]);
      if(c[j] == '[' || c[j] == '(' || c[j] == '{')
         push_front(&s, t);
      if(c[j] == ']' || c[j] == ')' || c[j] == '}') {
         if(front(s) + t == 0){
	    remove_front(&s);
	 }
      }
   }
   result(&s);
   return 0;
} //25 lines

/***********************************************************
 * Function: result
 * Description: Prints if the input would be rejected or accepted
 * Parameters: A pointer to the list
 * Pre-Conditions: None
 * Post-Conditions: None
 * Return: None
***********************************************************/
void result(struct list *s) {
   if(empty((*s)) == 1) //all nodes were removed in main
      printf("Your input would be accepted.\n");
   else if(empty((*s)) == 0) //nodes remain so bad input
      printf("Your input would be rejected.\n");
   
   if(empty((*s)) == 0)
      delete(s);  //remove all nodes from list. 
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
   s->head = NULL; //I point to null so I know they don't point to something random
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
   while(temp != NULL) { //adds 1 to count everytime temp does not point to NULL
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
   } //loops through every node printing its value until temp points to NULL
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
   temp->val = t; //insert value into temp
   temp->next = s->head; //point temp to the first node in the list like head is doing
   s->head = temp; //point head to temp to make it a list again
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
   if(temp = NULL) { //If not node, then create a node and set head and tail to the nodes address
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
   if(s.head == NULL) { //checks to see if there are any nodes
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
   count-=2; //makes temp point to the last node in the list 
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
   i = s->head->val; //stores value in first node
   temp = s->head->next; //temp points to second node
   free(s->head); //deleteing the first node
   s->head = temp; //pointing head to temp
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
   if(s->head==NULL) //no memory to delete if there are no nodes in the list
      return;
   while(s->head != NULL) { 
      temp = s->head->next; //temp points to one node ahead of s->head
      free(s->head); //s->head is deleted
      s->head = temp; //s->head now points to temp
   } //loops through untill all nodes are gone
}


