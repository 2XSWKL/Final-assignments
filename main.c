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
	char* username;
	username = login(adminers, noa);

	//加载学生信息
	HEAD* head = load_std();
	HEAD* del_head = load_del_std();
	//记载日志
	rec_time(username);

	int flag = 1;//控制循环
	while (flag)
	{
		//加载主菜单
		int choice;
		choice = general_menu();

		//功能部分
		switch (choice) 
		{
		case 0:
			//保存学生信息
			save_std(head, del_head);
			printf("正在保存\n");
			printf("操作成功\n");
			system("pause");
			system("cls");
			flag = 0;//退出循环
			break;
		case 1:
			//创建学生信息
			printf("输入1手动添加学生信息，输入2从文件添加学生信息\n");
			int choice1;
			if (scanf("%d", &choice1) != 1) {
				printf("输入错误\n");
				break;
			}
			if (choice1 == 1)
				add_std(head);
			else if (choice1 == 2)
			{
				printf("输入文件名:");
				char filename[20];
				if (scanf("%s", filename) != 1) {
					printf("输入错误\n");
					break;
				}
				add_std_from_file(head, filename);
			}
			else
				printf("无效的选择\n");
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 2:
			//浏览学生信息
			list_std(head);
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 3:
			//修改学生信息
			change_std(head);
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 4:
			//查找学生信息
			search_std(head);
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 5:
			//删除学生信息
			del_std(head, del_head);
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 6:
			//分析课程成绩
			display_grades(head);
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 7:
			//排序
			printf("输入1按学号排序，输入2按成绩排序\n");
			int c;
			if (scanf("%d", &c) != 1) {
				printf("输入错误\n");
				break;
			}
			if (c == 1)
				sort_std_by_id(head);
			else if (c == 2)
			{
				printf("输入1按课程一排序，输入2按课程二排序，输入3按课程三排序\n");
				int s;
				if (scanf("%d", &s) != 1) {
					printf("输入错误\n");
					break;
				}
				sort_std_by_grades(head, s);
			}
			else
				printf("无效的选择\n");
			printf("操作成功\n");
			system("pause");
			system("cls");
			break;
		case 8:
			//显示日志
			display_log();
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
	void save_log(username);

	//释放内存
	NODE* p = head->next;
	for (int i = 0; i < head->total; i++)
	{
		NODE* temp = p->next;
		free(p->student);
		free(p);
		p = temp;
	}
	p = del_head->next;
	for (int i = 0; i < del_head->total; i++)
	{
		NODE* temp = p->next;
		free(p->student);
		free(p);
		p = temp;
	}
	free(head);
	free(del_head);

	//程序结束
	return 0;
}