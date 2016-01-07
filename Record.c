#include "Record.h"

void RecordInit(Record* pR)
{
	StringInit(pR->_pStrName);
	StringInit(pR->_pStrTel);
	StringInit(pR->_pStrPS);
}

void RecordDestroy(Record* pR)
{
	StringDestroy(pR->_pStrName);
	StringDestroy(pR->_pStrTel);
	StringDestroy(pR->_pStrPS);
}