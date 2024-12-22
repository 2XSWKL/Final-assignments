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
	if (head == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	head->total = 0;
	if (fread(&head->total, sizeof(int), 1, file) != 1)
	{
		fputs("无法读取学生数据文件\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	p->student = (Student*)malloc(sizeof(Student));
	if (p->student == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("无法读取学生数据\n", stderr);
			exit(1);
		}
		if (i == count - 1)
		{
			p->next = NULL;
			head->end = p;
			break;
		}
		p->next = (NODE*)malloc(sizeof(NODE));
		if (p->next == NULL)
		{
			fputs("无法分配内存\n", stderr);
			exit(1);
		}
		p = p->next;
		p->student = (Student*)malloc(sizeof(Student));
		if (p->student == NULL)
		{
			fputs("无法分配内存\n", stderr);
			exit(1);
		}
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
	if (head == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	head->total = 0;
	if (fread(&head->total, sizeof(int), 1, file) != 1)
	{
		fputs("无法读取学生数据文件\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->student = (Student*)malloc(sizeof(Student));
	if (p == NULL && p->student == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("无法读取学生数据\n", stderr);
			exit(1);
		}
		if (i == count - 1)
		{
			p->next = NULL;
			head->end = p;
			break;
		}
		p->next = (NODE*)malloc(sizeof(NODE));
		p->student = (Student*)malloc(sizeof(Student));
		p = p->next;
	}
	fclose(file);
	return head;
}

//添加学生
void add_std(HEAD* head)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->student = (Student*)malloc(sizeof(Student));
	if (new_node == NULL && new_node == NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}	
	head->end->next = new_node;
	head->end = new_node;
	head->total = head->total + 1;
	new_node->next = NULL;
	new_node->student->ID = head->total;

	printf("请输入学生姓名\n");
	scanf("%20s", new_node->student->name);
	printf("请输入语文成绩\n");
	scanf("%d", &new_node->student->grade[0]);
	printf("请输入数学成绩\n");
	scanf("%d", &new_node->student->grade[1]);
	printf("请输入英语成绩\n");
	scanf("%d", &new_node->student->grade[2]);
	printf("请输入体育成绩\n");
	scanf("%d", &new_node->student->grade[3]);
	printf("添加成功！\n");

	return;
}

//从文件添加学生
void add_std_from_file(HEAD* head, char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "rb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	int count = 0;
	while (fread(&count, sizeof(int), 1, file) == 1)
	{
		for (int i = 0; i < count; i++)
		{
			NODE* new_node = (NODE*)malloc(sizeof(NODE));
			new_node->student = (Student*)malloc(sizeof(Student));
			if (new_node == NULL && new_node == NULL)
			{
				fputs("无法分配内存\n", stderr);
				exit(1);
			}
			head->end->next = new_node;
			head->end = new_node;
			head->total = head->total + 1;
			new_node->next = NULL;
			new_node->student->ID = head->total;

			if (fread(new_node->student, sizeof(Student), 1, file) != 1)
			{
				fputs("无法读取学生数据\n", stderr);
				exit(1);
			}
			printf("学号:%d\n", new_node->student->ID);
			printf("姓名:%s\n", new_node->student->name);
			printf("课程一成绩:%d\n", new_node->student->grade[0]);
			printf("课程二成绩:%d\n", new_node->student->grade[1]);
			printf("课程三成绩:%d\n", new_node->student->grade[2]);
			printf("课程四成绩:%d\n", new_node->student->grade[3]);
		}
	}
	fclose(file);
	return;
}

//更改学生信息
void change_std(HEAD* head)
{
	NODE* p = search_std(head);
	char name[21] = {0}; // 初始化name数组
	int grade;
	printf("输入要更改的信息:\n");
	printf("1:姓名  2:课程一成绩  3:课程二成绩  4:课程三成绩  5:课程四成绩\n");
	int choice;
	if (scanf("%d", &choice) != 1) // 检查scanf返回值
	{
		fputs("输入错误\n", stderr);
		return;
	}
	switch (choice)
	{
	case 1:
		printf("输入姓名\n");
		int i = 0;
		while (getchar() != '\n'); // 清空输入缓冲区
		while (i < 20 && (name[i] = getchar()) != '\n') // 读取姓名
		{
			p->student->name[i] = name[i];
			i++;
		}
		p->student->name[i] = '\0';
		break;
	case 2:
		printf("输入成绩\n");
		if (scanf("%d", &grade) != 1) // 检查scanf返回值
		{
			fputs("输入错误\n", stderr);
			return;
		}
		p->student->grade[0] = grade;
		break;
	case 3:
		printf("输入成绩\n");
		if (scanf("%d", &grade) != 1) // 检查scanf返回值
		{
			fputs("输入错误\n", stderr);
			return;
		}
		p->student->grade[1] = grade;
		break;
	case 4:
		printf("输入成绩\n");
		if (scanf("%d", &grade) != 1) // 检查scanf返回值
		{
			fputs("输入错误\n", stderr);
			return;
		}
		p->student->grade[2] = grade;
		break;
	case 5:
		printf("输入成绩\n");
		if (scanf("%d", &grade) != 1) // 检查scanf返回值
		{
			fputs("输入错误\n", stderr);
			return;
		}
		p->student->grade[3] = grade;
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
	del_std->student = (Student*)malloc(sizeof(Student));
	if (del_std == NULL && del_std->student ==NULL)
	{
		fputs("无法分配内存\n", stderr);
		exit(1);
	}
	NODE* p = search_std(head);
	del_head->end->student = p->student;
	del_std->next = NULL;
	del_std->student = NULL;
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
		return NULL;
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
			return NULL;
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
		printf("姓名:%21s  ", p->student->name);
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
	for (int i = 0; i < Head->total - 1; i++)
	{
		if (p->next == NULL) break;
		if (p->student->grade[subject] < p->next->student->grade[subject])
		{
			// 交换学生信息
			Student* temp = p->student;
			p->student = p->next->student;
			p->next->student = temp;
			swaped = 1;
		}
		p = p->next;
	}
	return;
}

//按学号排序学生信息
void sort_std_by_id(HEAD* Head)
{
	NODE* p = Head->next;
	int swaped = 0;
	for (int i = 0; i < Head->total - 1; i++)
	{
		if (p->next == NULL) break;
		if (p->student->ID > p->next->student->ID)
		{
			// 交换学生信息
			Student* temp = p->student;
			p->student = p->next->student;
			p->next->student = temp;
			swaped = 1;
		}
		p = p->next;
	}
	return;
}

//显示课程最低，最高，平均分
void display_grades(HEAD* head)
{
	NODE* p = head->next;
	int min[4] = { 100, 100, 100, 100 };
	int max[4] = { 0, 0, 0, 0 };
	int sum[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < head->total; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (p->student->grade[j] < min[j]) min[j] = p->student->grade[j];
			if (p->student->grade[j] > max[j]) max[j] = p->student->grade[j];
			sum[j] += p->student->grade[j];
		}
		p = p->next;
	}
	printf("课程一最低分:%d  最高分:%d  平均分:%.2f\n", min[0], max[0], (float)sum[0] / head->total);
	printf("课程二最低分:%d  最高分:%d  平均分:%.2f\n", min[1], max[1], (float)sum[1] / head->total);
	printf("课程三最低分:%d  最高分:%d  平均分:%.2f\n", min[2], max[2], (float)sum[2] / head->total);
	printf("课程四最低分:%d  最高分:%d  平均分:%.2f\n", min[3], max[3], (float)sum[3] / head->total);
	return;
}

//保存学生信息
void save_std(HEAD* head, HEAD* del_head)
{
	//保存学生信息
	FILE* file;
	if ((file = fopen("students.dat", "wb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	fwrite(&head->total, sizeof(int), 1, file);
	NODE* p = head->next;
	for (int i = 0; i < head->total; i++)
	{
		fwrite(p->student, sizeof(Student), 1, file);
		p = p->next;
	}
	fclose(file);
	
	//保存删除的学生信息
	FILE* file1;
	if ((file1 = fopen("del_students.dat", "wb")) == NULL)
	{
		fputs("无法打开学生数据文件\n", stderr);
		exit(1);
	}
	fwrite(&del_head->total, sizeof(int), 1, file);
	NODE* p1 = head->next;
	for (int i = 0; i < head->total; i++)
	{
		fwrite(p1->student, sizeof(Student), 1, file);
		p1 = p1->next;
	}
	fclose(file1);
	return;
}


