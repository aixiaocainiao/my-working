#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <queue>
#include <condition_variable>
#include "sl_lidar.h"
#include "sl_lidar_driver.h"
// 宏定义 一个计算数组的
#ifndef _countArray
#define _countArray(_Array) (int)(sizeof(_Array)/sizeof(_Array[0]))
#endif

#ifdef _WIN32
#include <window.h>
#define delay(x) ::sleep(x)
#else
#include <unistd.h>
static inline void delay(sl_word_size_t ms)
{
    

}
#endif
class Fs_Laser
{
public:
    Fs_Laser()
    {
        isProducerDone = fasle;
        if(!data_scan.empty()){
            data_scan.pop();
        }
        while (true)
        {
            if(!connecttion){
                Open_Mylaser();
            }
            else{
                break;
            }
        }
        
        t1 = std::thread(&Fs_Laser::main_control,this);
    }
    ~Fs_Laser()
    {
        isProducerDone = fasle;
        if(!data_scan.empty()){
            data_scan.pop();
        }
        if(t1.joinable()){
            t1.join();
        }
    }
private:
    std::thread t1;
    std::mutex mux;
    std::condition_variable dataReady;
    std::queue<double>data_scan;
    bool isProducerDone = false;
    //雷达打开成功标志  打不开 不进行数据的读取
    bool connecttion = false;
    void Open_Mylaser()
    {

    }




    void main_control()
    {


    }


};
int main(int argc, char const *argv[])
{
    
    return 0;
}
