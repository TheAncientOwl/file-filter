#include <iostream>
#include <fstream>
#include <string>

#include "Args.hpp"

using namespace std::literals::string_view_literals;

int main(int argc, const char* argv[])
{
    if (argc > 1 && argv[1] == "--help"sv)
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

    std::ifstream inputFile(args.input_file_path);
    std::ofstream outputFile(args.output_file_path);
    std::string inputLine;

    while (std::getline(inputFile, inputLine))
    {
        for (const auto& tag : args.tags)
        {
            if (tag.match(inputLine))
            {
                outputFile << inputLine << '\n';
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
