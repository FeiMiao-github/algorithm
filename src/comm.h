#ifndef COMM_H_
#define COMM_H_

#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cassert>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

// std::cout vector<int>
std::ostream& operator<<(std::ostream& os, const vector<int>& arr);

// std::cout vector<vector<int>>
std::ostream& operator<<(std::ostream& os, const vector<vector<int>>& arrs);

// std::cout vector<string>
std::ostream& operator<<(std::ostream& os, const vector<string>& strs);

// std::cout vector<vector<string>>
std::ostream& operator<<(std::ostream& os, const vector<vector<string>>& strs);

#endif // COMM_H_