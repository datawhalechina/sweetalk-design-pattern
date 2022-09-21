//
// Created by HuRF on 2022/9/20.
//

#include "ComponentComposite.h"

int main() {
    // 生成树根root，根上长出两叶LeafA和LeafB
    Composite root("root");
    Leaf leafA("Leaf A");
    root.Add(leafA);
    Leaf leafB("Leaf B");
    root.Add(leafB);

    // 根上长出分枝CompositeX，分枝上也有两叶LeafXA和LeafXB
    Composite comp("Composite X");
    Leaf leafXA("Leaf XA");
    comp.Add(leafXA);
    Leaf leafXB("Leaf XB");
    comp.Add(leafXB);

    root.Add(comp);

    // 在CompositeX上再长出分枝CompositeXY，分枝上也有两叶LeafXYA和LeafXYB
    Composite comp2("Composite XY");
    Leaf leafXYA("Leaf XYA");
    comp2.Add(leafXYA);
    Leaf leafXYB("Leaf XYB");
    comp2.Add(leafXYB);

    comp.Add(comp2);

    // 根部又长出两叶LeafC和LeafD
    Leaf leafC("Leaf C");
    root.Add(leafC);

    Leaf leaf("Leaf D");
    root.Add(leaf);
    // 可惜LeafD没长牢，被风吹走了
    root.Remove(leaf);

    // 显示大树的样子
    root.Display(1);
    return 0;
}

