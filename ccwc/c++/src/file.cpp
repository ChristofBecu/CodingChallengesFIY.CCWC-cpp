#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>
#include <locale>
#include <codecvt>

namespace file
{
    std::wifstream inputFile;

    void openFile(std::string& filename) {
        file::inputFile.open(filename, std::ios::in);

        if (!inputFile.is_open())
        {
            std::cout << "File not found : " << filename << std::endl;
            return;
        }
        // Use UTF-8 encoding
        inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8<wchar_t>));
    };

    void closeFile() {
        file::inputFile.close();
    };

    int countBytes() {
        inputFile.clear();
        file::inputFile.seekg(0, std::ios::end);
        return file::inputFile.tellg();
    };

    int countLines() {
        inputFile.clear();
        file::inputFile.seekg(0, std::ios::beg);
        int count = 0;
        std::wstring line;
        while (std::getline(file::inputFile, line))
        {
            count++;
        }
        return count;
    }

    int countWords(){
        inputFile.clear();
        file::inputFile.seekg(0, std::ios::beg);
        int count = 0;
        std::wstring word;
        while (file::inputFile >> word)
        {
            count++;
        }
        return count;
    }

    int countChars(){
        inputFile.clear();
        file::inputFile.seekg(0, std::ios::beg);
        int count = 0;
        wchar_t c;
        while (file::inputFile.get(c))
        {
            count++;
        }
        return count;
    }
}