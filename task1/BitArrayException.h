//
// Created by Yulia on 02.12.2023.
//

#ifndef TASK1_BITARRAYEXCEPTION_H
#define TASK1_BITARRAYEXCEPTION_H

#include <exception>
#include <string>

class BitArrayException : public std::exception {
private:
    std::string errorMessage;

public:
    BitArrayException(std::string errorMessage) {
        this->errorMessage = errorMessage;
    }

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

#endif //TASK1_BITARRAYEXCEPTION_H
