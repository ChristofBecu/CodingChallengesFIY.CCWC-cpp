#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>

#include "arguments.hpp"
#include "file.hpp"
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> files;
    arguments::parseArguments(argc, argv, files);

    if (files.size() == 0)
    {
        arguments::showUsage();
        return 1;
    }

    for (const auto &file : files)
    {
        arguments::filename = file;
        file::openFile(arguments::filename);

        if (!file::inputFile.is_open())
        {
            continue;
        }

        if (arguments::isCountBytes)
        {
            std::cout << "\t" << file::countBytes() << " " << arguments::filename << std::endl;
        }

        if (arguments::isCountLines)
        {
            std::cout << "\t" << file::countLines() << " " << arguments::filename << std::endl;
        }

        if (arguments::isCountWords)
        {
            std::cout << "\t" << file::countWords() << " " << arguments::filename << std::endl;
        }

        if (arguments::isCountchars)
        {
            std::cout << "\t" << file::countChars() << " " << arguments::filename << std::endl;
        }

        if (arguments::isNoOptions)
        {
            std::cout << "\t" << file::countLines() << "\t" << file::countWords() << "\t" << file::countBytes() << "\t" << arguments::filename << std::endl;
        }

        file::closeFile();
    }

    return 0;
}
