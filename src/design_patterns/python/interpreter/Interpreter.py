# -*- coding:utf-8 -*-
'''
@File    :   Interpreter.py
@Time    :   2022/09/30 18:29:56
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
NOTE_DICT = {
    "C":"1","D":"2","E":"3","F":"4","G":"5","A":"6","B":"7"
}
SCALE_DICT = {
    "1":"低音","2":"中音","3":"高音"
}


class PlayContext(object):
    __text = ""
    def get_text(self):
        return self.__text
    def set_text(self,text):
        self.__text = text
    playText = property(get_text,set_text)

# 表达式类
class Expression(object):
    def interpret(self,context:PlayContext):
        if len(context.playText) == 0:
            return None
        else:
            playKey = context.playText.split(" ")[0]
            #context.playText = context.playText[:3]
            playValue = context.playText.split(" ")[1]
            context.playText = " ".join(context.playText.split(" ")[2:])
            self.excute(playKey,playValue)
    def excute(self,key,value):
        pass

# 音符
class Note(Expression):
    def excute(self,key,value):
        note = NOTE_DICT.get(key,"")
        print(f"{note}",end=" ")

# 音阶
class Scale(Expression):
    def excute(self,key,value):
        scale = SCALE_DICT.get(value,"")
        print(f"{scale}",end=" ")

# 音速
class Speed(Expression):
    def excute(self,key,value):
        speed = ""
        if float(value) < 500:
            speed = "快速"
        elif float(value) >= 1000:
            speed = "慢速"
        else:
            speed = "中速"
        print(f"{speed}",end=" ")

if __name__ == '__main__':
    context = PlayContext()
    print("上海滩：")
    context.playText = "O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3"
    expression = None
    try:
        while len(context.playText)>0:
            str = context.playText.split(" ")[0] 
            if str == "O":
                expression = Scale()
            elif str in ["C","D","E","F","G","A","B","P"]:
                expression = Note()
            expression.interpret(context)
    except Exception as exp:
        print(exp)

    context = PlayContext()
    print("\n上海滩：")
    context.playText = "T 500 O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3"
    expression = None
    try:
        while len(context.playText)>0:
            str = context.playText.split(" ")[0] 
            if str == "O":
                expression = Scale()
            elif str == "T":
                expression = Speed()
            elif str in ["C","D","E","F","G","A","B","P"]:
                expression = Note()
            expression.interpret(context)
    except Exception as exp:
        print(exp)