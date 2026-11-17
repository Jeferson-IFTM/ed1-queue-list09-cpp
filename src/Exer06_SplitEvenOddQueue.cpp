#include "LinkedQueue.h"
#include <sstream>
#include <string>

void splitEvenOdd(LinkedQueue<int>& queue, LinkedQueue<int>& evens, LinkedQueue<int>& odds) {
    while (!queue.isEmpty()) {
        const int item = queue.pop();
        LinkedQueue<int>& destination = item % 2 == 0 ? evens : odds;
        destination.push(item);
    }
}

void runExer06(std::istream& input, std::ostream& output) {
    std::string line;
    std::getline(input, line);
    LinkedQueue<int> queue;
    std::istringstream values(line);
    for (int value; values >> value;) {
        queue.push(value);
    }
    LinkedQueue<int> evens;
    LinkedQueue<int> odds;
    splitEvenOdd(queue, evens, odds);
    while (!evens.isEmpty()) {
        output << evens.pop();
        if (!evens.isEmpty()) {
            output << ' ';
        }
    }
    output << '\n';
    while (!odds.isEmpty()) {
        output << odds.pop();
        if (!odds.isEmpty()) {
            output << ' ';
        }
    }
    output << '\n';
}
