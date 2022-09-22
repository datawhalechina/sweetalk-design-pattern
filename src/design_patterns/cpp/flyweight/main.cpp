//
// Created by HuRF on 2022/9/22.
//

#include "WebSite.h"
#include <iostream>

using namespace std;

int main() {
    WebSiteFactory * f = new WebSiteFactory();

    WebSite * fx = f->GetWebSiteCategory("产品展示");
    fx->Use(new User("小菜"));

    WebSite * fy = f->GetWebSiteCategory("产品展示");
    fy->Use(new User("大鸟"));

    WebSite * fz = f->GetWebSiteCategory("产品展示");
    fz->Use(new User("娇娇"));

    WebSite * fl = f->GetWebSiteCategory("博客");
    fl->Use(new User("老顽童"));

    WebSite * fm = f->GetWebSiteCategory("博客");
    fm->Use(new User("桃谷六仙"));

    WebSite * fn = f->GetWebSiteCategory("博客");
    fn->Use(new User("南海鳄神"));

    std::cout << "得到网站分类总数为 " << f->GetWebSiteCount() << std::endl;

    return 0;
}