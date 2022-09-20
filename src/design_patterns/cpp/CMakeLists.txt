cmake_minimum_required(VERSION 3.20)
project(sweetalk-design-pattern)

set(CMAKE_CXX_STANDARD 14)

# 适配器模式
add_executable(play_adapter adapter/PlayAdapter.cpp adapter/main.cpp)
# 备忘录模式
add_executable(game_memento memento/GameRoleMemento.cpp memento/main.cpp)
# 组合模式
add_executable(component_composite composite/ComponentComposite.cpp composite/main.cpp)

