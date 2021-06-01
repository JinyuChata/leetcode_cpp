//给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。 
//
// 示例: 
//
// 输入: 2
//输出: 91 
//解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
// 
// Related Topics 数学 动态规划 回溯算法 
// 👍 137 👎 0
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        while (n > 10) {
            n = 10;
        }

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 9;
        int sum = 10;
        for (int i = 2; i <= n; i++) {
            dp[i] = (10-i+1)*dp[i-1];
            sum += dp[i];
        }

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}