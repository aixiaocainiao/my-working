#include <iostream>
using namespace std;
template<typename T>//或者template<class T>，T需要在以下指定具体的数据类型
void swap(T&a,T&b){//a和b的数据类型一致
	T temp=a;
	a=b;
	b=temp;
}
void test(){
	int a=10;
	int b=20;
	char c='1';
	swap(a,b);//自动类型推导
	swap(a,c);//错误,要求数据类型一致
	//或者 swap<int>(a,b);//显示指定类型
	cout<<"a="<<a<<" b="<<b<<endl;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
