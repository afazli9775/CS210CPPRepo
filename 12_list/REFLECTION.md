# Reflection

## 1. What is the difference between an ArrayList and a LinkedList?
An ArrayList stores its elements in an array, while a LinkedList stores elements in separate nodes connected by pointers. The ArrayList has a fixed capacity in this project, while the LinkedList can grow by adding new nodes.

## 2. Why do we use an abstract List class?
The abstract List class gives both ArrayList and LinkedList the same interface. This allows the program to use either implementation without changing the code in main.cpp.

## 3. What does addFront() do in each implementation?
In the ArrayList, addFront() shifts the existing elements to the right and puts the new element at index 0. In the LinkedList, it creates a new node and makes that node the new head of the list.

## 4. Why is memory management important in this project?
The program uses pointers and dynamically allocated objects, so the memory must be released when it is no longer needed. Using delete correctly prevents memory leaks.

## 5. What did you learn from this lab?
I learned how ArrayList and LinkedList can perform the same operations using different internal structures. I also learned more about templates, inheritance, pointers, and dynamic memory in C++.