typedef struct account//�˻��ṹ
{
	char username[9];
	char password[9];
}Account;

int loadAccounts(Account adminers[], int size);//�����˺�����
void create_account(Account adminer, int count);//�����˻�
void del_account(Account adminer);//ɾ���˺�
int encrypt(int password);//��������
void login(Account adminer[], int count);//��½
void list_accounts(Account adminer, int count);//�˺�����