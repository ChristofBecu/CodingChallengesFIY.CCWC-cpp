#include "arguments.hpp"

#include <filesystem>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>
#include <unordered_map>

namespace arguments
{
    enum Option
    {
        COUNT_BYTES,
        COUNT_LINES,
        COUNT_WORDS,
        COUNT_CHARS,
        SHOW_USAGE
    };

    const std::unordered_map<std::string, Option> option_map = {
        {"-c", COUNT_BYTES},
        {"--bytes", COUNT_BYTES},
        {"-l", COUNT_LINES},
        {"--lines", COUNT_LINES},
        {"-w", COUNT_WORDS},
        {"--words", COUNT_WORDS},
        {"-m", COUNT_CHARS},
        {"--chars", COUNT_CHARS},
        {"-h", SHOW_USAGE},
        {"--help", SHOW_USAGE}
    };

    bool isCountBytes = false;
    bool isCountLines = false;
    bool isCountWords = false;
    bool isCountchars = false;
    bool isNoOptions = false;
    bool isNoFiles = false;

    std::string usage = "Usage: ccwc [OPTION]... [FILES]...\n"
                    "Count characters, words, and lines in given files.\n"
                    "\n"
                    "Options:\n"
                    "\t-h\t\tShow this help message\n"
                    "\t-c\t\tCount bytes\n"
                    "\t-l\t\tCount lines\n"
                    "\t-w\t\tCount words\n"
                    "\t-m\t\tCount characters\n"
                    "\n"
                    "If no FILES specified, read standard input.\n"
                    "e.g. ls | ccwc\n"
                    "to quit stdin input, type :q";

    std::string filename;

    void showUsage()
    {
        std::cout << arguments::usage << std::endl;
    }

    void parseArguments(int argc, char *argv[], std::vector<std::string> &files)
    {
        int optionCount = 0;
        int fileCount = 0;

        for (int i = 1; i < argc; ++i)
        {
            auto it = option_map.find(argv[i]);
            if (it != option_map.end())
            {
                switch (it->second)
                {
                    case COUNT_BYTES:
                        isCountBytes = true;
                        optionCount++;
                        break;
                    case COUNT_LINES:
                        isCountLines = true;
                        optionCount++;
                        break;
                    case COUNT_WORDS:
                        isCountWords = true;
                        optionCount++;
                        break;
                    case COUNT_CHARS:
                        isCountchars = true;
                        optionCount++;
                        break;
                    case SHOW_USAGE:
                        showUsage();
                        exit(EXIT_SUCCESS);
                        break;
                }
            }
            else if (argv[i][0] != '-')
            {
                files.push_back(argv[i]);
                fileCount++;
            }
            else
            {
                std::cerr << "Unknown option: " << argv[i] << "\n" << usage;
                exit(EXIT_FAILURE);
            }
        }
        if (optionCount == 0)
        {
            isNoOptions = true;
        }

        if (files.empty())
        {
            isNoFiles = true;
        }
    }
}