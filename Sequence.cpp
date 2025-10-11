#include "Sequence.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sequence::Sequence(size_t sz = 0) 
    : numElts(sz), headPointer(nullptr), tailPointer(nullptr)
{
    for (int i = 0; i < sz; i++) {
        push_back("");  
    }
}

// creates a (deep) copy of Sequence s
Sequence::Sequence(const Sequence& s)
    : numElts(0), headPointer(nullptr), tailPointer(nullptr)
{
    SequenceNode* curr = s.headPointer;
    while (curr != nullptr) {
        push_back(curr -> item);
        curr = curr -> next;
    }
}

// Destroys all items in the sequence and release the memory associated with the sequence
Sequence::~Sequence()

// Return the number of elements in the sequence
size_t Sequence::size() const {
    return numElts;
}

// Return true if the sequence has no elements, otherwise false
bool Sequence::empty() const {
    return numElts == 0;
}