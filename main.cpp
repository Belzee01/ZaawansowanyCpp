#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"
#include "TasksContainer.h"
#include "Process.h"
#include <list>
#include "Communication.h"

using namespace std;

int main() {
    auto input = new InputBuilder();

    input->withTasks(10)->withProc(4)->withComm(1);

    std::list<Process> processes;
    for (int j = 0; j < input->getProc(); ++j) {
        processes.emplace_back(j % 2 == 0.0 ? 1 : 0);
    }

    auto generator = new DAGenerator();
    int **matrix = generator->generate(input->getTasks());
    auto *taskContainer = new TasksContainer<int>(input->getTasks(), processes, matrix);

    auto comms = new Communication[input->getComm()];
    comms[0] = *new Communication(input->getProc());
    Communication::coverNoConnections(comms, input->getComm(), input->getProc());

    list<Task<int>> *tasksList = taskContainer->getTasks();

    std::cout << "@tasks " << input->getTasks() << std::endl;
    for (int k = 0; k < input->getTasks(); ++k) {
        std::cout << "T" << k << ": " << tasksList[k].size() << " ";
        for (auto &it : tasksList[k]) {
            std::cout << it.getId() << "(" << it.getWeight() << ")" << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "@proc " << input->getProc() << std::endl;
    for (auto &p : processes) {
        std::cout << p.getInitialCost() << " " << p.getBandWith() << " " << p.getTypeOfProcess() << std::endl;
    }

    std::cout << "@times " << std::endl;
    for (int k = 0; k < input->getTasks(); ++k) {
        for (auto &it : tasksList[k]) {
            for (int i = 0; i < input->getProc(); ++i) {
                std::cout << it.getTimes()[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "@costs " << std::endl;
    for (int k = 0; k < input->getTasks(); ++k) {
        for (auto &it : tasksList[k]) {
            for (int i = 0; i < input->getProc(); ++i) {
                std::cout << it.getCosts()[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "@comm " << input->getComm() << std::endl;
    int j = 0;
    for (int k = 0; k < input->getComm(); ++k) {
        std::cout << "CHAN" << k << " " << comms[j].getCapacity() << " " << comms[j].getCost() << " ";
        for (int i = 0; i < input->getProc(); ++i) {
            std::cout << comms[j].getProcConnections()[i] << " ";
        }
        std::cout << std::endl;
        j++;
    }
}