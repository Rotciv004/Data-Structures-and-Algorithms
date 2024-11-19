#pragma once
#include "SortedSet.h"

class SortedSetIterator {
    friend class SortedSet;
private:

    const SortedSet& multime;
    TElem* sortedArray;
    int currentIndex;
    int length;

    void sortElements();

    SortedSetIterator(const SortedSet& m);

public:
    void first();

    void next();

    TElem getCurrent();

    bool valid() const;

    ~SortedSetIterator();

    void jumpBackward(int k);

};
