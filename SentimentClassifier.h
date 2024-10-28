#ifndef SENTIMENTCLASSIFIER_H
#define SENTIMENTCLASSIFIER_H

#include "DSString.h"
#include <vector>
#include <map>

class SentimentClassifier {
private:
    std::map<DSString, int> positiveWords;
    std::map<DSString, int> negativeWords;

public:
    void train(const DSString& trainFile);
    int predict(const DSString& tweet);
    void evaluate(const DSString& testFile, const DSString& truthFile,
                  const DSString& resultFile, const DSString& accuracyFile);
};

#endif

