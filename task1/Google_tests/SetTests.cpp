#include "../BitArray.h"
#include "gtest/gtest.h"

TEST(SetTests, SetNoOperands) {
    BitArray array(33, 0);

    string allTrue;
    int cnt = 0;
    while(cnt != 33) {
        allTrue += "1";
        cnt++;
    }

    array.set();
    ASSERT_EQ(allTrue, array.to_string());
    ~array;
}

TEST(SetTests, SetWithOperands) {
    BitArray array(33, 0);

    string str;
    str += "1";
    int cnt = 1;
    while(cnt != 33) {
        str += "0";
        cnt++;
    }

    array.set(0, true);
    ASSERT_EQ(str, array.to_string());

    array.set();
    string str2;
    cnt = 0;
    while(cnt != 32) {
        str2 += "1";
        cnt++;
    }
    str2 += "0";

    array.set(32, false);
    ASSERT_EQ(str2, array.to_string());
    ~array;
}
