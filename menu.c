#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

//��ӭ����
void welcome()
{
	printf("========================================\n");
	printf("           ѧ����Ϣ����ϵͳ\n");
	printf("========================================\n");
	system("pause");
	system("cls");
}

//���˵�
int general_menu()
{
	int menu = 0;
	int choice;
	while (menu == 0)
	{
		system("cls");
		printf("========================================\n����ѡ�\n");
		printf("0---������Ϣ���˳�\n");
		printf("1---����ѧ����Ϣ  2---���ѧ����Ϣ\n");
		printf("3---�޸�ѧ����Ϣ  4---����ѧ����Ϣ\n");
		printf("5---ɾ��ѧ����Ϣ  6---�����γ̳ɼ�\n");
		printf("7---���ɼ���ѧ������  8---��ʾ��־\n");
		printf("========================================\n");
		scanf("%d", &choice);
		if (choice < 0 || choice > 8)
		{
			printf("�����������������\n");
			system("pause");
		}
		else
		{
			menu = 1;
		}
	}
	return choice;
}