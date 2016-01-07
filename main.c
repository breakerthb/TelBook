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

	printf("==== 创建新纪录 ====\n");


	RecordDestroy(&g_record);
}

void SearchRecord()
{

}