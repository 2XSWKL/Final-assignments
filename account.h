typedef struct account//�˻��ṹ
{
	char username[9];
	char password[9];
}Account;

int loadAccounts(Account adminers[], int size);//�����˺�����
void create_account(Account adminer[], int count);//�����˻�
char* login(Account adminer[], int count);//��½
