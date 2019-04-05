//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_PROCESS_H
#define TEST_1_PROCESS_H

template<typename T>
class Process {
public:
    T initialCost;

    int typeOfProcess; // 1 dedicated, 0 universal

    Process(T initialCost, int typeOfProcess) : initialCost(initialCost), typeOfProcess(typeOfProcess) {}

    T getInitialCost() const {
        return initialCost;
    }

    int getTypeOfProcess() const {
        return typeOfProcess;
    }
};


#endif //TEST_1_PROCESS_H
