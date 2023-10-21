//
// Created by Yulia on 23.09.2023.
//

#ifndef TASK0_PARSER_H
#define TASK0_PARSER_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Parser {
public:
    Parser() = default;
    static vector<string> parse(string str);
};

#endif //TASK0_PARSER_H
