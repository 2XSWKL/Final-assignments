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
	while (menu == 0)
	{
		system("cls");
		printf("========================================\n����ѡ�\n");
		printf("0---������Ϣ���˳�\n");
		printf("1---����ѧ����Ϣ  2---����ѧ����Ϣ\n");
		printf("3---���ѧ����Ϣ  4---�޸�ѧ����Ϣ\n");
		printf("5---����ѧ����Ϣ  6---ɾ��ѧ����Ϣ\n");
		printf("7---����γ����Ʒ����ɼ�\n");
		printf("8������\n");
		printf("========================================\n");
		int choice;
		scanf("%d", &choice);
		
	}
	return choice;
}

//�˺Ų˵�
int account_menu()
{
	int choice = 0;
	return choice;
}

//ѧ����Ϣ�˵�
int student_menu()
{
	int choice = 0;
	return choice;
}
