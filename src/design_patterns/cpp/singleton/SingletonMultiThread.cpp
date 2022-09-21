//
// Created by HuRF on 2022/9/21.
//
#include <iostream>
#include <mutex>

using namespace std;

// 多线程的单例模式
class SingletonMultiThread {
private:
    static SingletonMultiThread * instance;
    static std::mutex mutex;
    SingletonMultiThread() = default;
public:
    // 获得本类实例的唯一全局访问点
    static SingletonMultiThread * GetInstance() {
        // 在同一时刻加了锁的那部分程序只有一个线程可以进入
        std::unique_lock<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new SingletonMultiThread;
        }
        return instance;
    }
};
SingletonMultiThread* SingletonMultiThread::instance = nullptr;
std::mutex SingletonMultiThread::mutex;

int main() {
    SingletonMultiThread * s1 = SingletonMultiThread::GetInstance();
    SingletonMultiThread * s2 = SingletonMultiThread::GetInstance();

    // 比较两次实例化后对象的结构是实例相同
    if (s1 == s2) {
        std::cout << "两个对象是相同的实例。" << std::endl;
    }

    return 0;
}
