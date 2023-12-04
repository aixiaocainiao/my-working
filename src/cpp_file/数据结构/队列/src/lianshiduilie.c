/*
    链式队列
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int data_t;
typedef struct node_t
{
    data_t data;
    struct node_t *next;
}listnode,*linklist;
typedef struct 
{
    linklist front,rear;  //队列的头和尾  
}linkqueue;
linkqueue* queue_create()
{

    linkqueue * qq = (linkqueue*)malloc(sizeof(linkqueue));//只是给这两个指针分配了空间 里面内部还未分配
    // printf("size:%ld\n",sizeof(linkqueue));
    if(qq == NULL){
        printf("qq:malloc failed\n");
        return NULL;
    }
#if 0
    需要指向同一块内存区域

    qq->front = (linklist)malloc(sizeof(listnode));
    if(qq->front == NULL){
        printf("qq->front:malloc failed\n");
        return NULL;
    }
    qq->rear = (linklist)malloc(sizeof(listnode));
    if(qq->rear == NULL){
        printf("qq->rear:malloc failed\n");
        return NULL;
    }
    //创建单链表   头结点  好像不用穿甲
    linklist ll = (linklist)malloc(sizeof(listnode));
    if(ll == NULL){
        printf("ll:malloc failed\n");
        return NULL;
    }
    ll->data = -1;
    ll->next = NULL;

    //头尾指向单链表
    qq->front = ll;
    qq->rear = ll;
    return qq;
#else

    qq->front = qq->rear = (linklist)malloc(sizeof(listnode));
    if(qq->front == NULL){
        printf("malloc qq->front failed\n");
        return NULL;
    }
    qq->front->data = 0;
    qq->front->next = NULL;
    return qq;
#endif 
}
//清空队列 留个头结点
// linkqueue* queue_clear(linkqueue *qq)
int queue_clear(linkqueue *qq)

{
#if 0
    if(qq == NULL){
        printf("qq:is NULL\n");
        return NULL;
    }
    linklist ll;
    ll = qq->front;
    while (qq->front->next != NULL)
    {
        /* code */
        ll = qq->front;
        qq->front = ll->next;
        free(ll);
        ll = NULL;
    }
    qq->front->next = NULL;
    qq->front->data = 0;

    return qq;
#else 
    if(qq == NULL){
            printf("qq:is NULL\n");
            return -1;
        }
    linklist ll;
    ll = qq->front;
    while (qq->front->next)
    {
        /* code */
        ll = qq->front;
        qq->front = ll->next;
        printf("clear free:%d\n",ll->data);
        free(ll);
        ll = NULL;
    }
    return 0;

#endif
}

/*
    先释放内层 再释放外层  free(qq)仅仅释放了两个指针  16个字节  内层并未释放
*/
linkqueue* queue_free(linkqueue* qq)
{
    if(qq == NULL){
        printf("qq:is NULL\n");
        return NULL;
    }
    linklist ll;
    // int i = 0;
    printf("free:");
    while (qq->front != NULL)
    {
        ll = qq->front;
        qq->front = ll->next;
        // if(i > 0)
            printf("%d ",ll->data);
        // i++;
        free(ll);
        ll = NULL;
        
    }
    printf("\n");
    
    free(qq);
    qq = NULL;

    
    return NULL;
    
    
    
}
//入列
int enqueue(linkqueue* qq,data_t value)
{
    if(qq == NULL){
        printf("qq:is NULL\n");
        return -1;
    }
    linklist ll = (linklist)malloc(sizeof(listnode));
    if(ll == NULL){
        printf("ll:malloc failed\n");
        return -1;
    }
    ll->data = value;
    ll->next = NULL;
    // qq->front->next = ll;//下一次再入队列变成 qq->front->next->next = ll;不合适
    qq->rear->next =ll;//队列链接起来了
    qq->rear = ll;
    return 0;
}
//出队
data_t dequeue(linkqueue* qq)
{
    if(qq == NULL){
        printf("qq:is NULL\n");
        return -1;
    }
    //确保有数据 主函数判断
    // data_t temp;
    linklist ll = qq->front;
    // temp = ll->next->data;
    qq->front = ll->next;
    free(ll);
    ll = NULL;
    return (qq->front->data);

}
/*
    空为 1  不空为0
*/
int queue_empty(linkqueue* qq)
{
#if 0
    if(qq == NULL){
        printf("qq:is NULL\n");
        return -1;
    }
    if(qq->front->next == NULL)
        return 1;
    else
        return 0;
#else
    if(qq == NULL){
            printf("qq:is NULL\n");
            return -1;
        }
    return (qq->front == qq->rear ? 1:0);

#endif
}

int main(int argc, char const *argv[])
{
    linkqueue* qq = queue_create();
    enqueue(qq,10);
    enqueue(qq,20);
    enqueue(qq,30);
    // while (!queue_empty(qq))
    // {
    //     /* code */
    //     printf("value:%d \n",dequeue(qq));
    // }
    queue_clear(qq);
    qq = queue_free(qq);
    
    // while (!queue_empty(qq))
    // {
    //     /* code */
    //     printf("value:%d \n",dequeue(qq));
    // }
    enqueue(qq,10);
    // enqueue(qq,20);
    // enqueue(qq,30);
    // enqueue(qq,40);//qq如果没有返回NULL  J就会出现段错误
    // while (!queue_empty(qq))
    // {
    //     /* code */
    //     printf("value:%d \n",dequeue(qq));
    // }

    return 0;
}
