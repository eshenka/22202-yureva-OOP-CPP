#include "../FileReader.h"
#include "gtest/gtest.h"

using std::string;

TEST(FileReaderTest, EmptyFileTest) {

    string filename;
    FileReader myFile(filename);

    ASSERT_EQ(myFile.isOpen(), 0);

}
