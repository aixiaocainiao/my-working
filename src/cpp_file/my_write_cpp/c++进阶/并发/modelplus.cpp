/*
    功能:
        一个线程接受数据 一个线程发送数据
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <vector>
// #include <condition_variabel>
#include <condition_variable>

std::mutex dataMutex;
std::condition_variable dataReady;
std::queue<int> sharedQueue;
bool isProducerDone = false;
class FS
{
public:
    FS()
    {
        isProducerDone = false;
        t1 = std::thread(&FS::main_Fs,this);
    }
    std::thread t1;
    void read_data()
    {
        for(int i = 0;i < 10;i++){
            {
                std::lock_guard<std::mutex>lock(dataMutex);
                sharedQueue.push(i);
            }
            dataReady.notify_one();
            std::this_thread::sleep_for(std::chrono::seconds(1));


        }
        // isProducerDone = true;
        // dataReady.notify_all();
    }
    void main_Fs()
    {
        int count = 1;
        while(true)
        {
            std::cout << "1-- 发送数据函数进来了" << std::endl;
            // int count = 2;
            read_data();
            std::cout << "--1 发送数据函数进来了" << std::endl;

            count--;
            if(count < 0){

                std::cout << "2-- 数据发送完毕条件进来了吗" << std::endl;
                isProducerDone = true;
                dataReady.notify_all();
                std::cout << "--2 数据发送完毕条件进来了吗" << std::endl;

                break;
            }
        }
        
    }
    ~FS()
    {
        isProducerDone = false;
        if(t1.joinable())
        {
            t1.join();
        }
    }

};

class RE
{
public:
    RE()
    {
        vi.clear();
        t1 = std::thread(&RE::main_Re,this);
        
    }
    std::thread t1;
    std::vector<int>vi;
    void main_Re()
    {
        //记住数据防止while循环外面 不然一直重置  一直为重新开始
        int count = 0;

        while(true){

            std::unique_lock<std::mutex>lock(dataMutex);
            dataReady.wait(lock,[&](){
                return (!sharedQueue.empty() || isProducerDone);

            });
            if(!sharedQueue.empty()){
                int data = sharedQueue.front();
                sharedQueue.pop();
                std::cout << "接受到的数据为: " << data << std::endl;
                count++;
                if(count > 0 && count < 11){
                    // std::cout << "进来了" << std::endl;
                    vi.push_back(data); 
                }
                if(count >=11 && count < 12)
                {
                    std::cout << "111111" << std::endl;
                    for(std::vector<int>::iterator it = vi.begin();it != vi.end();it++){

                        std::cout << *it << " ";
                    }
                    std::cout << std::endl;
                }

            }
            if(isProducerDone &&sharedQueue.empty())
            {
                std::cout << "222222" << std::endl;
                for(std::vector<int>::iterator it = vi.begin();it != vi.end();it++){

                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                std::cout << "-------------" << std::endl;
                std::cout << "333333" << std::endl;

                for(auto i:vi){
                    std::cout << i << " ";
                }
                std::cout << std::endl;
                std::cout << "-------------" << std::endl;

                // break;
                // continue;
                break;
            }
        }
    }
    ~RE()
    {
        if(t1.joinable()){
            t1.join();
        }

    }
};
FS fs;
RE re;
int main(int argc, char const *argv[])
{
    std::cout << "当前线程开始执行" << std::endl;
    // while(true)
    // {

    // }
    return 0;
}
