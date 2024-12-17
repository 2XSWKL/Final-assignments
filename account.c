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
void create_account(Account adminer[], int count)
{
	printf("�����˺�\n");
	if (count >= 10) 
	{
		printf("����Ա�˺����10��\n");
		return;
	}
	printf("�������˻�(8λ):");
	scanf("%s", adminer[count].username);
	printf("����������(8λ):");
	scanf("%s", adminer[count].password);
	FILE* file;
	if ((file = fopen("accounts.dat", "ab")) == NULL)
	{
		fputs("�޷����˺��ļ�\n", stderr);
		exit(1);
	}
	fwrite(&adminer[count], sizeof(Account), 1, file);
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
	char temp[9];
	printf("�������û���:\n");
	scanf("%8s", temp);
	for (int i = 0; i < count; i++) 
	{
		if (strcmp(temp, adminer[i].username) == 0) 
		{
			printf("����������(���λ���):\n");
			for (int j = 0; j < 3; j++) 
			{
				scanf("%8s", temp);
				if (strcmp(temp, adminer[i].password) == 0) 
				{
					printf("��¼�ɹ�!\n");
					return;
				}
			}
			printf("��¼ʧ�ܣ�����������Ρ�\n");
			return;
		}
	}
	printf("δ�������˻���\n");
	exit(0);
}

//�����˺�
void list_accounts(Account adminer, int count)
{

}
