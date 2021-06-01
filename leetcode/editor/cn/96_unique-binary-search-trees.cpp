//给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 19 
// 
// Related Topics 树 动态规划 
// 👍 1162 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);        // dumb: dp[0]=1
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // 找一个值 分开 1..i
            for (int j = 1; j <= i; j++) {
                int left = j-1; int right = i-j;
                dp[i] += dp[left] * dp[right];
            }
        }

        cout << endl;
        for (int i = 0; i <= n; i++) cout << dp[i] << " ";

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}