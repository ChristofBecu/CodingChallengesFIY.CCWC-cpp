# Build Your Own wc Tool (c++)
This challenge is to build your own version of the Unix command line tool wc: 
[Instructions](https://codingchallenges.fyi/challenges/challenge-wc)

This tool counts the number of lines, words, bytes and characters in given files or from standard input.

I have not worked with C++ in years, so this was a nice opportunity to refresh my skills.

## Build executable

Running one following commands in a terminal, will show a help screen on how to pass arguments to the scripts

- Cross platform
``` python build.py ```
- Linux
``` ./build.sh ```
- Windows
``` ./build.bat ``` (not tested)

## Usage

```
Usage: ccwc [OPTION]... [FILES]...

Count characters, words, and lines in given files.

Options:
        -h              Show this help message
        -c              Count bytes
        -l              Count lines
        -w              Count words
        -m              Count characters

If no FILES specified, read standard input.
e.g. ls | ccwc
to quit stdin input, type :q
```

## Things learned

### loop over arguments
```cpp
std::copy(argv, argv + argc, std::ostream_iterator<char *>(std::cout, "\n"));
```
### open / close file
```cpp
std::ifstream input_file(file_name, std::ios::in);
if (!input_file.is_open())
{
    std::cout << "File not found : " << file_name << std::endl;
    return 4;
}
input_file.close();
```

### count bytes in file
```cpp
input_file.seekg(0, std::ios::end);
std::cout << "File size: " << input_file.tellg() << " bytes" << std::endl;
```

### open file in UTF-8 encoding
- as current locale did not recognize multibyte characters when using the -c option, reading in the file had to be in UTF-8 

```cpp
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

```

### standard input
- write a temporary file to the filesystem's temporary directory from stdin
- clean up after running


### build process
- Convert generated MAKEFILE to CMakeLists.txt
- Write simple build scripts in bash and batch
- rewrite CMakeLists.txt manually, with the help of [CMake Workshop](https://enccs.github.io/cmake-workshop/)
- rewrite bash file to automate the build process
- create a python script to automate the build process

### Add unit tests
- Simple tests with ctest
- Rewrite unit tests using Google Test
- Streamline the global test environment

