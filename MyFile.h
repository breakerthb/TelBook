#ifndef __MY_FILE_H__
#define __MY_FILE_H__

#include <stdio.h>

#define FOR_READ		0
#define FOR_WRITE		1

FILE* fp;

extern int OpenFile(char* pFileName, int nOperate);
extern void CloseFile();

extern char* ReadLine();
extern int WriteLine(char* pLine);

#endif