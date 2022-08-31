#include <algorithm>
#include <string>

bool hasUniqueChars(std::string s)
{
    std::unique(s.begin(), s.end(), [](char letter) {

    });
}