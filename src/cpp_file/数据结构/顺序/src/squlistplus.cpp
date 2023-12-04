#include <iostream>
#include <stdlib.h>
#include <string.h>
/*
    顺序表的实现 我感觉和vector 这些内部是一样的   

*/
// #include 

#define N 100
typedef int data_int;
struct sqlist_t
{
    data_int data[N];
    int last;

};
typedef struct sqlist_t sqlist;//sqlist L  等价于struct sqlist_t L
typedef struct sqlist_t *sqlink;//struct sqlist_t* L;等价于 sqlink L;

sqlink list_create()
{
    //创建一个链表  首先 确定内存大小 和内存数据
    sqlink L = nullptr;
    /*
        #include <stdlib.h>
        void *malloc(size_t size);
        void* 万能指针
    
    */
   L= (sqlink)malloc(sizeof(sqlist));
   if(L == nullptr){
        std::cout << "動態內存分配失敗" << std::endl;
        return L;
   }

   //内容设置都为0
   /*   
        #include <string.h>
        void *memset(void *s, int c, size_t n);

   
   */
   //这个储存的是有多少个元素   没有元素就是 -1+1 = 0
   memset(L,0,sizeof(sqlist));//分配內存後  再給L->last給 值  不然直接分配的都是0
   L->last = -1;


   return L;
   /*
        1、malloc
        2、初始化
        3、返回值
   */




}
bool list_empty(sqlink list)
{
    
    if(list->last == -1)
    {
        //-1 代表是空表的標誌
        std::cout << "該列表是空表" << std::endl;
        return true;
    }
    else{
        std::cout << "該列表不是空表" << std::endl;
        return false;
    }


}
//列表清空 
/*
*   list_clear：檢查列表是否被清除了
*   para list:  列表
*   @ret 1 ---clear   0 --- not clear
*/
bool list_clear(sqlink list)
{
    if(list == nullptr)
    {
        return true;
        // break;
    }
    else{
        //列表清空
        memset(list,0,sizeof(*list));
        list = nullptr;
        list->last = -1;
        return true;
    }
    
}
int list_length(sqlink list)
{
    if(list == nullptr)
    {
        return false;
    }
    else
    {
        return (list->last + 1);
    }

}
//刪除一個位置上的元素 還是直接刪除一個值   
bool list_my_delete(sqlink list,int pos) 
{
    // int mytemp;
    if(list->last == -1)
    {
        std::cout << "列表中無元素" << std::endl;
        return false;
    }
    if(pos < 0 || pos > list->last)
    {
        std::cout << "無效位置" << std::endl;
        return false;
    }
    // for(int i = pos;i < list->last;i++)
    // {
    //     list->data[i] = list->data[i+1];
       
    // }
    for(int i = pos+1;i <= list->last;i++)
    {
        list->data[i-1] = list->data[i];
    }
    list->last--;
    return true;

}
bool list_insert(sqlink list,int value,int pos)
{

    if(list->last+1 == N){
        std::cout << "列表元素已經滿了 無法插入" << std::endl;
        return false;
    }
    
    if(pos < 0 || pos > (list->last+1))
    {
        std::cout << "插入位置無效" << std::endl;
        return false;
    }
    //插入  移動 從後往前
    for(int i = list->last;i >= pos;i-- ){

        list->data[i+1] = list->data[i];
    }
    list->data[pos] = value;
    // std::cout << "list->last " << list->last << std::endl;
    list->last++;
    // std::cout << "list->last " << list->last << std::endl;

    return true;
    
}
//查找相應的元素   然後返回相應的索引
int list_locate(sqlink list,int value)
{
    for (int i = 0; i <= list->last; i++)
    {
        /* code */
        if(value == list->data[i])
            return i;
    }
    return -1;
    
}
/*
    查找元素   
*/
//将list2中不属于list1中的元素加進來
bool list_merge(sqlink list1,sqlink list2)
{
/*
#if 0
    int temp = 0,index = -1;
    // auto list1_number = list1->last+1;
    // auto list2_number = list2->last+1;
    for(int i = 0;i <= list1->last;i++)
    {
        temp = list1->data[i];
        // index = list_locate(list1,temp);
        // if(index >= 0)
        // {
        //     list_my_delete(list,index);
        // }
        for(int j = 0;j <= list2->last;j++)
        {
            if(temp == list2->data[j]){
                list_my_delete(list2,j);
                list2->last --;
            }
            else{
                //越界判斷
                list_insert(list1,list2->data[j],list1->last+1);
            }
        }

    }
    
#endif*/
    for(int j = 0;j < list2->last+1;j++){
        
        if(list_locate(list1,list2->data[j]) == -1){

           if(!list_insert(list1,list2->data[j],list1->last+1)){
                std::cout << "插入失敗" << std::endl;
                return false;
                // break;
           }
        }
        
    }
    return 0;


    // int i = 0;
    // int ret;
    // while (i <= list2->last)
    // {
    //     std::cout << "22222" << "    " << list2->last << std::endl;

    //     /* code */
    //     ret = list_locate(list1,list2->data[i]);
    //     std::cout << ret << std::endl;

    //     if(ret == -1){
    //         // std::cout << "22222" << "    " << list2->last << std::endl;

    //         if(!list_insert(list1,list2->data[i],list1->last+1))
    //         {
    //             std::cout << "插入失敗" << std::endl;
    //             return false;
    //         }

    //     }
    //     i++;
    // }
    // return 0;
    

}
//合併重複額項 删除链表中重复的元素  没写出来  不看了   =========================================================
int list_purge(sqlink list)
{
    /*
        思路:依次比较左右两侧数据
        12   25  6  8   9   6   
        0    1   2  3   4   5  
    */
//    int i =0,temp;
//    while (i < list->last+1)
//    {

//         while(list->data[i+1] == list[i]);


//    }
    /*
    1、如果就一个元素 肯定不会重复
    
    */
    // if(list->last < 2){
    //     return list;

    // }
    // //                 思路：取出第一个数   然后用第二个数到最后遍历 与其作对比 
    // int i = 0;
    // while (i <= list->last)
    // {
    //     int j = i+1;
    //     while (j <= list->last)
    //     {
    //         if(list->data[i] == list->data[j]){
    //             list_my_delete(list,j);
    //             i++;
    //             break;
    //         }
    //         j++;
    //     }
    //     i++;
    // }

    int i = 1,j;
    if(list->last == 0){
        return 0;
    }
    while (i <= list->last)
    {

        j = i -1;
        while (j >= 0)
        {
            if(list->data[i] = list->data[j]){
                list_my_delete(list,i);
                break;

            }else{
 
                j--;
            }

            /* code */
        }
        if(j < 0){
            i++;
        }
        

        /* code */
    }
    
    // for(int i = 0;i <= list->last;i++)
    // {
    //     for(j = i+1;j <= list->last;j++)
    //     {
    //         if(list->data[i] == list->data[j]){

    //             list_my_delete(list,i);
    //         }
    //     }

    // }
   
    return 0;
}


bool list_show(sqlink list)
{
    if(list == nullptr){
        return false;
    }
    for(int i = 0;i < list->last + 1;i++){
        std::cout <<"value = " <<  list->data[i] << " ";
    }
    std::cout << std::endl;
}
bool list_delete(sqlink list)
{
    if(list == nullptr){
        return false;
    }
    free(list);
    list = nullptr;
    return true;
}
void test_insert()
{
    sqlink L;
    L = list_create();
    // std::cout << "---------------list->last " << L->last << std::endl;

    if(L == nullptr)
    {
        return;
    }
    
    list_insert(L,25,0);
    list_insert(L,35,0);
    list_insert(L,45,0);
    list_insert(L,55,0);

    list_show(L);
    list_insert(L,65,0);
    list_show(L);
    list_insert(L,75,list_length(L));
    // list_insert(L,55,-1000);
    

    list_show(L);

    list_delete(L);


}
void test_delete()
{
    sqlink L;
    L = list_create();
    // std::cout << "---------------list->last " << L->last << std::endl;

    if(L == nullptr)
    {
        return;
    }
    
    list_insert(L,25,0);
    list_insert(L,35,0);
    list_insert(L,45,0);
    list_insert(L,55,0);

    // list_show(L);
    // list_insert(L,65,0);
    list_show(L);
    list_my_delete(L,0);
    list_show(L);


}
void test_purge()
{
    sqlink L,L2;
    L = list_create();
    L2 = list_create();
    // std::cout << "---------------list->last " << L->last << std::endl;

    if(L == nullptr)
    {
        return;
    }
    if(L2 == nullptr)
    {
        return;
    }
    
    list_insert(L,25,0);
    list_insert(L,35,0);
    list_insert(L,35,0);
    list_insert(L,55,0);
    list_insert(L2,15,0);
    list_insert(L2,15,0);
    list_insert(L2,15,0);
    list_insert(L2,15,0);
    list_insert(L2,15,0);



    // list_show(L);
    // list_insert(L,65,0);
    list_show(L);
    list_show(L2);
    // list_merge(L,L2);
    list_purge(L);
    list_purge(L2);

    std::cout << " ---------------  " << std::endl;
    // list_my_delete(L,0);
    list_show(L);
    list_show(L2);

    


}
void test_merge()
{
    sqlink L,L2;
    L = list_create();
    L2 = list_create();
    // std::cout << "---------------list->last " << L->last << std::endl;

    if(L == nullptr)
    {
        return;
    }
    if(L2 == nullptr)
    {
        return;
    }
    
    list_insert(L,25,0);
    list_insert(L,35,0);
    list_insert(L,45,0);
    list_insert(L,55,0);
    list_insert(L2,15,0);
    list_insert(L2,55,0);


    // list_show(L);
    // list_insert(L,65,0);
    list_show(L);
    list_show(L2);
    list_merge(L,L2);
    std::cout << " ---------------  " << std::endl;
    // list_my_delete(L,0);
    list_show(L);
    list_show(L2);

    

}
int main(int argc, char const *argv[])
{
    
    // test_insert();
    // test_delete();
    // test_merge();
    test_purge();

    return 0;
}
