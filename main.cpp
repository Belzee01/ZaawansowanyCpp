#include <iostream>
#include "DAGenerator.h"
#include "InputBuilder.h"

using namespace std;

int main() {
    auto input = new InputBuilder();

    input->withTasks(10)->withProc(4)->withComm(1);

    auto generator = new DAGenerator();

    generator->generate(input->getTasks());
}