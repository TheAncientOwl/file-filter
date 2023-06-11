#include "Tag.hpp"

namespace FileFilter {

Tag::Tag(std::string_view pattern)
    : m_pattern(pattern)
{
    setupLps(pattern);
}

void Tag::setupLps(std::string_view pattern)
{
    std::size_t pattern_length = pattern.length();

    m_lps.resize(pattern_length);

    int length = 0; // length of the previous longest prefix suffix
    m_lps[0] = 0; // lps[0] is always 0

    int idx = 1;
    while (idx < pattern_length)
    {
        if (pattern[idx] == pattern[length])
        {
            length++;
            m_lps[idx] = length;
            idx++;
        }
        else
        {
            if (length)
            {
                length = m_lps[length - 1];
            }
            else
            {
                m_lps[idx] = 0;
                idx++;
            }
        }
    }
}

bool Tag::match(std::string_view str) const
{
    const auto pattern_length = m_pattern.length();
    const auto str_length = str.length();

    std::size_t str_idx = 0;
    std::size_t pattern_idx = 0;

    while ((str_length - str_idx) >= (pattern_length - pattern_idx))
    {
        if (m_pattern[pattern_idx] == str[str_idx])
        {
            pattern_idx++;
            str_idx++;
        }

        if (pattern_idx == pattern_length)
        {
            return true;
        }
        else if (str_idx < str_length && m_pattern[pattern_idx] != str[str_idx])
        {
            if (pattern_idx != 0)
            {
                pattern_idx = m_lps[pattern_idx - 1];
            }
            else
            {
                str_idx = str_idx + 1;
            }
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& out, const Tag& tag)
{
    out << tag.m_pattern;

    return out;
}

} // namespace FileFilter
