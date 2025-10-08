/**
 * Project 3: Linked Sequence Data Structure
 * Name: Jordan Wilson
 * 
 */

#ifndef CLASSES_SEQUENCE_H
#define CLASSES_SEQUENCE_H

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