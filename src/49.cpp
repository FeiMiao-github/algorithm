#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// std::cout vector<string>
std::ostream& operator<<(std::ostream& os, const vector<string>& strs)
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
std::ostream& operator<<(std::ostream& os, const vector<vector<string>>& strs)
{
    os << "{";
    for (auto p = strs.cbegin(); p != strs.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}";
    return os;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> mp;

        for (auto p = strs.begin(); p != strs.end(); p++)
        {
            std::string tmp = *p;
            std::sort(tmp.begin(), tmp.end());
 
            int i = p - strs.begin();
            mp[tmp].push_back(i);
        }

        for (auto p = mp.begin(); p != mp.end(); p++)
        {
            ans.push_back(vector<string>{});
            for (auto pi = p->second.begin(); pi != p->second.end(); pi++)
            {
                ans.rbegin()->push_back(strs[*pi]);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::cout << "groupAngrams is " << s.groupAnagrams(strs) << "\n";
    return 0;
}