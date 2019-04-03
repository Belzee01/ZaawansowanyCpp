#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"

using namespace std;

int main() {
    auto input = new InputBuilder();

    input->withTasks(10)->withProc(4)->withComm(1);

    auto generator = new DAGenerator();

    int** matrix = generator->generate(input->getTasks());

    for (int i = 0; i < input->getTasks(); ++i) {
        for (int j = 0; j < input->getTasks(); ++j) {
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}