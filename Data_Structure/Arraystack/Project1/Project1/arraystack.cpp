#include <iostream>
#include "arraystack.h"
using namespace std;
/*
typedef struct stack {
	int numOfData;
	int top;
	int st[MAX_LEN];
};

void stackinit(stack *ps);
bool SIsEmpty(stack *ps);
void Spush(stack *ps, int data);
int Spop(stack *ps);
int Stop(stack *ps);
*/
void stackinit(stack *ps) {
	ps->numOfData = 0;
	//ps->top = -1;
	return;
}
bool SIsEmpty(stack *ps) {
	if (ps->numOfData == 0) return true;
	else return false;
}

void Spush(stack *ps, int data) {
	int &idx = (ps->numOfData);
	if (idx == MAX_LEN) {
		cout << "���� ������ �� : " << ps->numOfData << endl;
		cout << "�� �̻� �����͸� ���� �� �����ϴ�.\n";
		return;
	}
	ps->st[idx++] = data;
	//ps->top = idx;
	return;
}

int Spop(stack *ps) {
	//(ps->top)--;
	(ps->numOfData)--;
	return ps->st[ps->numOfData];
}

int Stop(stack *ps) {
	return ps->st[ps->numOfData-1];
}
