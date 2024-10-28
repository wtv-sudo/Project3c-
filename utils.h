#ifndef UTILS_H
#define UTILS_H

#include "DSString.h"
#include <vector>

std::vector<DSString> tokenize(const DSString& str);
void writeResultsToFile(const DSString& filename, const std::vector<std::pair<int, int>>& results);

#endif
