#ifndef TEST_1_DAGENERATOR_H
#define TEST_1_DAGENERATOR_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include <map>
#include <list>

#define EDGE_PERCENTAGE 40;

using namespace std;

class DAGenerator {
private:
    int **initializeMatrix(int rows);

    std::map<int, std::list<int>> randomizeLevels(int nodes);

private:
    int randomizeFromRange(int max, int min) {
        return rand() % (max - min + 1) + min;
    }

    bool isEdge() {
        return randomizeFromRange(100, 0) < EDGE_PERCENTAGE;
    }

    int **randomizeConnections(const int nodes, int **matrix, const std::map<int, std::list<int>> &levels);

    void coverIsolatedNode(const int nodes, int **matrix);

    void randomizeNewConnection(int **matrix, int index);

    void cleanUpMatrix(int nodes, int** matrix);

public:
    DAGenerator() {
        srand(time(nullptr));
    };

    virtual ~DAGenerator();

    void generate(int nodes) {
        int **adjustmentMatrix = initializeMatrix(nodes);
        auto levels = randomizeLevels(nodes);
        adjustmentMatrix = randomizeConnections(nodes, adjustmentMatrix, levels);

        coverIsolatedNode(nodes, adjustmentMatrix);
        cleanUpMatrix(nodes, adjustmentMatrix);
    }
};


#endif //TEST_1_DAGENERATOR_H
