#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (ResizeTest, ExpandTest) {
    BitArray array(33, 0);
    array.resize(34);

    string str;
    int count = 0;
    while (count < 34) {
        str += "0";
        count++;
    }

    ASSERT_EQ(str, array.to_string());
    ~array;
}

TEST (ResizeTest, NarrowTest) {
    BitArray array(35, 0);
    array.resize(34);

    string str;
    int count = 0;
    while (count < 34) {
        str += "0";
        count++;
    }

    ASSERT_EQ(str, array.to_string());
    ~array;
}

TEST(ResizeTest, ExceptionTest) {
    BitArray array(33, 0);

    ASSERT_THROW(array.resize(-5), BitArrayException);
    ~array;
}