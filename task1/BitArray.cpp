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
        int dataElementToChange = length / BITS_IN_UNSIGNED_LONG;
        int indexElementToChange = length % BITS_IN_UNSIGNED_LONG;

        data[dataElementToChange] |= (element >> indexElementToChange);
        length += BITS_IN_UNSIGNED_LONG - indexElementToChange;

        int numberOfElementsToAdd = num_bits / BITS_IN_UNSIGNED_LONG;

        while (numberOfElementsToAdd) {
            data.push_back(element);
            numberOfElementsToAdd--;
        }

        length = num_bits;

    } else {
        unsigned numberOfElementsToDelete = data.size() - ((length - num_bits) / BITS_IN_UNSIGNED_LONG) - 1;
        while (numberOfElementsToDelete) {
            data.pop_back();
            numberOfElementsToDelete--;
        }

        length = num_bits;
    }
}

string BitArray::to_string() const {
    string number;
    int validLength = length / BITS_IN_UNSIGNED_LONG;

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

    int maxShift = BITS_IN_UNSIGNED_LONG - 1 - length % BITS_IN_UNSIGNED_LONG;

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
    if (length % BITS_IN_UNSIGNED_LONG) {
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
BitArray &BitArray::operator<<=(int n) {
    if (n < 0) {
        std::cout << "invalid n value" << std::endl;
        return *this;
    }

    if (n >= length) {
        this->reset();
        return *this;
    }

    int numberOfElementsToRemove = n / BITS_IN_UNSIGNED_LONG;
    int shift = n % BITS_IN_UNSIGNED_LONG;

}
*/

BitArray &BitArray::set(int n, bool val) {
    int numberOfElement = n / BITS_IN_UNSIGNED_LONG;
    int shiftInElement = BITS_IN_UNSIGNED_LONG - n % BITS_IN_UNSIGNED_LONG;

    data[numberOfElement] = data[numberOfElement] | (val << shiftInElement);

    return *this;
}

BitArray &BitArray::set() {
    for (unsigned long & i : data) {
        i = VALUE_TRUE;
    }
    return *this;
}

BitArray &BitArray::reset(int n) {
    (*this).set(n, false);
    return *this;
}

BitArray &BitArray::reset() {
    for (unsigned long & i : data) {
        i = VALUE_FALSE;
    }
    return *this;
}

bool BitArray::any() const {
    for (unsigned long i : data) {
        if (i ^ 0) {
            return true;
        }
    }
    return false;
}

bool BitArray::none() const {
    for (unsigned long i : data) {
        if (i ^ 0) {
            return false;
        }
    }
    return true;
}






