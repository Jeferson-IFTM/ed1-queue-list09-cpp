#include <exception>
#include <iostream>

void runExer01(std::istream& input, std::ostream& output);
void runExer02(std::istream& input, std::ostream& output);
void runExer03(std::istream& input, std::ostream& output);
void runExer04(std::istream& input, std::ostream& output);
void runExer05(std::istream& input, std::ostream& output);
void runExer06(std::istream& input, std::ostream& output);

int main(int argc, char* argv[]) {
    if (argc != 2 || argv[1][0] < '1' || argv[1][0] > '6' || argv[1][1] != '\0') {
        std::cerr << "Uso: queue_list09 <questao de 1 a 6>\n";
        return 1;
    }

    const auto exercises = {runExer01, runExer02, runExer03, runExer04, runExer05, runExer06};
    const int index = argv[1][0] - '1';
    try {
        exercises.begin()[index](std::cin, std::cout);
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
