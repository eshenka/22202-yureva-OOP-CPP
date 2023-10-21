#include "../DataStorage.h"
#include "gtest/gtest.h"

using std::vector;
using std::make_pair;
using std::pair;
using std::string;

TEST(DataStorageTest, SortTest) {

    DataStorage data;

    vector<string> vectorToTest = {"hello", "hello", "hello", "me", "it", "is", "it", "1", "me"};

    for (auto &i: vectorToTest) {
        data.pushBack(i);
    }

    vector<pair<string, int>> expectedResult = {make_pair("hello", 3), make_pair("it", 2), make_pair("me", 2), make_pair("1", 1), make_pair("is", 1)};
    vector<pair<string, int>> actualResult = data.sort();

    ASSERT_EQ(expectedResult, actualResult);

}