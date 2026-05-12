#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== 常量定义 =====
#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define DATA_FILE "students.txt"

// ===== 结构体定义 =====

// 学生信息结构体
typedef struct {
    int id;                          // 学号
    char name[MAX_NAME_LENGTH];      // 姓名
    int age;                         // 年龄
    char gender[10];                 // 性别
    float score;                     // 成绩
} Student;

// 学生列表结构体
typedef struct {
    Student students[MAX_STUDENTS];  // 学生数组
    int count;                        // 当前学生数量
} StudentList;

// ===== 函数声明 =====

// 初始化学生列表
void initStudentList(StudentList *list);

// 添加学生
int addStudent(StudentList *list, int id, const char *name, int age, const char *gender, float score);

// 删除学生
int deleteStudent(StudentList *list, int id);

// 修改学生信息
int modifyStudent(StudentList *list, int id, const char *name, int age, const char *gender, float score);

// 搜索学生
Student* searchStudent(StudentList *list, int id);

// 显示所有学生
void displayAllStudents(StudentList *list);

// 保存到文件
int saveToFile(StudentList *list, const char *filename);

// 从文件加载
int loadFromFile(StudentList *list, const char *filename);

#endif
