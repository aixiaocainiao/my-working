#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    指针函数   指针是修饰词  函数才是重要部分
    指针函数的返回值: 全局变量的地址、static变量的地址、字符常量的地址(这个是不能修改字符的)、malloc堆的地址(程序员自己开辟的)
    char* func()
*/
char* fun(char *str)
{
    char *z = str;//起始地址 不变 用来返回
    char *s = str;//s和str最后地址都变了  不是最初那个地址了 都是字符最后那个地址
    while(*str){
        if(*str == ' '){
            str++;
        }
        else{

            *s = *str;
            s++;
            str++;
        }


    }
    *s = '\0';
    // return s,p;是错误的  地址已经变了
    return z;


}
char* getstring()
{

    static char ch[20];
    strcpy(ch,"hello");
    return ch;
}
/*
    编写一个指针函数  实现字符串链接
*/
char* str_con(char *str,char *chr)
{
    char *st = str;//起始地址  作为返回值使用的
#if 0
    while(*str){
        str++;    
    }
    while(*chr){
        *str = *chr;
        str++;
        chr++;
    }
    *str = '\0';
#endif
#if 0
    while (*(str++));//退出while循环的时候 str已经加过了 
    str--;
    while (*chr)
    {
        *str++ = *chr++;
    }
    *str = '\0';
#endif

#if 1
    while (*(str++));//退出while循环的时候 str已经加过了 
    str--;
    *str = '\0';
    while(*str++ = *chr++);//*str = '\0'这个就没必要了  因为chr给过了  

#endif
    
    // printf("%s\n",str);
    
    return st;
}
/*
    需求:编写一个指针函数  将整数1234转化为字符串1234

    1234/10 = 123 剩余 4
    123/10 = 12  剩余  3
    12/10 = 1 剩余   2
    1/10 = 0 剩余   1
    顺序颠倒    取出来了数字位   再变成字符

*/

// char* itor(int num)
// {
//     int r,i = 0;
//     static char p[50];
   
//     while (num)
//     {
//        r = num %10;
//        num = num /10;
//        p[i] = r + '0';
//        i++;
//     }
//     p[i] = '\0';
//     //位置翻转
//     char *ptr_begin = p;
//     int number = sizeof(p)/sizeof(char);
//     char *ptr_end = &p[number];
    
//     return p;
    
// }
void test()
{
    /* code */
    char str[20];
    char ch[50];//整理之后再拷贝
    strcpy(str,"h e l loworld");
    char* z = fun(str);
    strcpy(ch,strcpy(str,fun(str)));
    printf("%s\n",ch);

    printf("%s\n",z);


    printf("%s\n",getstring());

}
void test01()
{
    char ch[30] = "nihao";
    char zh[20] = "nothing";
    char* st = str_con(ch,zh);
    char* zt = str_con(zh,ch);

    printf("%s\n",st);
    printf("%s\n",zt);


}
void error_test()
{
    int num = 1234;
    int yushu;
    int ge,shi,bai,qian;
    if(num / 10 == 0){

        ge =  num % 10;
    }
    else{
        ge =  num % 10;
        yushu = num /10;
        if(yushu / 10 == 0){

            shi = yushu %10;
        }else{
            shi = yushu % 10;
            bai = yushu / 10;
        }
        

    }
    

    printf(" %d ",ge);
}
char* itor(char *ptr,int num)
{
    // do
    // {
    //     ptr[i] = num % 10 + '0';//数字和字符之间相差 48  man ASCII
    //     i++;
        
    // } while (num/10);
    int i = 0,r;
    while (num)//这个是num 不是num/10
    {
        /* code */
        r = num %10;
        ptr[i] = r + 48;
        num = num /10;
        i++;
    }
    printf("%d\n",i);
    ptr[i] = '\0';
    int j = i - 1;
    i = 0;
    //将顺序颠倒过来 首尾指针 递增递减 中间为判断
    // char *p_begin = ptr;
    // char *p_end = &ptr[i];
    while(i < j){
        r = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = r;
        i++;
        j--;
    }

    printf("%s",ptr);
    
    printf("\n");
    // return NULL;

    return ptr;
    


}
void my_tet()
{
    // char ;
    char p[50],*r;
    int num;
    printf("input: ");
    scanf("%d",&num);
    r = itor(p,num);
    puts(r);
    puts(p);



}
#if 0
char* itor(int num)
{
    static char ptr[50];//这样指针是不能更改的 因为是数组名
    int i = 0,r;
    while (num)//这个是num 不是num/10
    {
        /* code */
        r = num %10;
        ptr[i] = r + 48;
        num = num /10;
        i++;
    }
    printf("%s",ptr);
    // for(int j = 0;j < i;j++)
    // {
    //     printf(" %d ",ptr[j] - '0');
    // }
    printf("\n");
    return ptr;
    

}
void my_test()
{
    int num;
    char *s;
    printf("input: ");
    scanf("%d",&num);
    // s = itor(num);
    printf("%s",s);
}
#endif
/*
    递归函数的学习  zzzz 求5的阶乘 5！
    理论:递归函数是指一个函数的函数体直接或间接的调用了函数自身
*/
int func(int num)
{
    if(num == 1 || num == 0)
        return 1;
    
    return num*func(num-1);
    

}
/*
    斐波那契数列数列  兔子繁殖问题 1 1 2 3 5 8
*/
int fib(int num)
{
    if(num == 1 || num == 2){
        return 1;
    }
    return fib(num -1) + fib(num -2);
}
void z_tset()
{
   // puts(s);
    // my_tet();
    int num = func(5);
    printf("%d\n",num);
    int yue;
    printf("input: ");
    scanf("%d",&yue);
    printf("output: %d\n",fib(yue));

}
/*
    函数指针 数据类型 (*函数名)(参数)
*/
int add(int num1,int num2)
{

    return num1+num2;
}
int sub(int num1,int num2)
{

    return num1-num2;
}
int Mul(int num1,int num2)
{

    return num1*num2;
}
void te()
{
    /*
        函数指针的使用场景:
        #include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

       Compile and link with -pthread.


       void *(*start_routine) (void *)  函数指针 参数指针  返回值 指针

    */
    int num1 = 20,num2 = 30;
    // printf("input: ");
    // int (*p)(int a,int b);这里面a和b可以省略 因为用不到  声明的时候可以不写
    // printf("%d\n",p(num1,num2));

    // int (*p)(int,int);
    

    //函数指针 数组
    int (*p[3])(int,int);

    p[0] = add;
    printf("%d\n",add(num1,num2));
    printf("%d\n",p[0](num1,num2));
    printf("%d\n",(*p[0])(num1,num2));

    p[1] = sub;
    printf("%d\n",sub(num1,num2));
    printf("%d\n",p[1](num1,num2));
    printf("%d\n",(*p[1])(num1,num2));

    p[2] = Mul;
    printf("%d\n",Mul(num1,num2));
    printf("%d\n",p[2](num1,num2));
    printf("%d\n",(*p[2])(num1,num2));




}
void my_qsort()
{

    /*
    
         #include <stdlib.h>

       void qsort(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *));

       void qsort_r(void *base, size_t nmemb, size_t size,
                  int (*compar)(const void *, const void *, void *),
                  void *arg);

    
    */
    //调用qsort实现整形数组的排序
    int sr[] = {5,4,2,3,1};
    //可以冒泡排序
}
int main(int argc, char const *argv[])
{

    

 
    return 0;
    
}
