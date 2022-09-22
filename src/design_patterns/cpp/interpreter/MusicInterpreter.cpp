//
// Created by HuRF on 2022/9/22.
//

#include "MusicInterpreter.h"
#include <iostream>

using namespace std;

string PlayContext::getPlayText() {
    return this->text;
}

void PlayContext::setPlayText(const string &value) {
    this->text = value;
}


void Expression::Interpret(PlayContext *context) {
    if (context->getPlayText().empty()) {
        return;
    } else {
        char playKey = context->getPlayText().substr(0, 1)[0];
        context->setPlayText(context->getPlayText().substr(2));
        double playValue = std::stof((context->getPlayText().substr(0, context->getPlayText().find(' '))));
        context->setPlayText(context->getPlayText().substr(context->getPlayText().find(' ') + 1));

        Execute(playKey, playValue);
    }
}


void Note::Execute(char &key, double &value) {
    string note;
    // 如果获得的key是C，则演奏1(do)，如果是D，则演奏2(Re)
    switch (key) {
        case 'C':
            note = "1";
            break;
        case 'D':
            note = "2";
            break;
        case 'E':
            note = "3";
            break;
        case 'F':
            note = "4";
            break;
        case 'G':
            note = "5";
            break;
        case 'A':
            note = "6";
            break;
        case 'B':
            note = "7";
            break;
        default:;
    }
    std::cout << note << " ";
}


void Scale::Execute(char &key, double &value) {
    string scale;
    // 如果获得的key是O，并且value是1，则演奏低音，2则是中音，3则是高音
    switch ((int32_t) value) {
        case 1:
            scale = "低音";
            break;
        case 2:
            scale = "中音";
            break;
        case 3:
            scale = "高音";
            break;
        default:;
    }
    std::cout << scale << " ";
}

void Speed::Execute(char &key, double &value) {
    string speed;
    if (value < 500)
        speed = "快速";
    else if (value >= 1000)
        speed = "慢速";
    else
        speed = "中速";

    std::cout << speed << " ";
}
