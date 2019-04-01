#include <iostream>
#include "DAGenerator.h"

using namespace std;

int main() {
    auto generator = new DAGenerator();

    generator->generate(10);
}