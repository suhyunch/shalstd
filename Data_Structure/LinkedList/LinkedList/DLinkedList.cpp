#include <iostream>
#include "DLinkedList.h"
using namespace std;

typedef int LData;
/*
struct _node {
	LData data;
	struct _node *next;
} Node;

struct _linkedList {
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	//int(*comp)(LData d1, LData d2);
	//1. 무조건 앞으로 삽입하는 리스트
} List;

*/
void ListInit(List *plist) {
	plist->head = new Node;
	plist->head->next = NULL;
	plist->numOfData = 0;
	return;
}
void LInsert(List *plist, LData data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	(plist->numOfData)++;
	return;
}

bool LFirst(List *plist, LData *pdata) {

	if (plist->head->next == NULL)
		return false;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return true;
}

bool LNext(List *plist, LData *pdata) {

	if (plist->cur->next == NULL)
		return false;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return true;
}

LData LRemove(List *plist) {
	//cur이 가르키고 있는 노드 삭제
	Node *rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}
int LCount(List *plist) {
	return plist->numOfData;
}
