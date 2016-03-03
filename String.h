#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#define BUF_SIZE 100
#define NULL 0

typedef struct _tagString
{
    char* pBuf;
    int len;
}String;

String* StringCreate();
void StringDestroy(String* pStr);

void StringSet(String* pStr, char* pBuf);
char* StringGetBuffer(String* pStr);
void StringCopy(String* pDes, String* pSrc);
void StringAppend(String* pStr, char* pBuf);

#endif // STRING_H_INCLUDED
