//
// Created by Yulia on 13.10.2023.
//

#ifndef TASK0_DATASTORAGE_H
#define TASK0_DATASTORAGE_H
#include <string>
#include <vector>
#include "map"
#include <tuple>
#include <algorithm>

using namespace std;
using std::string;

class DataStorage {
private:
    map<std::string, int> data;
    int length;
public:
    DataStorage();
    void push_back(const string& str);
    std::map<std::string, int>::iterator begin();
    std::map<std::string, int>::iterator end();
    vector<pair<string, int>> sort();
    int getLength();
};

#endif //TASK0_DATASTORAGE_H
