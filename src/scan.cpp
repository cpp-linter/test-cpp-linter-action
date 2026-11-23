#include <string>
#include <vector>

<<<<<<< HEAD
int sum(const std::vector<int> &values)
=======
int twice(int value) { return value * 2; }

int sum(std::vector<int> values)
>>>>>>> claude/project-thread-u751ea-sarif
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

int scale(int x)
{
    return x * 42;
}
