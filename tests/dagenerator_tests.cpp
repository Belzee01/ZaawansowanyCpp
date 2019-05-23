//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../DAGenerator.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        DAGenerator generator;
        ClassDeclaration() {
            generator;
        }
    };
}

TEST_F(ClassDeclaration, shouldInitializeMatrix) {
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, shouldRandomizeLevels) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldFailToRandomizeLevelsWhenInvalidNumberOfNodesPassed) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldRandomizeFromRange) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldRandomizeConnections) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldCoverIsolatedNodes) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldRandomizeNewConnectionByIndex) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldFailToRandomizeNewConnectionWhenInvalidIndexPassed) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldGenerateGraphBasedOnNumberOfNodes) {
    ASSERT_EQ("", "1");
}

TEST_F(ClassDeclaration, shouldFailOnGeneratingGraphWhenInvalidNumberOfNodesPassed) {
    ASSERT_EQ("", "1");
}