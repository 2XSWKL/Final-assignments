#include"account.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//加载账号数据
int loadAccounts(Account adminers[], int size)
{
	FILE* file;
	if ((file = fopen("accounts.dat", "rb")) == NULL)
	{
		fputs("无法打开账号文件\n", stderr);
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

//创建账号
void create_account(Account adminer, int count)
{
	if (count >= 10) 
	{
		printf("管理员账号最多10个\n");
		return;
	}
	printf("请输入账户(8位):");
	scanf("%s", adminer.username);
	printf("请输入密码(8位):");
	scanf("%s", adminer.password);
	FILE* file;
	if ((file = fopen("accounts.dat", "a")) == NULL)
	{
		fputs("无法打开账号文件\n", stderr);
		exit(1);
	}
	fwrite(&adminer, sizeof(Account), 1, file);
	fclose(file);
	printf("添加成功!下次运行时生效");
	return;
}

//删除账号
void del_account(Account adminer)
{

}

//密码加密
int encrypt(int password)
{
	int encrypted_pd = password;
	return encrypted_pd;
}

//登陆账号
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
			printf("请输入密码(三次机会):\n");
			scanf("%8s", &temp);
			if (strcmp(temp, adminers[i].password) == 0)
			{
				printf("登陆成功!\n");
				return;
			}
		}
	}
	printf("未检索到账户");
	exit(0);
}

//总览账号
void list_accounts(Account adminer, int count)
{

}
