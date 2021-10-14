//给定一个正整数 n，找出小于或等于 n 的非负整数中，其二进制表示不包含 连续的1 的个数。 
//
// 示例 1: 
//
// 输入: 5
//输出: 5
//解释: 
//下面是带有相应二进制表示的非负整数<= 5：
//0 : 0
//1 : 1
//2 : 10
//3 : 11
//4 : 100
//5 : 101
//其中，只有整数3违反规则（有两个连续的1），其他5个满足规则。 
//
// 说明: 1 <= n <= 10⁹ 
// Related Topics 动态规划 👍 181 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int findNew(vector<vector<int>>& dp, int root, int last, unsigned value, int height) {
        if (height == 0) return 0;
        int curr = (value & INT32_MIN) == INT32_MIN;

        if (height == 1) {
            if (curr == 1) return 1;
            return root == 0;
        }

        if (root == 0) {
            // 以0为根，高度为height，剩余height位开头为curr
            if (curr) {
                return dp[height][0];
            } else {
                return findNew(dp, 0, 0, value<<1, height-1)
                        + findNew(dp, 1, 0, value<<1, height-1);
            }
        } else {
            // 以1为根，如果curr=0,根本不配
            if (!curr) return 0;
            else {
                return findNew(dp, 0, 1, value<<1, height-1);
            }
        }
    }

    int findIntegers(int n) {
        // 先计算n的位数
        int nCopy = n; int digSize = 0;
        while (nCopy != 0) {
            digSize++;
            nCopy >>= 1;
        }

        // dp[i][0/1] 以0/1为root，i层的满二叉树，满足题意的个数
        vector<vector<int>> dp(digSize+1, vector<int>(2, 0));
        // 1层
        dp[1][0] = 1; dp[1][1] = 1;
        for (int i = 2; i <= digSize; i++) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][0];
        }

//        for (int i = 1; i <= digSize; i++) {
//            cout << i << ": " << dp[i][0] << ", " << dp[i][1] << endl;
//        }

        unsigned nn = n;
        nn <<= (32-digSize);
        int left = findNew(dp, 0, 0, nn, digSize);
        int right = findNew(dp, 1, 0, nn, digSize);
        return left + right;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.findIntegers(5);
}