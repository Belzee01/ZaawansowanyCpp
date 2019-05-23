//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Task.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Task task;
        ClassDeclaration() {
            task;
        }
    };
}

TEST_F(ClassDeclaration, shouldRandomizeRangeAndCostForDedicatedProcess) {
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, shouldRandomizeRangeAndCostForUniversalProcess) {
    ASSERT_EQ("", "");
}