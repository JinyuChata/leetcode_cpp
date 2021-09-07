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
    // {curr,sum} => cnt
    map<pair<int, int>, int> memo;

    int dfs(vector<int>& nums, int curr, int target, int sum) {
        if (curr == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (memo.count({curr, sum})) {
            return memo[{curr, sum}];
        }
        int res = dfs(nums, curr+1, target, sum+nums[curr]) +
               dfs(nums, curr+1, target, sum-nums[curr]);
        memo[{curr, sum}] = res;
        return res;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, 0, target, 0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> in = {1};
    cout << s.findTargetSumWays(in, 1);
}