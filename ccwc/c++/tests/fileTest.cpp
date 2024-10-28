#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <gtest/gtest.h>

#include "file.hpp"
#include "globalTestEnvironment.hpp"

GlobalTestEnvironment* env = nullptr;

// Unit tests for file handling
TEST(OpenFileTest, ValidFile) {
    file::openFile(env -> filename);
    ASSERT_TRUE(file::inputFile.is_open());
    file::closeFile();
}

TEST(OpenFileTest, InvalidFile) {
    std::string invalidFilename = "nonexistent.gibberish";
    testing::internal::CaptureStderr();
    file::openFile(invalidFilename);
    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_FALSE(file::inputFile.is_open());
    std::string expectedError = "Error: File not found: " + invalidFilename + "\n";
    ASSERT_EQ(output, expectedError);
}

// Unit tests for file counting
TEST(CountBytes, ValidResult) {
    file::openFile(env -> filename);
    auto result = file::countBytes();
    file::closeFile();
    ASSERT_EQ(result, env -> expectedResultCountBytes);
}

TEST(CountBytes, InvalidResult) {
    file::openFile(env -> filename);
    auto result = file::countBytes();
    file::closeFile();
    ASSERT_NE(result, env -> expectedResultCountBytes + 1);
}

TEST(CountLines, ValidResult) {
    file::openFile(env -> filename);
    auto result = file::countLines();
    file::closeFile();
    ASSERT_EQ(result, env -> expectedResultCountLines);
}

TEST(CountLines, InvalidResult) {
    file::openFile(env -> filename);
    auto result = file::countLines();
    file::closeFile();
    ASSERT_NE(result, env -> expectedResultCountLines + 1);
}

TEST(CountWords, ValidResult) {
    file::openFile(env -> filename);
    auto result= file::countWords();
    file::closeFile;
    ASSERT_EQ(result, env -> expectedResultCountWords);
}

TEST(CountWords, InvalidResult) {
    file::openFile(env -> filename);
    auto result= file::countWords();
    file::closeFile;
    ASSERT_NE(result, env -> expectedResultCountWords + 1);
}

TEST(countCharacters, ValidResult) {
    file::openFile(env -> filename);
    auto result= file::countChars();
    file::closeFile;
    ASSERT_EQ(result, env -> expectedResultCountCharacters);
}

TEST(countCharacters, InvalidResult) {
    file::openFile(env -> filename);
    auto result= file::countChars();
    file::closeFile;
    ASSERT_NE(result, env -> expectedResultCountCharacters + 1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    env = static_cast<GlobalTestEnvironment*>(testing::AddGlobalTestEnvironment(new GlobalTestEnvironment));
    return RUN_ALL_TESTS();
}

