#include "CSVFileWriter.h"
#include <iostream>
#include <utility>

using std::get;
using std::endl;

CSVFileWriter::CSVFileWriter(string filename) {
    this->filename = std::move(filename);
}

void CSVFileWriter::open() {
    file.open(filename);
}

void CSVFileWriter::write(tuple<string, int, double> data) {
    file << get<0>(data) << "; " << get<1>(data) << "; " << get<2>(data) << endl;
}

void CSVFileWriter::close() {
    file.close();
}