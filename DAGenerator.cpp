#include "DAGenerator.h"

void DAGenerator::cleanUpMatrix(int nodes, int **matrix) {
    for(int i = 0; i < nodes; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void DAGenerator::randomizeNewConnection(int **matrix, int index) {
    int upperNodeIndex = randomizeFromRange(index - 1, 0);
    matrix[upperNodeIndex][index] = 1;
}

void DAGenerator::coverIsolatedNode(const int nodes, int **matrix) {
    std::list<int> indexes;
    for (int i = 1; i < nodes; ++i) {
        int sum = 0;
        for (int j = 0; j < nodes; ++j) {
            sum += matrix[j][i];
        }
        if (sum < 1) {
            randomizeNewConnection(matrix, i);
        }
    }
}

int **DAGenerator::randomizeConnections(const int nodes, int **matrix, const std::map<int, std::list<int>> &levels) {
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

std::map<int, std::list<int>> DAGenerator::randomizeLevels(int nodes) {
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

int **DAGenerator::initializeMatrix(int rows) {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[rows];
        for (int j = 0; j < rows; ++j) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

DAGenerator::~DAGenerator() {

}
