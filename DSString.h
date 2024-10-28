#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>

class DSString {
private:
    char* data;
    int len;

public:
    DSString();
    DSString(const char* str);
    DSString(const DSString& other);
    ~DSString();

    DSString& operator=(const DSString& other);
    DSString operator+(const DSString& rhs);
    bool operator==(const DSString& rhs) const;
    bool operator!=(const DSString& rhs) const;
    bool operator<(const DSString& rhs) const;
    char& operator[](int index);

    int length() const;
    char* c_str() const;
};

#endif

