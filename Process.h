//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_PROCESS_H
#define TEST_1_PROCESS_H

template <typename T>
class Process {
public:
    T cost;

    Process(T cost) : cost(cost) {}

    T getCost() const {
        return cost;
    }
};


#endif //TEST_1_PROCESS_H
