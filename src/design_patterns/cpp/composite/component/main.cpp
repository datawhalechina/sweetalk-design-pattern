//
// Created by HuRF on 2022/9/20.
//

#include "ComponentComposite.h"

int main() {
    // 生成树根root，根上长出两叶LeafA和LeafB
    Composite *root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    // 根上长出分枝CompositeX，分枝上也有两叶LeafXA和LeafXB
    Composite *comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf XB"));
    root->Add(comp);

    // 在CompositeX上再长出分枝CompositeXY，分枝上也有两叶LeafXYA和LeafXYB
    Composite *comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp->Add(comp2);

    // 根部又长出两叶LeafC和LeafD
    root->Add(new Leaf("Leaf C"));
    Leaf *leafD = new Leaf("Leaf D");
    root->Add(leafD);
    // 可惜LeafD没长牢，被风吹走了
    root->Remove(leafD);

    // 显示大树的样子
    root->Display(1);
    return 0;
}

