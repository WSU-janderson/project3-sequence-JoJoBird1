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
    Sequence t;

    cout << "Test for Push Back Items: " << endl;
    s.push_back("Apples");
    s.push_back("Bananas");
    s.push_back("Carrots");
    s.push_back("Dragonfruit");
    s.push_back("Eggs");
    s.push_back("Fish");
    s.push_back("Grapes");
    s.push_back("Ham");
    t.push_back("Apes");
    t.push_back("Bonobos");
    t.push_back("Camels");
    t.push_back("Eagles");
    t.push_back("Fish");
    t.push_back("Giraffes");
    cout << "Tested Sequence: s " << s << endl;
    cout << "Tested Sequence: t " << t << endl;
    cout << endl;

    cout << "Test for Pop Back Items: " << endl;
    s.pop_back();
    s.pop_back();
    cout << "Tested Sequence: " << s << endl;
    cout << endl;

    cout << "Test for Insert Items: " << endl;
    s.insert(3,"Crackers");
    cout << "Tested Sequence: " << s << endl;
    cout << endl;

    cout << "Test for First Item: " << endl;
    cout << "Tested Sequence: " << s.front() << endl;
    cout << endl;

    cout << "Test for Last Item: " << endl;
    cout << "Tested Sequence: " << s.back() << endl;
    cout << endl;

    cout << "Test for Size: " << endl;
    cout << "Tested Sequence: " << s.size() << endl;
    cout << endl;

    cout << "Test for Erase: " << endl;
    s.erase(3, 2);
    cout << "Tested Sequence: " << s << endl;
    cout << endl;

    cout << "Test for Clear: " << endl;
    s.clear();
    cout << "Tested Sequence: " << s << endl;
    cout << endl;

    cout << "Test for Empty: " << endl;
    cout << "Tested Sequence: " << s.empty() << endl;
    cout << endl;

    cout << "Test for Empty Front: " << endl;
    try {
        cout << s.front() << endl;
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << endl;

    cout << "Test for Empty Back: " << endl;
    try {
        cout << s.back() << endl;
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << endl;

    cout << "Test for Empty Pop Back: " << endl;
    try {
        s.pop_back();
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << endl;


    cout << "Test for Empty Push Back: " << endl;
    s.push_back("Purple");
    cout << "Tested Sequence: " << s << endl;
    cout << endl;

    cout << "Test for Invalid Insert: " << endl;
    try {
        s.insert(3, "No");
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << endl;

    cout << "Test for Invalid Erase: " << endl;
    try {
        s.erase(3);
    }
    catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << endl;

    return 0;
}