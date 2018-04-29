#include <iostream>
#include "DLinkedList.h"
using namespace std;
/*
Dlinkedlist�� ADT

void ListInit(List *plist);
void LInsert(List *plist, LData data);

bool LFirst(List *plist, LData *pdata);
bool LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);
*/
int main() {
	List list;
	int data;
	ListInit(&list);

	//main menu
	
	cout << "�޴��� �����ϼ���. \n";
	while (true) {
		int menu;
		cout << "1. ������ ����\n";
		cout << "2. ��ü ������ �� Ȯ��\n";
		cout << "3. ���� List Ȯ��\n";
		cout << "4. ������ ����\n";
		cout << "5. ����\n";
		cin >> menu;

		if (menu == 5) break;
		switch (menu) {
		case 1:
			cout << "  �����͸� �Է��ϼ���(0�� ������ ������ �Է� ����)\n";
			while (true) {
				int d;
				cout << "\t";
				cin >> d;
				if (d == 0) break;
				LInsert(&list, d);
			}
			break;
		case 2 :
			cout << "��ü ������ �� : " << LCount(&list) << '\n';
			break;
		case 3:
			if (LFirst(&list, &data)) {
				cout << data << " ";
				
				while (LNext(&list, &data)) {
					cout << data << " ";
				}
			}
			cout << "\n\n";
			break;
		case 4:
			int d;
			cout << "  ������ �����͸� �Է��ϼ���\n";
			cin >> d;
			if(LFirst(&list, &data)){
				if (data == d)
					LRemove(&list);

				while (LNext(&list, &data))
					if (data == d)
						LRemove(&list);
			}
			break;
		}
	}

	


	system("pause");
	return 0;
}