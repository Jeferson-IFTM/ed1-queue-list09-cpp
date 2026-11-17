#pragma once

#include "Stack.h"
#include <stdexcept>
#include <vector>

template <typename T>
class ArrayStack : public Stack<T> {
public:
    explicit ArrayStack(int capacity) {
        if (capacity < 0) {
            throw std::invalid_argument("Capacidade negativa");
        }
        items.reserve(capacity);
        limit = capacity;
    }

    void push(const T& item) override {
        if (size() == limit) {
            throw std::overflow_error("Pilha cheia");
        }
        items.push_back(item);
    }

    T pop() override {
        T item = peek();
        items.pop_back();
        return item;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("Pilha vazia");
        }
        return items.back();
    }

    bool isEmpty() const override { return items.empty(); }
    int size() const override { return static_cast<int>(items.size()); }

private:
    std::vector<T> items;
    int limit;
};
