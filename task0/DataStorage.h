#ifndef TASK0_DATASTORAGE_H
#define TASK0_DATASTORAGE_H
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::tuple;

class DataStorage {
private:
    map<std::string, int> data;
    int length;
public:
    DataStorage();
    void pushBack(const string& str);
    map<string, int>::iterator begin();
    map<string, int>::iterator end();
    vector<pair<string, int>> sort();
    int getLength();
};

#endif //TASK0_DATASTORAGE_H
