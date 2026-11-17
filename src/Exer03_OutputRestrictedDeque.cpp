#include "ArrayQueue.h"
#include <sstream>
#include <string>

void runExer03(std::istream& input, std::ostream& output) {
    std::string line;
    std::getline(input, line);
    std::istringstream capacityInput(line);
    int capacity = 0;
    for (int value; capacityInput >> value;) {
        ++capacity;
    }
    ArrayQueue<int> queue(capacity);
    std::istringstream values(line);
    for (int value; values >> value;) {
        queue.push(value);
    }
    std::getline(input, line);
    std::istringstream commands(line);
    bool first = true;
    for (char command; commands >> command;) {
        if (command != 'F' && command != 'B') {
            throw std::invalid_argument("Use F para inicio ou B para fim");
        }
        const int item = command == 'F' ? queue.pop() : queue.popBack();
        if (!first) {
            output << ' ';
        }
        output << item;
        first = false;
    }
    output << '\n';
}
