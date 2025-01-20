#include <comm.h>

class Solution {
public:
    void pop_front(vector<int>& nums, int i, int last)
    {
        int largest = i;
        int l = largest * 2 + 1;
        int r = largest * 2 + 2;
        if (l < last && nums[l] > nums[largest])
        {
            largest = l;
        }

        if (r < last && nums[r] > nums[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(nums[i], nums[largest]);
            pop_front(nums, largest, last);
        }
    }

    void build_heap(vector<int>&nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            int tmp = i;
            int prev = tmp / 2 - (tmp % 2 == 0);
            while (prev >= 0)
            {
                if (nums[prev] < nums[tmp])
                {
                    swap(nums[prev], nums[tmp]);
                }
                tmp = prev;
                prev = tmp / 2 - (tmp % 2 == 0);
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        build_heap(nums);
        int ret = nums[0];
        int heapsize = nums.size();
        for (int i = 0; i < k; i++)
        {
            pop_front(nums, 0, heapsize);
            heapsize--;
            ret = nums[0];
            swap(nums[0], nums[heapsize]);
        }
        return ret;
    }
};

void test(const vector<int>& nums, int k, int expect) {
    vector<int> params = nums;
    Solution s;
    int res = s.findKthLargest(params, k);
    if(res == expect)
    {
        cout << "[OK] res is " << res << "\n";
    }
    else
    {
        cout << "[FAILED] res is " << res << "\n";
    }
}

int main()
{
    test({3,2,1,5,6,4}, 2, 5);
    test({3,2,3,1,2,4,5,5,6}, 4, 4);
    test({-1, 2, 0}, 1, 2);
    test({7,6,5,4,3,2,1}, 5, 3);

    return 0;
}
