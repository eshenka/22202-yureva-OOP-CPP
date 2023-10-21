#include "DataStorage.h"

DataStorage::DataStorage() {
    length = 0;
};

void DataStorage::pushBack(const std::string& str) {
    ++data[str];
    ++length;
}

map<string, int>::iterator DataStorage::begin() {
    return data.begin();
}

map<string, int>::iterator DataStorage::end() {
    return data.end();
}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second;
}

vector<pair<string, int>> DataStorage::sort() {
    vector<pair<string, int>> result;
    for (auto& i : data) {
        result.push_back(i);
    }
    std::sort(result.begin(), result.end(), cmp);
    return result;
}

int DataStorage::getLength() {
    return length;
}