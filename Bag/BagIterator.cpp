#include "BagIterator.h"
#include "Bag.h"
#include <exception>
#include <algorithm>

BagIterator::BagIterator(const Bag& c) : bag(c){
    
    this->current = 0;
}

void BagIterator::first() {
    current = 0;
}

void BagIterator::next() {
    if (!valid())
        throw std::exception("Invalid iterator position");

    ++current;
}

TElem BagIterator::getCurrent() const {
    if (!valid())
        throw std::exception("Invalid iterator position");
    return bag.U[bag.P[current]];
}

bool BagIterator::valid() const {
    return current < bag.size();
}