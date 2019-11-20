struct node {
   int val; //integer node value
   struct node *next; //ointer to next node
};

struct stack {
   struct node *head; //pointer to first node in stack
   struct node *tail; //pointer to top of stack aka the last node
};
