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
        arguments::showUsage();
        return 1;
    }

    for (const auto &file : files)
    {
        arguments::filename = file;
        file::openFile(arguments::filename);

        // if there is a error opening the file, skip to the next file
        if (!file::inputFile.is_open())
        {
            continue;
        }

        int lines = 0, words = 0, bytes = 0, chars = 0;

        if (arguments::count_lines)
        {
            lines = file::countLines();
            totalLines += lines;
            output << "\t" << lines;
        }

        else if (arguments::count_words)
        {
            words = file::countWords();
            totalWords += words;
            output << "\t" << words;
        }

        else if (arguments::isCountBytes)
        {
            bytes = file::countBytes();
            totalBytes += bytes;
            output << "\t" << bytes;
        }

        else if (arguments::count_chars)
        {
            chars = file::countChars();
            totalChars += chars;
            output << "\t" << chars;
        }

        else if (arguments::no_args)
        {

            lines = file::countLines();
            words = file::countWords();
            chars = file::countChars();
            
            totalLines += lines;
            totalChars += chars;
            totalWords += words;

            output << "\t" << lines << "\t" << words << "\t" << chars;
        }

        output << "\t" << arguments::filename << "\n";

        file::closeFile();
    }

    if (files.size() > 1)
    {
        output << "\t" << totalLines << "\t" << totalWords << "\t" << totalChars << "\ttotal\n";
    }

    std::cout << output.str();
    

    return 0;
}
