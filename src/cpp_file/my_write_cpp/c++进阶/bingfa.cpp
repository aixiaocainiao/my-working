// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <queue>
// #include <chrono>
// #include <condition_variable>

// class DataHandler {
// public:
//     DataHandler() : stopThreads_(false) {
//         // 启动发送数据的线程
//         senderThread_ = std::thread(&DataHandler::sendData, this);

//         // 启动接收数据的线程
//         receiverThread_ = std::thread(&DataHandler::receiveData, this);
//     }

//     ~DataHandler() {
//         // 通知线程停止
//         stopThreads_ = true;

//         // 唤醒可能在等待的接收数据线程
//         stopCondition_.notify_all();

//         // 等待线程结束
//         senderThread_.join();
//         receiverThread_.join();
//     }

// private:
//     std::mutex dataMutex_;
//     std::queue<std::string> dataQueue_;
//     std::thread senderThread_;
//     std::thread receiverThread_;
//     std::condition_variable stopCondition_;
//     bool stopThreads_;

//     // 发送数据的函数
//     void sendData() {
//         while (!stopThreads_) {
//             // 模拟生成数据
//             std::string data = "Data from sender";

//             // 加锁，将数据放入队列
//             std::lock_guard<std::mutex> lock(dataMutex_);
//             dataQueue_.push(data);

//             // 模拟间隔
//             std::this_thread::sleep_for(std::chrono::seconds(1));
//         }
//     }

//     // 接收数据的函数
//     void receiveData() {
//         while (!stopThreads_) {
//             // 加锁，检查并取出队列中的数据
//             std::unique_lock<std::mutex> lock(dataMutex_);
//             stopCondition_.wait(lock, [this] { return !dataQueue_.empty() || stopThreads_; });

//             while (!dataQueue_.empty()) {
//                 std::string data = dataQueue_.front();
//                 dataQueue_.pop();

//                 // 模拟处理接收到的数据
//                 std::cout << "Received data: " << data << std::endl;
//             }
//         }
//     }
// };

// int main() {
//     // 创建 DataHandler 对象，开始线程
//     DataHandler dataHandler;

//     // 主线程执行其他逻辑，这里简单地打印一些信息
//     while (true) {
//         std::cout << "Main thread is doing something..." << std::endl;

//         // 模拟间隔
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }

//     return 0;
// }
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>

class DataHandler {
public:
    DataHandler() : stopThreads_(false) {
        // 启动发送数据的线程
        senderThread_ = std::thread(&DataHandler::sendData, this);

        // 启动接收数据的线程
        receiverThread_ = std::thread(&DataHandler::receiveData, this);
    }

    ~DataHandler() {
        // 通知线程停止
        stopThreads_ = true;

        // 唤醒可能在等待的接收数据线程
        stopCondition_.notify_all();

        // 等待线程结束
        senderThread_.join();
        receiverThread_.join();
    }

private:
    std::mutex dataMutex_;
    std::queue<std::string> dataQueue_;
    std::thread senderThread_;
    std::thread receiverThread_;
    std::condition_variable stopCondition_;
    bool stopThreads_;

    // 发送数据的函数
    void sendData() {
        while (!stopThreads_) {
            // 模拟生成数据
            std::string data = "Data from sender";

            // 加锁，将数据放入队列
            std::lock_guard<std::mutex> lock(dataMutex_);
            dataQueue_.push(data);

            // 模拟间隔
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    // 接收数据的函数
    void receiveData() {
        while (!stopThreads_) {
            // 加锁，检查并取出队列中的数据
            std::unique_lock<std::mutex> lock(dataMutex_);
            stopCondition_.wait(lock, [this] { return !dataQueue_.empty() || stopThreads_; });

            while (!dataQueue_.empty()) {
                std::string data = dataQueue_.front();
                dataQueue_.pop();

                // 模拟处理接收到的数据
                std::cout << "Received data: " << data << std::endl;
            }
        }
    }
};

int main() {
    // 创建 DataHandler 对象，开始线程
    DataHandler dataHandler;

    // 主线程执行其他逻辑，这里简单地打印一些信息
    while (true) {
        std::cout << "Main thread is doing something..." << std::endl;

        // 模拟间隔
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
