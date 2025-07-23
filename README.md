# CS3304_Assignment2
CS 3304 – Data and Information Structures Assignment 2

**Submission:** Submit your solutions as a single .zip file through Canvas. The .zip file must
contain: MyPriorityQueue.h and MyPriorityQueueDriver.cpp (driver demonstrating test cases
and sample output)

In this assignment, you will implement your own priority queue template class named
MyPriorityQueue, storing elements in a dynamic array and maintaining the maximum element
at the front of the array (similar to a max-heap top). Since this class will be a template class,
you should include the function definitions at the end of the header file. You can also check the
Stack example in Chapter 9.
The class must use a generic dynamic array (T* myArray) with two integer attributes mySize and
myCapacity. You must maintain the array such that the first element is always the maximum of
the list.

**a. (10 pts) Constructor**
Create a constructor that accepts an integer for capacity. If the parameter is not positive, set it
to 5. Initialize mySize to 0 and dynamically allocate the array.

**b. (5 pts) Getters**
Write getSize() and getCapacity() methods to return current size and capacity.

**c. (20 pts) insert**
Add a new element to the array and re-order the array to ensure the maximum element is
moved to index 0.
If capacity is full:
• Double the capacity
• Allocate a new array and copy existing elements
• Add the new element
• Delete old array
• Update myCapacity

**d. (5 pts) getMax**
Return the maximum element. Throw an exception if the list is empty.

**e. (20 pts) removeMax**
Remove the maximum element (always at index 0).
After removal:
• Shift all elements to the left
• Find the next maximum and move it to index 0
Return the removed element.

**f. (10 pts) display**
Print elements in order, comma-separated, from index 0 to mySize - 1.

**g. (5 pts) at**
Return the element at the specified index or throw an exception if out of range.

**h. (10 pts) contains**
Return true if a given element is present in the queue, false otherwise.

**i. (5 pts) clear**
Reset the queue by setting mySize to 0.

**j. (5 pts) Destructor**
Implement a destructor that properly deallocates any dynamically allocated memory to prevent
memory leaks.

**k. (5 pts) Copy Constructor**
Write a copy constructor that performs a deep copy. This means:
• Allocate a new array of the same capacity.
• Copy all existing elements from the source object into this new array.
• Ensure mySize and myCapacity are copied correctly.
• Do not share the same myArray pointer between objects.
