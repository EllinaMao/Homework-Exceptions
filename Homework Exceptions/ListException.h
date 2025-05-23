#pragma once
#include "CustomExceptions.h"


class ListException : public CustomException {
public:
    explicit ListException(const std::string& msg = "List error") : CustomException(msg) {}
};

class EmptyListException : public ListException {
public:
    EmptyListException() : ListException("Operation on empty list") {}
};

class IndexOutOfRangeException : public ListException {
public:
    IndexOutOfRangeException() : ListException("Index out of range") {}
};
