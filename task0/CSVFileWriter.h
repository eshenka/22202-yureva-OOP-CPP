#ifndef TASK0_CSVFILEWRITER_H
#define TASK0_CSVFILEWRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>

using std::ofstream;
using std::string;
using std::vector;
using std::pair;
using std::tuple;

class CSVFileWriter {
private:
    string filename;
    ofstream file;
public:
    explicit CSVFileWriter(string filename);
    void open();
    void write(tuple<string, int, double> data);
    void close();
};


#endif //TASK0_CSVFILEWRITER_H
