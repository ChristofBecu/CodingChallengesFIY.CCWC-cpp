#include <iostream>
#include <algorithm>
#include <iterator>
#include <string.h>
#include <fstream>

int main(int argc, char *argv[])
{
    #ifdef DEBUG
        std::cout << "Debug mode" << std::endl;
        std::copy(argv, argv + argc, std::ostream_iterator<char *>(std::cout, "\n"));
    #endif


    char *file_name = nullptr;
    bool count_bytes = false;

    if (argv[1] == nullptr)
    {
        std::cout << "No arguments passed" << std::endl;
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0)
    {
        count_bytes = true;
    }

    if (argv[2] == nullptr)
    {
        std::cout << "No file name passed" << std::endl;
        return 3;
    }

    file_name = argv[2];
    std::ifstream input_file(file_name, std::ios::in);
    if (!input_file.is_open())
    {
        std::cout << "File not found : " << file_name << std::endl;
        return 4;
    }

    if (count_bytes)
    {
        input_file.seekg(0, std::ios::end);
        std::cout << input_file.tellg() << " " << file_name << std::endl;
    }

    input_file.close();

    
    







   
    return 0;
}
