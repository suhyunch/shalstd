#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

#define MAX_LEN 20

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
	return;
}
void merge_sort(int arr[],int start, int end) {
	if (start == end) return;
	else if (start + 1 == end) {
		//defalt : 오름차순
		if (arr[start] > arr[end]) swap(arr[start], arr[end]);
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid + 1, end);

	int *sortedarr = new int[end - start + 1];

	int idx1 = start;
	int idx2 = mid + 1;
	int sidx = 0;

	while (idx1 <= mid && idx2 <= end) {
		if (arr[idx1] < arr[idx2]) 
			sortedarr[sidx++] = arr[idx1++];
		else
			sortedarr[sidx++] = arr[idx2++];
	}

	while (idx1 <= mid) 
		sortedarr[sidx++] = arr[idx1++];
	while(idx2 <= end)
		sortedarr[sidx++] = arr[idx2++];


	for (int i = start; i <= end; i++)
		arr[i] = sortedarr[i - start];

	delete[] sortedarr;
	return;
}

int input(int arr[], int idx) {
	int n;
	cin >> n;
	arr[idx++] = n;
	cout << "\t현재 정렬 : ";
	for (int i = 0; i < idx; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return idx;
}

void print(int arr[], int len, bool sort) {
	merge_sort(arr, 0, len-1); //오름차순
	cout << "\t정렬 결과 : ";
	if (!sort) {//오름차순
		for (int i = 0; i < len; i++) {
			cout << arr[i] << ' ';
		}cout << '\n';
	}
	else {
		for (int i = len-1; i >=0; i--) {
			cout << arr[i] << ' ';
		}cout << '\n';
	}

	return;
}
int main() {
	int arr[MAX_LEN];
	int len = 0;
	while (true) {
		cout << "메뉴를 선택하세요.\n";
		cout << "1. 데이터 입력\n";
		cout << "2. 정렬 출력(오름차순)\n";
		cout << "3. 정렬 출력(내림차순)\n";
		cout << "(0 : exit)\n";

		int menu;
		cin >> menu;
		if (menu == 0) break;
		else if (menu == 1) {
			if (len == MAX_LEN) {
				cout << "더 이상의 데이터 입력은 불가능합니다.\n";
			}
			else len = input(arr, len);
		}
		else if (menu == 2) print(arr, len, false);
		else if (menu == 3) print(arr, len, true);
	}
	return 0;
}