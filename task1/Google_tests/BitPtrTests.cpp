#include "../BitArray.h"
#include "gtest/gtest.h"

TEST (BitPtrTest, EquiatingTest) {
    BitArray array(8, 154); //10011010

    bool a = array[3];

    ASSERT_EQ(true, a);
}

TEST (BitPtrTest, AssignTest) {
    BitArray array(8, 154); //10011010

    bool a = array[1];
    ASSERT_EQ(false, a);

    array[1] = true;
    a = array[1];
    ASSERT_EQ(true, a);
}

TEST (BitPtrTest, MemoryTest) {
    BitArray array(8, 154);

    ASSERT_EQ(1, array.bytes());

    array[33] = true;
    ASSERT_EQ(2, array.bytes());

    ~array;
}