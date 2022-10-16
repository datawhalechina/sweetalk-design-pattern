# -*- coding:utf-8 -*-
'''
@File    :   State.py
@Time    :   2022/09/27 19:04:33
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
# 工作状态
class State(object):
    def write_program(self,w):
        pass

# 睡眠状态
class SleepingState(State):
    def write_program(self, w):
        print(f"当前时间：{w.hour}点 不行了，睡着了。")

# 下班休息状态
class RestState(State):
    def write_program(self, w):
        print(f"当前时间：{w.hour}点 下班回家了")

# 晚间工作状态
class EveningState(State):
    def write_program(self, w):
        if w.taskFinished:
            w.set_state(RestState())
            w.write_program()
        else:
            if w.hour < 21:
                print(f"当前时间：{w.hour}点 加班哦，疲累之极")
            else:
                w.set_state(SleepingState())
                w.write_program()

# 下午工作状态
class AfternoonState(State):
    def write_program(self, w):
        if w.hour < 17:
            print(f"当前时间：{w.hour}点 下午状态还不错，继续努力")
        else:
            w.set_state(EveningState())
            w.write_program()

# 中午工作状态
class NoonState(State):
    def write_program(self, w):
        if w.hour < 13:
            print(f"当前时间：{w.hour}点 饿了，午饭；犯困，午休。")
        else:
            w.set_state(AfternoonState())
            w.write_program()

# 上午工作状态
class ForenoonState(State):
    def write_program(self, w):
        if w.hour < 12:
            print(f"当前时间：{w.hour}点 上午工作，精神百倍")
        else:
            w.set_state(NoonState())
            w.write_program()

# 工作
class Work(object):
    __current = None
    __hour = None
    __finish = False
    def __init__(self):
        self.__current = ForenoonState()

    def set_state(self,s:State):
        self.__current = s
    def write_program(self):
        self.__current.write_program(self)

    def get_hour(self):
        return self.__hour
    def set_hour(self,hour):
        self.__hour = hour
    def get_finish(self):
        return self.__finish
    def set_finish(self,finish):
        self.__finish = finish
    hour = property(get_hour,set_hour)
    taskFinished = property(get_finish,set_finish)


if __name__ == '__main__':
    # 紧急项目
    emergencyProjects = Work()
    emergencyProjects.hour = 9
    emergencyProjects.write_program()
    emergencyProjects.hour = 10
    emergencyProjects.write_program()
    emergencyProjects.hour = 12
    emergencyProjects.write_program()
    emergencyProjects.hour = 13
    emergencyProjects.write_program()
    emergencyProjects.hour = 14
    emergencyProjects.write_program()
    emergencyProjects.hour = 17

    #emergencyProjects.taskFinished = True
    emergencyProjects.taskFinished = False

    emergencyProjects.write_program()
    emergencyProjects.hour = 19
    emergencyProjects.write_program()
    emergencyProjects.hour = 22
    emergencyProjects.write_program()