/*
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
*/
#include <iostream>
#include "LINKEDLIST_STACK.h"
using namespace std;

void Sinit(stack *ps) {
	ps->head = NULL;
	ps->numOfdata = 0;
	return;
}
bool SIsEmpty(stack *ps) {
	if (ps->numOfdata == 0)return true;
	else return false;
}
void Spush(stack *ps, int data) {
	node *newnode = new node;
	newnode->data = data;
	newnode->next = ps->head;
	ps->head = newnode;
	ps->numOfdata++;
	return;
}
int Spop(stack *ps) {
	node* dnode;
	dnode = ps->head;
	int ddata = dnode->data;
	ps->head = dnode->next;
	delete dnode;
	ps->numOfdata--;
	return ddata;
}

int Stop(stack *ps) {
	if (ps->numOfdata == 0) {
		cout << "NULL\n";
		return 0;
	}
	return ps->head->data;
}