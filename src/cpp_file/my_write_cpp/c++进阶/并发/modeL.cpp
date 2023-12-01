#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::mutex dataMutex;
std::condition_variable dataReady;
std::queue<int> sharedQueue;

bool isProducerDone = false;

void producerThread() {
    // 模拟生成数据
    
    for (int i = 0; i < 10000; ++i) {
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            sharedQueue.push(i);
        }
        /*
            dataReady.notify_one(); 
            是用于通知一个正在等待的线程，告诉它有数据已经准备好可以被处理了。
        */

        dataReady.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // 标志生产者已完成
    isProducerDone = true;
    dataReady.notify_one();
}

void consumerThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(dataMutex);
        dataReady.wait(lock, [&] { return !sharedQueue.empty() || isProducerDone; });

        // 检查是否有数据可用
        if (!sharedQueue.empty()) {
            // 取出数据并处理
            int data = sharedQueue.front();
            sharedQueue.pop();
            std::cout << "Consumer thread received data: " << data << std::endl;
        }

        // 检查是否需要退出
        if (isProducerDone && sharedQueue.empty()) {
            break;
        }
    }
}

int main() {
    std::thread producer(producerThread);
    std::thread consumer(consumerThread);

    producer.join();
    consumer.join();

    return 0;
}
