#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>

namespace file
{
    std::fstream inputFile;

    void openFile(std::string filename) {
        file::inputFile.open(filename, std::ios::in);

        if (!inputFile.is_open())
        {
            std::cout << "File not found : " << filename << std::endl;
        }
    };

    void closeFile() {
        file::inputFile.close();
    };

    int countBytes() {
        file::inputFile.seekg(0, std::ios::end);
        return file::inputFile.tellg();
    };
}