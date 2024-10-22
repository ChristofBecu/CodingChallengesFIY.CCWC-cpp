# Build Your Own wc Tool (c++)
This challenge is to build your own version of the Unix command line tool wc!
[Instructions](https://codingchallenges.fyi/challenges/challenge-wc)


## Build executable

- make sure you have cmake installed
- linux/mac: run build.sh
- windows: run build.bat

## Usage
- ccwc [OPTION]... [FILE]...

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

### Converting build process
- Convert MAKEFILE to CMakeLists.txt
- Write build scripts in bash and batch