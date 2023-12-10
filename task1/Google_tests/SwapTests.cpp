#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (SwapTest, SwapTest) {
    BitArray array1(6, 1);
    BitArray array2(4, 1);

    array1.swap(array2);

    ASSERT_EQ("1000", array1.to_string());
    ASSERT_EQ("100000", array2.to_string());

    ~array1;
    ~array2;
}