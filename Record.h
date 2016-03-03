#ifndef __RECORD_H__  
#define __RECORD_H__

#include "String.h"

typedef struct _tagRecord
{
	String* _pStrName;
	String* _pStrTel;
	String* _pStrPS;
}Record;

void RecordInit(Record** pR);
void RecordDestroy(Record* pR);

void RecordSetName(Record* pR, char* pBuf);
void RecordSetTel(Record* pR, char* pBuf);
void RecordSetPS(Record* pR, char* pBuf);

void RecordPrint(Record* pR);

#endif