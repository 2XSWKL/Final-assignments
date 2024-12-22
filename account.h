typedef struct account//账户结构
{
	char username[9];
	char password[9];
}Account;

int loadAccounts(Account adminers[], int size);//加载账号数据
void create_account(Account adminer[], int count);//创建账户
char* login(Account adminer[], int count);//登陆
