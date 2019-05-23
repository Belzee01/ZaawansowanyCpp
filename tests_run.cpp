#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"
#include "TasksContainer.h"
#include "Process.h"
#include <list>
#include "Communication.h"
#include <fstream>
#include "OutputParser.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

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

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc,argv);
    RUN_ALL_TESTS();

    return 0;
}