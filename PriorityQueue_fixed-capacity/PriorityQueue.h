#pragma once
#include <vector>
#include <utility>
#include <exception>

using namespace std;

// DO NOT CHANGE THIS PART
typedef int TElem;
typedef int TPriority;
typedef std::pair<TElem, TPriority> Element;
typedef bool (*Relation)(TPriority p1, TPriority p2);
#define NULL_TELEM pair<TElem, TPriority> (-11111,-11111);

class PriorityQueue {
private:
    int* pozitions;
    Element* elements;
    int head, capacity, size, free_space;
    Relation rel;

public:
    // Constructor with capacity parameter
    PriorityQueue(int capacity, Relation rel);

    // Pushes an element with priority to the queue
    void push(TElem e, TPriority p);

    // Returns the element with the highest priority with respect to the order relation
    // Throws exception if the queue is empty
    Element top() const;

    // Removes and returns the element with the highest priority
    // Throws exception if the queue is empty
    Element pop();

    // Checks if the queue is empty
    bool isEmpty() const;

    // Checks if the queue is full
    bool isFull() const;

    // Destructor
    ~PriorityQueue();

private:
    // Resize the internal arrays
    void resize();
};
