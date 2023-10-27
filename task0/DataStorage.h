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
    map<string, int> data;
    int length;
public:
    DataStorage();
    void pushBack(const string& str);
    vector<pair<string, int>> sort();
    int getLength();
};

#endif //TASK0_DATASTORAGE_H
