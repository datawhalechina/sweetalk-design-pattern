# -*- coding:utf-8 -*-
'''
@File    :   Builder.py
@Time    :   2022/09/26 18:44:21
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

import matplotlib.pyplot as plt
from matplotlib.patches import Ellipse,Rectangle
from matplotlib.lines import Line2D

class PersonBuilder(object):
    def __init__(self,ax,color):
        self.ax = ax
        self.color = color

    def build_head(self):
        pass
    def build_body(self):
        pass
    def build_arm_left(self):
        pass
    def build_arm_right(self):
        pass
    def build_leg_left(self):
        pass
    def build_leg_right(self):
        pass

class PersonFatBuilder(PersonBuilder):
    def build_head(self):
        self.ax.add_patch(Ellipse(xy = (50+15,-20-15), width = 30, height = 30, color = self.color))
    def build_body(self):
        self.ax.add_patch(Ellipse(xy = (45+20,-50-25), width = 40, height = 50, color = self.color))
    def build_arm_left(self):
        self.ax.add_patch(Line2D(xdata = (50,30), ydata = (-50,-100), color = self.color))
    def build_arm_right(self):
        self.ax.add_patch(Line2D(xdata = (80,100), ydata = (-50,-100), color = self.color))
    def build_leg_left(self):
        self.ax.add_patch(Line2D(xdata = (60,45), ydata = (-100,-150), color = self.color))
    def build_leg_right(self):
        self.ax.add_patch(Line2D(xdata = (70,85), ydata = (-100,-150), color = self.color))

class PersonThinBuilder(PersonBuilder):
    def build_head(self):
        self.ax.add_patch(Ellipse(xy = (50+15,-20-15), width = 30, height = 30, color = self.color))
    def build_body(self):
        self.ax.add_patch(Rectangle(xy = (60,-50-50), width = 10, height = 50, color = self.color))
    def build_arm_left(self):
        self.ax.add_patch(Line2D(xdata = (60,40), ydata = (-50,-100), color = self.color))
    def build_arm_right(self):
        self.ax.add_patch(Line2D(xdata = (70,90), ydata = (-50,-100), color = self.color))
    def build_leg_left(self):
        self.ax.add_patch(Line2D(xdata = (60,45), ydata = (-100,-150), color = self.color))
    def build_leg_right(self):
        self.ax.add_patch(Line2D(xdata = (70,85), ydata = (-100,-150), color = self.color))
    
class PersonDirector(object):
    def __init__(self,pb):
        self.pb = pb
    def create_person(self):
        self.pb.build_head()
        self.pb.build_body()
        self.pb.build_arm_left()
        self.pb.build_arm_right()
        self.pb.build_leg_left()
        self.pb.build_leg_right()
        plt.xlim((0,150))
        plt.ylim((-150,0))
        plt.axis("off")
        plt.show()


if __name__ == '__main__':
    gThin = plt.figure(figsize = (8,8))
    axThin = gThin.add_subplot(1,1,1)
    ptb = PersonThinBuilder(axThin,"k")
    pdThin = PersonDirector(ptb)
    pdThin.create_person()

    gFat = plt.figure(figsize = (8,8))
    axFat = gFat.add_subplot(1,1,1)
    pfb = PersonFatBuilder(axFat,"k")
    pdFat = PersonDirector(pfb)
    pdFat.create_person()
    



