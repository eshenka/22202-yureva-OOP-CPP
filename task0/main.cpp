#include <iostream>
#include <ostream>
#include "FileReader.h"
#include "Parser.h"
#include "DataStorage.h"
#include "CSVFileWriter.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;
using std::get;

int main(int argc, char* argv[]) {

    if (argc < 3) {
        return 0;
    }

    string filename = argv[1];
    ifstream file;

    FileReader textToHandle(filename);
    textToHandle.open();

    if (!textToHandle.isOpen()) {
        cout << "Failed to open file";
        return 0;
    }

    string line;
    Parser parser;
    DataStorage mapData;

    while(textToHandle.hasNext()) {
        line = textToHandle.next();
        vector<string> v = parser.parse(line);
        for (auto i = 0; i < v.size(); i++) {
            mapData.pushBack(v[i]);
        }
    }
    textToHandle.close();

    vector<pair<string, int>> result;
    result = mapData.sort();
    int length = mapData.getLength();

    filename = argv[2];
    CSVFileWriter csvFile(filename);
    csvFile.open();

    for (auto& it : result) {
        tuple<string, int, double> toWrite;
        get<0>(toWrite) = it.first;
        get<1>(toWrite) = it.second;
        get<2>(toWrite) = (double) it.second / length * 100;
        csvFile.write(toWrite);
    }
    csvFile.close();

    return 0;

}

