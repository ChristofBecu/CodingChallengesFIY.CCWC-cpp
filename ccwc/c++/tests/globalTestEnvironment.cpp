#include "globalTestEnvironment.hpp"
#include <iostream>

void GlobalTestEnvironment::SetUp() {
    // Initialize test data
    std::cout << "Global setup" << std::endl;
    filename = "./test_data/test.txt";
    expectedResultCountBytes = 342190;
    expectedResultCountLines = 7145;
    expectedResultCountWords = 58164;
    expectedResultCountCharacters = 339292;
}

void GlobalTestEnvironment::TearDown() {
    std::cout << "Global teardown" << std::endl;
    filename.clear();
    expectedResultCountBytes = 0;
    expectedResultCountLines = 0;
    expectedResultCountWords = 0;
    expectedResultCountCharacters = 0;
}