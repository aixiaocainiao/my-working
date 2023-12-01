/*
c++中argc,argv的用处
    在C++中，argc 和 argv 是主函数（main 函数）的参数，用于处理命令行参数。它们的作用如下：

argc（Argument Count）： 表示命令行参数的数量，是一个整数。它告诉程序有多少个参数被传递给程序。argc 至少为1，因为第一个参数是程序的名称。

argv（Argument Vector）： 是一个指向字符指针数组的指针，其中每个指针指向一个字符串，即一个命令行参数。argv[0] 存储程序的名称，argv[1]、argv[2]，依此类推，存储其他命令行参数。

下面是一个简单的示例：
*/
#include <iostream>

int main(int argc, char *argv[]) {
    // 输出程序的名称
    std::cout << "Program name: " << argv[0] << std::endl;

    // 输出命令行参数的数量
    std::cout << "Number of arguments: " << argc - 1 << std::endl;

    // 输出所有命令行参数
    for (int i = 1; i < argc; ++i) {
        std::cout << "Argument " << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
