#include <iostream>
#include "MyPriorityQueue.h"
using namespace std;

int main() {
    MyPriorityQueue<double> d(-3);
    cout << "Initial size: " << d.getSize() << endl;
    cout << "Initial capacity: " << d.getCapacity() << endl;
    MyPriorityQueue<int> pq(3);
    // Inserting values
    pq.insert(10); pq.display();
    pq.insert(5); pq.display();
    pq.insert(20); pq.display();
    pq.insert(15); pq.display(); // causes resize
    pq.insert(25); pq.display();
    pq.insert(2); pq.display();
    MyPriorityQueue<int> copied(pq); // calls copy constructor
    copied.display();
    // Checking max
    cout << "Max element: " << pq.getMax() << endl;
    // Accessing by index
    cout << "Element at index 2: " << pq.at(2) << endl;
    // Deleting max
    cout << "Removing max: " << pq.removeMax() << endl; pq.display();
    cout << "Removing max: " << pq.removeMax() << endl; pq.display();
    cout << "Removing max: " << pq.removeMax() << endl; pq.display();
    // Contains test
    cout << "Contains 15? " << (pq.contains(15) ? "Yes" : "No") << endl;
    cout << "Contains 2? " << (pq.contains(2) ? "Yes" : "No") << endl;
    // Clear test
    pq.clear();
    pq.display();
    cout << "Size after clear: " << pq.getSize() << endl;
    cout << "Capacity after clear: " << pq.getCapacity() << endl;
    cout << "Size of the copy: " << copied.getSize() << endl;
    return 0;
}
