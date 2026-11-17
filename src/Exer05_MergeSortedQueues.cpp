#include "LinkedQueue.h"
#include <sstream>
#include <string>

LinkedQueue<int> mergeTwoQueues(LinkedQueue<int>& left, LinkedQueue<int>& right) {
    LinkedQueue<int> merged;
    while (!left.isEmpty() && !right.isEmpty()) {
        LinkedQueue<int>& source = left.peek() <= right.peek() ? left : right;
        source.transferFrontTo(merged);
    }
    while (!left.isEmpty()) {
        left.transferFrontTo(merged);
    }
    while (!right.isEmpty()) {
        right.transferFrontTo(merged);
    }
    return merged;
}

void runExer05(std::istream& input, std::ostream& output) {
    LinkedQueue<int> left;
    LinkedQueue<int> right;
    std::string line;
    std::getline(input, line);
    std::istringstream leftValues(line);
    for (int value; leftValues >> value;) {
        left.push(value);
    }
    std::getline(input, line);
    std::istringstream rightValues(line);
    for (int value; rightValues >> value;) {
        right.push(value);
    }
    auto merged = mergeTwoQueues(left, right);
    while (!merged.isEmpty()) {
        output << merged.pop();
        if (!merged.isEmpty()) {
            output << ' ';
        }
    }
    output << '\n';
}
