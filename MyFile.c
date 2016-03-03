#include "MyFile.h"

#include "string.h"

#define BUF_SIZE 100
char pBuf[BUF_SIZE];

int OpenFile(char* pFileName, int nOperate)
{
	switch (nOperate)
	{
	case FOR_READ:
		fp = fopen(pFileName, "r");
		break;
	case FOR_WRITE:
		fp = fopen(pFileName, "w+");
		break;
	default:
		break;
	}

	if (fp == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CloseFile()
{
	fflush(fp);
	fclose(fp);
}

char* ReadLine()
{
	pBuf[0] = 0;

	if (feof(fp))
	{
		return NULL;
	}
	else
	{
		if (NULL == fgets(pBuf, BUF_SIZE, fp))
		{
			return NULL;
		}
		else
		{
			pBuf[strlen(pBuf) - 1] = 0;
		}

	}

	return pBuf;
}

int WriteLine(char* pLine)
{
	fwrite(pLine, sizeof(char), strlen(pLine), fp);
	fwrite("\n", sizeof(char), 1, fp);

	return 1;
}