#ifndef __SHUJU_DEMO01_H__
#define __SHUJU_DEMO01_H__
#include <iostream> 
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
namespace my_test
{
class Fs
{
    public:
        Fs(){
            Isok = true;
            dataplus.clear();
            t1 = std::thread(&Fs::main_func,this);
        }
        ~Fs()
        {
            dataplus.clear();
            if(t1.joinable()){
                t1.join();
            }
        }
        
        std::vector<std::string> dataplus;

    public:
        std::thread t1;
        std::mutex mux;
        bool Isok;
        void read_data()
        {
             std::lock_guard<std::mutex>lock(mux);
                count++;
                // dataplus.push_back(data + static_cast<std::string>(count++));
                data = data + std::to_string(count);
                dataplus.push_back(data);
                std::cout << "要发送的数据为" << data << std::endl;
                std::this_thread::sleep_for((std::chrono::seconds(1)));

        }
        void main_func()
        {
            std::cout << "发送线程进来了" << std::endl;
            std::string data = "我正在发送数据";
            int count = 0;
            while(Isok)
            {

                if(Isok = treu)
                {
                    read_data();
                }
            }
        }

};
class RE
{
public:
    RE()
    {

        t2 = std::thread(&RE::main_receive,this);

    }
    std::vector<std::string>dataplus;
    ~RE()
    {
        dataplus.clear();
            if(t2.joinable()){
                t2.join();
            }
    }
public: 
    std::thread t2;
    std::mutex mux;
    
    void main_receive()
    {
        std::cout << "接受线程进来了" << std::endl;
        std::this_thread::sleep_for((std::chrono::seconds(5)));
        
        // if(dataplus.empty()){
        //     std::cout << "接受函数退出了" << std::endl;
        //     return;
        // }
        while (true)
        {
            std::lock_guard<std::mutex>lock(mux);
            std::cout << "while函数进来了" << std::endl;
            for(auto str:dataplus)
            {
                std::cout << "接受的数据为" << str << std::endl;
            }
            std::this_thread::sleep_for((std::chrono::seconds(1)));

        }
        

    }
    

};

};

#endif