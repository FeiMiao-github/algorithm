#include <comm.h>

class Solution {
public:
  ListNode *swap_inner(ListNode *prev, ListNode *tail) {
    ListNode *head = tail->next;
    ListNode *tmp = prev->next;
    ListNode *ret = tmp;
    ListNode *last = head;
    while (tmp && tmp != last) {
      ListNode *tp = tmp->next;
      tmp->next = head;
      head = tmp;
      tmp = tp;
    }
    prev->next = head;
    return ret;
  }

  ListNode *swapPairs(ListNode *nd) {
    ListNode head(0, nd);
    ListNode *ptmp = &head;
    while (ptmp && ptmp->next) {
      if (!ptmp->next->next)
        break;
      ptmp = swap_inner(ptmp, ptmp->next->next);
    }
    ptmp = head.next;
    head.next = nullptr;
    return ptmp;
  }
};

void test(const vector<int> &arr, const vector<int> &expect) {
  ListNode param(0, ListNode::from_vec(arr));
  Solution s;
  ListNode *pret = s.swapPairs(param.next);
  vector<int> res = ListNode::to_vec(pret);
  std::cout << "res is " << res << "\n";
  param.next = pret;
  if (res == expect) {
    std::cout << "[OK]\n";
  } else {
    std::cout << "[FAILED]\n";
  }
}

int main() {
  test({1, 2, 3, 4}, {2, 1, 4, 3});
  return 0;
}
