#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (ShiftTests, RightShiftTest) {
    BitArray array(4, 1);
    array >>= 1;

    string str = "0100";

    ASSERT_EQ(str, array.to_string());
    ~array;
}

TEST (ShiftTests, LeftShiftTest) {
    BitArray array(4, 0);
    array[1] = true;
    array <<= 1;

    string str = "1000";

    ASSERT_EQ(str, array.to_string());
    ~array;
}
