#include <iostream>
#include "shuju_demo1.h"
my_test::Fs fs;
my_test::RE re;
int main(int argc, char const *argv[])
{
    re.dataplus = fs.dataplus;
    for(auto str:re.dataplus)
    {
        std::cout << "--" << str << std::endl;
    }
    // while (true)
    // {
    //     std::cout << "嘻嘻" << std::endl;
    //     std::this_thread::sleep_for(std::chrono::seconds(1));
    // }

    

    return 0;
}
