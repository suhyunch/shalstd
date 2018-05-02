#ifndef __BINART_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

typedef int BTData;

typedef struct _BTnode {
	
	BTData data;
	_BTnode *left;
	_BTnode *right;
}BTreeNode;
void BSTInit(BTreeNode **proot);
BTreeNode* makeBTnode();
BTData GetData(BTreeNode *pbt);

BTreeNode* GetLeftChild(BTreeNode* pbt);
BTreeNode* GetRightChild(BTreeNode* pbt);

void SetData(BTreeNode* pbt, BTData data);
void BSTInsert(BTreeNode** pbt, BTData data);
BTreeNode *BSTSearch(BTreeNode *bst, BTData target);
//BTreeNode *BTdelete(BTreeNode *pbt, BTData target);
void InOrder(BTreeNode *pbt);
#endif