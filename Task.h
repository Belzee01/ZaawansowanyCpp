//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_TASK_H
#define TEST_1_TASK_H

template <typename T>
class Task {
private:
    int id;
    T weight;

    int proc;
    T* times;
    T* costs;
public:

    Task(int id);

    Task(int id, int proc);


};


#endif //TEST_1_TASK_H
