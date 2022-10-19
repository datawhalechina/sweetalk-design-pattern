#include <iostream>

#include "TestPaper.h"

using namespace std;


void TestPaper::testQuestion1()
{
    cout << "杨过得到，后来给了郭靖，炼成倚天剑、屠龙刀的玄铁可能是[ ] a.球磨铸铁 b.马口铁 c.高速合金钢 d.碳素纤维" << endl;
    cout << "答案：" << answer1() << endl;
}

void TestPaper::testQuestion2()
{
    cout << "杨过、程英、陆无双铲除了情花，造成[ ] a.使这种植物不再害人 b.使一种珍稀物种灭绝 c.破坏了那个生物圈的生态平衡 d.造成该地区沙漠化" << endl;
    cout << "答案：" << answer2() << endl;
}

void TestPaper::testQuestion3()
{
    cout << "蓝凤凰的致使华山师徒、桃谷六仙呕吐不止,如果你是大夫,会给他们开什么药[ ] a.阿司匹林 b.牛黄解毒片 c.氟哌酸 d.让他们喝大量的生牛奶 e.以上全不对" << endl;
    cout << "答案：" << answer3() << endl;
}


string TestPaperA::answer1()
{
    return "b";
}

string TestPaperA::answer2()
{
    return "c";
}

string TestPaperA::answer3()
{
    return "a";
}

string TestPaperB::answer1()
{
    return "c";
}

string TestPaperB::answer2()
{
    return "a";
}

string TestPaperB::answer3()
{
    return "a";
}

int main() {

    cout << "学生甲抄的试卷：" << endl;
    TestPaper * studentA = new TestPaperA();
    studentA->testQuestion1();
    studentA->testQuestion2();
    studentA->testQuestion3();

    cout << "学生乙抄的试卷：" << endl;
    TestPaper * studentB = new TestPaperB();
    studentB->testQuestion1();
    studentB->testQuestion2();
    studentB->testQuestion3();
    
    return 0;
}