/* John Candler
 * CS3304 Assignment 2
 *
 * https://github.com/28Candler62/CS3304_Assignment2
 * Compiler command:
 * see makefile
 *
 *  ## MyPriorityQueue.h ##
*/

#include <cassert>
#include <iostream>
#include <new>
#include <string>

template <typename T>
class MyPriorityQueue {
public: // Function members
    // -- Constructor
    MyPriorityQueue(int capacity);
    // -- Copy Constructor
    MyPriorityQueue(const MyPriorityQueue<T> & original);

    // -- Getters
    int getSize();

    int getCapacity();

    T getMax();

    T at(int index);

    T removeMax();

    // -- Setters
    void insert(T insrt);

    // -- Output
    void display() const;

    // -- Utility
    bool contains(T c);

    void clear();

    // -- Deconstructor
    ~MyPriorityQueue();

private: // Data mambers
    int mySize, myCapacity;
    T * myArray;

};

// -- Definition of constructor
template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(int capacity)
{
    if (capacity > 0)
    {
	myCapacity = capacity; // set capacity
	mySize = 0; // set size to 0
	myArray = new(std::nothrow) T[myCapacity]; // allocate array
    }
}

// -- Definition of copy constructor
template <typename T>
MyPriorityQueue<T>::MyPriorityQueue(const MyPriorityQueue<T> & original)
:mySize(original.mySize), myCapacity(original.myCapacity)
{
    myArray = new(std::nothrow) T[myCapacity]; // allocate the copy's array
    for (int i = 0; i <= mySize; i++)
	myArray[i] = original.myArray[i]; // copy elements to copy
}

// -- Defenition of destructor
template <typename T>
MyPriorityQueue<T>::~MyPriorityQueue()
{
    delete[] myArray;
}

// -- Defenition of getSize()
template <typename T>
int  MyPriorityQueue<T>::getSize()
{
    return mySize;
}

// -- Definition of getCapacity()
template <typename T>
int  MyPriorityQueue<T>::getCapacity()
{
    return myCapacity;
}

// Definition of getMax()
template <typename T>
T  MyPriorityQueue<T>::getMax()
{
    return myArray[0];
}

// Definition of at()
template <typename T>
T  MyPriorityQueue<T>::at(int i)
{
    assert(i <= mySize); // throw an exception if out of range
    assert(i >= 0); // throw an exception if out of range
    return myArray[i];
}

// Definition of removeMax()
template <typename T>
T MyPriorityQueue<T>::removeMax()
{
    T newMax = myArray[1];
    int newMaxIdx = 1;
    T value = myArray[0];
    for (int i = 2; i < mySize; i++)
	if (myArray[i] > newMax){
	    newMax = myArray[i];
	    newMaxIdx = i;
	}
    myArray[0] = newMax; // move new max to index 0
    for (int i = newMaxIdx + 1; i < mySize; i++)
	myArray[i-1] = myArray[i]; // left shift elements after new max
    mySize -= 1; //decrement mySize
    return value;
}

// Definition of insert()
template <typename T>
void MyPriorityQueue<T>::insert(T insrt)
{
    if(mySize == myCapacity){ // resize if required
	int capacity = myCapacity * 2;
	T * iArray = new(std::nothrow) T[capacity]; // allocate the copy's array
        for (int i = 0; i <= mySize; i++)
	    iArray[i] = myArray[i]; // copy elements to copy
	delete[] myArray;
	myArray = iArray;
	myCapacity = capacity;
    }
    if(insrt <= myArray[0]){
	myArray[mySize] = insrt; // append queue if new item is less than max
    } else {
	for (int i = mySize; i > 0; i--)
	    myArray[i] = myArray[i - 1]; // right shift
	myArray[0] = insrt; // new item set as max
    }
    mySize += 1; // increment size
}

// Definition of display()
template <typename T>
void MyPriorityQueue<T>::display() const
{
    std::cout << "[";
    for (int i = 0; i < mySize; i++)
	std::cout << myArray[i] << ",";
    std::cout << "]" << std::endl;
}

// Definition of contains()
template <typename T>
bool MyPriorityQueue<T>::contains(T c)
{
    bool value = false;
    for (int i =0; i < mySize; i++)
	if (c == myArray[i])
	    value = true;
    return value;
}

// Definition of clear()
template <typename T>
void MyPriorityQueue<T>::clear()
{
    mySize = 0;
}
