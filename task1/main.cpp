#include "BitArray.h"

using std::cout;
using std::endl;

int main() {
    /*BitArray myarr(32, 0);

    myarr[31] = true;
    cout << myarr.to_string() << endl;

    myarr.resize(33, true);
    cout << myarr.to_string() << endl;
    myarr[32] = false;
    cout << myarr.to_string() << endl;
    cout << myarr.size() << endl;
    myarr[33] = true;

    cout << myarr.to_string() << endl;
    cout << myarr.size() << endl;

    bool a = myarr[34];
    cout << a << endl;*/


    BitArray myarr(8, 154);

    cout << myarr.to_string() << endl;

    /*myarr[32] = false;
    cout << myarr.vector_size() << endl;*/

    //cout << sizeof(unsigned long) << endl;
}