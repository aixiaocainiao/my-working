#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef int data_t;
#define N 64
typedef struct queue
{
    /* data */
    data_t data[N];
    int front,rear;
}queuenode,*listqueue;
listqueue queue_create();
//清空队列
int queue_clear(listqueue qq);
//判断队列是否为空
int queue_empty(listqueue qq);
//判断队列是否满
int queue_full(listqueue qq);
//入队
int queue_push(listqueue qq,int value);
//出队
data_t queue_pop(listqueue qq);
listqueue queue_free(listqueue qq);

#endif

