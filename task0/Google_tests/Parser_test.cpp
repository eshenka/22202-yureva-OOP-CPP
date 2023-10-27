#include "..\Parser.h"
#include "gtest\gtest.h"
#include <vector>

using std::string;
using std::vector;

TEST(ParserTest, divisionTest1) {

    string strToTest = "hello it is me";

    Parser vectorResult;
    vector<string> finalString = vectorResult.parse(strToTest);

    ASSERT_EQ(4, finalString.size());
    ASSERT_EQ(vector<string> ({"hello", "it", "is", "me"}), finalString);

}

TEST(ParserTest, divisionTest2) {

    string strToTest = "!!!!hello___it's^$& %$#me)))";

    Parser vectorResult;
    vector<string> finalString = vectorResult.parse(strToTest);

    ASSERT_EQ(3, finalString.size());
    ASSERT_EQ(vector<string> ({"hello", "it's", "me"}), finalString);

}

TEST(ParserTest, toLowerCaseTest) {

    string strToTest = "HeLlO iT iS Me";

    Parser vectorResult;
    vector<string> finalString = vectorResult.parse(strToTest);

    ASSERT_EQ(vector<string> ({"hello", "it", "is", "me"}), finalString);

}
