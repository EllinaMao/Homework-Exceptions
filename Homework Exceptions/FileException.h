#pragma once
#include "CustomExceptions.h"

class FileException : public CustomException {
public:
    explicit FileException(const std::string& msg = "File error") : CustomException(msg) {}
};

class FileNotFoundException : public FileException {
public:
    FileNotFoundException() : FileException("File not found") {}
};

class FileAccessException : public FileException {
public:
    FileAccessException() : FileException("File access error") {}
};
