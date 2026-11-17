#include "ArrayQueue.h"
#include <sstream>
#include <string>

void runExer01(std::istream& input, std::ostream& output) {
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
    int removals;
    if (!(input >> removals) || removals < 0 || removals > queue.size()) {
        throw std::invalid_argument("Quantidade de remocoes invalida");
    }
    for (int i = 0; i < removals; ++i) {
        if (i > 0) {
            output << ' ';
        }
        output << queue.pop();
    }
    output << '\n';
    for (int i = 0; i < queue.size(); ++i) {
        if (i > 0) {
            output << ' ';
        }
        output << queue.at(i);
    }
    output << '\n';
}
