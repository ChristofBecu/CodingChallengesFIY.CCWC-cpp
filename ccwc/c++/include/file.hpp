#ifndef FILE_H
#define FILE_H

#include <string>

namespace file
{
    extern std::fstream inputFile;
    void openFile(std::string filename);
    void closeFile();
    int countBytes();
    int countLines();
    int countWords();
    int countChars();
}


#endif