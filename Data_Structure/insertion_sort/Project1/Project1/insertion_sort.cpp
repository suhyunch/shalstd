#include <iostream>
using namespace std;

#define MAX_LEN 20

int input(int arr[], int idx) {
	//defalt ��������
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
		cout << "�޴��� �����ϼ���.\n";
		cout << "1. ������ �Է�\n";
		cout << "2. ���� ���(��������)\n";
		cout << "3. ���� ���(��������)\n";
		cout << "(0 : exit)\n";

		int menu;
		cin >> menu;
		if (menu == 0) break;
		else if (menu == 1) {
			if (len == MAX_LEN) {
				cout << "�� �̻��� ������ �Է��� �Ұ����մϴ�.\n";
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