#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int capacity, Relation rel) {
    if (capacity <= 0) {
        throw std::exception("Capacity must be a positive integer!");
    }
    this->head = 0;
    this->rel = rel;
    this->capacity = capacity;
    this->size = 0;
    this->free_space = 0;

    this->elements = new Element[this->capacity];
    this->pozitions = new int[this->capacity];

    for (int i = 0; i < this->capacity - 1; ++i) {
        this->elements[i] = NULL_TELEM;
        this->pozitions[i] = i + 1;
    }

    this->elements[this->capacity - 1] = NULL_TELEM;
    this->pozitions[this->capacity - 1] = -1;
}

void PriorityQueue::push(TElem e, TPriority p) {
    if (isFull()) {
        throw std::exception("PriorityQueue is full!");
    }

    if (this->elements[this->head].first == -11111) {
        this->elements[this->head] = make_pair(e, p);
        this->pozitions[this->head] = -1;
        this->size++;
        this->free_space = 1;
    }
    else {
        int copy = this->pozitions[free_space];
        int i = this->head, k = -1;
        while (i != -1 && this->rel(this->elements[i].second, p)) {
            k = i;
            i = this->pozitions[i];
        }

        if (i == this->head) {
            this->elements[this->free_space] = make_pair(e, p);
            this->pozitions[this->free_space] = this->head;
            this->head = this->free_space;
            ++this->size;
        }
        else {
            this->elements[this->free_space] = make_pair(e, p);
            this->pozitions[this->free_space] = i;
            this->pozitions[k] = this->free_space;
            ++this->size;
        }

        this->free_space = copy;
    }
}

Element PriorityQueue::top() const {
    if (isEmpty()) {
        throw std::exception("PriorityQueue is empty!");
    }
    return this->elements[this->head];
}

Element PriorityQueue::pop() {
    if (isEmpty()) {
        throw std::exception("PriorityQueue is empty!");
    }

    Element topElement = this->elements[this->head];
    int copy = this->pozitions[this->head];
    this->pozitions[this->head] = this->free_space;
    this->free_space = this->head;
    this->elements[this->head] = NULL_TELEM;
    this->head = copy;

    --this->size;

    return topElement;
}

bool PriorityQueue::isEmpty() const {
    return this->elements[this->head].first == -11111 or this->size == 0;
}

bool PriorityQueue::isFull() const {
    return this->size == this->capacity;
}

PriorityQueue::~PriorityQueue() {
    delete[] this->elements;
    delete[] this->pozitions;
}

void PriorityQueue::resize() {
    this->capacity *= 6;

    Element* newElements = new Element[this->capacity];
    int* newPoz = new int[this->capacity];

    for (int i = 0; i < this->capacity; ++i) {
        newElements[i] = NULL_TELEM;
        newPoz[i] = -1;
    }

    for (int i = 0; i < this->size; i++) {
        newElements[i] = this->elements[i];
        newPoz[i] = this->pozitions[i];
    }
    newPoz[this->free_space] = this->size;
    for (int i = this->size; i < this->capacity - 1; i++) {
        newPoz[i] = i + 1;
    }
    newPoz[this->capacity - 1] = -1;

    delete[] this->pozitions;
    delete[] this->elements;

    this->elements = newElements;
    this->pozitions = newPoz;
}
