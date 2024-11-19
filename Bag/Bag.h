#pragma once

#define NULL_TELEM -111111
typedef int TElem;

class BagIterator;

class Bag {
private:
    TElem* U; // Dynamic array to store unique elements
    TElem* P;   // Dynamic array to store positions of elements in U
    int capacity; // Capacity of the dynamic arrays
    int length_U,length_P;   // Current number of elements in the Bag

    // Resizes the dynamic arrays if necessary
    void resize();

    // Finds the position of an element in U, returns -1 if not found
    int findPosition(TElem e) const;

    // Declare BagIterator as a friend class to allow access to private members
    friend class BagIterator;

public:
    // Constructor
    Bag(int max = 5);

    // Destructor
    ~Bag();

    // Adds an element to the bag
    void add(TElem e);

    // Removes one occurrence of an element from the bag
    // Returns true if an element was removed, false otherwise
    bool remove(TElem e);

    // Checks if an element appears in the bag
    bool search(TElem e) const;

    // Returns the number of occurrences for an element in the bag
    int nrOccurrences(TElem e) const;

    // Returns the number of elements in the bag
    int size() const;

    // Returns an iterator for this bag
    BagIterator iterator() const;

    // Checks if the bag is empty
    bool isEmpty() const;

    int toSet();
};