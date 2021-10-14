//给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 
//upper）之内的 区间和的个数 。 
//
// 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。 
//
// 
//示例 1：
//
// 
//输入：nums = [-2,5,-1], lower = -2, upper = 2
//输出：3
//解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0], lower = 0, upper = 0
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// -10⁵ <= lower <= upper <= 10⁵ 
// 题目数据保证答案是一个 32 位 的整数 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 356 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // 预计算preSum
        int n = nums.size();
        vector<int> preSum; preSum.push_back(0);
        int tmp = 0;
        for (int& num : nums) {
            tmp += num;
            preSum.push_back(tmp);
        }

        // sum[i..j] = p[j+1]-p[i]
        // p[0...n] 都可以减

    }

    int mergeSort(vector<int>& preSum, vector<int>& tmp, int l, int r, int lower, int higher) {
        if (l >= r) return 0;
        int mid = l + (r-l)/2;
        int ret = mergeSort(preSum, tmp, l, mid, lower, higher) + mergeSort(preSum, tmp, mid+1, r, lower, higher);
        // 现在，左右两边都已经排序
        int i = l;
        int jLeft = mid+1; int jRight = mid+1;
        // 锁定i
        while (i <= mid) {
            // 用这个i，匹配出啥样的j?
            int leftBound = lower + preSum[i];
            int rightBound = higher + preSum[i];

            while (jLeft <= mid && preSum[jLeft] < leftBound) jLeft++;
            while (jRight < mid && )
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}