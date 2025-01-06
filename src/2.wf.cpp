#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

void print(std::vector<int> arr)
{
    std::cout << "{";
    for (auto p = arr.begin(); p != arr.end(); p++)
    {
        std::cout << *p << ",";
    }
    std::cout << "}\n";
}

int32_t get(int32_t n, int32_t index)
{
    if (n < 3 || n > 7 || index < 0)
    {
        return -1;
    }

    std::vector<int32_t> v(n);

    v[0] = 1;
    for (int32_t i = 1; i < n; i++)
    {
        v[i] = 0;
    }

    int32_t cur_index = -1;
    while (v[0] < 10)
    {
        int32_t pow_res = 0;
        int32_t sum_res = 0;

        // print(v);

        for (int32_t i = 0; i < n; i++)
        {
            pow_res += pow(v[i], n);
            sum_res = sum_res * 10 + v[i];
        }

        bool flag = true;
        for (int32_t i = n - 1; i > 0; i--)
        {
            if (flag)
            {
                v[i] += 1;
                flag = false;
            }

            if (v[i] > 9)
            {
                flag = true;
                v[i] = 0;
            }
        }

        if (flag)
        {
            v[0] += 1;
        }

        // std::cout << "sum res: " << sum_res << ", " << "pow_res: " << pow_res << "\n";

        if (sum_res == pow_res)
        {
            cur_index ++;
        }

        if (index == cur_index)
        {
            return pow_res;
        }
    }

    return -1;
}

int main()
{
    // std::cout << "ret is " << get(3, 0) << "\n";
    assert(get(3, 0) == 153);
    assert(get(9, 0) == -1);
    return 0;
}