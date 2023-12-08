#include "../BitArray.h"
#include "gtest/gtest.h"

TEST(PushBackTest, NoMemoryTriggered) {
    BitArray array(6, 1);

    array.push_back(true);

    ASSERT_EQ("1000001", array.to_string());

    ~array;
}

TEST(PushBackTest, MemoryTriggered) {
    BitArray array(32, 0);

    array.push_back(true);

    ASSERT_EQ("000000000000000000000000000000001", array.to_string());

    ~array;
}