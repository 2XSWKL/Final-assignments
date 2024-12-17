#include<stdio.h>
#include<stdlib.h>
#include"account.h"
#include"menu.h"
#include"students.h"
#include"log.h"


int main(void)
{
	welcome();
	//加载登陆相关
	Account adminers[10];
	int noa;//加载账号数
	noa = loadAccounts(adminers, 10);
	login(adminers, noa);

	//加载学生信息
	HEAD* head = load_std();
	HEAD* del_head = load_del_std();
	//记载日志

	int flag = 1;//控制循环
	while (flag)
	{
		//加载主菜单
		int choice;
		choice = general_menu();

		//功能部分
		switch (choice) {
		case 0:
			//保存学生信息
			save_std(head);
			system("cls");
			printf("正在保存\n");
			flag = 1;//退出循环
			break;
		case 1:
			//
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 2:
			//
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 3:
		case 4:
		case 5:
			//
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 6:
		case 7:
		case 8:
			//
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		default:
			printf("无效的选择，请重新输入\n");
			system("pause");
			system("cls");
			break;
		}
	}
	//保存日志登出


	//释放内存
	NODE* p = head->next;
	for (int i = 0; i < head->total; i++)
	{
		NODE* temp = p->next;
		free(p);
		p = temp;
	}
	p = del_head->next;
	for (int i = 0; i < del_head->total; i++)
	{
		NODE* temp = p->next;
		free(p);
		p = temp;
	}
	free(head);
	free(del_head);

	//程序结束
	return 0;
}