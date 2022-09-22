//
// Created by HuRF on 2022/9/22.
//

#include "MusicInterpreter.h"
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    PlayContext * context = new PlayContext();
    // 音乐-上海滩
    std::cout << "上海滩：" << std::endl;
    string playtext = "T 500 O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 ";
    context->setPlayText(playtext);
    Expression * expression = nullptr;
    try {
        while (!context->getPlayText().empty()) {
            char str = context->getPlayText().substr(0, 1)[0];
            switch (str) {
                case 'O':
                    expression = new Scale();
                    break;
                case 'T':
                    expression = new Speed();
                    break;
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                case 'G':
                case 'A':
                case 'B':
                case 'P':
                    expression = new Note();
                    break;
                default:;
            }
            expression->Interpret(context);
        }
    } catch (const char * s) {
        std::cout << s << std::endl;
    }

    return 0;
}