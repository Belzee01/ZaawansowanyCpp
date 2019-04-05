#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"
#include "TasksContainer.h"
#include "Process.h"
#include <list>
#include "Communication.h"

using namespace std;

class CommunicationGenerator {
private:
    Communication *comms;

public:
    CommunicationGenerator(int commSize, int procSize) {
        comms = new Communication[commSize];

        for (int i = 0; i < commSize; ++i) {
            comms[i] = *new Communication(procSize);
        }
        Communication::coverNoConnections(comms, commSize, procSize);
    };

    Communication *getComms() const {
        return comms;
    }
};

class ProcessesGenerator {
private:
    std::list<Process> processes;

public:
    explicit ProcessesGenerator(int proc) {
        for (int j = 0; j < proc; ++j) {
            processes.emplace_back(j % 2 == 0.0 ? 1 : 0);
        }
    };

    const list<Process> &getProcesses() const {
        return processes;
    }
};

int main() {
    auto input = new InputBuilder();

    input->withTasks(10)->withProc(4)->withComm(3);

    auto generator = new DAGenerator();
    auto matrix = generator->generate(input->getTasks());

    auto processGenerator = ProcessesGenerator(input->getProc());
    auto processes = processGenerator.getProcesses();

    auto communicationGenerator = CommunicationGenerator(input->getComm(), input->getProc());
    auto comms = communicationGenerator.getComms();

    auto taskContainer = new TasksContainer<int>(input->getTasks(), processes, matrix);
    auto tasksList = taskContainer->getTasks();

    ////WYPISYWANIE ------////////
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
                std::cout << it.getTimes()[i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "@costs " << std::endl;
    for (int k = 0; k < input->getTasks(); ++k) {
        for (auto &it : tasksList[k]) {
            for (int i = 0; i < input->getProc(); ++i) {
                std::cout << it.getCosts()[i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "@comm " << input->getComm() << std::endl;
    for (int k = 0; k < input->getComm(); ++k) {
        std::cout << "CHAN" << k << "\t" << comms[k].getCapacity() << "\t" << comms[k].getCost() << "\t";
        for (int i = 0; i < input->getProc(); ++i) {
            std::cout << comms[k].getProcConnections()[i] << " ";
        }
        std::cout << std::endl;
    }
}