# Build Your Own wc Tool (c++)

## Build executable

- make -f Makefile

## Usage
- ccwc -c data/test.txt

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