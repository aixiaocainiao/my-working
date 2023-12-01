/*
    宏定义的使用方式
*/
#include <iostream>
using namespace std;
// 简单的宏定义使用 可以嵌套  作用   懂得一个替换的作用 和typedef不一样
#define PI 3.14
//2.带参数的宏定义  #define <宏名>(参数表) <宏体>
#define ADDONE(X) X+1
#if 0
—————— define中的三个特殊符号：##，#，#@ ——————

/*x连接y，例如：int n = Conn(123,456); 结果就是n=123456;char* str = Conn("asdf", "adf"); /*结果就是 str = "asdfadf";*/
#define Conn(x,y) x##y

/*
    给x加上单引号，结果返回是一个const char。例如：char a = ToChar(1);结果就是a='1';
    做个越界试验char a = ToChar(123);结果就错了;
    但是如果你的参数超过四个字符，编译器就给给你报错了！error C2015: too many characters in constant   ：P 
*/

#define ToChar(x) #@x


// x加双引号,例如：char* str = ToString(123132);就成了str="123132";
#define ToString(x) #x
#endif
int main(int argc, char const *argv[])
{
    float pi2 = PI*2;
    cout << "pi2 = " << pi2<< endl;
    auto pi = ADDONE(pi2);
    cout << "pi = " << pi << endl;
    return 0;
}
