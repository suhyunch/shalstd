#include <iostream>
using namespace std;

#define MAX_LEN 20


void bbsort(int arr[], int n, int sort) {
	if (sort) {
		//내림차순이라면
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n-i-1; j++) {
				if (arr[j] < arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
	else {
		for (int i = 0; i < n-1; i++) {
			for (int j = 0; j < n - i-1; j++) {
				if (arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
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
	if (len > 1) {
		if (sort == false) bbsort(arr, len, false); //오름차순
		else bbsort(arr, len, true); //내림차순
	}
	cout << "\t정렬 결과 : ";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ' ';
	}cout << '\n';
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
			else len=input(arr, len);
		}
		else if (menu == 2) print(arr, len, false);
		else if (menu == 3) print(arr, len, true);
	}
	return 0;
}