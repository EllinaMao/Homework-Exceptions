#pragma once
#include <exception>
#include <string>


class CustomException : public std::exception {
protected:
    std::string message;
public:
    explicit CustomException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};


