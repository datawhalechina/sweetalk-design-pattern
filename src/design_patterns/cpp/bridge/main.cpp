//
// Created by HuRF on 2022/9/21.
//

#include "HandsetBridge.h"

int main() {
    HandsetBrand * ab;
    ab = new HandsetBrandN("手机品牌N");

    HandsetGame * hg1 = new HandsetGame();
    ab->SetHandsetSoft(hg1);
    ab->Run();

    HandsetAddressList * ha1 = new HandsetAddressList();
    ab->SetHandsetSoft(ha1);
    ab->Run();

    ab = new HandsetBrandM("手机品牌M");

    HandsetGame * hg2 = new HandsetGame();
    ab->SetHandsetSoft(hg2);
    ab->Run();

    HandsetAddressList * ha2 = new HandsetAddressList();
    ab->SetHandsetSoft(ha2);
    ab->Run();

    return 0;
}