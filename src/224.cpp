// #include <iostream>
// #include <stack>
// #include <unordered_map>
// #include <cassert>

// using namespace std;

// class Number {
// public:
//     Number():
//         _up(0), _down(1) {}

//     Number operator+(const Number& v)
//     {
//         Number ret;
//         ret._up = this->_up * v._down + this->_down * v._up;
//         ret._down = this->_down * v._down;
//         return ret;
//     }

//     Number operator-(const Number& v)
//     {
//         Number ret;
//         ret._up = _up * v._down - v._up * _down;
//         ret._down = this->_down * v._up;
//     }

//     Number operator*(const Number& v)
//     {
//         Number ret;
//         ret._up = _up * v._up;
//         ret._down = _down * v._down;
//         return ret;
//     }

//     Number operator/(const Number& v)
//     {
//         Number ret;
//         ret._up = _up * v._down;
//         ret._down = _down * v._up;
//         return ret;
//     }

//     Number operator=(const Number& v)
//     {
//         _up = v._up;
//         _down = v._down;
//         return *this;
//     }

//     int32_t _up;
//     int32_t _down;
// };

// class Solution {
//     bool is_digit(char c)
//     {
//         return c >= '0' && c <= '9';
//     }

//     bool is_op(char c)
//     {
//         return c == '+' || c == '-' || c == '*' || c == '/';
//     }

//     bool is_bracket(char c)
//     {
//         return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']';
//     }

//     int priority(char c)
//     {
//     }

//     const static std::unordered_map<char, int32_t> priority_umap {
//         {'+', 1},
//         {'-', 1},
//         {'*', 2},
//         {'/', 2},
//     };

//     Number calc(const Number &l, const Number &r, char op)
//     {
//         Number ret;
//         Number ltmp = l;
//         Number rtmp = r;
//         switch(op)
//         {
//         case '+':
//             ret = ltmp + rtmp;
//             break;
//         }
//         return ret;
//     }

// public:
//     Number calculate(string s) {
//         std::stack<string> sign_st;
//         std::stack<Number> num_st;
//         Number ret;
//         ret._up = 0;
//         ret._down = 1;

//         for (auto p = s.begin(); p != s.end();)
//         {
//             if (is_digit(*p))
//             {
//                 string tmp = "";
//                 while (p != s.end())
//                 {
//                     if (is_digit(*p))
//                     {
//                         tmp += *p;
//                         p++;
//                     }
//                     else
//                     {
//                         Number num;
//                         num._up = stoi(tmp);
//                         num._down = 1;
//                         num_st.emplace(num);
//                     }
//                 }
//             }
//             else if (is_op(*p))
//             {
//                 if (!sign_st.empty())
//                 {
//                     auto last_op = sign_st.top();
//                     auto last_pri = priority_umap.at(last_op[0]);
                    
//                     auto cur_pri = priority_umap.at(*p);

//                     if (last_pri >= cur_pri)
//                     {
//                         Number num_r = num_st.top();
//                         Number num_l = num_st.top();
//                     }
//                 }
//                 else
//                 {

//                 }
//             }
//         }

//         return ret;
//     }
// };

int main()
{
//     Solution s;
//     s.calculate("(-1+1)");
    return 0;
} 