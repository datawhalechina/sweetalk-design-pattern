//
// Created by HuRF on 2022/9/21.
//

#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <string>

using namespace std;

// Iterator迭代器抽象类
class Iterator {
public:
    virtual string First() = 0;

    virtual string Next() = 0;

    virtual bool IsDone() = 0;

    virtual string CurrentItem() = 0;
};

// Aggregate聚集抽象类
class Aggregate {
public:
    virtual Iterator *CreateIterator() = 0;
};


class ConcreateAggregate : public Aggregate {
private:
    vector<string> items;
public:
    Iterator *CreateIterator() override;

    int GetCount();

    string operator[](int i);

    void Insert(const string &strVal);
};

class ConcreateIterator : public Iterator {
private:
    ConcreateAggregate *aggregate;
    int current;
public:
    explicit ConcreateIterator(ConcreateAggregate * aggregate);

    string First() override;

    string Next() override;

    bool IsDone() override;

    string CurrentItem() override;
};

class ConcreateIteratorDesc : public Iterator {
private:
    ConcreateAggregate *aggregate;
    int current;
public:
    explicit ConcreateIteratorDesc(ConcreateAggregate * aggregate);

    string First() override;

    string Next() override;

    bool IsDone() override;

    string CurrentItem() override;
};

#endif //ITERATOR_H
