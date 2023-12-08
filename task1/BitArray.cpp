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
    int dataSize = (num_bits - 1) / BITS_IN_UNSIGNED_LONG + 1;
    data.resize(dataSize);
    data[0] = value << shiftBinarySize(value);
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

    *this = tmp;
}

void BitArray::resize(int num_bits, bool value) {
    if (num_bits < 0) {
        throw BitArrayException("Unable to resize by negative value");
    }

    unsigned long element;
    if (value) {
        element = VALUE_TRUE;
    } else {
        element = VALUE_FALSE;
    }

    if (num_bits >= length) {
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
    int validLength = (length) / BITS_IN_UNSIGNED_LONG;

    for (int i = 0; i < validLength; i++) {
        int shift = BITS_IN_UNSIGNED_LONG - 1;
        while (shift >= 0) {
            if ((data[i] >> shift) & 1) {
                number += "1";
            } else {
                number += "0";
            }

            shift--;
        }
    }

    int maxShift = BITS_IN_UNSIGNED_LONG - 1 - (length) % BITS_IN_UNSIGNED_LONG;

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
    data.clear();
    length = 0;
}

void BitArray::push_back(bool bit) {
    if (length % BITS_IN_UNSIGNED_LONG) {
        data[data.size() - 1] |= (bit << (BITS_IN_UNSIGNED_LONG - data.size() - 1));
    } else {
        data.push_back(VALUE_FALSE | (bit << (BITS_IN_UNSIGNED_LONG - 1)));
    }
    length++;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    if (length != b.length) {
        throw BitArrayException("Lengths are not equal");
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] &= b.data[i];
    }

    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    if (length != b.length) {
        throw BitArrayException("Lengths are not equal");
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] |= b.data[i];
    }

    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (length != b.length) {
        throw BitArrayException("Lengths are not equal");
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] ^= b.data[i];
    }

    return *this;
}

BitArray &BitArray::operator<<=(int n) {
    if (n < 0) {
        throw BitArrayException("invalid n value");
    }

    if (n >= length) {
        (*this).reset();
        return *this;
    }

    int elementsToRemove = n / BITS_IN_UNSIGNED_LONG;
    int shift = n % BITS_IN_UNSIGNED_LONG;
    int shiftReversed = BITS_IN_UNSIGNED_LONG - shift;

    for (int i = 0; i < data.size() - elementsToRemove; i++) {
        data[i] = (data[elementsToRemove + i] << shift) | (data[elementsToRemove + i + 1] >> shiftReversed);
    }
    data[data.size() - elementsToRemove] << shiftReversed;

    for (unsigned long i = data.size() - elementsToRemove; i < data.size(); i++) {
        data[i] &= VALUE_FALSE;
    }

    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray shifted(*this);

    shifted <<= n;

    return shifted;
}

BitArray &BitArray::operator>>=(int n) {
    if (n < 0) {
        throw BitArrayException("invalid n value");
    }

    if (n >= length) {
        this->reset();
        return *this;
    }

    int elementsToRemove = n / BITS_IN_UNSIGNED_LONG;
    int shift = n % BITS_IN_UNSIGNED_LONG;
    int shiftReversed = BITS_IN_UNSIGNED_LONG - shift;

    for (int i = data.size() - 1; i >= elementsToRemove + 1; i--) {
        data[i] = (data[i - elementsToRemove] << shift) | (data[i - 1 - elementsToRemove] >> shiftReversed);
    }
    data[elementsToRemove] = (data[elementsToRemove] >> shift) | 0;

    for (int i = 0; i < elementsToRemove; i++) {
        std::cout << "b" << std::endl;
        data[i] &= VALUE_FALSE;
    }

    return *this;
}

BitArray BitArray::operator>>(int n) const {
    BitArray shifted(*this);

    shifted >>= n;

    return shifted;
}

BitArray &BitArray::set(int n, bool val) {
    if (n >= length - 1) {
        this->resize(n + 1, false);
    }

    int numberOfElement = n / BITS_IN_UNSIGNED_LONG;
    int shiftInElement = BITS_IN_UNSIGNED_LONG - n % BITS_IN_UNSIGNED_LONG - 1;

    if (val) {
        data[numberOfElement] = data[numberOfElement] | (val << shiftInElement);
    } else {
        data[numberOfElement] = data[numberOfElement] & ~(true << shiftInElement);
    }

    return *this;
}

BitArray &BitArray::set() {
    for (int i = 0; i <= data.size(); i++) {
        data[i] = VALUE_TRUE;
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

BitArray BitArray::operator~() const {
    BitArray inversion(*this);

    for (int i = 0; i < data.size(); i++) {
        inversion.data[i] = data[i] ^ (unsigned long)VALUE_TRUE;
    }

    return inversion;
}

int BitArray::count() const {
    int count = 0;

    for (unsigned long i : data) {
        for (int shift = 0; shift < BITS_IN_UNSIGNED_LONG; shift++) {
            if ((i >> shift) & 1) {
                count++;
            }
        }
    }
    return count;
}

int BitArray::size() const {
    int lastElement = (int)data.size() - 1;

    if (data[lastElement] != VALUE_FALSE) {
        int shift = BITS_IN_UNSIGNED_LONG - (length % BITS_IN_UNSIGNED_LONG) - 1;

        for (; shift < BITS_IN_UNSIGNED_LONG; shift++) {
            if ((data[lastElement] >> shift) & 1) {
                return BITS_IN_UNSIGNED_LONG * lastElement + (BITS_IN_UNSIGNED_LONG - shift);
            }
        }
    }

    lastElement--;

    while (lastElement >= 0) {
        if (data[lastElement] != VALUE_FALSE) {
            for (int shift = 0; shift < BITS_IN_UNSIGNED_LONG; shift++) {
                if ((data[lastElement] >> shift) & 1) {
                    return lastElement * BITS_IN_UNSIGNED_LONG - shift;
                }
            }
            lastElement--;
        }
    }
    return 0;
}

bool BitArray::empty() const {
    return length == 0;
}

BitArray::BitPointer BitArray::operator[](int i) const {
    BitArray::BitPointer bitPtr(*this, i);
    return bitPtr;
}

int BitArray::bytes() {
    return data.size();
}

BitArray::BitPointer &BitArray::BitPointer::operator=(bool e) {
    (bitArray).set(index, e);
    return *this;
}

BitArray::BitPointer::BitPointer(const BitArray &bitArray, int index) : bitArray(const_cast<BitArray &>(bitArray)) {
    this->bitArray = bitArray;
    this->index = index;
}

BitArray::BitPointer::operator bool() {
    if (index >= bitArray.length) {
        return false;
    }

    int element = index / BITS_IN_UNSIGNED_LONG;
    int shift = BITS_IN_UNSIGNED_LONG - index % BITS_IN_UNSIGNED_LONG - 1;

    return ((bitArray.data[element] >> shift) & 1);
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return true;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return true;
        }
    }

    return false;
}

BitArray operator&(const BitArray& b1, const BitArray& b2) {
    BitArray ANDResult(b1);

    ANDResult &= b2;

    return ANDResult;
}

BitArray operator|(const BitArray& b1, const BitArray& b2) {
    BitArray ORResult(b1);

    ORResult |= b2;

    return ORResult;
}

BitArray operator^(const BitArray& b1, const BitArray& b2) {
    BitArray XORResult(b1);

    XORResult ^= b2;

    return XORResult;
}
