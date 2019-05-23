//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../DAGenerator.h"
#include <map>
#include <list>

using testing::Eq;

namespace {
    class GeneratorTests : public testing::Test {
    public:
        GeneratorTests() {
        }
    };
}

TEST_F(GeneratorTests, shouldInitializeMatrix) {
    //given
    int numberOfRows = 3;
    auto generator = new DAGenerator();

    //when
    int **matrix = generator->initializeMatrix(numberOfRows);

    //then
    ASSERT_NE(matrix, nullptr);
    for (int i = 0; i < numberOfRows; ++i) {
        for (int j = 0; j < numberOfRows; ++j) {
            ASSERT_EQ(matrix[i][j], 0);
        }
    }
}

TEST_F(GeneratorTests, shouldRandomizeLevels) {
    //given
    int numberOfNodes = 10;
    auto generator = new DAGenerator();

    //when
    std::map<int, std::list<int>> levels = generator->randomizeLevels(numberOfNodes);

    //then
    ASSERT_GT(levels.size(), 0);
    ASSERT_LT(levels.size(), numberOfNodes + 1);
}

TEST_F(GeneratorTests, shouldFailToRandomizeLevelsWhenInvalidNumberOfNodesPassed) {
    //given
    int numberOfNodes = -1;
    auto generator = new DAGenerator();

    //when
    std::map<int, std::list<int>> levels = generator->randomizeLevels(numberOfNodes);

    //then
    ASSERT_EQ(levels.size(), 1);
}

TEST_F(GeneratorTests, shouldRandomizeFromRangeInclusive) {
    //given
    int min = -1;
    int max = 1;
    auto generator = new DAGenerator();

    //when
    int randomFromRange = generator->randomizeFromRange(max, min);

    //then
    ASSERT_GE(randomFromRange, -1);
    ASSERT_LE(randomFromRange, 1);
}

TEST_F(GeneratorTests, shouldRandomizeConnections) {
    ASSERT_EQ("", "1");
}

TEST_F(GeneratorTests, shouldCoverIsolatedNodes) {
    ASSERT_EQ("", "1");
}

TEST_F(GeneratorTests, shouldRandomizeNewConnectionByIndex) {
    ASSERT_EQ("", "1");
}

TEST_F(GeneratorTests, shouldFailToRandomizeNewConnectionWhenInvalidIndexPassed) {
    ASSERT_EQ("", "1");
}

TEST_F(GeneratorTests, shouldGenerateGraphBasedOnNumberOfNodes) {
    ASSERT_EQ("", "1");
}

TEST_F(GeneratorTests, shouldFailOnGeneratingGraphWhenInvalidNumberOfNodesPassed) {
    ASSERT_EQ("", "1");
}