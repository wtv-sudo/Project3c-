#include "SentimentClassifier.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Helper function for string tokenization
std::vector<DSString> tokenize(const DSString& tweet) {
    // Split tweet text into words and return as vector of DSStrings
}

// Train the classifier using a labeled dataset
void SentimentClassifier::train(const char* trainingFile) {
    std::ifstream infile(trainingFile);
    if (!infile) {
        std::cerr << "Error opening training file." << std::endl;
        return;
    }

    int sentiment;
    std::string line, token;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        // Parse sentiment, tweet id, date, query, username
        std::getline(ss, token, ','); sentiment = std::stoi(token);
        std::getline(ss, token, ','); // skip tweet id
        std::getline(ss, token, ','); // skip date
        std::getline(ss, token, ','); // skip query
        std::getline(ss, token, ','); // skip username
        std::getline(ss, token);      // actual tweet text

        DSString tweet(token.c_str());
        std::vector<DSString> words = tokenize(tweet);

        for (const DSString& word : words) {
            if (sentiment == 4)
                positiveWords[word]++;
            else if (sentiment == 0)
                negativeWords[word]++;
        }
    }
}

// Predict sentiment based on word frequency analysis
int SentimentClassifier::predict(const DSString& tweet) {
    std::vector<DSString> words = tokenize(tweet);
    int positiveScore = 0, negativeScore = 0;

    for (const DSString& word : words) {
        positiveScore += positiveWords[word];
        negativeScore += negativeWords[word];
    }

    return (positiveScore > negativeScore) ? 4 : 0;
}

// Evaluate predictions against ground truth
void SentimentClassifier::evaluate(const char* testFile, const char* truthFile, const char* resultsFile, const char* accuracyFile) {
    std::ifstream testInput(testFile);
    std::ifstream truthInput(truthFile);
    std::ofstream resultsOutput(resultsFile);
    std::ofstream accuracyOutput(accuracyFile);

    int correct = 0, total = 0;
    std::string line, token;
    while (std::getline(testInput, line)) {
        std::stringstream ss(line);
        std::getline(ss, token, ','); // tweet id
        std::string tweetId = token;
        std::getline(ss, token);      // actual tweet text
        DSString tweet(token.c_str());

        int prediction = predict(tweet);

        // Get ground truth sentiment for accuracy calculation
        std::getline(truthInput, line);
        std::stringstream ssTruth(line);
        std::getline(ssTruth, token, ','); // actual sentiment
        int groundTruth = std::stoi(token);

        if (prediction == groundTruth) correct++;
        else {
            // Log incorrect classifications
            accuracyOutput << prediction << ", " << groundTruth << ", " << tweetId << "\n";
        }

        // Write result
        resultsOutput << prediction << ", " << tweetId << "\n";
        total++;
    }

    double accuracy = static_cast<double>(correct) / total;
    accuracyOutput << std::fixed << std::setprecision(3) << accuracy << "\n";
}
