#ifndef GLOBAL_TEST_ENVIRONMENT_HPP
#define GLOBAL_TEST_ENVIRONMENT_HPP

#include <gtest/gtest.h>
#include <string>

class GlobalTestEnvironment : public ::testing::Environment {
public:
    std::string filename;
    int expectedResultCountBytes;
    int expectedResultCountLines;
    int expectedResultCountWords;
    int expectedResultCountCharacters;

    void SetUp() override;
    void TearDown() override;
};

#endif // GLOBAL_TEST_ENVIRONMENT_HPP