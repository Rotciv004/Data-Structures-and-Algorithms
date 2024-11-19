#include "Bag.h"
#include "BagIterator.h"
#include <algorithm>
#include <iostream>

Bag::Bag(int max) {
    this->capacity = max; // Initial capacity
    length_U = 0;
    length_P = 0;
    U = new TElem[this->capacity];
    P = new TElem[this->capacity];
}

/*Best Case: O(1) - When the bag is created with a specific capacity.
Worst Case: O(n) - When the bag is created with a capacity that needs resizing, requiring dynamic memory allocation and copying elements.
Total Case: O(n)*/

Bag::~Bag() {
    delete[] U;
    delete[] P;
}

/*Best Case: O(1) - When there's no resizing involved.
Worst Case: O(1) - When there's no resizing involved.
Total Case: O(1)*/

void Bag::resize() {
    this->capacity *= 2; // Double the capacity
    TElem* newU = new TElem[this->capacity];
    TElem* newP = new TElem[this->capacity];
    for (int i = 0; i < length_U; i++) {
        newU[i] = U[i];
    }
    for (int i = 0; i < length_P; i++) {
        newP[i] = P[i];
    }
    delete[] U;
    delete[] P;
    U = newU;
    P = newP;
}

/*Best Case: O(n) - When resizing is not needed.
Worst Case: O(n) - When resizing is needed, requiring copying elements to the new arrays.
Total Case: O(n)*/

void Bag::add(TElem e) {
    if (length_P == this->capacity-1)
        resize();

    int position = findPosition(e);

    if (position != -1) {
        P[length_P] = position;
        length_P++;
    }
    else 
    {
        P[length_P] = length_U;
        U[length_U] = e;
        length_P++;
        length_U++;
    }
    std::cout << length_P << " ";
    std::cout << length_U << " ";
}
/*Best Case: O(1) - When there's enough capacity and no resizing is required.
Worst Case: O(n) - When resizing is required, and all elements need to be copied to the new arrays.
Total Case: O(n)*/

bool Bag::remove(TElem e) {
    int pos = this->findPosition(e);

    if (pos == -1)
        return false;
    else
    {
        for (int i = 0; i < length_P; ++i)
            if (P[i] == pos)
            {
                for (int j = i; j < length_P - 1; ++j)
                    P[j] = P[j + 1];

                --length_P;

                break;
            }

        bool existance = false;

        for (int i = 0; i < length_P; ++i)
            if (P[i] == pos)
                existance = true;

        if (!existance)
        {
            for (int i = pos; i < length_U - 1; ++i)
                U[i] = U[i + 1];

            for (int i = 0; i < length_P; ++i)
                if (P[i] > pos)
                    --P[i];

            --length_U;


        }

        return true;
    }
}

/*Best Case: O(1) - When the element to be removed is at the beginning of the array.
Worst Case: O(n) - When the element to be removed is at the end of the array, requiring shifting elements.
Total Case: O(n)*/

bool Bag::search(TElem e) const {
    for (int i = 0; i < length_U; ++i)
        if (e == U[i])
            return true;

    return false;
}
/*Best Case: O(1) - When the element is found at the beginning.
Worst Case: O(n) - When the element is found at the end or not found.
Total Case: O(n)*/

int Bag::nrOccurrences(TElem e) const {
    int position = findPosition(e);
    int count = 0;

    for (int i = 0; i < length_P; ++i)
        if (P[i] == position)
            ++count;

    return count;
}
/*Best Case: O(1) - When the element is not present.
Worst Case: O(n) - When the element is present multiple times or at the end.
Total Case: O(n)*/

int Bag::size() const {
    return length_P;
}
/*Best Case: O(1) - When the size is stored as a separate variable and updated on each operation.
Worst Case: O(1) - Same as best case.
Total Case: O(1)*/

bool Bag::isEmpty() const {
    return length_P == 0;
}
/*Best Case: O(1) - When the size is checked against 0.
Worst Case: O(1) - Same as best case.
Total Case: O(1)*/

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}
/*Best Case: O(1) - When creating an iterator object.
Worst Case: O(1) - Same as best case.
Total Case: O(1)*/

int Bag::findPosition(TElem e) const {
    for (int i = 0; i < length_U; i++) {
        if (U[i] == e)
            return i;
    }
    return -1;
}
/*Best Case: O(1) - When the element is found at the beginning.
Worst Case: O(n) - When the element is found at the end or not found.
Total Case: O(n)*/
int Bag::toSet()
{
    int number_of_deleted_TElems = 0;
    int* elements_list;

    elements_list = new int[length_P];

    for (int i = 0; i < length_P; ++i)
        elements_list[i] = 0;

    for (int i = 0; i < length_P; ++i)
        if (elements_list[i] == 0)
            elements_list[i] = 1;
        else
        {
            for (int j = i; j < length_P - 1; ++j)
                P[j] = P[j + 1];

            --length_P;

            --i;

            ++number_of_deleted_TElems;
        }

    delete[] elements_list;

    return number_of_deleted_TElems;
}
/*Best Case: O(n) - When there are no duplicates.
Worst Case: O(n^2) - When all elements are duplicates, and for each element, all subsequent elements need to be shifted.
Total Case: O(n^2)*/
