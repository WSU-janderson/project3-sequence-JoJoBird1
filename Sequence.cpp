/**
 * Project 3: Linked Sequence Data Structure
 * Name: Jordan Wilson
 * Sequence.cpp file
 */

#include "Sequence.h"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Method: Sequence(size_t sz)
 * creates an empty sequence (numElts == 0) 
 * or
 * a sequence of numElts items indexed from 0 .. (numElts -1)
 */
Sequence::Sequence(size_t sz) 
    : numElts(sz), headPointer(nullptr), tailPointer(nullptr)
{
    for (int i = 0; i < sz; i++) {
        push_back("");  
    }
}

/**
 * Method: deep copy constructor
 * creates a deep copy of sequence s
 */
Sequence::Sequence(const Sequence& s)
    : numElts(0), headPointer(nullptr), tailPointer(nullptr)
{
    SequenceNode* curr = s.headPointer;
    while (curr != nullptr) {
        push_back(curr -> item);
        curr = curr -> next;
    }
}

/**
 * Method: ~Sequence
 * destroys all items in the sequence and release the memory associated with the sequence
 */
Sequence::~Sequence() {
    SequenceNode* curr = 
}

/**
 * Method: operator=
 * Current sequence is released and replaced by a (deep) copy of sequence s.
 * A reference to the copied sequence is returned (return *this)
 */
Sequence& Sequence::operator=(const Sequence& s) {

}

/**
 * Method: operator[]
 * Return value is a reference to the item at index position in the sequence.
 * Throws exception if the position is outside the bounds
 */
std::string& Sequence::operator[](size_t position) {

}

/**
 * Method: push back
 * The value of items is appended to the sequence
 */
void Sequence::push_back(std::string item) {

}

/**
 * Method: pop back
 * The items at the end of the sequence is deleted and size of the sequence is
 * reduced by one.
 * If empty, throws exception
 */
void Sequence::pop_back() {

}

/**
 * Method: insert
 * the value of item is inserted at position, size of sequence increases by one.
 * If position is outside the bounds of the sequence throws exception
 */
void Sequence::insert(size_t position, std::string item) {

}

/**
 * Method: front
 * returns the first item in the sequence.
 * if empty, throws an excetion
 */
std::string Sequence::front() const {

}

/**
 * Method: back
 * returns the last item in the sequence
 * is sequence is empty throws an exception
 */
std::string Sequence::back() const {

}

/**
 * Method: empty
 * returns true if the sequence has no items, otherwise false
 */
bool Sequence::empty() const {
    return numElts == 0;
}

/**
 * Method: size
 * return the number of elements in the sequence
 */
size_t Sequence::size() const {
    return numElts;
}

/**
 * Method: clear
 * All items in sequence are deleted and memory associated with sequence is released
 * resetting the sequence to an empty state to re-insert items
 */
void Sequence::clear() {

}

/**
 * Method: erase
 * the item at position is removed from the sequence, and memory is released.
 * if called with invalid position throws an exception
 */
void Sequence::erase(size_t position) {

}

/**
 * Method: erase
 * items in sequence at (position...(position + count - 1)) are deleted and memeory is released
 * if called with invalid position and/or count throws an exception
 */
void Sequence::erase(size_t position, size_t count) {

}
