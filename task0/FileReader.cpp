//
// Created by Yulia on 19.09.2023.
//

#include "FileReader.h"
#include <iostream>
#include <fstream>
#include <utility>

using namespace std;
using std::ifstream;

FileReader::FileReader(std::string fname) {
    filename = std::move(fname);
}

void FileReader::open() {
    file.open(filename);
}

string FileReader::next() {
    string text;
    std::getline((file), text);
    return text;
}

bool FileReader::hasNext() {
    return !file.eof();
}

void FileReader::close() {
    file.close();
}

void FileReader::reset() {
    file.seekg(0, std::ios::beg);
}
