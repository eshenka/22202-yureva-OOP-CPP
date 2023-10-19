#include <iostream>
#include "FileReader.h"
#include "Parser.h"
#include "DataStorage.h"
#include "CSVFileWriter.h"

using namespace std;
using std::string;
using std::get;
using std::map;

int main() {

    string filename;
    ifstream file;
    cout << "File to handle:";
    cin >> filename;
    cout << endl;

    FileReader textToHandle(filename);
    textToHandle.open();

    string myText;
    Parser vectorResult;
    DataStorage mapData;

    while(textToHandle.hasNext()) {
        myText = textToHandle.next();
        vector<string> v = vectorResult.parse(myText);
        for (auto i = 0; i < v.size(); i++) {
            mapData.push_back(v[i]);
        }
    }
    textToHandle.close();

    vector<pair<string, int>> result;
    result = mapData.sort();
    int length = mapData.getLength();

    cout << "File to store data:";
    cin >> filename;
    cout << endl;

    CSVFileWriter csvFile(filename);
    csvFile.open();

    for (auto& it : result) {
        tuple <string, int, double> toWrite;
        get<0>(toWrite) = it.first;
        get<1>(toWrite) = it.second;
        get<2>(toWrite) = (double) it.second / length * 100;
        csvFile.write(toWrite);
        csvFile.next();
    }
    csvFile.close();

    return 0;
}
