#pragma once

typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111

class SortedSetIterator;

class SortedSet {
    friend class SortedSetIterator;
private:
    Relation r;
    TElem* table;
    int capacity;
    int size_;
    int hash1(TComp e) const;
    int hash2(TComp e) const;
    int doubleHash(TComp e, int i) const;
    void resizeAndRehash();

public:
    SortedSet(Relation r);
    bool add(TComp e);
    bool remove(TComp e);
    bool search(TElem elem) const;
    int size() const;
    bool isEmpty() const;
    SortedSetIterator iterator() const;
    ~SortedSet();
};
