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

public:
    int maxCoins(vector<int> &nums) {
        // 最后一个被戳爆的是k
        // (i..j)中，无论最后戳爆哪个，在其他不变的情况下【i..j之外不变】，得到的最大钱数
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        // 0 [1,2,...,n] n+1
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // dp[i][j] (i..j)开区间，其他不变，最多拿到的钱
        // 初始化dp[0,2] dp[1,3] ...
        for (int i = 0; i <= n-3; i++) {
            dp[i][i+2] = nums[i+1]*nums[i]*nums[i+2];
        }

        for (int k = 3; k < n; k++) {
            for (int i = 0; i + k < n; i++) {
                // dp[i][i+k]
                for (int m = i+1; m < i+k; m++) {
                    // 戳爆m
                    dp[i][i+k] = max(nums[m]*nums[i]*nums[i+k] + dp[i][m] + dp[m][i+k], dp[i][i+k]);
                }
            }
        }

        return dp[0][n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}