#include <iostream>
#include <time.h>
using namespace std;

#define MAX_LEN 20

void quick(int arr[], int left, int right) {
	if (left < right) {
		int pivot = right;//ÇÇ¹þ ÀÎµ¦½º
		int pivotval = arr[pivot];
		int sidx=left;
		for (int i = left; i < right; i++) {
			if (arr[i] < pivotval) {
				int tmp = arr[i];
				arr[i] = arr[sidx];
				arr[sidx++] = tmp;
			}
		}
		int tmp = arr[sidx];
		arr[sidx] = pivotval;
		arr[pivot] = tmp;
		quick(arr, left, sidx - 1);
		quick(arr, sidx + 1, right);
	}
	return;
}
int main() {
	srand((unsigned int)time(0));

	int arr[MAX_LEN];

	for (int i = 0; i < MAX_LEN; i++) {
		arr[i] = rand() % 200;
	}

	cout << "ÇöÀç Á¤·Ä : \n";
	for (int i = 0; i < MAX_LEN; i++) {
		cout << arr[i] << ' ';
	}cout << "\n\n";
	int len = MAX_LEN;
	quick(arr, 0, len - 1);

	cout << "Äü Á¤·Ä : \n";
	for (int i = 0; i < MAX_LEN; i++) {
		cout << arr[i] << ' ';
	}cout << "\n\n";
	system("pause");
	return 0;
}