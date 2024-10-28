#include "SentimentClassifier.h"
#include "utils.h"
#include <fstream>

void SentimentClassifier::train(const DSString& trainFile) {
    std::ifstream file(trainFile.c_str());
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        // Extract sentiment and tweet from the line
        // Tokenize tweet into words
        // Update positiveWords or negativeWords based on sentiment
    }
}

int SentimentClassifier::predict(const DSString& tweet) {
    // Tokenize the tweet and calculate positive and negative score
    return score > 0 ? 4 : 0; // 4 for positive, 0 for negative
}

void SentimentClassifier::evaluate(const DSString& testFile, const DSString& truthFile,
                                   const DSString& resultFile, const DSString& accuracyFile) {
    // Open files and write results
}
