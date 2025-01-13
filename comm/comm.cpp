#include "comm.h"

// std::cout vector<int>
// weak function
std::ostream& __attribute__((weak)) operator<<(std::ostream& os, const vector<int>& arr)
{
    os << "{";
    for (auto &v: arr)
    {
        os << v << ",";
    }
    return os << "}";
}

// std::cout vector<vector<int>>
std::ostream& __attribute__((weak)) operator<<(std::ostream& os, const vector<vector<int>>& arrs)
{
    os << "{";
    for (auto p = arrs.cbegin(); p != arrs.end(); p++)
    {
        os << *p << ",";
    }
    os << "}";
    return os;
}

// std::cout vector<string>
std::ostream& __attribute__((weak)) operator<<(std::ostream& os, const vector<string>& strs)
{
    os << "{";
    for (auto p = strs.cbegin(); p != strs.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}";
    return os;
}

// std::cout vector<vector<string>>
std::ostream& __attribute__((weak)) operator<<(std::ostream& os, const vector<vector<string>>& strs)
{
    os << "{";
    for (auto p = strs.cbegin(); p != strs.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}";
    return os;
}