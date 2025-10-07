#include "Sequence.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sequence::Sequence(size_t sz = 0) 
    : 
{
    
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