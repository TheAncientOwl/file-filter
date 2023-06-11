#include <iostream>

#include "Tag.hpp"

using namespace std::literals::string_view_literals;

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "wrong usage: try file-info --help" << std::endl;
        return EXIT_FAILURE;
    }

    if (argv[1] == "--help"sv)
    {
        std::cout << "file-filter file.in --tags tag1 [tag2 tag3...] [-o filtered-file.out]" << std::endl;
        std::cout << "file-filter --help" << std::endl;
        std::cout << "file-filter --version" << std::endl;
        return EXIT_SUCCESS;
    }

    FileFilter::Tag pattern("ana");
    std::cout << std::boolalpha << pattern.match("xD anda are mere") << std::endl;

    return EXIT_SUCCESS;
}
