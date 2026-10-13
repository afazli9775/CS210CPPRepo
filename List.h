#pragma once
#include <iostream>
#include <memory>

template <typename T>
class List {
public:
    virtual ~List() = default;
    virtual void addFront(T* value) = 0;
    virtual void deleteFront() = 0;
    virtual bool search(const T* value) const = 0;
    virtual void print() const = 0;
    virtual void addAnywhere(int position, T* value) = 0;
    virtual void deleteAnywhere(int position) = 0;
    virtual void reverse() = 0;
    virtual void concat(List<T>* other) = 0;
};

// Change this one line to use ArrayList<T> instead of LinkedList<T>.
// The factory is defined after including the concrete implementations below.
template <typename T>
std::unique_ptr<List<T>> makeList();

#include "ArrayList.h"
#include "LinkedList.h"

template <typename T>
std::unique_ptr<List<T>> makeList() {
    return std::unique_ptr<List<T>>(new LinkedList<T>());
    // To test ArrayList instead, replace the line above with:
    // return std::unique_ptr<List<T>>(new ArrayList<T>());
}
