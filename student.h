#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== 常量定义 =====
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define DATA_FILE "student.txt"

// ===== 链表节点结构体 =====

// 学生信息结构体
typedef struct Student {                          
    char name[MAX_NAME_LENGTH];      // 姓名
    char origin[MAX_NAME_LENGTH];    // 籍贯
    char phone1[MAX_PHONE_LENGTH];   // 电话号码1
    char phone2[MAX_PHONE_LENGTH];   // 电话号码2
    char email[MAX_EMAIL_LENGTH];    // 电子邮箱
    struct Student *next;            // 指向下一个节点的指针
} Student;

// 链表头指针
typedef struct {
    Student *head;    // 链表头节点
    int count;        // 学生数量
} StudentList;

// ===== 函数声明 =====

// 初始化链表
void initStudentList(StudentList *list);

// 创建新节点
Student* createNode(const char *name, const char *origin, 
                    const char *phone1, const char *phone2, const char *email);

// 添加学生（尾插法）
int addStudent(StudentList *list, const char *name, const char *origin, 
               const char *phone1, const char *phone2, const char *email);

// 删除学生
int deleteStudent(StudentList *list, const char *name);

// 修改学生信息
int modifyStudent(StudentList *list, const char *name, const char *newOrigin, 
                  const char *newPhone1, const char *newPhone2, const char *newEmail);

// 搜索学生
Student* searchStudent(StudentList *list, const char *name);

// 显示所有学生
void displayAllStudents(StudentList *list);

// 保存到文件
int saveToFile(StudentList *list, const char *filename);

// 从文件加载
int loadFromFile(StudentList *list, const char *filename);

// 释放链表内存
void freeStudentList(StudentList *list);

#endif