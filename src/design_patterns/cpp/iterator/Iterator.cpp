//
// Created by HuRF on 2022/9/21.
//

#include "Iterator.h"


Iterator *ConcreateAggregate::CreateIterator() {
    return new ConcreateIterator(this);
}

int ConcreateAggregate::GetCount() {
    return (int) items.size();
}

string ConcreateAggregate::operator[](int index) {
    if (this->items.size() <= index) {
        this->items.resize(index + 1);
    }
    return this->items[index];
}

void ConcreateAggregate::Insert(const string &strVal) {
    items.push_back(strVal);
}

ConcreateIterator::ConcreateIterator(ConcreateAggregate *aggregate) : aggregate(aggregate), current(0) {}

string ConcreateIterator::First() {
    return (*aggregate)[0];
}

string ConcreateIterator::Next() {
    string ret;
    current++;
    if (current < aggregate->GetCount()) {
        ret = (*aggregate)[current];
    }
    return ret;
}

bool ConcreateIterator::IsDone() {
    return current >= aggregate->GetCount();
}

string ConcreateIterator::CurrentItem() {
    return (*aggregate)[current];
}

ConcreateIteratorDesc::ConcreateIteratorDesc(ConcreateAggregate *aggregate) : aggregate(aggregate),
                                                                              current(aggregate->GetCount() - 1) {
}

string ConcreateIteratorDesc::First() {
    return (*aggregate)[aggregate->GetCount() - 1];
}

string ConcreateIteratorDesc::Next() {
    string ret;
    current--;
    if (current >= 0) {
        ret = (*aggregate)[current];
    }
    return ret;
}

bool ConcreateIteratorDesc::IsDone() {
    return current < 0;
}

string ConcreateIteratorDesc::CurrentItem() {
    return (*aggregate)[current];
}








