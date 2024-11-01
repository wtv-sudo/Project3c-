#include "SentimentClassifier.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 6) {
        std::cerr << "Usage: " << argv[0] << " <train_file> <test_file> <truth_file> <result_file> <accuracy_file>" << std::endl;
        return 1;
    }

    SentimentClassifier classifier;
    classifier.train(argv[1]);
    classifier.evaluate(argv[2], argv[3], argv[4], argv[5]);

    return 0;
}

