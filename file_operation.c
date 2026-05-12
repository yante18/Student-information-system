#include <stdio.h>
#include "student.h"

// 不需要 extern，因为 student.h 已经声明了 createNode

int saveToFile(StudentList *list, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("无法打开文件进行写入！\n");
        return -1;
    }
    
    fprintf(fp, "%d\n", list->count);
    
    Student *current = list->head;
    while (current != NULL) {
        fprintf(fp, "%s %s %s %s %s\n",
                current->name,
                current->origin,
                current->phone1,
                current->phone2,
                current->email);
        current = current->next;
    }
    
    fclose(fp);
    printf("成功保存 %d 条记录到 %s\n", list->count, filename);
    return 0;
}

int loadFromFile(StudentList *list, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件进行读取！\n");
        return -1;
    }
    
    int count;
    fscanf(fp, "%d", &count);
    
    char name[MAX_NAME_LENGTH], origin[MAX_NAME_LENGTH];
    char phone1[MAX_PHONE_LENGTH], phone2[MAX_PHONE_LENGTH], email[MAX_EMAIL_LENGTH];
    
    for (int i = 0; i < count; i++) {
        fscanf(fp, "%s %s %s %s %s", name, origin, phone1, phone2, email);
        addStudent(list, name, origin, phone1, phone2, email);
    }
    
    fclose(fp);
    printf("成功从 %s 加载 %d 条记录\n", filename, list->count);
    return 0;
}