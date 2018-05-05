#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define MAX_LEN 20

struct stack {
	int numOfData;
	//int top;
	int st[MAX_LEN];
};

void stackinit(stack *ps);
bool SIsEmpty(stack *ps);
void Spush(stack *ps, int data);
int Spop(stack *ps);
int Stop(stack *ps);
#endif
