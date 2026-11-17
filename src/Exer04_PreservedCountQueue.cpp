#include "LinkedQueue.h"
#include <sstream>
#include <string>

int countPreservingQueue(LinkedQueue<int>& queue, int target) {
    const int initialSize = queue.size();
    int occurrences = 0;
    for (int i = 0; i < initialSize; ++i) {
        const int item = queue.pop();
        if (item == target) {
            ++occurrences;
        }
        queue.push(item);
    }
    return occurrences;
}

void runExer04(std::istream& input, std::ostream& output) {
    std::string line;
    std::getline(input, line);
    LinkedQueue<int> queue;
    std::istringstream values(line);
    for (int value; values >> value;) {
        queue.push(value);
    }
    int target;
    if (!(input >> target)) {
        throw std::invalid_argument("Informe o valor a contar");
    }
    output << countPreservingQueue(queue, target) << '\n';
}
