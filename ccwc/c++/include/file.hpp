#ifndef FILE_H
#define FILE_H

#include <string>
#include <fstream>

namespace file
{
    extern std::wifstream inputFile;
    void openFile(std::string& filename);
    void closeFile();
    std::string readFromStdin();
    void cleanUpTempFile();
    int countBytes();
    int countLines();
    int countWords();
    int countChars();
}


#endif