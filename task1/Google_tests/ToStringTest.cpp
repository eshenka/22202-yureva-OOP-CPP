//
// Created by Yulia on 01.12.2023.
//


#include "../BitArray.h"
#include "gtest/gtest.h"

TEST(ToStringTest, allZeros) {
    BitArray array3(33, 0);

    string str;
    int cnt = 0;
    while(cnt != 33) {
        str += "0";
        cnt++;
    }

    ASSERT_EQ(str, array3.to_string());
}
