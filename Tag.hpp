#pragma once

#include <iostream>
#include <string_view>
#include <string>
#include <vector>

namespace FileFilter {

/**
 * @brief Tag class
 *  Given a string (pattern), use the KMP algorithm to check if it matches another string.
 */
class Tag
{
public:
    Tag(std::string_view pattern);
    ~Tag() = default;

    Tag(const Tag&) = delete;
    Tag& operator=(const Tag&) = delete;

    Tag(Tag&&) noexcept = default;
    Tag& operator=(Tag&&) noexcept = default;

public:
    bool match(std::string_view str) const;
    friend std::ostream& operator<<(std::ostream& out, const Tag& tag);

private:
    void setupLps(std::string_view pattern);

private:
    std::vector<std::size_t> m_lps; // the longest proper prefix which is also a suffix
    std::string m_pattern;
};

} // namespace FileFilter