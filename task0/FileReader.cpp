#include "FileReader.h"
#include <iostream>
#include <utility>

FileReader::FileReader(string filename) {
    this->filename = std::move(filename);
}

void FileReader::open() {
    file.open(filename);
}

bool FileReader::isOpen() {
    return file.is_open();
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
