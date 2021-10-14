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
        int target = 0; int n = nums.size();
        for (int& num : nums) {
            target += num;
        }
        if (target % 2 == 1) return false;
        target /= 2;

        /*
        vector<int> dp(target+1);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
        */
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = nums[i-1];
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= num) dp[i][j] = dp[i][j] || dp[i-1][j-num];
            }
        }

        return dp[n][target];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<int> v{1,5,11,5};
    Solution s;
    cout << s.canPartition(v);

}