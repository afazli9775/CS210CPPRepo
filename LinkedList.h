#pragma once
#include "List.h"
#include "Node.h"
#include <iostream>

template <typename T>
class LinkedList : public List<T> {
private:
    Node<T>* head_ = nullptr;
    int size_ = 0;

public:
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* old = head_;
            head_ = head_->next;
            delete old->data;
            delete old;
        }
    }

    void addFront(T* value) override {
        Node<T>* node = new Node<T>(value);
        node->next = head_;
        head_ = node;
        ++size_;
    }

    void deleteFront() override {
        deleteAnywhere(0);
    }

    bool search(const T* value) const override {
        if (value == nullptr) return false;
        for (Node<T>* current = head_; current != nullptr; current = current->next) {
            if (*current->data == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (Node<T>* current = head_; current != nullptr; current = current->next) {
            std::cout << *current->data << ",";
        }
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid insertion position." << std::endl;
            delete value; // ownership is not transferred on failure
            return;
        }
        if (position == 0) {
            addFront(value);
            return;
        }
        Node<T>* previous = head_;
        for (int i = 0; i < position - 1; ++i) previous = previous->next;
        Node<T>* node = new Node<T>(value);
        node->next = previous->next;
        previous->next = node;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid deletion position." << std::endl;
            return;
        }
        if (position == 0) {
            Node<T>* old = head_;
            head_ = head_->next;
            delete old->data;
            delete old;
            --size_;
            return;
        }
        Node<T>* previous = head_;
        for (int i = 0; i < position - 1; ++i) previous = previous->next;
        Node<T>* target = previous->next;
        previous->next = target->next;
        delete target->data;
        delete target;
        --size_;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head_ = previous;
    }

    void concat(List<T>* other) override {
        auto* typedOther = dynamic_cast<LinkedList<T>*>(other);
        if (typedOther == nullptr) {
            std::cout << "concat failed: list representations do not match." << std::endl;
            return;
        }
        if (typedOther == this) {
            std::cout << "concat failed: cannot concatenate a list with itself." << std::endl;
            return;
        }
        if (typedOther->head_ == nullptr) return;

        if (head_ == nullptr) {
            head_ = typedOther->head_;
        } else {
            Node<T>* tail = head_;
            while (tail->next != nullptr) tail = tail->next;
            tail->next = typedOther->head_;
        }
        size_ += typedOther->size_;
        typedOther->head_ = nullptr;
        typedOther->size_ = 0;
    }
};
