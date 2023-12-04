/*
    链式队列：  这不是的  这就是一个单链表    
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *next;
}listnode,*linklist;
//头结点的创建
linklist queue_create()
{
    linklist H = (linklist)malloc(sizeof(listnode));
    if(H == NULL){
        printf("malloc failed\n");
        return NULL;

    }
    H->data = -1;
    H->next = NULL;
    return H;
}
int queue_push(linklist H,int value)
{
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    linklist q = (linklist)malloc(sizeof(listnode));
    if(q == NULL){
        printf("malloc failed\n");
        return -1;

    }
    q->data = value;
    q->next = NULL;
    linklist p = H;
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
    }
    p->next = q;
    
    // if(H->next != NULL){
    //     q->next = H->next;
    //     H->next = q;
    // }else{
    //     H->next = q;

    // }
    return 0;


}
data_t queue_pop(linklist H)
{
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    //从前往后输出   弹出 应该需要销毁
    if(H->next == NULL){
        printf("只有头节点\n");
        return -1;
    }
    linklist p = H->next;
    int temp;
    temp = p->data;
    H->next = p->next;        
    free(p);
    return temp;
    
}
int queue_empty(linklist H)
{
    if(H->next == NULL)
        return 1;
    else
        return 0;
}
int main(int argc, char const *argv[])
{
    linklist H = queue_create();
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    int ah[] = {1,2,3,4,5,6};
    int count = sizeof(ah)/sizeof(int);
    for (int i = 0; i < count; i++)
    {
        /* code */
        queue_push(H,ah[i]);
    }
    while (!queue_empty(H))
    {
        /* code */
        printf("pop:value=%d \n",queue_pop(H));
    }
    
    return 0;
}
