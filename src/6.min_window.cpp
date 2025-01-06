#include <iostream>
#include <unordered_map>

using namespace std;

class solution
{
public:
    string min_window(string s, string t)
    {
        bool is_valid = false;
        std::unordered_map<char, int> remain; // >= 1
        string res = s;

        for (const char c: t)
        {
            remain[c] = 0;
        }

        // s >= 1
        auto l = s.cbegin();
        auto r = s.cbegin();
        
        while (r < s.cend())
        {
            int vcount = 0;
            
            for (auto pair: remain)
            {
                if (pair.second != 0)
                {
                    vcount++;
                }
            }

            if (vcount != remain.size())
            {
                auto r_it = remain.find(*r);
                if (r_it != remain.cend())
                {
                    r_it->second ++;
                    if (r_it->second == 1)
                    {
                        vcount++;
                    }
                }
                r++;
            }

            std::cout << " cnt : " << vcount << "\n";

            while (l < r && vcount == remain.size())
            {
                if (res.size() > (r - l))
                {
                    res = "";
                    for (auto p = l; p < r; p++)
                    {
                        res += *p;
                    }
                }

                std::cout << "{";
                for (auto p = l; p < r; p++)
                {
                    std::cout << *p << ",";
                }
                std::cout << "}\n";
              
                auto iter = remain.find(*l);
                if (iter != remain.end())
                {
                    if (iter->second > 0)
                    {
                        iter->second -= 1;
                    }

                    l++;

                    if (iter->second == 0)
                    {
                        vcount--;
                        break;;
                    }
                }
                else
                {
                    l++;
                }
            }
        }

        return res;
    }
};

int main()
{
    solution s;

    string ret = s.min_window("ADOBECODEBANC", "ABC");
    std::cout << "res should be 'BANC', and cur res is " << ret << "\n";

    ret = s.min_window("a", "a");
    std::cout << "res should be 'a', and cur res is " << ret << "\n";

    ret = s.min_window("aa", "a");
    std::cout << "res should be 'a', and cur res is " << ret << "\n";

    return 0;
}