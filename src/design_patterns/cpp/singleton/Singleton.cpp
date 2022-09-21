//
// Created by HuRF on 2022/9/21.
//
#include <iostream>

using namespace std;

// 懒汉式单例模式
class SingletonMultiThread {
private:
    static SingletonMultiThread * instance;
    // 构造方法让其private，堵死外界利用new创建此类实例的可能
    SingletonMultiThread() = default;;
public:
    // 获得本类实例的唯一全局访问点
    static SingletonMultiThread * GetInstance() {
        // 若实例不存在，则new一个新实例，否则返回已有的实例
        if (instance == nullptr) {
            instance = new SingletonMultiThread;
        }
        return instance;
    }
};
SingletonMultiThread* SingletonMultiThread::instance = nullptr;

int main() {
    SingletonMultiThread * s1 = SingletonMultiThread::GetInstance();
    SingletonMultiThread * s2 = SingletonMultiThread::GetInstance();

    // 比较两次实例化后对象的结构是实例相同
    if (s1 == s2) {
        std::cout << "两个对象是相同的实例。" << std::endl;
    }

    return 0;
}
