#pragma once
#include "CustomExceptions.h"

class MathException : public CustomException {
public:
    explicit MathException(const std::string& msg = "Mathematical error") : CustomException(msg) {}
};

class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero") {}
};

class OverflowException : public MathException {
public:
    OverflowException() : MathException("Overflow error") {}
};

class UnderflowException : public MathException {
public:
    UnderflowException() : MathException("Underflow error") {}
};

class InfiniteSolutionsException : public MathException {
public:
	InfiniteSolutionsException() : MathException("The equation has infinite solutions") {}
};

class NoSolutionsException
    : public MathException {
public:
	NoSolutionsException() : MathException("The equation has no solutions") {}
};

class LinearEquationException
    : public MathException {
public:
	LinearEquationException() : MathException("Linear equation error") {}
};