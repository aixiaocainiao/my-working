#include <iostream>
#include <stdlib.h>
#include <string.h>
/*
    顺序表的实现 我感觉和vector 这些内部是一样的   

*/
// #include 
#if 0
#define N 100
typedef int data_int;
struct sqlist_t
{
    data_int data[N];
    int last;

};
typedef struct sqlist_t sqlist;//sqlist L  等价于struct sqlist_t L
typedef struct sqlist_t *sqlink;//struct sqlist_t* L;等价于 sqlink L;
#endif

// #else 1
//        ------------自己規定列表最後一個元素爲-1 標記是空表----------------
//写一个宏定义  计算last具体指向的位置  因为插入的也是结构体
#define SIZE_MYBOOK (sizeof(Mybook))
#ifndef _COUNTLIST
#define _COUNTIST(list) (int)((list->last + 1)/sizeof(list->Library[0]))
#define NUMBER 100
typedef struct Mybook
{
    std::string name;
    int index;

}data_info,*data_info_ptr;
typedef struct sqlist_L
{
    data_info Library[NUMBER];
    int last;//有多少个元素  默认值 为-1  

}sqlist,*sqlink;
#endif

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
   L->last = -1;
   memset(L,0,sizeof(sqlist));

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
        return -1;
    }
    else
    {
        return (list->last + 1);
    }

}
int list_locate(sqlink list,int value)
{
    
}
bool list_insert(sqlink list,data_info value,int pos)
{
    // typedef (int)(list->last + 1)/sizeof(list->Library[0]) list_pos;
    int list_pos = _COUNTIST(list);
    //
    /*
        條件1  列表是不是滿了  我們無法再次插入
        條件2    插入位置是否符合要求
        條件3 移動  （從後往前）
        條件4 存新的數值

    */
    //sizeof(*list)  这两个一定相等的  乱写
    // if(list->last+1 >= sizeof(*list))
    if(list_pos == NUMBER)
    {
        std::cout << "该列表已满 无法继续插入数值" << std::endl;
        return false;
    }
    else{
        // 插入位置是有要求的
        if(pos <= list_pos && pos >= 0)
        {
            //需要判斷是最前面还是最后面
            // if(pos == 0)
            // {
            //     list->Library
            // }
            for(int i = list_pos;i >= pos;i--)
            {
                // list->Library[i].index = list->Library[i+1].index;
                // list->Library[i].name = list->Library[i+1].name;
                list->Library[list_pos+1].index = list->Library[list_pos].index;
                list->Library[list_pos+1].name = list->Library[list_pos].name;


            }
            //更新
            list->Library[pos].index = value.index;
            list->Library[pos].name = value.name;
            list->last+SIZE_MYBOOK;   

        }
        else{
            std::cout << "数据插入位置无效" << std::endl;
            return false ;
        }
    }
    
}
bool list_show(sqlink list)
{
    if(list == nullptr){
        return false;
    }
    for(int i = 0;i < _COUNTIST(list) - 1;i++){
        std::cout <<"索引爲: " <<  list->Library->index << " 名字爲: " << list->Library->name << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char const *argv[])
{
    sqlink L;
    L = list_create();
    if(L == nullptr)
    {
        return -1;
    }
    data_info data;
    data.index = 0;
    data.name = "xx";
    list_insert(L,data,0);
    list_show(L);

    return 0;
}
