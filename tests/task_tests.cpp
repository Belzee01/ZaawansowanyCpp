//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Task.h"
#include "../Process.h"
#include <map>
#include <list>

using testing::Eq;

namespace {
    class TasksTests : public testing::Test {
    public:
        TasksTests() {

        }
    };
}

TEST_F(TasksTests, shouldRandomizeRangeAndCostForDedicatedProcess) {
    //given
    Process process1(0);
    std::list<Process> processes;
    processes.push_back(process1);

    //when
    Task<int> task(0, processes);
    task.randomizeTimeAndCost();

    //then
    ASSERT_GT(task.getTimes()[0], DEDICATED_TIME_MIN);
    ASSERT_LT(task.getTimes()[0], DEDICATED_TIME_MAX);
    ASSERT_GT(task.getCosts()[0], DEDICATED_COST_MIN);
    ASSERT_LT(task.getCosts()[0], DEDICATED_COST_MAX);
}

TEST_F(TasksTests, shouldRandomizeRangeAndCostForUniversalProcess) {
    Process process1(1);
    std::list<Process> processes;
    processes.push_back(process1);

    //when
    Task<int> task(0, processes);
    task.randomizeTimeAndCost();

    //then
    ASSERT_GT(task.getTimes()[0], UNIVERSAL_TIME_MIN);
    ASSERT_LT(task.getTimes()[0], UNIVERSAL_TIME_MAX);
    ASSERT_GT(task.getCosts()[0], UNIVERSAL_COST_MIN);
    ASSERT_LT(task.getCosts()[0], UNIVERSAl_COST_MAX);
}