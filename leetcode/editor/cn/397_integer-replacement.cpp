//给定一个正整数 n ，你可以做如下操作： 
//
// 
// 如果 n 是偶数，则用 n / 2替换 n 。 
// 如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。 
// 
//
// n 变为 1 所需的最小替换次数是多少？ 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 8
//输出：3
//解释：8 -> 4 -> 2 -> 1
// 
//
// 示例 2： 
//
// 
//输入：n = 7
//输出：4
//解释：7 -> 8 -> 4 -> 2 -> 1
//或 7 -> 6 -> 3 -> 2 -> 1
// 
//
// 示例 3： 
//
// 
//输入：n = 4
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 2³¹ - 1 
// 
// Related Topics 位运算 记忆化搜索 动态规划 👍 98 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerReplacement(int n) {
        int nn;
        if (n == 1) return 0;
        if (n & 1) nn = n+1;
        else nn = n;

        vector<int> dp(nn+1);
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 4; i <= nn; i += 2) {
            int k = i/2;
            if (k&1) {
                // 奇数
                dp[i] = 2+ min(dp[k+1], dp[k-1]);
            } else {
                // 偶数
                dp[i] = 1+dp[k];
            }
        }

        if (n&1) return 1+min(dp[n-1], dp[n+1]);
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.integerReplacement(8) << endl;
}