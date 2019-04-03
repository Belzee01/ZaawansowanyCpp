//
// Created by Kajetan Lipensky on 2019-04-03.
//

#include "InputBuilder.h"


InputBuilder::~InputBuilder() {

}

InputBuilder::InputBuilder() : tasks(0), proc(0), comm(0) {}

int InputBuilder::getTasks() const {
    return tasks;
}

int InputBuilder::getProc() const {
    return proc;
}

int InputBuilder::getComm() const {
    return comm;
}
