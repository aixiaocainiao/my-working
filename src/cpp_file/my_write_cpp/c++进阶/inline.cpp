/*
inline内联函数的学习
*/
#include <iostream>
using namespace std;
#define ADD(X,Y) ((X)+(Y))
/*
内联函数的语法:
    只需要在函数的最前面加一句 inline ，如下：
    以 inline 修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，
    没有函数压栈的开销，内联函数提升程序运行的效率。
特性:
    inline是一种以空间换时间的做法，省去调用函数、建立栈帧的额外开销；
但是如果代码很长（一般是10行左右，具体取决于编译器），或者有递归函数，就不适宜使用递归函数。

inline对于编译器而言只是一个建议，编译器归自动优化，如果定义的函数很长或者递归函数等等，编译器优化时会忽略掉内联。

inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到。
测试：
————————————————
版权声明：本文为CSDN博主「Massachusetts_11」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/yue152152/article/details/124761293
*/
inline int add(int a,int b)
{
    return a+b;
}
int main(int argc, char const *argv[])
{
    int ret = 0,a = 1,b = 2;
    ret = a+ b;
    ret = add(a,b);
    return 0;
}
