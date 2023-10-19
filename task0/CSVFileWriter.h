//
// Created by Yulia on 19.09.2023.
//

#ifndef TASK0_CSVFILEWRITER_H
#define TASK0_CSVFILEWRITER_H

#include "string"
#include "iostream"
#include <fstream>
#include "vector"
#include <tuple>

using std::string;
using std::pair;
using std::vector;
using std::ofstream;
using std::tuple;

class CSVFileWriter {
private:
    string filename;
    ofstream file;
public:
    explicit CSVFileWriter(string fname);
    void open();
    void write(tuple<string, int, double> data);
    void next();
    void close();
};


#endif //TASK0_CSVFILEWRITER_H
