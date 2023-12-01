/*
tips：最近要好好学习一下数据结构，所以必不可少的就是c语言的结构体和结构体指针了，所以就整理一下这些基础知识

c语言结构体(struct)是由一系列具有相同类型或不同类型的数据构成的数据集合。说的通俗一点就是一个集合。c语言是一门面向过程的编程语言，而结构体的使用在某些层次上跟面向对象有点异曲同工之处了。下面回归正题，学习一下结构体以及结构体指针的知识。


————————————————
版权声明：本文为CSDN博主「wrlovesmile」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/wrlovesmile/article/details/107885361
*/
#include <stdio.h>
#include <stdlib.h>
//定义结构体
struct student
{
	int num;
	char name[20];
	char sex;
};
//结构体+typedef 方式1
typedef struct Student
{
   int no;
   char name[12];
}Stu,student;
//用法举例3：如果使用了typedef，另外这里也可以不写Student（于是也不能struct Student stu1;了）
typedef struct
{
   int no;
   char name[12];
}Stu;

//结构体指针

/*
结构体指针用法1：
结构体要自引用时，Student1是错误用法。
试想引用成员next是另一个完整的结构，其内部还将包含它自己的成员next,
这第二个成员又包含一个完整的结构，它还将包括它自己的成员next，这样重复下去永无休止，内存都用光了。所以不合法。
struct Student1
{
   int age;
   struct Student1 next;
};
正确的用法是：结构体自引用 ，只能自引用指针。编译器在结构的长度确定之前就已经知道指针的长度，所以这种自引用是合法的。结构体的自引用在实现链表，树等高级的操作时用处很大。
struct Student1
{
	int age;
	struct Student *next; 
};
结构体指针用法注意：这样是不行的，虽然Student1代表了结构体，但是Student1类型名的声明是在末尾定义，当要声明struct{ }时，内部无法识别Student1类型。

typedef struct 
{
	int age;
	Student1 *next; 
}Student1,*StudentPtr;

结构体指针用法2：
注意此时，Student1是struct Student{}的别名，StudentPtr是Student的指针

typedef struct Student1
{
	int age;
	Student1 *next; 
}Student1,*StudentPtr;

我使用StudentPtr时出现了个有意思现象，结构体指针若不手动分分配内存，讲道理是不能用的。
当定义了两个结构体指针s1,s2，两个结构体指针都不分配内存，给其中一个赋值，然后使用没有问题，输出良好。
#include <stdio.h>
typedef struct Student1
{
	int age;
	 Student1 *next; 
}Student1,*StudentPtr;
int main()
{
	StudentPtr  s1;
	StudentPtr  s2;
	s1->age= 9;
	printf("%d",s1->age);
	return 0;
}
当尝试给另一个结构体指针赋值时，编译没有问题，程序运行奔溃。
#include <stdio.h>
typedef struct Student1
{
	int age;
	Student1 *next; 
}Student1,*StudentPtr;
int main()
{
	StudentPtr  s1;
	StudentPtr  s2;
	s1->age= 9;
    s2->age = 8;//会程序崩溃
	printf("%d",s1->age);
	return 0;
}
正确用法应该是

结构体指针需要初始化
结构体指针的成员指针同样需要初始化
若直接使用结构体，结构体中有成员指针，成员指针也要先初始化

*/
/*
    正确的用法是：结构体自引用 ，只能自引用指针。
    编译器在结构的长度确定之前就已经知道指针的长度，所以这种自引用是合法的。
    结构体的自引用在实现链表，树等高级的操作时用处很大。
*/
struct Student1
{
	int age;
	struct Student *next; 
};
typedef struct Student1
{
	int age;
	Student1 *next; 
}Student1,*StudentPtr;

void test()
{
    //结构体指针初始化
    StudentPtr s1;
    s1 = (StudentPtr)malloc(sizeof(Student1));
    StudentPtr s2;
    s2 = (struct Student1*)malloc(sizeof(Student1));
    //结构体指针指向的结构体成员指针同样需要手动分配内存
    s1->next = (Student1*)malloc(sizeof(struct Student1));
    s2->next = (Student1*)malloc(sizeof(struct Student1));
    s1->age = 9;
    s2->age = 8;
    printf("%d\n",s1->age);
    //直接使用结构体若结构体中有成员指针  需要手动分配内存
    Student1 s3;
    s3.next = (StudentPtr)malloc(sizeof(Student1));
    s3.age = 13;
    printf("%d\n",s3.age);

}
int main()
{
	//定义结构体数组
	struct student sarr[3] = { 1001,"wr1",'m',1003,"wr2",'m',1005,"wr3",'m' };
	struct student *p;//定义结构体指针
	
	p = sarr;//数组本身就是地址，不用取地址
	int num;
	num = p->num++;//num=p->num;p->num=p->num+1,优先级->的优先级高于++
	printf("num=%d,p->num=%d\n",num,p->num);

	//p->num上一步已经加一
	num = p++->num;//num=p->num，p=p+1
	printf("num=%d,p->num=%d\n", num, p->num);


    test();
	return 0;
}

