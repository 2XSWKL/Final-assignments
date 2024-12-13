typedef struct account//账户结构
{
	char username[9];
	char password[9];
}Account;

int loadAccounts(Account adminers[], int size);//加载账号数据
void create_account(Account adminer, int count);//创建账户
void del_account(Account adminer);//删除账号
int encrypt(int password);//加密密码
void login(Account adminer[], int count);//登陆
void list_accounts(Account adminer, int count);//账号总览