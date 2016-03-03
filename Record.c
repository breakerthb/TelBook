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
	printf("通讯录\n");
	printf("姓名：%s\n", StringGetBuffer(pR->_pStrName));
	printf("电话：%s\n", StringGetBuffer(pR->_pStrTel));
	printf("备注：%s\n", StringGetBuffer(pR->_pStrPS));
	printf("----------------\n");
}