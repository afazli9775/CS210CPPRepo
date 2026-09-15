#include <iostream>
#include "Stack.h"

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Stack size: " << s.size() << std::endl;
    std::cout << "Top value: " << s.peek() << std::endl;

    std::cout << "Popped: " << s.pop() << std::endl;

    std::cout << "Top after pop: " << s.peek() << std::endl;
    std::cout << "Stack size after pop: " << s.size() << std::endl;

    if (s.isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    return 0;
}