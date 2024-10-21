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

    file::closeFile();

    return 0;
}
