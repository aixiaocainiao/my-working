#include <stdio.h>
#include <stdlib.h>
typedef struct Stu
{
	int age;
	struct Stu *next; 
}Student1,*StudentPtr;
struct Student
{
   int age;
   struct Student* next;
};
void test()
{
    //结构体指针初始化
    StudentPtr s1;
    s1 = (StudentPtr)malloc(sizeof(Student1));
    StudentPtr s2;
    s2 = (struct Stu*)malloc(sizeof(Student1));
    //结构体指针指向的结构体成员指针同样需要手动分配内存
    s1->next = (Student1*)malloc(sizeof(struct Stu));
    s2->next = (Student1*)malloc(sizeof(struct Stu));
    s1->age = 9;
    s2->age = 8;
    printf("%d\n",s1->age);
    //直接使用结构体若结构体中有成员指针  需要手动分配内存
    Student1 s3;
    s3.next = (StudentPtr)malloc(sizeof(Student1));
    s3.age = 13;
    printf("%d\n",s3.age);

}
int main(int argc, char const *argv[])
{
    test();
    struct Student t1;
    printf("%ld\n",sizeof(t1));
    return 0;
}
