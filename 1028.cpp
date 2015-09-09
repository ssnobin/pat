// 结构体排序

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100005
struct Student
{
    char id[8];
    char name[10];
    int grade;
};
Student student[maxn];
int N,C;
bool idSmall(Student a, Student b)
{
    return strcmp(a.id,b.id) < 0;
}
bool nameSmall(Student a, Student b)
{
    if (strcmp(a.name,b.name)==0)
    {
        return strcmp(a.id,b.id) < 0;
    }
    else
    {
        return strcmp(a.name,b.name) < 0;
    }
}
bool gradeSmall(Student a,Student b)
{
    if (a.grade == b.grade)
    {
        return strcmp(a.id,b.id) < 0;
    }
    else
    {
        return a.grade < b.grade;
    }
}
int main()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        scanf("%s%s%d",student[i].id,student[i].name,&student[i].grade);
    }
    switch(C)
    {
        case 1:
        {
            sort(student,student+N,idSmall);
        }
            break;
        case 2:
        {
            sort(student,student+N,nameSmall);
        }
            break;
        case 3:
        {
            sort(student,student+N,gradeSmall);
        }
            break;
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s %s %d\n",student[i].id,student[i].name,student[i].grade);
    }
}
