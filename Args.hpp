#pragma once

#include <string>

#include "Tag.hpp"

namespace FileFilter {

struct Args
{
    std::string input_file_path;
    std::string output_file_path;
    std::vector<Tag> tags;

    void parse(int argc, const char* argv[]);
};

} // namespace FileFilter