#ifndef DSSTRING_H
#define DSSTRING_H

#include <iostream>
#include <cstring>

class DSString {
private:
    char* str; // Pointer to dynamically allocated char array
    size_t len;

public:
    // Constructors, Copy Constructor, Destructor, Assignment operator
    DSString(const char* s = "");
    DSString(const DSString& other);
    DSString& operator=(const DSString& other);
    ~DSString();

    // String manipulation and utility functions (add as needed)
    const char* c_str() const { return str; }
    bool operator==(const DSString& other) const;
    // Additional methods like substring, split, etc. can be added as needed
};

#endif // DSSTRING_H
