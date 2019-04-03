//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_TASK_H
#define TEST_1_TASK_H

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

public:

    Task(int id);

    Task(int id, int proc);


};


#endif //TEST_1_TASK_H
