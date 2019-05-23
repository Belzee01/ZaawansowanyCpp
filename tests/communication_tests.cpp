//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Communication.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Communication communication;
        ClassDeclaration() {
            communication;
        }
    };
}

TEST_F(ClassDeclaration, shouldCoverConnectionsWhenThereIsNoConnections) {
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, shouldNotCoverConnectionsWithNoMissingConnections) {
    ASSERT_EQ("", "");
}