#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//单链表
typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *next;
}listnode,*linklist;
linklist list_create()//创建一个头节点  也就是链表 的开始 头节点为数据-1 不作为数据本身使用
{
    //1、申请内存
    linklist p = (linklist)malloc(sizeof(listnode));
    if(p == NULL){
        printf("内存分配失败\n");
        return p;
    }
    // memset(p,0,sizeof(listnode));
    //2、给初值
    p->next = NULL;
    p->data = -1;
    //3、返回
    return p;
    

}
/*
    
*/
int list_tail_insert(linklist H,data_t value)//Head头结点  尾部插入
{
    if(H == NULL){
        printf("链表无意义H is NUll\n");
        return -1;
    }
    //1、创建新节点  malloc 赋值  链接、
    linklist p;
    linklist q;
    if((p = (linklist)malloc(sizeof(listnode))) == NULL){
        printf("malloc failed\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    //2、找尾节点(特点 尾节点自身为NULL) 如果是两个节点  就直接链接就好 
    q = H;
    while (q->next != NULL)
    {
        q = q->next;
    }
    //3、尾部插入 链接在一起
    q->next = p;


}
linklist list_get(linklist H,int pos);
int list_insert(linklist H,data_t value,int pos)
{
#if 0
    //插入 三部走

    //1、创建新节点
    linklist q;//分配内存呀
    linklist p;
    if((q = (linklist)malloc(sizeof(listnode))) == NULL){
        printf("malloc failed\n");
        return -1;
    }
    q->data = value;
    q->next = NULL;
    //2、找到插入位置的前一个节点
    if(pos == -1){
        p = H;
    }

    if(pos > -1){
        p = list_get(H,pos-1);
    }
    //3、更正指针指向
    q->next = list_get(H,pos);
    p->next = q;
#endif
    //老师写的比较规范
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }

    linklist p;
    linklist q;
    //1、new node p
    if((p=(linklist)malloc(sizeof(listnode))) == NULL){
        printf("malloc failed\n");
        return -1;
    }
    p->data = value;
    p->next = NULL;
    //2、locate node (pos-1)
    q = list_get(H,pos-1);
    if(q == NULL){

        printf("获取失败\n");
        return -1;
    }

    //3、insert
    p->next = q->next;
    q->next = p;


    return 0;

}
/*
    规范:

*/
linklist list_get(linklist H,int pos){

    if(H == NULL){
        printf("非法传参\n");
        return H;
    }
    if(pos == -1){
        return H;
    }
    if(pos < -1){
        printf("pos is invalid\n");
        return NULL;
    }
    int i = -1;
    linklist p = H;
    while (i < pos)
    {
        /* code */
        p = p->next;
        //判断
        if(p == NULL){
            printf("位置无效\n");
            //会出现段错误  主函数需要判断 如果不是NULL 可以打印输出
            return NULL;
        }
        i++;    
    }
    return p;
    
    
}
void list_show(linklist H)
{
    if(H == NULL){
        printf("非法传参\n");
        return;
    }
    linklist p = H;//p->data应该是-1  打印的数据应该是p->next->data
    while(p->next != NULL){
        #if 0
        printf(" %d ",p->data);   自己写错了
        #endif
        printf("%d ",p->next->data);

        p = p->next;
    }  
    printf("\n");
}
int list_delete(linklist H,int pos){
    if(H == NULL)
    {
        printf("H is NULL\n");
        return -1;
    }
    //2、locate error定位错误
    linklist p = list_get(H,pos-1);
    if(p == NULL){
        return -1;
    }
    if(p->next == NULL){
        //删除的位置是无效的 p->next = list_get(H,pos) 即为删除的的位置 超过来了链表的范围
        printf("delete pos is invaild\n");
        return -1;
    }
    //3、update list
    linklist q = p->next;//存储临时变量  因为malloc分配的内存需要释放掉
    p->next = q->next;
    //4、free  防止野指针
    printf("free's data is %d",q->data);
    free(q);    
    q = NULL;
    return 0;//成功0 失败-1
}
void test()
{
    //链表格式L = {1,3,5,-1}
    linklist H = list_create();
    if(H == NULL){
        printf("H is NULL");
        return;
    }
    // while (H == NULL)
    // {
    //     H = list_create();
    //     if(H != NULL)
    //         break;
    // }
    int value;
    printf("input: ");
    while (1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        list_tail_insert(H,value);
        printf("input: ");
        
    }
    list_show(H);
    linklist p = list_get(H,-1);
    if(p != NULL){//不然会出现段错误
        printf("value=%d\n",p->data);
    }

}
linklist list_free(linklist H)
{
#if 0
    /*内存释放  */    自己逻辑有问题
    if(H == NULL){
        return true;
    }
    linklist p = H;
    linklist q;//用来释放的临时变量 

    while (1)
    {
        int i = 0;
        while (p != NULL)
        {
            q = p;
            p = p->next;
            i++;
        }
        /*
            这时  p为null  只能释放最后一个内存
        */
        // if(p->next == NULL){
        //     break;
        // }
        
        
        free(p);
        p = q;
        if(i == 0)
            break;
    }
    
    return true;
#else 
    if(H == NULL){
        return NULL;
    }
    linklist p = H;
    printf("free: ");
    while (H != NULL)
    {
        p = H;
        H = H->next;
        printf("%d ",p->data);
        free(p);

    }
    printf("\n");
    return NULL;

    //注意
    // H = NULL;没有用 因为是形参  H在主函数中  可以二级指针传过来一级指针的地址  或者修改返回指针
#endif
 
}
//链表翻转的程序
int list_reverse(linklist H)
{
    linklist p,q;
    if(H == NULL){
        printf("H is NULL\n");
        return -1;
    }
    if(H->next == NULL || H->next->next == NULL){
        printf("没有翻转的必要性\n");
        return -1;
    }

    p = H->next->next;
    H->next->next = NULL;

    while (p != NULL)
    {
        /* code */
        q = p;
        p = p->next;
        q->next = H->next;
        H->next = q;
    }
    

    // p = H->next;
    // q = H->next->next;
    // p->next = NULL;
    // while (q->next != NULL)
    // {
    //     /* code */
    //     q->next = H->next;
    //     H->next = q;
    //     q = q->next;
    // }
    return 0;
}
/*
    链表求相邻两节点的相加最大值的前一个节点的指针
    
        分析: 三种情况
        1、如果只有头结点 应退出程序 返回NULL
        2、如果有两个数据 直接返回 第一个地址即可  不用往后比较
        3、最常用的就是有多个  两个指针 p q 一个在前 一个在后 相差一个地址位置
        
    
*/
//自己写的太稚嫩了
linklist obj_max(linklist H)
{
    if(H == NULL){
        printf("H is NULL\n");
        return NULL;
    }
    int i = 0;
    linklist p = H;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    if(i == 0){

        printf("H is Null\n");
        return NULL;
    }
    if(i == 1){
        printf("只有一个头节点");
        return NULL;
    }
    
    printf("i = %d\n",i);
    if(i == 2){
        printf("只有一个头结点和一个数据");
        return NULL;
    }
    if(i == 3){
        printf("一共两个数据位加一个头\n");
        //直接返回就行
        return H->next;
    }
    //重新赋值
    p = H->next;
    linklist q = p->next;
    printf("q: = %d\n",q->data);
    linklist ret;
    int temp = 0,data = 0;
    if(i > 3){
        while (q != NULL)
        {
            data = p->data + q->data;
            if(data > temp){
                temp = data;
                ret = p;
            }

            p = p->next;
            q = q->next;
        }
        printf("ret: = %d\n",ret->data);
        return ret;
        

    }


    // if(i > 3){
    //     while (q->next != NULL)
    //     {
            
    //         data = q->data + p->data;
    //         if(data > temp){
    //             temp = data;
    //             ret = p;
    //         }
    //         q = q->next;
    //         p = q->next;

            
    //     }
    //     printf("ret: = %d\n",ret->data);

    //     return ret;

    // }



}
linklist list_agjmax(linklist H)
{
    linklist p,q,r;
    int sum;
    if(H == NULL){
        printf("H is NULL\n");
        return NULL;
    }
    if(H->next == NULL || H->next->next == NULL || H->next->next->next == NULL){
        return H;
    }
    p = H->next;
    q = H->next->next;
    r = p;
    sum = p->data + q->data;
    while (q->next != NULL)
    {
        /* code */
        p = p->next;
        q = q->next;
        if(sum < (p->data + q->data)){
            sum = p->data + q->data;
            r = p;
        }
    }
    return r;

}
/*
    h1 拼接后的链表  
*/
linklist list_mege(linklist H1,linklist H2)
{
    //主函数可以判断是否为空  这里只进行数据整理
#if 0
    linklist p,q,r,tem;
    p = H1->next;
    H1->next = NULL;
    tem = H1;
    q = H2->next;
    H2->next = NULL;
    while (p != NULL && q != NULL)
    {
        if(p->data >= q->data)
        {
            r = q;
            q = q->next;
            r->next = NULL;
            tem->next = r;
            tem = tem->next;

        }
        else{

            r = p;
            p = p->next;
            r->next = NULL;
            tem->next = r;
            tem= tem->next;
        } 
    }
    if(p == NULL){
        tem->next = q;

    }
    else{
        tem->next = p;
    }
    return H1;
    
#endif
}
int list_empty(linklist H)
{
    if(H->next != NULL || H != NULL){
        return 0;
    }
}
int test_merge()
{
    int ah[] = {2,4,6,7,8,9};
    int sh[] = {1,4,5,7};
    linklist H1 = list_create();
    linklist H2 = list_create();
    if(H1 == NULL){
        printf("H is NULL");
        return -1;
    }
    if(H2 == NULL){
        printf("H is NULL");
        return -1;
    }
    for(int i = 0;i < sizeof(ah)/sizeof(int);i++)
    {
        list_tail_insert(H1,ah[i]);
    }
    for(int j = 0;j < sizeof(sh)/sizeof(int);j++)
    {
        list_tail_insert(H2,sh[j]);
    }

    list_show(H1);
    list_show(H2);
    linklist H ;
    if(!list_empty(H1) & !list_empty(H2)){
        H = list_mege(H1,H2);
    }
    list_show(H);




}
/*不涉及到指针的释放和malloc动态分配*/
linklist list_merge(linklist H1,linklist H2)
{
    linklist p,q,r;
    if(H1 == NULL || H2 == NULL){
        printf("H1 or H2 is NULL\n");
        return NULL;
    }
    //应该有好多情况呢  确保进来的是两个好的链表
    p = H1->next;
    H1->next = NULL;
    r = H1;//首地址是H  所以H1 是H1和H2合并之后的链表  
    q = H2->next;
    H2->next = NULL;
    while (p != NULL && q != NULL)
    {
        /* code */
        if(p->data <= q->data)
        {
            r->next = p;
            r = r->next;
            r->next = NULL;
            p = p->next;

        }else{
            r->next = q;
            r = r->next;
            r->next = NULL;
            q = q->next;

        }

    }
    //如果一个先结束 另一个 直接插在后面就行
    if(p == NULL){
        r->next = q;

    }else{
        r->next = p;
    }
    
    // int tem_q,tem_p;
#if 0
    if(p->data > q->data)
    {
        // list_insert(H,q->data,0);
        H->next->next = NULL;
        q = q->next;
    }
    else{
        H->next->next = NULL;
        q = q->next;
    }

    while (p != NULL)
    {
        p = p->next;

        tem_p = p->data;
        while (q != NULL)
        {
            tem_q = q->data;
            if(tem_p > tem_q){

                p = p->next;
            }
            temp = (tem_p > tem_q ? p : q);
            
        }
        
    }
    
    
    // while (q != NULL)
    // {


    // }
    
#endif
}

/*
    实现单链表的翻转 
        思路: H 2 4 6  8 
            部分1 ：H 2      部分2：  4 6 8  以此取出  然后插入到部分1

*/
int my_test()//int  成功0 失败-1
{
    linklist H = list_create();
    if(H == NULL){
        printf("H is NULL");
        return -1;
    }
    int value;
    printf("please input: ");
    while (1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;            
        
        list_tail_insert(H,value);
        printf("please input: ");

    }
    // list_show(H);
    //单链表开始翻转
    linklist zz = H;
    int j = 0;
    while (zz != NULL)
    {
        /* code */
        j++;
        zz = zz->next;
    }
    if(j == 0 || j == 1){
        printf("没必要翻转\n");
        return -1;
        // list_show(H);
    }
    
    linklist p;
    linklist q;
    q = list_get(H,1);//这是4 6  8 的起始地址
    printf("q:value=%d\n",q->data);
    p = list_get(H,0);
    printf("p:value=%d\n",p->data);

    p->next = NULL;

    //依次取出部分2的节点
    linklist fr;
    linklist temp = (linklist)malloc(sizeof(listnode));
    if(temp == NULL){
        printf("malloc failed \n");
        return -1;
    }
    int i = 1;
    
    while (q != NULL)
    {
        /* code */
        temp->data = q->data;
        temp->next = NULL;
        list_insert(H,temp->data,0);
        fr = q;
        q = q->next;
        free(fr);
        // if(q == NULL){

        // }
    }
    list_show(H);

    

    
    


    // while(q != NULL){
    //     q = q->next;
    //     temp->data = q->data;
    //     temp->next = NULL;
    //     list_insert(H,temp->data,i);
    //     // free(temp);
    //     i++;

    // }
    // list_insert(H,q->data,i);
    // list_show(H);

    // printf("value = %d\n",q->data);

    return 0;
    

}
int test05()
{
    //链表格式L = {1,3,5,-1}
    linklist H = list_create();
    if(H == NULL){
        printf("H is NULL");
        return -1;
    }
    // while (H == NULL)
    // {
    //     H = list_create();
    //     if(H != NULL)
    //         break;
    // }
    int value;
    printf("input: ");
    while (1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        list_tail_insert(H,value);
        printf("input: ");
        
    }
    list_show(H);

    linklist ret = obj_max(H);
    printf("ret:Value = %d\n",ret->data);

    // H = reseze(H);
    list_show(H);
    // printf("ret:Value = %d\n",ret->data);

    // H = list_free(H);


    return 0;

}
int main_fnc()
{
    //链表格式L = {1,3,5,-1}
    linklist H = list_create();
    if(H == NULL){
        printf("H is NULL");
        return -1;
    }
    // while (H == NULL)
    // {
    //     H = list_create();
    //     if(H != NULL)
    //         break;
    // }
    int value;
    printf("input: ");
    while (1)
    {
        scanf("%d",&value);
        if(value == -1)
            break;
        list_tail_insert(H,value);
        printf("input: ");
        
    }
    list_show(H);
    printf("%p\n",H);
    list_insert(H,100,0);
    list_insert(H,10,0);

    list_show(H);
    H = list_free(H);
    printf("%p\n",H);
    list_delete(H,0);
    list_show(H);

    // H = list_free(H);


    return 0;

    
}
int main(int argc, char const *argv[])
{
    // my_test();
    // test05();
    test_merge();
    return 0;
}
