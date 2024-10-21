#include "arguments.hpp"

#include <filesystem>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>

namespace arguments
{
    const char *ARG_COUNT_BYTES = "-c";
    const char *ARG_COUNT_LINES = "-l";
    const char *ARG_COUNT_WORDS = "-w";
    const char *ARG_COUNT_CHARS = "-m";

    bool count_bytes = false;
    bool count_lines = false;
    bool count_words = false;
    bool count_chars = false;
    bool no_args = false;

     const char *usage = "Usage: ccwc [OPTION]... [FILE]...\n"
                        "Count characters, words, and lines in a file.\n"
                        "\n"
                        "Options:\n"
                        "  -c\t\tCount bytes\n"
                        "  -l\t\tCount lines\n"
                        "  -w\t\tCount words\n"
                        "  -m\t\tCount characters\n"
                        "\n"
                        "With no FILE, or when FILE is -, read standard input.\n";

    std::string filename;

    void parse(int argc, char *argv[])
    {
        const std::vector<std::string_view> args(argv + 1, argv + argc);

        if (args.empty()) // TODO: and there is no pipe in the input
        {
            arguments::showUsage();
            return;
        }

        // If arg[0] is not a flag, then it is a filename, boolean no_args is set to true
        if (args[0][0] != '-')
        {
            arguments::no_args = true;
            arguments::filename = args[0];
            return;
        }

        if (args[0] == arguments::ARG_COUNT_BYTES)
        {
            arguments::count_bytes = true;
        }

        if (args[0] == arguments::ARG_COUNT_LINES)
        {
            arguments::count_lines = true;
        }

        if (args[0] == arguments::ARG_COUNT_WORDS)
        {
            arguments::count_words = true;
        }

        if (args[0] == arguments::ARG_COUNT_CHARS)
        {
            arguments::count_chars = true;
        }

        if (args.size() > 1)
        {
            arguments::filename = args[1];
        }

    }

    void showUsage()
    {
        std::cout << arguments::usage << std::endl;
    }
    
}