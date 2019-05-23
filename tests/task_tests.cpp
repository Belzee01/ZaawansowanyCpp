//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Task.h"

using testing::Eq;

namespace {
    class TasksTests : public testing::Test {
    public:
        TasksTests() {
        }
    };
}

TEST_F(TasksTests, shouldRandomizeRangeAndCostForDedicatedProcess) {
    ASSERT_EQ("", "");
}

TEST_F(TasksTests, shouldRandomizeRangeAndCostForUniversalProcess) {
    ASSERT_EQ("", "");
}