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
	if (head == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}
	head->total = 0;
	if (fread(&head->total, sizeof(int), 1, file) != 1)
	{
		fputs("�޷���ȡѧ�������ļ�\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	if (p == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}
	p->student = (Student*)malloc(sizeof(Student));
	if (p->student == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("�޷���ȡѧ������\n", stderr);
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
			fputs("�޷������ڴ�\n", stderr);
			exit(1);
		}
		p = p->next;
		p->student = (Student*)malloc(sizeof(Student));
		if (p->student == NULL)
		{
			fputs("�޷������ڴ�\n", stderr);
			exit(1);
		}
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
	if (head == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}
	head->total = 0;
	if (fread(&head->total, sizeof(int), 1, file) != 1)
	{
		fputs("�޷���ȡѧ�������ļ�\n", stderr);
		exit(1);
	}
	int count = head->total;
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->student = (Student*)malloc(sizeof(Student));
	if (p == NULL && p->student == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}
	head->next = p;
	for (int i = 0; i < count; i++)
	{
		if (fread(p->student, sizeof(Student), 1, file) != 1)
		{
			fputs("�޷���ȡѧ������\n", stderr);
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

//���ѧ��
void add_std(HEAD* head)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->student = (Student*)malloc(sizeof(Student));
	if (new_node == NULL && new_node == NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
		exit(1);
	}	
	head->end->next = new_node;
	head->end = new_node;
	head->total = head->total + 1;
	new_node->next = NULL;
	new_node->student->ID = head->total;

	printf("������ѧ������\n");
	scanf("%20s", new_node->student->name);
	printf("���������ĳɼ�\n");
	scanf("%d", &new_node->student->grade[0]);
	printf("��������ѧ�ɼ�\n");
	scanf("%d", &new_node->student->grade[1]);
	printf("������Ӣ��ɼ�\n");
	scanf("%d", &new_node->student->grade[2]);
	printf("�����������ɼ�\n");
	scanf("%d", &new_node->student->grade[3]);
	printf("��ӳɹ���\n");

	return;
}

//���ļ����ѧ��
void add_std_from_file(HEAD* head, char* filename)
{
	FILE* file;
	if ((file = fopen(filename, "rb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
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
				fputs("�޷������ڴ�\n", stderr);
				exit(1);
			}
			head->end->next = new_node;
			head->end = new_node;
			head->total = head->total + 1;
			new_node->next = NULL;
			new_node->student->ID = head->total;

			if (fread(new_node->student, sizeof(Student), 1, file) != 1)
			{
				fputs("�޷���ȡѧ������\n", stderr);
				exit(1);
			}
			printf("ѧ��:%d\n", new_node->student->ID);
			printf("����:%s\n", new_node->student->name);
			printf("�γ�һ�ɼ�:%d\n", new_node->student->grade[0]);
			printf("�γ̶��ɼ�:%d\n", new_node->student->grade[1]);
			printf("�γ����ɼ�:%d\n", new_node->student->grade[2]);
			printf("�γ��ĳɼ�:%d\n", new_node->student->grade[3]);
		}
	}
	fclose(file);
	return;
}

//����ѧ����Ϣ
void change_std(HEAD* head)
{
	NODE* p = search_std(head);
	char name[21] = {0}; // ��ʼ��name����
	int grade;
	printf("����Ҫ���ĵ���Ϣ:\n");
	printf("1:����  2:�γ�һ�ɼ�  3:�γ̶��ɼ�  4:�γ����ɼ�  5:�γ��ĳɼ�\n");
	int choice;
	if (scanf("%d", &choice) != 1) // ���scanf����ֵ
	{
		fputs("�������\n", stderr);
		return;
	}
	switch (choice)
	{
	case 1:
		printf("��������\n");
		int i = 0;
		while (getchar() != '\n'); // ������뻺����
		while (i < 20 && (name[i] = getchar()) != '\n') // ��ȡ����
		{
			p->student->name[i] = name[i];
			i++;
		}
		p->student->name[i] = '\0';
		break;
	case 2:
		printf("����ɼ�\n");
		if (scanf("%d", &grade) != 1) // ���scanf����ֵ
		{
			fputs("�������\n", stderr);
			return;
		}
		p->student->grade[0] = grade;
		break;
	case 3:
		printf("����ɼ�\n");
		if (scanf("%d", &grade) != 1) // ���scanf����ֵ
		{
			fputs("�������\n", stderr);
			return;
		}
		p->student->grade[1] = grade;
		break;
	case 4:
		printf("����ɼ�\n");
		if (scanf("%d", &grade) != 1) // ���scanf����ֵ
		{
			fputs("�������\n", stderr);
			return;
		}
		p->student->grade[2] = grade;
		break;
	case 5:
		printf("����ɼ�\n");
		if (scanf("%d", &grade) != 1) // ���scanf����ֵ
		{
			fputs("�������\n", stderr);
			return;
		}
		p->student->grade[3] = grade;
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
	del_std->student = (Student*)malloc(sizeof(Student));
	if (del_std == NULL && del_std->student ==NULL)
	{
		fputs("�޷������ڴ�\n", stderr);
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

//����ѧ����Ϣ
NODE* search_std(HEAD* head)
{
	int id;
	printf("����ѧ��\n");
	scanf("%d", &id);
	if (id <= 0 && id > head->total)
	{
		printf("ѧ�Ų���ȷ\n");
		return NULL;
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
			return NULL;
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
		printf("����:%21s  ", p->student->name);
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
	for (int i = 0; i < Head->total - 1; i++)
	{
		if (p->next == NULL) break;
		if (p->student->grade[subject] < p->next->student->grade[subject])
		{
			// ����ѧ����Ϣ
			Student* temp = p->student;
			p->student = p->next->student;
			p->next->student = temp;
			swaped = 1;
		}
		p = p->next;
	}
	return;
}

//��ѧ������ѧ����Ϣ
void sort_std_by_id(HEAD* Head)
{
	NODE* p = Head->next;
	int swaped = 0;
	for (int i = 0; i < Head->total - 1; i++)
	{
		if (p->next == NULL) break;
		if (p->student->ID > p->next->student->ID)
		{
			// ����ѧ����Ϣ
			Student* temp = p->student;
			p->student = p->next->student;
			p->next->student = temp;
			swaped = 1;
		}
		p = p->next;
	}
	return;
}

//��ʾ�γ���ͣ���ߣ�ƽ����
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
	printf("�γ�һ��ͷ�:%d  ��߷�:%d  ƽ����:%.2f\n", min[0], max[0], (float)sum[0] / head->total);
	printf("�γ̶���ͷ�:%d  ��߷�:%d  ƽ����:%.2f\n", min[1], max[1], (float)sum[1] / head->total);
	printf("�γ�����ͷ�:%d  ��߷�:%d  ƽ����:%.2f\n", min[2], max[2], (float)sum[2] / head->total);
	printf("�γ�����ͷ�:%d  ��߷�:%d  ƽ����:%.2f\n", min[3], max[3], (float)sum[3] / head->total);
	return;
}

//����ѧ����Ϣ
void save_std(HEAD* head, HEAD* del_head)
{
	//����ѧ����Ϣ
	FILE* file;
	if ((file = fopen("students.dat", "wb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
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
	
	//����ɾ����ѧ����Ϣ
	FILE* file1;
	if ((file1 = fopen("del_students.dat", "wb")) == NULL)
	{
		fputs("�޷���ѧ�������ļ�\n", stderr);
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


