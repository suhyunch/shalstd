#ifndef __LINKED_LIST_STACK__
#define __LINKED_LIST_STACK__

typedef struct node {
	int data;
	node* next;
};

typedef struct stack {
	node* head;
	int numOfdata;
};

void Sinit(stack *ps);
bool SIsEmpty(stack *ps);
void Spush(stack *ps, int data);
int Spop(stack *ps);
int Stop(stack *ps);
#endif