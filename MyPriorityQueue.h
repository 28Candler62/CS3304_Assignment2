/* John Candler
 * CS3304 Assignment 2
 *
 * https://github.com/28Candler62/CS3304_Assignment2
 * Compiler command:
 * see makefile
 *
 *  ## MyPriorityQueue.h ##
*/

#include <iostream>
#include <string>

template <typename T>
class MyPriorityQueue {
public: // Function members
    // -- Constructor
    MyPriorityQueue::MyPriorityQueue();

    // -- Getters
    MyPriorityQueue::getSize();

    MyPriorityQueue::getCapacity();

    MyPriorityQueue::getMax();

    MyPriorityQueue::at();

    // -- Setters
    MyPriorityQueue::insert();

    MyPriorityQueue::removeMax();

    // -- Output
    MyPriorityQueue::display();

    // -- Utility
    MyPriorityQueue::contains();

    MyPriorityQueue::clear();

    // -- Deconstructor
    MyPriorityQueue::~MyPriorityQueue();


    

private: // Data mambers

};
