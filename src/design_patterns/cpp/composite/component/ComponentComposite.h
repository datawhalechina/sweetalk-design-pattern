//
// Created by HuRF on 2022/9/20.
//

#ifndef COMPONENTCOMPOSITE_H
#define COMPONENTCOMPOSITE_H

#include <string>
#include <utility>
#include <list>

using namespace std;

class Component {
protected:
    string name;
public:
    explicit Component(string n);

    virtual ~Component() = default;

    virtual void Add(Component *c) {};

    virtual void Remove(Component *c) {};

    virtual void Display(int depth) {};

    bool operator==(Component *c);
};

class Leaf : public Component {
public:
    explicit Leaf(string n) : Component(std::move(n)) {};

    void Add(Component *c) override;

    void Remove(Component *c) override;

    void Display(int depth) override;
};

class Composite : public Component {
private:
    list<Component *> children;
public:
    explicit Composite(string n) : Component(std::move(n)) {};

    void Add(Component *c) override;

    void Remove(Component *c) override;

    void Display(int depth) override;
};

#endif //COMPONENTCOMPOSITE_H
