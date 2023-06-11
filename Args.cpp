#include "Args.hpp"

#include <stdexcept>

#include <sstream>
#include <filesystem>

using namespace std::literals::string_view_literals;

namespace FileFilter {

void Args::parse(int argc, const char* argv[])
{
    if (argc < 4)
    {
        throw std::invalid_argument("wrong usage : try file-info --help");
    }

    input_file_path = argv[1];
    if (!std::filesystem::exists(input_file_path))
    {
        std::ostringstream os;
        os << "file-filter error: file " << "\"" << input_file_path << "\" does not exist.";
        throw std::invalid_argument(os.str());
    }

    output_file_path = input_file_path + ".filtered";

    for (int i = 2; i < argc; i++)
    {
        if (argv[i] == "-o"sv)
        {
            if (i + 1 == argc)
            {
                throw std::invalid_argument("file-filter error: missing output file.");
            }
            output_file_path = argv[i + 1];
            i++;
        }
        else if (argv[i] != "--tags"sv)
        {
            tags.emplace_back(argv[i]);
        }
    }
}

} // namespace FileFilter
