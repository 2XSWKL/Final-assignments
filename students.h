//ѧ����Ϣ
typedef struct student
{
	int ID;
	char name[20];
	int grade[3];
}Student;

//����ڵ�
typedef struct node
{
	Student* student;
	struct node* next;
}NODE;

//����ͷ
typedef struct head
{
	int total;
	NODE* end;
	NODE* next;
}HEAD;

//����ѧ����Ϣ
HEAD* load_std();

//����ɾ����ѧ����Ϣ
HEAD* load_del_std();

//��ӵ���ѧ��
void add_std(HEAD* head);

//���ļ����ѧ��


//����ѧ����Ϣ
void change_std(HEAD* head);

//ɾ��ѧ����Ϣ
void del_std(HEAD* head, HEAD* del_head);

//����ѧ����Ϣ
NODE* search_std(HEAD* head);

//�г�ȫ��ѧ����Ϣ
void list_std(HEAD* head);

//���ɼ�����ѧ����Ϣ
void sort_std_by_grades(HEAD* Head, int subject);

//��ѧ������ѧ����Ϣ
void sort_std_by_id(HEAD* Head);

//��ʾ�γ���ͣ���ߣ�ƽ����


//����ѧ����Ϣ
void save_std(HEAD* Head);