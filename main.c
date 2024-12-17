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
	login(adminers, noa);

	//����ѧ����Ϣ
	HEAD* head = load_std();
	HEAD* del_head = load_del_std();
	//������־

	int flag = 1;//����ѭ��
	while (flag)
	{
		//�������˵�
		int choice;
		choice = general_menu();

		//���ܲ���
		switch (choice) {
		case 0:
			//����ѧ����Ϣ
			save_std(head);
			system("cls");
			printf("���ڱ���\n");
			flag = 1;//�˳�ѭ��
			break;
		case 1:
			//
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 2:
			//
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 3:
		case 4:
		case 5:
			//
			printf("�����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 6:
		case 7:
		case 8:
			//
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


	//�ͷ��ڴ�
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

	//�������
	return 0;
}