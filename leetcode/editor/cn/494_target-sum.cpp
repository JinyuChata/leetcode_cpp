//给你一个整数数组 nums 和一个整数 target 。 
//
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ： 
//
// 
// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。 
// 
//
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,1,1,1], target = 3
//输出：5
//解释：一共有 5 种方法让最终目标和为 3 。
//-1 + 1 + 1 + 1 + 1 = 3
//+1 - 1 + 1 + 1 + 1 = 3
//+1 + 1 - 1 + 1 + 1 = 3
//+1 + 1 + 1 - 1 + 1 = 3
//+1 + 1 + 1 + 1 - 1 = 3
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], target = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 20 
// 0 <= nums[i] <= 1000 
// 0 <= sum(nums[i]) <= 1000 
// -1000 <= target <= 1000 
// 
// Related Topics 数组 动态规划 回溯 
// 👍 887 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // dfs是一种办法
        // dp: 先算算数学推导，假设将nums分成x、y两部分
        //     x+y=sum, x-y=target
        //     则 2x=sum+target
        int sum = 0;
        for (int& num : nums) sum += num;
        int t = sum + target;       // 一定>0
        if ( t % 2 == 1) return 0;
        t /= 2;

        vector<int> dp(t+1);
        dp[0] = 1;
        for (int num : nums) {
            for (int i = t; i >= num; i--) {
                dp[i] = dp [i]+ dp[i-num];
            }
        }

        return dp[t];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> in = {1};
    cout << s.findTargetSumWays(in, 1);
}