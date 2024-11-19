#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

SortedSet::SortedSet(Relation r) : r(r), capacity(10), size_(0) {
    table = new TElem[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = NULL_TELEM;
    }
}

int SortedSet::hash1(TComp e) const {
    return std::abs(e) % capacity;
}

int SortedSet::hash2(TComp e) const {
    return 1 + (std::abs(e) % (capacity - 1));
}

int SortedSet::doubleHash(TComp e, int i) const {
    return (hash1(e) + i * hash2(e)) % capacity;
}

void SortedSet::resizeAndRehash() {
    int oldCapacity = capacity;
    capacity *= 2;
    TElem* oldTable = table;
    table = new TElem[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = NULL_TELEM;
    }
    size_ = 0;

    for (int i = 0; i < oldCapacity; ++i) {
        if (oldTable[i] != NULL_TELEM) {
            add(oldTable[i]);
        }
    }

    delete[] oldTable;
}

bool SortedSet::add(TComp e) {
    if (size_ >= capacity / 2) {
        resizeAndRehash();
    }

    int i = 0;
    int pos;
    while (true) {
        pos = doubleHash(e, i);
        if (table[pos] == NULL_TELEM) {
            table[pos] = e;
            size_++;
            return true;
        }
        else if (table[pos] == e) {
            return false;
        }
        i++;
    }
}

bool SortedSet::remove(TComp e) {
    int i = 0;
    int pos;
    while (i <= size_+1) {
        pos = doubleHash(e, i);
        if (table[pos] == e) {
            table[pos] = NULL_TELEM;
            size_--;
            return true;
        }
        ++i;
    }

    pos = doubleHash(e, i);
    if (table[pos] == e) {
        table[pos] = NULL_TELEM;
        size_--;
        return true;
    }
    return false;
}

bool SortedSet::search(TElem elem) const {
    int i = 0;
    int pos;
    while (i < capacity) {
        pos = doubleHash(elem, i);
        if (table[pos] == elem) {
            return true;
        }
        else if (table[pos] == NULL_TELEM) {
            return false;
        }
        i++;
    }
    return false;
}

int SortedSet::size() const {
    return size_;
}

bool SortedSet::isEmpty() const {
    return size_ == 0;
}

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

SortedSet::~SortedSet() {
    delete[] table;
}
