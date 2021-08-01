//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 104 
// -104 <= nums[i] <= 104 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 
// 👍 1191 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct MinHeapCmp
{
    inline bool operator()(const int &x, const int &y)
    {
        return x > y;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap;
        int size = 0;
        for (int & num : nums) {
            if (size < k) {
                heap.push_back(num);
                push_heap(heap.begin(), heap.end(), MinHeapCmp());
                size++;
            } else if (num > heap[0]) {
                heap[0] = num;
                make_heap(heap.begin(), heap.end(), MinHeapCmp());
            }
        }

        return heap[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}