//学生信息
typedef struct student
{
	int ID;
	char name[20];
	int grade[3];
}Student;

//链表节点
typedef struct node
{
	Student* student;
	struct node* next;
}NODE;

//链表头
typedef struct head
{
	int total;
	NODE* end;
	NODE* next;
}HEAD;

//加载学生信息
HEAD* load_std();

//加载删除的学生信息
HEAD* load_del_std();

//添加单个学生
void add_std(HEAD* head);

//从文件添加学生


//更改学生信息
void change_std(HEAD* head);

//删除学生信息
void del_std(HEAD* head, HEAD* del_head);

//搜索学生信息
NODE* search_std(HEAD* head);

//列出全部学生信息
void list_std(HEAD* head);

//按成绩排序学生信息
void sort_std_by_grades(HEAD* Head, int subject);

//按学号排序学生信息
void sort_std_by_id(HEAD* Head);

//显示课程最低，最高，平均分


//保存学生信息
void save_std(HEAD* Head);