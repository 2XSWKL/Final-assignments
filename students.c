#include "students.h"
#include <stdio.h>
#include <stdlib.h>
//����ѧ����Ϣ
HEAD* load_std()
{
	FILE* file;
	if ((file = fopen("students.dat", "rb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
		exit(1);
	}
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (fread(head->total, sizeof(int), 1, file) != 1)
	{
		fputs("�޷���ȡѧ�������ļ�\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("�޷���ȡ�˺��ļ�\n", stderr);
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

//����ɾ����ѧ����Ϣ
HEAD* load_del_std()
{
	FILE* file;
	if ((file = fopen("del_students.dat", "rb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
		exit(1);
	}
	HEAD* head = (HEAD*)malloc(sizeof(HEAD));
	if (fread(head->total, sizeof(int), 1, file) != 1)
	{
		fputs("�޷���ȡѧ�������ļ�\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("�޷���ȡ�˺��ļ�\n", stderr);
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

//���ѧ��
void add_std(HEAD* head)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	head->end->next = new_node;
	head->end = new_node;
	head->total = head->total + 1;
	new_node->next = NULL;
	new_node->student->ID = head->total;

	printf("������ѧ������\n");
	scanf("%4s", new_node->student->name);
	printf("���������ĳɼ�\n");
	scanf("%d", new_node->student->grade[0]);
	printf("��������ѧ�ɼ�\n");
	scanf("%d", new_node->student->grade[1]);
	printf("������Ӣ��ɼ�\n");
	scanf("%d", new_node->student->grade[2]);
	printf("�����������ɼ�\n");
	scanf("%d", new_node->student->grade[3]);
	printf("��ӳɹ���\n");

	return;
}

//����ѧ����Ϣ
void change_std(HEAD* head)
{
	NODE* p = search_std(head);
	char name[5];
	int grade;
	printf("����Ҫ���ĵ���Ϣ:\n");
	printf("1:����  2:�γ�һ�ɼ�  3:�γ̶��ɼ�  3:�γ����ɼ�  5:�γ��ĳɼ�\n");
	int choice;
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("��������\n");
		scanf("%4s", name);
		for(int i = 0; i < 5; i++)
			p->student->name[i] = name[i];
		break;
	case 2:
		printf("����ɼ�\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 3:
		printf("����ɼ�\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 4:
		printf("����ɼ�\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	case 5:
		printf("����ɼ�\n");
		scanf("%d", &grade);
		p->student->grade[0] = grade;
		break;
	default:
		printf("������ѡ��\n");
		break;
	}

	return;
}

//ɾ��ѧ����Ϣ
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

//����ѧ����Ϣ
NODE* search_std(HEAD* head)
{
	int id;
	printf("����ѧ��\n");
	scanf("%d", &id);
	if (id <= 0 && id > head->total)
	{
		printf("ѧ�Ų���ȷ\n");
		return;
	}
	NODE* p = head->next;
	for (int i = 1; i <= head->total; i++)
	{
		if (p->student->ID == id) break;
		p = p->next;
		if (i == head->total)
		{
			printf("���޴���\n");
			system("pause");
			system("cls");
			return;
		}
	}
	if (p->student == NULL) printf("��ɾ��\n");
	printf("ѧ��:%d\n", p->student->ID);
	printf("����:%s\n", p->student->name);
	printf("�γ�һ�ɼ�:%d\n", p->student->grade[0]);
	printf("�γ̶��ɼ�:%d\n", p->student->grade[1]);
	printf("�γ����ɼ�:%d\n", p->student->grade[2]);
	printf("�γ��ĳɼ�:%d\n", p->student->grade[3]);

	return p;
}

//�г�ȫ��ѧ����Ϣ
void list_std(HEAD* head)
{
	NODE* p = head->next;
	for (int i = 1; i <= head->total; i++)
	{
		if (p->student == NULL) printf("��ɾ��\n");
		printf("ѧ��:%8d  ", p->student->ID);
		printf("����:%5s  ", p->student->name);
		printf("�γ�һ���ĳɼ�:%3d", p->student->grade[0]);
		printf("  %3d", p->student->grade[1]);
		printf("  %3d", p->student->grade[2]);
		printf("  %3d\n", p->student->grade[3]);
		p = p->next;
	}
	return;
}

//���ɼ�����ѧ����Ϣ
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

//��ѧ������ѧ����Ϣ
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

//����ѧ����Ϣ
void save_std(HEAD* head)
{
	FILE* file;
	if ((file = fopen("students.dat", "wb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
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


