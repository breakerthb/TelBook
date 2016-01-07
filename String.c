#include "String.h"

void StringInit(String* pStr)
{
    pStr->pBuf = (char*)malloc(BUF_SIZE * sizeof(char));
    pStr->len = 0;
}

void StringDestroy(String* pStr)
{
	if (pStr->pBuf != NULL)
	{
		free(pStr->pBuf);
		pStr->pBuf = NULL;
		pStr->len = 0;
	}
}

void StringSet(String* pStr, char* pBuf)
{
    int i = 0;
    while (*pBuf != 0)
    {
        pStr->pBuf[i++] = *pBuf++;
    }

    pStr->pBuf[i] = 0;
    pStr->len = i;
}

void StringCopy(String* pDes, String* pSrc)
{
    StringSet(pDes, pSrc->pBuf);
}

void StringAppend(String* pStr, char* pBuf)
{
    int i = pStr->len;

    while (*pBuf != 0)
    {
        pStr->pBuf[i++] = *pBuf++;
    }

    pStr->pBuf[i] = 0;
    pStr->len = i;
}
