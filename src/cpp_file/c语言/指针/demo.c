#include <stdio.h>
//不利用任何字符串函数 编程实现字符串链接函数的功能
// #include <type.h>
void arr_pinjie()
{
    char ch[100] = "welcome";
    char *ptr = "world",*q;
    //找到ch 的 /0字符的位置
    // printf("%d \n",ch[7]);
#if 0
    int index,index2;
    for(int i = 0;ch[i] != 0;i++)
    {
        index = i+1;
    }
    printf("%d \n",index);
    for(int i = 0;ptr[i] != 0;i++)
    {
        index2 = i+1;
    }
    printf("%d \n",index2);
    int j = 0;
    while(index2--)
    {
        
        ch[index] = ptr[j];
        j++;
        index++;
    }
    printf("%s \n",ch);
#else
    q = ptr;
    int i = 0;
    while (*(ch+i) != '\0')
    {
        /* code */
        i++;
    }
    printf("%d \n",i);
    while (*ptr != '\0')
    {
        /* code */
        ch[i] = *ptr;
        i++;
        ptr++;

    }
    ch[i] = *ptr;
    ptr = q;
    printf("%s \n",ch);
    printf("%s \n",ptr);

    
    

#endif
    
}
/*
    指针控制二维数组 指针数组  


*/
void double_arr()
{
    int arr[3][2] = {{1,2},{3,4},{5,6}};
    int a[3] = {1,2,3};
    int *ptr[3],*p[3];//int* ptr[0] ptr[1] ptr[2]  一级指针 和 二维数组 就联系起来了
    ptr[0] = a;
    ptr[1] = a + 1;
    ptr[2] = a + 2;
    //相当于列地址  +1就是列加1  而不是行加1
    p[0] = arr[0];
    p[1] = arr[1];
    p[2] = arr[2];
    //等价于
    int *pb[] = {arr[0],arr[1],arr[2]};

    //下面这种情况可以使用指针数组   
    // int *p,*q,*ptr;//直接用一个指针数组就好了  不然要起很多变量名
    printf("%d %d %d\n",a[0],a[1],a[2]);
    printf("%d %d %d\n",*(ptr[0]),*(ptr[1]),*(ptr[2]));
    printf("%d %d %d\n",*(p[0]+1),*(p[1]-1),arr[0][1]);



}
/*
    编程练习  利用指针数组 处理一个二维数组 ，要求求出二位数组所有元素的和
*/
void sum_doble()
{
    /*
        思考题:1、指针数组占多少个内容空间
            sizeof(ptr);一个指针占多少 n*4 跟操作系统有关
                int num = sizeof(p);
                //指针数组占多少内存空间  n*4 跟double int 无关 只与操作系统有关
                printf("total = %d\n",num);//total = 16
            2、指针数组名加1 移动多少个字节  ：4  p[0]  p[1]
            3、指针数组名相当于什么样的指针:二级指针
                int a[2][3] = {{1,2,3},{4,5,6}};
                int *p[] = {a[0],a[1]},sum;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
                int* * q;//二级指针
                q = p;



    
    */
#if 0
    int arr[3][2] = {{1,2},{3,4},{5,6}};
    int *ptr[1];
    ptr[0] = arr[0];
    int sum = 0,index = sizeof(arr)/sizeof(int);
    printf("index = %d\n",index);
    int i = 0;
    while (index--)
    {
        /* code */
        // printf("sum = %d\n",sum);
        sum += (*(ptr[0]+i));
        i++;
    }
    printf("sum = %d\n",sum);
#else
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p[] = {a[0],a[1]},sum;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    int* * q;//二级指针
    q = p;
    int num = sizeof(p);
    //指针数组占多少内存空间  n*4 跟double int 无关 只与操作系统有关
    printf("total = %d\n",num);
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            sum += *(p[i]+j);
            printf("%d %d ",a[i][j],*(p[i]+j));
        }
        puts(" ");
    }
    printf("sum = %d\n",sum);

#endif

}
/*
    多级指针的学习
*/
void fun_do_ptr()
{
    int m = 10;
    //声明变量 数据类型 * 名字
    int * p;
    // --- *q;
    int num = sizeof(p);
    printf("int* = %d\n",num);
    int* * q;
    num = sizeof(q);
    printf("int**p = %d\n",num);
    p = &m;
    printf("%p %p\n",p,&m);
    q = &p;
    printf("%p %p\n",q,&p);
    /*
        0x7ffda267a9b4 0x7ffda267a9b4
        0x7ffda267a9b8 0x7ffda267a9b8
    */
   //找出10这个值
   printf("%d %d %d \n",m,*p,**q);
   printf("%p %p",q,q+1);//移动了一个一级指针 就是四个字节  操作系统有关
   //内存空间计算
   




}
void fun()
{
     //指针数组和二级指针结合使用
    int a[3] = {1,2,3};
    int **q;
    int *psr[3] = {&a[0],&a[1],&a[2]};//int * ----p[0] p[1] p[2]
    q = &psr[0];//p 和 &p[0] 数组名 元素的起始地址 q+1 = &psr[1] q+2 = &psr[2]   两次解引用即可得值
    q = psr;//常用写法    指针数组和二级指针结合使用

    //打印值
    printf("%d %d %d\n",a[0],a[1],a[2]);
    printf("%d %d %d\n",*(psr[0]),*(psr[1]),*(psr[2]));
    printf("%d %d %d\n",**(q+0),**(q+1),**(q+2));//q+1指向的是&a[1]/psr[1]的地址 指针加加指向下一个  地址

    char *ch1 = "helo";
    char *ch2 = "world";
    char *ch3 = "niao";
    char **qa;
    char *ch[3] = {
        "helo","world","niao"
    };
    qa = ch;//qa = &ch[0]

    int num = sizeof(ch)/sizeof(char*);
    int i = 0;
    while(i < num)
    {
        printf("%s  %s %s\n",ch[i],*(qa+i),qa[i]);
        i++;
    }
}

void func()
{
    printf("==============\n");
    char *yt = "hello world";
    char *yt2 = "hello world";
    printf("yt=%p %p %s \n",&yt,yt,yt);
    printf("yt=%p %p %s \n",&yt2,yt2,yt2);
}
/*

    void万能指针和const修饰符的学习
*/
void void_const()
{
    int a = 10;
    double b = 2.10;
    void *p,*q;//赋值取值 都需要强制类型转换  赋值可以省略  有隐式类型转化  系统自动完成 但是取值需要强制类型转化
    // p =(void*)&a;
    p = &a;
    printf("%p\n",p);
    p++;
    printf("%p\n",p);
    /*
    对与void指针，在没有强制类型转换之前，不能进行任何指针的运算 
        0x7ffd88ce0ef4
        0x7ffd88ce0ef5 p++就改变了一个字节
    */
    q = (void *)&b;

    // q = &b;
    printf("%p\n",q);
    q++;
    printf("%p\n",q);
    int num = sizeof(double);
    int num1 = sizeof(int);

    printf("%d %d\n",num,num1);
    printf("%d %d\n",a,*(int *)p);//指针的强制类型转化 不然不知道是分配的int4个字节 还是double 8个字节
    printf("%.2f %.2f\n",b,*(double *)q);


}
//编程实现 使用void指针遍历一维数组
void void_arr()
{
    int a[] = {1,2,3,4,5};
    int num = sizeof(a)/sizeof(int);
    void *q;
    q = (void *)a;//数组名就是起始地址
    int i = 0;
    while (num--)
    {
        /* code */
        printf(" %d ",a[i]);
        printf(" %d ",*((int *)q + i));//先强制类型转换 再+  不然不知道加几个字节

        i++;
    }
    printf("\n");


    const int m  = 10;//变量常量化
    // m++;


}
#if 0
void const_ptr()
{
    // const修饰谁谁不能变   const *p(*P不能变 也就是值不能变 但是p地址可以变) *const p(p不能变 也就是*p可以变)
    int m = 10;
    int n = 20;
    int z = 30;
    const int *p = &n;
    int const *p = &n;//写法不一样  但是表达的意思一样的 推荐这样写  ①
    p = &m;
    // *p = 30;

    int* const q = &m;        //②
    // q = &n;
    *q = 50;

    const int* const p = &z;//都不能变




}
#endif
/*
    main函数详解  int argc  char const *argv[]
    // char const *argv[]指针数组 argv[0] argv[1]等等指针 
        加上const说明*argv[]不能变  即为char不能变

*/
int main(int argc, char const *argv[])
{
    /*
    0x56451208a833  无论有多少个hello world这个是地址都只有这一份  地址已经放好了
        yt=0x7ffd78795b78 0x56451208a833 hello world 
        yt=0x7ffd78795b80 0x56451208a833 hello world 
    内存地址是一样的  这是个字符串常量
    */
//    arr_pinjie();
    // double_arr();
    // sum_doble();
    // fun_do_ptr();
    // fun();
    // void_const();
    // const char *argv[] = {"./democ","其他内容"}；命令行赋值  这里可以显示出来
    char ch[] = "bh";
    printf("argc = %d\n",argc);
    for (size_t i = 0; i < argc; i++)
    {
        /* code */
        // *argv[i] = "nihao";
        argv[i] = ch;
        printf("argv = %s \n",argv[i]);//指针数组 就是地址  
    }
    
    // void_arr();
    return 0;
}
