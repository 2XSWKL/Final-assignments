#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

//欢迎界面
void welcome()
{
	printf("========================================\n");
	printf("           学生信息管理系统\n");
	printf("========================================\n");
	system("pause");
	system("cls");
}

//主菜单
int general_menu()
{
	int menu = 0;
	int choice;
	while (menu == 0)
	{
		system("cls");
		printf("========================================\n功能选项：\n");
		printf("0---保存信息并退出\n");
		printf("1---创建学生信息  2---浏览学生信息\n");
		printf("3---修改学生信息  4---查找学生信息\n");
		printf("5---删除学生信息  6---分析课程成绩\n");
		printf("7---按成绩或学号排序  8---显示日志\n");
		printf("========================================\n");
		scanf("%d", &choice);
		if (choice < 0 || choice > 8)
		{
			printf("输入错误，请重新输入\n");
			system("pause");
		}
		else
		{
			menu = 1;
		}
	}
	return choice;
}