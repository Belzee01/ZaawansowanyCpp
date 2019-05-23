//
// Created by Kajetan Lipensky on 2019-05-22.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Communication.h"

using testing::Eq;

namespace {
    class CommunicationTests : public testing::Test {
    public:
        CommunicationTests() {
        }
    };
}

TEST_F(CommunicationTests, shouldCoverConnectionsWhenThereIsNoConnections) {
    //given
    const int procSize = 3;
    const int commSize = 2;
    int procConnections1[procSize] = {0, 1, 0};
    int procConnections2[procSize] = {0, 0, 1};
    Communication communication1(0, 0, procConnections1, procSize);
    Communication communication2(0, 0, procConnections2, procSize);
    Communication comm[commSize] = {communication1, communication2};

    //when
    Communication::coverNoConnections(comm, commSize, procSize);
    int *connections1 = communication1.getProcConnections();
    int *connections2 = communication2.getProcConnections();

    //then
    for (int i = 0; i < procSize; ++i) {
        ASSERT_GT(connections1[i] + connections2[i], 0);
    }
}

TEST_F(CommunicationTests, shouldNotCoverConnectionsWithNoMissingConnections) {
    const int procSize = 3;
    const int commSize = 2;
    int procConnections1[procSize] = {1, 1, 1};
    Communication communication1(0, 0, procConnections1, procSize);
    Communication communication2(0, 0, procConnections1, procSize);
    Communication comm[commSize] = {communication1, communication2};

    //when
    Communication::coverNoConnections(comm, commSize, procSize);
    int *connections1 = communication1.getProcConnections();
    int *connections2 = communication2.getProcConnections();

    //then
    for (int i = 0; i < procSize; ++i) {
        ASSERT_EQ(connections1[i] + connections2[i], 2);
    }
}