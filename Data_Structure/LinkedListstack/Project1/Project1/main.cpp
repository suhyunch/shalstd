#include <iostream>
#include "LINKEDLIST_STACK.h"
using namespace std;
/*
void Sinit(stack *ps);
bool SIsEmpty(stack *ps);
void Spush(stack *ps, int data);
int Spop(stack *ps);
int Stop(stack *ps);
*/
int main() {
	stack s;
	Sinit(&s);

	if (SIsEmpty(&s)) cout << "NULL\n";

	Spush(&s, 2);
	Spush(&s, 6);
	Spush(&s, 1);
	Spush(&s, 10);
	Spush(&s, 43);
	Spush(&s, 27);

	cout << Stop(&s) << '\n';
	while (!SIsEmpty(&s)) {
		cout << Spop(&s) << ' ';
	}cout << endl;

	Spush(&s, 1);
	Spush(&s, 2);
	Spush(&s, 3);
	Spush(&s, 4);
	Spush(&s, 5);
	Spush(&s, 6);
	Spush(&s, 7);
	Spush(&s, 8);
	Spush(&s, 9);
	Spush(&s, 10);
	Spush(&s, 11);
	Spush(&s, 12);
	Spush(&s, 13);
	Spush(&s, 14);
	Spush(&s, 15);
	Spush(&s, 16);
	Spush(&s, 17);
	Spush(&s, 18);
	Spush(&s, 19);
	Spush(&s, 20);
	Spush(&s, 21);
	Spush(&s, 22);
	Spush(&s, 23);
	Spush(&s, 24);
	cout << "------------------\n";
	cout << Spop(&s) << "\n\n";
	cout << Stop(&s) << '\n';

	system("pause");
	return 0;

}