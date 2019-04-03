//
// Created by Kajetan Lipensky on 2019-04-03.
//

#include "TasksContainer.h"


template<typename T>
//TODO change proc to list of objects reflecting the type of the process (universal or dedicated)
TasksContainer<T>::TasksContainer(int numberOfTasks, int proc, int **adjustmentMatrix):numberOfTasks(numberOfTasks) {
    this->tasks = new std::list<Task<T>>[numberOfTasks];

    int id = 0;
    for (int i = 0; i < numberOfTasks; ++i) {
        for (int j = 0; j < numberOfTasks; ++j) {
            if (adjustmentMatrix[i][j] == 1)
                this->tasks[id].push_back(new Task<T>(j, proc));
        }
        id++;
    }
}

template<typename T>
TasksContainer<T>::TasksContainer() {

}
