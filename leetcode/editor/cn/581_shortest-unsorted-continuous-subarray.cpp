//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。 
//
// 请你找出符合题意的 最短 子数组，并输出它的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：nums = [2,6,4,8,10,9,15]
//输出：5
//解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,4]
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 104 
// -105 <= nums[i] <= 105 
// 
//
// 
//
// 进阶：你可以设计一个时间复杂度为 O(n) 的解决方案吗？ 
// 
// 
// Related Topics 栈 贪心 数组 双指针 排序 单调栈 
// 👍 693 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * oN 方法，[GroupA/B/C]
     * - GroupA中，所有数字小于其右边的，则找到从右到左、最后一个大于右边的，就是需要排序的边界
     * - GroupC同理
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT32_MAX; int left = n;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] <= minVal) {
                minVal = nums[i];
            } else {
                left = i;
            }
        }
        int maxVal = INT32_MIN; int right = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= maxVal) {
                maxVal = nums[i];
            } else {
                right = i;
            }
        }
        if (left == n) return 0;
        return right - left + 1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}