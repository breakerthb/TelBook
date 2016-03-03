#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include "Record.h"

typedef struct _tagListNode
{
	Record* _pR;
	struct _tagListNode* _pPre;
	struct _tagListNode* _pNext;
}ListNode;

ListNode* g_pL;
ListNode* g_pCur;
int g_ListCnt;

void ListsInit();
void ListDestroy();
void ListAdd(Record* pR);
void ListDel(ListNode* pNode);
int ListCnt();
void ListTraverShow();

Record* ListFind(char* pStrName);


#endif