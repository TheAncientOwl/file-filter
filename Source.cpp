#include <iostream>
#include <fstream>

#include "Args.hpp"

using namespace std::literals::string_view_literals;

int main(int argc, const char* argv[])
{
    if (argv[1] == "--help"sv)
    {
        std::cout << "file-filter file.in --tags tag1 [tag2 tag3...] [-o filtered-file.out]" << std::endl;
        std::cout << "file-filter --help" << std::endl;
        std::cout << "file-filter --version" << std::endl;
        return EXIT_SUCCESS;
    }

    FileFilter::Args args{};
    try
    {
        args.parse(argc, argv);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
