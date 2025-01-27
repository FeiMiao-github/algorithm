#ifndef COMM_H_
#define COMM_H_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <numeric>

using namespace std;

// std::cout vector<int>
std::ostream &operator<<(std::ostream &os, const vector<int> &arr);

// std::cout vector<vector<int>>
std::ostream &operator<<(std::ostream &os, const vector<vector<int>> &arrs);

// std::cout vector<string>
std::ostream &operator<<(std::ostream &os, const vector<string> &strs);

// std::cout vector<vector<string>>
std::ostream &operator<<(std::ostream &os, const vector<vector<string>> &strs);

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pair) {
    return os << "{" << pair.first << ", " << pair.second << "}";
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
    os << "{";
    for (auto &e : v) {
        os << e << ",";
    }
    return os << "}";
}

template <typename T>
void ug_check_set(const vector<T> &res, const vector<T> &exp) {
    unordered_set<T> res_set;
    unordered_set<T> exp_set;

    res_set.insert(res.begin(), res.end());
    exp_set.insert(exp.begin(), exp.end());

    if (res_set == exp_set) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

template <typename T> void ug_check(const T &res, const T &exp) {
    if (res == exp) {
        std::cout << "[OK]\n";
    } else {
        std::cout << "[FAILED]" << res << "\n";
    }
}

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode &operator=(const ListNode &) {
        std::cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << " run !\n";
        throw std::exception();
    }

    ListNode &operator=(ListNode &&nd) {
        std::cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << " run !\n";
        while (next) {
            ListNode *tmp = next;
            next = next->next;
            delete tmp;
        }
        this->val = nd.val;
        this->next = nd.next;
        nd.next = nullptr;
        return *this;
    }

    ~ListNode() { delete next; }

    static ListNode *from_vec(const std::vector<int> &vec) {
        ListNode ret;
        ListNode *ptmp = &ret;
        for (auto v : vec) {
            ptmp->next = new ListNode(v);
            ptmp = ptmp->next;
        }
        ptmp = ret.next;
        ret.next = nullptr;
        return ptmp;
    }

    static vector<int> to_vec(ListNode *list) {
        vector<int> ret;
        while (list) {
            ret.push_back(list->val);
            list = list->next;
        }
        return ret;
    }
};

#endif // COMM_H_
