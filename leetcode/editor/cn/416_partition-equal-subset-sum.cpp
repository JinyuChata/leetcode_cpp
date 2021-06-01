//给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 200 
// 1 <= nums[i] <= 100 
// 
// Related Topics 动态规划 
// 👍 802 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for (int k : nums)
            sum += k;
        if (sum % 2 != 0) return false;
        sum /= 2;

        // dp[i][j]: [0...i] 中 和恰好等于j
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        if (nums[0] <= sum) {
            dp[0][nums[0]] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                }
            }
        }

        return dp[n-1][sum];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> v{67,95,58,76,19,60,20,17,23,23,67,85,8,67,81,65,73,92,59,97,45,94,26,90,70,45,
                  24,52,25,43,2,83,15,25,66,87,77,11,46,75,46,59,17,84,11,64,9,74,65,78,85,3,87,
                  81,67,37,79,50,14,88,55,45,58,31,75,74,13,2,60,51,94,82,63,90,25,60,86,12,42,
                  78,33,8,50,84,86,71,46,47,15,86,56,64,8,26,34,21,21,24,49,16};
    Solution s;
    cout << s.canPartition(v);
}