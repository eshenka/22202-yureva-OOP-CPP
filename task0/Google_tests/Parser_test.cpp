//
// Created by Yulia on 20.10.2023.
//

#include "..\Parser.h"
#include "gtest\gtest.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

TEST(nuya, hzeslchstn) {

    string strToTest = "hello it is me";

    Parser vectorResult;
    vector<string> finalString = vectorResult.parse(strToTest);

    ASSERT_EQ(4, finalString.size());

}
