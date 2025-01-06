#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

class LabyRinth
{
    using LABY_DATA_t = std::vector<std::vector<int32_t>>;

public:
    static constexpr uint32_t LAB_W = 32;
    static constexpr uint32_t LAB_H = 32;

    LabyRinth()
        : LABY(LAB_H, std::vector<int>(32, 0))
    {
    }

    ~LabyRinth() = default;

    int32_t Init()
    {
        AddIsland(10);
        return 0;
    }

    int32_t Print()
    {
        for (uint32_t i = 0; i < LAB_W; i++)
        {
            for (uint32_t j = 0; j < LAB_H; j++)
            {
                std::cout << LABY[i][j] << ",";
            }
            std::cout << std::endl;
        }
        return 0;
    }

protected:
    virtual int32_t AddIsland(int32_t ele_num)
    {
        int32_t x = rand() % LAB_W;
        int32_t y = rand() % LAB_H;
        std::stack<std::pair<int32_t, int32_t>> point_history;
        std::pair<int32_t, int32_t> points[4];

        LABY[x][y] = 1;
        point_history.emplace(x, y);

        int32_t cnt = 1;
        while (cnt < ele_num)
        {
            GetSurroundedPoints(x, y, points);
            cnt++;
        }

        return 0;
    }

    int32_t GetSurroundedPoints(int32_t x, int32_t y, std::pair<int32_t, int32_t> *points)
    {
        constexpr int32_t xoffset[] = {1, -1, 0, 0};
        constexpr int32_t yoffset[] = {0, 0, 1, -1};

        int32_t i = 0;
        int32_t cnt = 0;
        for (; i < 4; i++)
        {
            if (CheckIfValidPoints(x + xoffset[i], y + yoffset[i]))
            {
                points[cnt++] = std::make_pair(x + xoffset[i], y + yoffset[i]);
            }
        }
        
        return 0;
    }

    int32_t CheckIfValidPoints(int32_t x, int32_t y)
    {
        if (x < 0 || x >= LAB_W)
        {
            return 0;
        }

        if (y < 0 || y >= LAB_H)
        {
            return 0;
        }

        return 1;
    }

private:
    LABY_DATA_t LABY;
};

struct A{
    char c;
    short a;
    char c2;
    int c1;
    double x;
};

int main()
{
    srand48(0);

    // LabyRinth labrinth;
    // labrinth.Print();

    A a;
    std::cout << "sizeof(hello): " << sizeof(A) << "\n";
    std::cout << "c c: " << (reinterpret_cast<uint64_t>(&a.c) - reinterpret_cast<uint64_t>(&a)) << "\n";
    std::cout << "c a: " << (reinterpret_cast<uint64_t>(&a.a) - reinterpret_cast<uint64_t>(&a)) << "\n";
    std::cout << "c c2: " << (reinterpret_cast<uint64_t>(&a.c2) - reinterpret_cast<uint64_t>(&a)) << "\n";
    std::cout << "c c1: " << (reinterpret_cast<uint64_t>(&a.c1) - reinterpret_cast<uint64_t>(&a)) << "\n";
    std::cout << "c x: " << (reinterpret_cast<uint64_t>(&a.x) - reinterpret_cast<uint64_t>(&a)) << "\n";
    return 0;
}