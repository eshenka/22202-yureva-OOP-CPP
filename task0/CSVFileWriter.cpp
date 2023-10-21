//
// Created by Yulia on 19.09.2023.
//

#include "CSVFileWriter.h"
#include <iostream>
#include <utility>

using std::get;

CSVFileWriter::CSVFileWriter(string filename) {
    this->filename = std::move(filename);
}

void CSVFileWriter::open() {
    file.open(filename);
}

void CSVFileWriter::write(tuple<string, int, double> data) {
    file << get<0>(data) << "; " << get<1>(data) << "; " << get<2>(data);
}

void CSVFileWriter::next() {
    file << '\n';
}

void CSVFileWriter::close() {
    file.close();
}