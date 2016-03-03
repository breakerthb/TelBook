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
		printf("==== ͨѶ¼ ====\n");
		printf("1. ¼��\n");
		printf("2. ��ѯ\n");
		printf("0. �˳�\n");
		printf("----------------\n");
		printf("������Ҫʹ�õĹ��ܣ�");

		scanf("%d", &nMenu);

		switch (nMenu)
		{
		case 0:
			// �˳�
			SavedRecords();
			ListDestroy();
			exit(1);

			break;
		case 1:
			// ����
			CreateRecord();
			break;
		case 2:
			// ��ѯ
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

// ������¼
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

		printf("==== ������Ŀ ====\n\n");
		printf("�������������Ϣ��\n");
		printf("������");

		gets(str);
		RecordSetName(pR, str);

		printf("�绰��");
		gets(str);
		RecordSetTel(pR, str);

		printf("��ע��");
		gets(str);
		RecordSetPS(pR, str);
		printf("\n\n");

		printf("-------------------\n");
		printf("�������ݣ�\n");
		printf("-------------------\n");
		RecordPrint(pR);
		printf("�Ƿ񱣴�(y/n)��");
		if (getchar() == 'y')
		{
			// �����¼
			ListAdd(pR);
		}

		////
		printf("\n��һ��\n");
		printf("1. ����¼��\n");
		printf("0. ����\n");
		printf("----------------\n");
		printf("������Ҫʹ�õĹ��ܣ�");

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

	printf("==== ���Ҽ�¼ ====\n\n");

	printf("��������Ҫ���ҵ�������\n");
	printf("������");

	gets(str);

	Record* pRecord = ListFind(str);

	if (pRecord == NULL)
	{
		printf("δ�ҵ�%s�����ϡ�\n", str);
	}
	else
	{
		RecordPrint(pRecord);
	}

	system("pause");
}

// ��ѯ��¼
void SearchRecord()
{
	int loop = 1;
	while (loop)
	{
		CleanScreen();

		// ��ʾȫ��
		printf("==== ȫ����¼ ====\n\n");
		ListTraverShow();

		////
		int t;
		printf("\n\n��һ��\n");
		printf("1. ��ʾȫ��\n");
		printf("2. ����\n");
		printf("0. ����\n");
		printf("----------------\n");
		printf("������Ҫʹ�õĹ��ܣ�");

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