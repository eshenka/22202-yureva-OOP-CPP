#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (BitOperationTest, AND) {
    BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    cmp.set();
    array &= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.reset();
    array &= cmp;
    ASSERT_EQ("0000000000", array.to_string());

    ~cmp;
    ~array;
}

TEST (BitOperationTest, OR) {
    BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    array |= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.set();
    array |= cmp;
    ASSERT_EQ("1111111111", array.to_string());

    ~cmp;
    ~array;
}

TEST (BitOperationTest, XOR) {
    BitArray array(10, 0);
    array[5] = true;
    array[9] = true;

    BitArray cmp(10, 0);

    array ^= cmp;
    ASSERT_EQ("0000010001", array.to_string());

    cmp.set();
    array ^= cmp;
    ASSERT_EQ("1111101110", array.to_string());

    ~cmp;
    ~array;
}
