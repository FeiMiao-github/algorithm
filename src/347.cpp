#include <comm.h>
#include <tree.h>

class MinHeap {
public:
  using cmp_type = function<bool(int a, int b)>;
  vector<int> arr;
  int len;
  cmp_type cmp;

  MinHeap(cmp_type &&cmp) : arr(), len(0), cmp(cmp) {}

  void push_heap(int v) {
    arr.push_back(v);
    int i = len;
    int j = (i - 1) / 2;
    while (j >= 0 && cmp(arr[j], arr[i])) {
      swap(arr[i], arr[j]);
      i = j;
      j = (i - 1) / 2;
    }
    len++;
  }

  int pop_heap() {
    if (len < 1) {
      return -1;
    }
    int ret = arr[0];
    len--;
    swap(arr[0], arr[len]);
    int i = 0;
    while (i < len) {
      int lid = i * 2 + 1;
      int rid = i * 2 + 2;
      int largest = i;
      if (lid < len && cmp(arr[largest], arr[lid])) {
        largest = lid;
      }
      if (rid < len && cmp(arr[largest], arr[rid])) {
        largest = rid;
      }
      swap(arr[i], arr[largest]);
      if (i < largest)
        i = largest;
      else
        break;
    }
    return ret;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> mp;
    for (auto v : nums) {
      mp[v]++;
    }
    auto func = [&](int a, int b) { return mp[a] < mp[b]; };
    MinHeap hp(func);
    for (auto &[k, v] : mp) {
      hp.push_heap(k);
    };
    for (int i = 0; i < k; i++) {
      res.push_back(hp.pop_heap());
    }
    return res;
  }
};

void test(const vector<int> &arr, int k, const vector<int> &expect) {
  auto param1 = arr;
  vector<int> res = Solution().topKFrequent(param1, k);
  bool flag = true;

  set<int> st;
  for (auto v : expect) {
    st.insert(v);
  }
  for (auto v : res) {
    if (!st.contains(v)) {
      flag = false;
      break;
    }
  }
  if (flag) {
    std::cout << "[OK]\n";
  } else {
    std::cout << "[FAILED]\n";
  }
}

int main() {
  test({1, 2}, 2, {1, 2});
  return 0;
}
