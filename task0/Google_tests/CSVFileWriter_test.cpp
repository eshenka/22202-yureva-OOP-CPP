#include "../CSVFileWriter.h"
#include "gtest/gtest.h"
#include <fstream>

using std::ifstream;
using std::getline;

TEST (CSVFileWriterTest, OutputTest) {

    string filename = "C:\\Users\\Yulia\\uni2\\sem3\\OOP\\22202-yureva-OOP-CPP\\task0\\Google_tests\\test.txt";
    CSVFileWriter csvFile(filename);
    csvFile.open();

    tuple<string, int, double> line1 = {"hello", 2, 0.7};
    tuple<string, int, double> line2 = {"me", 1, 0.3};


    csvFile.write(line1);
    csvFile.write(line2);

    csvFile.close();

    ifstream file;
    file.open(filename);

    string line;
    getline(file, line);
    ASSERT_EQ(line, "hello; 2; 0.7");
    getline(file, line);
    ASSERT_EQ(line, "me; 1; 0.3");
    getline(file, line);
    ASSERT_EQ(line, "");
    ASSERT_EQ(file.eof(), 1);

    file.close();

}