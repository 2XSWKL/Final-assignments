#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 记录登陆时间
void rec_time(char username[])
{
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        perror("无法打开日志文件");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // 去掉换行符

    fprintf(file, "用户 %s 登陆时间: %s\n", username, time_str);
    fclose(file);
}

// 显示日志
void display_log()
{
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("无法打开日志文件");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

// 记录登出时间并保存日志
void save_log(char username[])
{
    FILE *file = fopen("log.txt", "a");
    if (file == NULL) {
        perror("无法打开日志文件");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // 去掉换行符

    fprintf(file, "用户 %s 登出时间: %s\n", username, time_str);
    fclose(file);
}