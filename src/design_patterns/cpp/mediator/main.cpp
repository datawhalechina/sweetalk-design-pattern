//
// Created by HuRF on 2022/9/22.
//

#include "UNMediator.h"

int main() {
    UnitedNationsSecurityCouncil * UNSC = new UnitedNationsSecurityCouncil();

    USA * c1 = new USA(UNSC);
    Iraq * c2 = new Iraq(UNSC);

    UNSC->setColleague1(c1);
    UNSC->setColleague2(c2);

    c1->Declare("不准研制核武器，否则要发动战争！");
    c2->Declare("我们没有核武器，也不怕侵略。");

    return 0;
}