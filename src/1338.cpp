#include <comm.h>

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> map;
        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]]++;
        }

        vector<int> cnt;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            cnt.push_back(it->second);
        }

        sort(cnt.begin(), cnt.end(), std::greater<int>());

        int res = 0;
        int sum = 0;
        for (int i = 0; i < cnt.size(); i++)
        {
            sum += cnt[i];
            if (sum * 2 >= arr.size())
            {
                res = i + 1;
                break;
            }
        }

        return res;
    }
};

void test(const vector<int>& arr, int expect) {
    Solution s;
    vector<int> param1 = arr;
    int res = s.minSetSize(param1);
    if(res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main()
{
    // 输入：arr = [3,3,3,3,5,5,5,2,2,7]
    // 输出：2
    test({3,3,3,3,5,5,5,2,2,7}, 2);

    // 输入：arr = [7,7,7,7,7,7]
    // 输出：1
    test({7,7,7,7,7,7}, 1);

    return 0;
}