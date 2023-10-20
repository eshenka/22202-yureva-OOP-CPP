//
// Created by Yulia on 19.09.2023.
//

#ifndef TASK0_FILEREADER_H
#define TASK0_FILEREADER_H

#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;

class FileReader {
private:
    string filename;
    ifstream file;
public:
    explicit FileReader(string filename);
    void open();
    bool isOpen();
    string next();
    bool hasNext();
    void close();
    void reset();
};


#endif //TASK0_FILEREADER_H
