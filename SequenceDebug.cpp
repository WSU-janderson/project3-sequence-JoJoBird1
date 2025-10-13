/**
 * Project 3: Linked Sequence Data Structure
 * CS-3100: Data Structures
 * Name: Jordan Wilson
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    Sequence s;

    cout << "Test for: Push Back Items" << endl;
    s.push_back("Apples");
    s.push_back("Bananas");
    s.push_back("Carrots");
    s.push_back("Dragonfruit");
    s.push_back("Eggs");
    s.push_back("Fish");
    s.push_back("Grapes");
    s.push_back("Ham");

    cout << "Tested Sequence: " << s << endl;

    return 0;
}