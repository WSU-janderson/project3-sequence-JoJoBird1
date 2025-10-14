/**
 * Project 3: Linked Sequence Data Structure
 * CS-3100: Data Structures
 * Name: Jordan Wilson
 *
 * Created Sequence objects and made a range of test to ensure that everything was implemented correctly.
 * Including tested with an empty string.
 */
#include <iostream>
#include "Sequence.h"

using namespace std;

/**
 * Main Function
 * @return value to operating system
 */
int main() {
    // Sequence Objects s, t
    Sequence s;
    Sequence t;

    cout << "Test for Push Back Items: " << endl;           // Test for pushing back items to both s and t
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
    cout << "Tested Sequence: s " << s << endl;             // Prints out list of item to s object
    cout << "Tested Sequence: t " << t << endl;            // Prints out list of items to t object
    cout << endl;

    cout << "Test for Pop Back Items: " << endl;            // Test for popping las 2 items on object s
    s.pop_back();
    s.pop_back();
    cout << "Tested Sequence: " << s << endl;               // Prints out list of items left on object s
    cout << endl;

    cout << "Test for Insert Items: " << endl;              // Test for inserting items on object s
    s.insert(3,"Crackers");                 // Inserts Crackers to object s
    cout << "Tested Sequence: " << s << endl;              // Prints out new list of items on object s
    cout << endl;

    cout << "Test for First Item: " << endl;               // Test for first item in object s
    cout << "Tested Sequence: " << s.front() << endl;      // Prints out the first item in object s
    cout << endl;

    cout << "Test for Last Item: " << endl;                 // Test for last item in object s
    cout << "Tested Sequence: " << s.back() << endl;        // Prints out the last item in object s
    cout << endl;

    cout << "Test for Size: " << endl;                      // Test for the size of object s
    cout << "Tested Sequence: " << s.size() << endl;        // Prints out the number of items in object s
    cout << endl;

    cout << "Test for Erase: " << endl;                     // Test to erase items in object s
    s.erase(3, 2);                             // Erases 2 items in object s at index 3
    cout << "Tested Sequence: " << s << endl;               // Prints out the remaining items in object s
    cout << endl;

    cout << "Test for Clear: " << endl;                     // Test to clear out all items in object s
    s.clear();                                              // Clears items in object s
    cout << "Tested Sequence: " << s << endl;               // Prints out empty list for object s
    cout << endl;

    cout << "Test for Empty: " << endl;                     // Test to see if object s is empty
    cout << "Tested Sequence: " << s.empty() << endl;       // Prints out a 1 since object s is empty
    cout << endl;

    cout << "Test for Empty Front: " << endl;               // Test for first item in empty object s
    try {
        cout << s.front() << endl;                          // Try to print first item in object s
    }
    catch (out_of_range e) {                                // Since empty, Catch out of range exception
        cout << e.what() << endl;                           // Prints out exception message
    }
    cout << endl;

    cout << "Test for Empty Back: " << endl;                // Test for last item in empty object s
    try {
        cout << s.back() << endl;                           // Try to print last item in object s
    }
    catch (out_of_range e) {                                // Since empty, Catch out of range exception
        cout << e.what() << endl;                          // Prints out exception message
    }
    cout << endl;

    cout << "Test for Empty Pop Back: " << endl;            // Test for pop back on empty object s
    try {
        s.pop_back();                                       // Try to pop back on object s
    }
    catch (out_of_range e) {                                // Since empty, Catch out of range message
        cout << e.what() << endl;                          // Prints out exception message
    }
    cout << endl;


    cout << "Test for Empty Push Back: " << endl;           // Test for push back on empty object s
    s.push_back("Purple");                          // Push back item value purple
    cout << "Tested Sequence: " << s << endl;               // Prints out new item in object s
    cout << endl;

    cout << "Test for Invalid Insert: " << endl;            // Test for invalid Insertion on Object s
    try {
        s.insert(3, "No");                  // Try to insert item value No to position 3
    }
    catch (out_of_range e) {                               // Since out of range, Catch it
        cout << e.what() << endl;                          // Print out exception message
    }
    cout << endl;

    cout << "Test for Invalid Erase: " << endl;            // Test for Invalid Erase on object s
    try {
        s.erase(3);                                 // Try to erase position 3
    }
    catch (out_of_range e) {                                // Since out of range, Catch it
        cout << e.what() << endl;                           // Print out exception message
    }
    cout << endl;

    return 0;
}