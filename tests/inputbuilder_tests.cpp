//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../InputBuilder.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        InputBuilder builder;
        ClassDeclaration() {
            builder;
        }
    };
}

TEST_F(ClassDeclaration, shouldProperlySetValuesForInput) {
    ASSERT_EQ("", "");
}