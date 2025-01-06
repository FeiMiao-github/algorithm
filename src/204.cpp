#include <iostream>
#include <vector>
#include <array>

using namespace std;

// 判断一个数是否是质数
constexpr bool is_prime(int num, int divisor = 2) {
    if (num < 2) return false;
    if (divisor * divisor > num) return true;
    if (num % divisor == 0) return false;
    return is_prime(num, divisor + 1);
}

// 生成质数表
template <int... Indices>
constexpr auto generate_primes(std::integer_sequence<int, Indices...>) {
    return std::array<bool, sizeof...(Indices)>{is_prime(Indices)...};
}

constexpr int limit = 100000;
constexpr auto primes = generate_primes(std::make_integer_sequence<int, limit + 1>{});

class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (primes[i])
            {
                res++;
            }
        }
        return res;
    }
};

int main()
{
    std::cout << "res is " << Solution().countPrimes(10) << "\n";
    return 0;
}