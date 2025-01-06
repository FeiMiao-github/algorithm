#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int32_t inner_imp(int n, std::list<int>& track, std::vector<std::list<int>>& res)
{
    if (track.size() == n)
    {
        res.emplace_back(track);
        return 0; 
    }

    for (int32_t i = 1; i <= n; i++)
    {
        auto iter = find_if(track.cbegin(), track.cend(), [i](int v) -> bool {
            return v == i;
        });

        if (iter != track.cend())
        {
            continue;
        }

        track.push_back(i);
        inner_imp(n, track, res);
        track.pop_back();
    }
    return 0;
}

int32_t full_arrange(int n)
{
    std::vector<std::list<int>> res;
    std::list<int> track;

    inner_imp(n, track, res);
    std::cout << "count: " << res.size() << "\n";

    return 0;
}

int main()
{
    full_arrange(10);
    return 0;
}