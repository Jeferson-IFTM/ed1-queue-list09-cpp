#pragma once

template <typename T>
class Queue {
public:
    virtual ~Queue() = default;
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
};
