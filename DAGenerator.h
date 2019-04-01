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
            long nodesInLevel = rand() % nodes + 1;
            nodes -= nodesInLevel;
            for (int j = 0; j < nodesInLevel; ++j) {
                levels[i].push_back(currentIndex++);
            }
            i++;
        }
        return levels;
    }

    int randomizeFromRange(int max, int min) {
        return rand() % (max - min + 1) + min;
    }

    bool isEdge() {
        return randomizeFromRange(100, 0) < EDGE_PERCENTAGE;
    }

    int **randomizeConnections(const int nodes, int **matrix, const std::map<int, std::list<int>> &levels) {
        int **matrixCopy = matrix;
        for (int i = 1; i < levels.size(); i++) {
            auto topLevel = levels.at(i - 1);
            for (auto &tl:topLevel) {
                const auto &lowerLevel = levels.at(i);
                for (auto &ll:lowerLevel) {
                    if (isEdge()) {
                        matrixCopy[tl][ll] = 1;
                    }
                }
            }
        }
        return matrixCopy;
    }

    void coverIsolatedNode(const int nodes, int **matrix) {
        std::list<int> indexes;
        for (int i = 1; i < nodes; ++i) {
            int sum = 0;
            for (int j = 0; j < nodes; ++j) {
                sum += matrix[j][i];
            }
            if (sum < 1) {
                std::cout << "Isolated node: " << i << std::endl;
                randomizeNewConnection(matrix, i);
            }
        }
    }

    void randomizeNewConnection(int **matrix, int index) {
        int upperNodeIndex = randomizeFromRange(index - 1, 0);
        matrix[upperNodeIndex][index] = 1;
    }

public:
    DAGenerator() {
        srand(time(nullptr));
    };

    void generate(int nodes) {
        int **adjustmentMatrix = initializeMatrix(nodes);
        auto levels = randomizeLevels(nodes);
        adjustmentMatrix = randomizeConnections(nodes, adjustmentMatrix, levels);

        std::cout << "Levels: " << levels.size() << std::endl;

        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                std::cout << adjustmentMatrix[i][j] << " ";
            }
            std::cout << endl;
        }
        coverIsolatedNode(nodes, adjustmentMatrix);
        std::cout << std::endl;
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                std::cout << adjustmentMatrix[i][j] << " ";
            }
            std::cout << endl;
        }
    }
};


#endif //TEST_1_DAGENERATOR_H
