#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>
#include <locale>
#include <codecvt>
#include <filesystem>

namespace fs = std::filesystem;

namespace file
{
    std::wifstream inputFile;
    std::filesystem::path tempDir = std::filesystem::temp_directory_path();
    std::filesystem::path tempFilePath = tempDir / "ccwc_stdin.txt";

    void openFile(std::string &filename)
    {
        try
        {
            // check if file exists
            if (!fs::exists(filename))
            {
                throw std::runtime_error("Error: File not found: " + filename);
            }

            file::inputFile.open(filename, std::ios::in);

            // Use UTF-8 encoding
            inputFile.imbue(std::locale(inputFile.getloc(), new std::codecvt_utf8<wchar_t>));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    };

    std::string readFromStdin()
    {
        std::string input;
        std::ostringstream stdinStream;
        while (std::getline(std::cin, input))
        {
            if (input == ":q") {
                break;
            }
            stdinStream << input << "\n";
        }
        std::string stdinContent = stdinStream.str();

        std::ofstream tempFile(tempFilePath);
        if (tempFile.is_open())
        {
            tempFile << stdinContent;
            tempFile.close();
        }
        else
        {
            std::cerr << "Failed to create temporary file." << std::endl;
            return "";
        }

        return tempFilePath.string();
    };

    void cleanUpTempFile()
    {
        if (fs::exists(tempFilePath))
        {
            fs::remove(tempFilePath);
        }
    };

    void closeFile()
    {
        file::inputFile.close();
    };

    int countBytes()
    {
        inputFile.clear();
        file::inputFile.seekg(0, std::ios::end);
        return file::inputFile.tellg();
    };

    int countLines()
    {
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

    int countWords()
    {
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

    int countChars()
    {
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