#include "DSString.h"
#include <cassert>
#include <iostream>

int main() {
    DSString str1("hello");
    DSString str2("world");

    assert(str1.length() == 5);       // Test length
    assert(str1 == "hello");          // Test equality
    assert(str1 + str2 == "helloworld"); // Test concatenation

    std::cout << "All DSString tests passed." << std::endl;
    return 0;
}
