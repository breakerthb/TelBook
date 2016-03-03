#include <stdio.h>

#include "ListNode.h"
#include "Record.h"
#include "MyFile.h"

void CleanScreen();
void CreateRecord();
void SearchRecord();

void SavedRecords();
void LoadRecords();

int main()
{
	int nMenu = 0;

	ListInit();

	LoadRecords();

	while (1)
	{
		printf("==== 通讯录 ====\n");
		printf("1. 录入\n");
		printf("2. 查询\n");
		printf("0. 退出\n");
		printf("----------------\n");
		printf("请输入要使用的功能：");

		scanf("%d", &nMenu);

		switch (nMenu)
		{
		case 0:
			// 退出
			SavedRecords();
			ListDestroy();
			exit(1);

			break;
		case 1:
			// 新增
			CreateRecord();
			break;
		case 2:
			// 查询
			SearchRecord();
			break;
		default:
			break;
		}

		CleanScreen();
	}

	ListDestroy();

	return 0;
}

// 新增记录
void CreateRecord()
{
	char str[50];
	int loop = 1;
	int t;

	while (loop)
	{
		gets(str); // Remove '\t'
		CleanScreen();

		Record* pR = NULL;
		RecordInit(&pR);

		printf("==== 新增条目 ====\n\n");
		printf("请输入下面的信息：\n");
		printf("姓名：");

		gets(str);
		RecordSetName(pR, str);

		printf("电话：");
		gets(str);
		RecordSetTel(pR, str);

		printf("备注：");
		gets(str);
		RecordSetPS(pR, str);
		printf("\n\n");

		printf("-------------------\n");
		printf("输入内容：\n");
		printf("-------------------\n");
		RecordPrint(pR);
		printf("是否保存(y/n)：");
		if (getchar() == 'y')
		{
			// 保存记录
			ListAdd(pR);
		}

		////
		printf("\n下一步\n");
		printf("1. 继续录入\n");
		printf("0. 返回\n");
		printf("----------------\n");
		printf("请输入要使用的功能：");

		scanf("%d", &t);

		if (t == 1)
		{
			// Do nothing
		}
		else
		{
			loop = 0;
		}
	}

}

void FindRecord()
{
	char str[50];
	int loop = 1;

	gets(str); // Remove '\t'
	CleanScreen();

	printf("==== 查找记录 ====\n\n");

	printf("请输入需要查找的姓名：\n");
	printf("姓名：");

	gets(str);

	Record* pRecord = ListFind(str);

	if (pRecord == NULL)
	{
		printf("未找到%s的资料。\n", str);
	}
	else
	{
		RecordPrint(pRecord);
	}

	system("pause");
}

// 查询记录
void SearchRecord()
{
	int loop = 1;
	while (loop)
	{
		CleanScreen();

		// 显示全部
		printf("==== 全部记录 ====\n\n");
		ListTraverShow();

		////
		int t;
		printf("\n\n下一步\n");
		printf("1. 显示全部\n");
		printf("2. 查找\n");
		printf("0. 返回\n");
		printf("----------------\n");
		printf("请输入要使用的功能：");

		scanf("%d", &t);

		if (t == 1)
		{
			// Do nothing
		}
		else if (t == 2)
		{
			FindRecord();
		}
		else
		{
			loop = 0;
		}
	}

}

void LoadRecords()
{
	Record* pR = NULL;

	if (OpenFile("book.txt", FOR_READ) != 1)
	{
		return;
	}

	char* pLine = NULL;
	while ((pLine = ReadLine()) != NULL)
	{
		if (pLine[0] == 0)
		{
			break;
		}

		RecordInit(&pR);

		RecordSetName(pR, pLine);

		pLine = ReadLine();
		RecordSetTel(pR, pLine);

		pLine = ReadLine();
		RecordSetPS(pR, pLine);

		pLine = ReadLine();

		ListAdd(pR);
	}

	CloseFile();
}

void SavedRecords()
{
	if (OpenFile("book.txt", FOR_WRITE) != 1)
	{
		return;
	}

	ListNode* pNode;
	for (pNode = g_pL; pNode->_pR != NULL; pNode = pNode->_pNext)
	{
		pNode->_pR;
		WriteLine(pNode->_pR->_pStrName->pBuf);
		WriteLine(pNode->_pR->_pStrTel->pBuf);
		WriteLine(pNode->_pR->_pStrPS->pBuf);
		WriteLine("----------");
	}

	CloseFile();
}



void CleanScreen()
{
	system("cls");
}