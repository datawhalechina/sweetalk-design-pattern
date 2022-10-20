cmake_minimum_required(VERSION 3.20)
project(sweetalk-design-pattern)

set(CMAKE_CXX_STANDARD 14)

# 状态模式
add_executable(work state/Work.cpp)
# 适配器模式
add_executable(play_adapter adapter/PlayAdapter.cpp adapter/main.cpp)
# 备忘录模式
add_executable(game_memento memento/GameRoleMemento.cpp memento/main.cpp)
# 组合模式-树
add_executable(component_composite composite/component/ComponentComposite.cpp composite/component/main.cpp)
# 组合模式-公司管理系统
add_executable(cms composite/company_management_system/Company.cpp composite/company_management_system/main.cpp)
# 迭代器模式
add_executable(bus_iterator iterator/Iterator.cpp iterator/main.cpp)
# 懒汉式单例模式
add_executable(singleton_lazy singleton/Singleton.cpp)
# 多线程的单例模式
add_executable(singleton_multi_thread singleton/SingletonMultiThread.cpp)
# 双重锁定的单例模式
add_executable(singleton_double_check singleton/SingletonDoubleCheck.cpp)
# 桥接模式
add_executable(handset_bridge bridge/HandsetBridge.cpp bridge/main.cpp)
# 命令模式
add_executable(order_command command/OrderCommand.cpp command/main.cpp)
# 职责链模式
add_executable(raise_chain_of_responsibility chain_of_responsibility/Raise.cpp chain_of_responsibility/main.cpp)
# 中介者模式
add_executable(united_nations_mediator mediator/UNMediator.cpp mediator/main.cpp)
# 享元模式
add_executable(website_flyweight flyweight/WebSite.cpp flyweight/main.cpp)
# 解释器模式
add_executable(music_interpreter interpreter/MusicInterpreter.cpp interpreter/main.cpp)
# 访问者模式
add_executable(man_woman_visitor visitor/ManWomanVisitor.cpp visitor/main.cpp)