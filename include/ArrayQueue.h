#pragma once

#include "Queue.h"
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class ArrayQueue : public Queue<T> {
public:
    explicit ArrayQueue(int capacity) {
        if (capacity < 0) {
            throw std::invalid_argument("Capacidade negativa");
        }
        items.reserve(capacity);
        limit = capacity;
    }

    void push(const T& item) override {
        if (size() == limit) {
            throw std::overflow_error("Fila cheia");
        }
        items.push_back(item);
    }

    T pop() override {
        T item = peek();
        // A remocao desloca cada elemento restante uma posicao a esquerda.
        for (int i = 1; i < size(); ++i) {
            items[i - 1] = std::move(items[i]);
        }
        items.pop_back();
        return item;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::underflow_error("Fila vazia");
        }
        T item = items.back();
        items.pop_back();
        return item;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("Fila vazia");
        }
        return items.front();
    }

    T at(int index) const { return items.at(index); }

    bool isEmpty() const override { return items.empty(); }
    int size() const override { return static_cast<int>(items.size()); }

private:
    std::vector<T> items;
    int limit;
};
