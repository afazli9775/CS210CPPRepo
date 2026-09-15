#include "Stack.h"
#include <iostream>

Stack::Stack() {
    topIndex = -1;
}

void Stack::push(int value) {
    if (isFull()) {
        std::cout << "Stack is full." << std::endl;
        return;
    }

    topIndex++;
    data[topIndex] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }

    int value = data[topIndex];
    topIndex--;
    return value;
}

int Stack::peek() const {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }

    return data[topIndex];
}

bool Stack::isEmpty() const {
    return topIndex == -1;
}

bool Stack::isFull() const {
    return topIndex == 99;
}

int Stack::size() const {
    return topIndex + 1;
}