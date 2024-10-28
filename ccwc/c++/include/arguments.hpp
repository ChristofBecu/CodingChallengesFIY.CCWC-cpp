#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <vector>

namespace arguments {
    extern bool isCountBytes;
    extern bool isCountLines;
    extern bool isCountWords;
    extern bool isCountchars;
    extern bool isNoOptions;
    extern bool isNoFiles;

    extern std::string usage;
    extern std::string filename;

    void parseArguments(int argc, char *argv[], std::vector<std::string> &files);

    void showUsage();
}


#endif