#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ��¼��½ʱ��
void rec_time(char username[])
{
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        perror("�޷�����־�ļ�");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // ȥ�����з�

    fprintf(file, "�û� %s ��½ʱ��: %s\n", username, time_str);
    fclose(file);
}

// ��ʾ��־
void display_log()
{
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("�޷�����־�ļ�");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// ��¼�ǳ�ʱ�䲢������־
void save_log(char username[])
{
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        perror("�޷�����־�ļ�");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // ȥ�����з�

    fprintf(file, "�û� %s �ǳ�ʱ��: %s\n", username, time_str);
    fclose(file);
}