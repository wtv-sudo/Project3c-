cmake_minimum_required(VERSION 3.10)
project(SentimentAnalysis)

set(CMAKE_CXX_STANDARD 11)

add_executable(sentiment main.cpp DSString.cpp SentimentClassifier.cpp utils.cpp)
