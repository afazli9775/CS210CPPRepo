#pragma once
#include "List.h"
#include <iostream>
#include <utility>

template <typename T>
class ArrayList : public List<T> {
private:
    static constexpr int CAPACITY = 1000;
    T* items_[CAPACITY]{};
    int size_ = 0;

public:
    ~ArrayList() override {
        for (int i = 0; i < size_; ++i) {
            delete items_[i];
        }
    }

    void addFront(T* value) override {
        addAnywhere(0, value);
    }

    void deleteFront() override {
        deleteAnywhere(0);
    }

    bool search(const T* value) const override {
        if (value == nullptr) return false;
        for (int i = 0; i < size_; ++i) {
            if (*items_[i] == *value) return true;
        }
        return false;
    }

    void print() const override {
        for (int i = 0; i < size_; ++i) std::cout << *items_[i] << ",";
        std::cout << std::endl;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid insertion position." << std::endl;
            delete value; // ownership is not transferred on failure
            return;
        }
        if (size_ >= CAPACITY) {
            std::cout << "ArrayList capacity exceeded." << std::endl;
            delete value;
            return;
        }
        for (int i = size_; i > position; --i) {
            items_[i] = items_[i - 1];
        }
        items_[position] = value;
        ++size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid deletion position." << std::endl;
            return;
        }
        delete items_[position];
        for (int i = position; i < size_ - 1; ++i) {
            items_[i] = items_[i + 1];
        }
        items_[size_ - 1] = nullptr;
        --size_;
    }

    void reverse() override {
        int left = 0;
        int right = size_ - 1;
        while (left < right) {
            std::swap(items_[left], items_[right]);
            ++left;
            --right;
        }
    }

    void concat(List<T>* other) override {
        auto* typedOther = dynamic_cast<ArrayList<T>*>(other);
        if (typedOther == nullptr) {
            std::cout << "concat failed: list representations do not match." << std::endl;
            return;
        }
        if (typedOther == this) {
            std::cout << "concat failed: cannot concatenate a list with itself." << std::endl;
            return;
        }
        if (size_ + typedOther->size_ > CAPACITY) {
            std::cout << "concat failed: insufficient ArrayList capacity." << std::endl;
            return;
        }
        for (int i = 0; i < typedOther->size_; ++i) {
            items_[size_ + i] = typedOther->items_[i];
            typedOther->items_[i] = nullptr;
        }
        size_ += typedOther->size_;
        typedOther->size_ = 0;
    }
};
