#pragma once
#include "CustomExceptions.h"

class MemoryException : public CustomException {
public:
    explicit MemoryException(const std::string& msg = "Memory allocation error") : CustomException(msg) {}
};

class NullPointerException : public MemoryException {
public:
    NullPointerException() : MemoryException("Null pointer exception") {}
};
class OutOfMemoryException : public MemoryException {
public:
    OutOfMemoryException() : MemoryException("Out of memory") {}
};
class MemoryLeakException : public MemoryException {
public:
    MemoryLeakException() : MemoryException("Memory leak detected") {}
};
class InvalidPointerException : public MemoryException {
public:
    InvalidPointerException() : MemoryException("Invalid pointer exception") {}
};
class MemoryCorruptionException : public MemoryException {
public:
    MemoryCorruptionException() : MemoryException("Memory corruption detected") {}
};
class MemoryAccessViolationException : public MemoryException {
public:
    MemoryAccessViolationException() : MemoryException("Memory access violation") {}
};
class MemoryAllocationException : public MemoryException {
public:
    MemoryAllocationException() : MemoryException("Memory allocation failure") {}
};
