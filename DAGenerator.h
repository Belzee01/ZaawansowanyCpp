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
    int **initializeMatrix(int rows) {
        int **matrix = new int *[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[rows];
            for (int j = 0; j < rows; ++j) {
                matrix[i][j] = 0;
            }
        }
        return matrix;
    }

    std::map<int, std::list<int>> randomizeLevels(int nodes) {
        std::map<int, std::list<int>> levels;
        levels[0].push_back(0);
        nodes--;

        int i = 1;
        int currentIndex = 1;
        while (nodes > 0) {
            long nodesInLevel = random() % nodes + 1;
            nodes -= nodesInLevel;
            for (int j = 0; j < nodesInLevel; ++j) {
                levels[i].push_back(currentIndex++);
            }
        }
        return levels;
    }

    int randomizeFromRange(int max, int min) {
        return rand() % (max - min + 1) + min;
    }

public:
    DAGenerator() {
        srand(time(0));
    };

    void generate(int nodes) {
        int **adjustmentMatrix = initializeMatrix(nodes);
        auto levels = randomizeLevels(nodes);


    }
};


#endif //TEST_1_DAGENERATOR_H
