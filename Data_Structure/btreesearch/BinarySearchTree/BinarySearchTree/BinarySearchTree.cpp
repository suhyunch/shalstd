/*
#ifndef __BINART_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

typedef int BTData;

typedef struct _BTnode {

BTData data;
_BTnode *left;
_BTnode *right;
}BTreeNode;

BTreeNode* makeBTnode();
BTData GetData(BTreeNode *pbt);

BTreeNode* GetLeftChild(BTreeNode* pbt);
BTreeNode* GetRightChild(BTreeNode* pbt);

void SetData(BTreeNode* pbt, BTData data);
void BSTInsert(BTreeNode* pbt, BTData data);
#endif
*/
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void BSTInit(BTreeNode **proot) {
	*proot = NULL;
}
BTreeNode* makeBTnode() {
	BTreeNode *newNode = new BTreeNode;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTData GetData(BTreeNode *pbt) {
	return pbt->data;
}

BTreeNode* GetLeftChild(BTreeNode* pbt) {
	return pbt->left;
}

BTreeNode* GetRightChild(BTreeNode* pbt) {
	return pbt->right;
}

void SetData(BTreeNode* pbt, BTData data) {
	pbt->data = data;
	return;
}
void BSTInsert(BTreeNode **pbt, BTData data) {
	BTreeNode *pnode = NULL;
	BTreeNode *cnode = *pbt;
	BTreeNode *nnode = NULL;
	while (cnode != NULL) {
		if (data == GetData(cnode)) return;
		pnode = cnode;
		if (GetData(cnode) > data)
			cnode = GetLeftChild(cnode);
		else
			cnode = GetRightChild(cnode);
	}

	nnode = makeBTnode();
	SetData(nnode, data);
	if (pnode != NULL) {
		if (data < GetData(pnode))
			pnode->left = nnode;
		else
			pnode->right = nnode;
			
	}
	else {
		*pbt = nnode;
	}
	return;
}
BTreeNode *BSTSearch(BTreeNode *bst, BTData target) {
	//cout << bst->data << endl;
	BTreeNode *tmp = NULL;
	if (bst != NULL) {
		if (bst->data == target) { return bst; }
		if (target < (bst->data)) tmp=BSTSearch(bst->left, target);
		else tmp=BSTSearch(bst->right, target);
	}
	return tmp;
}
void InOrder(BTreeNode *pbt) {
	if (pbt == NULL) return;
	BTreeNode *tmp = pbt;
	if (tmp->left != NULL)
		InOrder(tmp->left);
	cout << tmp->data << ' ';
	if (tmp->right != NULL)
		InOrder(tmp->right);

	return;
}
/*
BTreeNode *BTdelete(BTreeNode *pbt, BTData target) {
	if (BSTSearch(pbt, target) != NULL) {

	}
}*/
int main() {
	BTreeNode *bstroot;
	BSTInit(&bstroot);
	BSTInsert(&bstroot, 9);
	BSTInsert(&bstroot, 10);
	BSTInsert(&bstroot, 8);
	BSTInsert(&bstroot, 1);
	BSTInsert(&bstroot, 7);
	BSTInsert(&bstroot, 100);
	InOrder(bstroot);
	cout << endl;
	if(BSTSearch(bstroot, 2)==NULL) cout << "Å½»ö ½ÇÆÐ" << endl;
	else cout << "Å½»ö ¼º°ø" << endl;
	if (BSTSearch(bstroot, 10) == NULL) cout << "Å½»ö ½ÇÆÐ" << endl;
	else cout << "Å½»ö ¼º°ø" << endl;
//	cout << bstroot->data << endl;
	//cout << bstroot->left->data << endl;
//	cout << bstroot->right->data << endl;
	system("pause");
	return 0;
}