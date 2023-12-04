/*
    循环队列:涉及到了内存的循环使用   N 64  i % N 范围  0-N-1  例如 i / 6   (0,5)   
        循环使用的时候 空队和满队都会导致  rear = front   分了区分
            front 指向对头元素的位置
            rear 指向队尾元素下一个的位置
            在队列操作过程中，为了提高效率，已调整指针代替队列元素的移动，并将数组作为循环队列的操作空间
            为了区别空队和满队 蛮对元素个数比数组元素个数少1个
        顺序队列的学习:循环使用内存  判断怎样区分满 和空  怎样求余
        队列 是限制在两端进行插入和删除操作的线性表
        允许进行存入操作的一段称为队尾
        允许进行删除操作的一端称为队头         类比 排队做核酸  队尾插入人进行排队  对头删除人做核酸
        当线性表中没有元素时，称为空队
        特点  先进先出
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef int data_t;//定义队列中数据元素的数据类型
#define N 64//定义队列的容量
typedef struct
{
    /* data */
    data_t data[N];//用数组作为队列的存储空间
    int front,rear;//指示对头位置和队尾位置的指针

}queuenode,*listqueue;//顺序队列类型定义
//创建队列
listqueue queue_create()
{
    listqueue qq = (listqueue)malloc(sizeof(queuenode));
    if(qq == NULL){
        printf("qq is NULL\n");
        return NULL;
    }
    // memset(qq->data,0,N*sizeof(data_t));
    memset(qq->data,0,sizeof(qq->data));

    qq->front = 0;
    qq->rear = 0;

    return qq;
}
//清空队列
int queue_clear(listqueue qq)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    qq->front = qq->rear = 0;
    return 0;
}
//判断队列是否为空
int queue_empty(listqueue qq)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    return (qq->rear == qq->front ? 1 : 0);
}
//判断队列是否满
int queue_full(listqueue qq,int value)
{
#if 0
    if(qq->rear == N)
        return 1;
    else
        return 0;


    if((qq->rear + 1)%N == qq->front){

        printf("sequeue is full\n");
        return -1;

    }
    qq->data[qq->rear] = value;
    qq->rear = (qq->rear+1) % N;
    return 0;
#endif
    if(qq == NULL){
            printf("qq is NULL\n");
            return -1;
    }
    if((qq->rear + 1)%N == qq->front){

        return 1;
    }
    else
        return 0;
}
//入队
int queue_push(listqueue qq,int value)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    if((qq->rear + 1)%N == qq->front){

        printf("sequeue is full\n");
        return -1;

    }
    qq->data[qq->rear] = value;
    qq->rear = (qq->rear+1) % N;
    return 0;
//     qq->data[(qq->rear)%N] = value;
//     qq->rear++;
//     return 0;
// }
}
//出队
data_t queue_pop(listqueue qq)
{
    if(qq == NULL){
            printf("qq is NULL\n");
            return -1;
    }
    data_t temp;
    temp = qq->data[qq->front];
    qq->front = (qq->front + 1) % N;
    return temp;
}
listqueue queue_free(listqueue qq)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return NULL;
    }
    free(qq);
    qq = NULL;

}
int main(int argc, char const *argv[])
{
   listqueue qq = queue_create();
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    queue_push(qq,20);
    queue_push(qq,30);
    queue_push(qq,40);

    while (!queue_empty(qq))
    {
        /* code */
        printf("dequeue:%d\n",queue_pop(qq));
    }
    queue_free(qq);
    
    return 0;
}
