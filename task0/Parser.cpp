#include "Parser.h"

vector<string> Parser::parse(string str) {
    vector<string> result;

    string word;

    for (auto i = str.begin(); i != str.end(); i++) {
        if ((*i) == '\'' || isalnum(*i)) {
            word += tolower(*i);
        } else {
            if (!word.empty()) {
                result.push_back(word);
            }
            word = "";
        }
    }

    if (!word.empty()) {
        result.push_back(word);
    }

    return result;
}

