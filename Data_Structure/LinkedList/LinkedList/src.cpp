#include <iostream>
#include "DLinkedList.h"
using namespace std;
/*
Dlinkedlist의 ADT

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
	
	cout << "메뉴를 선택하세요. \n";
	while (true) {
		int menu;
		cout << "1. 데이터 삽입\n";
		cout << "2. 전체 데이터 수 확인\n";
		cout << "3. 현재 List 확인\n";
		cout << "4. 데이터 삭제\n";
		cout << "5. 종료\n";
		cin >> menu;

		if (menu == 5) break;
		switch (menu) {
		case 1:
			cout << "  데이터를 입력하세요(0을 누르면 데이터 입력 종료)\n";
			while (true) {
				int d;
				cout << "\t";
				cin >> d;
				if (d == 0) break;
				LInsert(&list, d);
			}
			break;
		case 2 :
			cout << "전체 데이터 수 : " << LCount(&list) << '\n';
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
			cout << "  삭제할 데이터를 입력하세요\n";
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