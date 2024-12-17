#include "students.h"
#include <stdio.h>
#include <stdlib.h>
//加载学生信息
HEAD* load_std()
{
	FILE* file;
	if ((file = fopen("students.dat", "rb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (fread(head->total, sizeof(int), 1, file) != 1)
	{
		fputs("无法读取学生数据文件\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("无法读取账号文件\n", stderr);
			exit(1);
		}
		if (i == count - 1)
		{
			p->next = NULL;
			head->end = p;
			break;
		}
		p->next = (NODE*)malloc(sizeof(NODE));
		p = p->next;
	}
	fclose(file);
	return head;
}

//加载删除的学生信息
HEAD* load_del_std()
{
	FILE* file;
	if ((file = fopen("del_students.dat", "rb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (fread(head->total, sizeof(int), 1, file) != 1)
	{
		fputs("无法读取学生数据文件\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("无法读取账号文件\n", stderr);
			exit(1);
		}
		if (i == count - 1)
		{
			p->next = NULL;
			head->end = p;
			break;
		}
		p->next = (NODE*)malloc(sizeof(NODE));
		p = p->next;
	}
	fclose(file);
	return head;
}

//添加学生
void add_std(HEAD* head)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	head->end->next = new_node;
	head->end = new_node;
	head->total = head->total + 1;
	new_node->next = NULL;
	new_node->student->ID = head->total;

	printf("请输入学生姓名\n");
	scanf("%4s", new_node->student->name);
	printf("请输入语文成绩\n");
	scanf("%d", new_node->student->grade[0]);
	printf("请输入数学成绩\n");
	scanf("%d", new_node->student->grade[1]);
	printf("请输入英语成绩\n");
	scanf("%d", new_node->student->grade[2]);
	printf("请输入体育成绩\n");
	scanf("%d", new_node->student->grade[3]);
	printf("添加成功！\n");

	return;
}

//更改学生信息
void change_std(HEAD* head)
{
	NODE* p = search_std(head);
	char name[5];
	int grade;
	printf("输入要更改的信息:\n");
	printf("1:姓名  2:课程一成绩  3:课程二成绩  3:课程三成绩  5:课程四成绩\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("输入姓名\n");
		scanf("%4s", name);
		for(int i = 0; i < 5; i++)
			p->student->name[i] = name[i];
		break;
	case 2:
		printf("输入成绩\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 3:
		printf("输入成绩\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 4:
		printf("输入成绩\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 5:
		printf("输入成绩\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	default:
		printf("请重新选择\n");
		break;
	}

	return;
}

//删除学生信息
void del_std(HEAD* head, HEAD* del_head)
{
	NODE* del_std = (NODE*)malloc(sizeof(NODE));
	NODE* p = search_std(head);
	del_std->student = p->student;
	del_std->next = NULL;
	p->student = NULL;
	del_head->end->next = del_std;
	del_head->end = del_std;
	del_head->total = del_head->total + 1;
	return;
}

//搜索学生信息
NODE* search_std(HEAD* head)
{
	int id;
	printf("输入学号\n");
	scanf("%d", &id);
	if (id <= 0 && id > head->total)
	{
		printf("学号不正确\n");
		return;
	}
	NODE* p = head->next;
	for (int i = 1; i <= head->total; i++)
	{
		if (p->student->ID == id) break;
		p = p->next;
		if (i == head->total)
		{
			printf("查无此人\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (p->student == NULL) printf("已删除\n");
	printf("学号:%d\n", p->student->ID);
	printf("姓名:%s\n", p->student->name);
	printf("课程一成绩:%d\n", p->student->grade[0]);
	printf("课程二成绩:%d\n", p->student->grade[1]);
	printf("课程三成绩:%d\n", p->student->grade[2]);
	printf("课程四成绩:%d\n", p->student->grade[3]);

	return p;
}

//列出全部学生信息
void list_std(HEAD* head)
{
	NODE* p = head->next;
	for (int i = 1; i <= head->total; i++)
	{
		if (p->student == NULL) printf("已删除\n");
		printf("学号:%8d  ", p->student->ID);
		printf("姓名:%5s  ", p->student->name);
		printf("课程一到四成绩:%3d", p->student->grade[0]);
		printf("  %3d", p->student->grade[1]);
		printf("  %3d", p->student->grade[2]);
		printf("  %3d\n", p->student->grade[3]);
		p = p->next;
	}
	return;
}

//按成绩排序学生信息
void sort_std_by_grades(HEAD* Head, int subject)
{
	NODE* p = Head->next;
	int swaped = 0;
	do 
	{
		swaped = 0;
		for (int i = 0; i < Head->total; i++)
		{
			if (p->next = NULL) break;
			if (p->student->grade[subject] < p->next->student->grade[subject])
			{
				Student temp = *(p->student);
				*(p->student) = *(p->next->student);
				*(p->next->student) = temp;
				p = p->next;
				swaped = 1;
			}
		}
	} while (swaped != 0);
	return;
}

//按学号排序学生信息
void sort_std_by_id(HEAD* Head)
{
	NODE* p = Head->next;
	int swaped = 0;
	do
	{
		swaped = 0;
		for (int i = 0; i < Head->total; i++)
		{
			if (p->next = NULL) break;
			if (p->student->ID > p->next->student->ID)
			{
				Student temp = *(p->student);
				*(p->student) = *(p->next->student);
				*(p->next->student) = temp;
				p = p->next;
				swaped = 1;
			}
		}
	} while (swaped != 0);
	return;
}

//保存学生信息
void save_std(HEAD* head)
{
	FILE* file;
	if ((file = fopen("students.dat", "wb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	fwrite(head->total, sizeof(int), 1, file);
	NODE* p = head->next;
	for (int i = 0; i < head->total; i++)
	{
		fwrite(p->student, sizeof(Student), 1, file);
		p = p->next;
	}
	return;
}


