#include "DSString.h"
#include <cstring>

DSString::DSString() : data(nullptr), len(0) {}
DSString::DSString(const char* str) {
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
}

// Implement copy constructor, assignment operator, destructor, etc.
