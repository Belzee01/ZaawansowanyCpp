//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../InputBuilder.h"

using testing::Eq;

namespace {
    class InputBuilderTests : public testing::Test {
    public:
        InputBuilderTests() {
        }
    };
}

TEST_F(InputBuilderTests, shouldProperlySetValuesForInput) {
    //given
    InputBuilder builder;

    //when
    builder.withComm(1)->withProc(2)->withTasks(3);

    //then
    ASSERT_EQ(builder.getComm(), 1);
    ASSERT_EQ(builder.getProc(), 2);
    ASSERT_EQ(builder.getTasks(), 3);
}