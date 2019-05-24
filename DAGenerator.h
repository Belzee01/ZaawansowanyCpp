//
// Created by Kajetan Lipensky on 2019-04-05.
//

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
    int nodes;
    int **adjustmentMatrix;

public:
    std::map<int, std::list<int>> randomizeLevels(int nodes);

    int randomizeFromRange(int max, int min) {
        if ((max - min + 1) < 1)
            return rand() % (1) + min;
        return rand() % (max - min + 1) + min;
    }

    bool isEdge() {
        return randomizeFromRange(100, 0) < EDGE_PERCENTAGE;
    }

    void randomizeConnections(const std::map<int, std::list<int>> &levels);

    void coverIsolatedNode();

    void randomizeNewConnection(int index);

    void cleanUpMatrix();

    int **initializeMatrix(int rows);

    DAGenerator();

    DAGenerator(int nodes, int **adjustmentMatrix);

    virtual ~DAGenerator();

    int **generate(int nodes);

    int **getAdjustmentMatrix() const;

    void setAdjustmentMatrix(int **adjustmentMatrix);
};


#endif //TEST_1_DAGENERATOR_H
