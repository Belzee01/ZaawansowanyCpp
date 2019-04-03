
#include "Task.h"

template<typename T>
Task<T>::Task(int id, int proc):proc(proc), id(id) {
    this->costs = new T[proc];
    this->times = new T[proc];
}

template<typename T>
Task<T>::Task(int id):id(id) {

}
