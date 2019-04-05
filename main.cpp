#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"
#include "TasksContainer.h"

using namespace std;

int main() {
    auto input = new InputBuilder();

    input->withTasks(10)->withProc(4)->withComm(1);

    auto generator = new DAGenerator();

    int **matrix = generator->generate(input->getTasks());

    auto *taskContainer = new TasksContainer<int>(input->getTasks(), input->getProc(), matrix);

    list<Task<int>> *tasksList = taskContainer->getTasks();

    std::cout << "@tasks " << input->getTasks() << std::endl;
    for (int k = 0; k < input->getTasks(); ++k) {
        std::cout << "T(" << k << "): " << tasksList[k].size() << " ";
        for (auto &it : tasksList[k]) {
            std::cout << it.getId() << "(" << it.getWeight() << ")" << ", ";
        }
        std::cout << std::endl;
    }
}