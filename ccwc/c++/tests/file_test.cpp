#include "file.hpp"
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include <gtest/gtest.h>

std::vector<std::string> filenames = {
    "./test_data/capital.txt",
    "./test_data/state.txt",
    "./test_data/empty.txt"
};

std::vector<int> exptectedResultsCountBytes = {
    39,
    58,
    0
};

std::vector<int> expectedResultsCountLines = {
    5,
    5,
    0
};

std::vector<std::pair<std::string, int>> getTestData(std::vector<int> exptedResults) {
    std::vector<std::pair<std::string, int>> testData;
    for (int i = 0; i < filenames.size(); i++) {
        testData.push_back({filenames[i], exptedResults[i]});
    }
    return testData;
}

TEST(countBytes, countBytes) {
    for (auto& [filename, expected] : getTestData(exptectedResultsCountBytes)) {
        file::openFile(filename);
        auto result = file::countBytes();
        file::closeFile();
        ASSERT_EQ(result, expected);
    }
}

TEST(countLines, countLines) {
    for (auto& [filename, expected] : getTestData(expectedResultsCountLines)) {
        file::openFile(filename);
        auto result = file::countLines();
        file::closeFile();
        ASSERT_EQ(result, expected);
    }
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

