#include<stdio.h>
#include<stdlib.h>
#include"account.h"
#include"menu.h"
#include"students.h"
#include"log.h"

int main(void)
{
	welcome();
	//���ص�½���
	Account adminers[10];
	int noa;//�����˺���

	noa = loadAccounts(adminers, 10);
	char* username;
	username = login(adminers, noa);

	//����ѧ����Ϣ
	HEAD* head = load_std();
	HEAD* del_head = load_del_std();
	//������־
	rec_time(username);

	int flag = 1;//����ѭ��
	while (flag)
	{
		//�������˵�
		int choice;
		choice = general_menu();

		//���ܲ���
		switch (choice) 
		{
		case 0:
			//����ѧ����Ϣ
			save_std(head, del_head);
			printf("���ڱ���\n");
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			flag = 0;//�˳�ѭ��
			break;
		case 1:
			//����ѧ����Ϣ
			printf("����1�ֶ����ѧ����Ϣ������2���ļ����ѧ����Ϣ\n");
			int choice1;
			if (scanf("%d", &choice1) != 1) {
				printf("�������\n");
				break;
			}
			if (choice1 == 1)
				add_std(head);
			else if (choice1 == 2)
			{
				printf("�����ļ���:");
				char filename[20];
				if (scanf("%s", filename) != 1) {
					printf("�������\n");
					break;
				}
				add_std_from_file(head, filename);
			}
			else
				printf("��Ч��ѡ��\n");
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 2:
			//���ѧ����Ϣ
			list_std(head);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 3:
			//�޸�ѧ����Ϣ
			change_std(head);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 4:
			//����ѧ����Ϣ
			search_std(head);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 5:
			//ɾ��ѧ����Ϣ
			del_std(head, del_head);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 6:
			//�����γ̳ɼ�
			display_grades(head);
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 7:
			//����
			printf("����1��ѧ����������2���ɼ�����\n");
			int c;
			if (scanf("%d", &c) != 1) {
				printf("�������\n");
				break;
			}
			if (c == 1)
				sort_std_by_id(head);
			else if (c == 2)
			{
				printf("����1���γ�һ��������2���γ̶���������3���γ�������\n");
				int s;
				if (scanf("%d", &s) != 1) {
					printf("�������\n");
					break;
				}
				sort_std_by_grades(head, s);
			}
			else
				printf("��Ч��ѡ��\n");
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 8:
			//��ʾ��־
			display_log();
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		default:
			printf("��Ч��ѡ������������\n");
			system("pause");
			system("cls");
			break;
		}
	}
	//������־�ǳ�
	void save_log(username);

	//�ͷ��ڴ�
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

	//�������
	return 0;
}