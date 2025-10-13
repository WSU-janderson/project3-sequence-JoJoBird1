/**
 * Project 3: Linked Sequence Data Structure
 * CS - 3100: Data Structures
 * Name: Jordan Wilson
 * Classes: Sequence & SequenceNode
 */

#ifndef CLASSES_SEQUENCE_H
#define CLASSES_SEQUENCE_H

#include <string> // for strings
#include <cstddef> // for size_t
#include <stdexcept> // for exceptions

/**
 * Class: Sequence
 */
class Sequence {
// private variables
private: 
size_t numElts;
SequenceNode* headPointer;
SequenceNode* tailPointer;

// public variables 
public:

// constructors
Sequence(size_t = 0); // constructor
Sequence(const Sequence& s); // copy constructor
~Sequence(); // de-constructor
Sequence& operator=(const Sequence& s); // copy assignment operator

std::string& operator[](size_t position); // access to non-const items
const std::string& operator[](size_t position) const // access to const items

// getters
std::string front() const; // return first item in the sequence, if empty throw exception
std::string back() const; // return the last item in the sequence, if empty throw exception
bool empty() const; // return true if the sequence has no items
size_t size() const; //return the items in the sequence

// list void methods in Sequence.cpp
void push_back(std::string item); // item is appended to the sequence
void pop_back(); // item at the end is deleted
void insert(size_t position, std:: string item); // if position satisfies, item is inserted at position
void clear(); // all items in sequence are deleted and memory associated is released, reset to empty
void erase(size_t position); // item removed and memory release, if called with invalid position throws an exception
void erase(size_t position, size_t count); // items in sequence are deleted and memory released, throws exception if invalid

// Friend Function. Allows access to private data. Prints items as a string to output
friend ostream& operator<<(ostream& os, const Sequence& s);

};

/**
 * Class: SequenceNode
 * 
 */
class SequenceNode {
    // public variables
    public: 
    SequenceNode* next; // pointer to the next Node. If node is the tail, next is nullptr
    SequenceNode* prev; // point to the previous Node. If node is the head, prev is nullptr
    std:: string item; // the element being stored in the node

    // default constructor, ensure next and prev are nullptr
    SequenceNode() : next(nullptr), prev(nullptr) {}

    // parameterized constructor, next and prev are set to nullptr and 
    // the node's element  is set to the given value
    SequenceNode(std::string item) : next(nullptr), prev(nullptr), item(item) {

    }
};