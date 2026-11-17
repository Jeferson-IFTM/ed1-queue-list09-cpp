#pragma once

#include "Stack.h"
#include <forward_list>
#include <stdexcept>

template <typename T>
class LinkedStack : public Stack<T> {
public:
    void push(const T& item) override {
        items.push_front(item);
        ++count;
    }

    T pop() override {
        T item = peek();
        items.pop_front();
        --count;
        return item;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("Pilha vazia");
        }
        return items.front();
    }

    bool isEmpty() const override { return items.empty(); }
    int size() const override { return count; }

private:
    std::forward_list<T> items;
    int count = 0;
};
