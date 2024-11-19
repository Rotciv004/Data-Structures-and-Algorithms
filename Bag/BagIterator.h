#pragma once

#include "Bag.h"

class BagIterator {
private:
    const Bag& bag;
    int current; // Current position in the bag

public:
    // Constructor
    BagIterator(const Bag& c);

    // Sets the iterator to the first valid position
    void first();

    // Moves the iterator to the next valid position
    void next();

    // Returns the element at the current position
    TElem getCurrent() const;

    // Checks if the iterator is in a valid position
    bool valid() const;
};
