#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (ShiftTests, RightShiftTest) {
    BitArray array2(4, 1);
    array2 >>= 1;

    string str = "0100";

    ASSERT_EQ(str, array2.to_string());
}

TEST (ShiftTests, LeftShiftTest) {
    BitArray array6(4, 0);
    array6[1] = true;
    array6 <<= 1;

    string str = "1000";

    ASSERT_EQ(str, array6.to_string());
}
