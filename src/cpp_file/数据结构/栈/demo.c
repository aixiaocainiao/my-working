/*
    栈  
        顺序栈的实现
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//自定义堆栈
/*
    顺序栈 它是顺序表的一部分 具有顺序表同样的存储结构 由数组定义 配合用数组下标表示的栈顶指针top(相对指针)完成各种操作
*/
typedef int data_t;/*定义栈中数据元素的数据类型*/
typedef struct 
{
    data_t *data;/*用指针指向栈的存储空间*/
    int maxlen;/*当前栈中最大元素个数 应该是数组的元素个数*/
    int top;/*知识栈顶位置(数组下标)的变量*/

}sqstack;/*顺序栈类型定义*/
//1、创建栈
sqstack* sqstack_create(int len)
{
    if(len < 0){
        printf("输入的数据长度小于0,不合法\n");
        return NULL;
    }
    sqstack *ss = (sqstack*)malloc(sizeof(sqstack));
    if(ss == NULL){
        printf("malloc sqstack failed\n");
        free(ss);//ss->data 分配空间为空  直接释放ss即可 不然两个都要释放
        return NULL;
    }
    ss->data = (data_t*)malloc(sizeof(data_t)*len);
    if(ss->data == NULL){
        printf("mallc ss->data failed\n");
        return NULL;
    }
    memset(ss->data,0,len*sizeof(data_t));
    ss->maxlen = len;
    ss->top = -1;
    return ss;
}
//6、释放栈
int stack_free(sqstack *ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    // if(ss->top == -1){
    //     printf("该栈是空栈不用释放\n");
    //     return true;
    // }
    // while (ss->top != -1)
    // {
    //     /* code */
    //     ss->data[ss->top] = 0;
    //     ss->top--;
    // }
    if(ss->data != NULL)
        free(ss->data);
    free(ss);
    /*
        malloc 配套使用 几个malloc  几个free
    */
    

}
//2、清空栈 不是释放内存
int stack_clear(sqstack* ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }else{
        memset(ss->data,0,sizeof(data_t)*(ss->maxlen));
        ss->maxlen = 0;
        ss->top = -1;

    }
    //所有数据弹出来吗   也可以直接掩盖过去
#if 0
    ss->top = -1;
#endif


}

//3、判断栈是否为空
int stack_empty(sqstack* ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    if (ss->top == -1)
    {
        /* code */
        // printf("栈为空\n");
        return 0;
    }
    else{
        // printf("栈不为空");
        return 1;
    }

}

//4、入栈
int stack_push(sqstack* ss,int value){
#if 0
    if((ss->top) + 2 >= ss->maxlen){
        printf("栈已满无法添加元素\n");
        return -1;
    }
    ss->data[(ss->top)+1] = value;
    ss->top++;
#endif
    /*
        这样想  maxlen = 0的时候 top = -1 
    */
   if(ss == NULL){
        printf("ss is NUll\n");
        return -1;
   }
   if(ss->top + 1 == ss->maxlen)
   {
        printf("栈已满无法添加元素\n");
        return -1;
   }
   ss->top++;
   ss->data[ss->top] = value;

   return 0;


}
//5、出栈
data_t stack_pop(sqstack *ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    if(ss->top == -1){
        printf("栈中无数据\n");
        return -1;
    }
    return ss->data[ss->top--];

}

//7、判断是不是满栈
int stack_full(sqstack *ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    if(ss->top+1 == ss->maxlen)
    {
        printf("该栈是满栈\n");
        return true;
    }
    else{
        printf("该栈不是满栈\n");
        return false;
    }
#if 0
    return (ss->top == ss->maxlen -1 ? 1: 0);
#endif
}
//8、返回栈顶
data_t stack_top(sqstack *ss)
{
    return ss->data[ss->top];
}
int main(int argc, char const *argv[])
{
    sqstack *ss;
    int temp;
    int ah[] = {0,1,2,3,4,5,6};
    ss = sqstack_create(10);
    for(int i = 0;i < sizeof(ah)/sizeof(int);i++)
    {
        stack_push(ss,ah[i]);

    }

    while (stack_empty(ss))
    {
        /* code */
        printf("pop: %d \n",stack_pop(ss));
    }
    
    // for(int i = 0;i < sizeof(ah)/sizeof(int);i++)
    // {
    //     temp = stack_pop(ss);
    //     printf("value = %d\n",temp);
    // }
    stack_free(ss);

    
    return 0;
}
