#include "BitArray.h"

int shiftBinarySize (unsigned long value) {
    int counter = 0;
    while (value) {
        value /= 2;
        counter++;
    }

    return BITS_IN_UNSIGNED_LONG - counter;
}

BitArray::BitArray(int num_bits, unsigned long value) {
    data.push_back(value << shiftBinarySize(value));
    length = num_bits;
}

BitArray::BitArray(const BitArray &b) {
    data = b.data;
    length = b.length;
}

BitArray &BitArray::operator=(const BitArray &b) {
    if (&b != this) {
        data = b.data;
        length = b.length;
    }

    return *this;
}

void BitArray::swap(BitArray &b) {
    BitArray tmp;
    tmp = b;

    b.data = data;
    b.length = length;

    data = tmp.data;
    length = tmp.length;
}

void BitArray::resize(int num_bits, bool value) {
    unsigned long element;
    if (value) {
        element = VALUE_TRUE;
    } else {
        element = VALUE_FALSE;
    }

    if (num_bits > length) {
        int dataElementToChange = length / 32;
        int indexElementToChange = length % 32;

        data[dataElementToChange] |= (element >> indexElementToChange);
        length += BITS_IN_UNSIGNED_LONG - indexElementToChange;

        int numberOfElementsToAdd = num_bits / BITS_IN_UNSIGNED_LONG;

        while (numberOfElementsToAdd) {
            data.push_back(element);
            numberOfElementsToAdd--;
        }

        length = num_bits;

    } else {
        unsigned numberOfElementsToDelete = data.size() - ((length - num_bits) / 32) - 1;
        while (numberOfElementsToDelete) {
            data.pop_back();
            numberOfElementsToDelete--;
        }

        length = num_bits;
    }
}

string BitArray::to_string() const {
    string number;
    int validLength = length / 32;

    for (int i = 0; i < validLength; i++) {
        int shift = BITS_IN_UNSIGNED_LONG - 1;
        while (true) {
            if (shift == -1) {
                break;
            }

            if ((data[i] >> shift) & 1) {
                number += "1";
            } else {
                number += "0";
            }

            shift--;
        }
    }

    int maxShift = BITS_IN_UNSIGNED_LONG - 1 - length % 32;

    for (int shift = BITS_IN_UNSIGNED_LONG - 1; shift != maxShift; shift--) {
        if ((data[validLength] >> shift) & 1) {
            number += "1";
        } else {
            number += "0";
        }
    }

    return number;
}

void BitArray::clear() {
    for (unsigned long & i : data) {
        i &= 0;
    }
}

void BitArray::push_back(bool bit) {
    if (length % 32) {
        data[data.size() - 1] |= (bit << (BITS_IN_UNSIGNED_LONG - data.size()));
    } else {
        data.push_back(VALUE_FALSE | (bit << (BITS_IN_UNSIGNED_LONG - 1)));
    }
    length++;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    if (length != b.length) {
        std::cout << "Lengths are not equal" << std::endl;
        return *this;
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] &= b.data[i];
    }

    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    if (length != b.length) {
        std::cout << "Lengths are not equal" << std::endl;
        return *this;
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] |= b.data[i];
    }

    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (length != b.length) {
        std::cout << "Lengths are not equal" << std::endl;
        return *this;
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] ^= b.data[i];
    }

    return *this;
}

/*
BitArray BitArray::operator<<(int n) const {

}
*/
