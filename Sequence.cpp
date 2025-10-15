/**
 * Project 3: Linked Sequence Data Structure
 * CS- 3100: Data Structures
 * Name: Jordan Wilson
 * Sequence.cpp file
 *
 * Implementation for Sequence class, which is a doubly linked list.
 * Stores a sequence of strings, insertion, removal, erasing, and adding
 */

#include "Sequence.h"
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Method: Sequence(size_t sz)
 * Creates an empty sequence and initialized with an empty string of elements
 */
Sequence::Sequence(size_t sz) 
    : numElts(sz), headPointer(nullptr), tailPointer(nullptr)
{
    for (size_t i = 0; i < sz; i++) {           // For loop. starting from 0 to 1 less than sz increment
        push_back("");                  // add empty strings
    }
}

/**
 * Method: deep copy constructor
 * creates a deep copy of sequence
 * each node in s is copied into a new sequence
 */
Sequence::Sequence(const Sequence& s)
    : numElts(0), headPointer(nullptr), tailPointer(nullptr)
{
    SequenceNode* curr = s.headPointer;         // temporary pointer called curr (current) starting at firs node in s
    while (curr != nullptr) {                   // While Loop. runs until curr == nullptr (beginning - end)
        push_back(curr->item);              // push back. copies current nodes data from list & creates a new node with that data
        curr = curr->next;                     // moves temp pointer curr to the next node
    }
}

/**
 * Method: ~Sequence
 * destroys all items in the sequence and release the memory associated with the sequence
 */
Sequence::~Sequence() {
    while (headPointer != nullptr) {                   // While Loop. runs until headPointer == nullptr
        SequenceNode* newPointer = headPointer;        // Temporary pointer newPointer, points to current first node
        headPointer = headPointer->next;               // Moves temp pointer to next node, skipping node about to delete
        delete newPointer;                             // deallocates the node, freeing the memory that newPointer was pointing to
    }
}

/**
 * Method: operator=
 * Current sequence is released and replaced by a (deep) copy of sequence s.
 * A reference to the copied sequence is returned (return *this)
 */
Sequence& Sequence::operator=(const Sequence& s) {
    if (this != &s) {                                   // prevents same object assignment
        SequenceNode* curr = headPointer;              //  Temporary pointer curr pointing to start of sequence

        while (curr != nullptr) {                      // While Loop. runs until curr == nullptr
            SequenceNode* newPointer = curr;           // Temporary pointer newPointer pointing to curr
            curr = curr->next;                         // moves curr to the next node
            delete newPointer;                         // deallocates the node, freeing the memory that newPointer was pointing at
        }

        // Resets
        headPointer = nullptr;
        tailPointer = nullptr;
        numElts = 0;

        SequenceNode* other = s.headPointer;            // Temporary pointer other starting at sequence s
        while (other != nullptr) {                      // While Loop. runs until other == nullptr
            push_back (other->item);                //push back appending each item from s to current sequence
            curr = other->next;                        // moves curr to next node
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
    if (position >= numElts) {                                  // If condition. position is greater than or equal to numElts
        throw std::out_of_range("Index out of Bounds.");      // throw out of range exception message
    }

    SequenceNode* curr = headPointer;                           // Temporary pointer curr starting at headPointer
    for (size_t i = 1; i < position; i++) {                     // For Loop. starting a 1 run until one less than position, increment
        curr = curr->next;                                      // move curr to next node
    }
    return curr->item;                                          // return value that curr is at
}

/**
 * Method: push back
 * The value of items is appended to the sequence
 */
void Sequence::push_back(std::string item) {
    SequenceNode* newNode = new SequenceNode(item);         // Temporary pointer newNode

    if (headPointer == nullptr) {                              // If Condition. headPointer == nullptr
        headPointer = newNode;                                 // then headPointer = newNode
        tailPointer = newNode;                                 // and tailPointer = newNode
    }

    else {                                                      // Else.
        tailPointer->next = newNode;                            // tailPointer value = newNode
        newNode->prev = tailPointer;                            // newNode previous pointer set to current tail
        tailPointer = newNode;                                  // update tailPointer to new last node
    }
    numElts++;                                                  // increments the count of elements in list
}

/**
 * Method: pop back
 * The items at the end of the sequence is deleted and size of the sequence is
 * reduced by one.
 * If empty, throws exception
 */
void Sequence::pop_back() {
    if (headPointer == nullptr) {                               // If Condition. headPointer == nullptr
        throw std::out_of_range("The Sequence is Empty.");    // then throw out of range exception message
    }

    else if (headPointer == tailPointer) {                      // Else If Condition. headPointer == tailPointer
        delete tailPointer;                                     // deallocates the node, freeing the memory that tailPointer was pointing at
        headPointer = nullptr;                                  // reset headPointer to nullptr
        tailPointer = nullptr;                                  // reset tailPointer to nullptr
    }

    else {                                                      // Else
        SequenceNode* oldTail = tailPointer;                    // Temporary pointer oldTail stores current last node
        tailPointer = tailPointer->prev;                        // moves tailPointer to second to last node
        tailPointer->next = nullptr;                            // disconnects oldTail pointer from list to prepare for deletion
        delete oldTail;                                         // deallocates the node, freeing the memory that oldTail was pointing at
    }
    numElts--;                                                  // Decrements the number of elements in numElts
}

/**
 * Method: insert
 * the value of item is inserted at position, size of sequence increases by one.
 * If position is outside the bounds of the sequence throws exception
 */
void Sequence::insert(size_t position, std::string item) {
    if (position >= numElts) {                                          // If Condition. position is greater than or equal to numElts
        throw std::out_of_range("Position is out of Range.");         // Then throw out of range exception message
    }

    SequenceNode* newNode = new SequenceNode(item);                 // Temporary pointer newNode

    if (position == 0) {                                               // If Condition. position == 0
        newNode->next = headPointer;                                   // then value that newNode is pointing at is headPointer

        if (headPointer != nullptr) {                                  // Inner If Condition. headPointer is not nullptr
            headPointer->prev = newNode;                               // then headPointer previous node set to newNode
        }

        headPointer = newNode;                                          // sets headPointer to newNode

        if (tailPointer == nullptr) {                                   // If Condition. tailPointer == nullptr
            tailPointer = newNode;                                      // then tailPointer is newNode
        }
    }
    else if (position == numElts) {                                     // Else If Condition. position == numElts
        newNode->prev = tailPointer;                                    // then newNode's previous pointer points to current tail
        tailPointer->next = newNode;                                    // current tailPointer points forward to newNode
        tailPointer = newNode;                                          // updates tailPointer to last node
    }
    else {                                                              // Else
        SequenceNode* curr = headPointer;                               // Temporary pointer curr set to headPointer
        for (size_t i = 0; i < position; i++) {                         // For Loop. starts at 0 in size_t, runs while one less than position, increments
            curr = curr->next;                                          // move curr to next node
        }

        newNode->next = curr;                                           // newNode points to forward to curr
        newNode->prev = curr->prev;                                     // newNode previous points to curr previous node
        curr->prev->next = newNode;                                     // previous node points to newNode
        curr->prev = newNode;                                           // previous curr pointer points back to new node
    }
    numElts++;                                                          // increments the number of elements in numElts
}

/**
 * Method: front
 * returns the first item in the sequence.
 * if empty, throws an excetion
 */
std::string Sequence::front() const {
    if (headPointer == nullptr) {                                   // If Condition. headPointer == nullptr
        throw std::out_of_range("The Sequence is Empty.");        // then throw out of range exception message
    }
    return headPointer->item;                                   // return value where headPointer is at
}

/**
 * Method: back
 * returns the last item in the sequence
 * is sequence is empty throws an exception
 */
std::string Sequence::back() const {
    if (tailPointer == nullptr) {                               // If Condition. tailPointer == nullptr
        throw std::out_of_range("The Sequence is Empty.");    // then throw out of range exception message
    }
    return tailPointer->item;                               // return value where tailPointer is at
}

/**
 * Method: empty
 * returns true if the sequence has no items, otherwise false
 */
bool Sequence::empty() const {
    return headPointer == nullptr && tailPointer == nullptr;        //  Return head and tail pointers as nullptrs
}

/**
 * Method: size
 * return the number of elements in the sequence
 */
size_t Sequence::size() const {
    return numElts;                         // Return the number of elements in numElts
}

/**
 * Method: clear
 * All items in sequence are deleted and memory associated with sequence is released
 * resetting the sequence to an empty state to re-insert items
 */
void Sequence::clear() {
    SequenceNode* curr = headPointer;                       // Temporary pointer curr starting at headPointer

    while (curr != nullptr) {                               // While Loop. runs until curr == nullptr
        SequenceNode* newPointer = curr->next;              // Temporary pointer newPointer moves to next node to prepare current node for deletion
        delete curr;                                        // deallocates the node, freeing the memory that curr was pointing at
        curr = newPointer;                                  // curr is set to newPointer
    }

    // Resets
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
        if (position >= numElts) {                                      // If Condition. position is greater than or equal to numElts
        throw std::out_of_range("The Position is out of Bounds.");      // throw out of range excetion message
    }

    SequenceNode* curr = headPointer;                                   // Temporary pointer curr starts at headPointer
    for (size_t i = 0; i < position; i++) {                             // For Loop. starting i = 0, runs till i is one less than position, increments
        curr = curr->next;                                              // moves curr forward to the node at index
    }

    if (curr->next != nullptr) {                                        // If Condition. curr not the last node
        curr->next->prev = curr->prev;                                  // then, update to skip curr
    }
    else {                                                              // Else
        tailPointer = curr->prev;                                       // update tailPointer to previous node
    }

    if (curr->prev != nullptr) {                                        // If Condition. curr previous node is not nullptr
        curr->prev->next = curr->next;                                  // then, updated to skip curr
    }
    else {                                                              // Else
        headPointer = curr->next;                                       // updates headPointer to next node
    }

    delete curr;                                                        // deallocates the node, freeing the memory that curr was pointing at
    numElts--;                                                          // decrements the number in numElts
}

/**
 * Method: erase
 * items in sequence at (position...(position + count - 1)) are deleted and memeory is released
 * if called with invalid position and/or count throws an exception
 */
void Sequence::erase(size_t position, size_t count) {
    if (position >= numElts || position + count >= numElts) {                          // If Condition. position is greater than or equal to numElts OR position plus count is greater than or equal to numElts
        throw std::out_of_range("The position and/or the count is out of bounds.");     // then, throw out of range exception message
    }

    for (size_t i = 0; i < count; i++) {                                                // For Loop. start at i = 0, runs until one less than count, increments
        erase(position);                                                                // removes node at specified index
    }
}


ostream& operator<<(ostream& os, const Sequence& s) {
    os << "< ";
    SequenceNode* curr = s.headPointer;                     // Temporary pointer curr at head of s
    while (curr != nullptr) {                               // While Loop. runs until curr == nullptr
        os << curr->item;                                   // prints item stored in node

        if (curr->next != nullptr) {                        // If Condition. if not the last node
            os << ", ";                                     // prints a comma
        }
        curr = curr->next;                                  // moves curr to the next node
    }
    os << " >";
    return os;                                              // returns os
}