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
    ASSERT_EQ("", "");
}