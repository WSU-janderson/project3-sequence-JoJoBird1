/**
 * Project 3: Linked Sequence Data Structure
 * CS- 3100: Data Structures
 * Name: Jordan Wilson
 * Sequence.cpp file
 */

#include "Sequence.h"
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
    for (size_t i = 0; i < sz; i++) {
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
        push_back(curr->item);
        curr = curr->next;
    }
}

/**
 * Method: ~Sequence
 * destroys all items in the sequence and release the memory associated with the sequence
 */
Sequence::~Sequence() {
    while (headPointer != nullptr) {
        SequenceNode* newPointer = headPointer;
        headPointer = headPointer->next;
        delete newPointer;
    }
}

/**
 * Method: operator=
 * Current sequence is released and replaced by a (deep) copy of sequence s.
 * A reference to the copied sequence is returned (return *this)
 */
Sequence& Sequence::operator=(const Sequence& s) {
    if (this != &s) {
        SequenceNode* curr = headPointer;

        while (curr != nullptr) {
            SequenceNode* newPointer = curr;
            curr = curr->next;
            delete newPointer;
        }

        headPointer = nullptr;
        tailPointer = nullptr;
        numElts = 0;

        SequenceNode* other = s.headPointer;
        while (other != nullptr) {
            push_back (other->item);
            curr = other->next;
        }
    }
    return *this;
}

/**
 * Method: operator[]
 * Return value is a reference to the item at index position in the sequence.
 * Throws exception if the position is outside the bounds
 */
std::string& Sequence::operator[](size_t position) {
    if (position >= numElts) {
        throw std::out_of_range("Index out of Bounds.");
    }

    SequenceNode* curr = headPointer;
    for (size_t i = 1; i < position; i++) {
        curr = curr->next;
    }
    return curr->item;
}

/**
 * Method: push back
 * The value of items is appended to the sequence
 */
void Sequence::push_back(std::string item) {
    SequenceNode* newNode = new SequenceNode(item);

    if (headPointer == nullptr) {
        headPointer = newNode;
        tailPointer = newNode;
    }

    else {
        tailPointer->next = newNode;
        newNode->prev = tailPointer;
        tailPointer = newNode;
    }
    numElts++;
}

/**
 * Method: pop back
 * The items at the end of the sequence is deleted and size of the sequence is
 * reduced by one.
 * If empty, throws exception
 */
void Sequence::pop_back() {
    if (headPointer == nullptr) {
        throw std::out_of_range("The Sequence is Empty.");
    }

    else if (headPointer == tailPointer) {
        delete tailPointer;
        headPointer = nullptr;
        tailPointer = nullptr;
    }

    else {
        SequenceNode* oldTail = tailPointer;
        tailPointer = tailPointer->prev;
        tailPointer->next = nullptr;
        delete oldTail;
    }
    numElts--;
}

/**
 * Method: insert
 * the value of item is inserted at position, size of sequence increases by one.
 * If position is outside the bounds of the sequence throws exception
 */
void Sequence::insert(size_t position, std::string item) {
    if (position >= numElts) {
        throw std::out_of_range("Position is out of Range.");
    }

    SequenceNode* newNode = new SequenceNode(item);

    if (position == 0) {
        newNode->next = headPointer;

        if (headPointer != nullptr) {
            headPointer->prev = newNode;
        }

        headPointer = newNode;

        if (tailPointer == nullptr) {
            tailPointer = newNode;
        }
    }
    else if (position == numElts) {
        newNode->prev = tailPointer;
        tailPointer->next = newNode;
        tailPointer = newNode;
    }
    else {
        SequenceNode* curr = headPointer;
        for (size_t i = 0; i < position; i++) {
            curr = curr->next;
        }

        newNode->next = curr;
        newNode->prev = curr->prev;
        curr->prev->next = newNode;
        curr->prev = newNode;
    }
    numElts++;
}

/**
 * Method: front
 * returns the first item in the sequence.
 * if empty, throws an excetion
 */
std::string Sequence::front() const {
    if (headPointer == nullptr) {
        throw std::out_of_range("The Sequence is Empty.");
    }
    return headPointer->item;
}

/**
 * Method: back
 * returns the last item in the sequence
 * is sequence is empty throws an exception
 */
std::string Sequence::back() const {
    if (tailPointer == nullptr) {
        throw std::out_of_range("The Sequence is Empty.");
    }
    return tailPointer->item;
}

/**
 * Method: empty
 * returns true if the sequence has no items, otherwise false
 */
bool Sequence::empty() const {
    return headPointer == nullptr && tailPointer == nullptr;
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
    SequenceNode* curr = headPointer;

    while (curr != nullptr) {
        SequenceNode* newPointer = curr->next;
        delete curr;
        curr = newPointer;
    }

    headPointer = nullptr;
    tailPointer = nullptr;
    numElts = 0;
}

/**
 * Method: erase
 * the item at position is removed from the sequence, and memory is released.
 * if called with invalid position throws an exception
 */
void Sequence::erase(size_t position) {
        if (position >= numElts) {
        throw std::out_of_range("The Position is out of Bounds.");
    }

    SequenceNode* curr = headPointer;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }

    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    else {
        tailPointer = curr->prev;
    }

    if (curr->prev != nullptr) {
        curr->prev->next = curr->next;
    }
    else {
        headPointer = curr->next;
    }

    delete curr;
    numElts--;
}

/**
 * Method: erase
 * items in sequence at (position...(position + count - 1)) are deleted and memeory is released
 * if called with invalid position and/or count throws an exception
 */
void Sequence::erase(size_t position, size_t count) {
    if (position >= numElts || position + count >= numElts) {
        throw std::out_of_range("The position and/or the count is out of bounds.");
    }

    for (size_t i = 0; i < count; i++) {
        erase(position);
    }
}


ostream& operator<<(ostream& os, const Sequence& s) {
    os << "< ";
    SequenceNode* curr = s.headPointer;
    while (curr != nullptr) {
        os << curr->item;

        if (curr->next != nullptr) {
            os << ", ";
        }
        curr = curr->next;
    }
    os << " >";
    return os;
}