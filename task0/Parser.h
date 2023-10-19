//
// Created by Yulia on 23.09.2023.
//

#ifndef TASK0_PARSER_H
#define TASK0_PARSER_H
#include <string>
#include "regex"

using namespace std;
using std::string;

class Parser {
public:
    Parser() = default;
    vector<string> parse(const string& str);
};

#endif //TASK0_PARSER_H
