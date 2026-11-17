#include <stack>
#include <sstream>
#include <string>
#include <stdexcept>

class StackBasedQueue {
public:
    void push(int item) { inStack.push(item); }

    int pop() {
        const int item = peek();
        outStack.pop();
        return item;
    }

    int peek() {
        if (isEmpty()) {
            throw std::underflow_error("Fila vazia");
        }
        if (outStack.empty()) {
            // Cada elemento passa para a pilha de saida uma unica vez.
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    bool isEmpty() const { return inStack.empty() && outStack.empty(); }

private:
    std::stack<int> inStack;
    std::stack<int> outStack;
};

void runExer02(std::istream& input, std::ostream& output) {
    std::string line;
    std::getline(input, line);
    std::istringstream commands(line);
    StackBasedQueue queue;
    bool first = true;
    for (int command; commands >> command;) {
        if (command > 0) {
            queue.push(command);
            continue;
        }
        if (command != -1 && command != -2) {
            throw std::invalid_argument("Comando invalido");
        }

        const int item = command == -1 ? queue.pop() : queue.peek();
        if (!first) {
            output << ' ';
        }
        output << item;
        first = false;
    }
    output << '\n';
}
