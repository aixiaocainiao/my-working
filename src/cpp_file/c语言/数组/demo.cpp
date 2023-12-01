#include <iostream>
using namespace std;
/*
    数组的学习   二维数组 
*/
//     ---------------杨辉三角 打印出来
void  yanghuisanjiao()
{
    int sr = {0};//初始化都为0
    int a[10][10] = {{0}};
    for(int i = 0;i < 10;i++){
        a[i][0] = 1;
        for(int j = 1;j <= i;j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
        // std::cout << std::endl;
    }

    for(int i = 0;i < 10;i++){
        for(int j = 0;j <= i;j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

/*

    找出三行四列的最大值 以及下标
*/
}
void func_max()
{
    int a[3][4] = {{1,2,3,4},{5,6,4,7},{7,8,9,5}};
    // int temp = 0;//应该初始化为元素的第一个元素  因为如果都是负数的话 第一个就失败了
    int temp = a[0][0];
    int max_i = 0,max_j = 0;
    for (size_t i = 0; i < 3; i++)
    {
        /* code */
        for (size_t j = 0; j < 4; j++)
        {
            /* code */
            if(a[i][j] > temp)
            {
                temp = a[i][j]; 
                max_i = i;
                max_j = j;
            }
            
            
        }
    }
    std::cout << "i = " << max_i + 1 << " " << "j = " << max_j + 1 << std::endl;

    // std::cout << "i " << i << " " << "j = " << j << std::endl;

    // for (size_t i = 0; i < 3; i++)
    // {
    //     for (size_t j = 0; j < 4; j++)
    //     {
    //         /* code */
    //         if(a[i][j] ==  temp)
    //         {
    //             std::cout << "i = " << i+1 << " " << "j = " << j+1 << std::endl;
    //         }
            
            
    //     }
    // }
    

}
void double_arr()
{
    /*
    
        1、列元素不够的补充0
        2、行数可以省略
        3、大括号省略  系统会根据行和类数  进行行列判断
        4、不能省略列  行数可以省略
    */
    int a[2][3] = {{1,2,3},{4,5,6}};
    int c[2][3] = {{1,2},{6}};

    int d[2][3] = {{1,2,6}};//省略括号


    int b[][3] = {{1,2,3},{4,5,6}};

    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 3;j++)
        {
            std::cout << &a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << "地址 " << a << "内存空间 " << sizeof(a) << std::endl;
    /*
        // a[0]++;
        // a[1]++;
        // a++;
        数组名   ++ 常量  是不能变的   
    */

    cout << "地址 " << a[0] << "内存空间 " << sizeof(a[0]) << std::endl;
    cout << "地址 " << a[1] << "内存空间 " << sizeof(a)[1] << std::endl;


}
int main(int argc, char const *argv[])
{
    // double_arr();
    // yanghuisanjiao();
    func_max();
    return 0;
}
