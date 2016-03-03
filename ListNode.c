#include "ListNode.h"


void ListInit()
{
	g_pL = (ListNode*)malloc(sizeof(ListNode));

	g_pCur = g_pL;

	g_pCur->_pR = NULL;
	g_pCur->_pPre = NULL;
	g_pCur->_pNext = NULL;
	g_ListCnt = 0;
}

void ListDestroy()
{
	for (g_pCur = g_pL; g_pCur != NULL;)
	{
		RecordDestroy(g_pCur->_pR);
		g_pL = g_pCur->_pNext;
		free(g_pCur);
		g_pCur = g_pL;
	}

	g_ListCnt = 0;
}

void ListAdd(Record* pR)
{
	g_pCur->_pR = pR;

	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));

	g_pCur->_pNext = pNode;
	pNode->_pNext = NULL;
	pNode->_pPre = g_pCur;
	g_pCur = g_pCur->_pNext;

	g_pCur->_pR = NULL;
	g_pCur->_pNext = NULL;

	g_ListCnt++;
}

void ListDel(ListNode* pNode)
{
	if (g_ListCnt < 1)
	{
		return;
	}

	if (pNode->_pPre == NULL)
	{
		g_pL = g_pL->_pNext;
		g_pL->_pPre = NULL;
	}
	else if (pNode->_pNext == NULL)
	{
		pNode->_pPre->_pNext = NULL;
	}
	else
	{
		pNode->_pPre->_pNext = pNode->_pNext;
		pNode->_pNext->_pPre = pNode->_pPre;
	}

	RecordDestroy(pNode->_pR);
	free(pNode);

	g_ListCnt--;
}

void ListTraverShow()
{
	ListNode* pNode;
	for (pNode = g_pL; pNode->_pR != NULL; pNode = pNode->_pNext)
	{
		RecordPrint(pNode->_pR);
	}
}

int ListCnt()
{
	return g_ListCnt;
}

Record* ListFind(char* pStrName)
{
	ListNode* pNode;
	for (pNode = g_pL; pNode->_pR != NULL; pNode = pNode->_pNext)
	{
		if (strcmp(pNode->_pR->_pStrName->pBuf, pStrName) == 0)
		{
			return pNode->_pR;
		}
	}

	return NULL;
}
