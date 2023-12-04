/*
    栈:
        链式栈的实现
        插入操作和删除操作均在链表头部插入 链表尾部就是栈底 栈顶指针就是头指针
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int data_t;//定义栈中数据元素类型
typedef struct node_t
{
    /* data */
    data_t data;//数据域 //头结点可以用来存储数据个数 然后可以用这个进行判断  
    struct node_t* next;//链接指针域
}listnode,*linkstack;//链栈指针定义
linkstack stack_create()
{
    linkstack ss = (linkstack)malloc(sizeof(listnode));
    if(ss == NULL){
        printf("malloc failed \n");
        return NULL;
    }
    // ss->data = -1;
    ss->data = 0;

    ss->next = NULL;   
    return ss;
}
int stack_push(linkstack ss,data_t value)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    linkstack p = (linkstack)malloc(sizeof(listnode));
    p->data = value;
    p->next = NULL;
    if(ss->next != NULL)
    {
        p->next = ss->next;
        ss->next = p;
        // ss->data++;
    }else{
        ss->next = p;
        // ss->data++;
    }
    return 0;
    
}
data_t stack_pop(linkstack ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    if(ss->data == -1){
        printf("栈中无数据\n");
        return -1;
    }
#if 0
    自己写的 就不需要判断是否为空了 有个函数  没有函数用我这个就行
    linkstack q;
    int temp;
    if(ss->next != NULL){
        q = ss->next;
        ss->data--;
        temp = q->data;
        ss->next = q->next;
        free(q);
        return temp;


    }
#endif
    linkstack p;
    data_t temp;
    p = ss->next;
    ss->next = p->next;
    ss->data--;
    temp = p->data;

    free(p);
    p = NULL;
    return temp;
    // linkstack p = ss;
    // while (ss->next != NULL)
    // {
    //     /* code */
    //     p = ss;
    //     ss = ss->next;
    //     return p->next->data;  
    // }
    

}
/*
    空为1  不空为0
*/
int stack_empty(linkstack ss)
{
#if 0
    if(ss->data == -1)
        return 1;
    else
        return 0;
#else
    if(ss == NULL){
            printf("ss is NULL\n");
            return -1;
    }
    if(ss->next == NULL)
        return 1;
    else
        return 0;
#endif

}
data_t stack_top(linkstack ss)
{
    return ss->next->data;

}
linkstack stack_free(linkstack ss)
{
    if(ss == NULL){
        printf("ss is NULL\n");
        return NULL;
    }
    linkstack temp = ss;
    while (ss != NULL)
    {
        /* code */
        temp = ss;
        ss = ss->next;
        printf("free:%d \n",temp->data);
        free(temp);
    }
    return NULL;

}
int main(int argc, char const *argv[])
{
    linkstack ss = stack_create();
    int ah[] = {2,4,6,7,8,9};
    
    if(ss == NULL){
        printf("ss is NULL\n");
        return -1;
    }
    for(int i = 0;i < sizeof(ah)/sizeof(int);i++)
    {
        stack_push(ss,ah[i]);
    }
    // while (!stack_empty(ss))
    // {
    //     /* code */
    //     printf("pop:value=%d \n",stack_pop(ss));
    // }
    // printf("valu= %d\n",ss->data);

    stack_free(ss);
    return 0;
}
