#include"account.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�����˺�����
int loadAccounts(Account adminers[], int size)
{
	FILE* file;
	if ((file = fopen("accounts.dat", "rb")) == NULL)
	{
		fputs("�޷����˺��ļ�\n", stderr);
		exit(1);
	}
	int count = 0;
	while (fread(&adminers[count], sizeof(Account), 1, file) == 1)
	{
		count++;
		if (count >= size) break;
	}
	fclose(file);
	return count;
}

//�����˺�
void create_account(Account adminer, int count)
{
	if (count >= 10) 
	{
		printf("����Ա�˺����10��\n");
		return;
	}
	printf("�������˻�(8λ):");
	scanf("%s", adminer.username);
	printf("����������(8λ):");
	scanf("%s", adminer.password);
	FILE* file;
	if ((file = fopen("accounts.dat", "a")) == NULL)
	{
		fputs("�޷����˺��ļ�\n", stderr);
		exit(1);
	}
	fwrite(&adminer, sizeof(Account), 1, file);
	fclose(file);
	printf("��ӳɹ�!�´�����ʱ��Ч");
	return;
}

//ɾ���˺�
void del_account(Account adminer)
{

}

//�������
int encrypt(int password)
{
	int encrypted_pd = password;
	return encrypted_pd;
}

//��½�˺�
void login(Account adminer[], int count)
{
	Account adminers[10];
	int size = 0;
	size = loadAccounts(adminers, 10);
	char temp[9];
	scanf("%8s", temp);
	for (int i = 0;i < size ; i++)
	{
		for (int j = 0; strcmp(temp, adminers[i].username) == 0 && j < 3; j++)
		{
			printf("����������(���λ���):\n");
			scanf("%8s", &temp);
			if (strcmp(temp, adminers[i].password) == 0)
			{
				printf("��½�ɹ�!\n");
				return;
			}
		}
	}
	printf("δ�������˻�");
	exit(0);
}

//�����˺�
void list_accounts(Account adminer, int count)
{

}
