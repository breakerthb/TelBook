#include <stdio.h>

#include "Record.h"

void CleanScreen();
void CreateRecord();
void SearchRecord();

Record g_record;

int main()
{
	int nMenu = 0;

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


	return 0;
}

void CleanScreen()
{
	system("cls");
}

void CreateRecord()
{
	CleanScreen();

	RecordInit(&g_record);

	printf("==== �����¼�¼ ====\n");


	RecordDestroy(&g_record);
}

void SearchRecord()
{

}