#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>
#include <sstream>

#include "arguments.hpp"
#include "file.hpp"
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> files;
    arguments::parseArguments(argc, argv, files);

    int totalLines = 0;
    int totalWords = 0;
    int totalBytes = 0;
    int totalChars = 0;

    std::ostringstream output;

    if (files.size() == 0)
    {
        // TODO: read from stdin
        arguments::showUsage();
        return 1;
    }

    for (const auto &file : files)
    {
        int lines = 0, words = 0, bytes = 0, chars = 0;
        arguments::filename = file;
        file::openFile(arguments::filename);

        if (!file::inputFile.is_open())
        {
            continue;
        }

        if (arguments::isNoOptions) {
            lines = file::countLines();
            words = file::countWords();
            bytes = file::countBytes();

            totalLines += lines;
            totalWords += words;
            totalBytes += bytes;

            output << lines << "\t" << words << "\t" << bytes << "\t";
        }

        if (arguments::isCountBytes)
        {
            bytes = file::countBytes();
            totalBytes += bytes;

            output << bytes << "\t";
        }

        if (arguments::isCountLines)
        {
            lines = file::countLines();
            totalLines += lines;

            output << lines << "\t";
        }

        if (arguments::isCountWords)
        {
            words = file::countWords();
            totalWords += words;

            output << words << "\t";
        }

        if (arguments::isCountchars)
        {
            chars = file::countChars();
            totalChars += chars;

            output << chars << "\t";
        }

        output << arguments::filename << std::endl;

        file::closeFile();
    }

    if (files.size() > 1)
    {
        if (arguments::isNoOptions)
        {
            output << totalLines << "\t" << totalWords << "\t" << totalBytes;
        }
        if (arguments::isCountBytes)
        {
            output << totalBytes << "\t";
        }
        if (arguments::isCountLines)
        {
            output << totalLines << "\t";
        }
        if (arguments::isCountWords)
        {
            output << totalWords << "\t";
        }
        if (arguments::isCountchars)
        {
            output << totalChars << "\t";
        }

        output << " total" << std::endl;
    }
    
    std::cout << output.str();

    return 0;
}
