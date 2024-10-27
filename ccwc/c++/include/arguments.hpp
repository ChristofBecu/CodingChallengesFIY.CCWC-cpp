#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <vector>

namespace arguments {
    extern bool isCountBytes;
    extern bool count_lines;
    extern bool count_words;
    extern bool count_chars;
    extern bool no_args;

    extern std::string usage;
    extern std::string filename;

    void parseArguments(int argc, char *argv[], std::vector<std::string> &files);

    void showUsage();
}


#endif