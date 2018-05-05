#include <iostream>
using namespace std;

#define MAX_LEN 20

int input(int arr[], int idx) {
	//defalt 오름차순
	int n;
	cin >> n;
	arr[idx] = n;
	int i = idx-1;
	for (; i >= 0; i--) {
		if (n < arr[i]) {
			arr[i + 1] = arr[i];
			arr[i] = n;
		}
		else {
			break;
		}
	}
	idx++;
	for (int i = 0; i < idx; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return idx;
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
		else if (menu == 2) {
			for (int i = 0; i < len; i++) {
				cout << arr[i] << ' ';
			}cout << '\n';
		}
		else if (menu == 3) {
			for (int i = len-1; i >=0; i--) {
				cout << arr[i] << ' ';
			}cout << '\n';
		}
	}
	return 0;
}