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
	while (menu == 0)
	{
		system("cls");
		printf("========================================\n功能选项：\n");
		printf("0---保存信息并退出\n");
		printf("1---创建学生信息  2---增加学生信息\n");
		printf("3---浏览学生信息  4---修改学生信息\n");
		printf("5---查找学生信息  6---删除学生信息\n");
		printf("7---输入课程名称分析成绩\n");
		printf("8—排序\n");
		printf("========================================\n");
		int choice;
		scanf("%d", &choice);
		
	}
	return choice;
}

//账号菜单
int account_menu()
{
	int choice = 0;
	return choice;
}

//学生信息菜单
int student_menu()
{
	int choice = 0;
	return choice;
}
