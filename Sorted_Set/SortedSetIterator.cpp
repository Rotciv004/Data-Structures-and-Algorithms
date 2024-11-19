#include "SortedSetIterator.h"
#include <algorithm>
#include <stdexcept>  // Include stdexcept for std::out_of_range

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m), currentIndex(0) {
    length = multime.size();
    sortedArray = new TElem[length];
    int index = 0;
    for (int i = 0; i < multime.capacity; ++i) {
        if (multime.table[i] != NULL_TELEM) {
            if (index < length) {
                sortedArray[index++] = multime.table[i];
            }
            else {
                throw std::runtime_error("Buffer overrun while writing to 'sortedArray'");
            }
        }
    }
    sortElements();
}

void SortedSetIterator::sortElements() {
    std::sort(sortedArray, sortedArray + length, multime.r);
}

void SortedSetIterator::first() {
    currentIndex = 0;
}

void SortedSetIterator::next() {
    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }

    currentIndex++;
}

TElem SortedSetIterator::getCurrent() {
    if (!valid()) {
        throw std::out_of_range("Iterator out of range");
    }
    return sortedArray[currentIndex];
}

bool SortedSetIterator::valid() const {
    return currentIndex>=0 and currentIndex < length;
}

SortedSetIterator::~SortedSetIterator() {
    delete[] sortedArray;
}



void SortedSetIterator::jumpBackward(int k) {
    if (k <= 0 or !valid()) {
        throw std::invalid_argument("k must be positive");
    }

    currentIndex -= k;

}
