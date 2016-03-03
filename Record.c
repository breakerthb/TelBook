#include "Record.h"

void RecordInit(Record** pR)
{
	*pR = (Record*)malloc(sizeof(Record));

	(*pR)->_pStrName = StringCreate();
	(*pR)->_pStrTel = StringCreate();
	(*pR)->_pStrPS = StringCreate();
}

void RecordDestroy(Record* pR)
{
	if (pR != NULL)
	{
		StringDestroy(pR->_pStrName);
		StringDestroy(pR->_pStrTel);
		StringDestroy(pR->_pStrPS);

		free(pR);
	}
}

void RecordSetName(Record* pR, char* pBuf)
{
	StringSet(pR->_pStrName, pBuf);
}

void RecordSetTel(Record* pR, char* pBuf)
{
	StringSet(pR->_pStrTel, pBuf);
}

void RecordSetPS(Record* pR, char* pBuf)
{
	StringSet(pR->_pStrPS, pBuf);
}

void RecordPrint(Record* pR)
{
	printf("----------------\n");
	printf("ͨѶ¼\n");
	printf("������%s\n", StringGetBuffer(pR->_pStrName));
	printf("�绰��%s\n", StringGetBuffer(pR->_pStrTel));
	printf("��ע��%s\n", StringGetBuffer(pR->_pStrPS));
	printf("----------------\n");
}