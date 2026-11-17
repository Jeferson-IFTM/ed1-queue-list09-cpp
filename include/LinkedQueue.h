#pragma once

#include "Queue.h"
#include <stdexcept>
#include <utility>

template <typename T>
class LinkedQueue : public Queue<T> {
    struct Node {
        T item;
        Node* next;
    };

public:
    LinkedQueue() = default;
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;

    LinkedQueue(LinkedQueue&& other) noexcept
        : head(std::exchange(other.head, nullptr)),
          tail(std::exchange(other.tail, nullptr)),
          count(std::exchange(other.count, 0)) {}

    ~LinkedQueue() override {
        while (!isEmpty()) {
            delete detachFront();
        }
    }

    void push(const T& item) override { append(new Node{item, nullptr}); }

    T pop() override {
        T item = peek();
        delete detachFront();
        return item;
    }

    T peek() const override {
        if (isEmpty()) {
            throw std::underflow_error("Fila vazia");
        }
        return head->item;
    }

    bool isEmpty() const override { return count == 0; }
    int size() const override { return count; }

    void transferFrontTo(LinkedQueue& destination) {
        if (isEmpty()) {
            throw std::underflow_error("Fila vazia");
        }
        destination.append(detachFront());
    }

private:
    Node* detachFront() noexcept {
        Node* node = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        node->next = nullptr;
        --count;
        return node;
    }

    void append(Node* node) noexcept {
        if (tail) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        ++count;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;
};
