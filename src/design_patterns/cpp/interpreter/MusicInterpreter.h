//
// Created by HuRF on 2022/9/22.
//

#ifndef MUSICINTERPRETER_H
#define MUSICINTERPRETER_H

#include <string>

using namespace std;

// 演奏内容
class PlayContext {
private:
    // 演奏文本
    string text;
public:
    string getPlayText();
    void setPlayText(const string &value);
};

// 表达式
class Expression{
public:
    // 解释器
    void Interpret(PlayContext *context);
    // 执行
    virtual void Execute(char &key, double &value) = 0;
};

// 音符
class Note : public Expression {
public:
    void Execute(char &key, double &value) override;
};

class Scale: public Expression {
public:
    void Execute(char &key, double &value) override;
};

// 音速
class Speed : public Expression {
    void Execute(char &key, double &value) override;
};

#endif //MUSICINTERPRETER_H
