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
    // 模拟一直生成数据
    int counter = 0;
    while (true) {
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            sharedQueue.push(counter);
            counter++;
        }
        dataReady.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
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
        if (isProducerDone) {
            continue;  // 继续尝试接收数据，即使队列为空
        }
    }
}

int main() {
    std::thread producer(producerThread);
    std::thread consumer(consumerThread);

    // 主线程等待一段时间
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // 标志生产者已完成（实际应用中可能需要更复杂的结束逻辑）
    isProducerDone = true;
    dataReady.notify_one();

    producer.join();
    consumer.join();

    return 0;
}
