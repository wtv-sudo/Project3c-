#ifndef SENTIMENTCLASSIFIER_H
#define SENTIMENTCLASSIFIER_H

#include <map>
#include <vector>
#include "DSString.h"

class SentimentClassifier {
private:
    std::map<DSString, int> positiveWords;
    std::map<DSString, int> negativeWords;

public:
    void train(const char* trainingFile);
    int predict(const DSString& tweet);
    void evaluate(const char* testFile, const char* truthFile, const char* resultsFile, const char* accuracyFile);
};

#endif // SENTIMENTCLASSIFIER_H
