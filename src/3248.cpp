#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (auto& v: commands)
        {
            if (v == "UP")
            {
                ans -= n;
            }
            else if (v == "DOWN")
            {
                ans += n;
            }
            else if (v == "RIGHT")
            {
                ans += 1;
            }
            else if (v == "LEFT")
            {
                ans -= 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    int n = 2;
    vector<string> commands { "RIGHT", "DOWN" };
    std::cout << "final pos is " << s.finalPositionOfSnake(n, commands) << "\n";
    return 0;
}