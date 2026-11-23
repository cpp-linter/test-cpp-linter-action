#include <string>
#include <vector>

int twice(int value) { return value * 2; }

int sum(std::vector<int> values)
{
    int total = 0;
    for (auto v : values)
        total += v;
    return total;
}

bool is_empty(const std::string &text)
{
    if (text.size() == 0)
        return true;
    else
        return false;
}
