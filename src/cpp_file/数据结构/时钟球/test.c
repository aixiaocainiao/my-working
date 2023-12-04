/*
    三栈一队列
    问题描述如下:
        
*/
#include <stdio.h>
#include <string.h>
//创建队列
typedef int data_t;
#define N 27
typedef struct 
{
    data_t data[27];
    int front,rear;
}queuenode,*listqueue;
//创建队列
listqueue queue_create()
{
    listqueue qq = (listqueue)malloc(sizeof(queuenode));
    if(qq == NULL){
        printf("malloc failed\n");
        return NULL;
    }
    memset(qq->data,0,sizeof(qq->data));
    qq->front = qq->rear = 0;
    return qq;
}
//判断队列是否满
int queue_full(listqueue qq)
{
    if((qq->rear + 1) % N == qq->front){
        printf("该队列已满");
        return 1;
    }else{
        return 0;
    }
}
//入队
int queue_push(listqueue qq,int value)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    //是不是需要判断 是否已经满了 满队的的判断
    if((qq->rear + 1) % N == qq->front){
        printf("该队列已满");
        return -1;
    }

    //先不判断 假设可以插入数据
    qq->data[qq->rear] = value;
    qq->rear = (qq->rear + 1) % N;//限制在0-63使用
    return 0;
    
}
//出队
data_t queue_pop(listqueue qq)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return -1;
    }
    if(qq->front == qq->rear){
        printf("该队列为空 无法删除数据\n");
        return -1;
    }
    int temp;
    temp = qq->data[qq->front];
    qq->front = (qq->front + 1) % N;
    return temp;

}
//清空队列
int queue_clear(listqueue qq)
{
    if(qq->front == qq->rear){
        printf("该队列为空 无需清空\n");
        return 0;
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
    return (qq->front == qq->rear ? 1 : 0);
}
//释放对列
listqueue queue_free(listqueue qq)
{
    if(qq == NULL){
        printf("qq is NULL\n");
        return NULL;
    }
    free(qq);
    qq = NULL;
    return NULL;

}


int main(int argc, char const *argv[])
{
    
    return 0;
}
