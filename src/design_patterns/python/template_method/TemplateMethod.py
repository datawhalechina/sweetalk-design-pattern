# -*- coding:utf-8 -*-
'''
@File    :   TemplateMethod.py
@Time    :   2022/09/26 16:44:50
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# 金庸小说考题试卷
class TestPaper(object):
    def testQuestion1(self):
        print("杨过得到，后来给了郭靖，炼成倚天剑、屠龙刀的玄铁可能是[ ] a.球墨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维")
        print("答案："+self.Answer1())
    def testQuestion2(self):
        print("杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝了 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化")
        print("答案："+self.Answer2())
    def testQuestion3(self):
        print("蓝凤凰致使华山师徒、桃谷六仙呕吐不止，如果你是大夫，会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对")
        print("答案："+self.Answer3())
    def Answer1(self):
        return ""
    def Answer2(self):
        return ""
    def Answer3(self):
        return ""

class TestPaperA(TestPaper):
    def Answer1(self):
        return "b"
    def Answer2(self):
        return "c"
    def Answer3(self):
        return "a"

class TestPaperB(TestPaper):
    def Answer1(self):
        return "c"
    def Answer2(self):
        return "a"
    def Answer3(self):
        return "a"

if __name__ == '__main__':
    print("学生甲抄的试卷：")
    studentA = TestPaperA()
    studentA.testQuestion1()
    studentA.testQuestion2()
    studentA.testQuestion3()

    print("学生乙抄的试卷：")
    studentB = TestPaperB()
    studentB.testQuestion1()
    studentB.testQuestion2()
    studentB.testQuestion3()
