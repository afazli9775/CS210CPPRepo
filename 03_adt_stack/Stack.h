#pragma once

class Stack {
public:
    Stack();
    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;

private:
    int data[100];
    int topIndex;
};