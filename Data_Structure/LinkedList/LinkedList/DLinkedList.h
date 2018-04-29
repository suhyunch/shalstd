#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

typedef int LData;

typedef struct _node {
	LData data;
	struct _node *next;
} Node;

typedef struct _linkedList {
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	//int(*comp)(LData d1, LData d2);
	//1. 무조건 앞으로 삽입하는 리스트
} List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

bool LFirst(List *plist, LData *pdata);
bool LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);
#endif
