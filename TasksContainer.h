//
// Created by Kajetan Lipensky on 2019-04-03.
//

#ifndef TEST_1_TASKSCONTAINER_H
#define TEST_1_TASKSCONTAINER_H

#include "Task.h"
#include <list>

using namespace std;

template<typename T>
class TasksContainer {
private:
    int numberOfTasks;
    std::list<Task<T>> *tasks;

public:
    TasksContainer();

    TasksContainer(int numberOfTasks, int proc, int **adjustmentMatrix);
};


#endif //TEST_1_TASKSCONTAINER_H
