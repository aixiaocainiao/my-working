#include <iostream>
/*
    指针的学习
*/
void forexample()
{
    int a[] = {5,8,7,9,10};


    int y,*p = &a[1];

    y = (*--p)++;//--p  p = a  然后解引用 *P = a[0] 再加加  先给 再加 a[0]  = 6  但是 y = a[0] = 5
    std::cout << "y = " << y << std::endl;
    std::cout << "a[0] = " << a[0] << std::endl;

}
void test_bf()
{
    for(int i = 0;i < 7;i++){
        int y = i++;
    
        // std::cout << (i++) << " ";//先给再加
        std::cout << y << " ";//先给再加

    }
    std::cout << std::endl;
    int str[5],*p;
    p = str;
    for(int i = 0;i < 5;i++)
    {
        std::cin >> *(p++);
    }
    //其实这里++的优先级 比 *高  可以加一个括号 不加也可以  自己要理解是怎样运算的   p++先给后加  还是 在给*p赋值
    for(auto i : str)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    /*
        前置++是将自身加1的值赋值给新变量，然后自身也加1
        后置++是将自身的值赋值给新变量后，自身再加1

        没有变量赋值就是单纯的将自身加1
    
    */
    int j = 0;
    j++;
    std::cout << "j 单独一行 = " << j << std::endl;
    int z = 0;
    std::cout << "z = " << z << std::endl;




    

}
//指针和数组
void ptr_str()
{

    int sr[5] = {1,5,9,2,6};
    int *p = sr;
    int *ptr = &sr[0];

    std::cout << sizeof(sr) << std::endl;

    std::cout << sizeof(&sr[0]) << std::endl;//    这是指针的字节大小  对于一个操作系统 是固定的  
    std::cout << sizeof(sr[0]) << std::endl;//这是一个元素的字节大小


    int number = sizeof(sr)/sizeof(sr[0]);
    int num = sizeof(sr)/sizeof(int);
    std::cout << number << std::endl;
    

    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(*p) << std::endl;

    //打印第三个数
    int *pfy = sr;
    /*
        demo.cpp:82:7: error: lvalue required as increment operand
    */
    //sr++;//这是错的    变量名是不可以修改的  你可以写表达式  但是 不难修改  sr = sr + 1;这是错的呀  
    std::cout << "sr++ = " << (sr+1) << std::endl;//这个应该是对的   
    std::cout << "sr++ = " << (sr+2) << std::endl;//这个应该是对的   
    std::cout << "sr++ = " << (sr+3) << std::endl;//这个应该是对的   

    std::cout << "sr[3] = " << sr[3] << " " << "*(pfy+3) = " <<  *(pfy+3) << " " <<"*(sr+3)" << *(sr+3) << std::endl;
    for(int i = 0;i < 5;i++){
        std::cout << " " << *(pfy+i) << " " << *(sr+i) << " " << pfy[i] << std::endl;
    }


}
void test01()
{
    //64位   指针字节  8位
    int *p; 
    int a = 10;
    p = &a;
    double c = 20.0,*ptr,*psr;
    ptr = &c;
    psr = ptr;
    std::cout << &p  << " " <<  *p << " " << sizeof(p)  << std::endl;
    std::cout << &ptr << *ptr << " " << &(*ptr) << " " << sizeof(ptr)  << std::endl;
    std::cout << &psr << " " << sizeof(psr)  << std::endl;


    std::cout << *ptr << " " << sizeof(psr)  << std::endl;


    std::cout << c << " " << *ptr << " " << *psr << " "  << &c << " " << &(*ptr) << " " << ptr <<  " " << &(*psr) << " " << psr << std::endl;
    //指针做运算
    int str[5] = {1,2,3,4,5};
    // std::cout << str[5] << std::endl;
    int *p1 = &str[0];
    int *p3 = str;//等价于这个  
    int *p2 = &str[3];
    std::cout << "p2 - p1 = " << p2-p1 << std::endl;
    /*
        指针加减 是移动一个数  而不是一个字节  一个数 是什么类型  就移动多少个字节*n  对于内存来说的 
    */
    int *p4 = str;
    std::cout << *p4 << " " << p4 << " " << &p4 << std::endl;
    p4++;
    std::cout << *p4 << " " << p4 << " " << &p4 << std::endl;






    std::cout << p << std::endl;
    std::cout << &a << std::endl;

    forexample();
    // test_bf();
}
/*
    将整形数组中的n个数按照反序存放
*/
void fanxun_func()
{
    int *ptr,sr[5] = {1,2,3,4,5};
    int num = sizeof(sr)/sizeof(int);
    for(auto i:sr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    ptr = sr;
    int i = 0,j = num;
    if(i <num){
        j--;
        ptr[j] = sr[i];
        i++;
    }
    for(auto i:sr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    // for(int i = 0; i < 5;i++)
    // {

    //     for(j = 5;j > 0;j--){
    //         ptr[j] = 
    //     }

    // }
    

    for(int i = 0;i < num;i++)
    {
        std::cout << *ptr++  << " ";

    }
    std::cout << std::endl;

    // while (num--)
    // {

    //     /* code */
    // }
    
}
void _test_func()
{
    // //反序函数 
    // int asr[] = {1,2,3,4,5};
    // //简单一点 复制一份  然后再重新给
    // int nm = sizeof(asr)/sizeof(int);
    // int fan[nm];
    // int *pasr = &asr;
    // int *pfan = &fan;
    // int i = 0;
    // if(nm > 0){
    //     nm--;
    //     fan[i] = asr[nm];
    //     i++;

    // }

    // // asr = fan;
    // pasr =pfan;
    // for(auto i : asr){
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;


    /*
    
        将整形数组中的n个数按照反序存放
        思路:首尾 都用指针  然后  1  2   3   4   5   6  7   首尾换  减减  尾减一  首加一 最后
    */
    int asr[5] = {1,2,3,4,5};
    int *ptr_bf = &asr[0];
    int *ptr_af = &asr[4];
    int temp = 0;
    while(ptr_bf < ptr_af)
    {
        temp = *ptr_af;
        *ptr_af = *ptr_bf;
        *ptr_bf = temp;
        ptr_af--;
        ptr_bf++;
    }
    for(auto i : asr){
        std::cout << i << " ";
    }
    std::cout << std::endl;




}
//多维数组和指针  一级指针访问二维数组
void double_arr_ptr()
{
    int ar[3][2] = {{1,2},{3,4},{5,6}};
    int num = sizeof(ar)/sizeof(int);
    int *ptr;
    // ptr = ar[0];
    ptr = &ar[0][0];
    for(int i = 0;i < num;i++){
        std::cout << *ptr++ << " ";
    }
    std::cout << std::endl;


}
/*
    通过行指针  把所有元素打印出来
*/
void func(int (*p)[2])
{
    int number = sizeof(p)/sizeof(int);
    printf("%d\n",number);
    int hang = (int)number/2;
    for(int i = 0;i < hang;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            printf(" %d ",p[i][j]);
        }
    }

}
void double_arr()
{
    //二维数组名代表数组的起始地址  数组名加1 是移动一行元素   因此 二维数组名常被称为行地址  
    int ar[3][2] = {{1,2},{3,4},{5,6}};
    int *p,i,n;
    n = sizeof(ar)/sizeof(int);
    printf("%p %p\n",ar,ar+1);//行指针  +1 是一行
    printf("%p %p\n",ar[0],ar[0]+1);//降级  以及指针  列指针
    printf("%d %d %d\n",ar[0][1],*(ar[0]+1),*(*(ar+0)+1));

    //改变指针性质   一级指针  降级   
    printf("%p %p\n",ar,ar+1);//行指针
    printf("%p %p\n",*ar,*ar+1);//列指针     *(ar+0) = ar[0]一维数组名  地址 


    /*
        0x7fff4074e080 0x7fff4074e088   8 
        0x7fff4074e080 0x7fff4074e084   4
    
    */
   int a[3][2] = {{1,2},{3,4},{5,6}};
//    int *p;
   //p = a;//会报错指针类型不兼容   行指针  声明和使用
   int (*ptr)[2];
   ptr = a;
   printf("%d",a[1][1]);
   printf("%d",ptr[1][1]);
   printf("%d %d",ptr[1][1],a[1][1]);
   printf("%d %d %d %d",ptr[1][1],a[1][1],*(*(a + 1)+1),*(*(ptr+1)+1));

    printf("  ====================== \n");
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            printf(" %d ",ptr[i][j]);
        }
        std::cout << std::endl;
    }
//    func(ptr);


}
/*
    字符指针的学习

*/
void char_ptr()
{
    /*
    p = str1;
    p = str2;
    0x7ffd2dc9a260 0x7ffd2dc9a260
    0x7ffd2dc9a26c 0x7ffd2dc9a26c
        分配的地址空间是不一样的
        但是如果是常量  static  内存地址是一样的  无法改变内容  
    
    */

    char ch = 'A';
    char *ptr;
    ptr = &ch;
    printf("%c %c \n",ch,*ptr);

    char str1[] = "hello world";
    char str2[] = "Hello world";
    char *p;
    p = str1;
    //str1[0] *(str+1)  *p p[0]
    if(isalpha(*p))
    {
        if(isupper(*p))
        {
            *p = tolower(*p);
        }
        else{

            *p = toupper(*p);
        }
    }
    /*
        //如果是用 %s 的话,符号这个["",]后面要写地址=>一串字符串=>一串就是地址
             > //即,单个就要放值,不少于一个(即一串)要放值
    
    */ 
    printf("%s %s\n",p,str1);
    printf("%p %p\n",p,str1);
    p = str2;
    if(isalpha(*p))
    {
        if(islower(*p))
        {
            *p = toupper(*p);
        }
        else{

            *p = tolower(*p);
        }
    }
    printf("%s %s\n",p,str2);
    printf("%p %p\n",p,str2);
    /*
        char *ytr = "hello world";
        *ytr = 'A';
        printf("%s/n",ytr);
            demo.cpp:375:17: warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]
            char *ytr = "hello world";
    字符串常量不能改变  地址一开始初始化就分配了  无法改变           ^~~~~~~~~~~~~
        
    */
//    char *ytr = "hello world";//字符串常量  放在了一个固定的内存区域
//     *ytr = 'A';              //不可以修改
//     printf("%s/n",ytr);
    //       test    
    /*
        printf("==============\n");
        char *yt = "hello world";
        char *yt2 = "hello world";
        printf("yt=%p %p %s \n",&yt,yt,yt);
        printf("yt=%p %p %s \n",&yt2,yt2,yt2);

        在c语言中可以测试
    */ 
   



    

}
int main(int argc, char const *argv[])
{
    
    // ptr_str();
    // fanxun_func();
    // _test_func();
    // double_arr_ptr();
    // double_arr();
    char_ptr();

    return 0;
}
