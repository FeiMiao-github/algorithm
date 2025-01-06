#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec)
{
    os << "{";
    for (auto p = vec.cbegin(); p != vec.cend(); p++)
    {
        os << *p << ", ";
    }
    os << "}\n";
    return os << "}";
}

class Solution
{
public:
    long long pow2(long long x)
    {
        return x * x;
    }

    bool checkInCircle(int x, int y, const vector<int> &circle)
    {
        long long xl = x, yl = y;
        long long cxl0 = circle[0], cyl0 = circle[1], crl0 = circle[2];
        return pow2(cxl0 - xl) + pow2(cyl0 - yl) <= pow2(crl0);
    }

    bool checkIntersectRect(int x, int y, const vector<int> &circle0, const vector<int> &circle1)
    {
        long long xl = x, yl = y;
        long long cxl0 = circle0[0], cyl0 = circle0[1], crl0 = circle0[2];
        long long cxl1 = circle1[0], cyl1 = circle1[1], crl1 = circle1[2];

        return (pow2(cxl0 - cxl1) + pow2(cyl0 - cyl1) <= pow2(crl0 + crl1)) 
            && (cxl0 * crl1 + cxl1 * crl0 < (crl0 + crl1) * xl)
            && (cyl0 * crl1 + cyl1 * crl0 < (crl0 + crl1) * yl);
    }

    bool checkIntersectLeftOrTopRect(int x, int y, const vector<int> &circle)
    {
        // return (std::abs(circle[0]) <= circle[2] && circle[1] <= y) || (std::abs(circle[1] - y) <= circle[2] && circle[0] <= x);
        // (x <= X and abs(y - Y) <= r or y <= Y and x <= r)
        return (circle[0] <= x && std::abs(circle[1] - y) <= circle[2]) || (circle[1] <= y && circle[0] <= circle[2]);
    }

    bool checkIntersectRightOrBottomRect(int x, int y, const vector<int> &circle)
    {
        // y1 <= Y and abs(x1 - X) <= r1 or x1 <= X and y1 <= r1
        return (circle[1] <= y && std::abs(circle[0] - x) <= circle[2]) || (circle[0] <= x && circle[1] <= circle[2]);
        // return (std::abs(circle[0] - x) <= circle[2] && circle[1] <= y) || (std::abs(circle[1]) <= circle[2] && circle[0] <= x);
    }

    bool dfs(int idx, vector<int> &vis, const vector<vector<int>> &circles, int xCorner, int yCorner)
    {
        if (checkIntersectRightOrBottomRect(xCorner, yCorner, circles[idx]))
        {
            return true;
        }

        vis[idx] = 1;

        for (size_t i = 0; i < circles.size(); i++)
        {
            if (vis[i] == 0 && checkIntersectRect(xCorner, yCorner, circles[idx], circles[i]) && dfs(i, vis, circles, xCorner, yCorner))
            {
                return true;
            }
        }

        return false;
    }

    bool canReachCorner(int xCorner, int yCorner, const vector<vector<int>> &circles)
    {
        std::vector<int> vis(circles.size(), 0);

        for (size_t i = 0; i < circles.size(); i++)
        {
            if (checkInCircle(xCorner, yCorner, circles[i]) || checkInCircle(0, 0, circles[i]))
            {
                return false;
            }

            if (vis[i] == 0 && checkIntersectLeftOrTopRect(xCorner, yCorner, circles[i]) && dfs(i, vis, circles, xCorner, yCorner))
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    // auto res = s.canReachCorner(20, 100, vector<vector<int>>{{1, 102, 18}, {50, 60, 48}});
    // auto res = s.canReachCorner(15, 15, vector<vector<int>>{{2, 20, 13}, {20, 2, 13}});
    // auto res = s.canReachCorner(3, 3, vector<vector<int>>{{7,6,5}});
    auto res = s.canReachCorner(500000000, 500000000, vector<vector<int>>{{499980000, 699999999, 200000000}, {500020000, 300000001, 200000000}});
    std::cout << "can reach corner is " << (res ? "true" : "false") << "\n";
    return 0;
}