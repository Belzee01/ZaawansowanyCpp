//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_TASK_H
#define TEST_1_TASK_H

#include<iostream>
#include<cstdlib>
#include<ctime>

template<typename T=int>
class Task {
private:
    int id;
    T weight;

    int proc;
    T *times;
    T *costs;

private:
    T randomizeTime();

    T randomizeCost();

    int randomizeFromRange(int max, int min) {
        return rand() % (max - min + 1) + min;
    }

public:

    Task(int id);

    Task(int id, int proc) : proc(proc), id(id) {
        this->costs = new T[proc];
        this->times = new T[proc];
        this->weight = 0;
        srand(time(0));
    }

    int getId() const {
        return id;
    }

    T getWeight() const {
        return weight;
    }

    int getProc() const {
        return proc;
    }

    T *getTimes() const {
        return times;
    }

    T *getCosts() const {
        return costs;
    }
};


#endif //TEST_1_TASK_H
