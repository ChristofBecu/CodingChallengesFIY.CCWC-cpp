#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>

#include "arguments.hpp"
#include "file.hpp"

int main(int argc, char *argv[])
{
    arguments::parse(argc, argv);

    file::openFile(arguments::filename);

    if (arguments::count_bytes) {
        std::cout << "\t" << file::countBytes() << " " << arguments::filename << std::endl;
    }

    if (arguments::count_lines) {
        std::cout << "\t" << file::countLines() << " " << arguments::filename << std::endl;
    }

    if (arguments::count_words) {
        std::cout << "\t" << file::countWords() << " " << arguments::filename << std::endl;
    }

    if (arguments::count_chars) {
        std::cout << "\t" << file::countChars() << " " << arguments::filename << std::endl;
    }

    file::closeFile();

    return 0;
}
