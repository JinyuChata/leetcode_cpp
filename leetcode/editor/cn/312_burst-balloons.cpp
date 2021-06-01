//有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。 
//
// 现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。 这里的 i -
// 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。 
//
// 求所能获得硬币的最大数量。 
//
//示例 1：
//
//输入：nums = [3,1,5,8]
//输出：167
//解释：
//nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167 
//
// 示例 2： 
//
//输入：nums = [1,5]
//输出：10
//
//
// 提示： 
//
// n == nums.length 
// 1 <= n <= 500 
// 0 <= nums[i] <= 100 
// Related Topics 分治算法 动态规划 
// 👍 732 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> memo;
public:
    int dp(vector<int>& nums, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];

        int maxVal = 0;
        for (int k = i+1; k < j; k++) {
            // 最后一个戳破的是k
            maxVal = max(maxVal, nums[i]*nums[j]*nums[k] + dp(nums, i, k) + dp(nums, k, j));
        }

        memo[i][j] = maxVal;
        return maxVal;
    }

    int maxCoins(vector<int>& nums) {
        // 状态太难想了！！
        // dp[i][j]: 在(i,j)开区间内戳气球，最大的获利
        // -> 要关注在(i,j)内 最后一个被戳爆的是什么
        // -> 在(i,j)内戳气球，就意味着只有(i,j)这个区间内存在气球，其他全被戳爆了
        int n = nums.size();
        // 两侧加上两个dumb值
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        memo = vector<vector<int>>(n+2, vector<int>(n+2, -1));
        // 初始化
        for (int i = 0; i < n+2; i++) memo[i][i] = 0;
        for (int i = 0; i < n+1; i++) memo[i][i+1] = 0;

        // base cond:
        // -> 无须刻意初始化，已经在dp建立时被初始化
        // -> 不好用直接dp列表！最好还是要写递归函数

        return dp(nums, 0, nums.size()-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}