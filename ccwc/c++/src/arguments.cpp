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
        COUNT_CHARS
    };

    const std::unordered_map<std::string, Option> option_map = {
        {"-c", COUNT_BYTES},
        {"--bytes", COUNT_BYTES},
        {"-l", COUNT_LINES},
        {"--lines", COUNT_LINES},
        {"-w", COUNT_WORDS},
        {"--words", COUNT_WORDS},
        {"-m", COUNT_CHARS},
        {"--chars", COUNT_CHARS}
    };

    bool isCountBytes = false;
    bool count_lines = false;
    bool count_words = false;
    bool count_chars = false;
    bool no_args = false;

    std::string usage = "Usage: ccwc [OPTION]... [FILES]...\n"
                    "Count characters, words, and lines in given files.\n"
                    "\n"
                    "Options:\n"
                    "\t-c\t\tCount bytes\n"
                    "\t-l\t\tCount lines\n"
                    "\t-w\t\tCount words\n"
                    "\t-m\t\tCount characters\n"
                    "\n"
                    "With no FILE, or when FILE is -, read standard input.\n";

    std::string filename;

    void showUsage()
    {
        std::cout << arguments::usage << std::endl;
    }

    void parseArguments(int argc, char *argv[], std::vector<std::string> &files)
    {
        for (int i = 1; i < argc; ++i)
        {
            int optionCount = 0;
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
                        count_lines = true;
                        optionCount++;
                        break;
                    case COUNT_WORDS:
                        count_words = true;
                        optionCount++;
                        break;
                    case COUNT_CHARS:
                        count_chars = true;
                        optionCount++;
                        break;
                }
            }
            else if (argv[i][0] != '-')
            {
                files.push_back(argv[i]);
            }
            else
            {
                std::cerr << "Unknown option: " << argv[i] << "\n" << usage;
                exit(EXIT_FAILURE);
            }
            if (optionCount == 0)
            {
               no_args = true;
            }
        }

        if (files.empty())
        {
            std::cerr << "No files provided.\n" << usage;
            exit(EXIT_FAILURE);
        }
    }
    
}